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

struct Shark {
    int x;
    int y;
    bool isLive;
    int recentDir; // 현재 보고 있는 방향 
    int PriorityDir[5][5]; // dir[보고 있는 방향][우선순위];
};

int N, M, K;
int graph[21][21];
pair<int, int> sharkSmell[21][21]; // pair<상어 번호, K>
Shark sharks[5];
int dx[5] = {0, -1, 1, 0, 0};
int dy[5] = {0, 0, 0, -1, 1};

void LeaveSmell() {
    
}

void MoveShark() {
    for (int i = 1; i <= 4; i ++) {
        int cnt = 0; // 빈 공간 개수
        int x = sharks[i].x;
        int y = sharks[i].y;

        for (int j = 1; j <= 4; j ++) {
            int nx = x + dx[j];
            int ny = y + dy[j];
        }
    }
}

void Simulation() {
    MoveShark();
}

int main()
{   
    cin >> N >> M >> K;
    for (int i = 1; i <= N; i ++) {
        for (int j = 1; j <= N; j++) {
            cin >> graph[i][j];
        }
    }

    for (int i = 1; i <= 4; i ++) {
        cin >> sharks[i].recentDir;
    }

    for (int i = 1; i <= 4; i ++) {
        for (int j = 1; j <= 4; j ++) {
            for (int k = 1; k <= 4; k ++) {
                cin >> sharks[i].PriorityDir[j][k];
            }
        }
    }

    Simulation();
}