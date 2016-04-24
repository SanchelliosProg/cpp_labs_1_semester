#include "iostream" 
#include <cstdio>
#include <ctime>
#include "other.h"

///////////////////////////////////////////////////
char* categoryStrings[] = { "classics", "post modern" };

void Sort(char* pcFirst, int nNumber, int size,
	 void (*Swap)(void*, void*), int (*Compare)(void*, void*) )
{
	int i;
	for(i=1; i<nNumber; i++)
		for(int j=nNumber-1; j>=i; j--)
		{
			char* pCurrent = pcFirst + j*size;
			char* pPrevious = pcFirst + (j-1)*size;
			if((*Compare)(pPrevious, pCurrent) > 0)
				(*Swap)( pPrevious, pCurrent );
		}
}

void SwapInt(void* p1, void* p2){
	int* px = static_cast<int*>(p1);
	int* py = static_cast<int*>(p2);
	int temp = *px;
	*px = *py;
	*py = temp;
}

int CmpInt(void* p1, void* p2){
	int nResult = *static_cast<int*>(p1)-*static_cast<int*>(p2);
	return nResult;
}

void SwapDouble(void* p1, void* p2) {
	double *px = static_cast<double*>(p1);
	double *py = static_cast<double*>(p2);
	double temp = *px;
	*px = *py;
	*py = temp;
}

int CmpDouble(void* p1, void* p2) {
	double res = *static_cast<double*>(p1)-*static_cast<double*>(p2);
	if (res > 0)
		return 1;
	if (res < 0)
		return -1;
	return 0;
}

void SwapString(void* p1, void* p2) {
	char **str_1 = static_cast<char**>(p1);
	char **str_2 = static_cast<char**>(p2);
	char *temp = *str_1;
	*str_1 = *str_2;
	*str_2 = temp;
}

int CmpString(void* p1, void* p2) {
	char *str_1 = *static_cast<char**>(p1);
	char *str_2 = *static_cast<char**>(p2);
	while (*str_1 && *str_1 == *str_2) {
		++str_1;
		++str_2;
	}
	return *str_1 - *str_2;
}

double sum(double x, double y) {
	return x + y;
}

double sub(double x, double y) {
	return x - y;
}

double mul(double x, double y) {
	return x * y;
}

double div(double x, double y) {
	return x / y;
}

void printDivLine() {
	using namespace std;
	cout << "-----------------------------------------------------" << endl;
}

void printArray(int* arr, size_t size) {
	using namespace std;
	cout << "THE ARRAY OF INTEGERS: ";
	cout << "[";
	for (int i = 0; i < size; i++) {
		if (i != size - 1) {
			cout << arr[i] << " ";
		}
		else {
			cout << arr[i];
		}
	}
	cout << "]" << endl;
}

void printArray(double* arr, size_t size) {
	using namespace std;
	cout << "THE ARRAY OF DOUBLES: ";
	cout << "[";
	for (int i = 0; i < size; i++) {
		if (i != size - 1) {
			cout << arr[i] << " ";
		}
		else {
			cout << arr[i];
		}
	}
	cout << "]" << endl;
}

void printArray(char* arr[], size_t size) {
	using namespace std;
	cout << "THE ARRAY OF DOUBLES: ";
	cout << "[";
	for (int i = 0; i < size; i++) {
		if (i != size - 1) {
			cout << arr[i] << " ";
		}
		else {
			cout << arr[i];
		}
	}
	cout << "]";
}

void printMessage(char *message) {
	using namespace std;
	cout << message << endl;
}

const char* getString_1() {
	return "Bis dat, qui cito dat.";
}

const char* getString_2() {
	return "Carpe diem.";
}

const char* getString_3() {
	return "Docendo discimus.";
}

const char* getString_4() {
	return "Du ut des.";
}

void printBook(const Book &book) {
	printDivLine();
	printf("%s\n%s\nCategory: %s\nYear of Release: %d\nPice: %.2lf RUR\n", book.title, book.author, categoryStrings[book.category], book.year, book.price);
	printDivLine();
}

void initBook(Book &book) {
	char title[book_szs::TITLE_SZ];
	printf("Enter title: ");
	scanf("%s", &title);
	strcpy_s(book.title, book_szs::TITLE_SZ, title);
	fflush(stdin);

	char author[book_szs::AUTHOR_SZ];
	printf("Enter author: ");
	scanf("%s", &author);
	strcpy_s(book.author, book_szs::AUTHOR_SZ, author);
	fflush(stdin);

	int year = 0;
	printf("Enter year: ");
	while (true) {
		scanf("%d", &year);
		if (year < -5000 || year > 2016) {
			printf("Wrong year, try another one: ");
			continue;
		} else {
			book.year = year;
			break;
		}
			
	}
	double price = 0.0;
	printf("Enter price: ");
	while (true) {
		scanf("%lf", &price);
		if (price < 0)
			printf("Price can not be negative, enter another one:\n");
		else {
			book.price = price;
			break;
		}
	}
	
	int catId = 0;
	int catNum = sizeof(categoryStrings) / sizeof(categoryStrings[0]);
	while (true) {
		printf("Choose category: [1...%d]\n> ", catNum);
		scanf("%d", &catId);
		if (catId < 1 || catId >= catNum) {
			printf("You've entered wrong category");
		}
		else {
			book.category = static_cast<Category>(catId - 1);
			break;
		}
	}
}