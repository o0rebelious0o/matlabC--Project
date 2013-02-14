#include <math.h>    // atan2(), sqrt()

// Datatype
typedef struct { double re, im; } TComplex;

// Function implementations
TComplex makeComplex(double, double);
// makeComplex()

int compareComplex(TComplex,  TComplex);
// compareComplex ()

double angleComplex(TComplex);
// angleComplex ()

TComplex addComplex(TComplex, TComplex);
// addComplex()

double magnitudeComplex(TComplex);
//magnitudeComplex()

TComplex subtractComplex(TComplex,TComplex);
// subtractComplex()

TComplex multiplyComplex(TComplex,TComplex);
//multiplyComplex()

TComplex divideComplex(TComplex,TComplex);
//divideComplex()

TComplex reciprocalComplex(TComplex);  // use divideComplex()
//divideComplex()

TComplex conjugateComplex(TComplex);
//conjugateComplex()