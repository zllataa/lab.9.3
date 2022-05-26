#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h> // забезпечення відображення кирилиці
using namespace std;


struct Ware
{
    string Name;//назва
    int price; //ціна
    int amount; //к-сть
    int integer; //одиниця вимірювання
};

void Create(Ware* w, const int N);
void Print(Ware* w, const int N);
void Sort(Ware* w, const int N);
int BinSearch(Ware* w, const int N, const string Name);

int main()
{
    SetConsoleCP(1251); // встановлення сторінки win-cp1251 в потік вводу
    SetConsoleOutputCP(1251); // встановлення сторінки win-cp1251 в потік виводу
    int N;
    cout << "Введіть к-сть товарів: "; cin >> N;

    Ware* w = new Ware[N];
    string Name;//назва
    int price; //ціна
    int amount; //к-сть
    int iamount;
    int integer; //одиниця вимірювання
    int found;

    int menuItem;
    do {
        cout << endl << endl << endl;
        cout << "Виберіть дію:" << endl << endl;
        cout << " [1] - введення даних з клавіатури" << endl;
        cout << " [2] - вивід даних на екран" << endl;
        cout << " [3] - фізичне впорядкування даних" << endl << endl; // Фізичне впорядкування масиву структур
        cout << " [4] - пошук товару" << endl;
        cout << "за назвою та к-тю" << endl << endl; // Бінарний пошук в масиві структур
        cout << " [0] - вихід та завершення роботи програми" << endl << endl;
        cout << "Введіть значення: "; cin >> menuItem;
        cout << endl << endl << endl;
        switch (menuItem)
        {
        case 1:
            Create(w, N);
            break;
        case 2:
            Print(w, N);
            break;
        case 3:
            Sort(w, N);
            break;
        case 4:
            cout << "Введіть ключі пошуку:" << endl;
            cout << " назва: "; getline(cin, Name);
            cin.get(); // очищуємо буфер клавіатури – бо залишаються символи
            cin.sync(); // "кінець рядка", які не дають ввести наступний літерний рядок
            cout << endl;
            if ((found = BinSearch(w, N, Name)) != -1)
                cout << "Знайдено працівника в позиції " << found + 1 << endl;
            else
                cout << "Шуканого працівника не знайдено" << endl;
            break;
        case 0:
            break;
        default:
            cout << "Ви ввели помилкове значення! "
                "Слід ввести число - номер вибраного пункту меню" << endl;
        }
    } while (menuItem != 0);
    return 0;
}

void Create(Ware* w, const int N)
{
    for (int i = 0; i < N; i++)
    {
        cout << "Товар № " << i + 1 << ":" << endl;
        cin.get();
        cin.sync();
        cout << " Назва товару: "; getline(cin, w[i].Name);
        cout << " Вартість одиниці в грн: "; cin >> w[i].price;
        cout << " Кількість: "; cin >> w[i].amount;
        cout << " Одиниця вимірювання “упаковка кг”: "; cin >> w[i].integer;
        cout << endl;
    }
}
void Print(Ware* w, const int N)
{
    cout << " " << endl;
    cout << " " << endl;
    cout << "  =========================================================================================================  " << endl;
    cout << " | № |     Назва товару     | Вартість одиниці в грн |  Кількість  |   Одиниця вимірювання “упаковка кг”  | " << endl;
    cout << "  =========================================================================================================  " << endl;
    for (int i = 0; i < N; i++)
    {
        cout << " | " << right << i + 1 << " ";
        cout << "| " << setw(20) << left << w[i].Name << " "
            << "| " << setw(22) << right << w[i].price << " ";
        cout << "| " << setw(18) << right << w[i].amount << " "
            << "| " << setw(30) << right << w[i].integer << " ";
        cout << endl;
    }
    cout << "  =========================================================================================================  " << endl;
    cout << endl;
}

void Sort(Ware* w, const int N) //Фізичне впорядкування масиву структур
{
    Ware tmp;
    for (int i0 = 0; i0 < N - 1; i0++)
        for (int i1 = 0; i1 < N - i0 - 1; i1++)
            if ((w[i1].Name > w[i1 + 1].Name)
                ||
                (w[i1].Name == w[i1 + 1].Name &&
                    w[i1].price > w[i1 + 1].price))

            {
                tmp = w[i1];
                w[i1] = w[i1 + 1];
                w[i1 + 1] = tmp;
            }
}

int BinSearch(Ware* w, const int N, const string Name, int amount)
{ // повертає індекс знайденого елемента або -1, якщо шуканий елемент відсутній
    int L = 0, R = N - 1, m;
    do {
        m = (L + R) / 2;
        if (w[m].Name == Name)
            return m;
       
    } while (L <= R);
    return -1;
}

