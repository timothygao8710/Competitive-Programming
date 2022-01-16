//Author: timg8710

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
 
#define pb push_back
 
#define f first
#define s second
//interesting problem!
int mod = (int)(1e9+7);
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while(T--){
        int N; cin >> N;
        int nums[2][N];
        int each[N][2];
        for(int i = 0; i<N; i++) for(int j= 0; j<2; j++) each[i][j] = -1;
        for(int i =0; i<2; i++){
            for(int j= 0; j<N; j++){
                cin >> nums[i][j]; nums[i][j]--;
                if(each[nums[i][j]][0] == -1){
                    each[nums[i][j]][0] = j;
                }else{
                    each[nums[i][j]][1] = j;
                }
            }
        }
        int ret = 0;
        bool vis[N]; memset(vis, false, sizeof(vis));
        for(int i = 0; i<N; i++){
            if(vis[i]) continue; vis[i] = true; ret++;
            int next = nums[1][i]; int idx = i;
            while(next != nums[0][i]){
                int otheridx = 0;
                if(each[next][0] == idx) otheridx ^= 1;
                idx = each[next][otheridx]; vis[idx] = true;
                for(int k = 0; k<2; k++){
                    if(nums[k][idx] != next) next = nums[k][idx];
                }
            }
        }
        ll wiz = 1;
        for(int i = 0; i<ret; i++){
            wiz = (wiz*2)%mod;
        }
        cout << wiz << "\n";
    }    
    return 0;
}
