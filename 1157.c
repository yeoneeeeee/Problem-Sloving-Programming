#include <stdio.h>
#include <string.h>
char a[1000005];
int arr[26];
int main() {
    int max = 0;
    char ans = '?';
    scanf_s("%s", a, 1000005);
    int size = strlen(a);
    memset(arr, 0, sizeof(arr));
    for (int i = 0; i < size; i++) {
        if (a[i] >= 'a' && a[i] <= 'z')
            arr[a[i] - 'a']++;
        else if (a[i] >= 'A' && a[i] <= 'Z')
            arr[a[i] - 'A']++;
    }
    for (int i = 0; i < 26; i++) {
        if (arr[i] > max) {
            max = arr[i];
            ans = 'A' + i;
        }
        else if (arr[i] == max) {
            ans = '?';
        }
    }
    printf("%c\n", ans);
    return 0;
}