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
    int N; cin >> N;
    string str; cin >> str;
    int cur = 0;
    for(int i = 0; i<str.length()-11; i++){
        if(str[i]== '8'){
            cur++;
        }else{
            cur--;
        }
    }    
    if(cur < 0){
        cout << "No";
    }else if(cur > 0){
        cout << "Yes";
    }else{
        cout << ((str[str.length()-11] == '8') ? "Yes" : "No");
    }
    return 0;
}
