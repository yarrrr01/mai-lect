#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <string>
#include <cstdlib>
#include <random>

using namespace std;

int rngNum() {
    return rand() % 200 - 100;
};

void taskMap() {
    /* ============================================== */
    /* ================= Задание 1 ================== */
    /* ============================================== */

    map<string, int> mapS;
    string str;
    int words = 1; // слова (пустую строку передавать нельзя) ghj ghj dfdf ghj sdefk ghj dfc

    getline(cin, str);
    for (char c : str) if (c == ' ') words++;
    string* strArr = new string[words];
    for (int i = 0; i < words; i++) strArr[i] = "";
    int i = 0;
    for (char c : str) {
        if (c == ' ') {
            i++;
            continue;
        }
        strArr[i] += c;
    }

    for (int s = 0; s < words; s++) {
        string sa = strArr[s];

        if (mapS.count(sa) == 1) {
            mapS[sa] += 1;
            continue;
        }

        mapS[sa] = 1;
    }
    map <string, int> ::iterator it = mapS.begin();
    for (; it != mapS.end(); it++) {
        cout << it->first << ": " << it->second << '\n';
    }
    delete[] strArr;
    cout << '\n';
};


void taskVector() {
    /* ============================================== */
    /* ================= Задание 2 ================== */
    /* ============================================== */

    srand(4);
    map<int, int> mapS2;

    int v1Size, v2Size;
    double arMean1(0), arMean2(0);
    cin >> v1Size;
    cin >> v2Size;
    vector<int> v1;
    vector<int> v2;
    for (int i = 0; i < v1Size; i++) {
        int m = rngNum();
        v1.push_back(m);
        cout << v1[i] << ' ';
        arMean1 += m;
    }
    arMean1 /= v1.size();
    cout << '\n';
    for (int i = 0; i < v2Size; i++) {
        int m = rngNum();
        v2.push_back(m);
        cout << v2[i] << ' ';
        arMean2 += m;
    }
    arMean2 /= v2.size();
    cout << '\n';

    cout << arMean1 << '\n' << arMean2 << "\n\n";

    for (int i = 0; i < v1Size; i++) {
        for (int j = 0; j < v2Size; j++) {
            if (v1[i] == v2[j]) {
                if (mapS2.count(v1[i]) == 1) {
                    mapS2[v1[i]] += 1;
                    continue;
                }

                mapS2[v1[i]] = 1;
            }
        }
    }
    map <int, int> ::iterator it2 = mapS2.begin();
    for (; it2 != mapS2.end(); it2++) {
        cout << it2->first << " " << it2->second << '\n';
    }
    cout << '\n';
}

void taskStack() {

    /* ============================================== */
    /* ================= Задание 3 ================== */
    /* ============================================== */
    
    int graphSize;
    cin >> graphSize;

    int** table = new int*[graphSize];
    for (int i = 0; i < graphSize; i++) {
        table[i] = new int[graphSize];

        for (int j = 0; j < graphSize; j++) table[i][j] = 0;
    }

    for (int i = 0; i < graphSize; i++) { // считываем входные данные и записываем их в массив
        string s;
        getline(cin, s);
        if (s == "") getline(cin, s);
        int num(0);
        for (int j = 0; j <= s.size(); j++) {
            char c = s[j];
            if (j == 0 && c == '0') break;
            if (c == ' ' || j == s.size()) {
                num--;
                //cout << i << " " << num << '\n';
                table[i][num] = 1;
                num = 0;
            }
            else {
                num = num * 10 + (c - '0');
            }   
        }
    }
    

    // Поиск путей
    stack<int*> stack; // y, x
    int x = 0;
    for (int y = 0; y < graphSize; y++) { // Пробегаем по матрице
        for (; x < graphSize; x++) {
            if (table[y][x] == 1) {
                table[y][x] = 2; // места с двойкой считаются проверенными (нужно, чтобы избежать зацикливания и помогает иногда избежать некоторых ненужных проверок)

                int* a = new int[2];
                a[0] = y; 
                a[1] = x + 1;
                stack.push(a); // сохраняем точку, где остановились и переходим на новый ряд
                y = x;
                x = -1;
                continue;
            }

        }
        if (!stack.empty()) { // Поднимаемся на уровень выше
            int y1 = stack.top()[0];
            for (int i = 0; i < graphSize; i++) if (table[y][i] == 2) table[y1][i] = 2; // Заполняем предудущий ряд в стеке двойками там, где они есть в этом ряду
            y = stack.top()[0] - 1;
            x = stack.top()[1];
            delete[] stack.top();
            stack.pop();
            continue;
        }
        x = 0;
    }
    cout << '\n';
    for (int i = 0; i < graphSize; i++) {
        for (int j = 0; j < graphSize; j++) {
            if (i == j) table[i][j] = 1;
            if (table[i][j] == 2) table[i][j] = 1;
            cout << table[i][j] << " ";
        }
        cout << '\n';
        delete[] table[i];
    }
    delete[] table;

}

int main()
{

    //taskMap();

    //taskVector();

    taskStack();

}
