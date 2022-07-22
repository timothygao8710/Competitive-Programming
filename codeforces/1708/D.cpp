//@timothyg

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back

#define f first
#define s second

int zeroes = 0;

vector<int> solve(vector<int>& pps){
    if(pps.empty()){
        --zeroes; return pps;
    }
    vector<int> res;
    sort(pps.begin(), pps.end());
    int i = 0, last = 0;
    if(zeroes == 0){
        i++, last = pps[0];
    }
    if(zeroes != 0){
        --zeroes;
    }
    // cout << "last is " << last << endl;
    for(; i<(int)(pps.size()); i++){
        // cout << pps[i] << " ";
        if(last == pps[i]){
            zeroes++;
        }else{
            res.pb(pps[i] - last);
            last = pps[i];
        }
    }
    // cout << endl;
    
    // cout << "Has " << zeroes << endl;
    return res;
}

void testcase(){
    //sqrt(5 * 5e5) ^ 2 log(5e5)
    int N; cin >> N;
    zeroes = 0;
    vector<int> nums;
    int last; cin >> last;
    for(int i = 1; i<N; i++){
        int a; cin >> a;
        if(last == a){
            zeroes++;
        }else{
            nums.pb(a - last);
            swap(last, a);
        }
    }

    for(int i = 1; i<N-1; i++){
        vector<int> nxt = solve(nums);
        swap(nxt, nums);
    }

    cout << (nums.empty() ? 0 : nums[0]) << '\n';
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);

    int T; cin >> T;
    while(T--){
        testcase();
    }
    
    return 0;
}
