class Solution
{
public:
    int longestPalindrome(string s)
    {
        char a[52] = {0};
        int oddcount = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] >= 'a' and s[i] <= 'z')
            {
                a[s[i] - 'a']++;
                if ((a[s[i] - 'a'] % 2 != 0))
                {
                    oddcount++;
                }
                else
                {
                    oddcount--;
                }
            }
            else
            {
                a[s[i] - 'A' + 26]++;
                if ((a[s[i] - 'A' + 26] % 2) != 0)
                {
                    oddcount++;
                }
                else
                {
                    oddcount--;
                }
            }
        }

        if (oddcount)
        {
            return s.size() - oddcount + 1;
        }
        return s.size() - oddcount;
    }
};