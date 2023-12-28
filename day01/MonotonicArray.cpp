#include<vector>
class Solution
{
public:
    bool isMonotonic(std::vector<int> &nums)
    {
        bool decrease = false;
        bool increase = false;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] < nums[i + 1])
            {
                increase = true;
            }
            else if (nums[i] > nums[i + 1])
            {
                decrease = true;
            }
            if (increase & decrease)
            {
                return false;
            }
        }
        return true;
    }
};
