#include <iostream>

int main() {
    std::ios::sync_with_stdio(false); // Faster I/O
    std::cin.tie(nullptr);

    int ac;
    std::cin >> ac; // Number of rounds (not really used here)
    
    long a = 0, b = 0; // Scores for player A and B
    std::string s;
    std::cin >> s; // Input string representing the sequence of rounds

    int i = 0;
    bool f = false;

    // Process the string to calculate scores
    while (s[i]) {
		printf("hello\n");
        if (s[i] == 'A')
            a++; // Increment score for A
        else if (s[i] == 'B')
            b++; // Increment score for B

        // Check if the game is tied
        if (a == b) {
            f = true;
        }
        i++;
    }

    // Determine the winner based on final scores
    if (f) {
        if (a >= b + 2)
            std::cout << 'A';
        else
            std::cout << 'B';
    } else {
        if (a > b)
            std::cout << 'A';
        else
            std::cout << 'B';
    }

    std::cout << '\n';
    return 0;
}
