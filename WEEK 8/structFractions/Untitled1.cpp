#include <stdio.h>
#include <math.h>

int main() {
	int num;
	printf("4 digit Armstrong numbers:\n");
	
	for (num = 1000; num <= 9999; ++num) {
		int originalNum = num;
		int tempNum = num;
		int sum = 0;
		
		while (tempNum > 0) {
			int digit = tempNum % 10;
			sum += pow(digit, 4);
			tempNum /= 10;
		}
		
		if (sum == originalNum) {
			printf("%d\n", originalNum);
		}
	}
	return 0;
}
