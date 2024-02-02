/*
아이디어 :

시간초과로 애먹었던 문제.

처음에는 상어 삭제를 벡터를 지우는 형식으로 했는데 시간 초과가 떠서 shark에 사이즈를 인덱스로 놓고 isLive를 통해 상어가 살아있나 없나를 판단함.

그런데 이제와서 다시해보니
int time;
if (shark[i].dir == 1 || shark[i].dir == 2) time = shark[i].speed % ((R-1)*2);
if (shark[i].dir == 3 || shark[i].dir == 4) time = shark[i].speed % ((C-1)*2);

이 부분이 문제였음.
사실 벡터로 해도 상관 없었다...

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

struct Shark {
    int x;
    int y;
    int speed;
    int dir;
    int size = 0;
    bool isLive = false;
};

int R, C, M;
int graph[101][101];
int result;
Shark shark[10001]; // 상어 크기가 인덱스
int maxIndex;
int dx[5] = {0, -1, 1, 0, 0};
int dy[5] = {0, 0, 0, 1, -1};

void FishingShark(int col) {
    for (int i = 1; i <= R; i ++) {
        if (graph[i][col] != 0) {
            result += graph[i][col];
            // 상어 없애기.
            shark[graph[i][col]].isLive = false;
            graph[i][col] = 0;
            break;
        }
    }

    return;
}

void MoveShark() {
    int temp[101][101] = {0,};
    for (int i = 0; i <= maxIndex; i ++) {
        if (shark[i].isLive) {
            int time;
            if (shark[i].dir == 1 || shark[i].dir == 2) time = shark[i].speed % ((R-1)*2);
            if (shark[i].dir == 3 || shark[i].dir == 4) time = shark[i].speed % ((C-1)*2);
            while(time) {
                int nx = shark[i].x + dx[shark[i].dir];
                int ny = shark[i].y + dy[shark[i].dir];

                if (nx < 1 || nx > R || ny < 1 || ny > C) {
                    if (shark[i].dir == 1) shark[i].dir = 2;
                    else if (shark[i].dir == 2) shark[i].dir = 1;
                    else if (shark[i].dir == 3) shark[i].dir = 4;
                    else if (shark[i].dir == 4) shark[i].dir = 3;
                    continue;
                }

                shark[i].x = nx;
                shark[i].y = ny;
                time --;
            }

            int x = shark[i].x;
            int y = shark[i].y;

            // 물고기 자리 배치. (그 자리에 다른 상어가 있으면 크기 비교해서 먹기.)
            if (temp[x][y] == 0) {
                temp[x][y] = shark[i].size;
            } 
            else {
                if (temp[x][y] < shark[i].size) {
                    shark[temp[x][y]].isLive = false;
                    temp[x][y] = shark[i].size;
                }
                else {
                    shark[i].isLive = false;
                }
            }
        }
    }

    copy(&temp[0][0], &temp[0][0] + 101*101, &graph[0][0]);

}

int main()
{
    cin >> R >> C >> M;

    for (int i = 0; i < M; i ++) {
        int r, c, s, d, z;
        cin >> r >> c >> s >> d >> z;
        Shark temp = {r,c,s,d,z,true};
        shark[z] = temp;
        graph[r][c] = z;
        maxIndex = max(maxIndex, z);
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