//@timothyg

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back

#define f first
#define s second

ll cross(pii va, pii vb){  //RHR, 0 if va and vb have same unit vector
    return (ll) va.f * vb.s - va.s * vb.f;
}

//AP Physics knowledge coming in clutttcch
//returns in the k dimension, so up/down, which is why there's pos/neg
//if convex, RHR on lower -> neg; if not convex, RHR on upper -> pos
bool isConvex(pii a, pii b, pii c){
    pii va(b.f - a.f, b.s - a.s);
    pii vb(c.f - b.f, c.s - b.s);
    return cross(va, vb) <= 0; //0 if straight line from a to c (which is ok)
}

double dist(pii a, pii b){
    return sqrt((double)(a.f - b.f) * (a.f - b.f) + (double) (a.s - b.s) * (a.s - b.s));
}

//try infinite symbol polygon -- middle should included twice. Try triangle

//Returns all points that are included in convex polygon
vector<int> solve(int N, vector<pii> points){
    assert((int)(points.size()) >= 3); //to define a triangle
    sort(points.begin(), points.end());

    vector<int> included(N);
    vector<int> upper, lower; //upper and lower hull, combined together give clockwise order of points (might be overlaps)
    upper.pb(0); upper.pb(1);
    included[0] = included[1] = 1;
    for(int i = 2; i<N; i++){
        int sz = upper.size();
        while(sz >= 2 && !isConvex(points[upper[sz-2]], points[upper[sz-1]], points[i])){
            included[upper[sz-1]]--; upper.pop_back(); 
        }
        upper.pb(i); included[i]++;
    }
    lower.pb(N-1); lower.pb(N-2);
    for(int i = N-3; i>=0; i--){
        int sz = lower.size();
        while(sz >= 2 && !isConvex(points[lower[sz-2]], points[lower[sz-1]], points[i])){
            included[lower[sz-1]]--; lower.pop_back();
        }
        lower.pb(i); included[i]++;
    }

    // double sum = 0; //of lengths of edges
    // pii last = points[0];
    // for(int i : upper) sum += dist(last, points[i]), last = points[i];
    // for(int i : lower) sum += dist(last, points[i]), last = points[i];

    return included;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int N; N = 10;
    vector<pii> points(N);

    return 0;
}
