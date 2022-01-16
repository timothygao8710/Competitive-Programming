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
  int T, N; cin >> T; string s, t;
  while(T--){
    cin >> s >> t;
    vector<pii> step;
    for(int i = 0; i<s.length(); i++){
      step.pb(pii(i, 1));
    }

    for(int i = 0; i<t.length(); i++){
      // for(auto j : step){
      //   cout << j.f << " " << j.s << endl;
      // }
      // cout << endl;
      vector<pii> next;
      map<pii, bool> has;
      for(auto j : step){
        if(j.f < 0 || j.f >= s.length() || s[j.f] != t[i]) continue;
        pii same = pii(j.f+j.s, j.s);
        pii diff = pii(j.f-j.s, j.s*-1);
        if(!has[same]){
          has[same] = true; next.pb(same);
        }
        if(!has[diff] && diff.s == -1){
          has[diff] = true; next.pb(diff);
        }
      }
      swap(next, step);
    }
    cout << (step.empty() ? "NO" : "YES") << '\n';
  }
  return 0;
}
