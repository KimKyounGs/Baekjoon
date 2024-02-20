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
#include <climits>
#define INF 1e9
#define endl '\n'

using namespace std;

int N;
bool graph[10][10];
int score;
int total;

void Total() {
    for (int i = 4; i <= 9; i++) {
        for (int j = 0; j <= 3; j ++) {
            if (graph[i][j] > 0) {
                total ++;
            }
        }
    }

    for (int i = 0; i <= 3; i ++) {
        for (int j = 4; j <= 9; j ++) {
            if (graph[i][j] > 0) {
                total ++;
            }
        }
    }
}

void ScoreCheck() {
    // 초록색
    int cnt = 0;
    for (int i = 9; i >= 4; i --) {
        if (graph[i][0] > 0 && graph[i][1] > 0 && graph[i][2] > 0 && graph[i][3] > 0) {
            for (int j = 0; j <= 3; j ++) {
                graph[i][j] = 0;
            }
            cnt ++;
            score++;
        }

        else if (cnt > 0) {
            for (int j = 0; j <= 3; j ++) {
                graph[i+cnt][j] = graph[i][j];
                graph[i][j] = 0;
            }
        }
    }

    
    // 파란색
    cnt = 0;
    for (int i = 9; i >= 4; i --) {
        if (graph[0][i] > 0 && graph[1][i] > 0 && graph[2][i] > 0 && graph[3][i] > 0) {
            for (int j = 0; j <= 3; j ++) {
                graph[j][i] = 0;
            }
            cnt ++;
            score++;
        }
        else if (cnt > 0) {
            for (int j = 0; j <= 3; j ++) {
                graph[j][i+cnt] = graph[j][i];
                graph[j][i] = 0;
            }
        }
    }


    
}

void SpecialCheck() {
    // 초록색
    int cnt = 0;
    for (int i = 4; i <= 5; i ++) {
        bool check = false;
        for (int j = 0; j <= 3; j ++) {
            if (graph[i][j] > 0) {
                check = true;
                break;
            }
        }
        if (check) cnt ++;
    }

    if (cnt) {
        for (int i = 9-cnt; i >= 4; i --) {
            for (int j = 0; j <= 3; j ++) {
                graph[i+cnt][j] = graph[i][j];
                graph[i][j] = 0;
            }
        }
    }
    
    // 파란색
    cnt = 0;
    for (int i = 4; i <= 5; i ++) {
        bool check = false;
        for (int j = 0; j <= 3; j ++) {
            if (graph[j][i] > 0) {
                check = true;
                break;
            }
        }
        if (check) cnt ++;
    }

    if (cnt) {
        for (int i = 9-cnt; i >= 4; i --) {
            for (int j = 0; j <= 3; j ++) {
                graph[j][i+cnt] = graph[j][i];
                graph[j][i] = 0;
            }
        }
    }

    
}

void Move(int t, int x, int y, int n) {
    if (t == 1) {
        int nx = x;
        // 초록색
        while(1) {
            if (graph[nx+1][y] == 0 && nx + 1 <= 9) {
                nx ++;
            }
            else {
                graph[nx][y] = n;
                break;
            }
        }

        // 파란색 
        int ny = y;
        while(1) {
            if (graph[x][ny+1] == 0 && ny + 1 <= 9) {
                ny ++;
            }
            else {
                graph[x][ny] = n;
                break;
            }
        }
    }

    else if (t == 2) {
        // 초록색
        int nx = x;
        while(1) {
            if (graph[nx+1][y] == 0 && graph[nx+1][y+1] == 0 && nx + 1 <= 9) {
                nx ++;
            }
            else {
                graph[nx][y] = n;
                graph[nx][y+1] = n;
                break;
            }
        }

        // 파란색
        int ny = y + 1;
        while(1) {
            if (graph[x][ny+1] == 0 && ny + 1 <= 9) {
                ny ++;
            }
            else {
                graph[x][ny] = n;
                graph[x][ny-1] = n;
                break;
            }
        }
    }

    else if (t == 3) {
        // 초록색
        int nx = x + 1;
        while(1) {
            if (graph[nx+1][y] == 0 && nx + 1 <= 9) {
                nx ++;
            }
            else {
                graph[nx][y] = n;
                graph[nx-1][y] = n;
                break;
            }
        }

        // 파란색
        int ny = y;
        while(1) {
            if (graph[x][ny+1] == 0 && graph[x+1][ny+1] == 0 && ny + 1 <= 9) {
                ny ++;
            }
            else {
                graph[x][ny] = n;
                graph[x+1][ny] = n;
                break;
            }
        }
    }
}

int main(){
    cin >> N;

    for (int i = 1; i <= N; i ++) {
        int t, x, y;
        cin >> t >> x >> y;

        Move(t,x,y,i);
        ScoreCheck();
        SpecialCheck();
    }

    Total();
    cout << score << endl << total << endl;
}

