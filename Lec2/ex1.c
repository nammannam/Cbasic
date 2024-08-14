#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Phai de con tro
char *my_strcat(const char *s1, const char *s2)
{
    // Cap phat dong
    char *str = (char *)malloc((strlen(s1) + strlen(s2) + 1) * sizeof(char));
    // Check
    if (str == NULL)
    {
        printf("Loi cap phat dong\n");
        exit(-1);
        return NULL;
    }
    int i, j;
    int len1 = strlen(s1), len2 = strlen(s2);
    // Con tro s1
    for (i = 0; i < len1; i++)
    {
        *(str + i) = *(s1 + i);
    }
    // Con tro s2
    for (j = 0; j <= len2; j++)
    {
        *(str + len1 + j) = *(s2 + j);
    }

    // Co the them gan = '\0' -> sua code

    return str;
}

int main()
{
    char s1[] = "Hello_";
    char s2[] = "World!";
    char *ptr = my_strcat(s1, s2);
    // Phai co check
    if (ptr == NULL)
    {
        return -1;
    }
    // gets(s1);
    // gets(s2);
    printf("Result : %s\n", ptr);
    free(ptr); // Quan trong

    return 0;
}