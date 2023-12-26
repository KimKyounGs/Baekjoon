/*
아이디어 :

-1 조건 
1. B가 0에 빠질 때
2. 더 이상 구멍에 못 갈 때

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

int Red(int idx);
int Blue(int idx);

struct Point {
    int x;
    int y;
};

int N, M;
Point red, blue, target;
char graph[11][11];
int redVisited[11][11];
int blueVisited[11][11];
queue<Point> redQ;
queue<Point> blueQ;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};


int Red(int idx) {
    int x,y;
    if (!redQ.empty()) {
        x = redQ.front().x;
        y = redQ.front().y;
        redQ.pop();
    }
    else return 0;

    cout << "Red enter" << '\n';
    int mul = 1;
    while(true) 
    {
        int nx = x + dx[idx] * mul;
        int ny = y + dy[idx] * mul;

        // 굴러가다가 B 만나면 B 먼저 하게 함.
        if (graph[nx][ny] == 'B') {
            Blue(idx);
        }
            
        // 구멍을 만나면 그대로 끝.
        else if (graph[nx][ny] == 'O') {
            redVisited[nx][ny] = redVisited[x][y] + 1;
            return 1;
        }

        // 굴러가다가 벽을 만나면
        else if (graph[nx][ny] == '#' || blueVisited[nx][ny] == redVisited[x][y]) {
            int ex = nx + dx[idx] * (--mul);
            int ey = ny + dy[idx] * (--mul);
            if (redVisited[ex][ey] == 0) {
                redQ.push({ex, ey});
                redVisited[ex][ey] = redVisited[x][y] + 1;
            }
            break;
        }
        
        mul ++;
    }
    return 2;
}

int Blue(int idx) {
    int x,y;
    if (!blueQ.empty()) {
        x = blueQ.front().x;
        y = blueQ.front().y;
        blueQ.pop();
    }
    else return 0;

    cout << "Blue enter" << '\n';
    int mul = 1;
    while(true) 
    {
        int nx = x + dx[idx] * mul;
        int ny = y + dy[idx] * mul;

        // 굴러가다가 B 만나면 B 먼저 하게 함.
        if (graph[nx][ny] == 'R') {
            Red(idx);
        }

        // 구멍을 만나면 그대로 끝.
        else if (graph[nx][ny] == 'O') {
            blueVisited[nx][ny] = blueVisited[x][y] + 1;
            return 1;
        }

        // 굴러가다가 벽을 만나면
        else if (graph[nx][ny] == '#' || blueVisited[x][y] == redVisited[nx][ny]) {
            int ex = nx + dx[idx] * (--mul);
            int ey = ny + dy[idx] * (--mul);
            if (blueVisited[ex][ey] == 0) {
                blueQ.push({ex, ey});
                blueVisited[ex][ey] = blueVisited[x][y] + 1;
            }
            break;
        }

        mul ++;
    }
    return 2;
}

void BFS() {
    redQ.push(red);
    blueQ.push(blue);
    redVisited[red.x][red.y] = 1;
    blueVisited[blue.x][blue.y] = 1;
    
    while(true) {
        for (int i = 0; i < 4; i ++) {
            int nRed = Red(i);
            int nBlue = Blue(i);
            if ((nRed == 0 && nBlue == 0) || (nRed == 1 || nBlue == 1)) break;
        }

        // Debug
        cout << '\n' << "Red" << '\n';
        for(int i = 0; i < N; i ++) {
            for (int j = 0; j < N; j ++) {
                cout << redVisited[i][j] << ' ';
            }
            cout << '\n';
        }
        cout << "blue" << '\n';
        for(int i = 0; i < N; i ++) {
            for (int j = 0; j < N; j ++) {
                cout << blueVisited[i][j] << ' ';
            }
            cout << '\n';
        }
    }
}


int main() { 
    cin >> N >> M;    
    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < M; j ++) {
            cin >> graph[i][j];
            if (graph[i][j] == 'B') {
                blue.x = i;
                blue.y = j;
            }
            else if (graph[i][j] == 'R') {
                red.x = i;
                red.y = j;
            }
            else if (graph[i][j] == 'O') {
                target.x = i;
                target.y = j;
            }
        }
    }


    BFS();

    // red만 들어오고 blue는 없어야 한다.
    if (redVisited[target.x][target.y] != 0 && blueVisited[target.x][target.y] == 0) {
        cout << redVisited[target.x][target.y] << '\n';
    }
    else {
        cout << -1 << '\n';
    }
}