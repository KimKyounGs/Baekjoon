/*
아이디어 :

cctv 개수에 따라서 경우의 수가 나뉜다.
예를 들어서 cctv 개수가 3개면
cctv가 취할 수 있는 행동 4가지이며
경우의 수를 생각해보면 4*4*4 = 4^3이다.
문제에서 cctv의 개수가 최대 8개로 O(4^8)이다.

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

int N, M;
int graph[9][9];
int cctvCnt = 0;
int result = INF;
vector<pair<int, int>> v;

int total = 0;

// 차례대로 동, 서, 북, 남
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void Moniter(int x, int y, int dir, bool moni, int idx) {
    int mul = 1;
    int type = (idx+1)*10;
    if (moni) {
        while(1) {
            int nx = x + dx[dir] * mul;
            int ny = y + dy[dir] * mul;
            if (nx < 0 || ny < 0 || nx > N-1 || ny > M-1 || graph[nx][ny] == 6) break;
            if (graph[nx][ny] == 0) {
                graph[nx][ny] = type;
            }
            mul ++;
        }
    }
    else {
        while(1) {
            int nx = x + dx[dir] * mul;
            int ny = y + dy[dir] * mul;
            if (nx < 0 || ny < 0 || nx > N-1 || ny > M-1 || graph[nx][ny] == 6) break;
            if (graph[nx][ny] == type) {
                graph[nx][ny] = 0;
            }
            mul ++;
        }
    }
}

void CCTV(int x, int y, int dir, bool moni, int idx) {
    int type = graph[x][y];
    switch(type) {
        case 1: {
            Moniter(x, y, dir, moni, idx);
            break;
        }
        
        case 2: {
            // 0,1 2,3 0,1 2,3
            if (dir % 2 == 0) {
                Moniter(x, y, 0, moni, idx);
                Moniter(x, y, 1, moni, idx);
            }
            else {
                Moniter(x, y, 2, moni, idx);
                Moniter(x, y, 3, moni, idx);
            }
            break;
        }    
        case 3: {
            // 0,2 1,2 1,3 0,3
            if (dir == 0) {
                Moniter(x, y, 0, moni, idx);
                Moniter(x, y, 2, moni, idx);
            }
            else if (dir == 1) {
                Moniter(x, y, 1, moni, idx);
                Moniter(x, y, 2, moni, idx);
            }
            else if (dir == 2) {
                Moniter(x, y, 1, moni, idx);
                Moniter(x, y, 3, moni, idx);
            }
            else if (dir == 3) {
                Moniter(x, y, 0, moni, idx);
                Moniter(x, y, 3, moni, idx);
            }
            break;
        }
        case 4: {
            // 0,1,2 1,2,3 0,1,3 0,2,3
            if (dir == 0) {
                Moniter(x, y, 0, moni, idx);
                Moniter(x, y, 1, moni, idx);
                Moniter(x, y, 2, moni, idx);
            }
            else if (dir == 1) {
                Moniter(x, y, 1, moni, idx);
                Moniter(x, y, 2, moni, idx);
                Moniter(x, y, 3, moni, idx);
            }
            else if (dir == 2) {
                Moniter(x, y, 0, moni, idx);
                Moniter(x, y, 1, moni, idx);
                Moniter(x, y, 3, moni, idx);
            }
            else if (dir == 3) {
                Moniter(x, y, 0, moni, idx);
                Moniter(x, y, 2, moni, idx);
                Moniter(x, y, 3, moni, idx);
            }
            break;
        }
        case 5: {
            Moniter(x, y, 0, moni, idx);
            Moniter(x, y, 1, moni, idx);
            Moniter(x, y, 2, moni, idx);
            Moniter(x, y, 3, moni, idx);
            break;
        }
    }
}

void DFS(int cnt, int idx) {
    if (cnt == cctvCnt) {
        total ++;
        int sum = 0;
        for (int i = 0; i < N; i ++) {
            for (int j = 0; j < M; j ++) {
                if (graph[i][j] == 0) sum ++;
            }
        }
        /*
        cout << '\n' << "/////출력/////" << '\n';
        for (int i = 0; i < N; i ++) {
            for (int j = 0; j < M; j ++) {
                cout << graph[i][j] << ' ';
            }
            cout << '\n';
        }
        */
        result = min(result, sum);
        return;
    }

    for (int i = idx; i < cctvCnt; i ++) {
        for (int j = 0; j < 4; j ++) {
            CCTV(v[i].first, v[i].second, j, true, idx);
            DFS(cnt + 1, i + 1);
            CCTV(v[i].first, v[i].second, j, false, idx);
        }
    }
}

int main() { 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < M; j ++) {
            cin >> graph[i][j];
            if (graph[i][j] != 0 && graph[i][j] != 6) {
                cctvCnt ++;
                v.push_back({i,j});
            }
        }
    }
    DFS(0, 0);
    //cout << "total = " << total << '\n';
    cout << result << '\n';
}