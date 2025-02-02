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

const int N = (int)2e5 + 1, M = N * 2;

void solve(){
	string s;
	cin >> s;

	int n = s.size();
	vector<int> pref(n + 1), suf(n + 2);

	string ds = s;
	s = '#' + s;

	string t = "";
	map<string, int> v;
	for(int i = 1; i <= n; i++){
		pref[i] = pref[i - 1] + (s[i] == '(' ? 1 : -1);
		t += s[i];
		if(pref[i] == 0){
			v[t]++;
			t = "";
		}
	}

	if(v.size() <= 1){
		cout << "no" << endl;
		return;
	}

	for(int i = n; i >= 1; i--){
		suf[i] = suf[i + 1] + (s[i] == ')' ? 1 : -1);
	}

	for(int i = 2; i <= n - 1; i++){
		if(pref[i] == 0 && suf[i + 1] == 0){
			string t = s.substr(i + 1, n - i) + s.substr(1, i);
			cout << t << endl;
			return;
		}
	}
	cout << "no" << endl;
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