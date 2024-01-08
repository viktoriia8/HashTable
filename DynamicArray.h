#pragma once
using namespace std;
template <typename T>
class DynamicArray
{
public:
	int size;
	int maxSize;
	T* array;
	void addNew(T some_data);
	T findDataNr(int i);
	bool newValueInNr(int i, T newValue);
	void to_string();
	void deleteArr();
	bool operator>(const T& other) const {
		return T > other.T;
	}
	void bubbleSort();
	DynamicArray() {
		size = 0;
		maxSize = 1;
		array = new T[maxSize];
	}
};


template <typename T>
void DynamicArray<T>::addNew(T some_data) {
	if (maxSize == size) {
		maxSize *= 2;
		T* newArray = new T[maxSize];
		for (int i = 0; i < size; i++) {
			newArray[i] = array[i];
		}
		delete array;
		array = newArray;
	}
	array[size] = some_data;
	size++;
}
template <typename T>
T DynamicArray<T>::findDataNr(int i) {
	if (i > size - 1) {
		return false;
	}
	else {
		return array[i];
	}
}
template <typename T>
bool DynamicArray<T>::newValueInNr(int i, T newValue) {
	if (i > size - 1) {
		return false;
	}
	else {
		array[i] = newValue;
		return true;
	}
}
template <typename T>
void DynamicArray<T>::to_string() {
	if (!size) {
		cout << "Tablica jest pusta.\n";
		exit;
	}
	for (int i = 0; i < size; i++) {
		cout << "Element nr." << i << " = " << array[i] << endl;
	}
	cout << "-------------------\n";
}
template<typename T>
void DynamicArray<T>::deleteArr() {
	for (int i = 0; i < size; i++) {
		array[i] = NULL;
	}
	size = 0;
	T* newArray = new T[1];
	delete array;
	array = newArray;
	maxSize = 1;
}

template<typename T>
void DynamicArray<T>::bubbleSort() {

	for (int i = 0; i < size - 1; i++) {

		for (int j = 0; j < size - i - 1; j++) {
			if (array[j] > array[j + 1]) {
				T s = array[j];
				array[j] = array[j + 1];
				array[j + 1] = s;
			}
		}
	}
}
