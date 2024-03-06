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

int N, M, fuel, cnt;
int taxiX, taxiY;
int graph[21][21];
int temp[21][21];
bool visit[21][21];
vector<pair<int, int>> cStart; // 손님 시작점
vector<pair<int, int>> cEnd; // 손님 도착점
int customer[401]; // 손님 거리 저장. --> -2는 이미 도착한 사람.
// ex) 0번째 손님 = 2, 1번째 손님 = 3으로 graph에 저장됨.
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int BFS(int x1, int y1, int x2, int y2) {
    queue<pair<int, int>> q;
    q.push({x1, y1});
    visit[x1][y1] = true;

    // 시작점과 도착점이 같은 경우
    if (x1 == x2 && y1 == y2) {
        return 0;
    }

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for (int i = 0; i < 4; i ++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // 범위체크, 방문체크, 벽 체크
            if (nx < 1 || ny < 1 || nx > N || ny > N || visit[nx][ny] || graph[nx][ny] == 1) continue;

            if (temp[x][y] + 1 <= fuel) {
                if (nx == x2 && ny == y2) {
                    return temp[x][y] + 1;
                }

                temp[nx][ny] = temp[x][y] + 1;
                q.push({nx,ny});
                visit[nx][ny] = true;
            }
        }
    }
    
    return -1;
}

void BFS(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x,y});
    visit[x][y] = true;

    // 택시 시작점에 손님이 있는 경우
    if (graph[x][y] >= 2 && customer[graph[x][y]-2] != -2) {
        customer[graph[x][y]-2] = 0;
    }

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i ++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // 범위체크, 방문체크, 벽 체크
            if (nx < 1 || ny < 1 || nx > N || ny > N || visit[nx][ny] || graph[nx][ny] == 1) continue;

            if (temp[x][y] + 1 <= fuel) {
                if (graph[nx][ny] != 0) {
                    // 목적지에 도착한 손님이 아니면.
                    if (customer[graph[nx][ny]-2] != -2) {
                        customer[graph[nx][ny]-2] = temp[x][y] + 1;
                    }
                }
                temp[nx][ny] = temp[x][y] + 1;
                q.push({nx,ny});
                visit[nx][ny] = true;
            }
        }
    }
}

bool Move(int idx) {
    int distance = customer[idx];
    if (distance <= fuel) {
        fuel -= distance;
        memset(temp, 0, sizeof(temp));
        memset(visit, 0, sizeof(visit));
        int distance = BFS(cStart[idx].first, cStart[idx].second, cEnd[idx].first, cEnd[idx].second);
        if (distance != -1 && distance <= fuel) {
            fuel += distance;
            return true;
        }
    }

    return false;
}

void Sol() {
    // 초기화
    memset(visit, 0, sizeof(visit));
    memset(temp, 0, sizeof(temp));
    for(int i = 0; i < M; i ++) {
        if (customer[i] == -2) continue;
        customer[i] = -1;
    }

    // 최단거리 계산.
    BFS(taxiX, taxiY);

    int min = INF;
    int cusIdx = -1;
    // 최단거리 손님 구하기
    for (int i = 0; i < M; i++) {

        // 이미 도착한 손님.
        if (customer[i] == -2 || customer[i] == -1) continue;

        if (min > customer[i]) {
            min = customer[i];
            cusIdx = i;
        }
            
        else if (min == customer[i]) {
            // 행 번호가 가장 작은 손님
            if (cStart[i].first < cStart[cusIdx].first) {
                min = customer[i];
                cusIdx = i;
            }
            else if (cStart[i].first == cStart[cusIdx].first) {
                // 열 변호가 가장 작은 손님
                if (cStart[i].second < cStart[cusIdx].second) {
                    min = customer[i];
                    cusIdx = i;
                }
            }
        }
    }

    // 태울 손님이 아무도 없다.
    if (cusIdx == -1) {
        cout << -1 << endl;
        exit(0);
    }

    // 이동하기
    if (Move(cusIdx)) {
        taxiX = cEnd[cusIdx].first;
        taxiY = cEnd[cusIdx].second;
        customer[cusIdx] = -2;
        cnt ++;

        // 모든 손님 다 태움
        if (cnt == M) {
            cout << fuel << endl;
            exit(0);
        }
    }
    else {
        cout << -1 << endl;
        exit(0);
    }
}


int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> fuel;
    for (int i = 1; i <= N; i ++) {
        for (int j = 1; j <= N; j ++) {
            cin >> graph[i][j];
        }
    }

    cin >> taxiX >> taxiY;

    for (int i = 0; i < M; i ++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cStart.push_back({x1, y1});
        cEnd.push_back({x2, y2});
        graph[x1][y1] = i+2;
        customer[i] = -1;
    }

    for (int i = 0; i < M; i ++) {
        Sol();
    }

    return 0;
}
