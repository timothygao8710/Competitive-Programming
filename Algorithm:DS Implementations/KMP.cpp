//@timothyg

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back

#define f first
#define s second

vector<int> buildFail(string str){
    int N = str.length();
    assert(!str.empty());
    vector<int> ret(N);
    //In KMP: mismatched at i
    //Stores pointer to longest prefix equal to suffix ending at i (not the whole string)
    //ret[i] means next element at pref[i] (so we have length i pref so far)
    for(int i = 1; i<N; i++){
        int mIdx = ret[i-1];
        while(true){
            if(str[mIdx] == str[i]){
                mIdx++; //Matches, so the next looking-at match of the current prefix will be +1 index
                //basically we now have length i+1 matched prefix, so we increment idx
                break;
            }else{
                if(mIdx == 0) break;
                mIdx = ret[mIdx-1]; //We fall back to mIdx-1, because we know we have matched that much prefix for sure
            }
        }
        ret[i] = mIdx;
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);

    // string test = "AAAAABBABABAB";
    // vector<int> tF = buildFail(test);
    // for(int i : tF) cout << i << " ";

    string pat = "AABA"; int N = pat.length();
    string txt = "AABAACAADAABAABA"; int M = txt.length();
    vector<int> fail = buildFail(pat);
    vector<int> ret; //All occ where txt[i-N+1..i] == pat, N = len(pat)
    //The procedure is very similar to building the fail table
    int p1 = 0; //in the pattern
    for(int i = 0; i<M; i++){
        while(true){
            if(pat[p1] == txt[i]){
                if(p1 == N-1) {
                    ret.pb(i); p1 = fail[p1];
                }else{
                    p1++;
                }
                break;
            }else{
                if(p1 == 0) break;
                p1 = fail[p1-1];
            }
        }
    }
    for(int i : ret) cout << i << " ";
    cout << endl;
    for(int i : ret) cout << (i-N+1) << " ";
    return 0;
}
