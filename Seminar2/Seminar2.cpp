#include <iostream>
#include <typeinfo>

using std::cout;
using std::cin;
/*
* 
* Задание 1
* 	
*/
class NumberMassive { 
	static const int ARRAY_SIZE_LIMIT = 10000;

	int16_t* arrayData;
	int16_t arraySize;


public:
	NumberMassive(int16_t size) {
		arraySize = size;
		if (arraySize > ARRAY_SIZE_LIMIT) throw std::bad_alloc();
		arrayData = new int16_t[arraySize];
	}
	~NumberMassive() {
		delete[] arrayData;
	}
	NumberMassive(const NumberMassive& nm) {
		this->arraySize = nm.arraySize;
		this->arrayData = new int16_t[this->arraySize];
		for (int16_t i = 0; i < this->arraySize; i++) {
			arrayData[i] = nm.arrayData[i];
		}
	}


	void show() {
		for (int16_t i = 0; i < arraySize; i++) {
			cout << arrayData[i] << ' ';
		}
		cout << '\n';
	}


	void setNum(int16_t pos, int16_t number) {
		if (pos >= 0 && pos < arraySize) {
			if (number >= -100 && number <= 100) {
				arrayData[pos] = number;
			}
			else {
				throw std::invalid_argument("The number must belong to the interval [-100; 100]\n");
			}
		}
		else {
			throw std::range_error("Number cannot be set outside the array\n");
		}
	}


	int16_t getNum(int16_t pos) {
		if (pos >= 0 && pos < arraySize) {
			return arrayData[pos];
		}
		else {
			throw std::range_error("Number cannot be set outside the array\n");
		}
	}


	void addNum(int16_t number) {
		if (number >= -100 && number <= 100) {
			int16_t* bufData = arrayData;

			arraySize++;
			if (arraySize > ARRAY_SIZE_LIMIT) throw std::bad_alloc();
			arrayData = new int16_t[arraySize];
			for (int i = 0; i < arraySize - 1; i++) {
				arrayData[i] = bufData[i];
			}
			arrayData[arraySize - 1] = number;
		}
		else {
			throw std::invalid_argument("The number must belong to the interval [-100; 100]\n");
		}
	}


	void addArray(const NumberMassive& nm) {
		int nmSize = nm.arraySize;
		int16_t* nmData = new int16_t[nmSize];
		for (int i = 0; i < nmSize; i++) {
			nmData[i] = nm.arrayData[i];
		}

		for (int i = 0; i < this->arraySize; i++) {
			int16_t addition;
			if (i >= nmSize) addition = 0;
			else addition = nmData[i];
			this->arrayData[i] += addition;
		}

		delete[] nmData;
	}


	void subArray(const NumberMassive& nm) {
		int nmSize = nm.arraySize;
		int16_t* nmData = new int16_t[nmSize];
		for (int i = 0; i < nmSize; i++) {
			nmData[i] = nm.arrayData[i];
		}

		for (int i = 0; i < this->arraySize; i++) {
			int16_t substraction;
			if (i >= nmSize) substraction = 0;
			else substraction = nmData[i];
			this->arrayData[i] -= substraction;
		}

		delete[] nmData;
	}
};


/*		
* 
* Задание 2
* 
*/
template <typename T>
class DataArray {
	T* data;
	int arraySize;
public:
	DataArray(int arraySize, T* data) {
		this->arraySize = arraySize;
		this->data = new T[arraySize];
		for (int i = 0; i < arraySize; i++) this->data[i] = data[i];
	}
	~DataArray() {
		delete[] data;
	}
	T get(int index) {
		return data[index];
	}

	void set(int index, int num) {
		int test;
		if (typeid(data[index]).name() != typeid(test).name()) {	
			return;
		}
		data[index] = num;
	}
};



/*
*
* Задание 3
*
*/

class OutPut
{
	int data;
public:
	
	OutPut(int data)
	{
		this->data = data;
	}
	int get() { return data; }
};

std::ostream& operator<<(std::ostream& stream, OutPut& output)
{
	stream << "Yes?? ";
	stream << output.get();
	return stream;
}

int main()
{
	OutPut asd = 21414;
	cout << asd;

	/* int16_t arr1Size, arr2Size;
	int numOfCom;

	cin >> arr1Size;
	NumberMassive arr1(arr1Size);
	for (int i = 0; i < arr1Size; i++) {
		int16_t num;
		cin >> num;
		arr1.setNum(i, num);
	}

	cin >> arr2Size;
	NumberMassive arr2(arr2Size);
	for (int i = 0; i < arr2Size; i++) {
		int16_t num;
		cin >> num;
		arr2.setNum(i, num);
	}

	cin >> numOfCom;

	for (int i = 0; i < numOfCom; i++) {
		int typeCom, numOfArr;
		cin >> typeCom;
		cin >> numOfArr;

		int elemPos;
		int16_t num;

		switch (typeCom) {

		case 1:
			cin >> elemPos;
			cout << (numOfArr == 1 ? arr1 : arr2).getNum(elemPos) << '\n';
			break;


		case 2:
			cin >> elemPos;
			cin >> num;

			(numOfArr == 1 ? arr1 : arr2).setNum(elemPos, num);
			break;


		case 3:
			cin >> num;
			(numOfArr == 1 ? arr1 : arr2).addNum(num);
			break;


		case 4:
			(numOfArr == 1 ? arr1 : arr2).show();
			break;

		case 5:
			(numOfArr == 1 ? arr1 : arr2).addArray(numOfArr == 1 ? arr2 : arr1);
			break;

		case 6:
			(numOfArr == 1 ? arr1 : arr2).subArray(numOfArr == 1 ? arr2 : arr1);
			break;
		}
	}

	return 0;*/
}