#include <stdio.h>
#include <stdlib.h>


size_t ft_strlen(char *str)
{
    size_t i = 0;
    if (!str)
        return 0;
    while (str[i] != '\0')
        i++;
    return (i);
}


int anagram_checker(char *s1, char *s2)
{
    int len1, len2;
    int i;
    len1 = ft_strlen(s1);
    len2 = ft_strlen(s2);
    if (len1 != len2)
        return 1;
    int count[128] = {0};
    for (i = 0; i < len1; i++)
    {
        count[s1[i]]++;
        count[s2[i]]--;
    }
    for (i = 0; i < 128; i++)
        if (count[i] != 0)
            return 1;
    return 0;


}

int main()
{
    char *s1 = "hellot";
    char *s2 = "olleh";

    if (anagram_checker(s1, s2) == 0)
        printf("anagrams.\n");
    else
        printf("not anagrams.\n");
    return (0);
}

