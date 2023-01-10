#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // code goes here
    int n, x;
    cin >> n >> x;
    bool flag = 0;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first;
        v[i].second = i + 1;
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++)
    {
        int l = i + 1, r = n - 1;
        while (l < r)
        {
            int sum = v[i].first + v[l].first + v[r].first;
            if (sum < x)
            {
                l++;
            }
            else if (sum > x)
            {
                r--;
            }
            else
            {
                cout << v[i].second << " " << v[l].second << " " << v[r].second;
                flag = 1;
                break;
            }
        }
        if (flag)
            break;
    }
    if (flag == 0)
        cout << "IMPOSSIBLE";
    return 0;
}
