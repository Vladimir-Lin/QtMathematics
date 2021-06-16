#include <qtmathematics.h>

bool N::Math::Initialize(void)
{
  ::gsl_rng_env_setup   ( )           ;
  ::gsl_rng_types_setup ( )           ;
  gsl_rng_default_seed = time(NULL)   ;
  N::CPU::Usage::InitializeOpenMP ( ) ;
  ::srand ( time ( NULL ) )           ;
  ::srand ( rand (      ) )           ;
  return true                         ;
}
