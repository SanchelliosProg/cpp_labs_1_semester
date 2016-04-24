
//Прототипы используемых в данном задании функций:
enum Category {
	CLASSICS,
	POST_MODERN
};

namespace book_szs{
	const int AUTHOR_SZ = 50;
	const int TITLE_SZ = 100;
}

struct Book{
	char author[book_szs::AUTHOR_SZ];
	char title[book_szs::TITLE_SZ];
	int year;
	double price;
	Category category;
};

void Sort(char* pcFirst, int nNumber, int size,
	 void (*Swap)(void*, void*), int (*Compare)(void*, void*) );

double sum(double x, double y);
double sub(double x, double y);
double mul(double x, double y);
double div(double x, double y);

void printArray(int* arr, size_t size);
void printArray(double* arr, size_t size);
void printArray(char* arr[], size_t size);
void printMessage(char *message);
void printDivLine();

void printBook(const Book &book);

void SwapInt(void* p1, void* p2);
int CmpInt(void* p1, void* p2);

void SwapDouble(void* p1, void* p2);
int CmpDouble(void* p1, void* p2);


void SwapString(void* p1, void* p2);
int CmpString(void* p1, void* p2);

const char* getString_1();

const char* getString_2();

const char* getString_3();

const char* getString_4();

void initBook(Book &book);



