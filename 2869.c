#include <stdio.h>
int main() {
    int A, B, V;
    int day = 0;
    scanf_s("%d %d %d", &A, &B, &V);
    day += (V - B - 1) / (A - B) + 1;
    printf("%d", day);
    return 0;
}