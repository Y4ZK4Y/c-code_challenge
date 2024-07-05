#include <unistd.h>

void rotone(char *str)
{
    int i = 0;
    int c;
    while(str[i])
    {
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
        {
            if (str[i] == 'z' || str[i] == 'Z')
            {
                c = str[i] - 25;
                write(1, &c, 1);
            }
            else
            {
                c = str[i] + 1;
                write(1, &c, 1);
            }
        }
        else
            write(1, &str[i], 1);
        i++;
    }
}

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        rotone(argv[1]);
        write(1, "\n", 1);
    }
    else
        write(1, "\n", 1);
    return (0);
}