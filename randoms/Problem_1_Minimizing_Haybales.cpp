//@timothyg

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back

#define f first
#define s second

int K, N;

struct bucket{
    vector<int> vals;
    int mx = 0, mn = 1e9+8;
    bool add(int v, bool must = false){
        int n = (int)vals.size();
        int last = n;
        for(int i = n-1; i>=0; i--){
            if(abs(vals[i] - v) > K){
                break;
            }
            if(vals[i] > v) last = i;
        }
        // cout << v << " " << last << " " << n << endl;
        if(last == n && !must) return false;
        vals.insert(vals.begin() + last, v);
        mx = max(mx, v), mn = min(mn, v);
        return true; //wont be fast enough atm
    }
    
    void print(){
        cout << "start:" << endl;
        for(int i : vals) cout << i << endl;
        cout << endl;
    }

    void clear(){
        vals.clear(); mx = 0, mn = 1e9+8;
    }
};

//Move each haybale as far left as possible
const int bket = 300;
const int nbket = 350;
// const int bket = 4;
// const int nbket = 1000;
vector<bucket> nums(nbket);

void init(){
    vector<int> tot;
    for(int i = 0; i<nbket; i++){
        for(int j : nums[i].vals) tot.pb(j);
        nums[i].clear();
    }
    for(int i = 0; i<(int)(tot.size()); i++){
        // nums[i/bket].add(tot[i]); should be same as other
        nums[i/bket].vals.pb(tot[i]);
        nums[i/bket].mx = max(nums[i/bket].mx, tot[i]);
        nums[i/bket].mn = min(nums[i/bket].mn, tot[i]);
    }
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> N >> K;
    int idx = -1;
    for(int i = 0; i<N; i++){
        int v; cin >> v;
        if(i%bket == 0) {
            init(); idx++;
        }
        int j = idx - 1; //stopped at
        for(; j>=0 && abs(nums[j].mx - v) <= K && abs(nums[j].mn - v) <= K; j--){}
        if(v == 2) {
            // cout << "WPW" <<  nums[j].add(v) << endl;
            // cout << (j!=-1 && nums[j].add(v)) << endl;
            // nums[j].print();
        }
        if(j!=-1 && nums[j].add(v)) {
            // cout << "WHY " << v<<  endl;
            continue;
        }
        int ok = 0;
        for(int k = j+1; k<idx; k++){
            if(nums[k].mx > v){
                ok = 1;
                // cout << "WWWW" << endl;
                assert(nums[k].add(v));
                // nums[k].print();
                break;
            }
        }
        if(ok) continue;
        nums[idx].add(v, 1);
        // cout << nums[i/bket].mn << " " << nums[i/bket].mx << endl;
    }
    for(auto i : nums){
        for(int j : i.vals){
            cout << j << '\n';
        }
    }
    return 0;
}
