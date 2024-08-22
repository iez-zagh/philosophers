#include <iostream>
#include <map>
#include <algorithm>

#define LL long long

using namespace std;

int main()
{
    std::ios::sync_with_stdio(false); // Faster I/O
    std::cin.tie(nullptr);
    
    long long n;
    cin >> n;
    long long n2;
    cin >> n2;
    map<LL, LL> my;
    for (LL i = 0; i < n;i++)
    {
        LL m;
        cin >> m;
        my[i] = m;
    }

    map<LL, LL>::iterator it = my.begin();
    while (it != my.end())
    {
        std::cout << it->first << it->second << std::endl;
        ++it;
    }
    // map<LL, LL>::iterator it = my.begin();
    // while (it != my.end())
    // {
    //     LL h = abs(n2 - it->first);
    //     if (my.find(h) != my.end())
    //     {
    //         if (my[h] != it->second)
    //         {
    //             cout  << my[h] + 1  << ' ' << it->second + 1 << '\n';
    //         return 0;

    //         }
    //     }
    //     ++it;
    // }
    cout << "IMPOSSIBLE\n"; 

}

