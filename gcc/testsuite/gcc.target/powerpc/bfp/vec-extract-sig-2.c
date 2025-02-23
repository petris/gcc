/* { dg-do compile { target { powerpc*-*-* } } } */
/* { dg-skip-if "do not override -mcpu" { powerpc*-*-* } { "-mcpu=*" } { "-mcpu=power8" } } */
/* { dg-require-effective-target powerpc_p9vector_ok } */
/* { dg-options "-mcpu=power8" } */

#include <altivec.h>

__vector unsigned long long int
get_significands (__vector double *p)
{
  __vector double source = *p;

  return __builtin_vec_extract_sig (source);	/* { dg-error "builtin function __builtin_vsx_extract_sig_dp requires" } */
}
