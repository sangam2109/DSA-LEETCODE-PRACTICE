#include <vector>
#include <algorithm>

class Solution
{
public:
    int findMaxLength(std::vector<int> &nums)
    {
        int maxLength = 0;
        int count = 0;
        std::vector<int> countMap(2 * nums.size() + 1, -2); // Initialize countMap with -2

        countMap[nums.size()] = -1; // Initialize count 0 at index nums.size()

        for (int i = 0; i < nums.size(); i++)
        {
            count += nums[i] == 1 ? 1 : -1; // Increment count for 1, decrement count for 0

            if (countMap[count + nums.size()] >= -1)
            {
                maxLength = std::max(maxLength, i - countMap[count + nums.size()]);
            }
            else
            {
                countMap[count + nums.size()] = i;
            }
        }

        return maxLength;
    }
};
