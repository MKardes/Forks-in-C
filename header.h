#ifndef FORK_H
# define FORK_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <fcntl.h>

static char     *ft_writer(char *str, int bas, int n)
{
        int     i;
        int     b;
        int     c;

        i = 0;
        if (n > 9)
        {
                while (i < bas)
                {
                        c = n;
                        b = bas - 1 - i;
                        while (b-- > 0)
                                c /= 10;
                        str[i++] = c % 10 + 48;
                }
        }
        else
        {
                str[i] = n + 48;
                i++;
        }
        str[i] = '\0';
        return (str);
}

static void     is_negative(int n, char *str, int bas)
{
        *str = '-';
        str++;
        str = ft_writer(str, bas, (n * -1));
        str = str - 1;
}

char    *ft_itoa(int n)
{
        int             i;
        int             a;
        int             n1;
        char    *str;

        n1 = n;
        a = 0;
        if (n1 < 0)
        {
                a = 1;
                n1 *= -1;
        }
        i = 1;
        while (n1 >= 10 && ++i)
                n1 = n1 / 10;
        if (n == -2147483648)
                return (strdup("-2147483648"));
        str = (char *)malloc(sizeof(char) * (i + a + 1));
        if (!str)
                return (0);
        else if (n < 0)
                is_negative(n, str, i);
        else
                ft_writer(str, i, n);
        return (str);
}

char    *ft_strjoin(char const *s1, char const *s2)
{
        int             i;
        int             len1;
        int             len2;
        char    *str;

        if (s1 && s2)
        {
                len1 = strlen(s1);
                len2 = strlen(s2);
                str = (char*)malloc(sizeof(char) * (len1 + len2 + 1));
                if (str == NULL)
                        return (NULL);
                i = -1;
                while (s1[++i])
                        str[i] = s1[i];
                i = -1;
                while (s2[++i])
                {
                        str[len1] = s2[i];
                        len1++;
                }
                str[len1] = '\0';
                return (str);
        }
        return (NULL);
}

#endif
