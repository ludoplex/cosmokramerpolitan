# read a .pyc file and pretty-print it
# copied from https://gist.github.com/twerp/fdc9975f0461821fcd3d7679d1f0f7e9
# copied from http://nedbatchelder.com/blog/200804/the_structure_of_pyc_files.html
# and updated to Python 3.5 (Nov 10th 2015)

import dis, marshal, struct, sys, time, types, binascii

def show_file(fname):
    f = open(fname, "rb")
    magic = f.read(4)
    moddate = f.read(4)
    filesz = f.read(4)
    modtime = time.asctime(time.localtime(struct.unpack('=L', moddate)[0]))
    filesz = struct.unpack('=L', filesz)
    print(f"magic {binascii.hexlify(magic)}")
    print(f"moddate {binascii.hexlify(moddate)} ({modtime})")
    print("files sz %d" % filesz)
    code = marshal.load(f)
    show_code(code)

def show_code(code, indent=''):
    print(f"{indent}code")
    indent += '   '
    print("%sargcount %d" % (indent, code.co_argcount))
    print("%snlocals %d" % (indent, code.co_nlocals))
    print("%sstacksize %d" % (indent, code.co_stacksize))
    print("%sflags %04x" % (indent, code.co_flags))
    show_hex("code", code.co_code, indent=indent)
    dis.disassemble(code)
    print(f"{indent}consts")
    for const in code.co_consts:
        if type(const) == types.CodeType:
            show_code(const, f'{indent}   ')
        else:
            print("   %s%r" % (indent, const))
    print("%snames %r" % (indent, code.co_names))
    print("%svarnames %r" % (indent, code.co_varnames))
    print("%sfreevars %r" % (indent, code.co_freevars))
    print("%scellvars %r" % (indent, code.co_cellvars))
    print("%sfilename %r" % (indent, code.co_filename))
    print("%sname %r" % (indent, code.co_name))
    print("%sfirstlineno %d" % (indent, code.co_firstlineno))
    show_hex("lnotab", code.co_lnotab, indent=indent)

def show_hex(label, h, indent):
    h = binascii.hexlify(h)
    if len(h) < 60:
        print(f"{indent}{label} {h}")
    else:
        print(f"{indent}{label}")
        for i in range(0, len(h), 60):
            print(f"{indent}   {h[i:i + 60]}")

show_file(sys.argv[1])
