class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {

        vector<int> s_string(128, -1);
        vector<int> t_string(128, -1);

        for (int i = 0; i < s.length(); i++)
        {

            if (s_string[s[i]] == -1)
            {
                if (t_string[t[i]] != -1)
                {
                    return false;
                }
                s_string[s[i]] = t[i];
                t_string[t[i]] = s[i];
            }
            else if (s_string[s[i]] != t[i])
            {
                return false;
            }
        }

        return true;
    }
};
