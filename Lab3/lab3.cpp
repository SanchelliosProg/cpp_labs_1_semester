/*************************************************************
Практическое занятие №3. Встроенные массивы.
Динамическое выделение памяти.
Простейшие алгоритмы сортировки и поиска.
Сложные указатели.
Ссылки.
*************************************************************/
#define	  stop __asm nop

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <string>
#include "func_decl.h"

namespace cnst {
	const int ROW = 2, COL = 10;
}

char generate_asterisk_or_space();
void print_char_2d_array(char ch_array[][cnst::COL]);
void asterisk_count(char ch_array[][cnst::COL], int asterisk_counter[][1]);
void swap_astsks_and_undln(char ch_array[][cnst::COL], int asterisk_counter[][1]);
void move_asterisks_down(char ch_array[][cnst::COL]);

int main(){
	///////////////////////////////////////////////////////////////
	//			Встроенные массивы                               //
	///////////////////////////////////////////////////////////////

	//Задание 1. Объявите трехмерный массив и сформируйте указанные
	//значения элементов следующим образом:
	//а) проинициализируйте массив при объявлении
	const int N = 3, M = 3, K = 3;
	double arr_one[N][M][K] = { { { 1.1, 1.2, 1.3 }, { 1.4, 1.5, 1.6 }, { 1.7, 1.8, 1.9 } },
	{ { 2.1, 2.2, 2.3 }, { 2.4, 2.5, 2.6 }, { 2.7, 2.8, 2.9 } },
	{ { 3.1, 3.2, 3.3 }, { 3.4, 3.5, 3.6 }, { 3.7, 3.8, 3.9 } }
	};
	//б) объявите неинициализированный массив и присвойте значения элементам
	const int FIRST = 3, SECOND = 3, THIRD = 3;
	int arr_2[FIRST][SECOND][THIRD];
	int number = 1;
	for (int i = 0; i < FIRST; i++) {
		for (int j = 0; j < SECOND; j++) {
			for (int k = 0; k < THIRD; k++) {
				arr_2[i][j][k] = i + 1;
			}
		}
		number++;
	}
	//	с помощью кода
	//					 |--------|		
	//				   / |3  3  3 |		
	//    			 |---------|3 |
	//			   / | 2  2  2 |3 |
	//			  |---------|2 |__|
	//			  | 1  1  1 |2 | /
	//			  | 1  1  1 |__| 
	//			  | 1  1  1 | /
	//			  |_________|
	//Средствами отладчика проверьте правильность Вашего решения.

	//в) найдите сумму элементов массива
	int sum = 0;
	for (int i = 0; i < FIRST; i++) {
		for (int j = 0; j < SECOND; j++) {
			for (int k = 0; k < THIRD; k++) {
				sum += arr_2[i][j][k];
			}
		}
	}

	{
		using namespace std;
		cout << "Sum of the arrays elements: " << sum << endl;
	}
	//sum = 0;
	//int* p = &arr2[0][0];
	//г) проинициализируйте массив при объявлении:
	//					 |--------|		
	//				   / |3  0  0 |		
	//    			 |---------|0 |
	//			   / | 2  0  0 |0 |
	//			  |---------|0 |__|
	//			  | 1  0  0 |0 | /
	//			  | 0  0  0 |__| 
	//			  | 0  0  0 | /
	//			  |_________|

	int array_3[3][3][3] = { { 3 }, { 2 }, { 1 } };
	stop
		//д) Инициализация массивов строковыми литералами:
		//Объявите и проинициализируйте строковыми литералами два массива:
		//двухмерный массив и массив указателей. Поясните разницу в использовании
		//элементов таких массивов.

		char m_array[][7] = { { "hello " }, { "world!" } }; //хранит значения
	const char* m_arr_ptr[] = { { "hello " }, { "world!" } };	//хранит адреса строк
	m_array[1][1] = 'W';
	//m_arr_ptr[1][1] = 'W';

	stop

		///////////////////////////////////////////////////////////////
		//			Динамическое выделение памяти                    //
		///////////////////////////////////////////////////////////////
		//Задание2. Создайте динамический двухмерный массив с размерностями,
		//вычисляемыми в процессе выполнения программы - N*M.
		//Задайте значения элементов помощью генератора случайных чисел.
		//Найдите  сумму элементов.
		//Подсказка 1: для генерации случайных чисел используйте функцию
		//стандартной библиотеки - rand() (<cstdlib>)
		//Подсказка 2: На самом деле те значения, которые создаются генератором случайных
		//чисел являются «псевдослучайными», то есть при двух последовательных запусках
		//приложения Вы получаете две одинаковые последовательности значений.
		//Для того чтобы генерируемые "случайные" значения были разными при каждом 
		//запуске приложения используйте функции стандартной библиотеки srand() (<cstdlib>)
		//и time() (<ctime>).
		//Функция srand() осуществляет «привязку» начала генерации к указанному в качестве параметра значению.
		//Функция time() задает эту точку отсчета, считывая текущее время
	{
		using namespace std;
		srand(static_cast<int>(time(0)));
		int N = 3, M = 5;
		{//ВАРИАНТ 1
			print_div_line();
			int** pp = new int*[N];
			for (int i = 0; i < N; i++) {
				pp[i] = new int[M];
				cout << "Unsorted Line " << i + 1 << ": ";
				for (int j = 0; j < M; j++) {
					pp[i][j] = rand() % 100;
					cout << setw(3) << pp[i][j];
				}
				cout << endl;
				selection_sort(pp[i], M);
				print_array(pp[i], M, "Sorted line");
			}

			print_div_line();

			for (int line = 0; line < N; line++) {
				delete[] pp[line];
			}

		}

			{//ВАРИАНТ2
				int* p = new int[N*M];
				int** pp = new int*[N];

				cout << "FILLING THE ARRAY ..." << endl;

				for (int i = 0; i < N*M; i++) {
					if ((i % M) == 0) {
						cout << endl;
					}
					p[i] = rand() % 100;
					cout << setw(3) << p[i];
				}
				cout << endl;
				print_div_line();


				cout << "JUST PRINTING TWO LINES OF ARRAY ..." << endl;
				for (int i = 0; i < N; i++) {
					pp[i] = p + i*M;
					print_array(pp[i], M);
				}
				print_div_line();

				cout << "SORTING ..." << endl;
				for (int i = 0; i < N; i++) {
					pp[i] = p + i*M;
					selection_sort(pp[i], M);
					print_array(pp[i], M);
				}
				print_div_line();
				delete[] p;
				delete[] pp;
			}


			//Задание2а. В сформированном массиве отсортируйте каждую строку по
			//убыванию значений. Используйте сортировку "выбором"
	}
		//Задание2б. Объявите одномерный массив размерностью N.
		//Сформируйте значение i-ого элемента одномерного массива
		//равным среднему значению элементов i-ой строки
		//двухмерного массива
	{ 
		using namespace std;
		print_div_line(2);
		cout << "Ex.2b" << endl << endl;
		int ROW = 9;
		int COL = 5;
		int line = 1;

		int* p = new int[ROW*COL];
		int** pp = new int*[ROW];

		cout << "FILLING THE 2-D ARRAY ..." << endl;

		for (int i = 0; i < ROW*COL; i++) {
			if (i == 0) {
				cout << setw(6) << "LINE[" << line << "]:";
			}
			if ((i % COL) == 0 && i != 0) {
				cout << endl;
				line++;
				cout << setw(6) << "LINE[" << line << "]:";
			}
			p[i] = rand() % 100;
			cout << setw(4) << p[i];
		}
		cout << endl;
		print_div_line();
		cout << "FILLING ARRAY WITH AVERAGES" << endl;
		double* my_array = new double[ROW];
		for (int i = 0; i < ROW; i++) {
			pp[i] = p + i*COL;
			my_array[i] = get_avg_number(pp[i], COL);
		}
		print_div_line();
		cout << "RESULT " << endl;
		print_array(my_array, ROW, 5);

		delete[] p;
		delete[] pp;
		delete[] my_array;

		print_div_line(2);
	}
			

	//Подсказка - не забудьте освободить память!

	/////////////////////////////////////////////////////////////////////
	//Задание 3. а) Напишите фрагмент кода, который вводит NN целых чисел с помощью
	//потока ввода в объявленный Вами встроенный одномерный массив, каждый раз
	//упорядочивая полученное значение по возрастанию
	{
		using namespace std;
		cout << "ex. 3" << endl;
		const int ARR_SIZE = 10;
		int m_array[ARR_SIZE] = { 0 };
		int current_num = 0;
		cout << "Enter " << ARR_SIZE << " numbers." << endl;
		for (int i = 0; i < ARR_SIZE; i++) {
			cout << "> ";
			cin >> current_num;
			if (!is_duplicate(m_array, ARR_SIZE, current_num)) {
				if (i == 0) {
					m_array[i] = current_num;
					print_array(m_array, ARR_SIZE);
				}
				else {
					add_and_sort(m_array, i, current_num, &i);
					print_array(m_array, ARR_SIZE);
				}
			}
			else {
				cout << "\nAborting the Entry..." << endl;
				print_array(m_array, ARR_SIZE);
				i--;
				continue;
			}
		}
		cout << endl;
		print_div_line();
	}
	//б) Простой поиск.
	//Модифицируйте предыдущее задание следующим образом:очередное значение
	//вводится в массив только при условии, что там еще такого нет (то есть
	//дубли игнорируются

	///////////////////////////////////////////////////////////////////////////
	//Задание 4.С помощью данной заготовки напишите программу,
	//которая:
	//вводит строки с клавиатуры с помощью cin>>...
	//в объявленный Вами двухмерный встроенный массив 5*80 элементов типа char;
	//признаком конца ввода является символ * (то есть строка - "*") или
	//заполнение массива (больше свободных строк нет);
	//сортировка строк в алфавитном порядке. Пояснение: крайне
	//не рекомендуется для сортировки сложных объектов физически
	//перемещать их в памяти. Намного эффективнее завести массив
	//указателей на соответствующие строки и перемещать только
	//указатели.

	//Подсказка: для лексиграфического сравнения строк пользуйтесь
	//функцией стандартной библиотеки strcmp(...), заголовочный файл <string>.


	//Определите необходимые значения как константы
	//STOP_STRING  -  "*"	//признак "прекратить ввод"
	//M  -  80	//максимальный размер одной строки
	//N  -  10	//максимальное количество строк в массиве
			{
#define STOP_STRING "*"
#define NULL_STRING '\0' 
				using namespace std;
				const int N = 10;
				const int M = 80;
				//Объявите двухмерный массив с именем cBuffer типа char и
				// размерностью N*M
				char cBuffer[N][M] = {NULL_STRING};
				//Объявите массив (с именем cPointers) указателей на строки
				//размерностью N
				stop
				//Цикл ввода строк:
				//а) выведите приглашение для ввода
				cout << "Enter the characters: " << endl;
				//б) пока не введена строка STOP_STRING или не заполнен весь массив
				char buffer[80] = { 0 };
				//ввод строки в массив cBuffer:
				//если введint i = 0;
				int i = 0;
				while (i < N) {
					cin >> buffer;
					if (strlen(buffer) > N + 1) break;
					if (strcmp(buffer, STOP_STRING) == 0) break;
					strcpy_s(cBuffer[i], buffer);
					i++;
				}

				const int pSIZE = i;
				print_div_line();
				char* cPointers[N];

				cout << "PRINTING WHOLE ARRAY" << endl;
				int pCounter = 0;
				for (int i = 0; i < N; i++) {
					if (*cBuffer[i] != NULL_STRING) {
						cPointers[pCounter] = cBuffer[i];
						cout << cPointers[pCounter] << endl;
						pCounter++;
					}
				}
				print_div_line();
				//Присвойте элементу массива cPointers с индексом nIndex
				//указатель на строку с номером nIndex в массиве cBuffer
				//Выдать диагностику о том, что прием строк завершен.

				//Теперь сортируем строки:
				cout << "BUBBLE SORT: " << endl;
				for (int i = 0; i < pCounter - 1; i++) {
					for (int j = 1; j < pCounter; j++) {
						if (strcmp(cPointers[j - 1], cPointers[j]) == 1) {
							char* temp = cPointers[j - 1];
							cPointers[j - 1] = cPointers[j];
							cPointers[j] = temp;
						}
					}
				}

				for (int i = 0; i < pCounter; i++) {
					cout << cPointers[i] << endl;
				}
				//Цикл сортировки строк по методу "всплывающего пузырька" в
				//порядке возрастания. На каждой итерации - промежуточная печать
				//отсортированных строк
			}
			
			//Задание 5. Реализуйте задание №4, используя не встроенные,
			//а динамические массивы (массив?). Так как строки могут быть разной длины,
			//эффективным решением было бы отводить под каждую строку ровно столько байтов,
			//сколько требуется для ее хранения.
			//При этом необходимые параметры (количество строк
			// сформируйте с помощью потока ввода
				{

					using namespace std;

					int num_of_strings = 10;
					const int STRING_LIMIT = 80;

					char** m_str_array = new char*[num_of_strings];
					int line_counter = 0;

					while (true) {
						char buffer[STRING_LIMIT];
						cin >> buffer;

						if (strlen(buffer) > STRING_LIMIT + 1) break;
						if (strcmp(buffer, STOP_STRING) == 0) break;

						int str_size = strlen(buffer);
						m_str_array[line_counter] = new char[str_size];
						for (int i = 0; i < str_size; i++) {
							m_str_array[line_counter][i] = buffer[i];
						}
						line_counter++;
					}
					print_div_line();
					cout << "PRINT ARRAY OF POINTERS" << endl;
					print_div_line();
					for (int i = 0; i < line_counter; i++) {
						cout << m_str_array[i] << endl;
					}
					print_div_line();
					for (int i = 0; i < line_counter - 1; i++) {
						for (int j = 1; j < line_counter; j++) {
							if (strcmp(m_str_array[j - 1], m_str_array[j]) == 1) {
								char* temp = m_str_array[j - 1];
								m_str_array[j - 1] = m_str_array[j];
								m_str_array[j] = temp;
							}
						}
					}
					cout << "PRINT ARRAY OF POINTERS (AFTER SORT)" << endl;
					print_div_line();
					for (int i = 0; i < line_counter; i++) {
						cout << m_str_array[i] << endl;
					}

					delete[] m_str_array;
					print_div_line(2);
				}
			//Цикл ввода строк:
			//Цикл сортировки строк методом "всплывающего пузырька" в
			//порядке возрастания кода первого символа
			//Освобождение занятой памяти:

			
			//Задание 6. Объявление и использование указателей на многомерные
			// массивы. Проинициализируйте трехмерный массив
			//double dArray[4][3][3] так, как показано на рисунке и напишите фрагмент
			//кода, который меняет местами значения элементов четных
			//и нечетных слоев:
			//	было:			     |--------|
			//  				   / |4  4  4 |
			//					 |--------|	4 |
			//				   / |3  3  3 |	4 |
			//    			 |---------|3 |   |
			//			   / | 2  2  2 |3 | /
			//			  |---------|2 |__|
			//			  | 1  1  1 |2 | /
			//			  | 1  1  1 |__|
			//			  | 1  1  1 | /
			//			  |_________|

			//	стало:			     |--------|
			//  				   / |3  3  3 |
			//					 |--------|	3 |
			//				   / |4  4  4 |	3 |
			//    			 |---------|4 |   |
			//			   / | 1  1  1 |4 | /
			//			  |---------|1 |__|
			//			  | 2  2  2 |1 | /
			//			  | 2  2  2 |__|
			//			  | 2  2  2 | /
			//			  |_________|

			//for(int i=0; i<...; ...)
			//{
			////Замечание: НЕ НУЖНО МОДИФИЦИРОВАТЬ ВЫРАЖЕНИЯ СПРАВА ОТ ЗНАКА РАВЕНСТВА!!!
			//... =  dArray[i];
			//... =  dArray[i+1];
			////переставляем местами элементы i-того и i+1-ого слоев
			//}

			{
				using namespace std;

				const int LR = 4, ROW = 3, COL = 3;
				double dArray[LR][ROW][COL];
				double num = 1;
				for (int i = 0; i < LR; i++) {
					for (int j = 0; j < ROW; j++) {
						fill_n(dArray[i][j], COL, num);
					}
					num++;
				}

				for (int i = 0; i < LR - 1; i++) {
					if ((i + 1) % 2 == 1) {
						double odd_val = dArray[i][0][0];
						double even_val = dArray[i + 1][0][0];
						for (int j = 0; j < ROW; j++) {
							fill_n(dArray[i][j], COL, even_val);
							fill_n(dArray[i + 1][j], COL, odd_val);
						}
					}
				}
				stop
			}


			
			///////////////////////////////////////////////////////////////////////////
			//Задание 7а. Объявите двухмерный встроенный массив элементов типа char.
			//Сформируйте значения элементов массива с помощью генератора случайных
			//чисел таким образом, чтобы в массиве были только символы '*' и '_'


			//В каждой строке "сдвиньте звездочки" в начало строки, например:
			//было - '*' '_' '_' '*' '*' '_' '*' '_' '*' '_'
			//стало: '*' '*' '*' '*' '*' '_' '_' '_' '_' '_'
			//и распечатайте массив по строкам - "постройте распределение"


			// 7б. Модифицируйте предыдущее задание следующим способом:
			//После заполнения массива с помощью генератора случайных чисел
			//"сдвиньте" звездочки по столбцам вниз и распечатайте полученное
			//"распределение"
			{
				using namespace std;
				using namespace cnst;
				srand(static_cast<int>(time(0)));
				char ch_array[ROW][COL] = { 0 };

				for (int i = 0; i < ROW; i++) {
					for (int j = 0; j < COL; j++) {
						ch_array[i][j] = generate_asterisk_or_space();
					}
				}

				for (int i = 0; i < ROW; i++) {
					for (int j = 0; j < COL; j++) {
						cout << ch_array[i][j] << ' ';
					}
					cout << endl;
				}

				int asterisk_counter[ROW][1] = { { 0 }, { 0 } };

				cout << "Choose the mode:" << endl
					<< "0 - swap asterisks and undrlines;" << endl
					<< "1 - move asterisks down;" << endl
					<< "> ";
				int choise = 0;
				cin >> choise;
				print_div_line();
				switch (choise) {
				case 0:
					cout << "Counting asterisks..." << endl;
					asterisk_count(ch_array, asterisk_counter);
					cout << "Swapping asterisks with underlines..." << endl;
					swap_astsks_and_undln(ch_array, asterisk_counter);
					print_char_2d_array(ch_array);
					print_div_line();
					break;
				case 1:
					move_asterisks_down(ch_array);
					print_char_2d_array(ch_array);
					print_div_line();
					break;
				default:
					break;
				}
			}

			system("pause");
			return 0;

}

