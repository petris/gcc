/* { dg-do compile { target { powerpc*-*-* } } } */
/* { dg-skip-if "do not override -mcpu" { powerpc*-*-* } { "-mcpu=*" } { "-mcpu=power8" } } */
/* { dg-require-effective-target powerpc_p9vector_ok } */
/* { dg-skip-if "" { powerpc*-*-aix* } } */
/* { dg-options "-mcpu=power8" } */

/* This test should succeed on both 32- and 64-bit configurations.  */
#include <altivec.h>

int
test_byte_in_either_range (unsigned char b,
			   unsigned char first_lo_bound,
			   unsigned char first_hi_bound,
			   unsigned char second_lo_bound,
			   unsigned char second_hi_bound)
{
  unsigned int range_encoding;
  range_encoding = ((first_hi_bound << 24) | (first_lo_bound << 16)
		    | (second_hi_bound << 8) | second_lo_bound);

  return __builtin_byte_in_either_range (b, range_encoding); /* { dg-error "builtin function __builtin_scalar_byte_in_either_range requires" } */
}
