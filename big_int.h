#ifndef MANDELBROT_BIG_INT_H
#define MANDELBROT_BIG_INT_H

#include <stdlib.h>
#include <stdint.h>
#include "mbarray.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Represents a little-endian unsigned big integer. */
struct big_int {
	struct mb_array_u32 arr;	/* Little-endian array of uin32_t's. */
};

struct big_int * bi_new(uint32_t init);
struct big_int * bi_new_from_u32arr(const uint32_t *init, size_t length);
void bi_delete(struct big_int *i);

int bi_cmp_u64(const struct big_int *a, uint64_t val);
int bi_cmp(const struct big_int *i1, const struct big_int *i2);
struct big_int * bi_cpy(const struct big_int *i);

/* --- Operator functions producing a new value --- */

struct big_int * bi_add_u64(const struct big_int *i, uint64_t val);
struct big_int * bi_sub_u64(const struct big_int *i, uint64_t val);
struct big_int * bi_mul_u64(const struct big_int *i, uint64_t val);

struct big_int * bi_add(const struct big_int *i1, const struct big_int *i2);
struct big_int * bi_sub(const struct big_int *i1, const struct big_int *i2);
struct big_int * bi_mul(const struct big_int *i1, const struct big_int *i2);

/* --- Operator functions modifinying first argument. --- */

void bi_add_u64_i(struct big_int *i, uint64_t val);
void bi_sub_u64_i(struct big_int *i, uint64_t val);

void bi_add_i(struct big_int *ret, const struct big_int *i);
void bi_sub_i(struct big_int *ret, const struct big_int *i);

#define MB_MAX(_a, _b) (((_a) > (_b)) ? (_a) : (_b))

#ifdef __cplusplus
}
#endif

#endif /* MANDELBROT_BIG_INT_H */
