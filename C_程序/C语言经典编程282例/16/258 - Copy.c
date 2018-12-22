#include <stdio.h>
#include <string.h>
void encode(char str[], int n)
{
    char c;
    int i;
    for (i = 0; i < strlen(str); i++)
    {
        c = str[i];
        if (c >= 'a' && c <= 'z')
            if (c + n % 26 <= 'z')
                str[i] = (char)(c + n % 26);
            else
                str[i] = (char)('a' + ((n - ('z' - c) - 1) % 26));
            else if (c >= 'A' && c <= 'Z')
                if (c + n % 26 <= 'Z')
                    str[i] = (char)(c + n % 26);
                else
                    str[i] = (char)('A' + ((n - ('Z' - c) - 1) % 26));
                else
                    str[i] = c;
    }
    printf("\nout:");
    puts(str);

}

void decode(char str[], int n)
{
    char c;
    int i;
    for (i = 0; i < strlen(str); i++)
    {
        c = str[i];
        if (c >= 'a' && c <= 'z')
            if (c - n % 26 >= 'a')
                str[i] = (char)(c - n % 26);
            else
                str[i] = (char)('z' - (n - (c - 'a') - 1) % 26);
            else if (c >= 'A' && c <= 'Z')
                if (c - n % 26 >= 'A')
                    str[i] = (char)(c - n % 26);
                else
                    str[i] = (char)('Z' - (n - (c - 'A') - 1) % 26);
                else
                    str[i] = c;
    }
    printf("\nout:");

    puts(str);

}

void main()
{
    void encode(char str[], int n);
    void decode(char str[], int n);
    //char str[]="abcdef";
    char *str;
    int k = 0, n = 0, i = 1;
    printf("\nPlease input strings:");
    scanf("%s", str);

    printf("\n1:Encryption");
    printf("\n2:Decryption");
    printf("\n3:Violent Crack");
    printf("\nPlease choose:");
    scanf("%d", &k);


    if (k == 1)
    {
        printf("\nPlease input number:");
        scanf("\n%d", &n);
        encode(str, n);
    }
    else if (k == 2)
    {
        printf("\nPlease input number:");
        scanf("%d", &n);
        decode(str, n);
    }
    else if (k == 3)
    {
        for (i = 1; i <= 25; i++)
        {
            printf("%d ", i);
            decode(str, 1);
        }
    }
}
