#include <qtmathematics.h>

#define PI_DIV_180  0.0174532925199432950888775748252454731199476453993055555555556
#define R180_DIV_PI 57.295779513082323110286093015487255497408894895967540988741

extern double fastsintable[] ;
extern double fastcostable[] ;

double N::Math::Radian(double angle)
{
  return ( angle * PI_DIV_180 ) ;
}

double N::Math::Degree(double radian)
{
  return ( radian * R180_DIV_PI ) ;
}

double N::Math::fastSine(double angle)
{
  if (angle>360)                          {
    int m = angle / 360                   ;
    m *= 360                              ;
    angle -= m                            ;
  }                                       ;
  if (angle<0)                            {
    while (angle<0) angle += 360.0        ;
  }                                       ;
  return N::Math::safeFastSin(angle*1024) ;
}

double N::Math::fastCosine(double angle)
{
  if (angle>360)                          {
    int m = angle / 360                   ;
    m *= 360                              ;
    angle -= m                            ;
  }                                       ;
  if (angle<0)                            {
    while (angle<0) angle += 360.0        ;
  }                                       ;
  return N::Math::safeFastCos(angle*1024) ;
}

int N::Math::compare(double x, double y, double epsilon)
{
  double d = x - y             ;
  if ( d       < 0 ) d = - d   ;
  if ( epsilon > d ) return  0 ;
  if ( x       < y ) return -1 ;
  return                     1 ;
}

double N::Math::fastCos(int id)
{
  return fastcostable[id] ;
}

double N::Math::fastSin(int id)
{
  return fastsintable[id] ;
}

double N::Math::safeFastCos(int id)
{
  while (id<0) id += 368640 ;
  id %= 368640              ;
  return fastcostable[id]   ;
}

double N::Math::safeFastSin(int id)
{
  while (id<0) id += 368640 ;
  id %= 368640              ;
  return fastsintable[id]   ;
}
