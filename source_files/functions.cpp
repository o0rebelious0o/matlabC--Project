#include "functions.h"
#include <iostream>
#include <fstream>
#include <string>
#define _USE_MATH_DEFINES
#include <math.h>

//if not defined
#ifndef win.h
#include <windows.h>
#include <Tlhelp32.h>
#endif

using namespace std;

//macros
#define MAXIMIZEFIG(){do { MLW.hWnd = FindWindow(NULL, "Figure 1"); Sleep(500); cout << "."; }while(MLW.hWnd == NULL); }
#define SHOWWIN(){ ShowWindow(CMD.hWnd,SW_NORMAL); MAXIMIZEFIG() cout << endl; ShowWindow(MLW.hWnd,SW_NORMAL);}

//tell user what's available
void displayTypes()
{
	cout << "Filter 1 is the Bandpass Filter" << endl
		 << "Filter 2 is the Bandreject Filter" << endl
		 << "Filter 3 is the RLC High Pass Filter" << endl
		 << "Filter 4 is the RLC Low Pass Filter" << endl 
		 << "Filter 5 is the RC High Pass Filter" << endl
		 << "Filter 6 is the RC Low Pass Filter" << endl
		 << "Enter 0 to Exit" << endl << endl;
}

//get from the user filter type
int getType()
{
	int tempNo;
	cout << "Enter the number of the filter you would like to analyse: ";
	//allow only valid input
	do
	{
		cin >> tempNo;
		while(cin.fail())
			{
				cin.clear();
				cin.ignore();
				cout << endl << "Please Enter A Valid Choice ";
				cin >> tempNo;
				cout << endl;
			}
	}while(! ((tempNo == 0) | (tempNo == 1) | (tempNo == 2) | (tempNo == 3) | (tempNo == 4) | (tempNo == 5) | (tempNo == 6)));
	return tempNo;
}

//get option for filter
char getChoice()
{
	char choice;

	cout << endl
		 << "Enter P to plot phase and gain frequency response in Matlab" << endl
		 << "Enter R to display circuit cut-off Frequency" << endl
		 << "Enter Q to display circuit Quality" << endl
		 << "Enter M to modify circuit specification" << endl
		 << "Enter F to show phase and gain response at a specific frequency" << endl 
		 << "Enter S to show switch filter type" << endl
		 << "Enter E to quit" << endl << endl;

	//only allow valid input
	do
	{
		cin >> choice;
		while(cin.fail())
			{
				cin.clear();
				cin.ignore();
				cout << endl << "Please Enter A Valid Choice\t";
				cin >> choice;
				cout << endl;
			}
		//allow lower or upper case user input
		choice = toupper(choice);
		if(!((choice == 'E') | (choice == 'P') | (choice == 'R') | (choice == 'Q') | (choice == 'M') | (choice == 'F') | (choice == 'S')))
			cout << "Please enter a Valid Choice " << endl;
	}while(!((choice == 'E') | (choice == 'P') | (choice == 'R') | (choice == 'Q') | (choice == 'M') | (choice == 'F') | (choice == 'S')));
	
	return choice;
}

