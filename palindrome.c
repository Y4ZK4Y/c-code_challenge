/*
Assignment name  : biggest_pal
Expected files   : *.c, *.h
Allowed functions: write
--------------------------------------------------------------------------------

Write a program named biggest_pal that takes a string as argument and prints the
biggest palindrome included inside this string, followed by a newline.

This string contains only lowercase characters.

If there is two palindromes of the same length, you have to print the last one.

If there is more or less than 1 argument, your program must print only a newline
only.

Exemples:

$> biggest_pal "abcba"
abcba
$> biggest_pal "aaaaaaaaaabbcbbaaaa"
aaaabbcbbaaaa
$> biggest_pal "aooibdaoiwhoihwdoinzeldaisaboyobasiadlezfdsfnslk"
zeldaisaboyobasiadlez
$> biggest_pal "aeibaabaammaabaalek"
aabaammaabaa
$> biggest_pal abeb qpinqwjobo qkmnwoiq

$> biggest_pal

$>
*/

#include <unistd.h>
#include <stdbool.h>


size_t ft_strlen(char *str)
{
    size_t i = 0;
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
    maxlen = 1; //  a single character is a palindrome

    for (i = 0; i < len; i++)
    {
        for (j = i; j < len; j++)
        {
            // checks substrings for palindromes
            if (is_palindrome(str, i, j) && (j - i + 1) >= maxlen) // j-i+1: len of the current substring
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
    if (argc == 2)
        longest_palindrome(argv[1]);
    else
        write(1, "\n", 1);
    return 0;
}
