/*
아이디어 : 처음 외벽을 조사할 때 들어갈 수 있는지 확인한다.

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

int N, M, D;
int graph[16][16];
bool bDie[16][16];
int result = 0;
vector<pair<int, int>> v;
vector<pair<int, int>> tempV;

bool visited[16][16];
int dx[] = {-1, 0, 0};
int dy[] = {0, 1, -1};



void EnemyDown()
{
    // 적을 내리는 대신 궁수 위치를 위로 한칸 옮기기
    for (int i = 0; i < v.size(); i ++)
    {
        tempV[i].first -= 1;   
    }
}

vector<pair<int, pair<int,int>>> BFS(int x, int y)
{
    vector<pair<int, pair<int,int>>> hitEnemy; // 맞은 적을 리턴하게.
    queue<pair<pair<int,int>, int>> q;
    int limit = x;
    q.push({{x, y},0});
    visited[x][y] = true;
    
    while(!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int d = q.front().second;
        q.pop();
        for (int i = 0; i < 3; i ++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nd = d+1;
            if (nx < 0 || nx > limit-1 || ny < 0 || ny > M-1) continue;

            if (nd > D || visited[nx][ny]) continue;
            // 적이 있고 살아있으면
            if (graph[nx][ny] == 1 && !bDie[nx][ny])
            {
                // 정렬 기준 때문에 좌표 거꾸로 넣기
                hitEnemy.push_back({nd,{ny,nx}});
            }
            q.push({{nx,ny},nd});
            visited[nx][ny] = true;
        }
    }

    return hitEnemy;
}

int ShootBow()
{
    int cnt = 0;
    vector<pair<int, int>> total;
    for (int i = 0; i < 3; i ++)
    {
        memset(visited, 0, sizeof(visited));
        vector<pair<int, pair<int, int>>> hitEnemy = BFS(tempV[i].first, tempV[i].second);
        if (hitEnemy.size() == 0) continue;
        sort(hitEnemy.begin(), hitEnemy.end()); // 정렬
        // cout << "i = " << i << " hit[0] " << hitEnemy[0].second.second << ' ' << hitEnemy[0].second.first <<endl;
        total.push_back({hitEnemy[0].second.second, hitEnemy[0].second.first});
    }

    for (int i = 0; i < total.size(); i ++)
    {
        // 그 병사가 아직 죽지 않았다면
        if (!bDie[total[i].first][total[i].second])
        {
            bDie[total[i].first][total[i].second] = true;
            // cout << "적 잡음 : " << total[i].first<< ' ' << total[i].second << endl;
            cnt ++;
        }
    }

    return cnt;
}

int Simulation()
{
    // cout << endl << "시뮬 시작" << endl;
    int enemyDelCnt = 0;
    int time = N;
    tempV = v;
    memset(bDie, 0, sizeof(bDie));
    while(time--)
    {
        enemyDelCnt += ShootBow();
        EnemyDown();
    }
    return enemyDelCnt;
}

void Back(int cnt, int idx)
{
    if (cnt == 3)
    {
        result = max(result, Simulation());
        return;
    }

    for (int i = idx; i < M; i ++)
    {
        v.push_back({N,i});
        Back(cnt + 1, i + 1);
        v.pop_back();
    }
}


int main()
{
    cin >> N >> M >> D;
    for (int i = 0; i < N; i ++)
    {
        for (int j = 0; j < M; j ++)
        {
            cin >> graph[i][j];
        }
    }

    Back(0, 0);
    // v.push_back({N, 0});
    // v.push_back({N, 2});
    // v.push_back({N, 4});
    // Simulation();
    cout << result << endl;
}
