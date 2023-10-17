#include <iostream>
#include <cmath>
#include <map>
#include <random>

using std::string;
using std::cout;

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



std::map<string, uint32_t> mapS;
std::map<uint32_t, string> mapReversed;
int main() {
    std::srand(999); // 999, 899, 500, 12345, 0, 100000, 13, 2345, 34633
    string s;
    
    for (int z = 3; z <= 7; z++) {
        for (int i = 0; i < 10000; i++) {
            s = stringGen(z);
            mapS[s] = hashCode(s);
        }

        for (int i = 0; i < 100; i++) {
            s = stringGen(z);
            mapS[s] = hashCode(s);
            int idS = rand() % z;
            for (int j = 0; j < 36; j++) {
                s[idS] = defineSym(j);
                mapS[s] = hashCode(s);
            }
        }
        std::map <string, uint32_t> ::iterator it = mapS.begin();
        for (int i = 0; it != mapS.end(); it++, i++) {
            mapReversed[it->second] = it->first;
        }
        cout << "Number of collision for strings of length " << z << ":  " << mapS.size() - mapReversed.size() << '\n'; // кол-во коллизий
        //cout << mapS.size() - mapReversed.size() << '\n';
        mapS.clear();
        mapReversed.clear();
    }
}
