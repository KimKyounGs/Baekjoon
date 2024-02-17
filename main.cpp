/*
아이디어 :

N,M의 크기도 작고 벽도 3개까지만 만드는 것을 보고 백트래킹으로 풀 수 있다고 생각했고, 
감염되는 것을 보고 그래프문제인 것을 알 수 있었다.

*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>
#include <deque>
#include <map>
#define INF 1e9
#define endl '\n'

using namespace std;

vector<int> v;
int graph[42];
vector<int> horse;
bool bHorse[4];
int result;

int Simulation() {
    int sum = 0;
    for (int i = 0; i < 10; i ++) {
        int n = horse[i];
        
    }

    return sum;
}

void DFS(int cnt) {
    if (cnt == 10) {
        int value = Simulation();
        return;
    }

    for (int i = 0; i < 4; i ++) {
        horse.push_back(i);
        DFS(cnt + 1);
        horse.pop_back();
    }
}

int main()
{
    for (int i = 0; i < 10; i ++) {
        int n;
        cin >> n;
        v.push_back(n);
    }
    
    DFS(0);
}


