//Author: timg8710

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, int> pii;
 
#define pb push_back
 
#define f first
#define s second
//way to easy to overcomplicate this shit
int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  int T, N, K; cin >> T;
  while(T--){
    cin >> N >> K;
    ll nums[N]; ll ret = LLONG_MIN;
    for(int i = 0; i<N; i++){
      cin >> nums[i];
      for(ll j = max(0,i-202); j<i; j++){
        ret = max(ret, (1+i)*(1+j) - K*(nums[i]|nums[j]));
      }
    }
    cout << ret << '\n';
  }
  return 0;
}
