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

int N, k;
int graph[51][51];
int result = INF;
// 동 = 0, 남 = 1, 서 = 2, 북 = 3
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
// 0번 타일은 차 방향이 3(북)일 때 1(동)으로 바뀌고 혹인 서(2)일 때 1(남)으로 바뀜
pair<pair<int, int>, pair<int, int>> tileDir[] = { {{3,0},{2,1}}, {{0,1},{3,2}}, {{1,0},{2,3}}, {{0,3},{1,2}}, {{1,1},{3,3}}, {{0,0},{2,2}} };

void Simulation() {
    int distance = 1;
    int carX = 0, carY = 0, carDir = 0;
    while(1) {
        int tileType = graph[carX][carY];
        if (tileDir[tileType].first.first == carDir) {
            carDir = tileDir[tileType].first.second;
            carX += dx[carDir];
            carY += dy[carDir];
            distance ++;
            cout << "Debug = type 1 -> " << carX << ' ' << carY << ' ' << carDir  << ' ' << tileType << '\n';
            if (carX < 0 || carY < 0 || carX > N-1 || carY > N-1) return;
        }
        else if (tileDir[tileType].second.first == carDir) {
            carDir = tileDir[tileType].second.second;
            carX += dx[carDir];
            carY += dy[carDir];
            distance ++;
            cout << "Debug = type 2 -> " << carX << ' ' << carY << ' ' << carDir << ' ' << tileType << '\n';
            if (carX < 0 || carY < 0 || carX > N-1 || carY > N-1) return;
        }
        else {
            return;
        }
        // cout << carX << ' ' << carY << ' ' << carDir << '\n';
        if (carX == N-1 && carY == N) break;
    }
    if(distance != 0) result = min(result, distance);
}

void DFS(int cnt, int idx, int idx2) {
    if (cnt == k) {
        Simulation();
        return;
    }

    for (int i = idx; i < N; i ++, idx2 = 0) {
        for(int j = idx2; j < N; j ++) {
            int temp = graph[i][j];
            for (int k = 0; k <= 5; k ++) {
                if (temp == k) continue;
                graph[i][j] = k;
                DFS(cnt + 1, i, j);
                graph[i][j] = temp;
            }
        }
    }
}

int main()
{   
    cin >> N >> k;
    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < N; j ++) {
            cin >> graph[i][j];
        }
    }

    // graph[2][1] = 3;
    Simulation(); // 바꾸지 않아도 될 수 있는 경우
    // DFS(0, 0, 0);

    if (result == INF) {
        cout << -1 << '\n';
    }
    else {
        cout << result << '\n';
    }
    return 0;
}