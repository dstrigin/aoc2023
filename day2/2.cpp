#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int main(){

    int res = 0;

    std::ifstream f("input.txt");
    std::string line;

    while (std::getline(f, line))
    {
        int r_max = 0, g_max = 0, b_max = 0;
        int r = 0, g = 0, b = 0;
    
        std::string token;

        std::istringstream iss(line);
        
        while (iss >> token)
        {
            if (token == "Game")
            {
                iss >> token;
                continue;
            }

            int val = stoi(token);
            iss >> token;
            
            switch (token[0])
            {
            case 'r':
                r = val;
                if (r > r_max)
                    r_max = r;
                break;
            case 'g':
                g = val;
                if (g > g_max)
                    g_max = g;
                break;
            case 'b':
                b = val;
                if (b > b_max)
                    b_max = b;
                break;
            }
        }
        
        res += r_max * g_max * b_max;

    }

    std::cout << res;

}