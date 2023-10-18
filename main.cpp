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
#define INF 1e9

using namespace std;

int N, M, K;
int graph[51][51];
vector<pair<pair<int, int>, int>> v;
bool visited[9];

void Rotate(int idx, bool flag) {
    int startX = (v[idx].first.first - v[idx].second)-1;
    int startY = (v[idx].first.second - v[idx].second)-1;
    int endX = (v[idx].first.first + v[idx].second)-1;
    int endY = (v[idx].first.second + v[idx].second)-1;

    for (int i = startX; i <= endX; i ++) {
        for (int j = startY; i <= endY; i ++) {
            
        }
    }
}

void DFS(int cnt) {
    if (cnt == K) {
        
        
        return;
    }

    for (int i = 0; i < K; i ++) {
        if (!visited[i]) {
            visited[i] = true;
            Rotate(i, true);
            DFS(cnt + 1);
            visited[i] = false;
            Rotate(i, false);
        }
    }
}

int main() { 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> K;
    
    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < M; j++) {
            cin >> graph[i][j];
        }
    }

    for (int i = 0; i < K; i ++) {
        int r, c, s;
        cin >> r >> c >> s;
        v.push_back({{r,c},s});
    }
}