//get component values for the circuit
void getValues(int &fMinimum, int &fMaximum, double &rValue, double &cValue, double &lValue, double &cValueW, double &lValueW)
{
	//allow only valid user input
	do
	{
		cout << "Enter the Resistor Value (Ohms):\t";
		cin >> rValue;
		while(cin.fail())
			{
				cin.clear();
				cin.ignore();
				cout << endl << "Please Enter A Valid Choice\t";
				cin >> rValue;
				cout << endl;
			}
	}while(!((rValue > 0) && (rValue < 10000000)));
	//allow only valid user input
	do
	{
		cout << "Enter the Capacitor Value (Fahrads):\t";
		cin >> cValue;
		while(cin.fail())
			{
				cin.clear();
				cin.ignore();
				cout << endl << "Please Enter A Valid Choice\t";
				cin >> cValue;
				cout << endl;
			}
	}while(!((cValue > 0) && (cValue < 10000000)));
	cValueW = 2*M_PI*cValue;
	//allow only valid user input
	do
	{
		cout << "Enter the Inductor Value (Henries):\t";
		cin >> lValue;
		while(cin.fail())
			{
				cin.clear();
				cin.ignore();
				cout << endl << "Please Enter A Valid Choice\t";
				cin >> lValue;
				cout << endl;
			}
	}while(!((lValue > 0) && (lValue < 10000000)));
	lValueW = 2*M_PI*lValue;
	//allow only valid user input
	do
	{
		cout << "Enter the Minimum Frequency (Hz):\t";
		cin >> fMinimum;
		while(cin.fail())
			{
				cin.clear();
				cin.ignore();
				cout << endl << "Please Enter A Valid Choice\t";
				cin >> fMinimum;
				cout << endl;
			}
	}while(!((fMinimum > 0) && (fMinimum < 10000000)));
	//allow only valid user input
	do
	{
		cout << "Enter the Maximum Frequency (Hz):\t";
		cin >> fMaximum;
		while(cin.fail())
			{
				cin.clear();
				cin.ignore();
				cout << endl << "Please Enter A Valid Choice\t";
				cin >> fMaximum;
				cout << endl;
			}
	}while(!((fMaximum > 0) && (fMaximum < 100000000) && (fMaximum > fMinimum)));
}

//get component values for the RC circuits
void getValuesRC(int &fMinimum, int &fMaximum, double &rValue, double &cValue, double &cValueW, double &fResonant)
{
	//allow only valid user input
	do
	{
		cout << "Enter the Resistor Value (Ohms):\t";
		cin >> rValue;
		while(cin.fail())
			{
				cin.clear();
				cin.ignore();
				cout << endl << "Please Enter A Valid Choice\t";
				cin >> rValue;
				cout << endl;
			}
	}while(!((rValue > 0) && (rValue < 10000000)));
	//allow only valid user input
	do
	{
		cout << "Enter the Capacitor Value (Fahrads):\t";
		cin >> cValue;
		while(cin.fail())
			{
				cin.clear();
				cin.ignore();
				cout << endl << "Please Enter A Valid Choice\t";
				cin >> cValue;
				cout << endl;
			}
	}while(!((cValue > 0) && (cValue < 10000000)));
	cValueW = 2*M_PI*cValue;
	//allow only valid user input
	do
	{
		cout << "Enter the Minimum Frequency (Hz):\t";
		cin >> fMinimum;
		while(cin.fail())
			{
				cin.clear();
				cin.ignore();
				cout << endl << "Please Enter A Valid Choice\t";
				cin >> fMinimum;
				cout << endl;
			}
	}while(!((fMinimum > 0) && (fMinimum < 10000000)));
	//allow only valid user input
	do
	{
		cout << "Enter the Maximum Frequency (Hz):\t";
		cin >> fMaximum;
		while(cin.fail())
			{
				cin.clear();
				cin.ignore();
				cout << endl << "Please Enter A Valid Choice\t";
				cin >> fMaximum;
				cout << endl;
			}
	}while(!((fMaximum > 0) && (fMaximum < 10000000) && (fMaximum > fMinimum)));

	fResonant = (1/(2*M_PI*rValue*cValue));
}

