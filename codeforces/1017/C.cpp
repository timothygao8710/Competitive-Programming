//@timothyg

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back

#define f first
#define s second

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int N; cin >> N; //no clue if this is correct but ill try for the lockout LOL
    int sq = sqrt(N);
    for(int i = 1; i<=N; i += sq){
        for(int j = i + sq - 1; j>=i; j--){
            if(j <= N) cout << j << " ";
        }
    }
    return 0;
}
