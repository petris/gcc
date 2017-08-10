// { dg-do run }
// { dg-options "-ftrapv" }

#include <limits.h>

// This is a pointer returned from malloc() in the original case.
#if ( __WORDSIZE == 64 )
#define BASE 0x7FFFffffFFFFfff0UL
#else
#define BASE 0x7FFFfff0UL
#endif

int ptrdiff(int *a, int *b)
{
	return b - a;
}

int main(int argc, char *argv[])
{
	if (16 != ptrdiff((int*)BASE, (int*)(BASE + 16 * sizeof(int))))
		return 1;
	if (-16 != ptrdiff((int*)(BASE + 16 * sizeof(int)), (int*)BASE))
		return 1;
	return 0;
}
