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

struct shark {
    int x;
    int y;
    int speed;
    int dir;
    int size;
};

int R, C, M;
int graph[101][101];
int result;
vector<shark> v;
int dx[5] = {0, -1, 1, 0, 0};
int dy[5] = {0, 0, 0, 1, -1};

void FishingShark(int col) {
    for (int i = 1; i <= R; i ++) {
        if (graph[i][col] != 0) {
            result += graph[i][col];
            int len = v.size();
            for (int j = 0; j < len; j ++) {
                if (v[j].size == graph[i][col]) {
                    v.erase(v.begin() + j);
                    graph[i][col] = 0;
                    break;
                }
            }
            break;
        }
    }

    return;
}

void MoveShark() {
    int temp[101][101] = {0,};
    vector<shark> tempV;
    int len = v.size();
    for (int i = 0; i < len; i ++) {
        int time = v[i].speed;
        while(time) {
            int nx = v[i].x + dx[v[i].dir];
            int ny = v[i].y + dy[v[i].dir];
                
            if (nx < 1 || nx > R || ny < 1 || ny > C) {
                if (v[i].dir == 1) v[i].dir = 2;
                else if (v[i].dir == 2) v[i].dir = 1;
                else if (v[i].dir == 3) v[i].dir = 4;
                else if (v[i].dir == 4) v[i].dir = 3;
                continue;
            }

            v[i].x = nx;
            v[i].y = ny;
            time --;
        }

        if (temp[v[i].x][v[i].y] == 0) {
            temp[v[i].x][v[i].y] = v[i].size;
            tempV.push_back(v[i]);
        }
        else {
            if (v[i].size > temp[v[i].x][v[i].y]) {
                int len2 = tempV.size();
                for (int j = 0; j < len2; j ++) {
                    if (tempV[j].size == temp[v[i].x][v[i].y]) {
                        tempV.erase(tempV.begin() + j);
                        break;
                    }
                }
                temp[v[i].x][v[i].y] = v[i].size;
                tempV.push_back(v[i]);
            }
        }
    }

    copy(&temp[0][0], &temp[0][0] + 101*101, &graph[0][0]);
    v.clear();
    for (int i = 0; i < tempV.size(); i ++) {
        v.push_back(tempV[i]);
    }
}

int main()
{
    cin >> R >> C >> M;

    for (int i = 0; i < M; i ++) {
        int r, c, s, d, z;
        cin >> r >> c >> s >> d >> z;
        graph[r][c] = z;
        v.push_back({r,c,s,d,z});
    }

    for (int i = 1; i <= C; i ++) {
        FishingShark(i);
        MoveShark();

        /*
        cout << "현재 i = " << i << endl;
        for (int j = 1; j <= R; j ++) {
            for (int k = 1; k <= C; k ++) {
                cout << graph[j][k] << ' ';
            }
            cout << endl;
        }
        cout << endl;
        */
    }

    cout << result << endl;
}