// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//******************************************************************************
// D=Done,Tested	I=InProgress	T=Done,ToBeTested
//
// Requirements / steps
//
//  Input (Numerals)
//	- Allocate memory for numerals
//  - Get input from user
//  - Check input Valididy
//		- Individual # should not exceed Game-size
//		- Numbers should not repeat within same column / rows
//
//  Input (Spl Characters -- <, >, v, ^)
//  - Allocate memory for SplChars
//  - Get input from user
//		- Row input
//		- Column input
//	 
//
// For Testing
// 
//  - Print 
//
// Output


#include "pch.h"
#include <iostream>
#include "conio.h"
#include <time.h>

#pragma once
#include <iostream>

bool CatchRegression4x4()
{
	bool result = true;
	result &= TestInput4_1();
	result &= TestInput4_2();
	result &= TestInput4_3();
	result &= TestInput4_4();
	result &= TestInput4_5();
	result &= TestInput4_6();
	result &= TestInput4_7();
	result &= TestInput4_8();
	result &= TestInput4_9();
	result &= TestInput4_10();

	if (!result) PRINTMSG << "Regression";
	return result;
}

bool CatchRegression5x5()
{
	bool result = true;
	result &= TestInput5_1(); // SOLVED
	result &= TestInput5_2(); // SOLVED
	result &= TestInput5_3(); // SOLVED
	result &= TestInput5_4(); // SOLVED
	result &= TestInput5_5(); // SOLVED
	result &= TestInput5_6(); // SOLVED
	result &= TestInput5_7(); // SOLVED
	result &= TestInput5_8(); // SOLVED
	result &= TestInput5_9(); // SOLVED
	result &= TestInput5_10();
	result &= TestInput5_2000();

	if (!result) PRINTMSG << "Regression";
	return result;
}

bool CatchRegression6x6()
{
	bool result = true;

	result &= TestInput6_1();
	result &= TestInput6_2();
	result &= TestInput6_3();
	result &= TestInput6_4();
	
	if (!result) PRINTMSG << "Regression";
	return result;
}
bool CatchRegression7x7()
{
	bool result = true;

	result &= TestInput7_1();
	result &= TestInput7_2();
	result &= TestInput7_3();

	if (!result) PRINTMSG << "Regression";
	return result;
}
bool CatchRegression8x8()
{
	bool result = true;

	result &= TestInput8_1();

	if (!result) PRINTMSG << "Regression";
	return result;
}
bool CatchRegression9x9()
{
	bool result = true;

	result &= TestInput9_1();
	//result &= TestInput9_2();

	if (!result) PRINTMSG << "Regression";
	return result;
}

bool CatchRegression()
{
	bool result = true;

	result &= CatchRegression4x4();
	result &= CatchRegression5x5();
	result &= CatchRegression6x6();
	result &= CatchRegression7x7();
	result &= CatchRegression8x8();
	result &= CatchRegression9x9();

	return result;
}

int main()
{
	double time_spent = 0.0;
	clock_t begin = clock();

	bool catchRegression = false;
	bool result = true;
	if (catchRegression)
	{
		result = CatchRegression();

		if (result)
			PRINTMSG << "\nALL PASS\n";
		else
			PRINTMSG << "\n !!! REGRESSION !!!\n";

	}
	else
		result = TestInput5_2000();

	// NOT SOLVED
	//result = TestInput5_2000();
	//result = TestInput9_1();

	clock_t end = clock();

	time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
	PRINT << "Time elpased is : " << time_spent << "seconds";
	return result;
}


