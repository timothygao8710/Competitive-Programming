//Author: timg8710

#include <vector>
#include <string>
#include <iostream>

using namespace std;
 
typedef long long ll;
typedef pair<ll, int> pii;
 
#define pb push_back
 
#define f first
#define s second
/*
ngl this problem's actually goated
How to optimize dp? 
- Think about what matters and what doesn't(in this problem only relative ordering matters)
- Which boxes in naive dp are unused(in this problem there can only be i distinct elements by index i)
*/
const int mod = 1e9+7;

int main(){
    string S; int N;
    cin >> N >> S;
    int greater[N];
    for(int i = 0; i<N-1; i++){
        greater[i] = (S[i] == '<');
    }
    vector<int> dp; dp.resize(2); dp[1] = 1;
    
    int sum = 1;
    for(int i = 1; i<N; i++){
        vector<int> dp1; dp1.pb(0);

        for(int j = 1; j<=i+1; j++){
            if(greater[i-1]){
                dp1.pb(dp[j-1]);
            }else{
                dp1.pb((sum - dp[j-1] + mod)%mod);
            }
            dp1[j] = (dp1[j] + dp1[j-1])%mod;
        }
        sum = dp1[i+1];
        swap(dp, dp1);
    }
    cout << sum;
    return 0;
}
