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
    T none, lazynone, val, lazy; //comb(a, none) = a
    int gL, gR, mid;
    segtree<T> *left, *right;

    T comb(T &l, T &r)
    {
        return min(l, r); //modify
    }

    //mod lazy, upd val
    //In this code, lazy represents the value only to be propagated(this->value already updated)
    void compose(segtree<T> *tree, T v)
    {
        tree->lazy += v;
        tree->val += v;
        // cout << tree -> gL << " " << tree -> gR << " " << tree -> val << " " << tree -> lazy << endl;
    }
    
    void push()
    {
        if (gL != gR)
        {
            compose(left,lazy);
            compose(right,lazy);
        }
        lazy = lazynone;
    }

    segtree(int l, int r, T non, T lazynon)
    { //modify arr type
        none = non, lazy = lazynone = lazynon;
        gL = l, gR = r, mid = (gL + gR) / 2;
        if (l == r)
        {
            val = non;
        }
        else
        {
            left = new segtree<T>(l, mid,non, lazynon);
            right = new segtree<T>(mid + 1, r, non, lazynon);
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
        push();
        T a = left->query(l, min(r, mid));
        T b = right->query(max(l, mid + 1), r);
        return comb(a, b);
    }

    void update(int l, int r, T updlazy)
    {
        if(gL > r || gR < l){
            return;
        }
        
        if(gL == l && gR == r){
            compose(this, updlazy);
        }else{
            push();
            left -> update(l, min(r, mid), updlazy);
            right -> update(max(l, mid+1), r, updlazy);
            val = comb(left->val, right->val);
        }
    }
};

bool cmp(array<int, 3>& a, array<int, 3>& b){
  return a[2] < b[2];
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  int N, M; cin >> N >> M;
  array<int, 3> qs[N];
  for(int i = 0; i<N; i++){
    cin >> qs[i][0]; cin >> qs[i][1]; cin >> qs[i][2];
  }  
  sort(qs, qs+N, cmp);
  int r = 0; int ret = INT_MAX;
  segtree<int> sgt(0, M-2, 0, 0);
  for(int i = 0; i<N; i++){
    while(r < N && sgt.val == 0){
      sgt.update(qs[r][0]-1, qs[r][1]-2, 1); r++;
    }
    // cout << i << " " << r << " " << qs[i][2] <<  " " << qs[r-1][2] << endl;;
    if(sgt.val != 0) ret = min(ret, qs[r-1][2] - qs[i][2]);
    sgt.update(qs[i][0]-1, qs[i][1]-2, -1);
  }
  cout << ret;
  return 0;
}
