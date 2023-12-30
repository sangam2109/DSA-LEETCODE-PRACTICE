#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {

        if (numRows == 0)
        {
            return {};
        }
        vector<vector<int>> dp(numRows);
        for (int i = 0; i < numRows; i++)
        {
            dp[i].push_back(1);

            for (int j = 1; j < i; j++)
            {
                dp[i].push_back(dp[i - 1][j] + dp[i - 1][j - 1]);
            }

            if (i > 0)
            {
                dp[i].push_back(1);
            }
        }

        return dp;
    }
};
