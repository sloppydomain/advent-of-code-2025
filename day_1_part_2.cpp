
#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int start = 50;
	string in;
	long long ans = 0;
	while (cin >> in) {
		long long rotate = stoll(in.substr(1));
		if (in[0] == 'L') {
			if (start - rotate <= 0) {
				ans += (rotate - start) / 100 + (start > 0);
			}
			start = (start - rotate % 100 + 100) % 100;
		} else {
			if (start + rotate >= 100) {
				ans += (rotate - (100 - start)) / 100 + 1;
			}
			start = (start + rotate % 100) % 100;
		}
	}
	cout << ans << '\n';
	return 0;
}