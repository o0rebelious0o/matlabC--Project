#include "TComplex.h"

// Functions
TComplex makeComplex(double r, double i){
       static TComplex tmp;

       tmp.re = r;
       tmp.im = i;
       return tmp;
} // makeComplex()

int compareComplex(TComplex c1,  TComplex c2){
       double LIMIT = 0.0000001;

       if ((fabs(c1.re - c2.re) < LIMIT) && (fabs(c1.im - c2.im) < LIMIT))
              return true;
       else
              return false;
} // compareComplex ()

double angleComplex(TComplex c){
       return atan2(c.im, c.re); // Note: returns radian value (not degrees)
} // angleComplex ()

TComplex addComplex( TComplex c1,  TComplex c2){
       static TComplex tmpadd;

       tmpadd.re = c1.re+c2.re;
       tmpadd.im = c1.im+c2.im;
       return tmpadd;
} // addComplex()

double magnitudeComplex(TComplex c)
{
	return sqrt(((c.im)*(c.im))+((c.re)*(c.re)));
}//magnitudeComplex()

TComplex subtractComplex(TComplex c1,TComplex c2)
{
       static TComplex tmpsub;

       tmpsub.re = c1.re - c2.re;
       tmpsub.im = c1.im - c2.im;
       return tmpsub;
} // subtractComplex()

TComplex multiplyComplex(TComplex c1,TComplex c2)
{
	static TComplex tmpmux;

	tmpmux.re = ((c1.re * c2.re) - (c1.im * c2.im));
	tmpmux.im = ((c1.re * c2.im) + (c1.im * c2.re));
	return tmpmux;
}
//multiplyComplex()

TComplex divideComplex(TComplex c1,TComplex c2)
{
	static TComplex tmpdiv;

	tmpdiv.re = (((c1.re * c2.re) + (c1.im * c2.im))/((c2.re * c2.re) + (c2.im * c2.im)));
	tmpdiv.im = (((c1.im * c2.re) - (c1.re * c2.im))/((c2.re * c2.re) + (c2.im * c2.im)));
	return tmpdiv;
}
//divideComplex()

TComplex reciprocalComplex(TComplex c) // use divideComplex()
{
	static TComplex tmprec;
	TComplex unity;
	unity.re = 1;
	unity.im = 0;

	tmprec = divideComplex(unity, c);

	return tmprec;
}
//reciprocalComplex()

TComplex conjugateComplex(TComplex c)
{
	static TComplex tmpconj;
	tmpconj.re = c.re;
	tmpconj.im = -c.im;

	return tmpconj;
}
//conjugateComplex()