/* { dg-do compile { target { powerpc*-*-* } } } */
/* { dg-skip-if "do not override -mcpu" { powerpc*-*-* } { "-mcpu=*" } { "-mcpu=power8" } } */
/* { dg-require-effective-target powerpc_p9vector_ok } */
/* { dg-options "-mcpu=power8" } */

#include <altivec.h>

__vector float
make_floats (__vector float *significands_p, 
	     __vector unsigned int *exponents_p)
{
  __vector float significands = *significands_p;
  __vector unsigned int exponents = *exponents_p;

  return __builtin_vec_insert_exp (significands, exponents); /* { dg-error "builtin function __builtin_vsx_insert_exp_sp requires" } */
}
