//Author: timg8710

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
 
#define pb push_back
 
#define f first
#define s second
//bruv how is this 2.8k rated
template <typename T>
struct segtree
{
    pii none = pii(-1,-1);
    T ys; //only needed at leaves, on hindsight shouldnt have put this in segtree
    int mx = -1;
    int gL, gR, mid;
    segtree<T> *left;
    segtree<T> *right;

    void comb(){
        mx = max(left -> mx, right -> mx);
    }

    segtree(int l, int r)
    { //modify arr type
        gL = l; gR = r; mid = (gL+gR)/2;
        if (l != r)
        {
            left = new segtree<T>(l, mid); right = new segtree<T>(mid + 1, r);
        }
    }

    pii query(int val, int idx, int N) //idx inclsuive here
    {

        if (gL > N || gR < idx || mx <= val)
        {
            return none;
        }

        if (gL == idx && gR == N)
        {
            return dig(val);
        }
        // T a = left->query(l, min(r, mid)); T b = right->query(max(l, mid + 1), r);
        pii a = left->query(val, idx, min(mid, N)); 
        if(a.f != -1) return a;
        assert(a == none);
        return right->query(val, max(idx, mid+1), N);
    }

    pii dig(int val)
    {
        if(mx <= val) return none;
        if(gL == gR){
            assert(ys.upper_bound(val) != ys.end());
            return pii(gL, *ys.upper_bound(val));
        }else{
            if(left -> mx > val){
                return left -> dig(val);
            }else{
                assert(right -> mx > val); //assertions are honestly so OP
                return right -> dig(val);
            }
        }
    }

    void update(int idx, int val, bool add)
    {
        if (gL == gR)
        {
            if(add){
                ys.insert(val);
            }else{
                ys.erase(val);
            }
            mx = ys.empty() ? -1 : (*(--ys.end()));
        }
        else
        {
            if (idx <= mid)
            {
                left->update(idx, val, add);
            }
            else
            {
                right->update(idx, val, add);
            }
            comb();
        }
   }
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    //if max doesnt even work, then dont consider at all
    //0 - add, 1 - remove, 2 - find
    int N,x,y; cin >> N; string t;
    map<int, int> xtocomp;
    vector<int> all;
    pair<string, pii> qs[N];
    for(int i = 0; i<N; i++){
        cin >> t >> x >> y;
        qs[i] = pair(t, pii(x,y));
        all.pb(x);
    }
    sort(all.begin(), all.end());
    for(int i = 0; i<all.size(); i++){
        xtocomp[all[i]] = i;
    }
    segtree<set<int>> sgt(0, N);
    for(int i = 0; i<N; i++){
        if(qs[i].f == "add"){
            sgt.update(xtocomp[qs[i].s.f], qs[i].s.s, 1);
        }else if(qs[i].f == "remove"){
            sgt.update(xtocomp[qs[i].s.f], qs[i].s.s, 0);
        }else{
            pii ret = sgt.query(qs[i].s.s, xtocomp[qs[i].s.f]+1, N);
            if(ret.f == -1){
                assert(ret.s == -1);
                cout << -1 << '\n';
            }else{
                cout << all[ret.f] << " " << ret.s << '\n';   
            }
        }
    }
    return 0;
}