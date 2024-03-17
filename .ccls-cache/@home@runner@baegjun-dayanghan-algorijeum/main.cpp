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

struct Fish {
    int num, x, y, dir;
    bool isLive;
};

int N;
int result = 0;
vector<Fish> fishs;
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};

bool Compare(const Fish& p1, const Fish& p2) {
    return p1.num < p2.num;
}

void FishMove(int sharkX, int sharkY, int (&graph)[5][5]) {
    for (int i = 0; i < 16; i ++) {
        // 살아 있는 물고기만 움직이기.
        if (fishs[i].isLive == true) {
            int num = fishs[i].num;
            int dir = fishs[i].dir;
            int x = fishs[i].x;
            int y = fishs[i].y;

            while(true) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];

                // 경계선 넘어가거나 상어가 있는 칸은 건너뛰기
                if (nx < 0 || ny < 0 || nx > 3 || ny > 3 || (nx == sharkX && ny == sharkY)) {
                    dir ++;
                    if (dir == 8) {
                        dir = 0;
                    }
                    continue;
                } 

                // 이동할 칸에 다른 물고기가 있다면
                if (graph[nx][ny] != 0) {
                    // 이동하는 물고기 정보 업데이트
                    fishs[i].x = nx;
                    fishs[i].y = ny;
                    fishs[i].dir = dir;

                    // 원래 있던 물고기 정보 업데이트
                    int tempNum = graph[nx][ny];
                    fishs[tempNum-1].x = x;
                    fishs[tempNum-1].y = y;

                    // graph 업데이트
                    graph[x][y] = tempNum;
                    graph[nx][ny] = num;
                }
                // 이동할 칸이 빈칸이면
                else {
                    // 이동하는 물고기 정보 업데이트
                    fishs[i].x = nx;
                    fishs[i].y = ny;
                    fishs[i].dir = dir;

                    // graph 업데이트
                    graph[x][y] = 0;
                    graph[nx][ny] = num;
                }
                break;
            }
        } 
    }
}

vector<pair<int, int>> SharkMove(int sharkX, int sharkY, int sharkDir, int (&graph)[5][5]) {
    vector<pair<int, int>> v;
    int tempX = sharkX, tempY = sharkY;
    while(true) {
        int nx = tempX + dx[sharkDir];
        int ny = tempY + dy[sharkDir];
        
        if (nx < 0 || ny < 0 || nx > 3 || ny > 3) break;

        // 상어가 이동할 좌표에 물고기가 있다면
        if (graph[nx][ny] != 0) {
            v.push_back({nx, ny});
        }
        tempX = nx;
        tempY = ny;
        cout << "Debug = " << tempX << ' ' << tempY << ' ' << sharkDir << endl;
    }
    return v;
}

void DFS(int sum, int sharkX, int sharkY, int sharkDir, int (&graph)[5][5]) {
    int temp[5][5];
    copy(&temp[0][0], &temp[0][0]+5*5, &graph[0][0]);
    FishMove(sharkX, sharkY, graph);
    vector<pair<int, int>> v = SharkMove(sharkX, sharkY, sharkDir, graph);
    
    if (v.size() == 0) {
        result = max(result, sum);
        return;
    }

    for (int i = 0; i < v.size(); i ++) {
        int x = v[i].first;
        int y = v[i].second;
        int num = graph[x][y];
        sum += num;
        graph[x][y] = 0;
        fishs[num-1].isLive = false;
        DFS(sum, x, y, fishs[num-1].dir, graph);
        copy(&graph[0][0], &graph[0][0]+5*5, &temp[0][0]);
        sum -= num;
        graph[x][y] = num;
        fishs[num-1].isLive = true;
    }
    
}

int main()
{   
    int sum = 0;
    int sharkX;
    int sharkY;
    int sharkDir;
    int graph[5][5] = {0,};
    for (int i = 0; i < 4; i ++) {
        for (int j = 0; j < 4; j ++) {
            int a, b;
            cin >> a >> b;
            // 첫번째 물고기는 먹는다.
            if (i == 0 && j == 0) {
                sharkX = i;
                sharkY = j;
                sharkDir = b-1;
                sum = a;
                fishs.push_back({a,i,j,b-1,false});
                continue;
            }
            graph[i][j] = a;
            fishs.push_back({a,i,j,b-1,true});
        }
    }
    // 번호대로 움직이기 위해 정렬
    sort(fishs.begin(), fishs.end(), Compare);

    DFS(sum, sharkX, sharkY, sharkDir, graph);

    cout << result << endl;
    // for (int i = 0; i < 4; i ++) {
    //     for (int j = 0; j < 4; j ++) {
    //         cout << graph[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    // cout << endl;
    // for (int i = 0; i < fishs.size(); i ++) {
    //     cout << i + 1 << "번의 물고기 정보" << fishs[i].x << ' ' << fishs[i].y << ' ' << fishs[i].dir << ' ' << fishs[i].isLive << endl;
    // }
}