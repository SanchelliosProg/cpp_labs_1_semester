#include "other.h"
#include <limits.h>
#include <ctime>
#include <iostream>
#include <cstdarg>
int my_ref_val = 10;
int& ref = my_ref_val;
///////////////////////////////////////////////////
using namespace ar_const;
int incByValue(int val) {
	return ++val;
}
void incByPointer(int* val) {
	++(*val);
}
void incByReference(int& val) {
	val++;
}
void swap(int* x, int* y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}
void swap(int& x, int& y) {
	int temp = x;
	x = y;
	y = temp;
}
int findMinNumber(int a[][ar_const::COL], int size_row) {
	int min = INT_MAX;
	for (int i = 0; i < size_row; i++) {
		for (int j = 0; j < ar_const::COL; j++) {
			if (a[i][j] < min) {
				min = a[i][j];
			}
		}
	}
	return min;
}

int findMinNumber(int* a[], int size_row, int size_col) {
	int min = INT_MAX;
	for (int i = 0; i < size_row; i++) {
		for (int j = 0; j < size_col; j++) {
			if (a[i][j] < min) {
				min = a[i][j];
			}
		}
	}
	return min;
}

void randomize_2d_array(int a[][ar_const::COL], int row_sz, int max_num) {
	for (int i = 0; i < row_sz; i++) {
		for (int j = 0; j < ar_const::COL; j++) {
			a[i][j] = getRandomInt(max_num);
		}
	}
}

void randomize_2d_array(int** a, int row_sz, int col_sz, int max_num) {
	for (int i = 0; i < row_sz; i++) {
		a[i] = new int[col_sz];
		for (int j = 0; j < col_sz; j++) {
			a[i][j] = getRandomInt(max_num);
		}
	}
}

void randomize_int_array(int arr[], int size, int max_num) {
	for (int i = 0; i < size; i++) {
		arr[i] = getRandomInt(max_num);
	}
}

int getRandomInt(int max_num) {
	return rand() % (max_num + 1);
}

//int myStrCmp(char* f_str, char* s_str, int f_sz, int s_sz) {
//	if (f_sz > s_sz) {
//		return 1;
//	}
//	else if (f_sz < s_sz) {
//		return -1;
//	}
//	else {
//		for (int i = 0; i < f_sz; i++) {
//			if (f_str[i] > s_str[i]) {
//				return 1;
//			}
//			else if (f_str[i] < s_str[i]){
//				return -1;
//			}
//		}
//		return 0;
//	}
//}

int myStrCmp(char* f_str, char* s_str, int f_sz, int s_sz) {
	int size_biggest = 0;
	if (f_sz > s_sz) {
		size_biggest = f_sz;
	}
	else if (f_sz < s_sz) {
		size_biggest = s_sz;
	}
	else {
		size_biggest = f_sz;
	}
	for (int i = 0; i < size_biggest; i++) {
		if (f_str[i] > s_str[i]) {
			return 1;
		}
		else if (f_str[i] < s_str[i]) {
			return -1;
		}
	}
	return 0;
}

std::string print_result_of_comparison(int res) {
	switch (res) {
	case -1:
		return "Second string is bigger";
	case 0:
		return "Strings are equal";
	case 1:
		return "First string is bigger";
	default:
		return "ERROR";
	}
}

bool isLeapYear(int year) {
	return (year % 4 == 0 && year % 100 != 0 || year % 400 == 0);
}

int dayOfYear(int day, int month, int year, int ar[][12]) {
	int row = 0;
	int day_count = 0;
	if ((month > 12 || month < 1) || year > 9999) {
		return -1;
	}
	if (isLeapYear(year)) {
		for (int i = 1; i < month; i++) {
			day_count += ar[row][i];
		}
		return day_count + day;
	}
	else {
		row = 1;
		for (int i = 1; i < month; i++) {
			day_count += ar[row][i];
		}
		return day_count + day;
	}
}

int dayOfMonth(int day_of_year, int year, int ar[][12]) {
	int day_of_month = day_of_year;
	if (isLeapYear(year)) {
		int month = 0;
		while (day_of_month > 31) {
			day_of_month -= ar[0][month];
			month++;
		}
		return day_of_month;
	}
	else {
		int month = 0;
		while (day_of_month > 31) {
			day_of_month -= ar[1][month];
			month++;
		}
		return day_of_month;
	}
}

