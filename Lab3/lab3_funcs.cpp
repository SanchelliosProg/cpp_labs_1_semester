#include <iostream>
#include <iomanip>
using namespace std;

void print_div_line(){
	using namespace std;
	cout << "-------------------------------------------------------------" << endl;
}

void print_div_line(int num_of_lines){
	using namespace std;
	for (int i = 0; i < num_of_lines; i++){
		cout << "-------------------------------------------------------------" << endl;
	}
}

int get_array_size(int arr[]){
	return sizeof(arr) / sizeof(int);
}

void print_double_array(int *arr, int size){
	using namespace std;
	cout << "array = {";
	for (int i = 0; i < size - 1; i++){
		cout << arr[i] << ", ";
	}
	cout << arr[size - 1] << "}" << endl;
}

void selection_sort(int my_array[], int array_size){
	for (int i = 0; i < array_size - 1; i++){
		int min = i;
		for (int j = i + 1; j < array_size; j++){
			if (my_array[j] < my_array[min]){
				min = j;
			}
		}
		int temp = my_array[min];
		my_array[min] = my_array[i];
		my_array[i] = temp;
	}
}

void print_array(int my_array[], int size_of_array){
	using namespace std;
	cout << "ARRAY = { ";
	for (int i = 0; i < size_of_array; i++){
		if (i == size_of_array - 1){
			cout << my_array[i];
		}
		else {
			cout << my_array[i] << ", ";
		}
	}
	cout << "}" << endl;
}

void print_array(double my_array[], int size_of_array, int width){
	using namespace std;
	cout << "ARRAY = { ";
	for (int i = 0; i < size_of_array; i++){
		cout << setw(width) << my_array[i];
	}
	cout << "}" << endl;
}

void print_array(int my_array[], int size_of_array, char text[]){
	using namespace std;
	cout << text << " = { ";
	for (int i = 0; i < size_of_array; i++){
		cout << setw(3) << my_array[i];
	}
	cout << "}" << endl;
}

void print_array(char* my_array[], int size_of_array){
	using namespace std;
	cout << " = { ";
	for (int i = 0; i < size_of_array; i++){
		cout << my_array[i];
	}
	cout << "}" << endl;
}

double get_avg_number(int arr[], int size_of_array){
	int sum = 0;
	for (int i = 0; i < size_of_array; i++){
		sum += arr[i];
	}
	return static_cast<double>(sum) / size_of_array;
}

bool is_duplicate(int arr[], int size_of_arr, int current_num){
	using namespace std;
	for (int i = 0; i < size_of_arr; i++){
		if (arr[i] == current_num){
			cout << "You've entered a duplicate" << endl;
			return true;
		}
	}
	return false;
}

void add_and_sort(int arr[], int j, int current_num, int* counter){
	using namespace std;
	for (; j > 0; j--){
		if (current_num < arr[j - 1]){
			int temp = arr[j - 1];
			arr[j - 1] = current_num;
			arr[j] = temp;
		} else {
			arr[j] = current_num;
			break;
		}
	}
}