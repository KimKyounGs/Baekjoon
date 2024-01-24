/*
아이디어 :



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

int N, M, K;
bool graph[31][11];

int main()
{
    cin >> N >> M >> K;

    for (int i = 0; i < M; i ++) {
        int a, b;
        cin >> a >> b;
        graph[b][a] = true;
    }

    
}


