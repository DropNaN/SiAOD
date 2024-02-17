#include <iostream>
#include <Windows.h>
#include <format> //C++20
using namespace std;
const int maxStaticSize = 10;

int printArray(int array[], int size) {
	cout << "������: ";
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

int findInArrayMinimal(int staticArray[], int& size) {
	int minimalNumber = 2000000000;
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

	cout << "1. ����� �������\n"
		<< "2. �������� ������� ����� ����������� ���������, ����� ���� �������� �������� ������ 7\n"
		<< "3. ������� �������� �������, ����� ���� �������� ������ 7\n"
		<< "4. ����� ������ �������� �������, ����� ���� �������� �������� ������ 7\n"
		<< "0. �����\n";

	char menu;
	while (true) {
		cout << "�������� ��������: ";
		cin >> menu;
		switch (menu) {
		case'1':
			printArray(staticArray, currentStaticSize);
			break;
		case'2':
			cout << "������� �����: ";
			cin >> newNumber;
			if (addToArray(staticArray, currentStaticSize, newNumber) == -1) cout << "������ �����\n";
			else cout << "������� ������� ��������\n";
			break;
		case'3':
			switch (removeFromArray(staticArray, currentStaticSize)) {
			case 0:
				cout << "�������� ������� �������\n";
				break;
			case -1:
				cout << "������ ����\n";
				break;
			}
			break;
		case'4':
			result = findInArray(staticArray, currentStaticSize);
			if (result == -1)cout << "�������, ����� ���� �������� ������ 7, �� ������\n";
			else cout << format("�������, ����� ���� �������� ������ 7, ������ � ������� {:d}\n", result);
			break;
		case'0':
			return 0;
			break;
		default:
			cout << "�������� ����!\n";
			cout << "1. ����� �������\n"
				<< "2. �������� ������� ����� ����������� ���������, ����� ���� �������� �������� ������ 7\n"
				<< "3. ������� �������� �������, ����� ���� �������� ������ 7\n"
				<< "4. ����� ������ �������� �������, ����� ���� �������� �������� ������ 7\n"
				<< "0. �����\n"
				<< "�������� ��������: ";
			break;
		}
	}

}