char generate_asterisk_or_space() {
	int num = rand() % 2;
	switch (num) {
	case 0:
		return '_';
	case 1:
		return '*';
	default:
		return '_';
	}
}

void print_char_2d_array(char ch_array[][cnst::COL]) {
	using namespace std;
	using namespace cnst;
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			cout << ch_array[i][j] << ' ';
		}
		cout << endl;
	}
}

void asterisk_count(char ch_array[][cnst::COL], int asterisk_counter[][1]) {
	using namespace cnst;
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			if (ch_array[i][j] == '*') {
				asterisk_counter[i][0]++;
			}
		}
	}
}

void swap_astsks_and_undln(char ch_array[][cnst::COL], int asterisk_counter[][1]) {
	using namespace cnst;
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			if (asterisk_counter[i][0] > 0) {
				ch_array[i][j] = '*';
				asterisk_counter[i][0]--;
			}
			else {
				ch_array[i][j] = '_';
			}
		}
	}
}

void move_asterisks_down(char ch_array[][cnst::COL]) {
	using namespace cnst;
	for (int i = 0; i < ROW - 1; i++) {
		for (int j = 0; j < COL; j++) {
			if (ch_array[i][j] == '*') {
				ch_array[i][j] = '_';
				ch_array[i + 1][j] = '*';
			}
		}
	}
}