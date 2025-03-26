/*STL2Seq2. Дан набор целых чисел. Заполнить список L исходными числами и вывести
элементы списка L вначале в исходном, а затем в обратном порядке.
*/
#include<list>
#include <iostream>
#include<fstream>
#include<cstdlib>
#include<ctime>
using namespace std;
void InputKeyboard(list<int>& L) 
{
    int n;
    cout << "Введите кол-во элементов:";
    cin >> n;
    cout << "Введите " << n << " целых чисел:";
    for (int i = 0; i < n; i++) 
    {
        int number;
        cin >> number;
        L.push_back(number);
    }

}
void InputRandom(list<int>& L, int count) 
{
    srand(static_cast<unsigned int>(time(0)));
    for (int i = 0; i < count; i++)
    {
        L.push_back(rand() % 101);
    }
}
void InputFile(list<int>& L)
{
    ifstream file("text.txt");
    if (!file) 
    {
        cout << "Ошибка открытия файла!" << endl;
        return;
    }
    int number;
    while (file >> number) 
    {
        L.push_back(number);
    }
    file.close();
}
void Print(const list<int>& L) 
{
    cout << "Исходный порядок: ";
    for (auto it = L.begin(); it != L.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    cout << "Обратный порядок: ";
    for (auto it = L.rbegin(); it != L.rend(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}
int main()
{      
    list<int> L;
    setlocale(LC_ALL, "rus");
    int choice;
    cout << "Выберите способ ввода данных:\n1. С клавиатуры\n2. Случайные числа\n3. Из файла\nВыбор: ";
    cin >> choice;
    switch (choice) 
    {
    case 1:
        InputKeyboard(L);
        break;
    case 2:
        int RandomCount;
        cout << "Введите кол-во случайных чисел:";
        cin >> RandomCount;
        InputRandom(L, RandomCount);
        break;
    case 3:
        InputFile(L);
        break;
    default:
        cout << "Неверный выбор!" << endl;
        return 0;

    }
    Print(L);
    return 0;

    

    
}


