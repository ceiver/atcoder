#include <stdio.h>

int main()
{
    int N;
    char S[200] = "3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679";
    scanf("%d", &N);
    int i;
    for (i = 0; i <= N + 1; i++) {
        printf("%c", S[i]);
    }
    printf("\n");
    return 0;
}