#include <iostream>
#include <Windows.h>
#include <format> //C++20
using namespace std;

int printArray(int array[], int size) {
	cout << "Массив: ";
	for (int i = 0; i < size; i++)
		cout << array[i] << " ";
	cout << endl;
	return 0;
}

int isSumMultipleSeven(int number) {
	int sumOfNumbers = 0;
	while (number != 0) {
		sumOfNumbers += number % 10;
		number = number / 10;
	}
	if (sumOfNumbers % 7 == 0) return 1;
	return -1;
}

int findInArrayMinimal(int dynamicArray[], int& size) {
	int minimalNumber = 2000000000;
	int minimalNumberIndex = -1;
	for (int i = 0; i < size; i++)
		if (isSumMultipleSeven(dynamicArray[i]) == 1) {
			if (dynamicArray[i] < minimalNumber) {
				minimalNumberIndex = i;
				minimalNumber = dynamicArray[i];
			}
		}
	return minimalNumberIndex;
}

int addToArray(int*& dynamicArray, int& size, int number) {
	size++;

	dynamicArray = (int*)realloc(dynamicArray, size * sizeof(int));
	int whereToInsert = findInArrayMinimal(dynamicArray, size);

	if (whereToInsert == -1)
		dynamicArray[size - 1] = number;
	else {
		for (int i = size; i > whereToInsert; i--)
			dynamicArray[i] = dynamicArray[i - 1];
		dynamicArray[whereToInsert] = number;
	}
	return 0;
}

int findInArray(int dynamicArray[], int& size) {
	for (int i = 0; i < size; i++)
		if (isSumMultipleSeven(dynamicArray[i]) == 1)
			return i;
	return -1;
}

int removeFromArray(int dynamicArray[], int& size) {
	if (size <= 0) return -1;
	int numberToDeleteIndex;
	while (findInArray(dynamicArray, size) != -1) {
		numberToDeleteIndex = findInArray(dynamicArray, size);
		for (int i = numberToDeleteIndex; i < size; i++)
			dynamicArray[i] = dynamicArray[i + 1];
		size--;
	}
	return 0;
}

int main()
{
	int currentArraySize = 0;
	int* dynamicArray = new int[0];
	int newNumber;
	int result;

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

		cout << "1. Вывод массива\n"
		<< "2. Добавить элемент перед минимальным элементом, сумма цифр значения которого кратна 7\n"
		<< "3. Удалить элементы массива, сумма цифр которого кратна 7\n"
		<< "4. Найти индекс элемента массива, сумма цифр значения которого кратна 7\n"
		<< "0. Выход\n";

	char menu;
	while (true) {
		cout << "Выберите действие: ";
		cin >> menu;
		switch (menu) {
		case'1':
			printArray(dynamicArray, currentArraySize);
			break;
		case'2':
			cout << "Введите число: ";
			cin >> newNumber;
			if (addToArray(dynamicArray, currentArraySize, newNumber) == -1) cout << "Массив полон\n";
			else cout << "Элемент успешно добавлен\n";
			break;
		case'3':
			switch (removeFromArray(dynamicArray, currentArraySize)) {
			case 0:
				cout << "Элементы успешно удалены\n";
				break;
			case -1:
				cout << "Массив пуст\n";
				break;
			}
			break;
		case'4':
			result = findInArray(dynamicArray, currentArraySize);
			if (result == -1)cout << "Элемент, сумма цифр которого кратна 7, не найден\n";
			else cout << format("Элемент, сумма цифр которого кратна 7, найден в позиции {:d}\n", result);
			break;
		case'0':
			return 0;
			break;
		default:
			cout << "Неверный ввод!\n";
			cout << "1. Вывод массива\n"
				<< "2. Добавить элемент перед минимальным элементом, сумма цифр значения которого кратна 7\n"
				<< "3. Удалить элементы массива, сумма цифр которого кратна 7\n"
				<< "4. Найти индекс элемента массива, сумма цифр значения которого кратна 7\n"
				<< "0. Выход\n"
				<< "Выберите действие: ";
			break;
		}
	}

}
