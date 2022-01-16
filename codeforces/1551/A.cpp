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
  int T, N;
  cin >> T;
  while(T--){
    cin >> N;
    if(N%3 <= 1){
      cout << ((N+2)/3) << " " << (N/3) << '\n';
    }else{
      cout << (N/3) << " " << ((N+2)/3) << '\n';
    }
  }
  return 0;
}
