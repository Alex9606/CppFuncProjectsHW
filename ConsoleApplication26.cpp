#include <iostream>
#define random(min, max) (min + rand() % (max - min + 1))


using namespace std;

template <typename T>
void showArr(T** arr) {
	int size1 = _msize(arr) / sizeof(arr[0]);
	int size2 = _msize(arr[0]) / sizeof(arr[0][0]);
	for (int i = 0; i < size1; i++) {
		for (int j = 0; j < size2; j++) {
			cout << arr[i][j];
		}
	}
}



template <typename T>
void copArr(T** arr1, T** arr2) {
	int size1 = _msize(arr1) / sizeof(arr1[0]);
	int size2 = _msize(arr1[0]) / sizeof(arr1[0][0]);
	for (int i = 0; i < size1; i++) {
		for (int j = 0; j < size2; j++) {
			arr2[i][j] = arr1[i][j];
		}
	}
}

template <typename T>
void delEle(T* &arr, int index) {
	int size = _msize(arr) / sizeof(arr[0]);
	if (index >= size) {
		cout << "EROR\n";
		return;
	}
	T* buf = new T[size - 1];
	for (int i = 0; i < index; i++) {
		buf[i] = arr[i];
	}
	for (int i = index + 1; i < size; i++) {
		buf[i-1] = arr[i];
	}
	delete[] arr;
	arr = buf;
}


template <typename T>
void addArr(T** arr1, T* arr2, int index) {
		int size1 = _msize(arr1) / sizeof(arr1[0]);
		int size2 = _msize(arr1[0]) / sizeof(arr1[0][0]);
		int size3 = _msize(arr2) / sizeof(arr2[0]);
		T** buf = new T*[size1 + 1];
		for (int i = 0; i < index; i++){
			buf[i] = arr1[i];
		}
		T** buf2 = new T*[size3];
		for (int i = 0; i < size3; i++) {
			buf2[i] = arr2;
		}
		buf[index] = arr2;
		for (int i = index; i < size2; i++) {
			buf[i + 1] = arr1[i];
		}
		delete[] arr1;
		arr1 = buf;
}

//template <typename T>
//void delVer(T arr, int index) {
//	int = size1 = _msize(arr) / sizeof(arr[0]);
//	int = size2 = _msize(arr[0]) / sizeof(arr[0][0]);
//}
//void delMinStrok(int) {
//
//}


int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));

	//-1-
	//int a, b, d, c;
	//cout << "Введите 1 число: ";
	//cin >> a;
	//cout << "Введите 2 число: ";
	//cin >> b;
	//cout << "Введите 3 число: ";
	//cin >> d;
	//cout << "Введите 4 число: ";
	//cin >> c;
	//cout << "Среднее ариф: " << a << ", " << b << ", " << d << ", " << c << "=" << (a + b + d + c) / 4;

	//-2-
	/*int a1 = 1, b2 = 40;
	if (a1 % 2 != 0)a1++;
	for (int i = a1; i <= b2; i+=2){
		cout << i << " ";
	}
	cout << endl;*/


	//-3-
	//int strok3;
	//cout << "Ввести сторону квадрата: ";
	//cin >> strok3;
	//for (int i = 0; i <= strok3; i++){
	//	for (int j = 0; j < i; j++) {
	//		cout << "* ";
	//	}
	//	cout << endl;
	//}
	//cout << endl;


	//-4-
	/*int number;
	cout << "Введите число: ";
	cin >> number;
	int count = 0;
	while (number != 0){
		number != 10;
		count++;
	}
	cout << "Число состоит из: " << count << " разрядов\n";
	cout << endl;*/


	//-5-
	/*int const SIZE = 10;
	int array[SIZE];
	int min, max;
	cout << "Введите миним число: ";
	cin >> min;
	cout << "Введите максималь число: ";
	cin >> max;
	for (int i = 0; i < SiZE; i++){
		array[i] = random(min, max);
	}
	for (int i = 0; i < SiZE; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
	cout << endl;*/

	//-6-
	/*int size61 = 4, size62 = 4;
	int** array6 = new int* [size61];
	for (int i = 0; i < size61; i++) {
		array6[i] = new int[size62];
	}
	for (int i = 0; i < size61; i++) {
		for (int j = 0; j < size62; j++) {
			array6[i][j] = random(1, 10);
			cout << array6[i][j] << " ";
		}
		cout << endl;
	}
	int* sum1 = new int [size61]{};
	for (int i = 0; i < size62; i++) {
		for (int j = 0; j < size62; j++) {
			sum1[i] += array6[i][j];
		}
	}
	int index = 0;
	for (int max = sum1[0], i = 0; i < size61; i++){
		if (max < sum1[i]) {
			max < sum1[i];
			index = i;
		}
	}
	cout << "В строке номер " << index + 1 << " сумма элементов наибольшая\n";
	cout << endl;*/


	//-7-
	int size71 = 4, size72 = 4;
	int** array71 = new int* [size71];
	for (int i = 0; i < size71; i++) {
		array71[i] = new int[size72];
	}
	int** array72 = new int* [size71];
	for (int i = 0; i < size71; i++) {
		for (int j = 0; j < size72; j++) {
			array71[i][j] = random(1, 10);
			cout << array71[i][j] << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < size71; i++) {
		array72[i] = new int[size72];
	}
	copArr(array71, array72);

	for (int i = 0; i < size71; i++) {
		for (int j = 0; j < size72; j++) {
			array71[i][j] = random(1, 10);
			cout << array71[i][j] << " ";
		}
		cout << endl;
	}


	//-8-
	/*int* array81 = new int[5];
	for (int i = 0; i < 5; i++){
		array81[i] = random(1, 10);
		cout << array81[i] << " ";
	}
	cout << endl;
	delEle(array81, 3);
	for (int i = 0; i < 4; i++) {
		array81[i] = random(1, 10);
		cout << array81[i] << " ";
	}
	cout << endl;*/


	//-9-
	/*int size91 = 4, size92 = 4;
	int** array91 = new int* [size91];
	for (int i = 0; i < size91; i++) {
		array91[i] = new int[size92];
	}
	for (int i = 0; i < size91; i++) {
		for (int j = 0; j < size92; j++) {
			array91[i][j] = random(1, 10);
			cout << array91[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	int* array92 = new int[5];
	for (int i = 0; i < 4; i++){
		array92[i] = random(1, 10);
		cout << array91[i] << " ";
	}
	cout << endl;
	addArr(array91, array92, 1);
	for (int i = 0; i < size91; i++) {
		for (int j = 0; j < size92; j++) {
			cout << array91[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;*/

	//-10-
	/*int size10 = 4, size20 = 4;
	int** array10 = new int* [size10];
	for (int i = 0; i < size10; i++) {
		array10[i] = new int[size20];
	}
	for (int i = 0; i < size10; i++) {
		for (int j = 0; j < size10; j++) {
			array10[i][j] = random(1, 10);
			cout << array10[i][j] << " ";
		}
		cout << endl;
	}
	delVer(array10, 3);*/

}
