#include <bits/stdc++.h>
using namespace std;

int main() {
	int t, c, o, d, i;
	const int t0 = 4, c0 = 6, o0 = 8, d0 = 12, i0 = 20;
	cin >> t >> c >> o >> d >> i;
	int l = t + c + o + d + i;
	int r = t * t0 + c * c0 + o * o0 + d * d0 + i * i0;
	if ((r + l) % 2 == 1) {
		int mid1 = (r + l) / 2;
		int mid2 = (r + l) / 2 + 1;
		cout << mid1 << " " << mid2;
		while (mid1 != l) {
			mid1--;
			mid2++;
			cout << " " << mid1 << " " << mid2;
		}
	} else {
		int mid1 = (r + l) / 2;
		int mid2 = mid1;
		cout << mid1;
		while (mid1 != l) {
			mid1--;
			mid2++;
			cout << " " << mid1 << " " << mid2;
		}
	}
	cout << "\n";
	return 0;
}
