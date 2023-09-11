#include <iostream>
#include <string>

int getNumOfVar(std::string name, int vars){
    return name.length() % vars + 1;
}

int main()
{
    std::string fam;
    int vars;
    
    std::cout << "Input surname and after - number of variants\n"; 
    std::cin >> fam;
    std::cin >> vars;
    std::cout << getNumOfVar(fam, vars);
    
    return 0;
}

