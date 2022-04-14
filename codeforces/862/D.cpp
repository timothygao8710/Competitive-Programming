//@timothyg

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back

#define f first
#define s second

int N;

int ask(string a){
    cout << "? " << a << endl;
    int ret; cin >> ret; return ret;
}

string generate(string a, int front, int bit){
    string ret = a;
    for(int i  = 0; i<=front; i++){
        ret[i] = (bit ? '1' : '0');
    }
    return ret;
}

int find(string ref, int bit, int all){
    int l = 0, r = N-1;
    while(l < r){
        int mid = (l+r)/2; //bsearch for earliest not bit
        if(ask(generate(ref, mid, bit)) > all - mid - 1){
            r = mid;
        }else{
            l = mid+1;
        }
    }
    assert(l != 0);
    return r;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> N;
    string zeroes = "", ones = "";
    for(int i = 0; i<N; i++) zeroes += "0", ones += "1";
    int init = ask(zeroes);
    zeroes[0] = '1';
    int change = ask(zeroes);
    zeroes[0] = '0';

    if(change < init){
        //is 1
        int ret = find(zeroes, 1, init);
        cout << "! " << (ret+1) << " " << 1 << endl;
    }else{
        init = N - init;
        int ret = find(ones, 0, init);
        cout << "! " << 1 << " " << (ret+1) << endl;
    }
    return 0;
}
