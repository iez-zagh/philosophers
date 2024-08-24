#include <iostream>

using namespace std;

#define ll long long
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    ll n;
    cin >> n;
    int arr[n];
    for (ll i = 0;i <n;i++)
    {
        int f=0;
        ll n2;
        cin >> n2;
        ll odd = 0;
        ll even = 0;
        for (ll j = 0;j <n2;j++)
        {
            ll h;cin>>h;
            if (h % 2)
            {
                odd+=h;
            }
            else
                even+=h;
        }
        if (odd < even)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
