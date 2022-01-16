//@timothyg

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back

#define f first
#define s second
set<int> up;

int get(int x){
    int nxt = *(up.lower_bound(x));
    return nxt - x;
}

void solve()
{
    int N;
    cin >> N;
    vector<int> nums(N+1), pref(N+1);
    
    for (int i = 0; i < N; i++){
        int a; cin >> a; nums[a]++;
    }
    array<ll, 3> ret = {get(N)+2, 0, 1};
    for(int i = 1; i<=N; i++) {
        pref[i] += pref[i-1] + nums[i];
        // cout << pref[i] << endl;
    }
    for(int i = 0; i<=N; i++){
        
        for(int j = 0; j<28; j++){
            ll c = get(pref[i]);
            int look = pref[i] + (1<<j);
            auto it = upper_bound(pref.begin(), pref.end(), look); --it;
            // cout << i << endl;
            // if(i == 2 && j == 2){
            //     cout << "OK" << endl;
            //     cout << look << " " << *it <<  " " << pref[i] << " " << c << endl;
            // }
            c += (1<<j) - ((*it) - pref[i]);
            c += get(pref[N] - (*it));
            array<ll, 3> cur = {c, i+1, (int)(it - pref.begin())};
            ret = min(ret, cur);
        }
    }
    cout << ret[0] << '\n';
    // cout << ret[1] << " " << ret[2] << '\n';
}
/*
1
9
1 2 2 2 3 3 3 4 5
*/
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);for(int i = 0; i<30; i++) up.insert(1<<i);
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
