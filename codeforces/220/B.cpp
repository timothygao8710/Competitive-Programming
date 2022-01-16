//Author: timg8710

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, int> pii;
 
#define pb push_back
 
#define f first
#define s second

int64_t gilbertOrder(int x, int y, int pow, int rotate) {
    if (pow == 0) {
        return 0;
    }
    int hpow = 1 << (pow-1);
    int seg = (x < hpow) ? (
        (y < hpow) ? 0 : 3
    ) : (
        (y < hpow) ? 1 : 2
    );
    seg = (seg + rotate) & 3;
    const int rotateDelta[4] = {3, 0, 0, 1};
    int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
    int nrot = (rotate + rotateDelta[seg]) & 3;
    int64_t subSquareSize = int64_t(1) << (2*pow - 2);
    int64_t ans = seg * subSquareSize;
    int64_t add = gilbertOrder(nx, ny, pow-1, nrot);
    ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
    return ans;
}

struct Query{
    int l, r, idx; //inclusive
    int64_t order;
    Query(){}
    Query(int a, int b, int c){
        l = a, r = b, idx = c; 
        order = gilbertOrder(l, r, 21, 0);
    }
    bool operator<(const Query& other) const {
        return order < other.order;
    }
    // bool operator<(const Query& other) const {
    //     return l/bket == other.l/bket ? (
    //         l/bket % 2 ? other.r > r : other.r < r
    //     ) : l/bket < other.l/bket;
    // }
};

int nums[100007];
unordered_map<int, int> mp; int sum = 0;

void insert(int x){
    if(x > 100007) return;
    if(mp[x] == x) sum--;
    mp[x]++;
    if(mp[x] == x) sum++;
}

void remove(int x){
    if(x > 100007) return;
    if(mp[x] == x) sum--;
    mp[x]--; assert(mp[x] >= 0);
    if(mp[x] == x) sum++;
}

//Query last(0,0,-1); insert(nums[0]);
void move(Query& from, Query& to){
    int l = from.l, r = from.r;
    while(l > to.l) l--, insert(nums[l]);
    while(r < to.r) r++, insert(nums[r]);
    while(l < to.l) remove(nums[l]), l++;
    while(r > to.r) remove(nums[r]), r--;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int N, M; cin >> N >> M;
    for(int i = 0; i<N; i++) cin >> nums[i];
    vector<Query> qs(M);
    for(int i = 0; i<M; i++){
        int a, b; cin >> a >> b; a--, b--;
        qs[i] = Query(a, b, i);
    }
    sort(qs.begin(), qs.end()); vector<int> ret(M);
    Query last(0,0,-1); insert(nums[0]);
    for(auto i : qs){
        move(last, i); ret[i.idx] = sum; last = i;
    }
    for(int i : ret) cout << i << '\n';
    return 0;
}
