/* Написать программу, которая объединяет два упорядоченных по возрастанию массива в один, также упорядоченный, массив.*/
#include <iostream>
#include <clocale>   // для вывода сообщений на кириллице
#include <string>    // для std::string
#include <vector>    // для std::vector
#include <algorithm> // для std::swap

using  std::cout; using std::cin; using std::endl; using std::string; using std::vector;

// получаем от пользователя число
double get_number()
{
	double number;
	cin >> number;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Вы ввели что-то не очень похожее на число, попробуйте ещё раз: ";
		cin >> number;
	} 
	return number;
}

// получаем от пользователя упорядоченные значения, которые добавляем в вектор
void enter_array(const string& text_to_user, vector<double>& array)
{
	cout << text_to_user << endl << "Для завершения ввода введите любое отрицательное число" << endl;
	double previous_number = get_number();
	if (previous_number >=0 ) array.push_back(previous_number);
	while (previous_number >= 0)
	{
		double current_number = get_number();
		while ((current_number >= 0) && (current_number < previous_number))
		{
			cout << "Очередное число массива должно быть не меньше предыдущего!" << endl;
			current_number = get_number();
		}
		if (current_number < 0) break;
		array.push_back(current_number);
		previous_number = current_number;
	}
}

// Сортировка элементов вектора методом выбора
void Sort(vector<double>& array)
{
	const unsigned nNumber = array.size();
	// Перебираем каждый элемент массива
	// (кроме последнего, он уже будет отсортирован к тому времени, когда мы до него доберёмся)
	for (unsigned startIndex = 0; startIndex < (nNumber - 1); ++startIndex)
	{
		// В переменной minimumIndex хранится индекс наименьшего значения, которое мы нашли в этой итерации
		// Начинаем с того, что наименьший элемент в этой итерации - это первый элемент рассматриваемой части массива
		unsigned minimumIndex = startIndex;

		// Затем ищем элемент поменьше в остальной части массива
		for (unsigned currentIndex = (startIndex + 1); currentIndex < nNumber; ++currentIndex)
		{
			// Если мы нашли элемент, который больше нашего наименьшего элемента,
			if (array.at(currentIndex) < array.at(minimumIndex))
				// то запоминаем его
				minimumIndex = currentIndex;
		}
		// minimumIndex теперь индекс наименьшего элемента 

		// Меняем местами наше начальное наименьшее число с тем, которое мы обнаружили
		std::swap(array.at(startIndex), array.at(minimumIndex));
	}
}

// Вывод элементов массива
void vectorOutput(vector<double>& array)
{
	const unsigned nNumber = array.size();
	for (unsigned short i = 0; i < nNumber; i++)
		cout << array.at(i) << " ";
	cout << endl;
}

int main()
{
	setlocale(LC_CTYPE, "rus"); // "для вывода сообщений на кириллице

	vector<double> array{};
	enter_array("Введите элементы первого упорядоченного массива, от меньшего числа к большему.", array);
	enter_array("Введите элементы второго упорядоченного массива, от меньшего числа к большему.", array);
	Sort(array);
	cout << "Итоговый отсортированный массив из всех корректно введённых чисел:" << endl;
	vectorOutput(array);

	return 0;
}

