//Author: timg8710

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, int> pii;

#define pb push_back

#define f first
#define s second

struct sTable
{
    vector<int> table[23];
    sTable(int num[], int N)
    {
        int maxFit = maxPow(N);
        assert(maxFit <= 23);
        table[0].reserve(N);
        for(int i = 0; i<N; i++) table[0][i] = num[i];

        for (int i = 1; i < maxFit; i++)
        {
            table[i].reserve(N);
            for (int j = 0; j + (1 << i) - 1 < N; j++)
            {
                table[i][j] = min(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);
            }
        }
    }

    int get(int l, int r)
    {
        int max = maxPow(r - l + 1) - 1;
        return min(table[max][l], table[max][r - (1 << max) + 1]);
    }

    //a^b, returns b+1
    int maxPow(int num)
    {
        int ret = 0;
        while (num > 0)
        {
            num >>= 1;
            ret++;
        }
        return ret;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, Q, u, v; cin >> n >> Q;
    int nums[n];
    for(int i = 0; i<n ;i++){
        cin >> nums[i];
    }
    sTable st(nums, n);
    while(Q--){
        cin >> u; cin >> v; u--; v--;
        cout << st.get(u, v) << "\n";
    }
    return 0;
}
