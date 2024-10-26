#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int maxN = 5008;

int n;
int dp[maxN][maxN];
vector<int> a(1), b;
vector<int> ans;

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		if (x != a.back()) a.push_back(x);
	}
	n = a.size() - 1;

	b = a;
	reverse(b.begin() + 1, b.end());
}

void solve() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (a[i] == b[j]) {dp[i][j] = dp[i-1][j-1] + 1;}
			else {dp[i][j] = max(dp[i-1][j], dp[i][j-1]);}
		}
	}
}

void output() {
	cout << n - (dp[n][n] + 1)/2 << '\n';
}

int main() {
	
	input();
	solve();
	output();
	
	return 0;
}

