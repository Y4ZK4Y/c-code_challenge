/*
Assignment name  : inter
Expected files   : inter.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and displays, without doubles, the
characters that appear in both strings, in the order they appear in the first
one.

The display will be followed by a \n.

If the number of arguments is not 2, the program displays \n.

Examples:

$>./inter "padinton" "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
padinto$
$>./inter ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6ewg4$
$>./inter "rien" "cette phrase ne cache rien" | cat -e
rien$
$>./inter | cat -e
$
*/

#include <unistd.h>

void inter(char *str1, char *str2)
{
    int i, j;
    int seen[256] = {0}; // array to keep track of the seen characters. (extended ASCII character set)
    for (i = 0; str1[i]; i++)
    {
        if (!seen[(unsigned char)str1[i]]) // if character not seen before
        {
            // loops over the characters of the second string
            for (j = 0; str2[j]; j++)
            {
                if (str1[i] == str2[j])
                {
                    write(STDOUT_FILENO, &str1[i], 1);
                    seen[(unsigned char)str1[i]] = 1; // mark the character as seen in the array
                    break;
                }
            }
        }
    }
}


int main(int argc, char **argv)
{
    if (argc == 3)
    {
        inter(argv[1], argv[2]);
        write(STDOUT_FILENO, "\n", 1);
    }
    else
        write(STDOUT_FILENO, "\n", 1);
    return (0);
}


