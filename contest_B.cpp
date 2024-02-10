#include<bits/stdc++.h>
using namespace std;
int main()
{
    int s;
    cin >> s;
    while (s--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            v.push_back(x);
        }
        sort(v.begin(), v.end());
        int ans = 0, c = 0, k;
        for (int i = 0; i < n; i++)
        {
            c += v[i];
            if (c > m)
            {
                break;
            }
            ans = c;
            k = i;
        }
        if (ans == 0)
        {
            cout << m << endl;
        }
        else
        {
            ans = (m - ans) + ans + k + 1;
            cout << ans << endl;
        }
}
return 0;
}
