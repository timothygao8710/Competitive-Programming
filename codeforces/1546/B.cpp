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
    int T, N, M; cin >> T;
    for(int t = 0; t<T; t++){
        cin >> N >> M;
        multiset<int> tot[26];
        string actual[N];
        for(int i = 0; i<N; i++){
            string str; 
            cin >> str;actual[i] = str;
            for(int j = 0; j<M; j++){
                tot[str[j] - 'a'].insert(j);
            }
        }
        for(int i = 1; i<N; i++){
            string str;
            cin >> str;
            for(int j = 0; j<M; j++){
                tot[str[j] - 'a'].erase(tot[str[j] - 'a'].find(j));
            }
        }
        for(int i = 0; i<N; i++){
            int can = 1;
            for(int j = 0; j<26; j++){
                for(int k : tot[j]){
                    if(actual[i][k] -'a'!= j){
                        can = false; break;
                    }
                }
                if(!can) break;
            }
            if(can){
                cout << actual[i] << endl; break;
            }
        }
    }    
    return 0;
}
/*
1
5 6
abcdef
uuuuuu
kekeke
ekekek
xyzklm
xbcklf
eueueu
ayzdem
ukukuk
*/