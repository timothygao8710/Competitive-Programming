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
    map<int, vector<int>> all;
    int K, N;
    // cin >> N;
     cin >> N >> K;
    // K = 2;
    int ret[N]; fill(ret, ret+N, 0);
    for(int i = 0; i<N; i++){
      int x; cin >> x;
      all[x].pb(i);
    }  
    vector<int> extras;
    for(auto i : all){
      if(i.s.size() >= K){
        for(int j = 0; j<K; j++){
          ret[i.s[j]] = j+1;
        }
      }else{
        for(int j : i.s){
          extras.pb(j);
        }
      }
    }
    for(int i = 0; i<extras.size(); i+=K){
      if(i + K > extras.size()) break;
      for(int j = 0; j<K; j++){
        // assert(i+j < extras.size());
        // cout << i  << " "  << j << " " << extras.size() << endl;
        // assert(i+j < extras.size());
        // assert(extras[i+j] < N);
                ret[extras[i+j]] = j+1;
      }
    }
    // cout << "GSDF" << " " << am << endl;
    for(int i : ret){
      cout << i << " ";
    }
    cout << '\n';
  }
  return 0;
}
/*
1

*/