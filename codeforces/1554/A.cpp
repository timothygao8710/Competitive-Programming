// //Author: timg8710

// #include <bits/stdc++.h>
 
// using namespace std;
 
// typedef long long ll;
// typedef pair<ll, ll> pii;
 
// #define pb push_back
 
// #define f first
// #define s second

// int main(){
//   ios_base::sync_with_stdio(false); cin.tie(0);
//   int T, N; cin >> T;
//   while(T--){
//     cin >> N; ll ret = 0;
//     vector<pii> nums(N), og(N);
//     for(int i = 0; i<N; i++){
//       cin >> nums[i].f; nums[i].s = i;
//       og[i] = nums[i];
//     }
//     sort(nums.begin(), nums.end());
//     set<pii> bars; bars.insert(pii(-1, 0)); bars.insert(pii(N, 0));
//     int l = 0, r = N-1;
//     while(l <= r){
//       pii lb = *(--bars.lower_bound(pii(nums[l].s, 69)));
//       pii rb = *bars.upper_bound(pii(nums[l].s, 69));
//       if(lb.s == 1){
//         ret += (lb.f+1)*(N - nums[l].s) * og[lb.f].f * nums[l].f;
//       }
//       if(rb.s == 1){
//         ret += (N - rb.f) * (nums[l].s+1) * og[rb.f].f * nums[l].f;
//       }
//       bars.insert(pii(nums[l].s, -1)); l++;
//       if(l > r) break;
//       lb = *(--bars.lower_bound(pii(nums[r].s, 69)));
//       rb = *bars.upper_bound(pii(nums[r].s, 69));
//       if(lb.s == -1){
//         ret += (lb.f+1)*(N - nums[r].s) * og[lb.f].f * nums[r].f;;
//       }
//       if(rb.s == -1){
//         ret += (N - rb.f) * (nums[r].s+1) * og[rb.f].f * nums[r].f;
//       }
//       bars.insert(pii(nums[r].s, 1)); r--;
//     }
//     cout << ret << '\n';
//   }  
//   return 0;
// }
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
    int N; cin >> N;
    vector<pii> nums(N), og(N);
    for(int i = 0; i<N; i++){
      cin >> nums[i].f; nums[i].s = i;
      og[i] = nums[i];
    }
    sort(nums.begin(), nums.end());
    ll ret = 0;
    for(int i = N-1; i>=0; i--){
      if(nums[i].s + 1 < N){
        ret = max(ret, og[nums[i].s + 1].f * nums[i].f);
      }
      if(nums[i].s -1 >=0 ){
        ret = max(ret, og[nums[i].s-1].f * nums[i].f);
      }
    }
    cout << ret << '\n';
  }  
  return 0;
}
