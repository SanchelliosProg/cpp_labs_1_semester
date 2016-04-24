#include <iostream>
#include <iomanip>
#include "book.h"
#include "support.h"


char* categoriesToString[] = { "Programming", "Classic", "Post Modern", "Bigraphy", "Trash" };

void printBook(const Book &book) {
	printf("TITLE:\t\t%s\nAUTHOR:\t\t%s\nCATEGORY:\t%s\nRELEASE DATE:\t%d\nPRICE:\t\t%.2lf RUR\n", 
		book.title, book.author, categoriesToString[book.category], book.year, book.price);
	printDivLine();
}

void initBook(Book &book) {
	char title[TITLE_SZ];
	printf("Enter title: ");
	scanf("%s", &title);
	strcpy_s(book.title, TITLE_SZ, title);
	fflush(stdin);

	char author[AUTHOR_SZ];
	printf("Enter author: ");
	scanf("%s", &author);
	strcpy_s(book.author, AUTHOR_SZ, author);
	fflush(stdin);

	int year = 0;
	printf("Enter year: ");
	while (true) {
		scanf("%d", &year);
		if (year < -5000 || year > 2016) {
			printf("Wrong year, try another one: ");
			continue;
		}
		else {
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
	int catNum = sizeof(categoriesToString) / sizeof(categoriesToString[0]) + 1;
	while (true) {
		printDivLine();
		puts("Avaliable categories:");
		printDivLine();
		for (int i = 0; i < catNum-1; i++) {
			using namespace std;
			printf("[%d] - %s\n", (i + 1), categoriesToString[i]);
		}
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

float compareTitles(const Book& first, const Book& second) {
	return std::strcmp(first.title, second.title);
}

float compareAuthors(const Book& first, const Book& second) {
	return std::strcmp(first.author, second.author);
}

float compareYears(const Book& first, const Book& second) {
	return first.year - second.year;
}

float comparePrices(const Book& first, const Book& second) {
	return first.price - second.price;
}

float compareCategory(const Book& first, const Book& second) {
	return first.category - second.category;
}

char* getTitle(Book &book) {
	return book.title;
}

