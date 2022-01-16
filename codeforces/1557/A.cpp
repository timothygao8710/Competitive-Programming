//Author: timg8710

#include <bits/stdc++.h>
 
using namespace std;
using std::setprecision;
 
typedef long long ll;
typedef pair<ll, int> pii;
 
#define pb push_back
 
#define f first
#define s second



int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    
     int T, N, c; cin >> T;
     while(T--){
        cin >> N;
        int nums[N];
        long double sum = 0;
        for(int i = 0; i<N; i++){
            cin >> nums[i];
            sum += nums[i];
        }
        long double run = 0;
        sort(nums, nums+N);
        long double ret = -1e14;
        for(int i = 0; i<N-1; i++){
            run += nums[i];
            sum -= nums[i];
            ret = max(ret,
                run / (i+1) + sum / (N - i - 1)
                
            );
        }
        cout << fixed << std::setprecision(9)  << ret << '\n';
     }

    return 0;
}
