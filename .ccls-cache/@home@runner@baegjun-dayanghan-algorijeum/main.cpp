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

int N, M;
int result;
int graph[9][9];
int visit[9][9];
vector<pair<int, int>> v;
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

void BFS(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x,y});
    visit[x][y] = true;

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i ++) {
            int nx = x + dx[i];
            int ny = y + dy[i];    

            if (nx < 0 || nx >= N || ny < 0 || ny >= M || visit[nx][ny]) continue;

            if (graph[nx][ny] == 0) {
                q.push({nx,ny});
                graph[nx][ny] = 2;
                visit[nx][ny] = true;
            }
        }
    }
}

void DFS(int cnt) {
    if (cnt == 3) {
        int temp[9][9];
        int sum = 0;
        int len = v.size();

        copy(&graph[0][0], &graph[0][0]+81, &temp[0][0]);

        for (int i = 0; i < len; i ++) {
            BFS(v[i].first, v[i].second);
        }

        for (int i = 0; i < N; i ++) {
            for (int j = 0; j < M; j ++) {
                if (graph[i][j] == 0) {
                    sum ++;
                }
            }
        }


        result = max(sum, result);
        copy(&temp[0][0], &temp[0][0]+81, &graph[0][0]);
        memset(visit, 0, sizeof(visit));
        return;
    }

    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < M; j ++) {
            if (graph[i][j] == 0) {
                graph[i][j] = 1;
                DFS(cnt + 1);
                graph[i][j] = 0;
            }
        }
    }
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < M; j ++) {
            cin >> graph[i][j];
            if (graph[i][j] == 2) {
                v.push_back({i,j});
            }
        }
    }

    DFS(0);

    cout << result << endl;
}