bool SolveFutoshiki(int* Numeral_Input_fromOutside, char *betweenColsChar, char*betweenRowsChar, int Test_game_size)
{
	GLOBALS g = { 0 };
	int Total_Boxes;
	bool num_input_error = false;

	// Obtain Numeral Input from User
	if (Numeral_Input_fromOutside == nullptr)
	{
		PRINTMSG << "Game Size: ";
		SCAN >> g.Game_Size;
		Total_Boxes = g.Game_Size * g.Game_Size;
		g.Total_Boxes = Total_Boxes;

		// Allocate memory for input array
		g.Numeral_Inputs = (int*)malloc(Total_Boxes * sizeof(int));
		memset(g.Numeral_Inputs, 0, Total_Boxes * sizeof(int));

		g.RowSolvedCount = (int*)malloc(g.Game_Size * sizeof(int));
		memset(g.RowSolvedCount, 0, g.Game_Size * sizeof(int));

		g.ColSolvedCount = (int*)malloc(g.Game_Size * sizeof(int));
		memset(g.ColSolvedCount, 0, g.Game_Size * sizeof(int));

		for (int row = 0; row < g.Game_Size; row++) {
			PRINTMSG << "Input Numerals {Row:" << row + 1 << "}";
			for (int col = 0; col < g.Game_Size; col++) {
				SCAN >> ARRAY2D(g.Numeral_Inputs, row, col, g.Game_Size);
				/*if (row == 1 && col ==1) ARRAY2D(g.Numeral_Inputs, row, col, Game_Size) = 2;
				else ARRAY2D(g.Numeral_Inputs, row, col, Game_Size) = 0;*/
				if (ARRAY2D(g.Numeral_Inputs, row, col, g.Game_Size) > g.Game_Size)
					num_input_error = true;
			}
		}
	}
	else
	{
		g.Numeral_Inputs = Numeral_Input_fromOutside;
		g.Game_Size = Test_game_size;
		Total_Boxes = g.Game_Size * g.Game_Size;
		g.Total_Boxes = Total_Boxes;

		g.RowSolvedCount = (int*)malloc(g.Game_Size * sizeof(int));
		memset(g.RowSolvedCount, 0, g.Game_Size * sizeof(int));

		g.ColSolvedCount = (int*)malloc(g.Game_Size * sizeof(int));
		memset(g.ColSolvedCount, 0, g.Game_Size * sizeof(int));
	}
	CHECK_USER_INPUT_ERROR;

	// Allocate memory for Box attr array
	g.boxattr = (BOX_ATTR*)malloc(Total_Boxes * sizeof(BOX_ATTR));
	memset(g.boxattr, 0, Total_Boxes * sizeof(BOX_ATTR));

	num_input_error = false;
	for (int row = 0; row < g.Game_Size; row++) {
		for (int col = 0; col < g.Game_Size; col++) {
			int numCheck = ARRAY2D(g.Numeral_Inputs, row, col, g.Game_Size);
			if (numCheck) {
				// Check other row elements
				for (int ccol = 0; ccol < g.Game_Size && ccol != col; ccol++)
					if (ARRAY2D(g.Numeral_Inputs, row, ccol, g.Game_Size) == numCheck) { num_input_error = true; break; };
				// Check other column elements
				for (int rrow = 0; rrow < g.Game_Size && rrow != row; rrow++)
					if (ARRAY2D(g.Numeral_Inputs, rrow, col, g.Game_Size) == numCheck) { num_input_error = true; break; };
			}
		}
	}
	CHECK_USER_INPUT_ERROR;

	// Initialize Each Box (also apply Input Numerals to Box)
	for (int row = 0; row < g.Game_Size; row++) {
		for (int col = 0; col < g.Game_Size; col++) {
			int * ptr = NULL;
			ptr = (int*)malloc(g.Game_Size * sizeof(int));
			ARRAY2D(g.boxattr, row, col, g.Game_Size).box_possible = ptr;
			memset(ARRAY2D(g.boxattr, row, col, g.Game_Size).box_possible, 0, g.Game_Size * sizeof(int));

			int __usr_ip = ARRAY2D(g.Numeral_Inputs, row, col, g.Game_Size);
			if (__usr_ip != 0) {
				ARRAY2D(g.boxattr, row, col, g.Game_Size).box_possible[__usr_ip - 1] = __usr_ip;
				ARRAY2D(g.boxattr, row, col, g.Game_Size).count = 1;
			}
			else {
				int __count = 0;
				for (int i = 0; i < g.Game_Size; i++)
				{
					ARRAY2D(g.boxattr, row, col, g.Game_Size).box_possible[i] = ++__count;
				}
				ARRAY2D(g.boxattr, row, col, g.Game_Size).count = __count;
			}
		}
	}

	// Allocate memory for betweenRows
	// Number of betweenRows = ((Game_Size - 1) * Game_Size) OR (Total_Boxes - Game_Size)
	g.betweenRows = (BOX_RELATIONS*)malloc((Total_Boxes - g.Game_Size) * sizeof(BOX_RELATIONS));
	memset(g.betweenRows, 0, (Total_Boxes - g.Game_Size) * sizeof(BOX_RELATIONS));
	// Allocate memory for betweenColumns
	g.betweenColumns = (BOX_RELATIONS*)malloc((Total_Boxes - g.Game_Size) * sizeof(BOX_RELATIONS));
	memset(g.betweenColumns, 0, (Total_Boxes - g.Game_Size) * sizeof(BOX_RELATIONS));

	// Obtain between colums input
	num_input_error = false;
	for (int row = 0; row < g.Game_Size; row++) {
#undef ELEM
#define ELEM ARRAY2D(g.betweenColumns, row, col, g.Game_Size-1)
		if (betweenColsChar == nullptr) PRINTMSG << "Input Between Colums {Row:" << row + 1 << "}";
		for (int col = 0; col < g.Game_Size - 1; col++) {
			if (betweenColsChar == nullptr) SCAN >> ELEM.splChar;
			else ELEM.splChar = ARRAY2D(betweenColsChar, row, col, g.Game_Size - 1);

			if (INVALIDCHAR_COL(ELEM.splChar))
			{
				PRINTMSG << "ERROR--" << ELEM.splChar << "--\n\n";
				num_input_error = true;
			}
			else {
				ELEM.isValid = false;
				if (ELEM.splChar == '<') {
					ELEM.isValid = true;
					ELEM.isBetweenRows = false;
					ELEM.lowcol = col;
					ELEM.highcol = col + 1;
				}
				else if (ELEM.splChar == '>') {
					ELEM.isValid = true;
					ELEM.isBetweenRows = false;
					ELEM.lowcol = col + 1;
					ELEM.highcol = col;
				}
				else {
					if (ELEM.splChar != '.') PRINTMSG << "SPL CHAR Validation ERROR";
				}
			}
		}
	}
	CHECK_USER_INPUT_ERROR;

	// Obtain between rows input
	num_input_error = false;
	for (int row = 0; row < g.Game_Size - 1; row++) {
#undef ELEM
#define ELEM ARRAY2D(g.betweenRows, row, col, g.Game_Size)
		if (betweenRowsChar == nullptr) PRINTMSG << "Input Between Rows {Row:" << row + 1 << "}";
		for (int col = 0; col < g.Game_Size; col++) {
			if (betweenRowsChar == nullptr) SCAN >> ELEM.splChar;
			else ELEM.splChar = ARRAY2D(betweenRowsChar, row, col, g.Game_Size);
			if (INVALIDCHAR_ROW(ELEM.splChar)) {
				PRINTMSG << "ERROR--" << ELEM.splChar << "--\n";
				num_input_error = true;
			}
			else {
				ELEM.isValid = false;
				if (ELEM.splChar == '^') {
					ELEM.isValid = true;
					ELEM.isBetweenRows = true;
					ELEM.lowrow = row;
					ELEM.highrow = row + 1;
				}
				else if (ELEM.splChar == 'v') {
					ELEM.isValid = true;
					ELEM.isBetweenRows = true;
					ELEM.lowrow = row + 1;
					ELEM.highrow = row;
				}
				else {
					if (ELEM.splChar != '.') PRINTMSG << "SPL CHAR Validation ERROR";
				}
			}
		}
	}
	CHECK_USER_INPUT_ERROR;

	PrintBoxAttrFormatted(&g, true);

	ManualAlgo(&g);

	bool sol = CheckSolution(&g);

	if (!sol)
		BacktrackingAlgo(&g);

	sol = CheckSolution(&g);

	if (sol)
	{
		PrintNumeralAttributefn(&g);
		//PrintNumeralFormattedfn(&g);
	}
	else
	{
		PrintNumeralAttributefn(&g);
		//PrintBoxAttrFormattedfn(&g, true);
	}

	if (sol) PRINT << "* * * * * *\n" << "S O L V E D\n" << "* * * * * *\n";
	else PRINT << "- - - - - - - -\n" << "NOT S O L V E D\n" << "- - - - - - - - \n";

	return sol;
}

