/*************************************************************
������������ ������� �3. �������.
����������, �����������, �����.
�������� ����������. ����������� ��������.
��������� �� �������
*************************************************************/
#include <iostream>
#include <tchar.h>
#include <ctime>
#include <string>
//#include <cstdio>
//#include <cstdarg>
#include "other.h"
#define	  stop __asm nop

void print_div_line() {
	using namespace std;
	cout << endl << "--------------------------------------" << endl;
}

int _tmain() {

	/////////////////////////////////////////////////////////////////////////////
	// ������� 1. ������.
	//�������� ������ �� ��� double. ����������� ������ �������� ��������
	{
		double d_var = 10;
		double& d_ref = d_var;
		d_ref = 20;
		stop
	}

	//���������������� ��� ��������� �������. ��� ������� �������, �����
	//linker �� ������� ������ ��� �������� exe-����� ���������: ������ ref
	//������ ���� �������
	{

		//	extern int& ref;
		ref++;
		stop
	}

	//���������������� ��������� ������. ��� ������� �������, �����
	//���������� �� ������� ������ 
	const int& ref1 = 1;

	//����� ���������:
	char c = 'A';
	char c_2 = 'X';
	char* pc = &c;
	//�������� ������ �� ���������. ����������� ������ ��������
	//�) �������� �� ������
	char*& ref_pc = pc;
	*ref_pc = 'B';
	//�) ��� �����
	ref_pc = &c_2;
	stop

		//������� 2. ������� ��� �������� ���������� �) �� ��������,
		// �) �� ������, �) �� ���������
		//�������� � ���������� ��� ������� , ������� ����������� ��������
		//� ������� ��������� �������� �� 1 ( �) - IncByValue(),
		// �) - IncByPointer(), �) - IncByReference() ). 
		//��������� ������������ � ������� ���������.
		//���������: ���������� ������� ������� �������� � ������������ ����
		int val = 1;//�������� ���� ���������� ������ ���� ��������� � �������
	//������ �� ������� �� �������
	val = incByValue(val);
	incByPointer(&val);
	incByReference(val);
	stop

		//������� 2�. �������� ���������� c ������� ��������� � �� ������. 
		//������������� ����� �������.
		//�������� ������� (�������) Swap(), ������� ������ ��������
		//���������� nX � nY �������. 
		// �)������� ������ ��������� ��� ��������� �� int, �������� � 
		//�������� ������ �������� ���������� � ���������� ���������
		// �)������� ������ ��������� ��� ������ �� int 
		//��������� ������������ � ������� ������������ ���� ���������.

		int	nX = 1;
	int nY = -1;
	swap(&nX, &nY);	//�������� ������� �������� nX � nY �
	//������� ���������� �� nX � nY
	swap(nX, nY);	//� ������ ������� � ������� ������ �� nX � nY
	stop

		//������� 3. ��������� �� ������� � �������� ����������.
		//3a.�������� ��� �������� ������� ������ ������������ ��������
		//1. �� ���������� ���������� �������
		//2. � ������������ ���������� ������� (��� ����������� �����������)

		//1.��������:
		//int ar[N][M] = {������ ���������������};//��������� - ��� � ��� ������ ���� ������ N � M
		//int res = Min(ar, ... ����� ����, ����������� �������� ��� �����-������ ������); 
	{
		using namespace ar_const;
		int min_num = 0;
		srand(time(0));
		int ar[][COL] = { 0 };
		randomize_2d_array(ar, sizeof(ar) / sizeof(ar[0]), 20);
		min_num = findMinNumber(ar, sizeof(ar) / sizeof(ar[0]));
		stop
	}

	{
		using namespace std;
		unsigned int rows = 0, columns = 0, min_num = 0;
		cout << "Enter number of rows: ";
		cin >> rows;
		cout << "Enter number of columns: ";
		cin >> columns;
		int** p = new int*[rows];
		for (int i = 0; i < rows; i++) {
			p[i] = new int[columns];
		}
		randomize_2d_array(p, rows, columns, 10);
		min_num = findMinNumber(p, rows, columns);
		cout << "Minimal number from array is: " << min_num << endl;
		stop
			for (int i = 0; i < rows; i++) {
				delete[]p[i];
			}
		delete[]p;
		print_div_line();
	}

		//3b. �������� ������� ��������� ���� ����� - MyStrCmp():
		//������� ������ ��������� ��� ��������� �� ������������
		//������ (�������� �� ������ ������� �����������, ��� �������
		//�� ����� ����� �������������� ���������� �����)
		//������� ������ ���������� ������������� ��������, ����
		//������ ������ ��������������� ������ ������, 0 - ����
		//��� ����� � ������������� ��������, ���� ������ ������
		//������ ������.
		//���������, ��� ��������� ����� ������ �������� ������� ����.
		{
			using namespace std;
			char first[50];
			char second[50];
			int result_of_comparison = 0;
			cout << "Enter first word: ";
			cin >> first;
			cout << "Enter second word: ";
			cin >> second;
			result_of_comparison = myStrCmp(first, second, strlen(first), strlen(second));
			cout << print_result_of_comparison(result_of_comparison) << endl;
			print_div_line();
		}

		//�������� ��� ������ ��� ���������: 

		//�������� ������� ���������

		//�������� ��������� ��������� � ������� cout:

		stop


			//������� 4.������ � �������� ����������. �������� ��������� �� ����������
			//������ � �������� ��������� �������.

			//�������� ��� ����������������� ���� ����� �������:
			//1.  ... DayOfYear(...)
			//- ����������� ���� ������ (�����,����� � ��� �������� � �������� ����������)
			//� ���������� ���� ����(������������ ��������)
			//2. ... DayOfMonth(...) - ������� ����������� ���������� ���� ���� � ���� ������
			// (��������� ��� � ���������� ���� ���� � �������� ���������� � ������ ������������
			// ���� ������ � ����� ������ � �����-�� ������� �������� ��� �������� ���������� ���������)

			//��������� ����������������� ����� ������� � ������� ���������� ���������:


			//� �������� ���������� ��� �������� ��������� "���������� - ������������" ���.
			//��� ����� ������������ � ������ ������� � �������� ������ �� ���������� ����������
			//������ ������������ ���� ����������� ������� nDayTab

			int nDayTab[2][12] = {
				{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }, //������������ ���
				{ 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 } };	//���������� ���
		bool doStuff = true;
		while (doStuff) {
			using namespace std;
			int day, month, year;
			cout << "Enter the data please: " << endl
				<< "\tDAY: ";
			cin >> day;
			cout << "\tMONTH: ";
			cin >> month;
			cout << "\tYEAR: ";
			cin >> year;
			int day_of_year = dayOfYear(day, month, year, nDayTab);
			if (day_of_year == -1) {
				cout << "ERROR: You've entered the wrong data" << endl;
			}
			else {
				printf("The %i.%i.%i is the %i day of the year\n", day, month, year, day_of_year);
				cout << "Enter the day of the year: " << endl
					<< "\tDAY: ";
				int day = 0;
				cin >> day;
				int year = 0;
				cout << "\tYEAR: ";
				cin >> year;
				int day_of_month = dayOfMonth(day, year, nDayTab);
				printf("The %i day of the year %i, is %i day of ", day, year, day_of_month);
				cout << (defineMonth(day / 30 + 1)) << endl;
			}
			doStuff = isContinue("Do you want to enter a new date?");

			print_div_line();
		}

		//����� ������� DayOfYear
		//...


		//�������� ���������� �������� �������� DayOfMonth
		//...

		stop

			//������� 5. �������� ���������� ������ (����������� ����������� � ��������
			//���������� ���������), ��������� ��� ����������.
			//�������� �������, ������� ��������� � ������ ����� �������� ������ ���
			//�������, ��� ������ �������� � ������� ��� ���. ���������: ��� ���� ������
			//������� ������ �����������! ������� �� ������ ������ ����������.

			//��� �������� �������� �������, ������� ������� �������� ���� ��������� �� �����
		{
			using namespace std;
			int size_of_array = 5;

			cout << "Enter initial data to array (integer numbers): " << endl;
			int *p = new int[size_of_array];
			for (int i = 0; i < size_of_array; i++)
				p[i] = rand() % 30 + 1;

			cout << "PRINT OF INITIAL ARRAY: ";
			printArray(p, size_of_array);

			bool doContinue = true;
			while (doContinue) {
				cout << "Add number, please: ";
				int num = 0;
				cin >> num;
				addNumToArray(num, p, size_of_array);
				printArray(p, size_of_array);
				doContinue = isContinue("Do you want to add a number? ");
			}
			delete[] p;
			print_div_line();
		}


			//������� 6. ����������� �������. �������� ����������� ������� ����������
			//����� ������ N ����������� �����.

		{
			using namespace std;
			int num = 0, sum = 0;
			cout << "Enter the number: " << endl;
			cin >> num;
			recursive_f(num, sum);
			printf("Sum of the first %i natural numbers is: %i\n", num, sum);
			print_div_line();
		}


		
		//������� 7�. ������� � ���������� ������ ����������.
		//�������� ������� (���� ��������� VarArgs, �� ������������
		// �������), ������� ��������� ���������� ����� ����������
		// ���� int � ������� �� ������ ����� �������� ���������� �
		// �� ��������.
		// ��������� ����� ������ �������� ������� ��������.

		int nN1=5, nN2=11, nN3=4, nN4=7, nN5=-1;
		VarArgs(nN1,0);
		VarArgs(nN1,nN2,0);
		VarArgs(nN1,nN2,nN3,nN4,nN5,0);
		stop


		//������� 7�. ������������� ������� 5� � ������� ��������
		// va_start, va_arg, va_end
		
		VarArgsWithMacros(nN1, 0);
		VarArgsWithMacros(nN1, nN2, 0);
		VarArgsWithMacros(nN1, nN2, nN3, nN4, nN5, 0);
		stop
		//������� 8. ����������� ������.
		//�������� �������, ������� ������� ����������� �������� � �������,
		// ����� �������, ����� �� ����� ����� ���� ������������ ����� �� ����� 
		// ���������: *MyMin(���������) = 0;
		{
			const int size = 10;
			int myArray[size];
			int maxNum = 0;
			int minNum = 0;
			std::cout << "Enter the maximum number: ";
			std::cin >> maxNum;
			std::cout << "Enter the minimum number: ";
			std::cin >> minNum;
			for (int i = 0; i < size; i++) {
				myArray[i] = rand() % (maxNum - minNum) + minNum;
			}
			*myMin(myArray, size) = 0;
		}

		system("pause");
		return 0;
}//main

