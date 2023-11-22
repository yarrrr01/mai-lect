#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Circuit {

	string name;
	int	length, width, height; 
	float weight;

	Circuit(string name, int len, int wid, int hei, int wei) {
		this->name = name;
		length = len;
		this->width = wid;
		height = hei;
		this->weight = wei;
	}
	Circuit() {
		name = "";
		length = 0;
		width = 0;
		height = 0;
		weight = 0;
	}
};
std::ostream& operator<<(std::ostream& stream, const Circuit& cir) {
	stream << cir.name << " " << cir.length << " " << cir.width << " " << cir.height << " " << cir.weight << "\n";
	return stream;
}


Circuit* circuitArr; // Массив с элементами
int numOfCir; // Размер массива с элементами
// Команды
void cHelp() { // Теперь не нужно, зря писал
	cout << "------------------------------------------------------------------\n"
		<< "Программа может обрабатывать следующие команды:\n"
		<< "0 - Выход из программы\n"
		<< "1 - Вызов списка команд\n"
		<< "2 - Вывод полного списка элементов\n"
		<< "3 - Вывод списка элементов с фильтрами\n"
		<< "4 [параметр] [оператор сравнения] [число] - из списка с фильтрами удаляются все элементы, не соответствующие введённым параметрам.\n"
		<< "\tВозможные операторы сравнения: >, >=, <, <=, =\n"
		<< "\tВозможные параметры: res, trans, diod, capac, led\n"
		<< "\tПример: 4 diod < 5\n"
		<< "5 - Сброс фильтров\n"
		<< "------------------------------------------------------------------\n";
}

void cShow() {
	int size = numOfCir;
	cout << "Список всех элементов: резисторы, транзисторы, диоды, кондесаторы, светодиоды\n";
	if (size == 0) {
		cout << "Пусто\n";
		return;
	}
	for (int i = 0; i < size; i++) cout << i + 1 << ") " << circuitArr[i];
}

void cShowFilt(vector<Circuit>& filtCir) {
	int size = filtCir.size();
	//cout << "Отфильтрованный список: резисторы, транзисторы, диоды, кондесаторы, светодиоды\n";
	if (size == 0) {
		cout << "empty\n";
		return;
	}
	for (int i = 0; i < size; i++) cout << filtCir[i];
}

void cFilt(vector<Circuit>& filtCir) {
	int typeOfElem;
	string operatorComp;
	string str;
	cin >> typeOfElem >> operatorComp >> str;
	

	vector<string> dataStr;
	vector<float> dataF;

	for (int i = 0; i < filtCir.size(); i++) {  // Заполнения вектора числами, равными числам, обозначающими выбранный параметр
		if (typeOfElem == 1) dataStr.push_back(filtCir[i].name);
		else if (typeOfElem == 2) dataF.push_back(filtCir[i].length);
		else if (typeOfElem == 3) dataF.push_back(filtCir[i].width);
		else if (typeOfElem == 4) dataF.push_back(filtCir[i].height);
		else if (typeOfElem == 5) dataF.push_back(filtCir[i].weight);
		else {
			cout << "Неверный параметр объекта\n";
			return;
		}
	}

	float number = 0;
	if (!dataF.empty()) number = stoi(str); // stoi() преобразует строку в число

	if (operatorComp == "=" || operatorComp == "<" || operatorComp == ">") {
		for (int i = 0; i < filtCir.size(); i++) {
			if (!dataF.empty()) {// Сравнение чисел
				if (operatorComp == ">") if (dataF[i] > number) dataF[i] = 1; else dataF[i] = 0;
				else if (operatorComp == "<") if (dataF[i] < number) dataF[i] = 1; else dataF[i] = 0;
				else if (operatorComp == "=") if (dataF[i] == number) dataF[i] = 1; else dataF[i] = 0;
			}
			else {
				if (dataStr[i] != str) dataStr[i] = "";
			}
		}
	}
		else {
			cout << "Нет такого оператора сравнения\n";
			return;
		}
	vector<Circuit>::iterator it = filtCir.begin();
	for (int i(0), j(0); i < filtCir.size(); i++, j++) { //  Удаление неподходящих позиций в векторе
		if (!dataF.empty() && dataF[j] == 0 || !dataStr.empty() && dataStr[j] == "") {
			filtCir.erase(it);
			it = filtCir.begin() + i; // Устранение непонятной проблемы
			i--;
			continue;
		}
		if (it != filtCir.end()) it++;
	}
}

void cReset(vector<Circuit>& filtCir) {
	filtCir.clear();
	for (int i = 0; i < numOfCir; i++) filtCir.push_back(circuitArr[i]);
}

int main() {
	setlocale(LC_ALL,"Russian");
	
	string line;

	cin >> numOfCir;

	circuitArr = new Circuit[numOfCir]; 

		for (int i = 0; i < numOfCir; i++) {
			cin >> circuitArr[i].name;
			cin >> circuitArr[i].length;
			cin >> circuitArr[i].width;
			cin >> circuitArr[i].height;
			cin >> circuitArr[i].weight;
		}

	

	// Обработка команд пользователя
	//cHelp();
	int com, numOfCom;
	cin >> numOfCom;
	vector<Circuit> filtCir;
	cReset(filtCir);
	for (int i = 0; i < numOfCom; i++) {
		//cout << "Введите номер команды ";
		cin >> com;
		if (com == 1) cFilt(filtCir);
		else if (com == 2) cShowFilt(filtCir);
		else if (com == 3) cReset(filtCir);
		else cout << "Такой команды не существует, повторите ввод\n";
	}

	delete[] circuitArr;

}
