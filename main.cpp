


/*
//문제
정수의 연산식을 입력받아 연산을 위한 함수를 호출하여

4칙연산(+ - * /)의 연산결과를 출력하는 프로그램을 작성하시오.

('/'의 경우는 정수 부분만 출력하고 4칙연산 이외의 연산 결과는 0으로 한다.)
( if_else 문으로 작성하세요.)

//입력
10 + 20
//출력
10 + 20 = 30

//입력
10 - 20
//출력
10 - 20 = -10

*/



/*
//문제
완전수란 자기 자신을 제외한 양의 약수를 더했을때 자기 자신이 되는 양의 정수를 말한다.
예를들어 6의 경우, 약수가 1,2,3이므로 1+2+3=6이 되어서 완전수이다.

수를 입력받아 완전수인지 판단해주는 함수를 작성하시오.
(함수는 int자료형(true이면 1, false이면 0)을 반환해준다) 

//입력
6
//출력
6은 완전수이다. 

//입력
7
//출력
7은 완전수가 아니다. 
*/

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

int N, K;
int graph[500001];
int brother[500001];
bool bResult = false;

int Cal(int num)
{
    return K+((num*(1+num))/2);
}

void BFS(int x)
{
    queue<int> q;
    q.push({x});
    graph[x] = 0;

    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        // 동생을 찾음
        if (x == Cal(graph[x]))
        {
            bResult = true;
            cout << graph[x] << endl;
            return;
        }

        // 곱하기
        if (2*x <= 500000 || graph[2*x] == -1)
        {
            graph[2*x] = graph[x]+1;
            q.push(2*x);
            cout << "곱하기 " << 2*x << endl;
        }
        // 더하기
        if (x+1 <= 500000 || graph[x+1] == -1) 
        {
            graph[x+1] = graph[x]+1;
            q.push(x+1);
            cout << "더하기 " << x+1 << endl;
        }
        // 빼기
        if (x-1 >= 0 || graph[x-1] == -1)
        {
            graph[x-1] = graph[x]+1;
            q.push(x-1);
            cout << "빼기 " << x-1 << endl;
        }
    }
}

int main()
{
    cin >> N >> K;
    if (N == K) 
    {
        cout << 0 << endl;
        return 0;
    }

    memset(graph, -1, sizeof(graph));
    BFS(N);
    if (!bResult)
    {
        cout << -1 << endl;
    }
}