#include <bits/stdc++.h>
using namespace std;
 
int N, dp[600][600];
 
int main() {
	cin >> N;
	string a;
    cin >> a;
	for (int i = N-1; i >= 0; --i) 
		for (int j = i+1; j < N; ++j) {
			if (a[i] == a[j]) // draw segment from i to j
				dp[i][j] = max(dp[i][j],1+dp[i+1][j-1]);
			for (int k = i+1; k < j; ++k) // split at k
				dp[i][j] = max(dp[i][j],dp[i][k]+dp[k][j]);
		}
	cout << N-dp[0][N-1] << "\n";
}