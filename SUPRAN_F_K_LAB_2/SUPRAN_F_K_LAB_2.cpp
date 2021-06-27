#include <iostream>
#include <ctime>
#include <cmath>
#include <string>
#include <vector>
#include <functional>
/*
* Вторая лабораторная работа
* Автор: Супран Федор Константинович
* Группа: ПИ2-2
*/

/*
* Решение квадратного уравнения
*/
void func1()
{
	system("cls");
	double a, b, c, x;
	std::cout << "Введите значение a: ";
	std::cin >> a;
	std::cout << "Введите значение b: ";
	std::cin >> b;
	std::cout << "Введите значение c: ";
	std::cin >> c;
	if ((pow(b, 2) - 4 * a * c) >= 0) // Дискриминант больше или равен 0
	{
		x = (-1 * b + sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
		std::cout << "x1 = " << x << std::endl;
		x = (-1 * b - sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
		std::cout << "x2 = " << x << std::endl;
	}
	else
		std::cout << "Дискриминант меньше 0, корни невещественные." << std::endl;

	std::cout << "Для возврата в меню нажмите любую клавишу...";
	std::cin.ignore();
	std::cin.get();
}
/*
* Нахождение случайного числа в заданном диапазоне
*/
void func2()
{
	system("cls");
	int start, end;
	srand(time(NULL)); // Рандомизация генератора случайных чисел
	std::cout << "Введите значение начала диапазона: ";
	std::cin >> start;
	std::cout << "Введите значение конца диапазона: ";
	std::cin >> end;
	std::cout << "Случайное число из диапазона [" << start << ";" << end << "]: " 
		<< start + rand() % end << std::endl;

	std::cout << "Для возврата в меню нажмите любую клавишу...";
	std::cin.ignore();
	std::cin.get();
}
/*
* Сортировка массива из 10 элементов методом "пузырька"
*/
void func3()
{
	system("cls");
	const int SIZE = 10;
	int arr[SIZE];
	std::cout << "Введите 10 элементов массива: ";
	for (size_t i = 0; i < SIZE; i++) // Ввод массива
		std::cin >> arr[i];

	for (size_t i = 0; i < SIZE - 1; i++) // Сортировка методом "пузырька"
		for (size_t j = 0; j < SIZE - i - 1; j++)
			if (arr[j] > arr[j + 1])
				std::swap(arr[j], arr[j + 1]);

	std::cout << "Отсортированный массив: ";
	for (size_t i = 0; i < SIZE; i++) // Вывод массива
		std::cout << arr[i] << " ";
	std::cout << std::endl;

	std::cout << "Для возврата в меню нажмите любую клавишу...";
	std::cin.ignore();
	std::cin.get();
}
/*
* Меню для выбора функций
*/
void showMenu(std::vector<std::string> titleVector, std::vector<std::function<void()>> fVector)
{
	while (true)
	{
		system("cls");
		int choice = 0;
		std::cout << "============================\n";
		std::cout << "============Меню============\n";
		std::cout << "============================\n";
		for (size_t i = 0; i < titleVector.size(); i++)
			std::cout << i + 1 << ") " << titleVector[i] << std::endl;
		std::cout << "Введите номер выбранной задачи: ";
		std::cin >> choice;
		if (choice - 1 < 0 || choice - 1 >= titleVector.size())
			break;
		else
			fVector[choice - 1]();
	}
}
int main()
{
	setlocale(LC_ALL, "ru");
	std::vector<std::string> titleVector =
	{
		"Решение квадратного уравнения.",
		"Нахождение случайного числа в заданном диапазоне.",
		"Сортировка массива из 10 элементов методом \"пузырька\"."
	};
	std::vector<std::function<void()>> fVector = { func1, func2, func3 };
	showMenu(titleVector, fVector);
	return 0;
}