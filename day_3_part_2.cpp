#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int64_t ans = 0;
	string s;
	while (cin >> s) {
		const int d = 12;
		vector<int64_t> p10(d);
		p10[0] = 1;
		for (int i = 1; i < d; i++) {
			p10[i] = p10[i - 1] * 10;
		}
		int n = s.size();
		vector<vector<int64_t>> dp(d, vector<int64_t>(n, 0));
		int64_t mx = 0;
		for (int i = 0; i < d; i++) {
			if (i == 0) {
				dp[i][n - 1] = s[n - 1] - '0';
				for (int j = n - 2; j >= 0; j--) {
					dp[i][j] = max(dp[i][j + 1], int64_t(s[j] - '0'));
				}
				continue;
			} 
			for (int j = n - (i + 1); j >= 0; j--) {
				dp[i][j] = max(dp[i][j + 1], p10[i] * (s[j] - '0') + (dp[i - 1][j + 1]));
				if (i == d - 1) mx = max(mx, dp[i][j]);
			}
		}
		ans += mx;
	}
	cout << ans << '\n';
	return 0;
}