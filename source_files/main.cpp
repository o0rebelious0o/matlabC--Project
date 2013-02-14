/********************************
* Richard Evans					*
* ISE 1 - Computing Project		*
********************************/

/********************************************
* Engineering Tool To Provide Gain And		*
* Phase Response Information Of An Analogue	*
* Filter Circuit							*
********************************************/

#include <iostream>
#include "functions.h"

//if not defined
#ifndef win.h
#include <windows.h>
#include <Tlhelp32.h>
#endif

using namespace std;

//Macros
#define SWITCHFILTER(){displayTypes(); filterType = getType(); doneAlready = false; break; }
#define EXIT(){childProcessKill(); exit(0);}

//Main Function
int main()
{
	char choice;
	int filterType = -1, fMinimum, fMaximum, fChoice, quality;
	double rValue, lValue, cValue, cValueW, lValueW, fResonant;
	bool doneAlready = false;
	
	//do repeatedly until user chooses to exit
	do
	{
		//Do only initially at run time
		if(filterType == -1)
		{
			cout << "NOTE: To avoid zombie processes remaining after runtime please exit using provided commands" << endl << endl;
			displayTypes();
			ShellExecute(NULL, NULL, "Filters.png", NULL, NULL, SW_SHOWMINIMIZED);
			filterType = getType();
		}

		//do depending upon filter choice
		switch(filterType)
		{
			//exit
			case(0):
				{
					EXIT()
				}
			//band pass filter
			case (1):
				{
					getValues(fMinimum, fMaximum, rValue, cValue, lValue, cValueW, lValueW);
					do
					{
						choice = getChoice();

						switch(choice)
						{
						//plot graph
						case ('P'):
							{
								bandPassFilter(doneAlready, fMinimum, fMaximum, rValue, cValue, lValue, cValueW, lValueW);
								doneAlready = true;
								break;
							}
						//display filter resonant frequency
						case('R'):
							{
								resonantFrequency(cValue, lValue, fResonant);
								break;
							}
						//display circuit quality
						case('Q'):
							{
								filterQualityBandPass(lValue, cValue, rValue, quality);
								break;
							}
						//modify circuit component values
						case('M'):
							{
								getValues(fMinimum, fMaximum, rValue, cValue, lValue, cValueW, lValueW);
								doneAlready = false;
								break;
							}
						//display gain and phase information for a specific frequency
						case('F'):
							{
								fChoice = getFChoice();
								responseFChoiceBP(fChoice, rValue, cValue, lValue, cValueW, lValueW);
								break;
							}
						//switch filter type
						case('S'):
							{
								SWITCHFILTER()
							}
						//exit
						case('E'):
							{
								EXIT()
							}
						}
					//loop until user changes filter type
					}while(filterType == 1);
					break;
				}
			//band reject filter
			case (2):
				{
					getValues(fMinimum, fMaximum, rValue, cValue, lValue, cValueW, lValueW);
					do
					{
						choice = getChoice();
	
						switch(choice)
						{
						//plot graph
						case ('P'):
							{
								bandRejectFilter(doneAlready, fMinimum, fMaximum, rValue, cValue, lValue, cValueW, lValueW);
								break;
							}
						//display filter resonant frequency
						case('R'):
							{
								resonantFrequency(cValue, lValue, fResonant);
								break;
							}
						//display circuit quality
						case('Q'):
							{
								filterQuality(lValue, cValue, rValue, quality);
								break;
							}
						//modify circuit component values
						case('M'):
							{
								getValues(fMinimum, fMaximum, rValue, cValue, lValue, cValueW, lValueW);
								doneAlready = false;
								break;
							}
						//display gain and phase information for a specific frequency
						case('F'):
							{
								fChoice = getFChoice();
								responseFChoiceBR(fChoice, rValue, cValue, lValue, cValueW, lValueW);
								break;
							}
						//switch filter type
						case('S'):
							{
								SWITCHFILTER()
							}
						//exit
						case('E'):
							{
								EXIT()
							}
						}
					//loop until user changes filter type
					}while(filterType == 2);
					break;
				}
			//high pass filter
			case (3):
				{
					getValues(fMinimum, fMaximum, rValue, cValue, lValue, cValueW, lValueW);
					do
					{
						choice = getChoice();
	
						switch(choice)
						{
						//plot graph
						case ('P'):
							{
								highPassFilter(doneAlready, fMinimum, fMaximum, rValue, cValue, lValue, cValueW, lValueW);
								break;
							}
						//display filter resonant frequency
						case('R'):
							{
								resonantFrequency(cValue, lValue, fResonant);
								break;
							}
						//display circuit quality
						case('Q'):
							{
								filterQuality(lValue, cValue, rValue, quality);
								break;
							}
						//modify circuit component values
						case('M'):
							{
								getValues(fMinimum, fMaximum, rValue, cValue, lValue, cValueW, lValueW);
								doneAlready = false;
								break;
							}
						//display gain and phase information for a specific frequency
						case('F'):
							{
								fChoice = getFChoice();
								responseFChoiceHP(fChoice, rValue, cValue, lValue, cValueW, lValueW);
								break;
							}
						//switch filter type
						case('S'):
							{
								SWITCHFILTER()
							}
						//exit
						case('E'):
							{
								EXIT()
							}
						}
					}while(filterType == 3);
					break;
				}	
			//low pass filter
			case (4):
				{
					getValues(fMinimum, fMaximum, rValue, cValue, lValue, cValueW, lValueW);
					do
					{
						choice = getChoice();
	
						switch(choice)
						{
						//plot graph
						case ('P'):
							{
								lowPassFilter(doneAlready, fMinimum, fMaximum, rValue, cValue, lValue, cValueW, lValueW);
								break;
							}
						//display filter resonant frequency
						case('R'):
							{
								resonantFrequency(cValue, lValue, fResonant);
								break;
							}
						//display circuit quality
						case('Q'):
							{
								filterQuality(lValue, cValue, rValue, quality);
								break;
							}
						//modify circuit component values
						case('M'):
							{
								getValues(fMinimum, fMaximum, rValue, cValue, lValue, cValueW, lValueW);
								doneAlready = false;
								break;
							}
						//display gain and phase information for a specific frequency
						case('F'):
							{
								fChoice = getFChoice();
								responseFChoiceLP(fChoice, rValue, cValue, lValue, cValueW, lValueW);
								break;
							}
						//switch filter type
						case('S'):
							{
								SWITCHFILTER()
							}
						//exit
						case('E'):
							{
								EXIT()
							}	
						}
					//loop until user changes filter type
					}while(filterType == 4);
					break;
				}
				//high pass RC filter
				case (5):
				{
					getValuesRC(fMinimum, fMaximum, rValue, cValue, cValueW, fResonant);
					do
					{
						choice = getChoice();
	
						switch(choice)
						{
						//plot graph
						case ('P'):
							{
								highPassFilterRC(doneAlready, fMinimum, fMaximum, rValue, cValue, cValueW, fResonant);
								break;
							}
						//display filter resonant frequency
						case('R'):
							{
								resonantFrequencyRC(fResonant);
								break;
							}
						//display circuit quality
						case('Q'):
							{
								cout << endl << "Sorry, This Option Is Not Available" << endl;
								break;
							}
						//modify circuit component values
						case('M'):
							{
								getValuesRC(fMinimum, fMaximum, rValue, cValue, cValueW, fResonant);
								doneAlready = false;
								break;
							}
						//display gain and phase information for a specific frequency
						case('F'):
							{
								fChoice = getFChoice();
								responseFChoiceHPRC(fChoice, rValue, cValue, cValueW, fResonant);
								break;
							}
						//switch filter type
						case('S'):
							{
								SWITCHFILTER()
							}
						//exit
						case('E'):
							{
								EXIT()
							}
						}
					//loop until user changes filter type
					}while(filterType == 5);
					break;
				}
			//low pass RC filter
			case (6):
				{
					getValuesRC(fMinimum, fMaximum, rValue, cValue, cValueW, fResonant);
					do
					{
						choice = getChoice();
	
						switch(choice)
						{
						//plot graph
						case ('P'):
							{
								lowPassFilterRC(doneAlready, fMinimum, fMaximum, rValue, cValue, cValueW, fResonant);
								break;
							}
						//display filter resonant frequency
						case('R'):
							{
								resonantFrequencyRC(fResonant);
								break;
							}
						//display circuit quality
						case('Q'):
							{	
								cout << endl << "Sorry, This Option Is Not Avalilable" << endl;
								break;
							}
						//modify circuit component values
						case('M'):
							{
								getValuesRC(fMinimum, fMaximum, rValue, cValue, cValueW, fResonant);
								doneAlready = false;
								break;
							}
						//display gain and phase information for a specific frequency
						case('F'):
							{
								fChoice = getFChoice();
								responseFChoiceLPRC(fChoice, rValue, cValue, cValueW, fResonant);
								break;
							}
						//switch filter type
						case('S'):
							{
								SWITCHFILTER()
							}
						//exit
						case('E'):
							{
								EXIT()
							}
						}
					//loop until user changes filter type
					}while(filterType == 6);
					break;
				}
			}
		//do until exit
		}while(1);
	}