/*
아이디어 : 처음 외벽을 조사할 때 들어갈 수 있는지 확인한다.

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

int N, K;
int graph[500001];
int brother[500001];
bool bResult = false;

int Cal(int num)
{
    return K+((num*(1+num))/2);
}

void BFS(int x)
{
    queue<int> q;
    q.push({x});
    graph[x] = 0;

    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        // 동생을 찾음
        if (x == Cal(graph[x]))
        {
            bResult = true;
            cout << graph[x] << endl;
            return;
        }

        // 곱하기
        if (2*x <= 500000 || graph[2*x] == -1)
        {
            graph[2*x] = graph[x]+1;
            q.push(2*x);
            cout << "곱하기 " << 2*x << endl;
        }
        // 더하기
        if (x+1 <= 500000 || graph[x+1] == -1) 
        {
            graph[x+1] = graph[x]+1;
            q.push(x+1);
            cout << "더하기 " << x+1 << endl;
        }
        // 빼기
        if (x-1 >= 0 || graph[x-1] == -1)
        {
            graph[x-1] = graph[x]+1;
            q.push(x-1);
            cout << "빼기 " << x-1 << endl;
        }
    }
}

int main()
{
    cin >> N >> K;
    if (N == K) 
    {
        cout << 0 << endl;
        return 0;
    }

    memset(graph, -1, sizeof(graph));
    BFS(N);
    if (!bResult)
    {
        cout << -1 << endl;
    }
}