//calculate values and display graph for band pass filter
void bandPassFilter(bool doneAlready, int fMinimum, int fMaximum, double rValue, double cValue, double lValue, double cValueW, double lValueW)
{
	TComplex rComplex, cComplex, lComplex, potentialDivider, seriesComplex;
	int count = 0;
	ofstream outputFile;

	//skip if values are already current
	if(doneAlready != true)
	{
		cout << endl << "Populating Data Values... Please Wait... This May Take A Moment..." << endl;

		//output data points to text file
		outputFile.open("bandPassFilter.txt");
		if(outputFile.is_open())
		{
			rComplex = makeComplex(rValue, 0.0);

			for(int i = fMinimum; i <= fMaximum; i += 50)
			{
				cComplex = makeComplex(0.0, (-1/(i*cValueW)));
				lComplex = makeComplex(0.0, (i*lValueW));

				seriesComplex = addComplex(cComplex, lComplex);

				potentialDivider = multiplyComplex(rComplex, reciprocalComplex(addComplex(rComplex, seriesComplex)));

				outputFile << i << "\t" << magnitudeComplex(potentialDivider) << "\t" << angleComplex(potentialDivider) << endl;

				if(count%100 == 0)
					cout << ".";
				count++;
			}
		}
		else
			cout << "Error Opening Output File" << endl;

		outputFile.close();
	}

	cout << endl <<"Launching Matlab ";
	Sleep(1000);

	NOTIFYICONDATA MLW,CMD;

	CMD.hWnd = GetForegroundWindow();

	if((fMaximum - fMinimum) > 1000)
		ShellExecute(NULL, NULL, "matlab", "-nosplash -nodesktop -r bandpassfilterlog.m", NULL, NULL);
	else
		ShellExecute(NULL, NULL, "matlab", "-nosplash -nodesktop -r bandpassfilter.m", NULL, NULL);

	SHOWWIN()

}

//display band pass filter gain and phase at specific frequency
void responseFChoiceBP(int fChoice, double rValue, double cValue, double lValue, double cValueW, double lValueW)
{
	TComplex rComplex, cComplex, lComplex, potentialDivider, seriesComplex;

	rComplex = makeComplex(rValue, 0.0);
	cComplex = makeComplex(0.0, (-1/(fChoice*cValueW)));
	lComplex = makeComplex(0.0, (fChoice*lValueW));

	seriesComplex = addComplex(cComplex, lComplex);

	potentialDivider = multiplyComplex(rComplex, reciprocalComplex(addComplex(rComplex, seriesComplex)));

	cout << "Gain = " << magnitudeComplex(potentialDivider) << ", "
		 << "Phase Shift = " << angleComplex(potentialDivider) << " at "<< fChoice << " Hz" << endl;
}

//display band pass filter quality
void filterQualityBandPass(double lValue, double cValue, double rValue, int &quality)
{
	quality = ((sqrt(lValue/cValue))/rValue);
	cout << "The Filter Circuit Quality Is " << quality << endl;
}

//calculate values and display graph for band reject filter
void bandRejectFilter(bool doneAlready, int fMinimum, int fMaximum, double rValue, double cValue, double lValue, double cValueW, double lValueW)
{
	TComplex rComplex, cComplex, lComplex, potentialDivider, parallelComplex;
	int count = 0;
	ofstream outputFile;

	//skip if values are already current
	if(doneAlready != true)
	{
		cout << endl << "Please Wait... This May Take A Moment..." << endl;

		outputFile.open("bandRejectFilter.txt");
		if(outputFile.is_open())
		{
			rComplex = makeComplex(rValue, 0.0);
		
			for(int i = fMinimum; i <= fMaximum; i += 20)
			{
			
				cComplex = makeComplex(0.0, (-1/(i*cValueW)));
				lComplex = makeComplex(0.0, (i*lValueW));

				parallelComplex = reciprocalComplex(addComplex(reciprocalComplex(lComplex), reciprocalComplex(cComplex)));

				potentialDivider = multiplyComplex(rComplex, reciprocalComplex(addComplex(rComplex, parallelComplex)));
	
				outputFile << i << "\t" << magnitudeComplex(potentialDivider) << "\t" << angleComplex(potentialDivider) << endl;

				if(count%100 == 0)
					cout << ".";
				count++;
			}
		}
		else
			cout << "Error Opening Output File" << endl;
	
		outputFile.close();
	}

	cout << endl <<"Launching Matlab ";
	Sleep(1000);

	NOTIFYICONDATA MLW,CMD;

	CMD.hWnd = GetForegroundWindow();

	ShellExecute(NULL, NULL, "matlab", "-nosplash -nodesktop -r bandrejectfilter.m", NULL, NULL);

	SHOWWIN()

}

