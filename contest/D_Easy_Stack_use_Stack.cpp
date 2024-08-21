

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
	std::vector<long long> v;
	for (int i =0;i < ac;i++)
	{
		int u;
		std::cin >> u;
		v[i] = u;
	}
	std::cout << v[0];

}