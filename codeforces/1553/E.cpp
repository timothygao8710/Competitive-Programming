//Author: timg8710

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, int> pii;
 
#define pb push_back
 
#define f first
#define s second
//0-indxed
int needs(vector<int>& nums){
    vector<int> vis; vis.resize(nums.size());
    int ret = 0;
    for(int i = 0; i<nums.size(); i++){
        if(vis[i]) continue;
        int p = i;
        while(nums[p] != i){
            p = nums[p]; ret++;
            vis[p] = 1;
        }
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while(T--){
        int N, M, u, must; cin >> N >> M;
        must = N - 2*M;
        vector<int> shifts(N), point(N); 

        for(int i = 0; i<N; i++){
            cin >> u; point[u-1] = i;
        }
        for(int i = 0; i<N; i++){
            shifts[
                (N + point[i] - i)%N
            ]++;
        }
        vector<int> ret;
        for(int i = 0; i<N; i++){
            if(shifts[i] >= must){
                vector<int> temp;
                for(int j = N-i; j<N; j++){
                    temp.pb(point[j]);
                }
                for(int j = 0; j<N-i; j++){
                    temp.pb(point[j]);
                }
                if(needs(temp) <= M){
                    ret.pb(i);
                }
            }
        }
        cout << ret.size() << " ";
        for(int i : ret){
            cout << i << " ";
        }
        cout << '\n';
    }
    return 0;
}