//display gain and phase at specific frequency
void responseFChoiceBR(int fChoice, double rValue, double cValue, double lValue, double cValueW, double lValueW)
{
	TComplex rComplex, cComplex, lComplex, potentialDivider, parallelComplex;
		
	rComplex = makeComplex(rValue, 0.0);
	cComplex = makeComplex(0.0, (-1/(fChoice*cValueW)));
	lComplex = makeComplex(0.0, (fChoice*lValueW));

	parallelComplex = reciprocalComplex(addComplex(reciprocalComplex(lComplex), reciprocalComplex(cComplex)));

	potentialDivider = multiplyComplex(rComplex, reciprocalComplex(addComplex(rComplex, parallelComplex)));

	cout << "Gain = " << magnitudeComplex(potentialDivider) << ", "
		 << "Phase Shift = " << angleComplex(potentialDivider) << " at "<< fChoice << " Hz" << endl;
}

//calculate values and display graph for high pass filter
void highPassFilter(bool doneAlready, int fMinimum, int fMaximum, double rValue, double cValue, double lValue, double cValueW, double lValueW)
{
	TComplex rComplex, cComplex, lComplex, potentialDivider, parallelComplex;
	int count = 0;
	ofstream outputFile;

	//skip if values are current
	if(doneAlready != true)
	{
		cout << endl << "Please Wait... This May Take A Moment..." << endl;

		outputFile.open("highPassFilter.txt");
		if(outputFile.is_open())
		{
			rComplex = makeComplex(rValue, 0.0);

			for(int i = fMinimum; i <= fMaximum; i += 20)
			{
				cComplex = makeComplex(0.0, (-1/(i*cValueW)));
				lComplex = makeComplex(0.0, (i*lValueW));

				parallelComplex = reciprocalComplex(addComplex(reciprocalComplex(lComplex), reciprocalComplex(rComplex)));
	
				potentialDivider = multiplyComplex(parallelComplex, reciprocalComplex(addComplex(cComplex, parallelComplex)));
	
				outputFile << i << "\t" << magnitudeComplex(potentialDivider) << "\t" << angleComplex(potentialDivider) << endl;

				if(count%100 == 0)
					cout << ".";
				count++;
			}
		}	
		else
			cout << "Error Opening Output File" << endl;
		
		outputFile.close();
	}
	
	cout << endl <<"Launching Matlab ";
	Sleep(1000);

	NOTIFYICONDATA MLW,CMD;

	CMD.hWnd = GetForegroundWindow();

	if((fMaximum - fMinimum) > 1000)
		ShellExecute(NULL, NULL, "matlab", "-nosplash -nodesktop -r highpassfilterlog.m", NULL, NULL);
	else
		ShellExecute(NULL, NULL, "matlab", "-nosplash -nodesktop -r highpassfilter.m", NULL, NULL);


	SHOWWIN()

}

//display gain and phase for specific frequency
void responseFChoiceHP(int fChoice, double rValue, double cValue, double lValue, double cValueW, double lValueW)
{
	TComplex rComplex, cComplex, lComplex, potentialDivider, parallelComplex;

	rComplex = makeComplex(rValue, 0.0);
	cComplex = makeComplex(0.0, (-1/(fChoice*cValueW)));
	lComplex = makeComplex(0.0, (fChoice*lValueW));

	parallelComplex = reciprocalComplex(addComplex(reciprocalComplex(lComplex), reciprocalComplex(rComplex)));

	potentialDivider = multiplyComplex(parallelComplex, reciprocalComplex(addComplex(cComplex, parallelComplex)));

	cout << "Gain = " << magnitudeComplex(potentialDivider) << ", "
		 << "Phase Shift = " << angleComplex(potentialDivider) << " at "<< fChoice << " Hz" << endl;
}

