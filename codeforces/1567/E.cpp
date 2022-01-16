//Author: timg8710

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, int> pii;
 
#define pb push_back
 
#define f first
#define s second

struct node{
    ll l=0, r=0, mid=0;
    ll ledge=-1, redge=-1;
    bool single = 0;

    node(){}
    node(int v){
        l = r = 1; mid = 0;
        ledge = redge = v;
        single = 1;
    }

    ll calc(ll len){
        return (len)*(len+1)/2;
    }

    node comb(node right){
        if(ledge == -1) return right;
        if(right.ledge == -1) return *this; //might be wrong
        node ret; 

        ret.mid = mid + right.mid;
        ret.ledge = ledge; 
        ret.redge = right.redge;
        ret.l = l; ret.r = right.r;

        if(redge <= right.ledge){
            ret.single = single && right.single;
            ll len = r + right.l;
            if(single){
                ret.l = len;
            }
            if(right.single){
                ret.r = len;
            }
            if(!single && !right.single){
                ret.mid += calc(len);   
            }
        }else{  
            if(!single){
                ret.mid += calc(r);
            }
            if(!right.single){
                ret.mid += calc(right.l);
            }
        }

        return ret;
    }

    ll get(){
        if(single){
            assert(mid == 0);
            return calc(l);
        }else{
            return calc(l) + mid + calc(r);
        }
    }

    void print(){
        cout << "Current Node: " << single <<  " " << l << " " << mid << " " << r << '\n';
        cout << "the vals: " << ledge << " " << redge << endl;
    }
};

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
        return l.comb(r);
    }

    segtree(int l, int r, int arr[], T non)
    { //modify arr type
        none = non;
        gL = l; gR = r; mid = (gL+gR)/2;
        if (l == r)
        {
            val = node(arr[l]);
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
            //cout << gL << " " << gR << endl;
            return val;
        }
        T a = left->query(l, min(r, mid)); T b = right->query(max(l, mid + 1), r);
        return comb(a, b); //might be wrong
    }

    void update(int idx, int set)
    {
        if (gL == gR)
        {
            val = node(set);
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


int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int N, Q;
    cin >> N >> Q; int nums[N];
    for(int i = 0; i<N; i++){
        cin >> nums[i];
    }
    segtree<node> sgt(0, N-1, nums, node());
    while(Q--){
        int t, l, r; cin >> t >> l >> r; l--;
        if(t == 1){
            sgt.update(l, r);
        }else{
            r--;
           //sgt.query(l,r).print();
            cout << sgt.query(l, r).get() << '\n';
        }
    }
    return 0;
}
/*
10 1
1 2 3 4 3 2 4 3 2 1
2 1 7
*/