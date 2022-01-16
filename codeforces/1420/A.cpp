
#include <bits/stdc++.h>

#include <iostream>

using namespace std;

int main()
{

    int T;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        int N, last = INT_MAX;
        cin >> N;
        bool x = false;
        for (int i = 0; i < N; i++)
        {
            int cur;
            cin >> cur;
            if (last <= cur)
            {
                x = true;
            }
            last = cur;
        }
        cout << (x ? "YES" : "NO") << endl;
    }
    return 0;
};
/*
3
1
1
1
1
1
1
*/
