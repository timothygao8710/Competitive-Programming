//Author: timg8710

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, int> pii;
 
#define pb push_back
 
#define f first
#define s second

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T, N; cin >> T;
    while(T--){
        cin >> N; int nums[N]; for(int i = 0; i<N; i++) cin >> nums[i];
        sort(nums, nums + N);
        int diff = INT_MAX, idx = 1;
        for(int i=  1; i<N; i++){
            if(nums[i] - nums[i-1] < diff){
                diff = nums[i] - nums[i-1]; idx = i;
            }
        }
        cout << nums[idx-1] << " ";
        for(int i = idx+1; i<N; i++){
            cout << nums[i] << " ";
        }
        for(int i = 0; i<idx-1; i++){
            cout << nums[i] << " ";
        }
        cout << nums[idx] << "\n";
    }    
    return 0;
}
