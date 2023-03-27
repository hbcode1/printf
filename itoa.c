#include "main.h"

void rev_str(char *str, int a, int z)
{
    char tmp;
    
    if (a >= z)
    {
        return;
    }
    tmp = *(str + a);
    *(str + a) = *(str + z);
    *(str + z) = tmp;

    a++;
    z--;
    rev_str(str, a, z);
}
char *itoa(u_i n, char *str, int b)
{
    int i = 0, r;
    
    if (n == 0)
    {
        str[i] = '0';
        str[i + 1] = '\0';
        return str;
    }
    while (n != 0)
    {
        if (b == 17)
        {
            r = n % 16;
            str[i] = (r > 9) ? (r - 10) + 'A' : r + '0';
            i++;
            n /= 16;
        }
        else
        {
            r = n % b;
            str[i] = (r > 9) ? (r - 10) + 'a' : r + '0';
            i++;
            n /= b;
        }
    }
    rev_str(str, 0, i - 1);
    str[i] = '\0';
    return (str);
}