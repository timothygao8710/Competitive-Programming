//@timothyg

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back

#define f first
#define s second

string tobinary(int i){
    string s = bitset<21>(i).to_string();
    return s;
}

const int maxn = 20;
ll vals[maxn]; //the initial value for each subset

//DP[x] is sum of all DP of its subset
//Naive Solution:
void naive(){
    vector<ll> ret(1<<maxn);
    for(int i = 0; i<(1<<maxn); i++){
        //now we iterate through all subsets
        for(int j = i; j > 0; j = (j-1)&i){ //subset = (subset-1)&mask
            ret[i] += vals[i];
        }
    }
    for(int i : ret){
        cout << i << '\n';
    }
    //3^N
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    /*
    Meta: Draw out bits to visualize better

    SOS DP: https://codeforces.com/blog/entry/45223 (look at image)
    Although to provide an intuitive understanding, it's better to think about from the basis of each subset

    For each subset, the idea of SOS DP is that:
    we are going to iterate from smallest to largest bit
    let dp[mask][i] be ith index of the mask

    This is the value we get if all bits beyond ith bit are fixed
    however, SOS is applied over all subsets <= ith bit.
    So for example, 
    (one-indexed)
    (11101, 3) -> (11000, 11001, 11100, 11101)
     
    and now look at
    (11101, 2) -> (11100, 11101)

    transition... obvious now ain't it?

    Therefore, after we iterate j from 1...maxn-1 for a certain mask,
    we definitely need to include contribution from previous indices --> dp[mask][j] += dp[mask][j-1]
    but also,
    consider for each on bit at index j what happens if it's turned off --> dp[mask][j] += dp[mask - (1<<j)][j]
    (note: dp[mask - (1<<j)][j] is guranteeed not to have the bit turned on for obvious reasons,
    so it would just be dp[mask - (1<<j)][j-1], and if you look at our previous example, it works)

    and so for subset s in val, dp[s][-1] = val[s] (-1 used figuratively, can't actually be implemented)
    
    luckily, if we do the memory optimized iterative dp, with dp[i][mask] defined instead,
    since we always take dp[i-1][mask] our code can become simple
    */
    ll dp[1<<maxn]; 
    //technically the "-1"th index
    //Initially, dp[mask] = val[mask] because everything is fixed
    //as we iterate, we consider finding sos of all subsets of first i indices
    for(int i = 0; i<maxn; i++){
        // for(int j = (1<<maxn)-1; j>=0; j--){
        //     if((j>>i)&1){
        //         dp[j] += dp[j ^ (1<<i)]; //dp[j] = dp[j - (1<<i)];
        //     }
        // }
        //Or we can do:
        for(int j = 0; j<(1<<maxn); j++){
            if((j>>i)&1){
                dp[j] += dp[j ^ (1<<i)]; //dp[j] = dp[j - (1<<i)];
            }else{
                //supersets[j] += supersets[j ^ (1<<i)];
            }
        }
        //Because if ith bit is zero, then dp[i][mask] = dp[i-1][mask] so dp[i][different_mask] += dp[i-1][mask] is same as dp[i][different_mask] += dp[i][mask]
    }
    return 0;
}
