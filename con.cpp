

#include <iostream>
#include <map>
int main()
{
	int ac;
	std::cin >> ac;
	int	arr1[ac];
	for (int i = 0; i < ac; i++)
	{
		int n;
		std::cin >> n;
		arr1[i] = n;
	}
	int ac2;
	std::cin >> ac2;
	int	arr2[ac2];
	for (int i = 0; i < ac2; i++)
	{
		int n;
		std::cin >> n;
		arr2[i] = n;
	}
	int flag = 0;
	int y = 0;
	int arr3[ac];
	for (int i = 0; i < ac; i++)
	{
   		for (int j = 0; j < ac2; j++)
		{
			if (arr1[i] == arr2[j])
			{
				flag = 1;
				break ;
			}
		}
		if (!flag)
			arr3[y++] = arr1[i];
		flag = 0;
	}
	std::cout << y << "\n";
	for (int i = 0; i < y; i++)
	{
		std::cout << arr3[i];
		if (i != y -1)
			std::cout << " ";
	}
}