void InitializeNumAttrArray(GLOBALS *g)
{
	g->numAttr = (NUM_ATTR*)malloc(g->Game_Size * g->Game_Size * sizeof(NUM_ATTR));
	memset(g->numAttr, 0, g->Game_Size * g->Game_Size * sizeof(NUM_ATTR));

	for (int row = 0; row < g->Game_Size; row++)
	{
		for (int col = 0; col < g->Game_Size; col++)
		{
			if (ARRAY2D(g->Numeral_Inputs, row, col, g->Game_Size) != 0)
			{
				ARRAY2D(g->numAttr, row, col, g->Game_Size).value = ARRAY2D(g->Numeral_Inputs, row, col, g->Game_Size);
				ARRAY2D(g->numAttr, row, col, g->Game_Size).IsUserIp = true;
				ARRAY2D(g->numAttr, row, col, g->Game_Size).IsFilled = true;
			}

		}
	}
}

bool BackTrackAndFill(GLOBALS* g)
{
	static int EntryCount = 0;
	if (++EntryCount % 10000000 == 0)
		PRINT << ++EntryCount << " ";
	for (int row = 0; row < g->Game_Size; row++)
	{
		for (int col = 0; col < g->Game_Size; col++)
		{
			if (ARRAY2D(g->numAttr, row, col, g->Game_Size).value == 0)
			{
				for (int number = 1; number <= g->Game_Size; number++)
				{
					if (isAllowed(g, row, col, number))
					{
						ARRAY2D(g->numAttr, row, col, g->Game_Size).value = number;
						ARRAY2D(g->numAttr, row, col, g->Game_Size).IsFilled = true;
						//PrintNumeralAttributefn(g);

						if (BackTrackAndFill(g))
						{
							return true;
						}
						else
						{
							ARRAY2D(g->numAttr, row, col, g->Game_Size).value = 0;
							ARRAY2D(g->numAttr, row, col, g->Game_Size).IsFilled = false;
						}
					}
				}
				return false;
			}
		}
	}
	return true;
}

bool isAllowed(GLOBALS* g, int row, int col, int number)
{
	return (!containsInCol(g, col, number) && 
			!containsInRow(g, row, number) && 
			!violatesBetweenColRelation(g, row, col, number) && 
			!violatesBetweenRowRelation(g, row, col, number));
}

bool BackTrackAndFill2(GLOBALS *g, int startIndex)
{
	if (startIndex == g->Total_Boxes)
	{
		// All boxes completed
		return true;
	}

	int row = startIndex / g->Game_Size;
	int col = startIndex % g->Game_Size;

	if (ARRAY2D(g->numAttr, row, col, g->Game_Size).IsUserIp)
	{

	}

	for (int pos = 1; pos <= g->Game_Size; pos++)
	{
		bool restriction = false;

		ARRAY2D(g->numAttr, row, col, g->Game_Size).value = pos;
		ARRAY2D(g->numAttr, row, col, g->Game_Size).IsFilled = true;

		// Validate Current Values 
		if (!restriction) // All conditions pass
		{
			if (BackTrackAndFill2(g, startIndex + 1))
				return true;
			else
			{
				// Retract to 
				ARRAY2D(g->numAttr, row, col, g->Game_Size).value = 0;
				ARRAY2D(g->numAttr, row, col, g->Game_Size).value = false;
				continue;
			}
		}
		else 
		{
			// Retract to 
			ARRAY2D(g->numAttr, row, col, g->Game_Size).value = 0;
			ARRAY2D(g->numAttr, row, col, g->Game_Size).value = false;
			continue;
		}
	}

	return false;
}

bool containsInRow(GLOBALS *g, int row, int num)
{
	bool contains= false;
	for (int col = 0; col < g->Game_Size; col++)
	{
		if (ARRAY2D(g->numAttr, row, col, g->Game_Size).value == num)
		{
			return true;
		}
	}
	return contains;
}

bool containsInCol(GLOBALS *g, int col, int num)
{
	bool contains = false;
	for (int row = 0; row < g->Game_Size; row++)
	{
		if (ARRAY2D(g->numAttr, row, col, g->Game_Size).value == num)
		{
			return true;
		}
	}
	return contains;
}

bool violatesBetweenColRelation(GLOBALS *g, int num_row, int col, int num)
{
	int rowsize = g->Game_Size - 1;
	int colsize = g->Game_Size;
	bool modified = false;

	int UpRowIndex = num_row - 1;
	int DownRowIndex = num_row;

	if (UpRowIndex >= 0 && ARRAY2D(g->betweenRows, UpRowIndex, col, colsize).isValid)
	{
		NUM_ATTR *lowBox = &ARRAY2D(g->numAttr, ARRAY2D(g->betweenRows, UpRowIndex, col, colsize).lowrow, col, g->Game_Size);
		NUM_ATTR *highBox = &ARRAY2D(g->numAttr, ARRAY2D(g->betweenRows, UpRowIndex, col, colsize).highrow, col, g->Game_Size);

		if ((num_row == ARRAY2D(g->betweenRows, UpRowIndex, col, colsize).lowrow && highBox->IsFilled && highBox->value < num) ||
			(num_row == ARRAY2D(g->betweenRows, UpRowIndex, col, colsize).highrow && lowBox->IsFilled && lowBox->value > num))
		{
			return true; // violates, relation with high box
		}
	}
	else if (DownRowIndex != g->Game_Size && ARRAY2D(g->betweenRows, DownRowIndex, col, colsize).isValid)
	{
		NUM_ATTR *lowBox = &ARRAY2D(g->numAttr, ARRAY2D(g->betweenRows, DownRowIndex, col, colsize).lowrow, col, g->Game_Size);
		NUM_ATTR *highBox = &ARRAY2D(g->numAttr, ARRAY2D(g->betweenRows, DownRowIndex, col, colsize).highrow, col, g->Game_Size);

		if ((num_row == ARRAY2D(g->betweenRows, DownRowIndex, col, colsize).lowrow && highBox->IsFilled && highBox->value < num) ||
			(num_row == ARRAY2D(g->betweenRows, DownRowIndex, col, colsize).highrow && lowBox->IsFilled && lowBox->value > num))
		{
			return true; // violates, relation with high box
		}
	}

	/*for (int row = 0; row < rowsize; row++) {
		if (ARRAY2D(g->betweenRows, row, col, colsize).isValid)
		{
			int lowrowIndex = ARRAY2D(g->betweenRows, row, col, colsize).lowrow;
			int highrowIndex = ARRAY2D(g->betweenRows, row, col, colsize).highrow;
			NUM_ATTR *lowBox = &ARRAY2D(g->numAttr, lowrowIndex, col, g->Game_Size);
			NUM_ATTR *highBox = &ARRAY2D(g->numAttr, highrowIndex, col, g->Game_Size);

			if (num_row == lowrowIndex)
			{
				if (highBox->IsFilled)
				{
					if (highBox->value > num)
					{
						return false; // agrees, relation with high box
					}
					return true; // violates relation with high box
				}
				return false;
			}
			else if (num_row == highrowIndex)
			{
				if (lowBox->IsFilled)
				{
					if (lowBox->value < num)
					{
						return false;
					}
					return true;
				}
				return false;
			}

		}
	}*/
	return false;
}

