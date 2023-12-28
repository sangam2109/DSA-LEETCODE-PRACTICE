#include <string>
using namespace std;
class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.length();
        if (n <= 1)
        {
            return s;
        }

        int maxLength = 1;
        int start = 0;

        for (int i = 0; i < n; i++)
        {
            // Check for odd-length palindromes
            int left = i;
            int right = i;
            while (left >= 0 && right < n && s[left] == s[right])
            {
                if (right - left + 1 > maxLength)
                {
                    maxLength = right - left + 1;
                    start = left;
                }
                left--;
                right++;
            }

            // Check for even-length palindromes
            left = i;
            right = i + 1;
            while (left >= 0 && right < n && s[left] == s[right])
            {
                if (right - left + 1 > maxLength)
                {
                    maxLength = right - left + 1;
                    start = left;
                }
                left--;
                right++;
            }
        }

        return s.substr(start, maxLength);
    }
};
