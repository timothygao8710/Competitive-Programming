//@timothyg

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back

#define f first
#define s second

template <typename T>
struct BIT {
    vector<T> bit;
    int n;

    BIT(int N) {
        n = N + 1;
        bit.resize(n);
    }

    BIT(int nums[], int N){
        n = N+1;
        bit.resize(n);
        for (int i = 1; i < n; i++) {
            bit[i] += nums[i - 1]; //update node
            if (i + (i & -i) < n) {
                bit[i + (i & -i)] += bit[i]; //update parent
            }
        }
    }
    
    T sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    T sum(int r) {
        r++;
        T ret = 0;
        while (r > 0) {
            ret += bit[r];
            r -= r & -r;
        }
        return ret;
    }

    //updates # at pos nums[idx]
    //does not reset nums[idx], but updates it (+/-)
    void update(int idx, T v) {
        idx++;
        while (idx < n) {
            bit[idx] += v;
            idx += idx & -idx;
        }
    }
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while(T--){
        int N, K; cin >> N >> K;
        vector<int> cnt(N+1, -1); //0...N-1 at most
        BIT<int> occs(N+1), zeroes(N+1);
        map<int, int> times;
        for(int i = 0; i<N; i++){
            int a; cin >> a;
            times[a]++;
        }
        vector<pii> sorted;
        for(pii i : times){
            sorted.pb(pii(i.s, i.f));
        }
        sort(sorted.begin(), sorted.end());
        for(int i = 0; i<=N; i++){
            if(i < (int)sorted.size()){
                if(sorted[i].s <= N) cnt[sorted[i].s] = i;
                occs.update(i, sorted[i].f);
            }else{
                zeroes.update(i, 1);
            }
        }

        auto bsearch = [&] (){

            int l = -1, r = N;
            while(l < r){
                int mid = (l+r+1)/2;
                if(occs.sum(mid) <= K){
                    l = mid;
                }else{
                    r = mid-1;
                }
            }
            return l+1-zeroes.sum(l);
        };

        int ret = max(1, (int)sorted.size() - bsearch());
        int need = 0;
        for(int i = 0; i<N; i++){
            int MEX = i+1;
            if(cnt[i] == -1){
                need++;
            }else{
                occs.update(cnt[i], -sorted[cnt[i]].f);
                zeroes.update(cnt[i], 1);
            }
            if(need > K) {
                break;
            }
            int removes = bsearch();
            ret = min(ret, (int) sorted.size() + need - MEX - removes);
        }
        cout << ret << '\n';
    }
    return 0;
}
