/*input
8 4
3 2 4 5 1 1 5 3
2 1 4
2 5 6
1 3 1
2 1 4
*/

//Author: timg8710

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

//default intialized as none
struct node{
    ll val = 0;
    node(){}
    node(ll v){val = v;}
    //assume current is left
    node comb(node& other){
        return node(other.val + val);
    }
};

struct segtree
{
    node val;
    int gL, gR, mid;
    segtree *left, *right;

    segtree(int l, int r, vector<node> nums)
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

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, q, u, v, t;
    cin >> n; cin >> q;
    vector<node> nums(n);
    for(int i =0; i<n; i++) cin>>nums[i].val;
    segtree tree(0, n-1, nums);
	for(int i = 0; i<q; i++){
        cin>> t;
        cin >> u; cin >> v;
        if(t == 1){
            node temp(v);
            tree.update(u-1, temp);
        }else{
            cout << tree.query(u-1, v-1).val << endl;
        }
    }
    return 0;
}