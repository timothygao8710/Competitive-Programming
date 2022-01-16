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

const int maxu = 3e5+5;
// const int maxu = 10;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int N, u; cin >> N;
    ll run = 0;
    BIT<ll> cnt(maxu), sum(maxu), bps(maxu);
    for(int i = 0; i<N; i++){
        cin >> u;
        run += sum.sum(u-1);
        run += cnt.sum(u+1, maxu-1)*u;
        //me : small
        run += u*cnt.sum(u) - bps.sum(u);
        // cout << run << " " << endl;
        //large : me
        for(int j = u; j < maxu; j += u){
            int rightedge = min(maxu-1, j+u-1);
            run += sum.sum(j, rightedge) - cnt.sum(j, rightedge)*j;
            bps.update(j, u);
        }
        // cout << "after: " << run << endl;
        cout << run << " ";
        sum.update(u, u);
        cnt.update(u, 1);
    }
    return 0;
}
/*
2
1 2
*/