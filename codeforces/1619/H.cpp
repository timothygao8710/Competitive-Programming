//@timothyg

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back

#define f first
#define s second

const int block = 290;
const int maxn = 1e5 + 243;
vector<int> rnums(maxn), nums(maxn), forw(maxn), back(maxn), where(maxn); //jumps block steps in front of i each iteration

int run(int x, int step){
    return step == 0 ? x : run(nums[x], step-1);
}

vector<int> go(int x, int step, int type = 0){//0 - forw, 1 - back
    vector<int> go(step+1); go[0] = x;
    for(int i = 1; i<=step; i++){   
        if(type == 0){
            go[i] = nums[go[i-1]];
        }else{
            go[i] = rnums[go[i-1]];
        }
    }   
    return go;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int N, Q; cin >> N >> Q;
    for(int i = 0; i<N; i++){
        cin >> nums[i]; nums[i]--; where[nums[i]] = i;
        rnums[nums[i]] = i;
    }    
    for(int i = 0; i<N; i++){
        forw[i] = run(i, block);
    }
    while(Q--){
        int t; cin >> t;
        if(t == 1){ //swap px, py
            int x, y; cin >> x >> y; x--, y--; 
            rnums[nums[x]] = y, rnums[nums[y]] = x;
            swap(nums[x], nums[y]);

            vector<int> xl = go(x, block, 1), xr = go(x, block), yl = go(y, block, 1), yr = go(y, block);
            for(int i = 0; i<=block; i++){
                // cout << xl[i] << " " << yr[i] << endl;
                forw[xl[i]] = xr[block - i];
                forw[yl[i]] = yr[block - i];
            }
            // rnums[x] = y, rnums[y] = x;
            
        }else{
            int i, k; cin >> i >> k; i--;
            while(k >= block){
                i = forw[i]; k -= block;
            }
            cout << (1+run(i, k)) << '\n';
        }
        // for(int i = 0; i<N; i++) cout << forw[i] << " ";
        // cout << endl;
    }
    return 0;
}
