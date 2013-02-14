#include "TComplex.h"

//Function Prototypes

void displayTypes();

int getType();

char getChoice();

void getValues(int &fMinumum, int &fMaximum, double &rValue, double &cValue, double &lValue, double &cValueW, double &lValueW);

void getValuesRC(int &fMinumum, int &fMaximum, double &rValue, double &cValue, double &cValueW, double &fResonant);

void bandPassFilter(bool doneAlready, int fMinumum, int fMaximum, double rValue, double cValue, double lValue, double cValueW, double lValueW);

void responseFChoiceBP(int fChoice, double rValue, double cValue, double lValue, double cValueW, double lValueW);

void filterQualityBandPass(double lValue, double cValue, double rValue, int &quality);

void bandRejectFilter(bool doneAlready, int fMinimum, int fMaximum, double rValue, double cValue, double lValue, double cValueW, double lValueW);

void responseFChoiceBR(int fChoice, double rValue, double cValue, double lValue, double cValueW, double lValueW);

void highPassFilter(bool doneAlready, int fMinumum, int fMaximum, double rValue, double cValue, double lValue, double cValueW, double lValueW);

void responseFChoiceHP(int fChoice, double rValue, double cValue, double lValue, double cValueW, double lValueW);

void lowPassFilter(bool doneAlready, int fMinumum, int fMaximum, double rValue, double cValue, double lValue, double cValueW, double lValueW);

void responseFChoiceLP(int fChoice, double rValue, double cValue, double lValue, double cValueW, double lValueW);

void highPassFilterRC(bool doneAlready, int fMinumum, int fMaximum, double rValue, double cValue, double cValueW, double fResonant);

void responseFChoiceHPRC(int fChoice, double rValue, double cValue, double cValueW, double fResonant);

void lowPassFilterRC(bool doneAlready, int fMinumum, int fMaximum, double rValue, double cValue, double cValueW, double fResonant);

void responseFChoiceLPRC(int fChoice, double rValue, double cValue, double cValueW, double fResonant);

void resonantFrequencyRC(double fResonant);

void resonantFrequency(double cValue, double lValue, double &fResonant);

void filterQuality(double lValue, double cValue, double rValue, int &quality);

int getFChoice();

void childProcessKill();