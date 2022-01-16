//Author: timg8710

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, pair<int, int>> pii;
 
#define pb push_back
 
#define f first
#define s second

const int bucket = 1000;

//x -> l, y - > r, so basically just mo's algorithm ordering
//actaully, regular mo's gives 3*10^9 ish because transition between buckets takes 10^6
bool cmp(pii a, pii b){
    return a.f/bucket == b.f/bucket ? (
        (a.f/bucket)%2 ?
        a.s.f > b.s.f
        :
        a.s.f < b.s.f
        ) : a.f/bucket < b.f/bucket;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int N, x, y; cin >> N;
    pii points[N];
    for(int i =0; i<N; i++){
        cin >> x >> y;
        points[i] = pii(x, pair(y, i));
    }
    sort(points, points + N, cmp);
    for(pii i : points){
        cout << (1+i.s.s) << " ";
    }
    return 0;
}
