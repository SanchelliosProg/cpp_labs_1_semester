 #include <iostream>
#include "support.h"
#include "BooksCollection.h"

const int INIT_SIZE = 3;
const char textTxt[] = "text.txt";

enum SortType {
	title,
	author,
	year,
	price,
	category,
	SORT_LABELS_SIZE
};

const char* sortLabels[] = { "by title", "by author", "by year", "by price", "by category" };

float(*comparator[])(const Book&, const Book&) = {
	compareTitles,
	compareAuthors,
	compareYears,
	comparePrices,
	compareCategory
};

void initBooksCollection(BooksCollection &bc) {
	bc.numberOfBooks = 0;
	bc.capacity = INIT_SIZE;
	bc.books = new Book*[INIT_SIZE];
}

void addNewBook(BooksCollection &bc) {
	if (bc.numberOfBooks <= bc.capacity) {
		insertBook(bc);
		if (bc.numberOfBooks == bc.capacity) {
			enlargeTheCollection(bc);
		}
	} else {
		enlargeTheCollection(bc);
		insertBook(bc);
	}
}

void addNewBook(BooksCollection &bc, Book* book) {
	if (bc.numberOfBooks <= bc.capacity) {
		insertBook(bc, book);
		if (bc.numberOfBooks == bc.capacity) {
			enlargeTheCollection(bc);
		}
	}
	else {
		enlargeTheCollection(bc);
		insertBook(bc, book);
	}
}

void enlargeTheCollection(BooksCollection &bc) {
	Book** tmp = new Book*[bc.capacity];
	int prevCap = bc.capacity;
	int newCapacity = bc.capacity + INIT_SIZE;
	for (int i = 0; i < bc.capacity; i++) {
		tmp[i] = bc.books[i];
	}
	delete[] bc.books;
	bc.books = new Book*[newCapacity];
	bc.capacity = newCapacity;
	for (int i = 0; i < prevCap; i++) {
		bc.books[i] = tmp[i];
	}
}

void insertBook(BooksCollection &bc) {
	Book* newBook = new Book();
	initBook(*newBook);
	bc.numberOfBooks++;
	bc.books[bc.numberOfBooks - 1] = newBook;
}

void insertBook(BooksCollection &bc, Book* book) {
	Book* newBook = book;
	bc.numberOfBooks++;
	bc.books[bc.numberOfBooks - 1] = newBook;
}

void printTheCollection(const BooksCollection &bc) {
	using namespace std;
	if (isEmpty(bc)) {
		cout << "There are no books in the collection!" << endl;
	} else {
		printDivLine();
		cout << "    *** COLLECTION OF BOOKS ***" << endl;
		printDivLine();
		for (int i = 0; i < bc.numberOfBooks; i++) {
			printBook(*bc.books[i]);
		}
		printDivLine();
	}
}

bool isEmpty(const BooksCollection &bc) {
	if (bc.numberOfBooks == 0) {
		return true;
	}
	else {
		return false;
	}
}

void deleteBook(BooksCollection &bc) {
	using namespace std;
	int choise = 0;
	cout << "Which book do you want to delete: " << endl;
	printBookTitles(bc);
	cin >> choise;
	int chosenIndex = choise - 1;
	for (int i = chosenIndex; i < bc.numberOfBooks; i++) {
		bc.books[i] = bc.books[i + 1];
	}
	bc.numberOfBooks--; 
	printBookTitles(bc);
}

void printBookTitles(const BooksCollection &bc) {
	using namespace std;
	for (int i = 0; i < bc.numberOfBooks; i++) {
		
		cout << "[" << i + 1 << "] - " << getTitle(*bc.books[i]) << endl;
	}
}

void flushTheStruct(BooksCollection &bc) {
	for (int i = 0; i < bc.numberOfBooks; i++) {
		delete bc.books[i];
	}
	bc.capacity = 0;
	bc.numberOfBooks = 0;
	delete[] bc.books;
}

