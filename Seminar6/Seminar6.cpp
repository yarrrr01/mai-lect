#include <iostream>
#include <string>

using namespace std;

template <class T>
class DataArray2 { // с объектами, которые нельзя вывести через cout работать не будет
	T* data;
	int* numOfRequests; // количество запросов для каждого элемента
	int id; //?? размер? предположим, что это размер
	int accessСount = 0;

public:
	DataArray2(T* data, int id) {
		this->id = id;
		this->data = new T[id];
		numOfRequests = new int[id];
		for (int i = 0; i < id; i++) {
			this->data[i] = data[i];
			numOfRequests[i] = 0;
		}
	}
	~DataArray2() {
		delete[] data;
		delete[] numOfRequests;
	}

	void show() { 
		accessСount++;
		for (int i = 0; i < id; i++) cout << numOfRequests[i] << " ";
		cout << "... " << accessСount << " ... ";
		for (int i = 0; i < id; i++) cout << data[i] << " ";
	}

	T get(int id) { // здесь id - это id, а не размер
		T item = data[id];
		numOfRequests[id]++;
		
		sort(id);

		accessСount++;
		return item;
	}

	void sort(int id) {
		for (int i = id; i > 0; i--) {
			if (numOfRequests[i] < numOfRequests[i - 1]) break;
			T item2 = data[i - 1];
			data[i - 1] = data[i];
			data[i] = item2;

			int num = numOfRequests[i - 1];
			numOfRequests[i - 1] = numOfRequests[i];
			numOfRequests[i] = num;
		}
	}
	
};



int main() {
	int id1 = 5;
	int numArr[] = {3, 5, 34, 50, 87, 100};
	DataArray2<int>* arr1 = new DataArray2<int>(numArr, id1);
	char str[] = "weather";
	DataArray2<char>* arr2 = new DataArray2<char>(str, 7);

	while (true) {
		int typeCom, arrNum;

		cin >> typeCom >> arrNum;

		if (typeCom == 0) break;
		else if (typeCom == 1) {
			int id;
			cin >> id;
			if (arrNum == 1) cout << arr1->get(id);			//(arrNum == 1 ? arr1 : arr2)->get(id); не работает
			else cout << arr2->get(id);
			cout << "\n";
		}
		else if (typeCom == 2) {
			if (arrNum == 1) arr1->show();
			else arr2->show();
			cout << "\n";
		}
	}
}
