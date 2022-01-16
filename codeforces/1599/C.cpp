//Author: timg8710

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, int> pii;
 
#define pb push_back
 
#define f first
#define s second

ll choose(int S, int n){
    if(S < n) return 0;
    ll num = 1, dem = 1;
    for(int i = 0; i<n; i++){
        num *= S-i; dem *= i+1;
    }
    assert(num%dem == 0); return num/dem;
}
//we learn n from S
double calc(int n, int S){
    double sum = 0, tot = choose(S, 3); //vandermonde pogU
    // double sum = 0, tot = 1;
    for(int i = 1; i<=3; i++){
        double p = choose(n, i) * choose(S - n, 3 - i) / tot;
        // if(i == 1) p *= 2.0/3;
        if(i == 1) p *= 1/2.0; //!!!! Jonny doens't know his opponent's pick!!!!
        // cout << p << endl;
        sum += p;
    }
    // cout << sum << " " << tot << endl;
    return sum;
}

int main(){
    // cout << calc(997, 1000);
    ios_base::sync_with_stdio(false); cin.tie(0);
    int N; double P; cin >> N >> P;
    int l = 0, r = N;
    while(l < r){
        int mid = (l + r)/2;
        if(calc(mid, N)+0.000000001 >= P){
            r = mid;
        }else{
            l = mid+1;
        }
    }
    cout << r << '\n';
    return 0;
}
