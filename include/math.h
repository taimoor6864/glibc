#ifndef	_MATH_H

#ifdef _ISOMAC
# undef NO_LONG_DOUBLE
#endif

#include <math/math.h>

#ifndef _ISOMAC
/* Now define the internal interfaces.  */
extern int __signgam;

# if IS_IN (libc) || IS_IN (libm)
hidden_proto (__finite)
hidden_proto (__isinf)
hidden_proto (__isnan)
hidden_proto (__finitef)
hidden_proto (__isinff)
hidden_proto (__isnanf)

#  ifndef __NO_LONG_DOUBLE_MATH
hidden_proto (__finitel)
hidden_proto (__isinfl)
hidden_proto (__isnanl)
#  endif

#  if __HAVE_DISTINCT_FLOAT128
hidden_proto (__finitef128)
hidden_proto (__isinff128)
hidden_proto (__isnanf128)
hidden_proto (__signbitf128)
#  endif
# endif

libm_hidden_proto (__fpclassify)
libm_hidden_proto (__fpclassifyf)
libm_hidden_proto (__issignaling)
libm_hidden_proto (__issignalingf)
libm_hidden_proto (__exp)
libm_hidden_proto (__expf)
libm_hidden_proto (__roundeven)

# ifndef __NO_LONG_DOUBLE_MATH
libm_hidden_proto (__fpclassifyl)
libm_hidden_proto (__issignalingl)
libm_hidden_proto (__expl)
libm_hidden_proto (__expm1l)
# endif

# if __HAVE_DISTINCT_FLOAT128
libm_hidden_proto (__fpclassifyf128)
libm_hidden_proto (__issignalingf128)
libm_hidden_proto (__expf128)
libm_hidden_proto (__expm1f128)
# endif

# if !(defined __FINITE_MATH_ONLY__ && __FINITE_MATH_ONLY__ > 0)
#  ifndef NO_MATH_REDIRECT
/* Declare sqrt for use within GLIBC.  Compilers typically inline sqrt as a
   single instruction.  Use an asm to avoid use of PLTs if it doesn't.  */
float (sqrtf) (float) asm ("__ieee754_sqrtf");
double (sqrt) (double) asm ("__ieee754_sqrt");
#   ifndef __NO_LONG_DOUBLE_MATH
long double (sqrtl) (long double) asm ("__ieee754_sqrtl");
#   endif
#   if __HAVE_DISTINCT_FLOAT128 > 0
_Float128 (sqrtf128) (_Float128) asm ("__ieee754_sqrtf128");
#   endif
#  endif
# endif

#endif
#endif
