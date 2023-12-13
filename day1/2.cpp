#include <iostream>
#include <fstream>
#include <string>
#include <map>

int main(){

    int sum = 0;

    std::map<std::string, int> nums {
        {"one", 1},
        {"two", 2},
        {"three", 3},
        {"four", 4},
        {"five", 5},
        {"six", 6},
        {"seven", 7},
        {"eight", 8},
        {"nine", 9}
    };

    std::ifstream f("input.txt");
    std::string line;

    while (std::getline(f, line))
    {
        bool first = true;

        int last = 0;

        for (int i = 0; i < line.size(); i++)
        {
            if (isdigit(line[i])) 
            {
                if (first)
                {
                    sum += (line[i] - '0') * 10;
                    first = false;
                }

                last = line[i] - '0';
            }
            else 
            {
                int num = 0;
                
                for (auto [k, v] : nums)
                    if (line.substr(i, k.size()) == k)
                    {
                        num = v;
                        break;
                    }

                if (num == 0) continue;

                if (first) 
                {
                    sum += num * 10;
                    first = false;
                }
                last = num;
            }   
        }
        sum += last;
    }
    
    std::cout << sum; // 53221

}