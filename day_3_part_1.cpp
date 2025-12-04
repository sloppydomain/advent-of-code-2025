#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	string s;
	int ans = 0;
	while (cin >> s) {
		int n = s.size();
		string t = s;
		for (int i = n - 2; i >= 0; i--) {
			t[i] = max(t[i + 1], t[i]);
		}
		int mx = 0;
		for (int i = 0; i < n; i++) {
			int num = (s[i] - '0') * 10 + (t[i + 1] - '0');
			mx = max(mx, num);
		}
		ans += mx;
	} 
	cout << ans << '\n';
	return 0;
}