bool violatesBetweenRowRelation(GLOBALS *g, int row, int num_col, int num)
{
	int rowsize = g->Game_Size;
	int colsize = g->Game_Size - 1;

	int leftColIndex = num_col - 1;
	int rightColIndex = num_col;

	if (leftColIndex >= 0 && ARRAY2D(g->betweenColumns, row, leftColIndex, colsize).isValid)
	{
		NUM_ATTR *lowBox = &ARRAY2D(g->numAttr, row, ARRAY2D(g->betweenColumns, row, leftColIndex, colsize).lowcol, g->Game_Size);
		NUM_ATTR *highBox = &ARRAY2D(g->numAttr, row, ARRAY2D(g->betweenColumns, row, leftColIndex, colsize).highcol, g->Game_Size);

		if ((num_col == ARRAY2D(g->betweenColumns, row, leftColIndex, colsize).lowcol && 
			highBox->IsFilled && 
			highBox->value < num) || 
				(num_col == ARRAY2D(g->betweenColumns, row, leftColIndex, colsize).highcol &&
				lowBox->IsFilled &&
				lowBox->value > num))
		{
			return true;
		}
	}
	else if (rightColIndex != g->Game_Size && ARRAY2D(g->betweenColumns, row, rightColIndex, colsize).isValid)
	{
		NUM_ATTR *lowBox = &ARRAY2D(g->numAttr, row, ARRAY2D(g->betweenColumns, row, rightColIndex, colsize).lowcol, g->Game_Size);
		NUM_ATTR *highBox = &ARRAY2D(g->numAttr, row, ARRAY2D(g->betweenColumns, row, rightColIndex, colsize).highcol, g->Game_Size);

		if ((num_col == ARRAY2D(g->betweenColumns, row, rightColIndex, colsize).lowcol && 
			highBox->IsFilled && 
			highBox->value < num) || 
				(num_col == ARRAY2D(g->betweenColumns, row, rightColIndex, colsize).highcol &&
				lowBox->IsFilled &&
				lowBox->value > num))
		{
			return true; // violates, relation with high box
		}
	}

	/*for (int col = 0; col < colsize; col++) {
		if (ARRAY2D(g->betweenColumns, row, col, colsize).isValid)
		{
			int lowColIndex = ARRAY2D(g->betweenColumns, row, col, colsize).lowcol;
			int highColIndex = ARRAY2D(g->betweenColumns, row, col, colsize).highcol;
			NUM_ATTR *lowBox = &ARRAY2D(g->numAttr, row, lowColIndex, g->Game_Size);
			NUM_ATTR *highBox = &ARRAY2D(g->numAttr, row, highColIndex, g->Game_Size);

			if (num_col == lowColIndex)
			{
				if (highBox->IsFilled)
				{
					if (highBox->value > num)
					{
						return false; // agrees, relation with high box
					}
					return true; // violates relation with high box
				}
				return false; // high box is not filled, so proceed
			}
			else if (num_col == highColIndex)
			{
				if (lowBox->IsFilled)
				{
					if (lowBox->value < num)
					{
						return false;
					}
					return true;
				}
				return false;
			}
		}
	}*/
	

	return false;
}

void CopyNumAttrToNumeralInput(GLOBALS *g)
{
	for (int row = 0; row < g->Game_Size; row++)
	{
		for (int col = 0; col < g->Game_Size; col++)
		{
			if (!ARRAY2D(g->numAttr, row, col, g->Game_Size).IsUserIp && ARRAY2D(g->numAttr, row, col, g->Game_Size).IsFilled)
			{
				ARRAY2D(g->Numeral_Inputs, row, col, g->Game_Size) = ARRAY2D(g->numAttr, row, col, g->Game_Size).value;
			}
		}
	}
}

void BacktrackingAlgo(GLOBALS* g)
{
	PRINTMSG << "Try BackTracking\n";
	// Copy input Numerals to NumeralsWithAttr
	InitializeNumAttrArray(g);
	//PrintNumeralAttributefn(g);

	BackTrackAndFill(g);

	CopyNumAttrToNumeralInput(g);

	//PrintNumeralAttributefn(g);
}

void PrintNumeralAttributefn(GLOBALS* g)
{
	PRINT << "\n\n";
	for (int row = 0; row < g->Game_Size; row++) {
		for (int col = 0; col < g->Game_Size; col++) {
			PRINT << " _ _ " << " ";
		}
		PRINT << "\n";
		for (int col = 0; col < g->Game_Size; col++) {
			int num = ARRAY2D(g->numAttr, row, col, g->Game_Size).value;
			PRINT << "| ";
			if (num) PRINT << num;
			else
			{
				if (ARRAY2D(g->numAttr, row, col, g->Game_Size).IsUserIp)
					PRINT << ".";
				else
					PRINT << " ";
			}

			PRINT << " |";
			if (col != g->Game_Size - 1)
			{
				char rel = ARRAY2D(g->betweenColumns, row, col, g->Game_Size - 1).isValid ? ARRAY2D(g->betweenColumns, row, col, g->Game_Size - 1).splChar : ' ';
				PRINT << rel;
			}
		}
		PRINT << "\n";
		for (int col = 0; col < g->Game_Size; col++) {
			PRINT << "|_ _|" << " ";
		}
		PRINT << "\n";

		for (int col = 0; col < g->Game_Size; col++) {
			if (row != g->Game_Size - 1)
			{
				char rel = ARRAY2D(g->betweenRows, row, col, g->Game_Size).isValid ? ARRAY2D(g->betweenRows, row, col, g->Game_Size).splChar : ' ';
				PRINT << "  " << rel << "  " << " ";
			}
		}
		PRINT << "\n";
	}
}

