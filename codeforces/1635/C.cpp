//@timothyg

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back

#define f first
#define s second
//bro i am so fucking mad i thought the entire time u had to minimize operations
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);  
    int T; cin >> T;
    while(T--){
        int N; cin >> N;
        vector<int> nums(N);
        for(int i = 0; i<N; i++) cin >> nums[i];
        int dec = 0;
        for(int i = 1; i<N; i++){
            dec = dec || (nums[i] < nums[i-1]);
        }
        if(!dec){
            cout << 0 << '\n'; continue;
        }
        if(nums[N-1] < 0 || (nums[N-2] > nums[N-1])){
            cout << -1 << '\n'; continue;
        }
        cout << (N-2) << '\n';
        for(int i = 0; i<N-2; i++){
            cout << (i+1) << " " << (N-1) << " " << (N) << '\n';
        }
    }
    return 0;
}
