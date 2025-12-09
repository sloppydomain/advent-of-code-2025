#include <bits/stdc++.h>

using namespace std;

class dsu {
public:
  vector<int> p, sz;
  int n;
  dsu(int _n) : n(_n) {
    p.resize(n, -1);
    sz.resize(n, 1);
    for (int i = 0; i < n; ++i) {
      p[i] = i;
    }
  }
 
  inline int get(int v) {
    if (v == p[v]) {
      return v;
    }
    return p[v] = get(p[v]);
  }
 
  inline void unite(int u, int v) {
    int rootu = get(u);
    int rootv = get(v);
    if (rootu != rootv) {
      if (sz[rootu] < sz[rootv]) {
        swap(rootu, rootv);
      }
      p[rootv] = rootu;
      sz[rootu] += sz[rootv];
    }
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  vector<vector<int>> points; 
  while (cin >> s) {
    string p = "";
    vector<int> cord;
    for (char c : s) {
      if (c == ',') {
        cord.push_back(stoi(p));
        p.clear();
      } else {
        p.push_back(c);
      }
    }
    cord.push_back(stoi(p));
    points.push_back(cord);
  }
  int n = points.size();
  auto getd = [&](vector<int>& p1, vector<int>& p2) -> double {
    double dx = double(p1[0]) - double(p2[0]);
    double dy = double(p1[1]) - double(p2[1]);
    double dz = double(p1[2]) - double(p2[2]);
    return sqrt(dx * dx + dy * dy + dz * dz);
  };
  map<vector<int>, int> id;
  int next = 0;
  for (auto &v : points) {
    if (id.count(v) == 0) {
      id[v] = next++;
    }
  }
  dsu dis(next);
  priority_queue<vector<double>, vector<vector<double>>, greater<vector<double>>> pq;
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      pq.push({getd(points[i], points[j]), (double) id[points[i]], (double) id[points[j]]});
    }
  }
  int taken = 0;
  while (taken < 1000 && pq.size()) {
    auto v = pq.top();
    pq.pop();
    int id1 = v[1];
    int id2 = v[2];
    if (dis.get(id1) != dis.get(id2)) {
      dis.unite(id1, id2);
    }
    taken++;
  }
  vector<int> sz;
  vector<vector<int>> b(next);
  for (int i = 0; i < next; i++) {
    if (dis.get(i) == i) sz.push_back(dis.sz[i]);
    b[dis.get(i)].push_back(i);
  }
  sort(sz.rbegin(), sz.rend());
  long long ans = 1;
  for (int i = 0; i < min(3, (int) sz.size()); i++) {
    ans *= sz[i];
  }
  cout << ans;
  return 0;
}