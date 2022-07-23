//@timothyg

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;

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
    int nums[12] = {232,52,345,52345,25342,1345,2352,62,100,0,1,-134};
    pair<ll, vector<int>> ret = find_inversions(nums, 0, 11);
    cout << ret.f;
    return 0;
}
