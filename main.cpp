/********************************************
* Автор - Нургазин И.В                      *
* Блок - 4                                  *
* Задача - 3                                *
* Ссылка - https://onlinegdb.com/ob1pHB5h0  *
********************************************/
#include <iostream>
#include <iomanip>

using namespace std;

void printCalendar(int year)
{

    int monthDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    string monthList[] = { "Январь", "Февраль", "Март", "Апрель", "Май", "Июнь", "Июль", "Август", "Сентябрь", "Октябрь", "Ноябрь", "Декабрь" };

    int currentYear = 2023;
    int currentMonth = 11;
    int currentDay = 26;

    cout << " -----------------------------------" << endl;
    cout << "\033[1;33m"
        << "           Календарь - " << year
        << "\033[0m" << endl;
    cout << " -----------------------------------" << endl;

    int days;
    int startingGap;

    int lastYear = year - 1;
    startingGap = (lastYear + lastYear / 4 - lastYear / 100 + lastYear / 400) % 7;

    for (int i = 0; i < 12; i++)
    {
        if ((year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) && i == 1)
            days = 29;
        else
            days = monthDays[i];

        cout << endl;
        if (year == currentYear && currentMonth == i + 1)
        {
            cout << "\033[1;1;32m"
                << "  ------------" << monthList[i] << "-------------"
                << "\033[0m" << endl;
        }
        else if (year < currentYear || (year == currentYear && i + 1 < currentMonth))
        {
            cout << "\033[31m"
                << "  ------------" << monthList[i] << "-------------"
                << "\033[0m" << endl;
        }
        else
        {
            cout << "  ------------" << monthList[i] << "-------------"
                << endl;
        }

        if (year < currentYear || (year == currentYear && i + 1 <= currentMonth))
        {
            cout << "\033[1;33m"
                << "  Пон  Втр  Срд  Чет  Пят";
            cout << "\033[35m"
                << "  Суб"
                << "\033[0m";
            cout << "\033[35m"
                << "  Вос"
                << "\033[0m" << endl;
        }
        else
        {
            cout << "  Пон  Втр  Срд  Чет  Пят  Суб  Вос" << endl;
        }
        int k;
        for (k = 0; k < startingGap; k++)
            cout << "     ";

        for (int j = 1; j <= days; j++)
        {
            k++;
            if (year == currentYear && currentMonth == i + 1 && currentDay == j)
            {
                cout << "\033[1;1;32m" << setw(5) << j << "\033[0m";
            }
            else if (year < currentYear || (year == currentYear && i + 1 < currentMonth) || (year == currentYear && i + 1 == currentMonth && j < currentDay))
            {
                cout << "\033[39m" << setw(5) << j << "\033[0m";
            }
            else
            {
                cout << "\033[31m" << setw(5) << setw(5) << j << "\033[0m";
            }
            if (k > 6)
            {
                k = 0;
                cout << endl;
            }
        }
        if (k)
            cout << endl;
        startingGap = k;
    }
    return;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int year;
    while (1)
    {
        cout << "------------------------------------------------" << endl;
        cout << "Введите год чтобы начать, или любой символ чтобы выйти: ";
        cin >> year;
        cout << "------------------------------------------------" << endl;
        if (cin.fail())
            break;
        printCalendar(year);
    }

    return 0;
}
