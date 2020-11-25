#include <bits/stdc++.h>
using namespace std;
vector<double> ans, op;
int main(int argc, char **argv) {
  int n, m, k;
  cin >> n >> k >> m;
  for (int i = 1; i <= n; i++) {
    vector<int> now;
    for (int j = 1, t; j <= k; j++) {
      cin >> t;
      now.emplace_back(t);
    }
    sort(now.begin(), now.end());
    ans.emplace_back(accumulate(now.begin() + 1, now.end() - 1, 0) * 1.0 / (k - 2));
  }
  sort(ans.begin(), ans.end(), greater<double>());
  for (int i = 0; i < m; i++) op.emplace_back(ans[i]);
  reverse(op.begin(), op.end());
  for (int i = 0; i < m; i++)
    printf(i == m - 1 ? "%.3lf" : "%.3lf ", op[i]);
  return 0;
}