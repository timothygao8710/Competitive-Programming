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
        vector<int> nums(N); 
        vector<int> ret(0);
        set<int> all;
        queue<pii> list;
        for(int i = 0; i<N; i++){
            cin >> nums[i];
            all.insert(i);
        }
        for(int i = 0; i<N; i++){
            if(gcd(nums[(i+1)%N], nums[i]) == 1){
                list.push(pii(i, (i+1)%N));
            }
        }

        while(!list.empty() && ret.size() < N){
            pii cur = list.front(); list.pop();
            if(!all.count(cur.f)) continue;
            ret.pb(cur.s);
            if(ret.size() == N) break;
            all.erase(cur.s);
            if(*(--all.end()) == cur.f){
                int loop = *(all.begin());
                if(gcd(nums[loop], nums[cur.f]) == 1){
                    list.push(pii(cur.f, loop));
                }
            }else{
                int nxt = *(all.upper_bound(cur.f));
                //cout << cur.f <<  " "<< nxt << endl;
                if(gcd(nums[nxt], nums[cur.f]) == 1){
                    list.push(pii(cur.f, nxt));
                }
            }
        }  
        cout << ret.size() << " ";
        for(int i : ret){
            cout << (1+i) << " ";
        }  
        cout << endl;
        
    }
    return 0;
}
