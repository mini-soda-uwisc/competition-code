#include <bits/stdc++.h>
using namespace std;

int n, c;
multiset<int> s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> c;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		s.insert(x);
	}

	int ans = 0;
	while (!s.empty()) {
		++ans;
		auto it = prev(s.end());
		s.erase(it);
		// cerr << "find: " << *it << '\n';
		auto itp = s.upper_bound(c - *it);
		if (itp != s.begin()) {
			--itp;
			if (itp != it) {
				// cerr << "combined with " << *itp << '\n';
				s.erase(itp);
			}
		}

	}

	cout << ans << '\n';
	return 0;
}
