#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long n, k;
    cin >> n >> k;

    vector<int> mnt(n);
    vector<int> slp(n);

    for (int i = 0; i < n; i++)
    {
        cin >> mnt[i];
    }

    long x = 0;
    vector<long> prf(n, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> slp[i];
        if (slp[i] == 1)
        {
            x += mnt[i];
        }
        else
        {
            prf[i] = mnt[i];
        }
    }

    long maxi = 0,w = 0;
    for (int i = 0; i < k; i++)
    {
        w += prf[i];
    }
    maxi = w;

    for (int i = k; i < n; i++)
    {
        w += prf[i] - prf[i - k];
        maxi = max(maxi, w);
    }

    cout << x + maxi;

}
