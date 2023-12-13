#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int main(){
    
    int r_max = 12, g_max = 13, b_max = 14;

    int res = 0;

    std::ifstream f("input.txt");
    std::string line;

    while (std::getline(f, line))
    {
        int id = 0, r = 0, g = 0, b = 0;
        bool possible = true;

        std::string token;

        std::istringstream iss(line);
        
        while (iss >> token)
        {
            if (token == "Game")
            {
                iss >> token;
                id = stoi(token);
                //std::cout << id << "\n";
                continue;
            }

            int val = stoi(token);
            iss >> token;
            
            switch (token[0])
            {
            case 'r':
                if (val > r_max) possible = false;
                break;
            case 'g':
                if (val > g_max) possible = false;
                break;
            case 'b':
                if (val > b_max) possible = false;
                break;
            }
        }

        if (possible) res += id;

    }

    std::cout << res;

}