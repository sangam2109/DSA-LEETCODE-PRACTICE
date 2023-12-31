class Solution
{
public:
    int countFlips(const string &s, char next)
    {
        int count = 0;
        for (char c : s)
        {
            if (next != c)
                count++;
            next = (next == '0') ? '1' : '0';
        }
        return count;
    }
    int minOperations(const string &s)
    {
        int result0 = countFlips(s, '0');
        int result1 = countFlips(s, '1');
        return min(result0, result1);
    }
};