#include <Maths.h>
#include <cmath>

float Maths::roundf(float x)
{
   return x >= 0.0f ? floorf(x + 0.5f) : ceilf(x - 0.5f);
}

float Maths::roundProba(float a_proba)
{
    return roundf(a_proba * 10.f) / 10.f;
}

double factorial(double nValue)
{
    if(nValue <= 2)
        return nValue;

   double result = nValue;
   double result_next;
   double pc = nValue;
   do
   {
       result_next = result*(pc-1);
       result = result_next;
       pc--;
   }while(pc>2);
   return result;
}

double Maths::binomialCoeff(double nValue, double nValue2)
{
   double result;
   if(nValue2 == 1)return nValue;
   result = (factorial(nValue))/(factorial(nValue2)*factorial((nValue - nValue2)));
   return result;
}
