#include <iostream>
#include <vector>
#include <cstring>

int explore(int cur, int i);

std::vector<int> Station[100 + 5]; 
int P[100 + 5][100 + 5] = {0, };
int visited[100 + 5] = {0, };

int current = 0;

int main()  {
    int N, answer = 10000;
    bool flag;
    
    std::cin >> N;

    for(int i = 1; i < N; ++i) {
        int a, b;

        std::cin >> a >> b;

        Station[a].push_back(b);
    }

    for(int i = 1; i <= N; ++i)    {
        memset(visited, 0, sizeof(visited));
        current = i;
        explore(current, i);
    }

    for(int i = 1; i <= N; ++i) {
        flag = true;
        for(int j = 1; j <= N; ++j) {
            if(!P[j][i])    {
                flag = false;
                break;
            }
        }

        if(flag)  {
            answer = (answer < i)? answer: i;
        }
    }

    if(answer > 100)    {
        answer = -1;
    }

    std::cout << answer << "\n";

    return 0;
}

int explore(int cur, int i)  {
    visited[i] = 1;

    P[cur][i] = 1;

    for(int j : Station[i]) {
        if(visited[j])  {
            continue;
        }

        explore(cur, j);
    }

    return 0;
}