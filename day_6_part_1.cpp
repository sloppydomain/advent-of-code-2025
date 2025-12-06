#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  string in;
  vector<string> nums;
  vector<string> sym;
  while (cin >> in) {
    if (in == "*" || in == "+") {
      sym.push_back(in);
    } else {
      nums.push_back(in);
    }
  }
  int m = sym.size(), n = nums.size();
  int64_t ans = 0;
  for (int i = 0; i < m; i++) {
    int64_t cur = (sym[i] == "*"); 
    for (int j = i; j < n; j += m) {
      int64_t val = stoll(nums[j]);
      if (sym[i] == "+") {
        cur += val;     
      } else {
        cur *= val;    
      }
    }
    ans += cur;
  }
  cout << ans;
  return 0;
}
