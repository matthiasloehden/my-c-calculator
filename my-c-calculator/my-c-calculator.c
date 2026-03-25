#include <stdio.h>
#include <stdlib.h>

int getConfirmationAndClearConsole()
{
	printf("Press Enter to continue or (n) to exit...\n");

	char input[100];

	while (fgets(input, sizeof(input), stdin)) {
		if (input[0] == 'n' || input[0] == 'N') {
			return 0;
		}

		if (input[0] == '\n') {
			break;
		}
	}


	system("cls");

	return 1;
}

int getOperationFromUser(char operations[][100], int numberOfOperations)
{
	char input[100];
	int operation = -1;

	printf("What do you want to do? (Enter the number of the operation)\n");

	for (int i = 0; i < numberOfOperations; i++) {
		printf("%d. %s\n", i + 1, operations[i]);
	}

	while (fgets(input, sizeof(input), stdin)) {
		if (sscanf_s(input, "%d", &operation) == 1 && operation >= 1 && operation <= numberOfOperations) {
			return operation - 1;
		}

		printf("Invalid operation. Try again: ");
	}

	return -1;
}

int getNumberFromUser()
{
	int number = 0;
	char input[100];

	printf("Enter a number: ");

	while (fgets(input, sizeof(input), stdin)) {
		if (sscanf_s(input, "%d", &number) == 1) {
			break;
		}
		else {
			printf("Invalid input. Try again: ");
		}
	}

	return number;
}

int runCalculator()
{
	char operations[4][100] = {
		"Add",
		"Subtract",
		"Multiply",
		"Divide"
	};

	int numberOfOperations = sizeof(operations) / sizeof(operations[0]);

	int operation = getOperationFromUser(operations, numberOfOperations);

	printf("You selected: %s.\n", operations[operation]);

	if (!getConfirmationAndClearConsole()) return 0;

	printf("Now, let's get the numbers for the %s operation.\n", operations[operation]);

	int firstNumber = getNumberFromUser();

	int secondNumber = getNumberFromUser();

	printf("You entered: %d and %d. Press Enter to continue with the %s operation.\n", firstNumber, secondNumber, operations[operation]);

	if (!getConfirmationAndClearConsole()) return 0;

	printf("Performing the %s operation on %d and %d...\n\n", operations[operation], firstNumber, secondNumber);

	switch (operation) {
	case 0: // Add
		printf("Result: %d\n", firstNumber + secondNumber);
		break;

	case 1: // Subtract
		printf("Result: %d\n", firstNumber - secondNumber);
		break;

	case 2: // Multiply
		printf("Result: %d\n", firstNumber * secondNumber);
		break;
	case 3: // Divide
		if (secondNumber == 0) {
			printf("Error: Division by zero is not allowed.\n");
		}
		else {
			printf("Result: %.2f\n", (float)firstNumber / secondNumber);
		}
		break;
	default:
		break;
	}

	printf("\nHuge Success!\n\n");

	if (!getConfirmationAndClearConsole()) return 0;

	return 1;
}

int main()
{
	printf("Welcome to the serious Calculator console app!\n");

	if (!getConfirmationAndClearConsole()) return 0;

	while (runCalculator()) {}

	return 0;
}
