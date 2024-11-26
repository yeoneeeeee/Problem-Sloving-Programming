#include <stdio.h>
int main() {
    int a, b, c;
    scanf_s("%d %d %d", &a, &b, &c); 
    int prize = 0; 
    if (a == b && b == c) {
        prize = 10000 + a * 1000;
    }
    else if (a == b || b == c || a == c) {
        if (a == b || a == c) {
            prize = 1000 + a * 100;
        }
        else {
            prize = 1000 + b * 100;
        }
    }
    else {
        int max = a; 
        if (b > max) {
            max = b;
        }
        if (c > max) {
            max = c;
        }
        prize = max * 100;
    }
    printf("%d\n", prize);
    return 0;
}