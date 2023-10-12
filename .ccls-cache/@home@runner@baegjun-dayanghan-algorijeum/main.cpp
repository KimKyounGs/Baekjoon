/*
아이디어 :

구간을 3으로 나누기.
3 3 3
3 3 3
3 3 3

0을 찾으면.
확인 및 채워넣기.

참고 : 
https://yabmoons.tistory.com/129

*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>
#include <deque>

using namespace std;

int graph[11][11];
bool Row[10][10];
bool Col[10][10];
bool Square[10][10];

/*
bool check(int x, int y, int n) {
    int endX = 3*(x/3+1);
    int startX = endX-2;
    int endY = 3*(y/3+1);
    int startY = endY-2;

    for (int i = 1; i <= 9; i ++) {
        if (graph[x][i] == n || graph[i][y] == n) {
            return false;
        }
    }
    
    for (int i = startX; i <= endX; i ++) {
        for (int j = startY; j <= endY; j ++) {
            if (graph[i][j] == n) {
                return false;
            }
        }
    }
    return true;
}
*/

void DFS(int cnt) {
    if (cnt == 81) {
        for (int i = 0; i < 9; i ++) {
            for (int j = 0; j < 9; j ++) {
                 cout << graph[i][j];
            }
            cout << '\n';
        }
        exit(0);
    }

    int x = (cnt / 9);
    int y = (cnt % 9);

    if (graph[x][y] == 0) {
        for (int i = 1; i <= 9; i ++) {
            if (Row[x][i] == false && Col[y][i] == false && Square[(x / 3) * 3 + (y / 3)][i] == false)
            {
                Row[x][i] = true;
                Col[y][i] = true;
                Square[(x / 3) * 3 + (y / 3)][i] = true;
                graph[x][y] = i;
                DFS(cnt + 1);
                graph[x][y] = 0;
                Row[x][i] = false;
                Col[y][i] = false;
                Square[(x / 3) * 3 + (y / 3)][i] = false;
            }
        }
    }
    else {
        DFS(cnt + 1);
    }
}

int main() { 
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
    for (int i = 0; i < 9; i ++) {
        for (int j = 0; j < 9; j ++) {
            scanf("%1d", &graph[i][j]);
            if (graph[i][j] != 0)
            {
                Row[i][graph[i][j]] = true;
                Col[j][graph[i][j]] = true;
                Square[(i / 3) * 3 + (j / 3)][graph[i][j]] = true;
            }
        }
    }
    //cout << '\n';
    DFS(0);

}