void ManualAlgo(GLOBALS *g)
{
	static int LoopCount = 0;
	bool repeat = false;
	do {
		PRINTMSG << "LoopCount:" << ++LoopCount << "\n";
		repeat = false;
		if (UpdateBoxAttrNumerals(g))
		{
			PrintBoxAttrFormatted(g, true);
			PrintNumeralFormatted(g);
			repeat = true;
		}
		if (UpdateBoxAttrWithRowRelations(g))
		{
			if (g->NumeralUpdateNeeded)
			{
				UpdateBoxAttrNumerals(g);
			}
			g->NumeralUpdateNeeded = false;
			PrintBoxAttrFormatted(g, true);
			PrintNumeralFormatted(g);
			repeat = true;
		}
		if (UpdateBoxAttrWithColRelations(g))
		{
			if (g->NumeralUpdateNeeded)
			{
				UpdateBoxAttrNumerals(g);
			}
			g->NumeralUpdateNeeded = false;
			PrintBoxAttrFormatted(g, true);
			PrintNumeralFormatted(g);
			repeat = true;
		}
		if (FindNumeralsWithOnlyPossiblePosition(g))
		{
			if (g->NumeralUpdateNeeded)
			{
				UpdateBoxAttrNumerals(g);
			}
			g->NumeralUpdateNeeded = false;
			PrintBoxAttrFormatted(g, true);
			PrintNumeralFormatted(g);
			repeat = true;
		}
		if (FindPairsAndUpdateBoxattr(g))
		{
			if (g->NumeralUpdateNeeded)
			{
				UpdateBoxAttrNumerals(g);
				g->NumeralUpdateNeeded = false;
			}
			PrintBoxAttrFormatted(g, true);
			PrintNumeralFormatted(g);
			repeat = true;
		}

	} while (repeat);
}

void PrintBoxAttrFormattedfn(GLOBALS* g, bool PrintSplchar)
{
	int colRelPos = (g->Game_Size + 2) / 2;
	int colRelPosLen = g->Game_Size + 2;
	int gapbetCol = 3;

	PRINT << "\n\n";
	for (int row = 0; row < g->Game_Size; row++) {
		for (int col = 0; col < g->Game_Size; col++) {
			for (int i = 0; i < g->Game_Size; i++) {
				int __pos_val = ARRAY2D(g->boxattr, row, col, g->Game_Size).box_possible[i];
				if (__pos_val) {
					PRINT << ARRAY2D(g->boxattr, row, col, g->Game_Size).box_possible[i];
				}
				else {
					PRINT << " ";
				}
			}
			PRINT << "." << ARRAY2D(g->boxattr, row, col, g->Game_Size).count;
			if (col != g->Game_Size - 1)
			{
				if (ARRAY2D(g->betweenColumns, row, col, g->Game_Size - 1).isValid)
				{
					char splcr = ARRAY2D(g->betweenColumns, row, col, g->Game_Size - 1).splChar;
					if (PrintSplchar) PRINT << " " << splcr;
					else PRINT << "  ";
					/*if (splcr == '<' || splcr == '>')
					{
						PRINT << ARRAY2D(betweenCols, row, col, size-1).highcol << ARRAY2D(betweenCols, row, col, size-1).lowcol;
					}*/
					PRINT << " ";

				}
				else
					PRINT << "   ";
			}
		}
		PRINT << "\n";
		for (int col = 0; col < g->Game_Size; col++) {
			if (row != g->Game_Size - 1)
			{
				for (int j = 0; j < colRelPosLen + gapbetCol; j++)
				{
					if (j == colRelPos && ARRAY2D(g->betweenRows, row, col, g->Game_Size).isValid)
					{
						char splcr = ARRAY2D(g->betweenRows, row, col, g->Game_Size).splChar;
						if (PrintSplchar) PRINT << " " << splcr;
						else PRINT << "  ";
						/*if (splcr == '<' || splcr == '>')
						{
							PRINT << ARRAY2D(betweenRows, row, col, size).highcol << ARRAY2D(betweenRows, row, col, size).lowcol;
							j++; j++;
						}
						else if (splcr == '^' || splcr == 'v')
						{
							PRINT << ARRAY2D(betweenRows, row, col, size).highrow << ARRAY2D(betweenRows, row, col, size).lowrow;
							j++; j++;
						}*/
					}
					else
						PRINT << " ";
				}
			}
		}
		PRINT << "\n";
	}
}

void PrintNumeralFormattedfn(GLOBALS* g)
{
	PRINT << "\n\n";
	for (int row = 0; row < g->Game_Size; row++) {
		for (int col = 0; col < g->Game_Size; col++) {
			PRINT << " _ _ " << ".";
		}
		PRINT << "\n";
		for (int col = 0; col < g->Game_Size; col++) {
			int num = ARRAY2D(g->Numeral_Inputs, row, col, g->Game_Size);
			PRINT << "| ";
			if (num) PRINT << ARRAY2D(g->Numeral_Inputs, row, col, g->Game_Size);
			else PRINT << " ";

			PRINT << " |" << ".";
		}
		PRINT << "\n";
		for (int col = 0; col < g->Game_Size; col++) {
			PRINT << "|_ _|" << ".";
		}
		PRINT << "\n\n";
	}
}

