#include <bits/stdc++.h>
using namespace std;
 
const int MOD = 1e9 + 7;
const int MOD1 = 998244353;
 
#define debug(x) cout << #x << " " << x << endl;

void solve() {
  int n;
  cin >> n;
  if (n < 5) {
    cout << (n) * (n - 1) / 2 << endl;
  } else {
    int need;
    if (n < 50) {
      need = 1;
    } else if (n < 500) {
      need = 2;
    } else if (n < 5000) {
      need = 3;
    } else if (n < 50000) {
      need = 4;
    } else if (n < 500000) {
      need = 5;
    } else if (n < 5000000) {
      need = 6;
    } else if (n < 50000000) {
      need = 7;
    } else if (n < 500000000) {
      need = 8;
    } else {
      need = 9;
    }
    string s = "";
    for (int i = 0; i < need; i++) {
      s += '9';
    }
    auto compute = [&](long long x)-> long long {
      // debug(x);
      long long lo = 1, hi = x / 2;
      long long ans = hi + 1;
      while (lo <= hi) {
        long long mid = (lo + hi) / 2;
        if (n >= x - mid) {
          ans = min(ans, mid);
          hi = mid - 1;
        } else {
          lo = mid + 1;
        }
      }
      if (ans == x / 2 + 1) return 0;
      return (x / 2) - ans + 1;
    };
    long long ans = 0;
    for (int i = 0; i < 10; i++) {
      if (i == 0) {
        ans += compute(stoll(s));
        continue;
      }
      string t = char ('0' + i) + s;
      long long val = compute(stoll(t));
      ans += val;
    }
    cout << ans << endl;
  }
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