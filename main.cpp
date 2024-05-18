/*
계속해서 틀렸었는데, 밑에 질문 사이트를 보고 깨달았음.
https://www.acmicpc.net/board/view/65157
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

struct FireBall {
    int x, y, m, s, d;
};

int N,M,K;
vector<FireBall> graph[51][51];
vector<FireBall> v;
int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

// 1 2 3 4 5
void MoveFireBall() {
    for (int i = 1; i <= N; i ++) {
        for (int j = 1; j <= N; j ++) {
            if (graph[i][j].size() == 0) continue;
            graph[i][j].clear();
        }
    }
    for (int i = 0; i < v.size(); i ++) {
        int nx = v[i].x + v[i].s*dx[v[i].d];
        int ny = v[i].y + v[i].s*dy[v[i].d];

        if (nx > N) {
            int n = nx/N;
            nx -= n*N;
        }
        if (nx < 1) {
            int n = abs(nx)/N;
            nx += (n+1)*N;
        }
        if (ny > N) {
            int n = ny/N;
            ny -= n*N;
        }
        if (ny < 1) {
            int n = abs(ny)/N;
            ny += (n+1)*N;
        }

        v[i].x = nx;
        v[i].y = ny;
        graph[nx][ny].push_back(v[i]);
    }
}

void DividFireBall() {
    vector<FireBall> tempV;
    for (int i = 1; i <= N; i ++) {
        for (int j = 1; j <= N; j ++) {
            if (graph[i][j].size() == 0) continue;
            if (graph[i][j].size() == 1) {
                tempV.push_back(graph[i][j][0]); 
                continue;
            }

            int sum = 0, velocity = 0, direction = -1;
            bool check = true;
            for (int k = 0; k < graph[i][j].size(); k ++) {
                sum += graph[i][j][k].m;
                velocity += graph[i][j][k].s;
                if (direction == -1) direction = graph[i][j][k].d;
                else if  (direction % 2 != graph[i][j][k].d % 2) check = false;
            }
            sum /= 5;
            velocity /= graph[i][j].size();
            if (sum) {
                if (check) {
                    tempV.push_back({i,j,sum,velocity,0});
                    tempV.push_back({i,j,sum,velocity,2});
                    tempV.push_back({i,j,sum,velocity,4});
                    tempV.push_back({i,j,sum,velocity,6});
                }
                else {
                    tempV.push_back({i,j,sum,velocity,1});
                    tempV.push_back({i,j,sum,velocity,3});
                    tempV.push_back({i,j,sum,velocity,5});
                    tempV.push_back({i,j,sum,velocity,7});
                }
            }
        }
    }

    v.clear();
    for (int i = 0; i < tempV.size(); i ++) {
        v.push_back(tempV[i]);
    }

    // int cnt = 0;
    // for (int i = 0; i < v.size(); i ++) {
    //     cnt += v[i].m;
    // }
    // cout << "Debug = " << cnt << '\n';

    // for (int i = 1; i <= N; i ++) {
    //     for (int j = 1; j <= N; j ++) {
    //         if (graph[i][j].size() == 0) {
    //             cout << '0' << ' ';
    //         }
    //         else {
    //             for (int k = 0; k < graph[i][j].size(); k ++) {
    //                 cout << graph[i][j][k].m << ' ';
    //             }
    //         }
    //     }
    //     cout << '\n';
    // }
    // cout << '\n';
}

void Simulation() {
    MoveFireBall();
    DividFireBall();
}


int main()
{   
    cin >> N >> M >> K;
    for (int i = 0; i < M; i ++) {
        int x, y, m, s, d;
        cin >> x >> y >> m >> s >> d;
        FireBall fireball = {x, y, m, s, d};
        v.push_back(fireball);
    }

    while(K--) {
        Simulation();
    }

    int result = 0;
    for (int i = 0; i < v.size(); i ++) {
        result += v[i].m;
    }

    cout << result << '\n';

    return 0;
}