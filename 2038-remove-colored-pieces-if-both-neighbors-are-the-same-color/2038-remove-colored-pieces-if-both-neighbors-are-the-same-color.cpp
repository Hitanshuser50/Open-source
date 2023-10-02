class Solution {
public:
    bool winnerOfGame(string colors) {
        int n = colors.length();
        int aliceWins = 0, bobWins = 0;
        for (int i = 1; i < n - 1; ++i) {
            if (colors[i - 1] == 'A' && colors[i] == 'A' && colors[i + 1] == 'A') {
                aliceWins++;
            } else if (colors[i - 1] == 'B' && colors[i] == 'B' && colors[i + 1] == 'B') {
                bobWins++;
            }
        }
        if (aliceWins > bobWins) {
            return true;
        }
        return false;
    }
};