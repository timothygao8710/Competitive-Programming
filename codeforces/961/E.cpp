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

const int maxn = 2e5+40;
vector<int> qs[maxn];
int nums[maxn];

BIT<int> bit(maxn);

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int N; cin >> N;
    for(int i = 1; i<=N; i++){
        cin >> nums[i]; nums[i] = min(nums[i], maxn-30);
        if(i != 1){
            qs[min(nums[i], i-1)].pb(i);
        }
    }
    ll ret = 0;
    for(int i = 1; i<=N; i++){
        bit.update(nums[i], 1);
        for(int j : qs[i]){
            ret += bit.sum(j, maxn-1);
        }
    }
    cout << ret;
    return 0;
}
