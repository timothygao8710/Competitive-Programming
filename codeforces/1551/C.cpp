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
        cin >> N; int best = 0;
        string words[N];
        for(int i = 0; i<N; i++){
            cin >> words[i];
        }
        for(int i = 0; i<5; i++){
            vector<int> costs;
            for(string j : words){
                int cur = 0;
                for(int k = 0; k<j.size(); k++){
                    if(j[k] - 'a' == i){
                        cur++;
                    }else{
                        cur--;
                    }
                }
                // cout << cur <<  " ";
                costs.pb(cur);
            }
            sort(costs.begin(), costs.end());
            int run = 0, tot = 0;
            for(int i = N-1; i>=0; i--){
                if(run + costs[i] <= 0) break;
                run += costs[i]; tot++;
            }
            best = max(best, tot);
            // cout << endl;
        }
        cout << best << endl;
    }    
    return 0;
}
/*
1
2
baba
baba
*/