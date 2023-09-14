#include <iostream>
class FooString {
	char* buf;
public:
	FooString(char* tbuf) {
		buf = tbuf;
	};
	~FooString() {
	};
	void show() {
		std::cout << buf << '\n';
	};

	int lenght() {
		int len = 0;
		while (buf[len] != '\0') {
			len += 1;
		}
		return len;
	};
	char* getStr() { // Вспомогательный метод
		return buf;
	}
};

int main() {
	FooString str[] = { "Hello", "", "123456789The lenght of this string is 40" };
	std::cout << "\"FooString\" - lenght of this FooString\n";
	for (int i = 0; i < 3; i++) {
		std::cout << '\"' << str[i].getStr() << "\" - " << str[i].lenght() << '\n';
	}

	return 0;
}