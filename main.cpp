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

int N, K;
vector<pair<pair<int, int>, int>> v;
deque<int> graph[13][13];
int color[13][13];
// 0, 1(동), 2(서), 3(북), 4(남)
int dx[] = {0, 0, 0, -1, 1};
int dy[] = {0, 1, -1, 0, 0};
bool check = false;

void White(int x, int y, int nx, int ny, int n) {
    queue<int> q;
    while(1) {
        int num = graph[x][y].front();
        q.push(num);
        graph[x][y].pop_front();
        if (num == n) {
            break;
        }
    }

    while(!q.empty()) {
        int num = q.front();
        graph[nx][ny].push_back(num);
        q.pop();
    }

    if (graph[nx][ny].size() >= 4) {
        check = true;
    }
}

void Red(int x, int y, int nx, int ny, int n) {
    stack<int> s;
    while(1) {
        if (graph[x][y] ==                )
        int num = graph[x][y].front();
        s.push(num);
        graph[x][y].pop_front();
        if (num == n) {
            break;
        }
    }

    while(!s.empty()) {
        int num = s.top();
        graph[nx][ny].push_back(num);
        s.pop();
    }
                    
    if (graph[nx][ny].size() >= 4) {
        check = true;
    }
}

void Sol() {
    for (int i = 0; i < K; i ++) {
        if (check) break;
        int n = i+1;
        int x = v[i].first.first;
        int y = v[i].first.second;
        int dir = v[i].second;

        int nx = x + dx[dir];
        int ny = y + dy[dir];

        // 파란색 or 범위 벗어남.
        if (nx < 1 || nx > N || ny < 1 || ny > N || color[nx][ny] == 2) {
            if (dir == 1) v[i].second = 2;
            else if (dir == 2) v[i].second = 1;
            else if (dir == 3) v[i].second = 4;
            else if (dir == 4) v[i].second = 3;

            dir = v[i].second;
            nx = x + dx[dir];
            ny = y + dy[dir];

            if (nx < 1 || nx > N || ny < 1 || ny > N || color[nx][ny] == 2) {
                if (dir == 1) v[i].second = 2;
                else if (dir == 2) v[i].second = 1;
                else if (dir == 3) v[i].second = 4;
                else if (dir == 4) v[i].second = 3;

                continue;
            }
            else {
                if (color[nx][ny] == 0) {
                    White(x,y,nx,ny,n);
                } 
                else if (color[nx][ny] == 1) {
                    Red(x,y,nx,ny,n);
                }
            }
        }
        else if (color[nx][ny] == 0) {
            White(x,y,nx,ny,n);
        }
        else if (color[nx][ny] == 1) {
            Red(x,y,nx,ny,n);
        }
    }
}


int main() {
    cin >> N >> K;
    for (int i = 1; i <= N; i ++) {
        for (int j = 1; j <= N; j ++) {
            cin >> color[i][j];
        }
    }

    for (int i = 1; i <= K; i ++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a][b].push_back(i);
        v.push_back({{a,b},c});
    }


    /*
    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < N; j ++) {
            if(graph[i][j].size() != 0) {
                
            }
        }
    }
    */
    
    for (int i = 1; i < 1000; i ++) {
        Sol();
        if (check) {
            cout << i << endl;
            return 0;
        }
    }

    cout << -1 << endl;
    

}
