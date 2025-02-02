#include <bits/stdc++.h>
using namespace std;

#define int long long

int n;

int count(int d) {
	int length = 0;
	int tmp = 0;
	while (true) {
		tmp = tmp * 10 + d;
		++length;
		if (tmp > n) {
			--length;
			break;
		}
	}

	return length;
}

signed main() {
	cin >> n;
	int ans = 0;
	for (int i = 1; i <= 9; ++i) {
		// cout << "ans of " << i << ": " << count(i) << '\n';
		ans += count(i);
	}

	string t = to_string(n);
	ans += (long long)t.length() - 1ll;

	if (n < 10) ans += 1ll;
	cout << ans << '\n';
	return 0;
}