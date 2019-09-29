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
bool TestInput6_2()
{
	int Numeral_Inputs[] = { 0, 0, 6, 4, 0, 0,
							 2, 0, 0, 0, 0, 6,
							 0, 0, 0, 0, 0, 0,
							 0, 0, 0, 0, 0, 0,
							 5, 0, 0, 0, 0, 2,
							 0, 0, 3, 2, 0, 0 };

	 
	char betweenColsChar[] = {  '.', '.', '.', '.', '>',
								'.', '.', '.', '.', '.',
								'>', '.', '<', '.', '.',
								'<', '.', '.', '.', '.',
								'.', '.', '.', '.', '.',
								'.', '.', '.', '<', '.' };

	char betweenRowsChar[] = {  '.', '.', '.', '^', '.', '.',
								'.', '.', '.', '.', '.', '.',
								'.', '.', 'v', '.', '.', '.',
								'.', '.', 'v', '.', '.', '.',
								'.', '.', '.', '.', '.', '.' };

	return SolveFutoshiki(Numeral_Inputs, betweenColsChar, betweenRowsChar, 6);
}
bool TestInput6_3()
{
	int Numeral_Inputs[] = { 3, 0, 0, 0, 0, 1,
							 0, 0, 0, 0, 0, 0,
							 0, 3, 2, 5, 4, 0,
							 0, 2, 1, 6, 3, 0,
							 0, 0, 0, 0, 0, 0,
							 5, 0, 0, 0, 0, 4 };


	char betweenColsChar[] = {  '.', '.', '.', '.', '.',
								'.', '.', '>', '.', '.',
								'.', '.', '.', '.', '.',
								'.', '.', '.', '.', '.',
								'<', '.', '.', '.', '.',
								'.', '.', '.', '.', '<' };

	char betweenRowsChar[] = {  '.', '.', '.', '.', '.', '.',
								'.', 'v', '.', '.', '.', '.',
								'.', '.', '.', '.', '.', '.',
								'.', '.', '.', '.', '.', '.',
								'.', '.', '.', '.', '.', '.' };

	return SolveFutoshiki(Numeral_Inputs, betweenColsChar, betweenRowsChar, 6);
}
bool TestInput6_4()
{
	int Numeral_Inputs[] = { 0, 0, 4, 3, 0, 0,
							 0, 0, 3, 4, 0, 0,
							 0, 0, 1, 6, 0, 0,
							 0, 0, 2, 5, 0, 0,
							 0, 0, 6, 1, 0, 0,
							 0, 0, 5, 2, 0, 0 };


	char betweenColsChar[] = {  '.', '<', '.', '.', '>',
								'.', '.', '.', '.', '>',
								'<', '.', '.', '.', '.',
								'.', '<', '.', '.', '.',
								'.', '.', '.', '.', '<',
								'.', '.', '.', '.', '.' };

	char betweenRowsChar[] = {  '.', '.', '.', '.', '.', 'v',
								'.', '.', '.', '.', '.', '.',
								'.', '.', '.', '.', 'v', '.',
								'.', '.', '.', '.', '.', '.',
								'.', '^', '.', '.', '.', '.' };

	return SolveFutoshiki(Numeral_Inputs, betweenColsChar, betweenRowsChar, 6);
}
bool TestInput6_5()
{
	int Numeral_Inputs[] = { 0, 0, 0, 0, 0, 0,
							 0, 0, 0, 0, 0, 0,
							 0, 0, 0, 0, 0, 0,
							 0, 0, 0, 0, 0, 0,
							 0, 0, 0, 0, 0, 0,
							 0, 0, 0, 0, 0, 0 };


	char betweenColsChar[] = { '.', '.', '.', '.', '.',
								'.', '.', '.', '.', '.',
								'.', '.', '.', '.', '.',
								'.', '.', '.', '.', '.',
								'.', '.', '.', '.', '.',
								'.', '.', '.', '.', '.' };

	char betweenRowsChar[] = { '.', '.', '.', '.', '.', '.',
								'.', '.', '.', '.', '.', '.',
								'.', '.', '.', '.', '.', '.',
								'.', '.', '.', '.', '.', '.',
								'.', '.', '.', '.', '.', '.' };

	return SolveFutoshiki(Numeral_Inputs, betweenColsChar, betweenRowsChar, 6);
}
bool TestInput6_6()
{
	int Numeral_Inputs[] = { 0, 0, 0, 0, 0, 0,
							 0, 0, 0, 0, 0, 0,
							 0, 0, 0, 0, 0, 0,
							 0, 0, 0, 0, 0, 0,
							 0, 0, 0, 0, 0, 0,
							 0, 0, 0, 0, 0, 0 };


	char betweenColsChar[] = {  '.', '.', '.', '.', '.',
								'.', '.', '.', '.', '.',
								'.', '.', '.', '.', '.',
								'.', '.', '.', '.', '.',
								'.', '.', '.', '.', '.',
								'.', '.', '.', '.', '.' };

	char betweenRowsChar[] = {  '.', '.', '.', '.', '.', '.',
								'.', '.', '.', '.', '.', '.',
								'.', '.', '.', '.', '.', '.',
								'.', '.', '.', '.', '.', '.',
								'.', '.', '.', '.', '.', '.' };

	return SolveFutoshiki(Numeral_Inputs, betweenColsChar, betweenRowsChar, 6);
}
bool TestInput6_7()
{
	int Numeral_Inputs[] = { 0, 0, 0, 0, 0, 0,
							 0, 0, 0, 0, 0, 0,
							 0, 0, 0, 0, 0, 0,
							 0, 0, 0, 0, 0, 0,
							 0, 0, 0, 0, 0, 0,
							 0, 0, 0, 0, 0, 0 };


	char betweenColsChar[] = { '.', '.', '.', '.', '.',
								'.', '.', '.', '.', '.',
								'.', '.', '.', '.', '.',
								'.', '.', '.', '.', '.',
								'.', '.', '.', '.', '.',
								'.', '.', '.', '.', '.' };

	char betweenRowsChar[] = { '.', '.', '.', '.', '.', '.',
								'.', '.', '.', '.', '.', '.',
								'.', '.', '.', '.', '.', '.',
								'.', '.', '.', '.', '.', '.',
								'.', '.', '.', '.', '.', '.' };

	return SolveFutoshiki(Numeral_Inputs, betweenColsChar, betweenRowsChar, 6);
}
bool TestInput6_8()
{
	int Numeral_Inputs[] = { 0, 0, 0, 0, 0, 0,
							 0, 0, 0, 0, 0, 0,
							 0, 0, 0, 0, 0, 0,
							 0, 0, 0, 0, 0, 0,
							 0, 0, 0, 0, 0, 0,
							 0, 0, 0, 0, 0, 0 };


	char betweenColsChar[] = { '.', '.', '.', '.', '.',
								'.', '.', '.', '.', '.',
								'.', '.', '.', '.', '.',
								'.', '.', '.', '.', '.',
								'.', '.', '.', '.', '.',
								'.', '.', '.', '.', '.' };

	char betweenRowsChar[] = { '.', '.', '.', '.', '.', '.',
								'.', '.', '.', '.', '.', '.',
								'.', '.', '.', '.', '.', '.',
								'.', '.', '.', '.', '.', '.',
								'.', '.', '.', '.', '.', '.' };

	return SolveFutoshiki(Numeral_Inputs, betweenColsChar, betweenRowsChar, 6);
}
bool TestInput6_9()
{
	int Numeral_Inputs[] = { 0, 0, 0, 0, 0, 0,
							 0, 0, 0, 0, 0, 0,
							 0, 0, 0, 0, 0, 0,
							 0, 0, 0, 0, 0, 0,
							 0, 0, 0, 0, 0, 0,
							 0, 0, 0, 0, 0, 0 };


	char betweenColsChar[] = { '.', '.', '.', '.', '.',
								'.', '.', '.', '.', '.',
								'.', '.', '.', '.', '.',
								'.', '.', '.', '.', '.',
								'.', '.', '.', '.', '.',
								'.', '.', '.', '.', '.' };

	char betweenRowsChar[] = { '.', '.', '.', '.', '.', '.',
								'.', '.', '.', '.', '.', '.',
								'.', '.', '.', '.', '.', '.',
								'.', '.', '.', '.', '.', '.',
								'.', '.', '.', '.', '.', '.' };

	return SolveFutoshiki(Numeral_Inputs, betweenColsChar, betweenRowsChar, 6);
}
bool TestInput6_10()
{
	int Numeral_Inputs[] = { 0, 0, 0, 0, 0, 0,
							 0, 0, 0, 0, 0, 0,
							 0, 0, 0, 0, 0, 0,
							 0, 0, 0, 0, 0, 0,
							 0, 0, 0, 0, 0, 0,
							 0, 0, 0, 0, 0, 0 };


	char betweenColsChar[] = { '.', '.', '.', '.', '.',
								'.', '.', '.', '.', '.',
								'.', '.', '.', '.', '.',
								'.', '.', '.', '.', '.',
								'.', '.', '.', '.', '.',
								'.', '.', '.', '.', '.' };

	char betweenRowsChar[] = { '.', '.', '.', '.', '.', '.',
								'.', '.', '.', '.', '.', '.',
								'.', '.', '.', '.', '.', '.',
								'.', '.', '.', '.', '.', '.',
								'.', '.', '.', '.', '.', '.' };

	return SolveFutoshiki(Numeral_Inputs, betweenColsChar, betweenRowsChar, 6);
}