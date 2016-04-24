/*************************************************************
������������ ������� �5.
"������" ��������� ������� ����������� ����������
��������� �� �������
���������
*************************************************************/
#include <tchar.h>
#include <iostream>
//#include <cstdio>
#include "other.h"


#define	  stop __asm nop
Book globalBook;
int _tmain() {
	//���� "������" ��������� ������� ����������� ����������
	//������� 1. � ������� ������� scanf ����������� ��� ������������: A,B,C
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



		//������� 2. �������� (�������!) ������� �������� y=A*x*x + B*x + C
		//��� ��������� x � ��������� -2 �� +2 � ����� 0.5


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
	//���� ��������� �� �������

	//������� 1. ��������� �� �������. "�����������".
	//�������� �������:
	//1)Sum - ��������� ��� �������� double � ���������� �����
	//���� ��������
	//2)Sub- ��������� ��� �������� double � ���������� ��������
	//���� ��������
	//3)Mul - *
	//4)Div - /
	//5)� ��� ���������� � ������� ������ ������������ ������� ����������� ����������
	//		- pow(). ��������� 1: �������� ������� ��������� � <cmath>.
	//		��������� 2: ����������� ���������� ������������� ��������� �������������
	//		��������� ���� �������, � ��� ����������� ������������ ��������� �� 
	//		double pow(double, double);

	//������������ ������������	��������� �����������:
	//���� ������������ ����� ������������ �������� ������ ������������,
	//�� ����� ������� ��� �������� � ���� ��������
	//� �� �������� ���������. ��������� ��������� ����������� ������
	//��������������� ����� ������� �� ���������.
	//������������� ����������� ����� ������������������ ����� ��������
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

		//������� 2. ��������� �� ������� � �������� ���������.
		//���� ��������� ������� ���������� ����� �������� - Sort.
		//������� ��������� ��������� ���������:
		//1) ��������� �� ������ ����������� �������
		//2) ���������� ����������� ���������
		//3) ������ �������� � ������
		//4) ��������� �� ������� ������������ ���������
		//5) ��������� �� ������� ��������� ���������

		//2a. �������� ������� ������������ ���� ����� �������� -
		// SwapInt, ������� ��������� ��� void ��������� � 
		//������ �������� �������

		//�������� ������� ��������� ���� ����� �������� -
		// CmpInt, ������� ��������� ��� void ��������� �
		//���������� int ��������� ���������: 
		//<0 - ������ ������� ������, ��� ������
		//=0 - �����
		//>0 - ������ ������� ������, ��� ������

		//������ ��� ����������
		printDivLine();
		const int N = 10;
		int nAr[N];
		for (int i = 0; i < N; i++) {
			nAr[i] = rand() % 100;
		}
		//������ ��������� �������
		printArray(nAr, N);
		//����� ����������
		int nTotal = N;			//���������� ��������� � �������
		Sort(reinterpret_cast<char*>(&nAr[0]), nTotal, sizeof(int), SwapInt, CmpInt);
		//������ ����������� ����������
		printArray(nAr, N);
		stop
		
		
		//������� 2�. �� �������� � 8� �������� ���������������
		//������� - SwapDouble � CmpDouble � �������� ������� Sort
		//��� ���������� ������� ������������ ��������.
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
		
		//������� 2�*. �� �������� � 8� �������� ���������������
		//������� - SwapStr � CmpStr � �������� ������� Sort
		//��� ���������� ������� ���������� �� ������.
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
		//������� 3. ������� ���������� �� �������.
		//�������� ��������� ������� ����
		//const char* GetString1();
		//const char* GetString2();
		//		...., ������ �� ������� ���������� ��������� �� ���� ������
		//(��������� - ����� ����� �� ������ ����� ���������� �� �������)
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
		

		//�������� � ������������������ ������ ���������� �� �������
		//GetString1,GetString2...
		//������� ����� �������, ������� �� ������ �������:
		//�������� �������
		//������������ ���������

		//////////////////////////////////////////////////////////////////////////////////////

		//����. ��������� �.	
		//������� 1. �������� ��������� Book, ����������� �����
		//(�����, ��������, ��� �������, ����, ����������).
		//���������: ������ ���� ����� ���� ���� ���������.
		//���������: ���������� ��������� ������������� ��������
		//� ������������ ����.


		//������� 2. �������� ������� ��������� (����������, ���������, �����������,
		//������������) ���������� (�������) ���� Book (��� �������������).
		//���������� - ������� ������ ������� ���������� ��� ������
		//����� ������. ��� ���������������� (��� �� ����������������) ����
		//���������. ���������: �� ���� ������� ����� ���������� ������?
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

			//������� 3. ��������� ���� ��������� ��������.
			//���������: ���� ��� �������� ������ ������������ ������, ����������
			//������������� "������" �� ������ �� ������� �������.
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

			//������� 4. �������� �������, ��������� �� ����� ��������� �����.
			//���������: ��� ����������� ���������� ��������� Book � �������.
			//��� ������ �� ������� ����������� ������� ����������� ����������
			//printf

			printBook(globalBook);
			printBook(localBook);
			printBook(staticBook);
			printBook(*dynamicBook);
		}
		//������� 5. �������� ������� ��� ������������ ����� ���������.
		//��� ����� ����������� ������� ����������� ���������� scanf
		//���������: ������� �������� � ����� ������� ����������� ��������
		//������������ ���������� ��������, ��������, ��� ������� �� ����� ����
		//�����, ���... (��� ��������� ������������), ��������� �����������
		//������ �������� �� ������������, ���� �� ����� ���� �������������...
		Book newBook;
		initBook(newBook);
		printBook(newBook);
		system("pause");
	return 0;
}//main

