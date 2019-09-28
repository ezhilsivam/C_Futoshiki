#include "pch.h"
#include <iostream>
#include "conio.h"

bool TestInput4x4()
{
	int Numeral_Inputs[] = { 0, 0, 0, 0,
							 0, 0, 0, 0,
							 0, 0, 0, 0,
							 0, 0, 0, 0 };

	char betweenColsChar[] = { '.', '.', '.',
							   '.', '.', '.',
							   '.', '.', '.',
							   '.', '.', '.'  };

	char betweenRowsChar[] = { '.', '.', '.', '.', 
							   '.', '.', '.', '.', 
							   '.', '.', '.', '.' };

	return SolveFutoshiki(Numeral_Inputs, betweenColsChar, betweenRowsChar, 4);
}

bool TestInput4_1()
{
	int Numeral_Inputs[] = { 0, 1, 0, 0,
							 0, 0, 0, 0,
							 0, 4, 0, 0,
							 0, 0, 4, 0 };

	char betweenColsChar[] = { '.', '.', '.',
							   '>', '.', '.',
							   '.', '.', '>',
							   '.', '.', '.' };

	char betweenRowsChar[] = { 'v', '.', '.', '.',
							   '.', '.', '.', '.',
							   '^', '.', '.', '.' };

	return SolveFutoshiki(Numeral_Inputs, betweenColsChar, betweenRowsChar, 4);
}