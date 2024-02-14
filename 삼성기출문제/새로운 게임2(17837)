/*
아이디어 :

파란색애서 다시 파란색이나 벽을 만나면 방향을 바꾸지 않고 그대로 낫둬야 한다.
처음에 방향을 바꿔서 자꾸 6프로에서 틀렸었다.

deque을 이용해서 말들의 위치하고 어떻게 쌓여있는지 나타냈다.

시간복잡도 :

주어진 입력에 따라서, 각 말이 이동하는 횟수는 최대 1000번으로 제한되어 있습니다. 따라서 이 코드의 반복 횟수는 상수입니다. 이를 O(1)로 간주합니다.

Sol 함수 내에서 각 말이 이동하고, 해당 위치에서 처리되는 동작들은 상수 시간이 걸립니다. 이동하고 해당 위치에서의 처리가 O(1)입니다.

따라서 전체적인 시간 복잡도는 O(1)입니다.

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

void Red(int x, int y, int nx, int ny, int n) {
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
        graph[nx][ny].push_front(num);
        v[num-1].first.first = nx;
        v[num-1].first.second = ny;
        q.pop();
    }

    if (graph[nx][ny].size() >= 4) {
        check = true;
    }
}

void White(int x, int y, int nx, int ny, int n) {
    stack<int> s;
    while(1) {
        int num = graph[x][y].front();
        s.push(num);
        graph[x][y].pop_front();
        if (num == n) {
            break;
        }
    }

    while(!s.empty()) {
        int num = s.top();
        graph[nx][ny].push_front(num);
        v[num-1].first.first = nx;
        v[num-1].first.second = ny;
        s.pop();
    }

    if (graph[nx][ny].size() >= 4) {
        check = true;
    }
}

void Sol() {
    for (int i = 0; i < K; i ++) {
        int n = i+1;
        int x = v[i].first.first;
        int y = v[i].first.second;
        int dir = v[i].second;

        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (graph[x][y].size() >= 4) {
            check = true;
            break;
        }
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
                /*
                if (dir == 1) v[i].second = 2;
                else if (dir == 2) v[i].second = 1;
                else if (dir == 3) v[i].second = 4;
                else if (dir == 4) v[i].second = 3;
                */
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

        if (check) break;
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
        int x, y, d;
        cin >> x >> y >> d;
        graph[x][y].push_back(i);
        v.push_back({{x,y},d});
    }


    for (int i = 1; i <= 1000; i ++) {
        Sol();
        if (check) {
            cout << i << endl;
            return 0;
        }
    }

    cout << -1 << endl;

}
