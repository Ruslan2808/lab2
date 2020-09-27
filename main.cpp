#include <iostream>
#include <iomanip>

using namespace std;

class Array {

private:

	int** mas;
	int n, id;
	static int Count;

public:

	Array(int a);

	void vvod();
	void show()const;
	int min();
	int max();
	int GetID()const;

	~Array();
};

int Array::Count = 0;

int main() {
	setlocale(LC_ALL, "rus");
	int size;
	cout << "Введите размер матрицы: ";
	cin >> size;
	Array arr(size);
	cout << "Введите элементы матрицы: " << endl;
	arr.vvod();
	cout << "Матрица: ";
	arr.show();
	cout << "Максимальный элемент выше главной диагонали: " << arr.max() << endl;
	cout << "Минимальный элемент ниже главной диагонали: " << arr.min() << endl;
	cout << "Номер матрицы: " << arr.GetID() << endl;
	return 0;
}

Array::Array(int a) {
	n = a;
	mas = new int* [n];
	for (int i = 0; i < n; i++) {
		mas[i] = new int[n];
	}
	Count++;
	id = Count;
}

Array::~Array() {
	for (int i = 0; i < n; i++) {
		delete mas[i];
	}
	delete[] mas;
}

void Array::vvod() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mas[i][j];
		}
	}
}

void Array::show() const {
	for (int i = 0; i < n; i++) {
		cout << endl;
		for (int j = 0; j < n; j++) {
			cout << setw(3) << mas[i][j] << " ";
		}
	}
	cout << endl;
}

int Array::min() {
	int min = mas[n - 1][n - 2];
	for (int i = n - 1; i > 0; i--) {
		for (int j = i - 1; j >= 0; j--) {
			if (mas[i][j] < min) {
				min = mas[i][j];
			}
		}
	}
	return min;
}

int Array::max() {
	int max = mas[0][1];
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (mas[i][j] > max) {
				max = mas[i][j];
			}
		}
	}
	return max;
}

int Array::GetID() const {
	return id;
}
