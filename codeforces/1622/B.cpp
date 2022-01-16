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
    int T; cin >> T;
    while(T--){
        int N; cin >> N;
        vector<int> nums(N), perm(N);
        for(int i = 0; i<N; i++){
            cin >> nums[i];
        }
        vector<pii> ones, zeroes;
        string str; cin >> str;
        for(int i = 0; i<N; i++){
            // perm[nums[i]-1] = str[i];
            if(str[i] == '1'){
                ones.pb(pii(nums[i], i));
            }else{
                zeroes.pb(pii(nums[i], i));
            }
        }
        vector<int> ret(N); swap(ones, zeroes);
        sort(ones.begin(), ones.end());
        sort(zeroes.begin(), zeroes.end());
        for(int i = 0; i<ones.size(); i++){
            ret[ones[i].s] = i+1;
        }
        for(int i = 0; i<zeroes.size(); i++){
            ret[zeroes[i].s] = ones.size() + i + 1;
        }
        for(int i : ret) cout << i << " ";
        cout << '\n';
    }    
    return 0;
}
