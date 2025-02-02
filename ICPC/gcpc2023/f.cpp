#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ld = long double;
using ll = long long;

#define pb push_back

const ld pi = 3.14159265358979323846;
const int mod = 998244353;
const ll INF = 1e18;

template<typename T>
T chmax(T a, T b){
	return a > b ? a : b;
}

template<typename T>
T chmin(T a, T b){
	return a > b ? b : a;
}

const int N = (int)2e5 + 1, M = N * 10;

void solve(){
	int n, m;
	cin >> n >> m;

	int qwq = 0;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;

		int h = m - x;
		if(qwq > h){
			cout << "impossible" << endl;
			return;
		}
		if((h - qwq) % 2){
			qwq++;
		}
		else{
			qwq--;
		}
		qwq = chmax(qwq, 0);
	}

	cout << (!qwq ? "possible" : "impossible") << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t = 1;
	// cin >> t;

	while(t--){
		solve();
	}

	return 0;
}