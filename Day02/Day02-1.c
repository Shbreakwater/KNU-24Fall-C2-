#include <stdio.h>
int main()
{
	int op;
	printf("첫번째 정수 입력 : ");
	scanf_s("%d", &op);

	double num1, num2, num3, num4;
	scanf_s("%lf", &num1);
	printf("첫번째 숫자");

	scanf_s("lf", &num2);
	printf("두번째 숫자");

	scnaf_s("lf", &num3);
	printf("세번째 숫자");

	scnaf_s("lf", &num4);
	printf("네번째 숫자");


	double result = 0.0;
	if (op == 1) {
		result = num1 + num2;
	}
	else if (op == 2) {
		result = num1 - num2;
	}
	else if (op == 3) {
		result = num1 * num2;
	}
	else if (op == 4)
	{
		result = num1 / num2;
	}
	else {
		printf("잘못입력했습니다.\n");
	}
	printf("result,lf\n", result);
	return 0;
}