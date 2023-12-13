#include <iostream>
#include <fstream>
#include <string>

int main(){
    
    std::ifstream f("input.txt");
    std::string line;
    std::string nums = "1234567890";

    int sum = 0;

    while (std::getline(f, line))
        sum += (line[line.find_first_of(nums)] - '0') * 10 +
                    (line[line.find_last_of(nums)] - '0');
    

    std::cout << sum; // 55834

}