/*
# 아이디어 

5 3
1 2 3 1 2

sum
1 3 6 7 9 --> 3개




1, 1+2, 1+2+3, 1+2+3+4, 1+2+3+4+5




sum 
1. 1 3 6 7 9
2.   2 5 6 7
3.     3 4 6
4.       1 3
5.         2


*/
#include <iostream>

using namespace std;

int N, M;
int result;
unsigned long long sum[100001];


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    for (int i = 1; i <= N; i ++) {
        int n;
        cin >> n;
        sum[i] = sum[i-1] + n;
        if (sum[i] % M == 0) result ++;
    }


	for (int i = 0; i <= 1000; i++)
	{
		result += sum[i] * (sum[i] - 1) / 2;
	}
    
    cout << result << '\n';

}