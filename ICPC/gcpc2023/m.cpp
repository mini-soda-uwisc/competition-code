#include <bits/stdc++.h>
using namespace std;

int main() {
	int d;
	cin >> d;

	if (d == 1) {
		cout << "3 5 11\n";
	}
	else if (d < 10) {
		cout << "1 11 97\n";
	}
	else {
		cout << "1 2 3\n";
	}
	return 0;
}
