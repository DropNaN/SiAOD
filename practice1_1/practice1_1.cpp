#include <iostream>
#include <Windows.h>
#include <format> //C++20
using namespace std;
const int maxStaticSize = 10;

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
	return 0;
}

int findInArrayMinimal(int staticArray[], int& size) {
	int minimalNumber = INT_MAX;
	int minimalNumberIndex = -1;
	for (int i = 0; i < size; i++)
		if (isSumMultipleSeven(staticArray[i]) == 1) {
			if (staticArray[i] < minimalNumber) {
				minimalNumberIndex = i;
				minimalNumber = staticArray[i];
			}
		}
	return minimalNumberIndex;
}

int addToArray(int staticArray[], int& size, int number) {
	if (size >= maxStaticSize) return -1;
	size++;

	int whereToInsert = findInArrayMinimal(staticArray, size);

	if (whereToInsert == -1)
		staticArray[size - 1] = number;
	else {
		for (int i = size; i > whereToInsert; i--)
			staticArray[i] = staticArray[i - 1];
		staticArray[whereToInsert] = number;
	}
	return 0;
}

int findInArray(int staticArray[], int& size) {
	for (int i = 0; i < size; i++)
		if (isSumMultipleSeven(staticArray[i]) == 1)
			return i;
	return -1;
}

int removeFromArray(int staticArray[], int& size) {
	if (size <= 0) return -1;
	int numberToDeleteIndex;
	while (findInArray(staticArray, size) != -1) {
		numberToDeleteIndex = findInArray(staticArray, size);
		for (int i = numberToDeleteIndex; i < size; i++)
			staticArray[i] = staticArray[i + 1];
		size--;
	}
	return 0;
}

int main()
{
	int currentStaticSize = 0;
	int staticArray[maxStaticSize];
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
			printArray(staticArray, currentStaticSize);
			break;
		case'2':
			cout << "Введите число: ";
			cin >> newNumber;
			if (addToArray(staticArray, currentStaticSize, newNumber) == -1) cout << "Массив полон\n";
			else cout << "Элемент успешно добавлен\n";
			break;
		case'3':
			switch (removeFromArray(staticArray, currentStaticSize)) {
			case 0:
				cout << "Элементы успешно удалены\n";
				break;
			case -1:
				cout << "Массив пуст\n";
				break;
			}
			break;
		case'4':
			result = findInArray(staticArray, currentStaticSize);
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