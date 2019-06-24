---
layout: default
title : A. Bucket Brigade
---

Category : Math, Implement

Keyword : Manhattan distance

 이 문제는 맨하튼 거리를 이용해 쉽게 풀 수 있는 문제이다. 다만 호수와 헛간 사이에 바위가 있다는 점에 유의하여 풀어야 하는데, 필자는 이를 '호수와 바위, 헛간이 모두 일직선 상에 위치하면서 호수와 바위까지의 거리와 헛간과 바위까지의 거리의 합이 호수와 헛간까지의 거리와 같다면 호수와 헛간 사이에 바위가 있다'로 변형하여 풀어냈다. 왜냐하면, 호수와 헛간 사이에 바위가 있기 위해서는 무조건 셋 다 일직선 상에 있어야 하기 때문이다. 또한, 호수와 헛간 사이에 바위가 없다면 호수와 바위까지의 거리와 헛간과 바위까지의 거리의 합이 호수와 헛간까지의 거리와 같지 않기 때문이다. (겹치는 경로가 존재하게 되어 거리가 더 커진다.)

 또한, 이 문제는 BFS를 통해서도 풀 수 있다. 다만 이 방법은 자세히 소개하지 않도록 하겠다.

 아래는 코드이다.

~~~ c++
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
~~~