void addDefaultBookshelf(BooksCollection &bc) {
	addDefaultBook(bc, "Kernighan_and_Richie", "The_C_programming_language", 1978, 991.00, PROGRAMMING);
	addDefaultBook(bc, "Bjarne_Stroustroup", "The_C++_programming_language", 1997, 600.00, PROGRAMMING);
	addDefaultBook(bc, "Kernighan_and_Donovan", "The_Go_programming_language", 2015, 1315.00, PROGRAMMING);
	addDefaultBook(bc, "Steve_McConnel", "Code_Complete", 1993, 1200.99, PROGRAMMING);
	addDefaultBook(bc, "Bob_Martin", "Clean_Code", 2009, 653.00, PROGRAMMING);
	addDefaultBook(bc, "Viktor_Pelevin", "Generation_P", 1999, 300.00, POST_MODERN);
	addDefaultBook(bc, "Vladimir_Sorokin", "Blue_Fat", 1999, 280.00, POST_MODERN);
	addDefaultBook(bc, "Leo_Tolstoy", "War_and_Peace", 1869, 339.00, CLASSICS);
	addDefaultBook(bc, "Anton_Chekhov", "The_Cherry_Orchard", 1904, 169.52, CLASSICS);
	addDefaultBook(bc, "Sau_Sheong_Chang", "Go_Web_Programming", 2016, 2411.00, PROGRAMMING);
	addDefaultBook(bc, "Walter_Isaacson", "Steve_Jobs", 2011, 1000.00, BIOGRAPHY);
	addDefaultBook(bc, "Darya_Dontcova", "Evlampiya_Romanova", 2001, 50.00, TRASH_LIT);
	addDefaultBook(bc, "Chuck_Palahniuk", "Survivor", 1999, 304.00, POST_MODERN);
	addDefaultBook(bc, "Alexander_Pushkin", "The_Fountain_of_Bakhchisaray", 1823, 200.00, CLASSICS);
	addDefaultBook(bc, "Bruce_Eckel", "Thinling_In_Java", 1998, 1200.00, PROGRAMMING);
	addDefaultBook(bc, "Bruce_Eckel", "Atomic_Scala", 2012, 2050.00, PROGRAMMING);
	addDefaultBook(bc, "Sebastien_Goasguen", "Docker_in_Cloud", 2016, 1500.00, PROGRAMMING);
	addDefaultBook(bc, "Matthew_Campbell", "Microservices_in_Go", 2016, 1800.20, PROGRAMMING);
	addDefaultBook(bc, "Pete_Goodliffe", "Becoming_a_Better_Programmer", 2014, 1755.90, PROGRAMMING);
	addDefaultBook(bc, "Ivan_Turgenev", "A_Month_in_the_Country", 1848, 200.00, CLASSICS);
	addDefaultBook(bc, "Alexandra_Marinina", "Men_Games", 2012, 20.00, TRASH_LIT);
	addDefaultBook(bc, "Alexander_Suvorov", "Science_Of_Victory", 1806, 850.00, BIOGRAPHY);
}

void addDefaultBook(BooksCollection &bc, char* author, char* title, int year, double price, Category cat) {
	Book* book = new Book();
	strcpy_s(book->author, AUTHOR_SZ, author);
	strcpy_s(book->title, TITLE_SZ, title);
	book->year = year;
	book->price = price;
	book->category = cat;
	addNewBook(bc, book);
}

void saveToFile(const BooksCollection &bc) {
	if (isEmpty(bc))
		return;
	
	char fileName[] = "text.txt";
	printf("Saving to the \'%s\' file...\n", fileName);
	FILE* file = fopen(fileName, "w");
	if (file) {
		for (int i = 0; i < bc.numberOfBooks; i++) {
			Book book = *bc.books[i];
			fprintf(file, "%s %s %d %.2lf %d \n", book.author, book.title, book.year, book.price, book.category);
		}
		fclose(file);
	} else {
		printFileError();
	}
}

void loadBookFromFile(BooksCollection &bc) {
	printf("Loading from a \'%s\' file...\n", textTxt);
	FILE* file = fopen(textTxt, "r");
	if (file) {
		int lines = countNumberOfLines(file);
		file = fopen(textTxt, "r");
		for (int i = 0; i < lines; i++) {
			Book* book = new Book();
			scanBook(file, *book);
			addNewBook(bc, book);
		}
		fclose(file); 
	} else {
		printFileError();
	}
}

void scanBook(FILE* file, Book &book) {
	fscanf(file, "%s %s %d %lf %d \n", book.author, book.title, &book.year, &book.price, &book.category);
}

int countNumberOfLines(FILE* file) {
	unsigned int numberOfLines = 0;
	char ch;
	while (EOF != (ch = getc(file))) {
		if (ch == '\n')
			numberOfLines++;
	}
	fclose(file);
	return numberOfLines;
}

void printFileError() {
	puts("ERROR: Couldn't open the file!\n");
}

void flushFile() {
	FILE* file = fopen(textTxt, "w");
	if (file) {
		fflush(file);
		fclose(file);
	}
}

void flushCollection(BooksCollection &bc) {
	bc.capacity = INIT_SIZE;
	bc.numberOfBooks = 0;
	delete[] bc.books;
	bc.books = new Book*[bc.capacity];
}

void sortChoise(BooksCollection &bc) {
	using namespace std;
	int choise = 0;
	cout << "Please, choose type of sorting: " << endl;
	for (int i = 0; i < SORT_LABELS_SIZE; i++) {
		cout << i << " - sort " << sortLabels[i] << endl;
	}
	while (true) {
		printUserInvitation("sorting");
		fflush(stdin);
		scanf("%d", &choise);
		fflush(stdin);
		if (isSortChoiseValid(choise)) {
			break;
		} else {
			printf("Worng choise! Try again!\n");
			continue;
		}
	}
	sort(bc, comparator[choise]);
}


bool isSortChoiseValid(int choise) {
	if (choise < title || choise >= SORT_LABELS_SIZE) {
		return false;
	}
	else {
		return true;
	}
}

void sort(BooksCollection &bc, float(*comparators)(const Book&, const Book&)) {
	Book** booksArray = bc.books;
	for (int i = 1; i < bc.numberOfBooks; i++) {
		for (int j = 0; j < bc.numberOfBooks - 1; j++) {
			if (comparators(*booksArray[j], *booksArray[j+1]) > 0) {
				Book* tmpBook = booksArray[j];
				booksArray[j] = booksArray[j + 1];
				booksArray[j + 1] = tmpBook;
			}
		}
	}
}
