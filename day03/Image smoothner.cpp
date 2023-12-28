#include <vector>


class Solution
{
public:
    vector<vector<int>> imageSmoother(vector<vector<int>> &img)
    {
        // Save the dimensions of the image.
        int m = img.size();    // Number of rows
        int n = img[0].size(); // Number of columns

        // Create a new image of the same dimension as the input image to store the smoothed values.
        vector<vector<int>> smoothImg(m, vector<int>(n));

        // Iterate over the cells of the image.
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // Initialize the sum and count for averaging
                int sum = 0;
                int count = 0;

                // Iterate over all plausible nine indices around the current cell.
                for (int x = i - 1; x <= i + 1; x++)
                {
                    for (int y = j - 1; y <= j + 1; y++)
                    {
                        // Check if the indices form a valid neighbor within the image bounds.
                        if (0 <= x && x < m && 0 <= y && y < n)
                        {
                            sum += img[x][y]; // Accumulate the pixel value
                            count += 1;       // Increment count for averaging
                        }
                    }
                }

                // Store the averaged value (rounded down) in smoothImg[i][j].
                smoothImg[i][j] = sum / count;
            }
        }

        // Return the smoothed image.
        return smoothImg;
    }
};
