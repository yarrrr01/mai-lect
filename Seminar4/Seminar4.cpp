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
}

int main()
{
    
    /* ============================================== */
    /* ================= Задание 1 ================== */
    /* ============================================== */

    /*map<string, int> mapS;
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
    cout << '\n'; // проверено
    */

    /* ============================================== */
    /* ================= Задание 2 ================== */
    /* ============================================== */

    srand(1);

    int v1Size, v2Size;
    double arMean1(0), arMean2(0);
    cin >> v1Size >> v2Size;
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

    cout << arMean1 << '\n' << arMean2 << '\n';

    /* ============================================== */
    /* ================= Задание 3 ================== */
    /* ============================================== */
}