std::string defineMonth(int num_month) {
	switch (num_month) {
	case 1:
		return "january";
	case 2:
		return "february";
	case 3:
		return "march";
	case 4:
		return "april";
	case 5:
		return "may";
	case 6:
		return "june";
	case 7:
		return "july";
	case 8:
		return "august";
	case 9:
		return "september";
	case 10:
		return "october";
	case 11:
		return "november";
	case 12:
		return "december";
	default:
		break;
	}
}

void recursive_f(int num, int& sum) {
	sum += num;
	num--;
	if (num > 0) {
		recursive_f(num, sum);
	}
}

void append(int* arr, int& size, int num) {
	if (!is_duplicate(arr, size, num)) {
		int* temp_arr = new int[size];
		arcpy(temp_arr, arr, size);
		delete[]arr;

		size++;
		arr = new int[size];
		arcpy(arr, temp_arr, size);
		arr[size - 1] = num;
		delete[]temp_arr;
	}
}

void arcpy(int* first, int* second, int size) {
	for (int i = 0; i < size; i++) {
		first[i] = second[i];
	}
}

bool is_duplicate(int arr[], int size_of_arr, int current_num) {
	using namespace std;
	for (int i = 0; i < size_of_arr; i++) {
		if (arr[i] == current_num) {
			cout << "You've entered a duplicate" << endl;
			return true;
		}
	}
	return false;
}

void printIntDynamicArray(int* arr, int size) {
	using namespace std;
	cout << "{ ";
	for (int i = 0; i < size; i++) {
		if (i != size - 1) {
			cout << arr[i] << ", ";
		}
		else {
			cout << arr[i] << "}" << endl;
		}
	}
}

void printArray(const int *arr, int size) {
	using namespace std;
	cout << "[";
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << "]" << endl;
}

bool isContinue(char str[]) {
	using namespace std;
	cout << str << "[y/n]\n> ";
	char choice = 'x';
	cin >> choice;
	switch (choice) {
	case 'y':
	case 'Y':
		return true;
		break;
	case 'n':
	case 'N':
		return false;
		break;
	default:
		return false;
	}
}

void addNumToArray(int num, int *&arr, int &size) {
	int i = 0;
	for (; i < size; i++) {
		if (num == arr[i]) {
			std::cout<< num << " is already in array, skipping entry..." << std::endl;
			return;
		}
	}
	int* temp = new int[size + 1];
	for (i = 0; i < size; i++) {
		temp[i] = arr[i];
	}
	temp[size] = num;
	delete[]arr;
	size++;
	arr = temp;
}

//Подсказка-заготовка для задания 5а
//Без использования макросов

void VarArgs(int arg1,...)
{
	using namespace std;
	int number = 0;	//счетчик элементов
	//Объявите указатель на int и инициализируйте его адресом
	//первого аргумента
	int* ptr = &arg1; 
	int counter = 0;
	while (*ptr != 0) {
		cout << *ptr << " ";
		ptr++;
		counter++;
	}
	//Пока не достигнут конец списка:
	// а) печать значения очередного аргумента
	// б) модификация указателя (он должен указывать на
	//следующий аргумент списка)
	// в) увеличить счетчик элементов
//Печать числа элементо
	cout << endl << "[" << counter << "]";
	if (counter == 1) 
		cout << " argument was entered" << endl;
	else 
		cout << " arguments were entered" << endl;
}

void VarArgsWithMacros(int arg_1,...) {
	using namespace std;
	int counter = 0;
	if (arg_1 != 0) {
		cout << arg_1 << " ";
		counter++;								//считаем первый параметр
		va_list list;							//объявляем универсальный указатель
		va_start(list, arg_1);					//направляем указатель на первый необязательный параметр
		while (true) {
			int currentVar = va_arg(list, int);	//сдвигаем указатель на следующий аргумент
			if (currentVar == 0) {
				break;
			}
			cout << currentVar << " ";
			counter++;
		}
		va_end(list);							//обнуляем указатель
		cout << endl << "[" << counter << "]";
		if (counter == 1)
			cout << " argument was entered" << endl;
		else
			cout << " arguments were entered" << endl;
	}
}

int* myMin(int *arr, int size) {
	int minIndx = 0;
	for (int i = 1; i < size; i++) {
		if (arr[minIndx] > arr[i]) {
			minIndx = i;
		}
		return &arr[minIndx];
	}
}