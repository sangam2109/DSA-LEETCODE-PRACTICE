class Solution
{
public:
    bool isPathCrossing(string path)
    {
        int x = 0, y = 0;
        set<pair<int, int>> s;
        s.insert({0, 0});
        for (auto i : path)
        {
            if (i == 'N')
                y++;
            else if (i == 'W')
                x--;
            else if (i == 'E')
                x++;
            else
                y--;
            if (s.count({x, y}))
                return true;
            else
                s.insert({x, y});
        }
        return false;
    }
};