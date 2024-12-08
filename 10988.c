#include <stdio.h>
#include <string.h>
int main() {
    int len, k = 1;
    char str[100];
    scanf_s("%s", str, 100);
    len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - 1 - i]) {
            k = 0;
            break;
        }
    }
    printf("%d", k);
    return 0;
}