#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>


size_t ft_strlen(char *str)
{
    size_t i = 0;
    if (!str)
        return 0;
    while (str[i] != '\0')
        i++;
    return (i);
}

bool is_palindrome(char *str, int start, int end)
{
    while (start < end)
    {
        if (str[start++] != str[end--])
            return (false);
    }
    return (true);
}



void longest_palindrome(char *str)
{
    int start;
    int len;
    int maxlen;
    int i, j;

    len = ft_strlen(str);
    start = 0;
    maxlen = 1;

    for (i = 0; i < len; i++)
    {
        for (j = 0; j < len; j++)
        {
            if (is_palindrome(str, i, j) && (j - i + 1) > maxlen) // len of the current substring
            {
                start = i;
                maxlen = j - i + 1;
            }
        }
    
    }   
    write(1, str + start, maxlen);
    write(1, "\n", 1);

}




int main(int argc, char **argv)
{
    char *str = "Too hot to hoot";
    longest_palindrome(str);
    return 0;

}


