//Author: timg8710

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, int> pii;
 
#define pb push_back
 
#define f first
#define s second


//just go back and touch the untouched ones dud
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int N; cin >> N;
    ll ret = 0;
    pii link[N];
    for(int i = 0; i<N; i++){
        cin >> link[i].f >> link[i].s; ret += link[i].s;
    }
    sort(link, link+N);
    ll far = link[0].f + link[0].s;
    for(pii i : link){
        ret += max(0ll, i.f - far); 
        far = max(i.f + i.s, far);
    }
    cout << ret;
    return 0;
}
