#pragma once

#define PRINTBOXATTRdbg false
#if PRINTBOXATTRdbg
#define PrintBoxAttrFormatted PrintBoxAttrFormattedfn
#else
#define PrintBoxAttrFormatted
#endif

#define PRINTNUMERALSdbg false
#if PRINTNUMERALSdbg
#define PrintNumeralFormatted PrintNumeralFormattedfn
#else
#define PrintNumeralFormatted
#endif

#define PRINT std::cout 
#define PRINTMSG PRINT << "\n" << __FUNCTION__<<"::"
#define SCAN std::cin 
#define ARRAY2D(a, r, c, s) (*((a) + ((r) * (s)) + (c)))


#define CHECK_USER_INPUT_ERROR					\
	if (num_input_error)						\
	{											\
		PRINTMSG << "Input ERROR\n"; return false;	\
	}

#define INVALIDCHAR_COL(chr) ((chr != '.' && chr != '<' && chr != '>') ? true: false)
#define INVALIDCHAR_ROW(chr) ((chr != '.' && chr != '^' && chr != 'v') ? true: false)

typedef struct {
	int *box_possible;
	int count;
	bool boxAttrUpdated;
}BOX_ATTR;

typedef struct{
	int value;
	bool IsUserIp;
	bool IsFilled;
}NUM_ATTR;

typedef struct {
	bool isValid;
	char splChar;

	bool isBetweenRows; // 1=BetweenRows, 0=BetweenColums

	union
	{
		// if (betweenRows)
		struct
		{
			int highrow;
			int lowrow;
		};
		// if (BetweenColums)
		struct
		{
			int highcol;
			int lowcol;
		};
	};
}BOX_RELATIONS;

typedef struct {
	int* Numeral_Inputs;
	int* RowSolvedCount;
	int* ColSolvedCount;
	BOX_ATTR *boxattr;
	BOX_RELATIONS *betweenRows, *betweenColumns;
	int Game_Size;
	int Total_Boxes;
	bool NumeralUpdateNeeded;
	NUM_ATTR *numAttr;
}GLOBALS;

void PrintBoxAttrFormattedfn(GLOBALS*, bool);
void PrintNumeralFormattedfn(GLOBALS*);


bool SolveFutoshiki(int*, char*, char*, int);

bool UpdateBoxAttrNumerals(GLOBALS*);
bool RemoveNumeralFromPossibleList(BOX_ATTR *, int);
void UpdateNumeralsInputArray(GLOBALS *, int, int);
void UpdateNumeralsInputArrayBoxAttr(GLOBALS*, int, int, int);
bool UpdateBoxAttrWithRowRelations(GLOBALS*);
bool UpdateBoxAttrWithColRelations(GLOBALS*);
bool FindNumeralsWithOnlyPossiblePosition(GLOBALS*);
int MinPossible(int*, int);
int MinPossible(int*, int);
bool CheckSolution(GLOBALS*);
bool FindPairsAndUpdateBoxattr(GLOBALS*);
bool CompareBoxes(BOX_ATTR*, BOX_ATTR*, GLOBALS*);
bool CatchRegression();
bool CatchRegression4x4();
bool CatchRegression5x5();
bool CatchRegression6x6();
bool CatchRegression7x7();
bool CatchRegression8x8();
bool CatchRegression9x9();

void ManualAlgo(GLOBALS *g);
void BacktrackingAlgo(GLOBALS * g);

void InitializeNumAttrArray(GLOBALS *g);
bool BackTrackAndFill(GLOBALS *g);
bool BackTrackAndFill2(GLOBALS *g, int startIndex);
void PrintNumeralAttributefn(GLOBALS *);

bool containsInRow(GLOBALS *g, int row, int num);
bool containsInCol(GLOBALS *g, int col, int num);
bool violatesBetweenColRelation(GLOBALS *g, int row, int col, int num);
bool violatesBetweenRowRelation(GLOBALS *g, int row, int col, int num);
bool isAllowed(GLOBALS* g, int row, int col, int number);
void CopyNumAttrToNumeralInput(GLOBALS *g);