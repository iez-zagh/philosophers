

#include <iostream>
#include <stack>
#include <algorithm>
int main()
{
	int ac;
	std::cin >> ac;
	std::stack<int> stack;;
	for (int i =0;i < ac;i++)
	{
		int n;
		std::cin >> n;
		if(n==1)
		{
			int u;
			std::cin >> u;
			stack.push(u);
		}
		if (n == 2)
		{
			stack.pop();
		}
		if (n ==3)
		{
			if (!stack.empty())
				std::cout << stack.top()<<"\n";
			else
				std::cout << "Empty!\n";
		}
	}
}