bool UpdateBoxAttrNumerals(GLOBALS* g)
{
	static int EntryCount = 0;
	PRINTMSG << "EntryCount:" << ++EntryCount << "\n";

	bool modified = false;
	bool UpdateBoxAttrNumeralsAgain = false;

	for (int row = 0; row < g->Game_Size; row++) {
		for (int col = 0; col < g->Game_Size; col++) {
			int currNumeral = ARRAY2D(g->Numeral_Inputs, row, col, g->Game_Size);
			if (currNumeral != 0 && !ARRAY2D(g->boxattr, row, col, g->Game_Size).boxAttrUpdated)
			{
				// Iterate through the box attr Col and remove currNumeral from other boxes
				for (int boxrow = 0; boxrow < g->Game_Size; boxrow++) {
					if (boxrow != row) {
						if (ARRAY2D(g->boxattr, boxrow, col, g->Game_Size).count != 1)
						{
							BOX_ATTR *modifyBox = &ARRAY2D(g->boxattr, boxrow, col, g->Game_Size);
							modified |= RemoveNumeralFromPossibleList(modifyBox, currNumeral);
							if (modifyBox->count == 1) {
								UpdateNumeralsInputArray(g, boxrow, col);
								UpdateBoxAttrNumeralsAgain = true;
							}
						}
						//else PRINT << "ERROR Iterating through boxattr col" << row << col << "\n";
					}
				}

				// Iterate through the box attr row and remove currNumeral from other boxes
				for (int boxcol = 0; boxcol < g->Game_Size; boxcol++) {
					if (boxcol != col) {
						if (ARRAY2D(g->boxattr, row, boxcol, g->Game_Size).count != 1)
						{
							BOX_ATTR *modifyBox = &ARRAY2D(g->boxattr, row, boxcol, g->Game_Size);
							modified |= RemoveNumeralFromPossibleList(modifyBox, currNumeral);
							if (modifyBox->count == 1) {
								UpdateNumeralsInputArray(g, row, boxcol);
								UpdateBoxAttrNumeralsAgain = true;
							}
						}
						//else PRINT << "ERROR Iterating through boxattr row" << row << col << "\n";
					}
				}
				ARRAY2D(g->boxattr, row, col, g->Game_Size).boxAttrUpdated = true;
				
				g->RowSolvedCount[row]++;
				g->ColSolvedCount[col]++;

			}
			
		}
	}
	//return UpdateBoxAttrNumeralsAgain;

	if (UpdateBoxAttrNumeralsAgain) {
		UpdateBoxAttrNumerals(g);
	}
	
	if (!modified) PRINTMSG << "NOT Modified\n";
	return modified;
}

bool RemoveNumeralFromPossibleList(BOX_ATTR *modifyBox, int Numeral)
{
	//PRINTMSG << Numeral << "\n";

	if (modifyBox->box_possible[Numeral - 1] != 0)
	{
		modifyBox->box_possible[Numeral - 1] = 0;
		modifyBox->count--;
		return true;
	}

	return false;
}

// Update Only possible value in Numeral_Inputs
void UpdateNumeralsInputArray(GLOBALS*g, int row, int col)
{
	for (int k = 0; k < g->Game_Size; k++) {
		if (ARRAY2D(g->boxattr, row, col, g->Game_Size).box_possible[k] != 0) {
			ARRAY2D(g->Numeral_Inputs, row, col, g->Game_Size) = k + 1;
			g->NumeralUpdateNeeded = true;
		}
	}
}

int MaxPossible(int* boxPossible, int Game_Size)
{
	int Max = 0;
	for (int i = 0; i < Game_Size; i++)
		if (boxPossible[i] > Max) Max = boxPossible[i];
	if (Max == 0 || Max > Game_Size) PRINTMSG << "ERROR:" << Max << "\n";
	return Max;
}

int MinPossible(int* boxPossible, int Game_Size)
{
	int Min = Game_Size;
	for (int i = 0; i < Game_Size; i++)
		if ((boxPossible[i] != 0) && (boxPossible[i] < Min)) Min = boxPossible[i];

	return Min;
}

bool UpdateBoxAttrWithRowRelations(GLOBALS *g)
{
	static int EntryCount = 0;
	PRINTMSG << "EntryCount:" << ++EntryCount << "\n";

	int rowsize = g->Game_Size;
	int colsize = g->Game_Size - 1;
	bool modified = false;

	for (int row = 0; row < rowsize; row++) {
		for (int col = 0; col < colsize; col++) {
			if (ARRAY2D(g->betweenColumns, row, col, colsize).isValid)
			{
				int lowColIndex = ARRAY2D(g->betweenColumns, row, col, colsize).lowcol;
				int highColIndex = ARRAY2D(g->betweenColumns, row, col, colsize).highcol;
				BOX_ATTR *lowBox = &ARRAY2D(g->boxattr, row, lowColIndex, g->Game_Size);
				BOX_ATTR *highBox = &ARRAY2D(g->boxattr, row, highColIndex, g->Game_Size);
				int MinFromLowBox = MinPossible(lowBox->box_possible, g->Game_Size);
				int MaxFromHighBox = MaxPossible(highBox->box_possible, g->Game_Size);

				/*PRINTMSG << "\nCHAR:" << ARRAY2D(g->betweenColumns, row, col, colsize).splChar << row << col << "\n";
				PRINTMSG << "lowColIndex:" << lowColIndex;
				PRINTMSG << "highColIndex:" << highColIndex;
				PRINTMSG << "minFromLowBox" << MinFromLowBox;
				PRINTMSG << "maxFromHighBox" << MaxFromHighBox;
				PRINT << "\n";*/

				if (lowBox->count == 1 && highBox->count == 1)
				{
					ARRAY2D(g->betweenColumns, row, col, colsize).isValid = false;
					break;
				}

				for (int min = MinFromLowBox; min > 0; min--)
				{
					if (highBox->count != 1)
					{
						modified |= RemoveNumeralFromPossibleList(highBox, min);
						if (highBox->count == 1) {
							//PRINTMSG << "COUNT=1::" << row << " " << highColIndex << "\n";
							UpdateNumeralsInputArray(g, row, highColIndex);
						}
					}
				}

				for (int max = MaxFromHighBox; max <= g->Game_Size; max++)
				{
					if (lowBox->count != 1)
					{
						modified |= RemoveNumeralFromPossibleList(lowBox, max);
						if (lowBox->count == 1) {
							//PRINTMSG << "COUNT=1::" << row << " " << lowColIndex << "\n";
							UpdateNumeralsInputArray(g, row, lowColIndex);
						}
					}
				}

				//PrintBoxAttrFormatted(g, true);
			}
		}
	}
	if (!modified) PRINTMSG << "NOT Modified\n";
	return modified;
}

