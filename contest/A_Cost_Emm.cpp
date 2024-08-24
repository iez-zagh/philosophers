#include <iostream>

using namespace std;

#define ll long long
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    ll n;
    cin >> n;
    for (ll i = 0;i <n;i++)
    {
        int f=0;
        ll n2;
        cin >> n2;
        ll n3;
        cin >> n3;
        for (ll j = 0;j <n2;j++)
        {
            ll h;cin>>h;
            // cout << h;
            // puts("hi");
            // cout << n3 << "\n";
            if (h == n3 && !f)
            {
                // cout << "[" << h<<"]\n" << n3<<"hh\n";
                f = 1;
                cout << "YES\n";
                // break ;
            }
        }
        if (!f)
            cout << "NO\n";
    }
}