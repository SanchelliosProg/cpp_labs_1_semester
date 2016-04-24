#include <string>

namespace ar_const {
	const int ROW = 2;
	const int COL = 3;
}
extern int & ref;
//Прототипы используемых в данном задании функций:
int incByValue(int);
void incByPointer(int*);
void incByReference(int&);
void swap(int*, int*);
void swap(int&, int&);
int findMinNumber(int a[][ar_const::COL], int size_row);
int findMinNumber(int** a, int size_row, int size_col);
void randomize_2d_array(int a[][ar_const::COL], int, int);
void randomize_2d_array(int** a, int, int, int);
int myStrCmp(char* f_str, char* s_str, int f_sz, int s_sz);
std::string print_result_of_comparison(int);
int getRandomInt(int);
bool isLeapYear(int year);
int dayOfYear(int day, int month, int year, int ar[][12]);
int dayOfMonth(int day_of_year, int year, int ar[][12]);
std::string defineMonth(int num_month);
void recursive_f(int, int&);
void append(int* arr, int size, int num);
void arcpy(int* first, int* second, int size);
bool is_duplicate(int arr[], int size_of_arr, int current_num);
void printIntDynamicArray(int* arr, int size);
void printArray(const int *arr, int size);
bool isContinue(char str[]);
void addNumToArray(int num, int *&arr, int &size);
void VarArgs(int arg1, ...);
void VarArgsWithMacros(int arg_1, ...);
int* myMin(int *arr, int size);