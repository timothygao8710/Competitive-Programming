//Author: timg8710

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, int> pii;
 
#define pb push_back
 
#define f first
#define s second

template <typename T>
struct segtree
{
    T none; //comb(a, none) = a

    T val;
    int gL, gR, mid;
    segtree<T> *left;
    segtree<T> *right;

    T comb(T& l, T& r)
    {
        return min(l, r); //modify
    }

    segtree(int l, int r, T arr[], T non)
    { //modify arr type
        none = non;
        gL = l; gR = r; mid = (gL+gR)/2;
        if (l == r)
        {
            val = arr[l];
        }
        else
        {
            
            left = new segtree<T>(l, mid, arr, non); right = new segtree<T>(mid + 1, r, arr, non);
            val = comb(
                left->val, right->val);
        }
    }

    T query(int l, int r)
    {

        if (gL > r || gR < l)
        {
            return none;
        }

        if (gL == l && gR == r)
        {
            return val;
        }
        T a = left->query(l, min(r, mid)); T b = right->query(max(l, mid + 1), r);
        return comb(a, b); //might be wrong
    }

    void update(int idx, T set)
    {
        if (gL == gR)
        {
            val = set;
        }
        else
        {
            if (idx <= (gL + gR) / 2)
            {
                left->update(idx, set);
            }
            else
            {
                right->update(idx, set);
            }
            val = comb(left->val, right->val);
        }
   }
};
int big = 1e9+7;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T, N, a, b, c; cin >> T;
    while(T--){
        cin >> N;
        int nums[N]; pii sorted[N]; int temp[N];
        for(int i = 0; i<N;i ++){
            cin >> nums[i]; sorted[i] = pii(nums[i], i); temp[i] = big;
            
        }
        sort(sorted, sorted+N); map<int, int> comp;
        segtree<int> sgt(0, N-1, temp, big);
        for(int i=N-1; i>=0; i--){
            comp[sorted[i].f] = i;
        }
        for(int i = 0; i<N; i++) nums[i] = comp[nums[i]];
        int less[N], great[N];
        for(int i = N-1; i>=0; i--){
            less[i] = sgt.query(0, nums[i]);
            great[i] = sgt.query(nums[i], N-1);
            sgt.update(nums[i], i);
        }
        ll ret = 0; int last = N;
        segtree<int> les(0, N-1, temp, big), gre(0, N-1, temp, big);
        for(int i = N-1; i>=0; i--){
            int mn = min(les.query(0, nums[i]), gre.query(nums[i], N-1));
            mn = min(mn, last);
            ret += mn -i; last = min(last, mn);
            les.update(nums[i], less[i]); gre.update(nums[i], great[i]);
        }
        cout << ret << '\n';
    }
    return 0;
}
