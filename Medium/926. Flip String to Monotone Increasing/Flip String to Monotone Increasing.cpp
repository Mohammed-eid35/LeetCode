class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int numOfFlips = 0;
        for (auto &c : s)
            numOfFlips += (c == '0');
        
        int minFlips = numOfFlips;
        for (auto &c : s) {
            if (c == '0')
                minFlips = min(minFlips, --numOfFlips);
            else
                ++numOfFlips;
        }

        return minFlips;
    }
};
