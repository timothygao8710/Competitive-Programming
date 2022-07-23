//Author: timg8710
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

#define f first
#define s second

void setIO(string s) { // the argument is the filename without the extension
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

struct node
{
    bool empty;
    int l, r, best;
};

template <typename T>
struct segtree
{
    T open, close; //comb(a, none) = a

    T val;
    int gL, gR, mid, lazy;
    //1: now closed
    //2: now open
    segtree<T> *left;
    segtree<T> *right;

    segtree(int l, int r)
    { //modify arr type
        gL = l; lazy = 0;
        gR = r;
        mid = (gL + gR) / 2;

        open.best = open.l = open.r = gR - gL + 1;
        open.empty = 1;
        close.empty = close.best = close.l = close.r = 0;

        if (l != r)
        {
            left = new segtree<T>(l, mid);
            right = new segtree<T>(mid + 1, r);
        }
        val = open;
    }

    T comb(T &a, T &b)
    {
        T ret;
        if (a.empty && b.empty)
        {
            ret.l = ret.r = ret.best = a.best + b.best; ret.empty = 1;
            return ret;
        }
        ret.empty = 0;
        ret.l = a.empty ? a.best + b.l : a.l;
        ret.r = b.empty ? b.best + a.r : b.r;
        ret.best = max(a.best, max(b.best, a.r + b.l));
        return ret;
    }

    void push()
    {
        if (lazy != 0)
        {
            if (lazy - 1)
            {
                right->val = right->open;
                left->val = left->open;
            }
            else
            {
                right->val = right->close;
                left->val = left->close;
            }
            left -> lazy = right -> lazy = lazy;
            lazy = 0;
        }
    }

    //types:
    /*
    0 - find any
    1 - stick r
    2 - stick l
    */
    int insert(int size, int type)
    {
        if (size == val.best && val.empty)
        {
            val = close;
            lazy = 1;
            return gL;
        }
        push();
        int ret = -1;
        if (type == 0)
        {
            if (left->val.best >= size)
            {
                ret = left->insert(size, type);
            }
            else if (left->val.r + right->val.l >= size)
            {
                int take = left->val.r;
                ret = right->insert(size - take, 2);
                if(take > 0) {
                    ret = left->insert(take, 1);
                }
            }
            else
            {
                // cout << left -> val.best << " " << right -> val.best << endl;
                ret = right->insert(size, type);
            }
        }
        else if (type == 1)
        {
                int t = size;
                size -= right->val.r;
                size = max(size, 0);
                ret = right->insert(min(right->val.r, t), type);
            if(size > 0){
                ret = left->insert(size, type);        
            } 
        }
        else
        {
                int t = size;
                size -= left->val.l; size = max(size, 0);
                ret = left->insert(min(left->val.l, t), type);
            if(size > 0) right->insert(size, type);
        }
        val = comb(left -> val, right -> val);
        return ret;
    }
//ok now im regretting doing it this way rip

    void remove(int l, int r)
    {
        if(gL > r || gR < l){
            return;
        }
        // cout << l << " " << r << " " << gL << " " << gR << endl;
        if(gL == l && gR == r){
            lazy = 2; val = open;
        }else{
            push();
            left -> remove(l, min(r, mid));
            right -> remove(max(l, mid+1), r);
            val = comb(left->val, right->val);
        }
    }
};

int main()
{
    setIO("seating");
    ios_base::sync_with_stdio(false);
    cin.tie(0); 
    int N, M, u, v; //set root as empty
    
    char t; int ret = 0;
    //later, first check if root is ok
    cin >> N >> M;
    // cout << "SDFJSDFLKJSDF" << endl;
    segtree<node> root(1, N); 

    // cout << "SDFJSDFLKJSDF" << endl;
    for(int i = 0; i<M; i++){
        cin >> t >> u;
        if(t == 'A'){
            //insert
            if(root.val.best < u){
                // cout << 0 << '\n';
                ret++;
            }else{
                root.insert(u, 0);
            }
        }else{
            cin >> v;
            root.remove(u, v);
        }
    }
    cout << ret;
    return 0;
}

/*
10 2
1 5
1 5

*/


