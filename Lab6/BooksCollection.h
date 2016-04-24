#include "book.h"  
#include <iostream>

struct BooksCollection {
	int numberOfBooks;
	int capacity;
	Book** books;
};

void initBooksCollection(BooksCollection &bc);
void printTheCollection(const BooksCollection &bc);
void addNewBook(BooksCollection &bc);
void enlargeTheCollection(BooksCollection &bc);
void insertBook(BooksCollection &bc);
void addNewBook(BooksCollection &bc, Book* book);
void insertBook(BooksCollection &bc, Book* book);
void deleteBook(BooksCollection &bc);
void printBookTitles(const BooksCollection &bc);
void flushTheStruct(BooksCollection &bc);
void addDefaultBookshelf(BooksCollection &bc);
void addDefaultBook(BooksCollection &bc, char* author, char* title, int year, double price, Category cat);
bool isEmpty(const BooksCollection &bc);
void saveToFile(const BooksCollection &bc);
void printFileError();
void printFileError();
int countNumberOfLines(FILE* file);
void loadBookFromFile(BooksCollection &bc);
void scanBook(FILE* file, Book &book);
void flushFile();
void flushCollection(BooksCollection &bc);
void sortChoise(BooksCollection &bc);
bool isSortChoiseValid(int choise);
void sort(BooksCollection &bc, float(*comparators)(const Book&, const Book&));



