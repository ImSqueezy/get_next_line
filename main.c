#include "get_next_line.h"
#include <string.h>

void init(char *p)
{
    int i;

    i = 0;
    while (i < BUFFER_SIZE)
    {
        p[i] = 'a';
        i++;
    }
}

int main()
{
    static char *st;
    char *p;

    free(st);
    int i = 0;
    while (i < BUFFER_SIZE)
    {
        printf("here");
        st[i++] = 'a';
    }
    i = 0;
    while (st[i])
        printf("%d, %d\n", i++, st[i]);
    printf("%p\n", p);
    p = (char *)malloc(BUFFER_SIZE + 1 * sizeof(char));
    if (!p)
        return (0);
    free(p);
    printf("%p", p);
    // printf("buffer size %d\n%ld\n", BUFFER_SIZE, strlen(p));
    // init(p);
    // // free(p);
    // printf("%p", p);
    // printf("%ld", strlen(p));
    // int i = 0;
    // while (i < BUFFER_SIZE)
    // {
    //     printf("%c", p[i]);
    //     i++;
    // }
    return (0);
}
