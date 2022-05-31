//@timothyg

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back

#define f first
#define s second

template <typename T>
struct segtree
{
    T val, none;
    int l, r, mid;
    segtree<T> *left, *right;

    T comb(T& l, T& r){
        return max(l, r); //modify
    }

    segtree(int gL, int gR, vector<T>& nums, T non){ 
        l = gL, r = gR, mid = (l+r)/2, none = non;
        if (l == r){
            val = nums[l];
        }else{
            left = new segtree<T>(l, mid, nums, none), right = new segtree<T>(mid + 1, r, nums, none);
            val = comb(left->val, right->val);
        }
    }

    T query(int ql, int qr){
        if (ql > r || qr < l) return none;
        if (ql == l && qr == r) return val;
        T a = left->query(ql, min(qr, mid)), b = right->query(max(ql, mid + 1), qr);
        return comb(a, b);
    }

    void update(int idx, T set){
        if (l == r){
            val = set;
        }else{
            if (idx <= (l + r) / 2) left->update(idx, set);
            else { right->update(idx, set); }
            val = comb(left->val, right->val);
        }
   }
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while(T--){
        int N; cin >> N;
        vector<ll> f(N), b(N), nums(N);
        vector<pii> indicies(N);
        for(int i = 0; i<N; i++) cin >> nums[i], indicies[i] = pii(nums[i], i);
        for(int i = 0; i<N; i++) {
            f[i] = nums[i];
            if(i != 0) f[i] += f[i-1];
        }
        for(int i = N-1; i>=0; i--) {
            b[i] = nums[i];
            if(i != N-1) b[i] += b[i+1];
        }

        set<int> taken;
        taken.insert(-1); taken.insert(N);
        segtree<ll> front(0, N-1, f, -1e15);
        segtree<ll> back(0, N-1, b, -1e15);

        sort(indicies.begin(), indicies.end());
        reverse(indicies.begin(), indicies.end());

        int good = 1;
        for(int i = 0; i<N;){
            int j = i;
            while(j < N && indicies[i].f == indicies[j].f){
                //find op
                int l = (*(--taken.lower_bound(indicies[j].s)));
                int r = (*(taken.lower_bound(indicies[j].s)));
                ll left = back.query(l+1, indicies[j].s) - b[indicies[j].s];
                ll right = front.query(indicies[j].s, r-1) - f[indicies[j].s];

                // cout << left << " " << right << " "  << " " << l << " " << r <<  " " << indicies[j].s << " a " << front.query(indicies[j].s, r-1) << endl;
                ll sum = left + right + indicies[j].f;
                // cout << sum << endl;

                good = good && (indicies[j].f >= sum);
                j++;
            }

            for(int k = i; k<j; k++){
                taken.insert(indicies[k].s);
            }
            i = j;
        }
        cout << (good ? "YES" : "NO") << '\n';
    }    
    return 0;
}
