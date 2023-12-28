#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    int maxWidthOfVerticalArea(vector<vector<int>> &points)
    {
        sort(points.begin(), points.end(), [](const auto &a, const auto &b)
             { return a[0] < b[0]; });

        int maxi = INT_MIN;
        for (auto i = 0; i < points.size() - 1; i++)
        {
            maxi = max(points[i + 1][0] - points[i][0], maxi);
        }

        return maxi;
    }
};
