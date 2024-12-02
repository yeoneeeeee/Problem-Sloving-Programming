#include <stdio.h>
int main() {
	int X, N, a, b, sum = 0;
	scanf_s("%d", &X);
	scanf_s("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf_s("%d %d", &a, &b);
		sum += a * b;
	}
	if (sum == X) {
		printf("Yes");
	}
	else {
		printf("No");
	}
}
