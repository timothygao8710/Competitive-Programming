//@timothyg

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back

#define f first
#define s second

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while(T--){
        int N; cin >> N;
        map<char, vector<char>> vf, vs;
        for(int i = 0; i<N; i++){
            string a; cin >> a;
            vf[a[0]].pb(a[1]);
            vs[a[1]].pb(a[0]);
        }

        ll ret = 0;
        for(auto i : vf){
            ll tot = i.s.size();
            vector<int> cnt(26);
            for(char j : i.s){
                cnt[j-'a']++;
            }
            for(int j = 0; j<26; j++){
                ret += (tot - cnt[j]) * cnt[j];
            }
        }
        for(auto i : vs){
            ll tot = i.s.size();
            vector<int> cnt(26);
            for(char j : i.s){
                cnt[j-'a']++;
            }
            for(int j = 0; j<26; j++){
                ret += (tot - cnt[j]) * cnt[j];
            }
        }
        cout << ret/2 << '\n';
    }   
    return 0;
}
