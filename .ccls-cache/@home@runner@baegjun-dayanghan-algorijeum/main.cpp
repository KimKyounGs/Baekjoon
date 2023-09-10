/*
아이디어 : 

0을 생각 못했다. 
항상 나누기가 나오면 0을 생각하자.
나머지는 쉽다.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

int N;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
    cin >> N;
    if (N == 0) {
        cout << 0 << '\n';
        return 0;
    }
    for (int i = 0; i < N; i ++) {
        int n;
        cin >> n;
        v.push_back(n);
    }

    sort(v.begin(), v.end());

    //cout << "ss : " << (double)N*15/100 << '\n';
    
    int value = round((double)N*15/100);

    //cout << "value : " << value << '\n';

    int start = value;
    int end = N-value;

    long long sum = 0;
    for (int i = start; i < end; i ++) {
        sum += v[i];
    }

    //cout << "sum : " << sum << '\n';
    //cout << (double)sum/(N-value*2) << '\n';

    cout << round((double)sum/(N-value*2)) << '\n';
}
