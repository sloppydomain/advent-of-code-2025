#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<string> nums;
  string s;
  int col = -1;
  while (getline(cin, s)) {
    nums.push_back(s);
    col = max(col, (int) s.size());
  }
  int row = nums.size();
  string sym = "";
  vector<int64_t> ans;
  for (char c : nums[row - 1]) {
    if (c == '+' || c == '*') {
      sym.push_back(c);
      ans.push_back(c == '*');
    }
  }
  nums.pop_back();
  row--;
  int m = sym.size();
  int k = 0;
  for (int j = 0; j < col; j++) {
    string f = "";
    for (int i = 0; i < row; i++) {
      if (j < (int) nums[i].size()) {
        f.push_back(nums[i][j]);
      }
    }
    f.erase(remove(f.begin(), f.end(), ' '), f.end());
    if (f.empty()) {
      ++k;
    } else {
      int64_t cur = stoll(f); 
      if (sym[k] == '*') {
        ans[k] *= cur;
      } else {
        ans[k] += cur;
      }
    }
  }
  cout << accumulate(ans.begin(), ans.end(), 0LL);
  return 0;
}
