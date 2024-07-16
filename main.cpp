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

int N, M;
int result = 0;
int rainbowBlockCnt = 0;
int graph[21][21];
bool visited[21][21];
vector<pair<int, vector<pair<int, int>>>> blockCoords; // 탐색한 블록들의 좌표를 담을 공간
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

vector<pair<int, int>> BFS(int x, int y, int id) {
    vector<pair<int, int>> v;
    v.push_back({x,y});
    queue<pair<int, int>> q;
    q.push({x,y});
    visited[x][y] = true;

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i ++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx > N-1 || ny > N-1 || visited[nx][ny]) continue;
            if (graph[nx][ny] == id || graph[nx][ny] == 0) {
                if (graph[nx][ny] == 0) rainbowBlockCnt ++;
                v.push_back({nx,ny});
                visited[nx][ny] = true;
            }
        }
    }
    return v;
}

void FindBlock() {
    int ID = 1;
    for (int k = 1; k <= M; k ++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j ++) {
                if (!visited[i][j] && graph[i][j] == k) {
                    rainbowBlockCnt = 0;
                    vector<pair<int, int>> temp = BFS(i, j, k);
                    if (temp.size() != 1) {
                        blockCoords.push_back({rainbowBlockCnt, temp});
                    }
                }
            }
        }
        memset(visited, 0, sizeof(visited));
    }
}

void RemoveBlock() {
    sort(blockCoords.begin(), blockCoords.end(), greater<pair<int, pair<int, int>>>());
    for(int i = 0; i < blockCoords[0].second.size(); i ++) {
        int x = blockCoords[0].second[i].first;
        int y = blockCoords[0].second[i].second;
        graph[x][y] = -2;
    }
}

void ApplyGravity() {
    for (int i = N-1; i > N; i ++) {
        
    }
}

void Rotate() {
    
}

void Simulation() {
    FindBlock();    
    RemoveBlock();
    ApplyGravity();
    Rotate();
    ApplyGravity();
}

int main()
{   
    cin >> N >> M;
    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < N; j ++) {
            cin >> graph[i][j];
        }
    }
    while(true) {
        Simulation();
    }
}