bool UpdateBoxAttrWithColRelations(GLOBALS *g)
{
	static int EntryCount = 0;
	PRINTMSG << "EntryCount:" << ++EntryCount << "\n";

	int rowsize = g->Game_Size - 1;
	int colsize = g->Game_Size;
	bool modified = false;

	for (int row = 0; row < rowsize; row++) {
		for (int col = 0; col < colsize; col++) {
			if (ARRAY2D(g->betweenRows, row, col, colsize).isValid)
			{
				int lowrowIndex = ARRAY2D(g->betweenRows, row, col, colsize).lowrow;
				int highrowIndex = ARRAY2D(g->betweenRows, row, col, colsize).highrow;
				BOX_ATTR *lowBox = &ARRAY2D(g->boxattr, lowrowIndex, col, g->Game_Size);
				BOX_ATTR *highBox = &ARRAY2D(g->boxattr, highrowIndex, col, g->Game_Size);
				int MinFromLowBox = MinPossible(lowBox->box_possible, g->Game_Size);
				int MaxFromHighBox = MaxPossible(highBox->box_possible, g->Game_Size);

				/*PRINTMSG << "\nCHAR:" << ARRAY2D(g->betweenColumns, row, col, colsize).splChar << row << col << "\n";
				PRINTMSG << "lowrowIndex:" << lowrowIndex;
				PRINTMSG << "highrowIndex:" << highrowIndex;
				PRINTMSG << "minFromLowBox" << MinFromLowBox;
				PRINTMSG << "maxFromHighBox" << MaxFromHighBox;
				PRINT << "\n";*/

				if (lowBox->count == 1 && highBox->count == 1)
				{
					ARRAY2D(g->betweenRows, row, col, colsize).isValid = false;
					break;
				}

				for (int min = MinFromLowBox; min > 0; min--)
				{
					if (highBox->count != 1) {
						modified |= RemoveNumeralFromPossibleList(highBox, min);
						if (highBox->count == 1) {
							UpdateNumeralsInputArray(g, highrowIndex, col);
						}
					}
				}

				for (int max = MaxFromHighBox; max <= g->Game_Size; max++)
				{
					if (lowBox->count != 1) {
						modified |= RemoveNumeralFromPossibleList(lowBox, max);
						if (lowBox->count == 1) {
							UpdateNumeralsInputArray(g, lowrowIndex, col);
						}
					}
				}

				//PrintBoxAttrFormatted(g, true);
			}
		}
	}
	if (!modified) PRINTMSG << "NOT Modified\n";
	return modified;
}

bool CheckSolution(GLOBALS* g)
{
	for (int row = 0; row < g->Game_Size; row++)
	{
		for (int col = 0; col < g->Game_Size; col++)
		{
			if (ARRAY2D(g->Numeral_Inputs, row, col, g->Game_Size) == 0)
			{
				return false;
				break;
			}
		}
	}
	return true;
}

bool FindNumeralsWithOnlyPossiblePosition(GLOBALS* g)
{
	static int EntryCount = 0;
	PRINTMSG << "EntryCount:" << ++EntryCount << "\n";

	bool modified = false;
	int foundNum = 0;

	int* CountPossiblePositons = (int*)malloc(g->Game_Size * sizeof(int));

	for (int row = 0; row < g->Game_Size; row++)
	{
		memset(CountPossiblePositons, 0, g->Game_Size * sizeof(int));

		for (int col = 0; col < g->Game_Size; col++)
		{
			if (ARRAY2D(g->boxattr, row, col, g->Game_Size).count != 1)
			{
				// Unsolved Box
				for (int i = 0; i < g->Game_Size; i++)
				{
					int numUnSolved = i + 1;
					if (ARRAY2D(g->boxattr, row, col, g->Game_Size).box_possible[i] != 0)
					{
						CountPossiblePositons[numUnSolved-1]++;
					}
				}
			}
		}

		for (int i = 0; i < g->Game_Size; i++)
		{
			if (CountPossiblePositons[i] == 1)
			{
				foundNum = i + 1;
			}
		}

		if (foundNum != 0)
		{
			for (int col = 0; col < g->Game_Size; col++)
			{
				if (ARRAY2D(g->boxattr, row, col, g->Game_Size).count != 1)
				{
					for (int i = 0; i < g->Game_Size; i++)
					{
						if (ARRAY2D(g->boxattr, row, col, g->Game_Size).box_possible[i] == foundNum)
						{
							// foundNum to be placed in (row, col) position in Numerals array
							// Update the boxattr (row, col) count and box_possible array
							UpdateNumeralsInputArrayBoxAttr(g, row, col, foundNum);
							foundNum = 0;
							modified = true;
							//free(CountPossiblePositons);
							return true;
						}
					}
				}
			}
		}
	}

	for (int col = 0; col < g->Game_Size; col++)
	{
		memset(CountPossiblePositons, 0, g->Game_Size * sizeof(int));

		for (int row = 0; row < g->Game_Size; row++)
		{
			if (ARRAY2D(g->boxattr, row, col, g->Game_Size).count != 1)
			{
				// Unsolved Box
				for (int i = 0; i < g->Game_Size; i++)
				{
					int numUnSolved = i + 1;
					if (ARRAY2D(g->boxattr, row, col, g->Game_Size).box_possible[i] != 0)
					{
						CountPossiblePositons[numUnSolved-1]++;
					}
				}
			}
		}

		for (int i = 0; i < g->Game_Size; i++)
		{
			if (CountPossiblePositons[i] == 1)
			{
				foundNum = i + 1;
			}
		}

		if (foundNum != 0)
		{
			for (int row = 0; row < g->Game_Size; row++)
			{
				if (ARRAY2D(g->boxattr, row, col, g->Game_Size).count != 1)
				{
					for (int i = 0; i < g->Game_Size; i++)
					{
						if (ARRAY2D(g->boxattr, row, col, g->Game_Size).box_possible[i] == foundNum)
						{
							// foundNum to be placed in (row, col) position in Numerals array
							// Update the boxattr (row, col) count and box_possible array
							UpdateNumeralsInputArrayBoxAttr(g, row, col, foundNum);
							foundNum = 0;
							modified = true;
							//free(CountPossiblePositons);
							return true;
						}
					}
				}
			}
		}
	}
	if (!modified) PRINTMSG << "NOT Modified\n";
	return modified;
}

