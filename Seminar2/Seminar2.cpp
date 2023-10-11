#include <iostream>
#include <typeinfo>
#include <cmath>

using std::cout;
using std::cin;
/*
* 
* Задание 2
* 	
*/
class NumberMassive { 

	int16_t* arrayData;
	int16_t arraySize;


public:
	NumberMassive(int16_t size) {
		arraySize = size;
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

	int16_t getSize() {
		return arraySize;
	}

};
std::ostream& operator<<(std::ostream& stream, NumberMassive& numMas)
{
	for (int i = 0; i < numMas.getSize(); i++) {
		stream << numMas.getNum(i) << " ";
	}
	return stream;
}

/*		
* 
* Задание 1
* 
*/
template <typename T>
class DataArray {
	T* data;
	int arraySize;
public:
	DataArray(T* data, int arraySize) {
		
		this->arraySize = arraySize;
		this->data = new T[this->arraySize];
		for (int i = 0; i < this->arraySize; i++) this->data[i] = data[i];
	}
	~DataArray() {
		delete[] data;
	}
	T get(int index) {
		return data[index];
	}
	bool isItNum() {
		if constexpr (std::is_integral_v<T>) return true;
		else return false;
	}
	bool isItFloat() {
		if constexpr (std::is_floating_point_v<T>) return true;
		else return false;
	}

	void set(int index, int num) {

		if (!isItNum()) return;
		if (num > 100 || num < -100) return;

		data[index] = num;
	}

	/*
	*
	* Задание 3
	*
	*/

	double vectorLength(DataArray& DA) {
		return 3;
		if ((!isItNum() && !isItFloat()) || (!DA.isItNum() && !DA.isItFloat())) throw std::bad_typeid();
		if (arraySize != DA.arraySize) throw std::invalid_argument("invalid_argument");
		
		double length = 0;
		for (int i = 0; i < arraySize; i++) length += std::pow(data[i] - DA.data[i], 2);
		return std::sqrt(length);
	}

	
};






int main()
{
	std::string str[] = {"asfdsf", "dfdsf", "sdfdesf"};
	int num[] = { 2, 34, 54 };
	DataArray<std::string>* da = new DataArray<std::string>(str, sizeof(str) / sizeof(std::string));
	DataArray<int>* da2 = new DataArray<int>(num, 3);
	da2->set(0, 99);
	da->set(2, 23);

	for (int i = 0; i < 3; i++) {
		cout << da->get(i) << " ";
	} 
	for (int i = 0; i < 3; i++) {
		cout << da2->get(i) << " ";
	} // Для задания с шаблонным классом ..............................
	cout << '\n';
	try {
		int num1[] = { 0,0 };
		int num2[] = { 2,2,213 };
		DataArray<int>* A = new DataArray<int>(num1, 2);
		DataArray<int>* B = new DataArray<int>(num2, 2);
		cout << da->vectorLength(*da);
	}
	catch (std::bad_typeid e) {
		cout << "std::bad_typeid\n";
	}
	catch (std::invalid_argument e) {
		cout << "std::invalid_argument\n";
	}

	int16_t arr1Size, arr2Size; 
	int numOfCom;
	NumberMassive* arr1;
	NumberMassive* arr2;
	try {
		cin >> arr1Size;
		arr1 = new NumberMassive(arr1Size);
		for (int i = 0; i < arr1Size; i++) {
			int16_t num;
			cin >> num;
			arr1->setNum(i, num);
		}

		cin >> arr2Size;
		arr2 = new NumberMassive(arr2Size);
		for (int i = 0; i < arr2Size; i++) {
			int16_t num;
			cin >> num;
			arr2->setNum(i, num);
		}
	} catch (...) {
		cout << "std::bad_alloc\n";
		return 0;
	}

	cout << *arr1 << "\n" << *arr2; // Для задания с переопределением оператора   ................

		cin >> numOfCom;

		for (int i = 0; i < numOfCom; i++) {
			int typeCom, numOfArr;
			cin >> typeCom;
			cin >> numOfArr;

			int elemPos;
			int16_t num;
			try {
				switch (typeCom) {

				case 1:
					cin >> elemPos;
					cout << (numOfArr == 1 ? arr1 : arr2)->getNum(elemPos) << '\n';
					break;


				case 2:
					cin >> elemPos;
					cin >> num;

					(numOfArr == 1 ? arr1 : arr2)->setNum(elemPos, num);
					break;


				case 3:
					cin >> num;
					(numOfArr == 1 ? arr1 : arr2)->addNum(num);
					break;


				case 4:
					(numOfArr == 1 ? arr1 : arr2)->show();
					break;

				case 5:
					(numOfArr == 1 ? arr1 : arr2)->addArray(numOfArr == 1 ? *arr2 : *arr1);
					break;

				case 6:
					(numOfArr == 1 ? arr1 : arr2)->subArray(numOfArr == 1 ? *arr2 : *arr1);
					break;
				}
			}
			catch (std::invalid_argument& e) {
				cout << "std::invalid_argument\n";
				continue;
			}
			catch (std::range_error& e) {
				cout << "std::range_error\n";
				continue;
			}
			catch (...) {
				cout << "std::bad_alloc\n";
				return 0;
			}
		}

		return 0;
}
