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
    int T; cin >> T;
    while(T--){
        int N, K; cin >> N >> K;
        vector<int> nums(N);
        bool has = 0;
        int last = -100;
        bool good = 0;
        for(int i = 0; i<N; i++){
            cin >> nums[i];
            if(nums[i] == K) has = 1;
            nums[i] = nums[i] >= K;
        }
        if(!has){
            cout << "no" << "\n"; continue;
        }
        if(has && nums.size() == 1){
            cout << "yes" << '\n'; continue;
        }

        for(int i = 0; i<N; i++){
            if(nums[i] && (i+1 < N && nums[i+1])){
                good = true;
            }
            if(nums[i] && (i+2 < N && nums[i+2])){
                good = true;
            }
        }
        cout << (good ? "yes" : "no") << '\n';
    }    
    return 0;
}
/*
1
37 358112043
591710665 101102143 24943594 37015528 13671428 481806428 300828424 299139621 358112043 258207889 105581580 358112043 30119203 27297288 358112043 139240651 27711494 358112043 335132807 70316651 386495056 324130196 237855132 248930122 921841215 320472927 51805383 623233042 63366101 34771199 49288462 358112043 335319015 235922154 183524092 358112043 246576
*/