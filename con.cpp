// #include <stdio.h>
// int main()
// {
//     int ac;
//     scanf("%d", &ac);

//    for (int i =0; i < ac; i++)
//    {
//         int n;
//         scanf("%d", &n);
//         if (n > 0)
//             printf("%d", n + 2);
//         else
//             printf("%d", n);
//         if (i  != ac - 1)
//             printf(" ");
//    }
// }


#include <iostream>
#include <map>
int main()
{
    int ac;
    std::cin >> ac;
	std::map<std::string, int> myMap;
    for (int i = 0; i < ac; i++)
    {
		std::string s;
		std::cin >> s;
        myMap[s]++;
    }
	std::string s;
    int maxCount = 0;

    // Iterate through the map to find the word with the highest frequency
    for (const auto& pair : myMap) {
        if (pair.second >= maxCount)
		{
			

			if (std::lexicographical_compare(str1.begin(), str1.end(), str2.begin(), str2.end(), std::greater<>()))
			{
        		return str2;
   			}
			else
			{
   			    return str1;
   			}


            s = pair.first;
            maxCount = pair.second;
        }
    }
    std::cout << s << " " << maxCount << std::endl;
}
