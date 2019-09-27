#include "pch.h"
#include <iostream>
#include "conio.h"

bool TestInput5x5()
{
	int Numeral_Inputs[] = { 0, 0, 0, 0, 0,
							 0, 0, 0, 0, 0,
							 0, 0, 0, 0, 0,
							 0, 0, 0, 0, 0,
							 0, 0, 0, 0, 0 };

	char betweenColsChar[] = { '.', '.', '.', '.',
							   '.', '.', '.', '.',
							   '.', '.', '.', '.',
							   '.', '.', '.', '.',
							   '.', '.', '.', '.' };

	char betweenRowsChar[] = { '.', '.', '.', '.', '.',
							   '.', '.', '.', '.', '.',
							   '.', '.', '.', '.', '.',
							   '.', '.', '.', '.', '.' };
	return SolveFutoshiki(Numeral_Inputs, betweenColsChar, betweenRowsChar, 5);
}

bool TestInput5_1()
{
	int Numeral_Inputs[] = { 1, 3, 4, 2, 5,
							 0, 0, 0, 0, 0,
							 0, 0, 0, 0, 0,
							 0, 0, 0, 0, 0,
							 4, 5, 2, 3, 1 };

	char betweenColsChar[] = { '.', '.', '.', '.',
							   '.', '.', '.', '.',
							   '.', '.', '>', '.',
							   '.', '.', '.', '.',
							   '.', '.', '.', '<' };

	char betweenRowsChar[] = { '.', '^', '.', '.', '.',
								'.', '.', '.', '.', '.',
								'.', '.', '.', '.', '.',
								'.', '.', '^', '.', '.' };
	return SolveFutoshiki(Numeral_Inputs, betweenColsChar, betweenRowsChar, 5);
}
bool TestInput5_2()
{
	int Numeral_Inputs[] = { 0, 0, 0, 1, 0,
							 0, 0, 0, 0, 0,
							 0, 0, 0, 0, 0,
							 3, 0, 0, 0, 0,
							 0, 3, 0, 0, 0 };

	char betweenColsChar[] = { '<', '.', '.', '.',
							   '.', '.', '>', '.',
							   '>', '.', '>', '.',
							   '.', '.', '.', '.',
							   '>', '.', '.', '<' };

	char betweenRowsChar[] = { '.', '.', 'v', '.', '.',
								'.', '.', '.', '.', '.',
								'.', '.', '.', '^', '.',
								'.', '.', '.', '.', '.' };
	return SolveFutoshiki(Numeral_Inputs, betweenColsChar, betweenRowsChar, 5);
}
bool TestInput5_3()
{
	int Numeral_Inputs[] = { 0, 2, 0, 3, 0,
							 0, 1, 0, 2, 0,
							 5, 0, 0, 0, 2,
							 0, 5, 0, 4, 0,
							 0, 3, 0, 5, 0 };

	char betweenColsChar[] = { '.', '.', '.', '.',
							   '.', '.', '.', '.',
							   '.', '.', '.', '.',
							   '.', '.', '.', '.',
							   '.', '.', '.', '.' };

	char betweenRowsChar[] = { '.', '.', '.', '.', '.',
							   '.', '.', '.', '.', '.',
							   '.', '.', '.', '.', '.',
							   'v', '.', 'v', '.', '.' };
	return SolveFutoshiki(Numeral_Inputs, betweenColsChar, betweenRowsChar, 5);
}
bool TestInput5_4()
{
	int Numeral_Inputs[] = { 0, 0, 0, 0, 0,
							 0, 0, 0, 5, 0,
							 0, 0, 0, 0, 0,
							 0, 2, 0, 0, 0,
							 0, 0, 1, 0, 0 };

	char betweenColsChar[] = { '.', '.', '.', '.',
							   '.', '.', '.', '.',
							   '.', '.', '.', '.',
							   '>', '.', '.', '.',
							   '.', '.', '.', '.' };

	char betweenRowsChar[] = { 'v', '.', '.', '.', '.',
							   '.', '.', '.', '.', '^',
							   'v', '.', '.', 'v', '.',
							   '^', '.', '.', '.', '^' };
	return SolveFutoshiki(Numeral_Inputs, betweenColsChar, betweenRowsChar, 5);
}
bool TestInput5_5()
{
	int Numeral_Inputs[] = { 0, 0, 0, 0, 0,
							 4, 5, 0, 3, 2,
							 0, 4, 0, 5, 0,
							 1, 3, 0, 2, 5,
							 0, 0, 0, 0, 0 };

	char betweenColsChar[] = { '.', '.', '.', '.',
							   '.', '.', '.', '.',
							   '.', '.', '.', '.',
							   '.', '.', '.', '.',
							   '.', '.', '>', '.' };

	char betweenRowsChar[] = { '^', '.', '.', '.', '.',
							   '.', '.', '.', '.', '.',
							   '.', '.', '.', '.', '.',
							   '.', '.', '.', '.', '.' };
	return SolveFutoshiki(Numeral_Inputs, betweenColsChar, betweenRowsChar, 5);
}
bool TestInput5_6()
{
	int Numeral_Inputs[] = { 3, 0, 0, 0, 0,
							 0, 0, 0, 0, 0,
							 0, 0, 0, 0, 0,
							 5, 0, 0, 0, 0,
							 0, 0, 0, 0, 3 };

	char betweenColsChar[] = { '<', '<', '.', '.',
							   '.', '<', '.', '.',
							   '<', '>', '.', '.',
							   '.', '.', '.', '.',
							   '.', '.', '<', '.' };

	char betweenRowsChar[] = { '.', '.', '.', '.', '.',
							   '.', '.', '.', '.', '^',
							   '.', '.', '.', '.', '.',
							   '.', '.', '.', '.', '.' };
	return SolveFutoshiki(Numeral_Inputs, betweenColsChar, betweenRowsChar, 5);
}
bool TestInput5_7()
{
	int Numeral_Inputs[] = { 0, 0, 0, 0, 0,
							 3, 0, 5, 0, 0,
							 0, 0, 0, 0, 0,
							 0, 0, 0, 0, 2,
							 0, 0, 0, 0, 0 };

	char betweenColsChar[] = { '>', '.', '.', '.',
							   '>', '.', '.', '>',
							   '.', '.', '.', '.',
							   '.', '.', '.', '.',
							   '<', '<', '.', '.' };

	char betweenRowsChar[] = { '.', '.', '.', '.', '.',
							   '.', '.', '.', '.', '.',
							   '.', '.', '.', '.', '.',
							   '^', '.', '.', '.', '.' };
	return SolveFutoshiki(Numeral_Inputs, betweenColsChar, betweenRowsChar, 5);
}
bool TestInput5_8()
{
	int Numeral_Inputs[] = { 0, 3, 5, 1, 0,
							 0, 2, 0, 5, 0,
							 0, 0, 0, 0, 0,
							 0, 5, 0, 3, 0,
							 0, 4, 3, 2, 0 };


	char betweenColsChar[] = { '>', '.', '.', '.',
							   '.', '.', '.', '.',
							   '.', '.', '.', '.',
							   '.', '.', '.', '.',
							   '.', '.', '.', '<' };

	char betweenRowsChar[] = { '.', '.', '.', '.', '.',
								'.', '.', '.', '.', '^',
								'.', '.', '.', '.', '.',
								'.', '.', '.', '.', '.' };
	bool solved = false;
	solved = SolveFutoshiki(Numeral_Inputs, betweenColsChar, betweenRowsChar, 5);
	if (solved) PRINT << "* * * * * *\n" << "S O L V E D\n" << "* * * * * *\n";
	else PRINT << "- - - - - -\n" << "NOT S O L V E D\n" << "- - - - - -\n";
	return solved;
}
bool TestInput5_9()
{
	int Numeral_Inputs[] = { 0, 0, 0, 0, 0,
							 5, 1, 0, 2, 3,
							 1, 0, 0, 0, 4,
							 4, 5, 0, 3, 2,
							 0, 0, 0, 0, 0 };

	char betweenColsChar[] = { '.', '.', '.', '>',
							   '.', '.', '.', '.',
							   '.', '>', '.', '.',
							   '.', '.', '.', '.',
							   '.', '.', '.', '.' };

	char betweenRowsChar[] = { '.', '.', '.', '.', '.',
							   '.', '.', '.', '.', '.',
							   '.', '.', '.', '.', '.',
							   '.', '.', '.', '.', '.' };
	return SolveFutoshiki(Numeral_Inputs, betweenColsChar, betweenRowsChar, 5);
}

bool TestInput5_2000()
{
	int Numeral_Inputs[] = { 0, 0, 0, 0, 3,
							 0, 0, 0, 0, 0,
							 0, 0, 0, 0, 0,
							 0, 0, 0, 0, 0,
							 0, 0, 0, 0, 0 };

	char betweenColsChar[] = { '>', '.', '.', '.',
							   '.', '>', '<', '.',
							   '.', '.', '<', '>',
							   '>', '.', '.', '.',
							   '.', '>', '.', '.' };

	char betweenRowsChar[] = { '.', '.', '.', '.', '.',
							   '.', '.', '.', '.', '.',
							   '.', '.', '.', '^', 'v',
							   '^', '.', '.', '.', '.' };
	return SolveFutoshiki(Numeral_Inputs, betweenColsChar, betweenRowsChar, 5);
}
bool UserInput()
{
	return SolveFutoshiki(nullptr, nullptr, nullptr, 0);
}