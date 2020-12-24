#include <stdio.h>
#include <conio.h>

void main()
{
    char plaintext[50], ciphertext[50];
    int i, key;
    printf("\n Enter the plaintext to be encrypted : ");
    gets(plaintext);
    printf("\n Enter the key to be used : ");
    scanf("%d", &key);
    i = 0;
    while (plaintext[i] != '\0')
    {
        ciphertext[i] = plaintext[i] + key;
        i++;
    }
    ciphertext[i] = '\0';
    printf("\n\n The given plaintext was %s", plaintext);
    printf("\n The encoded text is %s", ciphertext);
    printf("\n Decoding.....................");
    i = 0;
    while (ciphertext[i] != '\0')
    {
        plaintext[i] = ciphertext[i] - key;
        i++;
    }
    plaintext[i] = '\0';
    printf("\n\n The decoded plaintext is %s", plaintext);
    getch();
}