void UpdateNumeralsInputArrayBoxAttr(GLOBALS* g, int row, int col, int foundNum)
{
	ARRAY2D(g->Numeral_Inputs, row, col, g->Game_Size) = foundNum;
	ARRAY2D(g->boxattr, row, col, g->Game_Size).count = 1;
	for (int i = 0; i < g->Game_Size; i++)
	{
		if (ARRAY2D(g->boxattr, row, col, g->Game_Size).box_possible[i] != foundNum)
		{
			ARRAY2D(g->boxattr, row, col, g->Game_Size).box_possible[i] = 0;
		}
	}
	UpdateNumeralsInputArray(g, row, col);
}

bool FindPairsAndUpdateBoxattr(GLOBALS* g)
{
	static int EntryCount = 0;
	PRINTMSG << "EntryCount:" << ++EntryCount << "\n";

	bool modified = false;
	int MaxExpectedCount = 2;
	
	int* IndicesWithExpCount = (int*)malloc(g->Game_Size * sizeof(int));
	
	for (int row = 0; row < g->Game_Size; row++)
	{
		// Step 1: Find unsolved Boxes with MaxExpected Count (<=)
		memset(IndicesWithExpCount, 0, g->Game_Size * sizeof(int));
		int colsCount = 0;
		bool foundIdenticalBoxeswithCount2 = false;
		if ((g->Game_Size - g->ColSolvedCount[row]) > MaxExpectedCount)
		{
			for (int col = 0; col < g->Game_Size; col++)
			{
				int BoxattrCount = ARRAY2D(g->boxattr, row, col, g->Game_Size).count;

				if (BoxattrCount != 1 && BoxattrCount <= MaxExpectedCount)
				{
					IndicesWithExpCount[colsCount++] = col;
				}
			}

			// Step 2: Iterate through all the boxes in the current row to find identical boxes
			for (int h = 0; h < colsCount; h++)
			{
				BOX_ATTR* PivotBox = &ARRAY2D(g->boxattr, row, IndicesWithExpCount[h], g->Game_Size);

				for (int f = h+1 ; f < colsCount; f++)
				{
					BOX_ATTR *SecondBox = &ARRAY2D(g->boxattr, row, IndicesWithExpCount[f], g->Game_Size);

					foundIdenticalBoxeswithCount2 = CompareBoxes(PivotBox, SecondBox, g);

					if (foundIdenticalBoxeswithCount2)
					{
						for (int w = 0; w < g->Game_Size; w++)
						{
							int poss_num = PivotBox->box_possible[w];
							if (poss_num != 0)
							{
								// Remove Poss_num from boxattr box_possible from other boxes
								for (int c = 0; c < g->Game_Size; c++)
								{
									if (c != IndicesWithExpCount[h] && c != IndicesWithExpCount[f])
									{
										BOX_ATTR *CurrBox = &ARRAY2D(g->boxattr, row, c, g->Game_Size);
										if (CurrBox->count != 1) {
											modified |= RemoveNumeralFromPossibleList(CurrBox, poss_num);
											if (CurrBox->count == 1) {
												//PRINTMSG << "COUNT=1::" << row << " " << highColIndex << "\n";
												UpdateNumeralsInputArray(g, row, c);
											}
										}
									}
								}
							}
						}
						break;
					}
				}
				if (foundIdenticalBoxeswithCount2) {
					foundIdenticalBoxeswithCount2 = false;
					break;
				}

			}
		}
	}

	for (int col = 0; col < g->Game_Size; col++)
	{
		// Step 1: Find unsolved Boxes with MaxExpected Count (<=)
		memset(IndicesWithExpCount, 0, g->Game_Size * sizeof(int));
		int rowsCount = 0;
		bool foundIdenticalBoxeswithCount2 = false;
		if ((g->Game_Size - g->RowSolvedCount[col]) > MaxExpectedCount)
		{
			for (int row = 0; row < g->Game_Size; row++)
			{
				int BoxattrCount = ARRAY2D(g->boxattr, row, col, g->Game_Size).count;

				if (BoxattrCount != 1 && BoxattrCount <= MaxExpectedCount)
				{
					IndicesWithExpCount[rowsCount++] = row;
				}
			}

			// Step 2: Iterate through all the boxes in the current col to find identical boxes
			for (int h = 0; h < rowsCount; h++)
			{
				BOX_ATTR* PivotBox = &ARRAY2D(g->boxattr, IndicesWithExpCount[h], col, g->Game_Size);

				for (int f = h + 1; f < rowsCount; f++)
				{
					BOX_ATTR *SecondBox = &ARRAY2D(g->boxattr, IndicesWithExpCount[f], col, g->Game_Size);

					foundIdenticalBoxeswithCount2 = CompareBoxes(PivotBox, SecondBox, g);

					if (foundIdenticalBoxeswithCount2)
					{
						for (int w = 0; w < g->Game_Size; w++)
						{
							int poss_num = PivotBox->box_possible[w];
							if (poss_num != 0)
							{
								// Remove Poss_num from boxattr box_possible from other boxes
								for (int r = 0; r < g->Game_Size; r++)
								{
									if (r != IndicesWithExpCount[h] && r != IndicesWithExpCount[f])
									{
										BOX_ATTR *CurrBox = &ARRAY2D(g->boxattr, r, col, g->Game_Size);
										if (CurrBox->count != 1)
										{
											modified |= RemoveNumeralFromPossibleList(CurrBox, poss_num);
											if (CurrBox->count == 1) {
												//PRINTMSG << "COUNT=1::" << row << " " << highColIndex << "\n";
												UpdateNumeralsInputArray(g, r, col);
											}
										}
									}
								}
							}
						}
						break;
					}
				}
				if (foundIdenticalBoxeswithCount2) {
					foundIdenticalBoxeswithCount2 = false;
					break;
				}

			}
		}
	}
	if (!modified) PRINTMSG << "NOT Modified\n";
	return modified;
}

bool CompareBoxes(BOX_ATTR* boxA, BOX_ATTR* boxB, GLOBALS* g)
{
	bool identical = true;

	if (boxA->count == boxB->count)
	{
		for (int a = 0; a < g->Game_Size; a++)
		{
			identical &= (boxA->box_possible[a] == boxB->box_possible[a]);
		}
	}
	return identical;
}

