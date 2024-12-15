#include <stdio.h>
#include<string.h>

int main() {
	char a[15];
	scanf("%s", a);
	int time = 0;

	for (int i = 0; i < strlen(a); i++ ) {
		if (a[i] >= 65 && a[i] <= 67) time += 3;
		else if (a[i] >= 68 && a[i] <= 70)time += 4;
		else if (a[i] >= 71 && a[i] <= 73)time += 5;
		else if (a[i] >= 74 && a[i] <= 76)time += 6;
		else if (a[i] >= 77 && a[i] <= 79)time += 7;
		else if (a[i] >= 80 && a[i] <= 83)time += 8;
		else if (a[i] >= 84 && a[i] <= 86)time += 9;
		else if (a[i] >= 87 && a[i] <= 90)time += 10;
	}
	printf("%d", time);
	return 0;
}