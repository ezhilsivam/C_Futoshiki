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

#pragma once
#include <iostream>

int main()
{
	bool catchRegression = true;
	bool result = true;
	if (catchRegression)
	{
		result &= TestInput5_1(); // SOLVED
		result &= TestInput5_2(); // SOLVED
		result &= TestInput5_3(); // SOLVED
		result &= TestInput5_4(); // SOLVED
		result &= TestInput5_5(); // SOLVED
		result &= TestInput5_6(); // SOLVED
		result &= TestInput5_7(); // SOLVED
		result &= TestInput5_8(); // SOLVED
		result &= TestInput5_9(); // SOLVED
		
		if (result)
			PRINTMSG << "\nALL PASS\n";
		else
			PRINTMSG << "\n !!! REGRESSION !!!\n";

		return result;
	}
	else
		return TestInput5_2000();
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

		// Allocate memory for input array
		g.Numeral_Inputs = (int*)malloc(Total_Boxes * sizeof(int));
		memset(g.Numeral_Inputs, 0, Total_Boxes * sizeof(int));

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

	static int LoopCount = 0;
	bool repeat = false;
	do {
		PRINTMSG << "LoopCount:" << ++LoopCount << "\n";
		repeat = false;
		if (UpdateBoxAttrNumerals(&g))
		{
			PrintBoxAttrFormatted(&g, true);
			PrintNumeralFormatted(&g);
			repeat = true;
		}
		if (UpdateBoxAttrWithRowRelations(&g))
		{
			if (g.NumeralUpdateNeeded)
			{
				UpdateBoxAttrNumerals(&g);
			}
			g.NumeralUpdateNeeded = false;
			PrintBoxAttrFormatted(&g, true);
			PrintNumeralFormatted(&g);
			repeat = true;
		}
		if (UpdateBoxAttrWithColRelations(&g))
		{
			if (g.NumeralUpdateNeeded)
			{
				UpdateBoxAttrNumerals(&g);
			}
			g.NumeralUpdateNeeded = false;
			PrintBoxAttrFormatted(&g, true);
			PrintNumeralFormatted(&g);
			repeat = true;
		}
		if (FindNumeralsWithOnlyPossiblePosition(&g))
		{
			if (g.NumeralUpdateNeeded)
			{
				UpdateBoxAttrNumerals(&g);
			}
			g.NumeralUpdateNeeded = false;
			PrintBoxAttrFormatted(&g, true);
			PrintNumeralFormatted(&g);
			repeat = true;
		}

	} while (repeat);

	bool sol = CheckSolution(&g);

	if (sol)
		PrintNumeralFormattedfn(&g);
	else
		PrintBoxAttrFormattedfn(&g, true);

	if (sol) PRINT << "* * * * * *\n" << "S O L V E D\n" << "* * * * * *\n";
	else PRINT << "- - - - - - - -\n" << "NOT S O L V E D\n" << "- - - - - - - - \n";

	return sol;
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
			if (currNumeral != 0) {
				// Iterate through the box attr Col and remove currNumeral from other boxes
				for (int boxrow = 0; boxrow < g->Game_Size; boxrow++) {
					if (boxrow != row) {
						if (ARRAY2D(g->boxattr, boxrow, col, g->Game_Size).count != 1)
						{
							BOX_ATTR *modifyBox = &ARRAY2D(g->boxattr, boxrow, col, g->Game_Size);
							modified = RemoveNumeralFromPossibleList(modifyBox, currNumeral);
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
							modified = RemoveNumeralFromPossibleList(modifyBox, currNumeral);
							if (modifyBox->count == 1) {
								UpdateNumeralsInputArray(g, row, boxcol);
								UpdateBoxAttrNumeralsAgain = true;
							}
						}
						//else PRINT << "ERROR Iterating through boxattr row" << row << col << "\n";
					}
				}
			}
		}
	}
	//return UpdateBoxAttrNumeralsAgain;

	if (UpdateBoxAttrNumeralsAgain) {
		UpdateBoxAttrNumerals(g);
	}
	
	if (!modified)
	{
		PRINTMSG << "FORCE_PRINT\n";
		PrintBoxAttrFormatted(g, true);
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
}