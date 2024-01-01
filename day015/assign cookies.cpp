class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {

        if (g.size() == 0 || s.size() == 0)
            return 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int index = 0, count = 0;
        while (count < g.size() && index < s.size())
        {
            if (s[index] >= g[count])
                count++;
            index++;
        }
        return count;
    }
};
