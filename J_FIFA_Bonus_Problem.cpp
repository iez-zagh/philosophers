#include <iostream>
#include <map>

#define LL long long

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); // Faster I/O
    std::cin.tie(nullptr);
    
    long long n;
    std::cin >> n;
    map<LL, LL> my;
    long long n2;
    std::cin >> n2;
    for (int i = 0; i < n;i++)
    {
        int n;std::cin >> n;
        my[n] = i;
        cout << my[i];
    }
    
}
