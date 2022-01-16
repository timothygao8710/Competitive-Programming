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
        int N; cin >> N; string str; cin >> str; int len = INT_MAX;
        for(int i = 0; i<N; i++){
            if(str[i] != 'a') continue;
            vector<int> cnt(3); cnt[0]++;
            for(int j = i+1; j<min(N, i+40); j++){
                cnt[str[j]-'a']++;
                if(cnt[0] > cnt[1] && cnt[0] > cnt[2]){
                    len = min(len, j-i+1);
                }
            }
        }
        cout << (len == INT_MAX ? -1 : len) << '\n';
    }    
    return 0;
}
