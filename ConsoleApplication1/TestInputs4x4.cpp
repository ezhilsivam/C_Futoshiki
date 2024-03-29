#include "pch.h"
#include <iostream>
#include "conio.h"

bool TestInput4x4()
{
	PRINTMSG;
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
	PRINTMSG;
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
bool TestInput4_2()
{
	PRINTMSG;
	int Numeral_Inputs[] = { 0, 0, 0, 0,
							 0, 0, 0, 0,
							 0, 2, 0, 0,
							 0, 0, 1, 0 };

	char betweenColsChar[] = { '.', '.', '.',
							   '<', '.', '.',
							   '.', '.', '>',
							   '.', '.', '.' };

	char betweenRowsChar[] = { '.', '.', 'v', '.',
							   '.', '.', '.', '.',
							   '.', '.', '.', 'v' };

	return SolveFutoshiki(Numeral_Inputs, betweenColsChar, betweenRowsChar, 4);
}
bool TestInput4_3()
{
	PRINTMSG;
	int Numeral_Inputs[] = { 0, 0, 0, 0,
							 0, 1, 0, 0,
							 0, 0, 2, 0,
							 0, 0, 0, 3 };

	char betweenColsChar[] = { '.', '.', '<',
							   '.', '.', '.',
							   '.', '.', '.',
							   '.', '.', '.' };

	char betweenRowsChar[] = { '.', '.', '.', '.',
							   '.', '.', '.', '.',
							   '.', '.', 'v', '.' };

	return SolveFutoshiki(Numeral_Inputs, betweenColsChar, betweenRowsChar, 4);
}
bool TestInput4_4()
{
	PRINTMSG;int Numeral_Inputs[] = { 0, 4, 0, 0,
							 0, 0, 0, 0,
							 0, 0, 0, 0,
							 0, 0, 0, 0 };

	char betweenColsChar[] = { '.', '.', '.',
							   '.', '.', '.',
							   '.', '.', '>',
							   '>', '.', '.' };

	char betweenRowsChar[] = { '.', '.', 'v', '.',
							   '.', '.', '.', '.',
							   'v', '^', '.', '.' };

	return SolveFutoshiki(Numeral_Inputs, betweenColsChar, betweenRowsChar, 4);
}
bool TestInput4_5()
{
	PRINTMSG;
	int Numeral_Inputs[] = { 4, 2, 3, 1,
							 0, 0, 0, 0,
							 0, 0, 0, 0,
							 2, 4, 1, 3 };

	char betweenColsChar[] = { '.', '.', '.',
							   '.', '>', '.',
							   '.', '.', '.',
							   '.', '.', '.' };

	char betweenRowsChar[] = { '.', '.', '.', '.',
							   '.', '.', '.', '.',
							   '.', '.', '.', '.' };

	return SolveFutoshiki(Numeral_Inputs, betweenColsChar, betweenRowsChar, 4);
}
bool TestInput4_6()
{
	PRINTMSG;
	int Numeral_Inputs[] = { 0, 0, 0, 3,
							 0, 0, 0, 0,
							 0, 0, 0, 0,
							 1, 0, 4, 0 };

	char betweenColsChar[] = { '.', '.', '.',
							   '.', '.', '.',
							   '.', '.', '.',
							   '.', '.', '.' };

	char betweenRowsChar[] = { '.', '.', '.', '.',
							   '^', '.', '.', '.',
							   '.', 'v', '.', '.' };

	return SolveFutoshiki(Numeral_Inputs, betweenColsChar, betweenRowsChar, 4);
}
bool TestInput4_7()
{
	PRINTMSG;
	int Numeral_Inputs[] = { 0, 4, 2, 0,
							 0, 0, 0, 0,
							 0, 0, 0, 0,
							 0, 0, 4, 0 };

	char betweenColsChar[] = { '.', '.', '.',
							   '>', '.', '.',
							   '.', '.', '>',
							   '.', '.', '.' };

	char betweenRowsChar[] = { '.', '.', '.', '.',
							   '.', '.', '.', '.',
							   '.', '.', '.', '.' };

	return SolveFutoshiki(Numeral_Inputs, betweenColsChar, betweenRowsChar, 4);
}
bool TestInput4_8()
{
	PRINTMSG;
	int Numeral_Inputs[] = { 4, 0, 0, 0,
							 0, 0, 0, 0,
							 0, 0, 0, 0,
							 0, 0, 0, 0 };

	char betweenColsChar[] = { '.', '.', '.',
							   '.', '.', '.',
							   '.', '.', '.',
							   '.', '<', '.' };

	char betweenRowsChar[] = { '.', '.', '.', '^',
							   'v', '.', '.', '.',
							   '.', '^', 'v', '.' };

	return SolveFutoshiki(Numeral_Inputs, betweenColsChar, betweenRowsChar, 4);
}
bool TestInput4_9()
{
	PRINTMSG;
	int Numeral_Inputs[] = { 0, 0, 0, 0,
							 0, 3, 0, 2,
							 0, 0, 4, 0,
							 0, 0, 0, 0 };

	char betweenColsChar[] = { '.', '.', '.',
							   '.', '.', '.',
							   '>', '.', '.',
							   '.', '.', '>' };

	char betweenRowsChar[] = { '.', '.', '.', '.',
							   '.', '.', '.', '.',
							   '.', '.', '.', '.' };

	return SolveFutoshiki(Numeral_Inputs, betweenColsChar, betweenRowsChar, 4);
}
bool TestInput4_10()
{
	PRINTMSG;
	int Numeral_Inputs[] = { 4, 1, 3, 2,
							 0, 0, 0, 0,
							 0, 0, 0, 0,
							 1, 3, 2, 4 };

	char betweenColsChar[] = { '.', '.', '.',
							   '.', '.', '.',
							   '.', '.', '.',
							   '.', '.', '.' };

	char betweenRowsChar[] = { '.', '.', '.', '.',
							   '.', '.', '.', '.',
							   '.', '^', '.', '.' };

	return SolveFutoshiki(Numeral_Inputs, betweenColsChar, betweenRowsChar, 4);
}