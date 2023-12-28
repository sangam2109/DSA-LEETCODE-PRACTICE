#include <string>
#include <algorithm>

class Solution
{
public:
    int maxScore(std::string s)
    {
        int cntOnes = 0;
        int maxScore = 0;

        for (char c : s)
        {
            if (c == '1')
            {
                cntOnes++;
            }
        }

        int cntZeros = 0;
        for (int i = 0; i < s.length() - 1; i++)
        {
            if (s[i] == '0')
            {
                cntZeros++;
            }
            else
            {
                cntOnes--;
            }

            maxScore = max(maxScore, cntZeros + cntOnes);
        }

        return maxScore;
    }
};
