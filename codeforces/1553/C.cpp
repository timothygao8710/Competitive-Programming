//Author: timg8710

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, int> pii;
 
#define pb push_back
 
#define f first
#define s second

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  int T; cin >> T;
  while(T--){
    string s; cin >> s;
    int best[2][2]; best[0][0] = best[0][1] = best[1][0] = best[1][1] = 0;
    int idx = 0;
    for(int i = 0; i<10; i++){
      best[0][i%2] += (s[i] == '1');
      best[1][i%2] += (s[i] == '1' || s[i] == '?');
    }
    // cout << best[0][0] << " " << best[1][0] << endl;
    // cout << best[0][1] << " " << best[1][1] << endl;
    int par[2] = {0, 0};
    int run[2][2]; run[0][0] = run[0][1] = run[1][0] = run[1][1] = 0;
    for(; idx < 10; idx++){
      par[idx%2]++;
      run[0][idx%2] += (s[idx] == '1');
      run[1][idx%2] += (s[idx] == '1' || s[idx] == '?');
      int a = 0, b = 1;
      // if(best[0][a] - run[0][a] + run[1][a] > best[1][b] - run[1][b] + run[0][b]){
      //   idx++; cout << "BRO" << endl; break;
      // }
      // swap(a, b);
      // if(best[0][a] - run[0][a] + run[1][a] > best[1][b] - run[1][b] + run[0][b]){
      //   idx++; cout << "SWAPPED" << endl; break;
      // } what tf are these garbage problem statements -_-

      if(run[1][a] > 5 - par[b] + run[0][b]){
        idx++; break;
      }
      swap(a, b);
      if(run[1][a] > 5 - par[b] + run[0][b]){
        idx++; break;
      }
    }
    cout << idx << '\n';
  }
  return 0;
}
