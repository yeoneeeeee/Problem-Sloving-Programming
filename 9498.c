#include <stdio.h>
int main() {
	int score;
	scanf_s("%d", &score);
	if (100>=score && score >= 90) {
		printf("A");
	}
	else if (89 >= score && score >= 80) {
		printf("B");
	}
	else if (79 >= score && score>=70) {
		printf("C");
	}
	else if (69 >= score && score >= 60) {
		printf("D");
	}
	else {
		printf("F");
	}
}
