//Author: timg8710

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, int> pii;
 
#define pb push_back
 
#define f first
#define s second
const int maxn = 2e5 + 1;
vector<int> adj[maxn];
int dp[maxn][5]; //dist from root

int dfs(int u, int p = 0, int state = 0){
  if(dp[u][state] != 0) return dp[u][state];
  dp[u][4] = 1; int best = 1;
  for(int n : adj[u]){
    if(n == p) continue;
    dp[u][4] += dfs(n, u, 2);
    dp[u][3] += dfs(n, u, 3);
    dp[u][2] += dfs(n, u, 3);
    dp[u][1] += dfs(n, u, 2);
    dp[u][0] += dfs(n, u, 1);
    best = min(best, dp[n][4]-dp[n][3]);
  }
  dp[u][3] += best;
  assert(dp[u][3] > 0);
  // if(u == 4) cout << u << " " << dp[u][0] << " " << dp[u][1] << " " << dp[u][2] <<  " " << dp[u][3] << " " << dp[u][4] << endl;
  for(int i = 0; i<5; i++) dp[u][i] = min(dp[u][i], dp[u][4]);
  assert(dp[u][0] <= dp[u][1] && dp[u][1] <= dp[u][2] && dp[u][2] <= dp[u][3] && dp[u][3] <= dp[u][4]);
  // cout << u << " " << dp[u][0] << " " << dp[u][1] << " " << dp[u][2] <<  " " << dp[u][3] << endl;
  return dp[u][state];
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  int N, u, v; cin >> N;
  for(int i = 0; i<N-1; i++){
    cin >> u >> v; adj[u].pb(v); adj[v].pb(u);
  }
  cout << dfs(1);
  // cout << dp[5][3] << " " << dp[6][3] << endl;
  return 0;
}
/*
10
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 9
9 10
*/