#include <stdio.h>

int my_strlen(const char *str)
{
    int length = 0;
    while (str[length] != '\0')
    {
        length++;
    }
    return length;
}

char *my_strcpy(char *dest, const char *src)
{
    int i = 0;
    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}

char *my_strcat(char *dest, const char *src)
{
    int dest_len = my_strlen(dest);
    int i = 0;
    
    while (src[i] != '\0')
    {
        dest[dest_len + i] = src[i];
        i++;
    }
    dest[dest_len + i] = '\0';
    return dest;
}

int my_strcmp(const char *str1, const char *str2)
{
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0')
    {
        if (str1[i] != str2[i])
        {
            return (unsigned char)str1[i] - (unsigned char)str2[i];
        }
        i++;
    }
    return (unsigned char)str1[i] - (unsigned char)str2[i];
}

char *my_strstr(const char *haystack, const char *needle)
{
    if (*needle == '\0')
    {
        return (char *)haystack;
    }

    for (int i = 0; haystack[i] != '\0'; i++)
    {
        int j = 0;
        while (haystack[i + j] != '\0' && haystack[i + j] == needle[j])
        {
            j++;
            if (needle[j] == '\0')
            {
                return (char *)&haystack[i];
            }
        }
    }
    return NULL;
}

int main(void)
{
    printf("=== TESTING MY STRING LIBRARY ===\n\n");

    printf("--- 1. my_strlen ---\n");
    printf("Test 1 (\"hello\"): %d\n", my_strlen("hello"));
    printf("Test 2 (\"\"): %d\n", my_strlen(""));
    printf("Test 3 (\"CS50\"): %d\n\n", my_strlen("CS50"));

    printf("--- 2. my_strcpy ---\n");
    char buf1[50];
    printf("Test 1: %s\n", my_strcpy(buf1, "hello"));
    printf("Test 2: %s\n", my_strcpy(buf1, "world"));
    printf("Test 3: \"%s\"\n\n", my_strcpy(buf1, ""));

    printf("--- 3. my_strcat ---\n");
    char buf2[50] = "hello";
    printf("Test 1: %s\n", my_strcat(buf2, " world"));
    printf("Test 2: %s\n", my_strcat(buf2, "!"));
    printf("Test 3: %s\n\n", my_strcat(buf2, ""));

    printf("--- 4. my_strcmp ---\n");
    printf("Test 1 (\"apple\", \"banana\"): %d\n", my_strcmp("apple", "banana"));
    printf("Test 2 (\"code\", \"code\"): %d\n", my_strcmp("code", "code"));
    printf("Test 3 (\"zoo\", \"apple\"): %d\n\n", my_strcmp("zoo", "apple"));

    printf("--- 5. my_strstr ---\n");
    char *res1 = my_strstr("hello world", "world");
    printf("Test 1 (\"hello world\", \"world\"): %s\n", res1 ? res1 : "NULL");

    char *res2 = my_strstr("programming", "gram");
    printf("Test 2 (\"programming\", \"gram\"): %s\n", res2 ? res2 : "NULL");

    char *res3 = my_strstr("hello", "xyz");
    printf("Test 3 (\"hello\", \"xyz\"): %s\n", res3 ? res3 : "NULL");

    return 0;
}