#include <stdio.h>
int main() {
	int A = 0, B = 0;
	scanf_s("%d %d", &A, &B);
	int sum = A + B;
	int gap = A - B;
	int mul = A * B;
	int div = A / B;
	int mol = A % B;
	printf("%d\n", sum);
	printf("%d\n", gap);
	printf("%d\n", mul);
	printf("%d\n", div);
	printf("%d\n", mol);
}