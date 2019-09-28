#include "pch.h"
#include <iostream>
#include "conio.h"

bool TestInput6x6()
{
	int Numeral_Inputs[] = { 0, 0, 0, 0, 0, 0, 
							 0, 0, 0, 0, 0, 0, 
							 0, 0, 0, 0, 0, 0, 
							 0, 0, 0, 0, 0, 0, 
							 0, 0, 0, 0, 0, 0, 
							 0, 0, 0, 0, 0, 0 };


	char betweenColsChar[] = {	'.', '.', '.', '.', '.', 
								'.', '.', '.', '.', '.', 
								'.', '.', '.', '.', '.', 
								'.', '.', '.', '.', '.', 
								'.', '.', '.', '.', '.', 
								'.', '.', '.', '.', '.' };

	char betweenRowsChar[] = {	'.', '.', '.', '.', '.', '.', 
								'.', '.', '.', '.', '.', '.', 
								'.', '.', '.', '.', '.', '.', 
								'.', '.', '.', '.', '.', '.', 
								'.', '.', '.', '.', '.', '.' };

	return SolveFutoshiki(Numeral_Inputs, betweenColsChar, betweenRowsChar, 6);
}

bool TestInput6_1()
{
	int Numeral_Inputs[] = { 0, 0, 0, 0, 0, 0,
							 0, 0, 5, 4, 0, 0,
							 0, 6, 4, 1, 5, 0,
							 0, 3, 2, 6, 4, 0,
							 0, 0, 1, 2, 0, 0,
							 0, 0, 0, 0, 0, 0 };


	char betweenColsChar[] = {  '<', '.', '.', '.', '.',
								'.', '.', '.', '.', '<',
								'.', '.', '.', '.', '.',
								'.', '.', '.', '.', '<',
								'.', '.', '.', '.', '.',
								'.', '.', '.', '.', '.' };

	char betweenRowsChar[] = {  'v', '.', '.', '.', '.', '.',
								'.', '.', '.', '.', '.', '.',
								'.', '.', '.', '.', '.', '.',
								'.', '.', '.', '.', '.', '.',
								'.', '.', '.', '.', '.', '.' };

	return SolveFutoshiki(Numeral_Inputs, betweenColsChar, betweenRowsChar, 6);
}