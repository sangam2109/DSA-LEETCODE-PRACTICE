class Solution
{
public:
    vector<vector<int>> findMatrix(const vector<int> &nums)
    {
        unordered_map<int, vector<int>> numMap;

        // Populate the unordered_map with vectors of indices for each number
        for (int i = 0; i < nums.size(); ++i)
        {
            numMap[nums[i]].push_back(i);
        }

        // Create the 2D vector based on the indices
        vector<vector<int>> result;
        result.reserve(numMap.size()); // Reserve space for the result vector to improve efficiency

        for (const auto &pair : numMap)
        {
            const vector<int> &indices = pair.second;
            vector<int> row(nums.size(), 0);

            for (int i : indices)
            {
                // Place the number in the row at the corresponding index
                row[i] = pair.first;
            }

            result.push_back(move(row)); // Move the row to the result vector
        }

        return result;
    }
};