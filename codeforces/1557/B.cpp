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
    int N, K; cin >> N >> K;
    vector<int> nums(N), sorted(N);
    for(int i = 0; i<N; i++){
      cin >> nums[i];
      sorted[i] = nums[i];
    }
    sort(sorted.begin(), sorted.end());
    map<int, int> mp;
    for(int i = 0; i<N; i++){
      mp[sorted[i]] = i;
    }
    int sadge = 0;
    for(int i = 0; i<N;){
      int j = i, k = mp[nums[i]];
      while(j < N && k < N && nums[j] == sorted[k]){
        j++; k++; 
      }
      i = j;
      sadge++;
    }
    
    cout << (sadge <= K ? "Yes" : "No") << '\n';
  }
  return 0;
}
