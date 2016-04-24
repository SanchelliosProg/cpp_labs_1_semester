#include <iostream>
#include "support.h"

using namespace std;

void printDivLine() {
	cout << "----------------------------------------------------" << endl;
}

void printUserInvitation() {
	printf("user > ");
}

void printUserInvitation(char* string) {
	printf("user/%s > ", string);
}

void help() {
	cout << "----------------------------" << endl
		<< "HELP" << endl
		<< "----------------------------" << endl
		<< "[p] - PRINT the collection;" << endl
		<< "[a] - ADD new book;" << endl
		<< "[d] - DELETE the book;" << endl
		<< "[s] - SAVE to the file;" << endl
		<< "[l] - LOAD books from file;" << endl
		<< "[t] - SORT books;" << endl
		<< "----------------------------" << endl
		<< "[b] - Add default bookshelf" << endl
		<< "[x] - Flush file" << endl
		<< "[z] - Flush collection" << endl
		<< "----------------------------" << endl
		<< "[h] - help" << endl
		<< "----------------------------" << endl;
}
