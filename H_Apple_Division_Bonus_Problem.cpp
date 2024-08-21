#include <iostream>
#include <stack>
#include <vector>
#include <map>
int main()
{

	std::ios::sync_with_stdio(false); // making the input faster , i do know how, but its work hhh
	std::cin.tie(nullptr);

	int ac;
	std::cin >> ac;
    long a,b;a=b=0;
	std::string s;
    std::cin >> s;
    int i = 0;
    int f = 0;
    while (s[i])
    {
        if (s[i] == 'A')
            a+=atoi(&s[i]);
        else if (s[i] == 'B')
            b+=atoi(&s[i]);
        if (a = b)
            f = 1;
        i++;
    }
    if (f)
    {
        if (a >= b + 2)
            std::cout << 'A';
        else
            std::cout << 'B';
        std::cout << '\n';
        return (0);
    }
    if (a > b)
        std::cout << 'A';
    else
        std::cout << 'B';
        std::cout << '\n';
    
}
/*



1 2 3 4 7





*/