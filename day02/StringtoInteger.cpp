#include <string>
using namespace std;
class Solution
{
public:
    int myAtoi(string s)
    {
        int sum = 0;
        int sign = 1;
        int i = 0;

        while (s[i] == ' ')
        {
            i++;
        }

        if (s[i] == '-' || s[i] == '+')
        {
            sign = (s[i++] == '-') ? -1 : 1;
        }

        if (s[i] < '0' || s[i] > '9')
        {
            return 0;
        }

        while (i < s.length() && s[i] >= '0' && s[i] <= '9')
        {
            int digit = s[i++] - '0';

            if (sum > INT_MAX / 10 || (sum == INT_MAX / 10 && digit > INT_MAX % 10))
            {
                return (sign == -1) ? INT_MIN : INT_MAX;
            }

            sum = sum * 10 + digit;
        }

        return sum * sign;
    }
};
