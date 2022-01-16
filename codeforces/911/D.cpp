//Author: timg8710

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, int> pii;
 
#define pb push_back
 
#define f first
#define s second

//pretty slow compared to BIT
pair<ll, vector<int>> find_inversions(int nums[], int l, int r){ //all nums[i] in nums is distinct
    pair<ll, vector<int>> ret;
    if(l == r){
        ret.s.pb(nums[l]);
    }else{
        pair<ll, vector<int>> left = find_inversions(nums, l, (l+r)/2), right = find_inversions(nums, (l+r)/2+1, r);
        ret.f = left.f + right.f;
        int p1 = 0, p2 = 0;
        while(p1 < left.s.size() || p2 < right.s.size()){
            while(p1 < left.s.size() && (p2 == right.s.size() || left.s[p1] < right.s[p2])){
                ret.s.pb(left.s[p1]); p1++; ret.f += p2;
            }
            while(p2 < right.s.size() && (p1 == left.s.size() || left.s[p1] > right.s[p2])){
                ret.s.pb(right.s[p2]); p2++;
            }
        }
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int N, M,l,r; cin >> N; int nums[N];
    for(int i = 0; i<N; i++) cin >> nums[i];
    int cur = find_inversions(nums, 0, N-1).f%2;
    cin >> M;
    for(int i = 0; i<M; i++){
        cin >> l >> r; l = r-l+1;
        int diff = (l-1)*(l)/2;
        cur ^= (diff%2);
        cout << (cur ? "odd" : "even") << "\n";
    }
    return 0;
}
