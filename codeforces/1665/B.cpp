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
        int freq = 0, num;
        map<int, int> mp;
        for(int i = 0; i<N; i++){
            int a; cin >> a;
            mp[a]++;
            if(mp[a] > freq){
                freq = mp[a]; num = a;
            }
        }
        int free = 0, have = freq, ret = 0;
        while(have < N){
            if(free == 0){  
                free += have; ret++;
            }
            have++, free--; ret++;
        }
        cout << ret << '\n';
    }    
    return 0;
}
