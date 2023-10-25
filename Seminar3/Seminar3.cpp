#include <iostream>
#include <cmath>
#include <map>
#include <random>
#include <ctime>


using namespace std;

uint32_t hashCode(string str) {

    int group, numOfSym;
    uint32_t hashCode;
    hashCode = 0;
 
    for (int i = 0; i < str.length(); i++) {
        char sym = str[i];
        

        if (sym <= 56) {
            group = 1;
            numOfSym = sym % 48;
        }
        else if (sym <= 104) {
            group = 2;
            numOfSym = (sym == 57 ? 0 : sym % 97 + 1);
        }
        else if (sym <= 113) {
            group = 3;
            numOfSym = sym % 105;
        } else {
            group = 4;
            numOfSym = sym % 114;
        }
        //numOfSym *= 8;
        numOfSym += i * 10;
        numOfSym += 115; //115

        hashCode += std::pow(numOfSym, group);
    }
    return hashCode;
}
char defineSym(int i) {
    char s;
    if (i < 10) {
        s = (char)(i + 48);
    }
    else {
        s = (char)(i + 87);
    }

    return s;
}
string stringGen(int len) {
    string str = "";

    for (int i = 0; i < len; i++) {
        int rng = rand() % 36;
        char let = defineSym(rng);
        
        str += let;
    }
    return str;
}


int main() {
    std::srand(34633); // 999, 899, 500, 12345, 0, 100000, 13, 2345, 34633  - это надо, чтобы генерировать при запуске генерировались одни и те же случайные числа
    string str;
    const int TOTAL_NUMBER_OF_STRINGS = 13600;
    string strArr[TOTAL_NUMBER_OF_STRINGS];
    int hashArr[TOTAL_NUMBER_OF_STRINGS];
    int timeToCompareStrings(0), timeToCompareHashCodes(0), numOfSimilarStr(0), numOfSimilarHashCodes(0);
    
    for (int z = 3; z <= 7; z++) {
        for (int i = 0; i < 10000; i++) { // генерация 10000 строк
            str = stringGen(z);
            strArr[i] = str;
            hashArr[i] = hashCode(str);
        }

        for (int i = 0; i < 100; i++) { // генерация 100 наборов строк с 36 строками
            str = stringGen(z);
            int idS = rand() % z;
            for (int j = 0; j < 36; j++) {
                str[idS] = defineSym(j);
                strArr[10000 + 36*i + j] = str;
                hashArr[10000 + 36*i + j] = hashCode(str);
            }
        }

        int startTime = clock();
        for (int i = 0; i < TOTAL_NUMBER_OF_STRINGS; i++) {
            for (int j = i+1; j < TOTAL_NUMBER_OF_STRINGS; j++) {
                if (strArr[i] == strArr[j]) numOfSimilarStr++;
            }
        }
        timeToCompareStrings = clock() - startTime;
        // ====
        startTime = clock();
        for (int i = 0; i < TOTAL_NUMBER_OF_STRINGS; i++) {
            for (int j = i + 1; j < TOTAL_NUMBER_OF_STRINGS; j++) {
                if (hashArr[i] == hashArr[j]) numOfSimilarHashCodes++;
            }
        }
        timeToCompareHashCodes = clock() - startTime;

        cout << "Number of collision for strings of length " << z << ":  " << numOfSimilarHashCodes - numOfSimilarStr << '\n'
            << "Time to comparing strings: " << timeToCompareStrings << '\n'
            << "Time to comparing hash codes: " << timeToCompareHashCodes << '\n' // кол-во коллизий / время сравнения строк / время сравнения чисел
            << "=============================================\n";

        numOfSimilarHashCodes = 0;
        numOfSimilarStr = 0;
    }
}
