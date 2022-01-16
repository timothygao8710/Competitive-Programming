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
    string str; cin >> str;
    vector<char> chars;
    for(int i = 0; i+1<str.length()/2; i+=2){
        int count[3] = {0,0,0};
        count[str[i]-'a']++;
        count[str[i+1]-'a']++;
        count[str[str.length()-1-i]-'a']++;
        count[str[str.length()-2-i]-'a']++;
        for(int j = 0; j<3; j++){
            if(count[j] >= 2){
                chars.pb((char)(j + 'a')); break;
            }
        }
    }
    for(char i : chars){
        cout << i;
    }
    if(str.length() != 4*chars.size()){
        cout << str[str.length()/2];
    }
    for(int i = chars.size()-1; i>=0; i--){
        cout << chars[i];
    }
    return 0;
}
