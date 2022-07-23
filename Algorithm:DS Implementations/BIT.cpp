//Author: timg8710

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, int> pii;
 
#define pb push_back
 
#define f first
#define s second

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
    int n, q, t, u, v;
    cin >> n; cin >> q;
    int nums[n];
    for(int i = 0; i<n; i++){
        cin >> nums[i];
    }
    BIT<ll> bit(nums, n);
    while(q--){
        cin >> t; cin >> u; cin >> v;
        u--; v--;
        if(t-1){
            cout << bit.sum(u, v) << "\n";
        }else{
            bit.update(u, -nums[u]+v+1);
            nums[u] = v+1;
        }
    }
    return 0;
}