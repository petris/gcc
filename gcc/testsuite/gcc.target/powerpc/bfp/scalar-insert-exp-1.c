/* { dg-do compile { target { powerpc*-*-* } } } */
/* { dg-skip-if "do not override -mcpu" { powerpc*-*-* } { "-mcpu=*" } { "-mcpu=power8" } } */
/* { dg-require-effective-target lp64 } */
/* { dg-require-effective-target powerpc_p9vector_ok } */
/* { dg-options "-mcpu=power8" } */

/* This test should succeed only on 64-bit configurations.  */
#include <altivec.h>

double
insert_exponent (unsigned long long int *significand_p,
		 unsigned long long int *exponent_p)
{
  unsigned long long int significand = *significand_p;
  unsigned long long int exponent = *exponent_p;

  return __builtin_vec_scalar_insert_exp (significand, exponent); /* { dg-error "builtin function __builtin_vsx_scalar_insert_exp requires" } */
}
