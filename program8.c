#include <stdio.h>
#include <conio.h>
#include <string.h>

void main()
{
    char plaintext[50], ciphertext[50], key[50], mat[5][5];
    int i, j, m, n, k, len, flag = 0;
    printf("\n Enter the plaintext : ");
    gets(plaintext);
    printf("\n Enter the key : ");
    scanf("%s", key);
    m = n = 0;
    for (i = 0; key[i] != '\0'; i++)
    {
        for (j = 0; j < i && key[i] != key[j]; j++)
            ;
        if (j == i)
        {
            mat[m][n] = key[i];
            n++;
            if (n == 5)
            {
                mat[m][n] = '\0';
                m++;
                n = 0;
            }
        }
    }
    i = m * 5 + n;
    for (j = 0; j < 26; j++)
    {
        if (j == 9)
            continue;
        for (k = 0; k < i; k++)
        {
            m = k / 5;
            n = k % 5;
            if (mat[m][n] == 'a' + j)
                break;
        }
        if (k == i)
        {
            m = k / 5;
            n = k % 5;
            mat[m][n] = 'a' + j;
            i++;
            n++;
            if (n == 5)
            {
                mat[m][n] = '\0';
                m++;
                n = 0;
            }
        }
    }
    printf("\n The key matrix to be used is :\n");
    for (i = 0; i < 5; i++)
    {
        printf("\n");
        for (j = 0; j < 5; j++)
            printf("%c", mat[i][j]);
    }
    len = strlen(plaintext);
    for (i = 0; i < len - 1; i += 2)
    {
        if (plaintext[i] == plaintext[i + 1])
        {
            for (j = len; j > i; j--)
                plaintext[j] = plaintext[j - 1];
            plaintext[j + 1] = 'x';
            plaintext[len + 1] = '\0';
            len++;
        }
        for (m = 0; m < 5; m++)
        {
            for (n = 0; n < 5; n++)
                if (mat[m][n] == plaintext[i])
                    break;
            if (n != 5)
                break;
        }
        for (j = 0, flag = 0; j < 5; j++)
            if (plaintext[i + 1] == mat[m][j])
            {
                k = (n + 1) % 5;
                ciphertext[i] = mat[m][k];
                k = (j + 1) % 5;
                ciphertext[i + 1] = mat[m][k];
                flag = 1;
                break;
            }
        for (j = 0; j < 5 && !flag; j++)
            if (plaintext[i + 1] == mat[j][n])
            {
                k = (m + 1) % 5;
                ciphertext[i] = mat[k][n];
                k = (j + 1) % 5;
                ciphertext[i + 1] = mat[k][n];
                flag = 1;
                break;
            }
        for (j = 0; j < 5 && !flag; j++)
            for (k = 0; k < 5; k++)
                if (mat[j][k] == plaintext[i + 1])
                {
                    ciphertext[i] = mat[m][k];
                    ciphertext[i + 1] = mat[j][n];
                    break;
                }
    }
    ciphertext[len] = '\0';
    printf("\n\n Plaintext : %s", plaintext);
    printf("\n Ciphertext : %s", ciphertext);
    getch();
}
