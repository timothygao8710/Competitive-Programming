//Author: timg8710

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, int> pii;
 
#define pb push_back
 
#define f first
#define s second
//spam: A is at least as good as B
int nums[5001];

int divide(int l, int r, int last = 0){
    if(l > r) return 0;
    int mn=INT_MAX, idx=-1;
    for(int i = l; i<=r; i++){
        if(nums[i] < mn){
            mn = nums[i]; idx = i;
        }
    }
    return min(
        r - l + 1,
        divide(l, idx-1, mn) + divide(idx+1, r, mn) + mn - last
    );
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int N; cin >> N;
    for(int i = 0; i<N; i++) cin >> nums[i];
    cout << divide(0, N-1);
    return 0;
}
