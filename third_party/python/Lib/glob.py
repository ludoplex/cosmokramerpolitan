"""Filename globbing utility."""

import os
import re
import fnmatch

__all__ = ["glob", "iglob", "escape"]

def glob(pathname, *, recursive=False):
    """Return a list of paths matching a pathname pattern.

    The pattern may contain simple shell-style wildcards a la
    fnmatch. However, unlike fnmatch, filenames starting with a
    dot are special cases that are not matched by '*' and '?'
    patterns.

    If recursive is true, the pattern '**' will match any files and
    zero or more directories and subdirectories.
    """
    return list(iglob(pathname, recursive=recursive))

def iglob(pathname, *, recursive=False):
    """Return an iterator which yields the paths matching a pathname pattern.

    The pattern may contain simple shell-style wildcards a la
    fnmatch. However, unlike fnmatch, filenames starting with a
    dot are special cases that are not matched by '*' and '?'
    patterns.

    If recursive is true, the pattern '**' will match any files and
    zero or more directories and subdirectories.
    """
    it = _iglob(pathname, recursive, False)
    if recursive and _isrecursive(pathname):
        s = next(it)  # skip empty string
        assert not s
    return it

def _iglob(pathname, recursive, dironly):
    dirname, basename = os.path.split(pathname)
    if not has_magic(pathname):
        assert not dironly
        if (
            basename
            and os.path.lexists(pathname)
            or not basename
            and os.path.isdir(dirname)
        ):
            yield pathname
        return
    if not dirname:
        if recursive and _isrecursive(basename):
            yield from _glob2(dirname, basename, dironly)
        else:
            yield from _glob1(dirname, basename, dironly)
        return
    # `os.path.split()` returns the argument itself as a dirname if it is a
    # drive or UNC path.  Prevent an infinite recursion if a drive or UNC path
    # contains magic characters (i.e. r'\\?\C:').
    if dirname != pathname and has_magic(dirname):
        dirs = _iglob(dirname, recursive, True)
    else:
        dirs = [dirname]
    if has_magic(basename):
        glob_in_dir = _glob2 if recursive and _isrecursive(basename) else _glob1
    else:
        glob_in_dir = _glob0
    for dirname in dirs:
        for name in glob_in_dir(dirname, basename, dironly):
            yield os.path.join(dirname, name)

# These 2 helper functions non-recursively glob inside a literal directory.
# They return a list of basenames.  _glob1 accepts a pattern while _glob0
# takes a literal basename (so it only has to check for its existence).

def _glob1(dirname, pattern, dironly):
    names = list(_iterdir(dirname, dironly))
    if not _ishidden(pattern):
        names = (x for x in names if not _ishidden(x))
    return fnmatch.filter(names, pattern)

def _glob0(dirname, basename, dironly):
    if basename:
        if os.path.lexists(os.path.join(dirname, basename)):
            return [basename]
    elif os.path.isdir(dirname):
        return [basename]
    return []

# Following functions are not public but can be used by third-party code.

def glob0(dirname, pattern):
    return _glob0(dirname, pattern, False)

def glob1(dirname, pattern):
    return _glob1(dirname, pattern, False)

# This helper function recursively yields relative pathnames inside a literal
# directory.

def _glob2(dirname, pattern, dironly):
    assert _isrecursive(pattern)
    yield pattern[:0]
    yield from _rlistdir(dirname, dironly)

# If dironly is false, yields all file names inside a directory.
# If dironly is true, yields only directory names.
def _iterdir(dirname, dironly):
    if not dirname:
        if isinstance(dirname, bytes):
            dirname = bytes(os.curdir, 'ASCII')
        else:
            dirname = os.curdir
    try:
        with os.scandir(dirname) as it:
            for entry in it:
                try:
                    if not dironly or entry.is_dir():
                        yield entry.name
                except OSError:
                    pass
    except OSError:
        return

# Recursively yields relative pathnames inside a literal directory.
def _rlistdir(dirname, dironly):
    names = list(_iterdir(dirname, dironly))
    for x in names:
        if not _ishidden(x):
            yield x
            path = os.path.join(dirname, x) if dirname else x
            for y in _rlistdir(path, dironly):
                yield os.path.join(x, y)


magic_check = re.compile('([*?[])')
magic_check_bytes = re.compile(b'([*?[])')

def has_magic(s):
    if isinstance(s, bytes):
        match = magic_check_bytes.search(s)
    else:
        match = magic_check.search(s)
    return match is not None

def _ishidden(path):
    return path[0] in ('.', b'.'[0])

def _isrecursive(pattern):
    return pattern == b'**' if isinstance(pattern, bytes) else pattern == '**'

def escape(pathname):
    """Escape all special characters.
    """
    # Escaping is done by wrapping any of "*?[" between square brackets.
    # Metacharacters do not work in the drive part and shouldn't be escaped.
    drive, pathname = os.path.splitdrive(pathname)
    if isinstance(pathname, bytes):
        pathname = magic_check_bytes.sub(br'[\1]', pathname)
    else:
        pathname = magic_check.sub(r'[\1]', pathname)
    return drive + pathname
