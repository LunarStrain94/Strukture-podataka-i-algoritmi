#include <stdio.h>
#include <string.h>

int mystrlen(char* str)
{
    int i;
    for (i = 0; ; ++i)
        if (str[i] == '\0')
            return i;
}

void mystrcpy(char* str, char* str2)
{
    int i, len = mystrlen(str2);

    for (i = 0; i <= len; ++i)
    {
        str[i] = str2[i];
    }
}

int mystrcmp(char* str, char* str2)
{
    int i, len = mystrlen(str2);
    for (i = 0; i <= len ; ++i)
    {
        if (str[i] == str2[i])
            continue;
        if (str[i] < str2[i])
            return -1;
        if (str[i] > str2[i])
            return 1;
    }
    return 0;
}

void mystrcat(char* str, char* str2)
{
    int i, j = 0, len = mystrlen(str2) + mystrlen(str);
    for (i = mystrlen(str); i <= len; ++i)
    {
        str[i] = str2[j];
        ++j;
    }
}

char* mystrstr(char* str, char* str2)
{
    int i, j;
    char* p = str;
    for (i = 0; str[i] != '\0'; i++)
    {
        for (j = 0; str[i + j] == str2[j]; j++)
        {
            p = &str[i];
            if (str2[j + 1] == '\0')
                return p;
        }
    }
    return p;
}

void reverse(char* str, char* str2)
{
    int i, j = mystrlen(str) - 1, len = mystrlen(str2), len2 = len + j;
    for (i = len; i <= len2; ++i)
    {
        str2[i] = str[j];
        --j;
        if (j < 0)
            break;
    }
}

int main()
{
    int a;
    char* p;
    char str[100] = "abaaaaabaa";
    char str2[100] = "aaab";

    //a = mystrlen(str);
    //printf("%d", a);

    //mystrcpy(str, str2);
    //printf("%s", str);

    //a = mystrcmp(str, str2);
    //printf("%d", a);

    //mystrcat(str, str2);
    //printf("%s", str);

    p = mystrstr(str, str2);
    printf("%d\n", p);
    printf("%s\n", p);

    //reverse(str, str2);
    //printf("%s", str2);
}
