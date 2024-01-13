/*
아이디어 :

0 2
3 4
5 6
7 8
4 4 4 1 3 3 3 2

5 0 0 0 3 0
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
int x,y;
int graph[21][21];
int dice[6];
int idx = 1; // 윗면 인덱스

void Dice(int dir) {
    
}

int Dice() {
    if (idx == 1) {
        return 6;
    }
    else if (idx == 2) {
        return 5; 
    }
    else if (idx == 3) {
        return 4;
    }
    else if (idx == 4) {
        return 3;
    }
    else if (idx == 5) {
        return 2;
    }
    else if (idx == 6) {
        return 1;
    }
}

void Simulation(int dir) {
    int nx, ny;
    switch(dir) {
        // 동
        case 1 : {
            nx = x;
            ny = y + 1;
            if (nx < 0 || ny > N-1 || ny < 0 || ny > M-1) {
                return;
            }
            break;
        }
        // 서
        case 2 : {
            nx = x;
            ny = y - 1;
            if (nx < 0 || ny > N-1 || ny < 0 || ny > M-1) {
                return;
            }
            break;
        }
        // 북
        case 3 : {
            nx = x - 1;
            ny = y;
            if (nx < 0 || ny > N-1 || ny < 0 || ny > M-1) {
                return;
            }
            break;
        }
        // 남
        case 4 : {
            nx = x + 1;
            ny = y;
            if (nx < 0 || ny > N-1 || ny < 0 || ny > M-1) {
                return;
            }
            break;
        }
    }
    Dice(dir);
    cout << "Debug = " << idx << '\n';
    int dIdx = Dice();
    if (graph[nx][ny] == 0) {
        graph[nx][ny] = dice[dIdx-1];
    }
    else {
        dice[dIdx-1] = graph[nx][ny];
        graph[nx][ny] = 0;
    }
    cout << dice[idx-1] << endl;
    x = nx;
    y = ny;
}

int main()
{
    cin >> N >> M >> x >> y >> K;
    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < M; j ++) {
            cin >> graph[i][j];
        }
    }

    for (int i = 0; i < K; i ++) {
        int n;
        cin >> n;
        Simulation(n);
    }
    
    return 0;
}