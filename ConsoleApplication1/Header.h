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
}BOX_ATTR;

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
	BOX_ATTR *boxattr;
	BOX_RELATIONS *betweenRows, *betweenColumns;
	int Game_Size;
	bool NumeralUpdateNeeded;
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
