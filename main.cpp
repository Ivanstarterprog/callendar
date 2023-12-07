/********************************************
* Автор - Нургазин И.В                      *
* Блок - 4                                  *
* Задача - 3                                *
* Ссылка - https://onlinegdb.com/Nmu5iJeNbX *
********************************************/
#include <iostream>
#include <iomanip>

using namespace std;

void printCalendar(int year)
{
    int currentYear;
    int currentMonth;
    int currentDay;
    int days;
    int startingGap;
    int lastYear;
    int spaces;

    int monthDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    string monthList[12] = { "Январь", "Февраль", "Март", "Апрель", "Май", "Июнь", "Июль", "Август", "Сентябрь", "Октябрь", "Ноябрь", "Декабрь" };
    currentYear = 2023;
    currentMonth = 11;
    currentDay = 26;

    cout << " -----------------------------------" << endl;
    cout << "\033[1;33m"
        << "           Календарь - " << year
        << "\033[0m" << endl;
    cout << " -----------------------------------" << endl;

    lastYear = year - 1;
    startingGap = (lastYear + lastYear / 4 - lastYear / 100 + lastYear / 400) % 7;

    for (int monthIndex = 0; monthIndex < 12; ++monthIndex)
    {
        if ((year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) && monthIndex == 1) {
            days = 29;
        } else {
            days = monthDays[monthIndex];
        }
        cout << endl;
        if (year == currentYear && currentMonth == monthIndex + 1) {
            cout << "\033[1;1;32m"
                << "  ------------" << monthList[monthIndex] << "-------------"
                << "\033[0m" << endl;
        } else if (year < currentYear || (year == currentYear && monthIndex + 1 < currentMonth)) {
            cout << "\033[1;33m"
                << "  ------------" << monthList[monthIndex] << "-------------"
                << "\033[1;33m" << endl;
        } else {
            cout << "  ------------" << monthList[monthIndex] << "-------------"
                << endl;
        }

        if (year < currentYear || (year == currentYear && monthIndex + 1 <= currentMonth)) {
            cout << "\033[1;33m"
                << "  Пон  Втр  Срд  Чет  Пят";
            cout << "\033[35m"
                << "  Суб"
                << "\033[0m";
            cout << "\033[35m"
                << "  Вос"
                << "\033[0m" << endl;
        } else {
            cout << "  Пон  Втр  Срд  Чет  Пят  Суб  Вос" << endl;
        }
        for (spaces = 0; spaces < startingGap; ++spaces)
            cout << "     ";

        for (int day = 1; day <= days; ++day) {
            spaces++;
            if (year == currentYear && currentMonth == monthIndex + 1 && currentDay == day) {
                cout << "\033[1;1;32m" << setw(5) << day << "\033[0m";
            } else if (year < currentYear || (year == currentYear && monthIndex + 1 < currentMonth) || (year == currentYear && monthIndex + 1 == currentMonth && day < currentDay)) {
                cout << "\033[39m" << setw(5) << day << "\033[0m";
            } else {
                cout << "\033[31m" << setw(5) << setw(5) << day << "\033[0m";
            }
            if (spaces > 6) {
                spaces = 0;
                cout << endl;
            }
        }
        if (spaces) {
            cout << endl;
        }
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
