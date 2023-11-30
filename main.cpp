/********************************************
* Автор - Нургазин И.В                      *
* Блок - 4                                  *
* Задача - 3                                *
* Ссылка - https://onlinegdb.com/hewhHG9pG  *
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

    for (int monthNum = 0; monthNum < 12; monthNum++)
    {
        if ((year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) && monthNum == 1)
            days = 29;
        else
            days = monthDays[monthNum];

        cout << endl;
        if (year == currentYear && currentMonth == monthNum + 1)
        {
            cout << "\033[1;1;32m"
                << "  ------------" << monthList[monthNum] << "-------------"
                << "\033[0m" << endl;
        }
        else if (year < currentYear || (year == currentYear && monthNum + 1 < currentMonth))
        {
            cout << "\033[31m"
                << "  ------------" << monthList[monthNum] << "-------------"
                << "\033[0m" << endl;
        }
        else
        {
            cout << "  ------------" << monthList[monthNum] << "-------------"
                << endl;
        }

        if (year < currentYear || (year == currentYear && monthNum + 1 <= currentMonth))
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
        int spaces;
        for (spaces = 0; spaces < startingGap; spaces++)
            cout << "     ";

        for (int day = 1; day <= days; day++)
        {
            spaces++;
            if (year == currentYear && currentMonth == monthNum + 1 && currentDay == day)
            {
                cout << "\033[1;1;32m" << setw(5) << day << "\033[0m";
            }
            else if (year < currentYear || (year == currentYear && monthNum + 1 < currentMonth) || (year == currentYear && monthNum + 1 == currentMonth && day < currentDay))
            {
                cout << "\033[39m" << setw(5) << day << "\033[0m";
            }
            else
            {
                cout << "\033[31m" << setw(5) << setw(5) << day << "\033[0m";
            }
            if (spaces > 6)
            {
                spaces = 0;
                cout << endl;
            }
        }
        if (spaces)
            cout << endl;
        startingGap = spaces;
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
