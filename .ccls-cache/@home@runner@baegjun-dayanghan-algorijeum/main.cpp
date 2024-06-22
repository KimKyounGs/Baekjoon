/*
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

int n;
vector<pair<int,int>> graph[10001];
bool visited[10001];
int result = 0;

void DFS(int x, int sum) {
    // cout << "Debug = " << x << endl;
    result = max(result, sum);
    visited[x] = true;
    
    for (int i = 0; i < graph[x].size(); i ++) {
        int nx = graph[x][i].first;
        int weight = graph[x][i].second;

        if (!visited[nx]) {
            DFS(nx, sum + weight);
        }
    }
}

int main()
{   
    cin >> n;
    for (int i = 0; i < n-1; i ++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }

    for (int i = 1; i <= n; i ++) {
        DFS(i, 0);
        memset(visited, 0, sizeof(visited));
    }

    cout << result << endl;
}