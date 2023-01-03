#include <stdio.h>
#include <stdlib.h>

int opCheck(char* op) {
	switch (*op) {
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
		return 1;
	default:
		return 0;
	}
}
void calculate(char* op, float num1, float num2, float* result) {
	int isNum1Int, isNum2Int;
	switch (*op) {
	case '+':
		*result = num1 + num2;
		break;
	case '-':
		*result = num1 - num2;
		break;
	case '*':
		*result = num1 * num2;
		break;
	case '/':
		*result = num1 / num2;
		break;
	case '%':
		isNum1Int = ((int)num1 == num1);
		isNum2Int = ((int)num2 == num2);
		if (isNum1Int && isNum2Int)
			*result = (int)num1 % (int)num2;
		else
			*op = 'M';
		break;
	}
}
void getNum(float* num) {
	int numRead;
	do {
		printf("Enter number: ");
		numRead = scanf("%f", num);
		if (numRead != 1)
			printf("Invalid entry!!!\n");
		scanf("%*[^\n]");	//read past invalid input
	} while (numRead != 1);
}
void getOp(char* op) {
	int opRead;
	do {
		printf("Enter operator: ");
		scanf(" %c", op);
		opRead = opCheck(op);
		if (opRead != 1)
			printf("Invalid entry!!!\n");
		//read past invalid input
		scanf("%*[^\n]");
	} while (opRead != 1);
}
void print(char error, float result) {
	switch (error) {
	case 'M':
		printf("Error: (%c)Cannot mod floats.\n", error);
		return;
	}
	printf("Result: %f\n", result);
}

int main() {
	float num1, num2;
	float result = 0;
	char op;

	do {
		getNum(&num1);

		getOp(&op);

		getNum(&num2);

		calculate(&op, num1, num2, &result);

		print(op, result);

		system("pause");
	} while (1);
	return 0;
}