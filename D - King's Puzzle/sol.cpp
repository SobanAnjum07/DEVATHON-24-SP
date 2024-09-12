#include <bits/stdc++.h>
using namespace std;

void solve() {
  long long n;
  cin >> n;
  long long lo = 1, hi = 1e9;
  bool ok = false;
  while (lo <= hi) {
    long long mid = (lo + hi) / 2;
    if (mid * (mid + 1) / 2 == n) {
      ok = true;
      break;
    } else if (mid * (mid + 1) / 2 > n) {
      hi = mid - 1;
    } else {
      lo = mid + 1;
    }
  }
  cout << (ok ? "yes" : "no") << endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);  
  int q;
  q = 1;  
  cin >> q;
  while (q--) {
    solve();
  }
}