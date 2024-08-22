// #include <iostream>
// #include <stack>
// #include <vector>
// #include <map>
// int main()
// {

// 	std::ios::sync_with_stdio(false); // making the input faster , i do know how, but its work hhh
// 	std::cin.tie(nullptr);

// 	int ac;
// 	std::cin >> ac;
//     long a,b;a=b=0;
// 	std::string s;
//     std::cin >> s;
//     int i = 0;
//     int f = 0;
//     while (s[i])
//     {
//         if (s[i] == 'A')
//         {
//             if (s[i + 1] == '2')
//                 a+=2;
//             else
//                 a++;
//         }
//        else if (s[i] == 'B')
//         {
//             if (s[i +1] == '2')
//                 b+=2;
//             else
//                 b++;
//         }
//         if (a = b)
//             f = 1;
//         std::cout << "hello";
//         i++;
//         i++;
//     }
//     std::cout << b;
//     if (f)
//     {
//         if (a >= b + 2)
//             std::cout << 'A';
//         else
//             std::cout << 'B';
//         std::cout << '\n';
//         return (0);
//     }
//     if (a > b)
//         std::cout << 'A';
//     else
//         std::cout << 'B';
//         std::cout << '\n';
    
// }

#include <iostream>

int main() {
    std::ios::sync_with_stdio(false); // Faster I/O
    std::cin.tie(nullptr);
    
    long a = 0, b = 0; // Scores for player A and B
    std::string s;
    std::cin >> s; // Input string representing the sequence of rounds

    int i = 0;
    bool f = false;
    while (s[i])
    {
        std::cout << "b =";
        std::cout << b;
        std::cout << "\n";
        if (s[i] == 'A')
        {
            if (s [i + 1] == '1')
                a++;
            else
                a+=2;
        }
        else if (s[i] == 'B')
        {
            if (s [i + 1] == '1')
                b++;
            else
                b+=2;
        }
        if (a == b)
        {
            if (a = 10)
                f = true;
        }
        // std::cout << a;std::cout << "\n";
        // std::cout << b;
        if (f)
        {
            if (a >= b+2)
            {
                std::cout << "A\n";return (0) ;
            }
            else if (a >= b+2)
            {
                std::cout << "B\n";return (0) ;
            }
        }
        i+=2;
    }
    // if (f) {
    //     if (a >= b + 2)
    //         std::cout << 'A';
    //     else
    //         std::cout << 'B';
    // } 
    // else {
    if (a > b)
        std::cout << 'A';
    else
        std::cout << 'B';
    // }
    std::cout << '\n';
    return 0;
}
