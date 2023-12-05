#include <iostream>
#include <string>
#include <fstream>
#include <stdint.h>
#include <vector>
#include <cmath>

using namespace std;

int to32int(char bytes[4]) { // Перевод из байтов в числа
    int32_t temp = *(reinterpret_cast<int32_t*>(bytes));
    int32_t result = static_cast<int32_t>(temp);
    return result;
}
vector<int32_t>* readFile(string file) {
    vector<int32_t>* data = new vector<int32_t>;

    ifstream f1;
    f1.open(file, ios::binary);
    if (f1.is_open())
    {
        char bytes[4];
        f1.seekg(10);
        f1.read(bytes, 4);
        int bfOffBits = to32int(bytes);

        f1.seekg(bfOffBits);

        do {
            bytes[0] = bytes[1] = bytes[2] = bytes[3] = 0;

            f1.read(bytes, 3);
            data->push_back(to32int(bytes));
            f1.read(bytes, 1);

        } while (!f1.eof());
            
       
    }
    f1.close();
    return data;
}
int r(int32_t num) {
    return (num & 0xFF0000) >> 16;
}
int g(int32_t num) {
    return (num & 0xFF00) >> 8;
}
int b(int32_t num) {
    return num & 0xFF;
}
int a(int32_t num) { // Прозрачность. Не учитывается
    return ((num & 0xFF000000) >> 24) / 255;
}
double difference(vector<int32_t>* data1, vector<int32_t>* data2) {
    double difference = 0;
    int fSize = data1->size();

    for (int i = 0; i < fSize; i++) {
        int32_t n1 = data1->at(i);
        int32_t n2 = data2->at(i);
        difference += abs(r(n2) - r(n1)) + abs(g(n2) - g(n1)) + abs(b(n2) - b(n1));
    }
    difference /= fSize;

    return difference;
}

int main()
{
    string file1 = "apple_1.bmp";
    string file2 = "apple_2.bmp";
    string file3 = "apple_3.bmp";
    string file4 = "apple_4.bmp";
    vector<int32_t>* data1 = readFile(file1);
    vector<int32_t>* data2 = readFile(file2);
    vector<int32_t>* data3 = readFile(file3);
    vector<int32_t>* data4 = readFile(file4);

    double diff12, diff13, diff14, diff23, diff24, diff34;
    diff12 = difference(data1, data2);
    diff13 = difference(data1, data3);
    diff14 = difference(data1, data4);
    diff23 = difference(data2, data3);
    diff24 = difference(data2, data4);
    diff34 = difference(data3, data4);

    cout << "Difference between 1 and 2: " << diff12 << '\n' << "Difference between 1 and 3: " << diff13 << '\n' 
        << "Difference between 1 and 4: " << diff14 << '\n' << "Difference between 2 and 3: " << diff23 << '\n' 
        << "Difference between 2 and 4: " << diff24 << '\n' << "Difference between 3 and 4: " <<  diff34 << '\n';
}
