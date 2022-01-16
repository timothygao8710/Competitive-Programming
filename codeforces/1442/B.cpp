//Author: timg8710

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, int> pii;
 
#define pb push_back
 
#define f first
#define s second
const int mod = 998244353;
template <typename T>
struct BIT {
    vector<T> bit;
    int n;

    BIT(int n) {
        this->n = n + 1;
        bit.resize(n+1);
    }

    BIT(int nums[], int n){
        this -> n = n+1;
        bit.resize(n+1);
        for (int i = 1; i <= n; i++) {
            bit[i] += nums[i - 1]; //update node
            if (i + (i & -i) <= n) {
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
        ll ret = 1;
        vector<int> act(N), nums(K);
        map<int, int> mp;
        for(int i = 0; i<N; i++){
            int a; cin >> a; act[i] = a;
            mp[a] = i;
        }
        set<int> needs;
        
        for(int i = 0; i<K; i++){
            cin >> nums[i]; needs.insert(nums[i]);
        }
        BIT<int> bit(N);
        for(int i = 0; i<K; i++){
            int a = nums[i]; 
            int cur = 0;
            if(mp[a] + 1 <= N - 1 - bit.sum(mp[a]+1, N-1) && !needs.count(act[mp[a]+1])){
                cur++;
            }
            if(mp[a] - 1 - bit.sum(mp[a]) >= 0 && !needs.count(act[mp[a]-1])){
                cur++;
            }
            ret = (ret * cur) % mod;
            needs.erase(a);
            bit.update(mp[a], 1);
        }

        cout << ret << '\n';
    }
    return 0;
}
