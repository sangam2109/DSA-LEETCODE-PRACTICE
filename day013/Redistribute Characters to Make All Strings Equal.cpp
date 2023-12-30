#include <string>
class Solution
{
public:
    bool makeEqual(vector<string> &words)
    {
        int n = words.size();
        if (n == 1)
        {
            return true;
        }
        int totalCharCount = 0;
        for (string s : words)
        {
            totalCharCount += s.size();
        }
        if (totalCharCount % n != 0)
        {
            return false;
        }
        int a[26] = {0};
        for (string s : words)
        {
            for (char c : s)
            {
                a[c - 'a']++;
            }
        }
        for (int i = 0; i < 26; i++)
        {
            if (a[i] % n != 0)
            {
                return false;
            }
        }
        return true;
    }
};