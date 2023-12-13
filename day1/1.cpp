#include <iostream>
#include <fstream>
#include <string>

int main(){
    
    std::ifstream f("input.txt");
    std::string line;

    int sum = 0;

    while (std::getline(f, line))
    {
        int num = (line[line.find_first_of("1234567890")] - '0') * 10 +
                    (line[line.find_last_of("1234567890")] - '0');

        sum += num;
    }

    std::cout << sum;

}