#ifndef COSMOPOLITAN_LIBC_TINYMATH_MAGICU_H_
#define COSMOPOLITAN_LIBC_TINYMATH_MAGICU_H_
#if !(__ASSEMBLER__ + __LINKER__ + 0)
COSMOPOLITAN_C_START_

struct magicu {
  uint32_t M;
  uint32_t s;
};

struct magicu __magicu_get(uint32_t);

/**
 * Performs fast division using precomputed magic for constant divisor.
 *
 * @param x is unsigned integer that shall be divided
 * @param d should be `__magicu_get(y)` if computing `x / y`
 * @return result of unsigned integer division
 */
static inline optimizesize uint32_t __magicu_div(uint32_t x, struct magicu d) {
  return ((((uint64_t)x * d.M) >> 32) + ((d.s & 64) ? x : 0)) >> (d.s & 63);
}

COSMOPOLITAN_C_END_
#endif /* !(__ASSEMBLER__ + __LINKER__ + 0) */
#endif /* COSMOPOLITAN_LIBC_TINYMATH_MAGICU_H_ */
