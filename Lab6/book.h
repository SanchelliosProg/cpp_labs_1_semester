
enum Category {
	PROGRAMMING,
	CLASSICS,
	POST_MODERN,
	BIOGRAPHY,
	TRASH_LIT
};

const int AUTHOR_SZ = 25;
const int TITLE_SZ = 50;

struct Book {
	char author[AUTHOR_SZ];
	char title[TITLE_SZ];
	int year;
	double price;
	Category category;
};

void printBook(const Book &book);
void initBook(Book &book);
char* getTitle(Book &book);
float compareTitles(const Book& first, const Book& second);
float compareAuthors(const Book& first, const Book& second);
float compareYears(const Book& first, const Book& second);
float comparePrices(const Book& first, const Book& second);
float compareCategory(const Book& first, const Book& second);
char* getAdaptedString(const char* str, const int size);





