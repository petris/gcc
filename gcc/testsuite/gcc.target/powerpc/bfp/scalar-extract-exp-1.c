/* { dg-do compile { target { powerpc*-*-* } } } */
/* { dg-skip-if "do not override -mcpu" { powerpc*-*-* } { "-mcpu=*" } { "-mcpu=power8" } } */
/* { dg-require-effective-target lp64 } */
/* { dg-require-effective-target powerpc_p9vector_ok } */
/* { dg-options "-mcpu=power8" } */

/* This test should succeed only on 64-bit configurations.  */
#include <altivec.h>

unsigned int
get_exponent (double *p)
{
  double source = *p;

  return __builtin_vec_scalar_extract_exp (source); /* { dg-error "builtin function __builtin_vsx_scalar_extract_exp requires" } */
}


