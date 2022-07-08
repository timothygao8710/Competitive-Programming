//@timothyg

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back

#define f first
#define s second

bool ok(int hours, int N, vector<int>& each){
    ll openWork = 0;
    ll openJobs = 0;
    for(int i = 0; i<N; i++){
        int sz = each[i];
        if(hours > sz){
            openWork += (hours - sz)/2;
        }else{
            openJobs += sz - hours;
        }
    }
    return openWork >= openJobs;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while(T--){
        int N, M; cin >> N >> M;
        vector<int> each(N);
        for(int i= 0; i<M; i++){
            int a; cin >> a; --a; each[a]++;
        }
        int l = 1, r = 1e9;
        while(l < r){
            int mid = (l + r)/2;
            if(ok(mid, N, each)){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        cout << r << '\n';
    }    
    return 0;
}
