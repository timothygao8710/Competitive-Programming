//Author: timg8710

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, int> pii;
 
#define pb push_back
 
#define f first
#define s second
//10 minutes lockout
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int N; cin >> N;
    if(N%4 == 3 || N%4 == 0){
        cout << "0" << '\n';
    }else{
        cout << "1";
    }

    return 0;
}