//calculate values and display graph for low pass filter
void lowPassFilter(bool doneAlready, int fMinimum, int fMaximum, double rValue, double cValue, double lValue, double cValueW, double lValueW)
{
	TComplex rComplex, cComplex, lComplex, potentialDivider, parallelComplex;
	int count = 0;
	ofstream outputFile;

	//skip if values are current
	if(doneAlready != true)
	{
		cout << endl << "Please Wait... This May Take A Moment..." << endl;

		outputFile.open("lowPassFilter.txt");
		if(outputFile.is_open())
		{
			rComplex = makeComplex(rValue, 0.0);

			for(int i = fMinimum; i <= fMaximum; i += 20)
			{
				cComplex = makeComplex(0.0, (-1/(i*cValueW)));
				lComplex = makeComplex(0.0, (i*lValueW));
	
				parallelComplex = reciprocalComplex(addComplex(reciprocalComplex(cComplex), reciprocalComplex(rComplex)));

				potentialDivider = multiplyComplex(parallelComplex, reciprocalComplex(addComplex(lComplex, parallelComplex)));
		
				outputFile << i << "\t" << magnitudeComplex(potentialDivider) << "\t" << angleComplex(potentialDivider) << endl;

				if(count%100 == 0)
					cout << ".";
				count++;
			}
		}
		else
			cout << "Error Opening Output File" << endl;
		
		outputFile.close();
	}

	cout << endl <<"Launching Matlab ";
	Sleep(1000);

	NOTIFYICONDATA MLW,CMD;

	CMD.hWnd = GetForegroundWindow();

	if((fMaximum - fMinimum) > 1000)
		ShellExecute(NULL, NULL, "matlab", "-nosplash -nodesktop -r lowpassfilterlog.m", NULL, NULL);
	else
		ShellExecute(NULL, NULL, "matlab", "-nosplash -nodesktop -r lowpassfilter.m", NULL, NULL);

	SHOWWIN()
}

//display gain and phase for specific frequency
void responseFChoiceLP(int fChoice, double rValue, double cValue, double lValue, double cValueW, double lValueW)
{
	TComplex rComplex, cComplex, lComplex, potentialDivider, parallelComplex;

	rComplex = makeComplex(rValue, 0.0);
	cComplex = makeComplex(0.0, (-1/(fChoice*cValueW)));
	lComplex = makeComplex(0.0, (fChoice*lValueW));
	
	parallelComplex = reciprocalComplex(addComplex(reciprocalComplex(cComplex), reciprocalComplex(rComplex)));

	potentialDivider = multiplyComplex(parallelComplex, reciprocalComplex(addComplex(lComplex, parallelComplex)));

	cout << "Gain = " << magnitudeComplex(potentialDivider) << ", "
		 << "Phase Shift = " << angleComplex(potentialDivider) << " at "<< fChoice << " Hz" << endl;

}

//calculate values and display graph for high pass RC filter
void highPassFilterRC(bool doneAlready, int fMinimum, int fMaximum, double rValue, double cValue, double cValueW, double fResonant)
{
	ofstream outputFile;
	int count = 0;

	double vGain, phaseShift;

	//skip if values are current
	if(doneAlready != true)
	{
		cout << endl << "Please Wait... This May Take A Moment..." << endl;

		outputFile.open("highPassFilterRC.txt");
		if(outputFile.is_open())
		{
			for(int i = fMinimum; i <= fMaximum; i += 20)
			{
				vGain = 1/(sqrt(1+((fResonant/i)*(fResonant/i))));
				phaseShift = atan(fResonant/i);
				outputFile << i << "\t" << vGain << "\t" << phaseShift << endl;

				if(count%100 == 0)
					cout << ".";
				count++;
			}
		}	
		else
			cout << "Error Opening Output File" << endl;
	
		outputFile.close();
	}

	cout << endl <<"Launching Matlab ";
	Sleep(1000);

	NOTIFYICONDATA MLW,CMD;

	CMD.hWnd = GetForegroundWindow();

	if((fMaximum - fMinimum) > 1000)
		ShellExecute(NULL, NULL, "matlab", "-nosplash -nodesktop -r highpassRCfilterlog.m", NULL, NULL);
	else
		ShellExecute(NULL, NULL, "matlab", "-nosplash -nodesktop -r highpassRCfilter.m", NULL, NULL);

	SHOWWIN()
}

