#include <iostream>
#include <Windows.h>
#include <format> //C++20
#include <vector>
using namespace std;

int printArray(vector<int> array) {
	cout << "Массив: ";
	for (int i = 0; i < array.size(); i++)
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

int findInArrayMinimal(vector<int> vectorArray) {
	int minimalNumber = 2000000000;
	int minimalNumberIndex = -1;
	for (int i = 0; i < vectorArray.size(); i++)
		if (isSumMultipleSeven(vectorArray[i]) == 1) {
			if (vectorArray[i] < minimalNumber) {
				minimalNumberIndex = i;
				minimalNumber = vectorArray[i];
			}
		}
	return minimalNumberIndex;
}

int addToArray(vector<int> &vectorArray, int number) {
	int whereToInsert = findInArrayMinimal(vectorArray);

	if (whereToInsert == -1)
		vectorArray.push_back(number);
	else {
		vectorArray.emplace(vectorArray.begin() + whereToInsert, number);
	}
	return 0;
}

int findInArray(vector<int> vectorArray) {
	for (int i = 0; i < vectorArray.size(); i++)
		if (isSumMultipleSeven(vectorArray[i]) == 1)
			return i;
	return -1;
}

int removeFromArray(vector<int> &vectorArray) {
	if (vectorArray.size() <= 0) return -1;
	int numberToDeleteIndex;
	while (findInArray(vectorArray) != -1) {
		numberToDeleteIndex = findInArray(vectorArray);
		vectorArray.erase(vectorArray.begin() + numberToDeleteIndex);
	}
	return 0;
}

int main()
{
	vector<int> vectorArray;
	int newNumber;
	int result;

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "1. Вывод вектора\n"
		<< "2. Добавить элемент перед минимальным элементом, сумма цифр значения которого кратна 7\n"
		<< "3. Удалить элементы вектора, сумма цифр которого кратна 7\n"
		<< "4. Найти индекс элемента вектора, сумма цифр значения которого кратна 7\n"
		<< "0. Выход\n";

	char menu;
	while (true) {
		cout << "Выберите действие: ";
		cin >> menu;
		switch (menu) {
		case'1':
			printArray(vectorArray);
			break;
		case'2':
			cout << "Введите число: ";
			cin >> newNumber;
			if (addToArray(vectorArray, newNumber) == -1) cout << "Массив полон\n";
			else cout << "Элемент успешно добавлен\n";
			break;
		case'3':
			switch (removeFromArray(vectorArray)) {
			case 0:
				cout << "Элементы успешно удалены\n";
				break;
			case -1:
				cout << "Массив пуст\n";
				break;
			}
			break;
		case'4':
			result = findInArray(vectorArray);
			if (result == -1)cout << "Элемент, сумма цифр которого кратна 7, не найден\n";
			else cout << format("Элемент, сумма цифр которого кратна 7, найден в позиции {:d}\n", result);
			break;
		case'0':
			return 0;
			break;
		default:
			cout << "Неверный ввод!\n";
			cout << "1. Вывод вектора\n"
				<< "2. Добавить элемент перед минимальным элементом, сумма цифр значения которого кратна 7\n"
				<< "3. Удалить элементы вектора, сумма цифр которого кратна 7\n"
				<< "4. Найти индекс элемента вектора, сумма цифр значения которого кратна 7\n"
				<< "0. Выход\n"
				<< "Выберите действие: ";
			break;
		}
	}

}
