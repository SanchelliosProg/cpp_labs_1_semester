/*************************************************************
Практическое занятие №3. Функции.
Объявление, определение, вызов.
Передача параметров. Возвращение значения.
Указатели на функции
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
	// Задание 1. Ссылки.
	//Объявите ссылку на тип double. Посредством ссылки измените значение
	{
		double d_var = 10;
		double& d_ref = d_var;
		d_ref = 20;
		stop
	}

	//Раскомментируйте две следующих строчки. Что следует сделать, чтобы
	//linker не выдавал ошибки при создании exe-файла Подсказка: ссылка ref
	//должна быть внешней
	{

		//	extern int& ref;
		ref++;
		stop
	}

	//Раскомментируйте следующую строку. Что следует сделать, чтобы
	//компилятор не выдавал ошибки 
	const int& ref1 = 1;

	//Задан указатель:
	char c = 'A';
	char c_2 = 'X';
	char* pc = &c;
	//Объявите ссылку на указатель. Посредством ссылки измените
	//а) значение по адресу
	char*& ref_pc = pc;
	*ref_pc = 'B';
	//б) сам адрес
	ref_pc = &c_2;
	stop

		//Задание 2. Отличия при передаче параметров а) по значению,
		// б) по ссылке, в) по указателю
		//Объявите и определите три функции , которые увеличивают заданное
		//с помощью параметра значение на 1 ( а) - IncByValue(),
		// б) - IncByPointer(), в) - IncByReference() ). 
		//Проверьте правильность с помощью отладчика.
		//Замечание: объявления функций принято помещать в заголовочный файл
		int val = 1;//значение этой переменной должно быть увеличено с помощью
	//каждой из функций на единицу
	val = incByValue(val);
	incByPointer(&val);
	incByReference(val);
	stop

		//Задание 2а. Передача параметров c помощью указателя и по ссылке. 
		//Перегруженные имена функций.
		//Создайте функцию (функции) Swap(), которая меняет значения
		//переменных nX и nY местами. 
		// а)Функция должна принимать два указателя на int, оперируя с 
		//которыми менять значения переменных в вызывающей программе
		// б)Функция должна принимать две ссылки на int 
		//Проверьте правильность с помощью приведенного ниже фрагмента.

		int	nX = 1;
	int nY = -1;
	swap(&nX, &nY);	//поменяли местами значения nX и nY с
	//помощью указателей на nX и nY
	swap(nX, nY);	//а теперь обратно с помощью ссылок на nX и nY
	stop

		//Задание 3. Указатели на массивы в качестве аргументов.
		//3a.Напишите два варианта функции поиска минимального элемента
		//1. во встроенном двухмерном массиве
		//2. в динамическом двухмерном массиве (обе размерности вычисляются)

		//1.Например:
		//int ar[N][M] = {список инициализаторов};//подумайте - как и где должны быть заданы N и M
		//int res = Min(ar, ... может быть, понадобится передать еще какие-нибудь данные); 
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

		//3b. Напишите функцию сравнения двух строк - MyStrCmp():
		//Функция должна принимать два указателя на сравниваемые
		//строки (возможно Вы должны указать компилятору, что функция
		//не имеет права модифицировать содержимое строк)
		//Функция должна возвращать отрицательное значение, если
		//первая строка лексиграфически меньше второй, 0 - если
		//они равны и положительное значение, если первая строка
		//больше второй.
		//Вспомните, что признаком конца строки является нулевой байт.
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

		//Создайте две строки для сравнения: 

		//Вызовите функцию сравнения

		//Выведите результат сравнения с помощью cout:

		stop


			//Задание 4.Ссылки в качестве параметров. Передача указателя на встроенный
			//массив в качестве параметра функции.

			//Напишите две взаимодополняющие друг друга функции:
			//1.  ... DayOfYear(...)
			//- преобразует день месяца (число,месяц и год задаются в качестве параметров)
			//в порядковый день года(возвращаемое значение)
			//2. ... DayOfMonth(...) - функция преобразует порядковый день года в день месяца
			// (принимает год и порядковый день года в качестве параметров и должна сформировать
			// день месяца и номер месяца и каким-то образом сообщить эти значения вызывающей процедуре)

			//Проверьте работоспособность обеих функций с помощью следующего фрагмента:


			//В процессе вычислений Вам придется учитывать "високосный - невисокосный" год.
			//Для этого предлагается в каждую функцию в качестве одного из параметров передавать
			//данные приведенного ниже двухмерного массива nDayTab

			int nDayTab[2][12] = {
				{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }, //невисокосный год
				{ 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 } };	//високосный год
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

		//Вызов функции DayOfYear
		//...


		//Проверка результата обратной функцией DayOfMonth
		//...

		stop

			//Задание 5. Создайте одномерный массив (размерность вычисляется в процессе
			//выполнения программы), заполните его значениями.
			//Напишите функцию, которая добавляет в массив ервре значение только при
			//условии, что такого значения в массиве еще нет. Подсказка: при этом размер
			//массива должен увеличиться! Функция НЕ ДОЛЖНА ничего возвращать.

			//Для проверки напишите функцию, которая выводит значения всех элементов на экран
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


			//Задание 6. Рекурсивные функции. Напишите рекурсивную функцию вычисления
			//суммы первых N натуральных чисел.

		{
			using namespace std;
			int num = 0, sum = 0;
			cout << "Enter the number: " << endl;
			cin >> num;
			recursive_f(num, sum);
			printf("Sum of the first %i natural numbers is: %i\n", num, sum);
			print_div_line();
		}


		
		//Задание 7а. Функции с переменным числом параметров.
		//Напишите функцию (дана заготовка VarArgs, не использующая
		// макросы), которая принимает переменное число аргументов
		// типа int и выводит на печать число принятых параметров и
		// их значения.
		// Признаком конца списка является нулевое значение.

		int nN1=5, nN2=11, nN3=4, nN4=7, nN5=-1;
		VarArgs(nN1,0);
		VarArgs(nN1,nN2,0);
		VarArgs(nN1,nN2,nN3,nN4,nN5,0);
		stop


		//Задание 7б. Модифицируйте функцию 5а с помощью макросов
		// va_start, va_arg, va_end
		
		VarArgsWithMacros(nN1, 0);
		VarArgsWithMacros(nN1, nN2, 0);
		VarArgsWithMacros(nN1, nN2, nN3, nN4, nN5, 0);
		stop
		//Задание 8. Возвращение адреса.
		//Напишите функцию, которая находит минимальное значение в массиве,
		// таким образом, чтобы ее вызов можно было использовать слева от знака 
		// равенства: *MyMin(параметры) = 0;
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

