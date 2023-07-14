#include <map>
#include <string>
using namespace std;
class Solution
{
public:
    int romanToInt(string s)
    {
        map<char, int> roman = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000},
        };
        int sum = 0;

        for (int i = 0; i < s.length(); i++)
        {
            if (roman[s[i]] >= roman[s[i + 1]] && s[i + 1] != s.length())
            {
                sum += roman[s[i]];
            }
            else
            {
                sum -= roman[s[i]];
            }
        }
        return sum;
    }
};