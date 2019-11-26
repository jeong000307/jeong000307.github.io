#include <iostream>
#include <cstdlib>
#include <utility>

int main()  {
    std::pair<int, int> barn, lake, rock;
    int DistBL, DistBR, DistRL;

    for(int i = 1; i <= 10; ++i)    {
        for(int j = 1; j <= 10; ++j)    {
            char temp;
            
            std::cin >> temp;

            switch(temp)  {
                case 'B' : barn = std::make_pair(i, j); break;
                case 'L' : lake = std::make_pair(i, j); break;
                case 'R' : rock = std::make_pair(i, j); break;
            }
        }
    }

    DistBL = abs(barn.first - lake.first) + abs(barn.second - lake.second);
    DistBR = abs(barn.first - rock.first) + abs(barn.second - rock.second);
    DistRL = abs(rock.first - lake.first) + abs(rock.second - lake.second);

    if((barn.first == lake.first || barn.second == lake.second) && DistBL == DistBR + DistRL)    {
        std::cout << DistBL + 1 << "\n";
    }
    else {
        std::cout << DistBL - 1 << "\n";
    }

    return 0;
}