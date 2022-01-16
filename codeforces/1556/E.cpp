//Author: timg8710

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, int> pii;
 
#define pb push_back
 
#define f first
#define s second

//default intialized as none
struct node{
    ll val = LLONG_MAX, type = 5;
    node(){}
    node(ll v, ll t){val = v, type = t;}
    //assume current is left
    node comb(node& other){
        if(type == 5) return other;
        if(other.type == 5) return node{val, type};
        if(type == 0){
            return node{min(val, other.val), 0};
        }else{
            return node{max(val, other.val), 1};
        }
    }
};

struct segtree
{
    node val;
    int gL, gR, mid;
    segtree *left, *right;

    segtree(int l, int r, vector<node>& nums)
    {
        gL = l; gR = r; mid = (gL+gR)/2;
        if (l == r)
        {
            val = nums[l];
        }
        else
        {
            
            left = new segtree(l, mid, nums), right = new segtree(mid + 1, r, nums);
            val = left->val.comb(right->val);
        }
    }

    node query(int l, int r)
    {

        if (gL > r || gR < l)
        {
            return node();
        }

        if (gL == l && gR == r)
        {
            return val;
        }
        node a = left->query(l, min(r, mid)), b = right->query(max(l, mid + 1), r);
        return a.comb(b); //might be wrong
    }

    void update(int idx, node& set)
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
            val = left->val.comb(right->val);
        }
   }
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int N, Q; cin >> N >> Q;
    vector<ll> nums(N+1);
    for(int i= 0; i<N; i++){
        cin >> nums[i+1];
    }
    for(int i = 0; i<N; i++){
        int t; cin >> t; nums[i+1] = t - nums[i+1]; 
    }
    // cout << endl;
    // for(int i = 0; i<=N; i++) cout << nums[i] << "  ";
    for(int i = 1; i<=N; i++) nums[i] += nums[i-1];
    // cout << endl;
    // for(int i = 0; i<=N; i++) cout << nums[i] << "  ";
    // cout << endl;
    vector<node> temp(N+1), tempa(N+1);
    for(int i = 0; i<=N; i++){
        temp[i] = node(nums[i], 0);
        tempa[i] = node(nums[i], 1);
    }
    segtree mnsgt(0, N, temp), mxsgt(0, N, tempa);
    while(Q--){ //BRO THIS IS SO TROLL IT SAYS AN EVEN NUMBER OF ELEMENTS MUST BE SELECTED BRUAAHHHHH
        int l, r; cin >> l >> r;
        ll mn = mnsgt.query(l, r).val, mx = mxsgt.query(l, r).val;
        if(mn - nums[l-1] < (ll)0 || nums[r] - nums[l-1] != 0){
            cout << -1 << '\n';
        }else{
            cout << (mx - nums[l-1]) << '\n';
        }
    }
    return 0;
}