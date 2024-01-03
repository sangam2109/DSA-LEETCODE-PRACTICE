class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        vector<int> a(26, 0);
        for (char c : magazine)
        {
            a[c - 'a']++;
        }

        for (char c : ransomNote)
        {
            if (a[c - 'a'] > 0)
            {
                a[c - 'a']--;
            }
            else
            {
                return false;
            }
        }

        return true;
    }
};