//show gain and phase for specific frequency
void responseFChoiceHPRC(int fChoice, double rValue, double cValue, double cValueW, double fResonant)
{
	double vGain, phaseShift;
	vGain = 1/(sqrt(1+((fResonant/fChoice)*(fResonant/fChoice))));
	phaseShift = atan(fResonant/fChoice);

	cout << "Gain = " << vGain << ", "
		 << "Phase Shift = " << phaseShift << " at "<< fChoice << " Hz" << endl;
}

//calculate values and display graph for low pass RC filter
void lowPassFilterRC(bool doneAlready, int fMinimum, int fMaximum, double rValue, double cValue, double cValueW, double fResonant)
{
	int count = 0;
	ofstream outputFile;

	double vGain, phaseShift;

	//skip if values are current
	if(doneAlready != true)
	{
		cout << endl << "Please Wait... This May Take A Moment..." << endl;

		outputFile.open("lowPassFilterRC.txt");
		if(outputFile.is_open())
		{
			for(int i = fMinimum; i <= fMaximum; i += 20)
			{
				vGain = 1/(sqrt(1+((i/fResonant)*(i/fResonant))));
				phaseShift = atan(i/fResonant);
				outputFile << i << "\t" << vGain << "\t" << phaseShift << endl;

				if(count%100 == 0)
					cout << ".";
				count++;
			}
		}	
		else
			cout << "Error Opening Output File" << endl;
	
		outputFile.close();
	}

	cout << endl <<"Launching Matlab ";
	Sleep(1000);

	NOTIFYICONDATA MLW,CMD,MATLAB;

	CMD.hWnd = GetForegroundWindow();

	if((fMaximum - fMinimum) > 1000)
		ShellExecute(MATLAB.hWnd, NULL, "matlab", "-nosplash -nodesktop -r lowpassRCfilterlog.m", NULL, NULL);
	else
		ShellExecute(MATLAB.hWnd, NULL, "matlab", "-nosplash -nodesktop -r lowpassRCfilter.m", NULL, NULL);

	SHOWWIN()
}

//display gain and phase for specific frequency
void responseFChoiceLPRC(int fChoice, double rValue, double cValue, double cValueW, double fResonant)
{
	double vGain, phaseShift;
	vGain = 1/(sqrt(1+((fChoice/fResonant)*(fChoice/fResonant))));
	phaseShift = atan(fChoice/fResonant);

	cout << "Gain = " << vGain << ", "
		 << "Phase Shift = " << phaseShift << " at "<< fChoice << " Hz" << endl;
}

//display resonant frequency for RC circuit
void resonantFrequencyRC(double fResonant)
{
	cout << "The Resonant Frequency Of The Circuit is " << fResonant  << " Hz" << endl;
}

//calculate resonant frequency for non RC circuit
void resonantFrequency(double cValue, double lValue, double &fResonant)
{
 	fResonant = (1/(2*(M_PI)*sqrt(cValue*lValue)));
	cout << "The Resonant Frequency Of The Circuit is " << fResonant  << " Hz" << endl;
}

//calculate circuit quality
void filterQuality(double lValue, double cValue, double rValue, int &quality)
{
	quality = (rValue/(sqrt(lValue/cValue)));
	cout << "The Filter Circuit Quality Is " << quality << endl;
}

//get frequency
int getFChoice()
{
	int choice;
	//accept only valid input
	do
	{
		cout << "Enter Frequency:  ";
		cin >> choice;
	}while(!((choice > 0) && (choice < 10000000)));

	return choice;
}

//kill child processes of the program
void childProcessKill()
{
	int pid = -1;
    HANDLE h = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0), processKill;
	PROCESSENTRY32 pe = { 0 };    
	pe.dwSize = sizeof(PROCESSENTRY32);
	
    pid = GetCurrentProcessId();

    if( Process32First(h, &pe)) 
	{
        do
		{
			if (pe.th32ParentProcessID == pid)
			{
				processKill = OpenProcess(PROCESS_TERMINATE, NULL, pe.th32ProcessID);
				TerminateProcess(processKill,NULL);
            }
        } while( Process32Next(h, &pe));
    }

    CloseHandle(h);
}