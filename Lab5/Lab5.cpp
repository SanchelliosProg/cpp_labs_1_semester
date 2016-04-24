/*************************************************************
Практическое занятие №5.
"Старые" потоковые функции стандартной библиотеки
Указатели на функции
Структуры
*************************************************************/
#include <tchar.h>
#include <iostream>
//#include <cstdio>
#include "other.h"


#define	  stop __asm nop
Book globalBook;
int _tmain() {
	//Тема "Старые" потоковые функции стандартной библиотеки
	//Задание 1. С помощью функции scanf сформирйуте три коэффициента: A,B,C
	{
		double a, b, c;
		printf("Please, enter A, B, and C integers\n");
		printf("A: ");
		scanf("%lf", &a);
		fflush(stdin);
		printf("B: ");
		scanf("%lf", &b);
		fflush(stdin);
		printf("C: ");
		scanf("%lf", &c);
		fflush(stdin);
		printf("A = %lf, B = %lf, C = %lf \n\n", a, b, c);



		//Задание 2. Выведите (красиво!) таблицу значений y=A*x*x + B*x + C
		//при изменении x в диапазоне -2 до +2 с шагом 0.5


		int counter = 0;
		printf("-------------------\n");
		printf("| # |  x |   f(x) |\n");
		printf("|-----------------|\n");
		for (double x = -2.0; x < 2.01; x += 0.5) {
			counter++;
			printf("| %2d|%4.1lf|  %6.1lf|\n", counter, x, (a*x*x + b*x + c));
		}
		printf("-------------------\n");
	}

	///////////////////////////////////////////////////////////////////
	//Тема Указатели на функции

	//Задание 1. Указатель на функцию. "Калькулятор".
	//Напишите функции:
	//1)Sum - принимает два значения double и возвращает сумму
	//этих значений
	//2)Sub- принимает два значения double и возвращает разность
	//этих значений
	//3)Mul - *
	//4)Div - /
	//5)а для возведения в степень можете использовать функцию стандартной библиотеки
	//		- pow(). Подсказка 1: прототип функции находится в <cmath>.
	//		Подсказка 2: стандартная библиотека предоставляет несколько перегруженных
	//		вариантов этой функции, а Вам потребуется сформировать указатель на 
	//		double pow(double, double);

	//Предоставьте пользователю	следующую возможность:
	//пока пользователь хочет пользоваться услугами Вашего калькулятора,
	//он может вводить два значения и знак операции
	//а Вы выводите результат. Результат получаете посредством вызова
	//соответствующей Вашей функции по указателю.
	//Предусмотрите возможность ввода непредусмотренного знака операции
	{
		double x_num = 0, y_num = 0;
		char operation = 0;
		bool doContinue = true;
		while (true) {
			if (!doContinue) break;
			printf("Enter the expression: ");
			scanf("%lf %c %lf", &x_num, &operation, &y_num);
			fflush(stdin);
			double(*function)(double, double) = nullptr;

			switch (operation) {
			case '+':
				function = sum;
				break;
			case '-':
				function = sub;
				break;
			case '*':
				function = mul;
				break;
			case '/':
				function = div;
				break;
			case '^':
				function = pow;
				break;
			default:
				break;
			}

			if (function) {
				printf("x %c y = %.2f\n", operation, function(x_num, y_num));
			}
			else {
				printf("ERROR: you've entered UNKNOWN OPERATOR!!!\n");
			}

			char choise = 0;
			printf("One more calculation? [y/n]: ");
			scanf("%c", &choise);
			fflush(stdin);
			switch (choise) {
			case 'Y':
			case 'y':
				break;
			case 'n':
			case 'N':
				doContinue = false;
				break;
			default:
				doContinue = false;
				printf("ERROR: Skipping calculation by default...");
				break;
			}
		}
	}
	stop

		//Задание 2. Указатель на функцию в качестве аргумента.
		//Дана заготовка функции сортировки любых объектов - Sort.
		//Функция принимает следующие параметры:
		//1) указатель на первый сортируемый элемент
		//2) количество сортируемых элементов
		//3) размер элемента в байтах
		//4) указатель на функцию перестановки элементов
		//5) указатель на функцию сравнения элементов

		//2a. Напишите функцию перестановки двух целых значений -
		// SwapInt, которая принимает два void указателя и 
		//меняет значения местами

		//Напишите функцию сравнения двух целых значений -
		// CmpInt, которая принимает два void указателя и
		//возвращает int результат сравнения: 
		//<0 - первый элемент меньше, чем второй
		//=0 - равны
		//>0 - первый элемент больше, чем второй

		//массив для сортировки
		printDivLine();
		const int N = 10;
		int nAr[N];
		for (int i = 0; i < N; i++) {
			nAr[i] = rand() % 100;
		}
		//Печать исходного массива
		printArray(nAr, N);
		//Вызов сортировки
		int nTotal = N;			//количество элементов в массиве
		Sort(reinterpret_cast<char*>(&nAr[0]), nTotal, sizeof(int), SwapInt, CmpInt);
		//Печать результатов сортировки
		printArray(nAr, N);
		stop
		
		
		//Задание 2б. По аналогии с 8а создайте вспомогательные
		//функции - SwapDouble и CmpDouble и вызовите функцию Sort
		//для сортировки массива вещественных значений.
		{
			printDivLine();
			const int N = 10;
			double nAr[N];
			for (int i = 0; i < N; i++) {
				nAr[i] = rand() % 1000 / 10.0;
			}
			printArray(nAr, N);
			int nTotal = N;
			Sort(reinterpret_cast<char*>(&nAr[0]), nTotal, sizeof(double), SwapDouble, CmpDouble);
			printArray(nAr, N);
			stop
		}
		
		//Задание 2в*. По аналогии с 8а создайте вспомогательные
		//функции - SwapStr и CmpStr и вызовите функцию Sort
		//для сортировки массива указателей на строки.
		{
			printDivLine();
			char s[] = "QWERTY";
			char* arStr[] = { "WWW", "SDF", "ABC", s, "C++", "is", "Wonderful", "Programming", "Language" };
			int sizeOfArray = sizeof(arStr) / sizeof(arStr[0]);
			nTotal = sizeOfArray;
			printMessage("Unsorted");
			printArray(arStr, sizeOfArray);
			Sort(reinterpret_cast<char*>(&arStr[0]), nTotal, sizeof(char*), SwapString, CmpString);
			printMessage("Sorted");
			printArray(arStr, sizeOfArray);
		}
		//Задание 3. Массивы указателей на функцию.
		//Напишите несколько функций вида
		//const char* GetString1();
		//const char* GetString2();
		//		...., каждая из функций возвращает указатель на свою строку
		//(подумайте - какой адрес Вы имеете право возвращать из функции)
		printDivLine();
		const char* (*stringGetFuncs[])() = {getString_1, getString_2, getString_3, getString_4};
		int capacity = sizeof(stringGetFuncs) / sizeof(stringGetFuncs[0]);
		while (true) {
			int choise = 0;
			std::cout << "Get string [1 ..." << capacity << "]: ";
			std::cin >> choise;
			if (choise == 0 || choise > capacity) {
				std::cout << "Wrong choise, try again..." << std::endl;
				continue;
			}
			else {
				const char* str = stringGetFuncs[choise - 1]();
				std::cout << str << std::endl;
				break;
			}
			stop
		}
		

		//Объявите и проинициализируйте массив указателей на функции
		//GetString1,GetString2...
		//Введите номер функции, которую Вы хотите вызвать:
		//Вызовите функцию
		//Распечатайте результат

		//////////////////////////////////////////////////////////////////////////////////////

		//Тема. Структуры С.	
		//Задание 1. Объявите структуру Book, описывающую книгу
		//(автор, заглавие, год издания, цена, категория…).
		//Подумайте: какого типа могут быть поля структуры.
		//Подсказка: объявление структуры рекомендуется выносить
		//в заголовочный файл.


		//Задание 2. Создайте разными способами (глобальный, локальный, статический,
		//динамический) экземпляры (объекты) типа Book (без инициализации).
		//Определите - сколько памяти отводит компилятор под каждый
		//такой объект. Как инициализируются (или не инициализируются) поля
		//структуры. Подумайте: от чего зависит объем выделяемой памяти?
		{
			Book localBook;
			static Book staticBook;
			Book* dynamicBook = new Book();

			{
				using namespace std;
				printDivLine;
				cout << "Global book size: " << sizeof(globalBook) << " bytes;" << endl;
				cout << "Local book size: " << sizeof(localBook) << " bytes;" << endl;
				cout << "Static book size: " << sizeof(staticBook) << " bytes;" << endl;
				cout << "Dynamic book size: " << sizeof(*dynamicBook) << " bytes;" << endl;
			}

			//Задание 3. Заполните поля созданных объектов.
			//Замечание: если для хранения строки используется массив, необходимо
			//предусмотреть "защиту" от выхода за границы массива.
			strcpy_s(globalBook.author, book_szs::AUTHOR_SZ, "Tolstoy L.N.");
			strcpy_s(globalBook.title, book_szs::TITLE_SZ, "War And Peace");
			globalBook.year = 1865;
			globalBook.price = 1000.99;
			globalBook.category = CLASSICS;

			strcpy_s(localBook.author, book_szs::AUTHOR_SZ, "Pelevin V");
			strcpy_s(localBook.title, book_szs::TITLE_SZ, "Generation P");
			localBook.year = 1999;
			localBook.price = 345.52;
			localBook.category = POST_MODERN;

			strcpy_s(staticBook.author, book_szs::AUTHOR_SZ, "Chekhov A.P.");
			strcpy_s(staticBook.title, book_szs::TITLE_SZ, "The Cherry Orchad");
			staticBook.year = 1904;
			staticBook.price = 254.20;
			staticBook.category = CLASSICS;

			strcpy_s(dynamicBook->author, book_szs::AUTHOR_SZ, "Sorokin V");
			strcpy_s(dynamicBook->title, book_szs::TITLE_SZ, "Generation P");
			dynamicBook->year = 1999;
			dynamicBook->price = 299.99;
			dynamicBook->category = POST_MODERN;

			//Задание 4. Напишите функцию, выводящую на экран реквизиты книги.
			//Подумайте: как эффективнее передавать экземпляр Book в функцию.
			//Для вывода на консоль используйте функцию стандартной библиотеки
			//printf

			printBook(globalBook);
			printBook(localBook);
			printBook(staticBook);
			printBook(*dynamicBook);
		}
		//Задание 5. Напишите функцию для формирования полей структуры.
		//Для ввода используйте функцию стандартной библиотеки scanf
		//Замечание: неплохо заложить в такую функцию возможность проверки
		//корректности введенного значения, например, год издания не может быть
		//меьше, чем... (год появления письменности), категорию ползователь
		//должен выбирать из существующих, цена не может быть отрицательной...
		Book newBook;
		initBook(newBook);
		printBook(newBook);
		system("pause");
	return 0;
}//main

