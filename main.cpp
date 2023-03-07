/*
# 아이디어 

23.3.7

참고 https://cocoon1787.tistory.com/396

누적합 + 수학적 지식을 요구하는 문제이다.
어려워서 찾아봤음..

*/
#include <iostream>

using namespace std;

int N, M;
long long result;
unsigned long long sum;
long long modul[1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    
    for (int i = 1; i <= N; i ++) {
        int n;
        cin >> n;
        sum += n;
        modul[sum % M] ++;
    }


	for (int i = 0; i <= M; i++)
	{
        result += (modul[i] * (modul[i]-1)) / 2;
	}
    
    cout << result + modul[0] << '\n';

}