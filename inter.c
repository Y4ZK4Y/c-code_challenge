#include <stdio.h>
#include <unistd.h>



int main(int argc, char **argv)
{
    int i, j;
    int seen[128] = {0};
    if (argc == 3)
    {
        for (i = 0; argv[1][i]; i++)
        {
            if (!seen[(unsigned char)argv[1][i]]) // if character not seen
            {
                for (j = 0; argv[2][j]; j++)
                {
                    if (argv[1][i] == argv[2][j])
                    {
                        write(1, &argv[1][i], 1);
                        seen[(unsigned char)argv[1][i]] = 1;
                        break;
                    }
                }
            }

        }

    }
    write(1, "\n", 1);
    return (0);
}