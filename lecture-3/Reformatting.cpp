#include "Reformatting.h";

#include <fstream>
#include <string>

Reformatting::Reformatting(std::string fileName)
    {
        this->fileName = fileName;
    }

void Reformatting::reformat() {
    std::string newFileName = fileName; // Имя нового файла
    std::string gift{".gift"};
    int nameSize = fileName.length();
    newFileName.std::string::erase(nameSize - 4, 4);
    newFileName += gift;


    std::ofstream newFile{ newFileName };
    std::string line;
    char lastSymbol = ' ';
    bool isBracketOpen = false;

    std::ifstream in(fileName);
    if (in.is_open())
    {
        while (std::getline(in, line))
        {
            for (char el : line) {
                /*
                * 1. Проверяем на символ: любую цифру при открытой фигурной скобке после переноса строки, чтобы перед цифрой закрыть фигурную скобку и записываем её (конец вопроса)
                * 2. Проверяем на символы - или + (при открытой фигурной скобке), чтобы заменить их
                * 3. Записываем в файл новый символ
                * 4. Проверяем на символ ?, чтобы после него открыть фигурную скобку
                */
                if (isBracketOpen && lastSymbol == '\n' && ((el - '0') > 0 && (el - '0') <= 9)) {
                    newFile << "}\n";
                    isBracketOpen = false;
                }

                if (isBracketOpen) {
                    if (el == '+') {
                        el = '=';
                    }
                    else if (el == '-') {
                        el = '~';
                    }
                }

                newFile << el;

                if (el == '?' && !isBracketOpen) {
                    newFile << " {";
                    el = '{'; // Для lastSymbol
                    isBracketOpen = true;
                }

                lastSymbol = el;
            }
            if (lastSymbol == '\n' && isBracketOpen) { newFile << '}'; isBracketOpen = false; } // Дополнительная проверка на наличие пустых строк после вопроса
            lastSymbol = '\n';
            newFile << lastSymbol;
        }
        newFile << "}";
    }
    in.close();

};
