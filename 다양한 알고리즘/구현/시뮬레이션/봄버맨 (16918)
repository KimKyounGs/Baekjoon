/*
# 아이디어 

23.2.25
구현 시뮬레이션 문제이다.

if (nx < 0 || ny < 0 || nx > R-1 || ny > C-1 || graph[nx][ny] == times-3) continue;
이 구문에서 graph[nx][ny] == times-3 부분이 중요하다.
그 이유는 터져야할 폭탄이 옆에 있던 폭탄이 터지면서 -1로 바꿔어 지는 것을 막는 역할을 하기 때문이다.
이해가 안되면 저 부분을 지워보고 실행해보자 !
*/

#include <iostream>

using namespace std;

int R, C, N;
int graph[201][201];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void Simulation(int times) {
    if (times == 1) return;
    
    if (times % 2 == 0) {
        for (int i = 0; i < R; i ++) {
            for (int j = 0; j < C; j ++) {
                if (graph[i][j] == -1) {
                    graph[i][j] = times;
                }
            }
        } 
    }
    else {
        for (int i = 0; i < R; i ++) {
            for (int j = 0; j < C; j ++) {
                if (graph[i][j] == times-3) {
                    graph[i][j] = -1;
                    for (int z = 0; z < 4; z ++) {
                        int nx = i + dx[z];
                        int ny = j + dy[z];
                        if (nx < 0 || ny < 0 || nx > R-1 || ny > C-1 || graph[nx][ny] == times-3) continue;
                        graph[nx][ny] = -1;
                    }
                }
            }
        } 
    }
    /*
    for (int i = 0; i < R; i ++) {
        for (int j = 0; j < C; j ++) {    
            cout << graph[i][j];
        }
        cout << '\n';
    }
    cout << '\n';
    */
}

int main() {
    cin >> R >> C >> N;

    for (int i = 0; i < R; i ++) {
        for (int j = 0; j < C; j ++) {
            char c;
            cin >> c;
            if (c == '.') graph[i][j] = -1;
            else graph[i][j] = 0;
        }
    }

    for (int i = 0; i < N; i ++) {
        Simulation(i+1); 
    }

    for (int i = 0; i < R; i ++) {
        for (int j = 0; j < C; j ++) {    
            if (graph[i][j] == -1) cout << '.';
            else cout << 'O';
        }
        cout << '\n';
    }

    
}