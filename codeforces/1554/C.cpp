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
  int T, N, M; cin >> T;
  while(T--){
    cin >> N >> M;
    int ret = 0;
    for(int i = 30; i>=0; i--){
      if((N>>i)%2){
        M -= (1 << i); ret += (1 << i); continue;
      }
      if((1<<i)-1 <= M){
        ret += (1 << i); M -= (1 << i);
      }
    }
    cout << (ret ^ N) << '\n';
  }  
  return 0;
}
