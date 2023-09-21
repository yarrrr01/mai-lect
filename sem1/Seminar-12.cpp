#include <iostream>

using std::cout;

class NumberMassive {
	int* arrayData;
	int arraySize;


public:
	NumberMassive(int size) {
		arraySize = size;
		arrayData = new int[arraySize];
	}
	~NumberMassive() {
		delete[] arrayData;
	}
	NumberMassive(const NumberMassive &nm) {
		this->arraySize = nm.arraySize;
		this->arrayData = new int[this->arraySize];
		for (int i = 0; i < this->arraySize; i++) {
			arrayData[i] = nm.arrayData[i];
		}
	}


	void show() {
		for (int i = 0; i < arraySize; i++) {
			cout << arrayData[i] << ' ';
		}
		cout << '\n';
	}


	void setNum(int pos, int number) {
		if (pos >= 0 && pos < arraySize){
			if (number >= -100 && number <= 100) {
				arrayData[pos] = number;
			}
			else {
				cout << "The number must belong to the interval [-100; 100]\n";
			}
		}
		else {
			cout << "Number cannot be set outside the array\n";
		}
	}


	int getNum(int pos){
		if (pos >= 0 && pos < arraySize) {
			return arrayData[pos];
		}
		else {
			cout << "Number cannot be get outside the array\n";
		}
	}


	void addNum(int number) {
		if (number >= -100 && number <= 100) {
			int* bufData = arrayData;

			arraySize++;
			arrayData = new int[arraySize];
			for (int i = 0; i < arraySize - 1; i++) {
				arrayData[i] = bufData[i];
			}
			arrayData[arraySize - 1] = number;
		}
		else {
			cout << "The number must belong to the interval [-100; 100]\n";
		}
	}


	void addArray(const NumberMassive& nm) {
		int nmSize = nm.arraySize;
		int* nmData = new int[nmSize];
		for (int i = 0; i < nmSize; i++) {
			nmData[i] = nm.arrayData[i];
		}

		for (int i = 0; i < this->arraySize; i++) {
			int addition;
			if (i >= nmSize) addition = 0;
			else addition = nmData[i];
			this->arrayData[i] += addition;
		}

		delete[] nmData;
	}


	void subArray(const NumberMassive& nm) {
		int nmSize = nm.arraySize;
		int* nmData = new int[nmSize];
		for (int i = 0; i < nmSize; i++) {
			nmData[i] = nm.arrayData[i];
		}

		for (int i = 0; i < this->arraySize; i++) {
			int substraction;
			if (i >= nmSize) substraction = 0;
			else substraction = nmData[i];
			this->arrayData[i] -= substraction;
		}

		delete[] nmData;
	}
};
int main()
{
	/*NumberMassive numB(3);
	numB.show();
	numB.setNum(0, 5);
	cout << numB.getNum(0) << '\n';

	numB.setNum(12, 10);
	numB.setNum(1, 123);
	numB.getNum(-2);

	numB.show();
	numB.setNum(1, 15);

	NumberMassive numB2(numB);

	numB.setNum(2, -44);
	numB.show();
	numB2.show();

	cout << "===========\n";
	numB.addNum(3);
	numB.addNum(100);
	numB.addNum(1243);
	numB.show();
	numB2.show();

	NumberMassive numB3(4);
	for (int i = 0; i < 4; i++) {
		numB3.setNum(i, 1);
	}
	NumberMassive numBnull(0);
	numB3.show();
	numB3.subArray(numBnull);
	numB3.show();

	NumberMassive numB4(3);
	for (int i = 0; i < 3; i++) {
		numB4.setNum(i, 1);
	}
	numB3.show();
	numB3.subArray(numB4);
	numB3.show();
	*/


	return 0;
}