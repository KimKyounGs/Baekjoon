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

struct Point {
    int x,y,n;
};

int N, M;
int result = INF;
int graph[51][51];
vector<pair<int, int>> v;
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

void BFS() {
    deque<Point> dq;
    for (int i = 0; i < M; i ++) {
        dq.push_back({v[i].first, v[i].second, 3});
        graph[v[i].first][v[i].second] = 3;
    }

    while(!dq.empty()) {
        int x = dq.front().x;
        int y = dq.front().y;
        dq.pop_front();
        for (int i = 0; i < 4; i ++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= N ) continue;

            if (graph[nx][ny] == 0) {
                dq.push_back({nx,ny,graph[x][y] + 1});
                graph[nx][ny] = graph[x][y] + 1; 
            }
        }
    }
}

void DFS(int cnt, int idx, int idx2) {
    if (cnt == M) {
        int temp[51][51];
        copy(&graph[0][0], &graph[0][0]+51*51, &temp[0][0]);

        BFS();
        
        bool check = false;
        for (int i = 0; i < N; i ++) {
            for (int j = 0; j < N; j ++) {
                if (graph[i][j] == 0) {
                    check = true;
                }
            }
        }

        int maxs = 0;
        if (!check) {
            for (int i = 0; i < N; i ++) {
                for (int j = 0; j < N; j ++) {
                    if (graph[i][j] >= 4) {
                        maxs = max(maxs, graph[i][j] - 3);
                    }
                }
            }
            result = min(result, maxs);
        }
        
        copy(&temp[0][0], &temp[0][0]+51*51, &graph[0][0]);
        
        return;
    }
    
    for (int i = idx; i < N; i ++, idx2 = 0) {
        for (int j = idx2; j < N; j ++) {
            if (graph[i][j] == 2) {
                v.push_back({i,j});
                DFS(cnt + 1, i, j);
                v.pop_back();
            }
        }
    }
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < N; j ++) {
            cin >> graph[i][j];
        }
    }

    DFS(0, 0, 0);

    if (result == INF) {
        cout << -1 << '\n';
    }
    else {
        cout << result << endl;
    }
}


