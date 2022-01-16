//Author: timg8710

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, int> pii;
 
#define pb push_back
 
#define f first
#define s second

//Which swaps are bad/useless?
//never swap same characters
//never swap must-be-before and must-be-after characters
template <typename T>
struct BIT {
    vector<T> bit;
    int n;

    BIT(int n) {
        this->n = n + 1;
        bit.resize(n+1);
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
    int n; string str;
    cin >> n >> str;
    int ar[n], a[n];
    vector<int> chars[26];
    for(int i = 0; i<n; i++){
        chars[str[i] - 'a'].pb(i);
    }
    BIT<ll> bit(n);
    for(int i = 0; i<26; i++){
        for(int j = 0; j<chars[i].size(); j++){
            a[
                n - 1 - chars[i][chars[i].size()-1-j]
            ] = chars[i][j];
        }
    }

    ll ret = 0;
    for(int i : a){
        ret += bit.sum(i, n-1);
        bit.update(i, 1);
    }
    cout << ret;
    return 0;
}
