#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;


int main() {
    double temps[12][30][3];
    for (int month = 0; month < 12; month++) {
        for (int day = 0; day < 30; day++) {
            int val1 = rand() % 100 + 1, val2 = rand() % 100 + 1;
            if (val1 >= val2) {
                temps[month][day][0] = val2;
                temps[month][day][1] = val1;
            } else {
                temps[month][day][0] = val1;
                temps[month][day][1] = val2;
            }
            temps[month][day][2] = (val1 + val2) / 2;
        }

    }

    /*
    1. Any day's high and low temperature
    2. Any month high, low and average temperature for  a given month
    3. Month and day with the highest temperature
    4. Month and day with the lowest temperature
    5. All months average temperature to be printed in table format
    */

    cout << "\n\nChoose from the following options:\n" << string(80, '-') << endl <<
        "1. Any day's high and low temperature\n"
        "2. Any month high, low and average temperature for  a given month\n"
        "3. Month and day with the highest temperature\n"
        "4. Month and day with the lowest temperature\n"
        "5. All months average temperature to be printed in table format." << endl;
    cout << endl << "Choose: ";

    int choice;
    cin >> choice;

    switch (choice) {
    case 1:
        int d, m;
        double arr[3];
        cout << "Enter month and day: ";
        cin >> m >> d;
        for (int month = 0; month < 12; month++) {
            for (int day = 0; day < 30; day++) {
                if (m == month && d == day) {
                    for (int i = 0; i < 3; i++) {
                        arr[i] = temps[month][day][i];
                    }
                    break;
                }
            }
        }
        cout << endl << "low, high and average temperature of month " << m << " and day " << d << " is : \n";
        cout << string(25, '-') << endl
            << "Min: " << setw(5) << arr[0] << endl
            << "Max: " << setw(5) << arr[1] << endl
            << "Avg: " << setw(5) << arr[2];
        break;
    case 2:
        cout << "Enter month: ";
        cin >> m;
        for (int month = 0; month < 12; month++) {
            if (m == month) {
                cout << setw(7) << "minimum" << " |";
                for (int day = 0; day < 30; day++) {
                    cout << setw(4) << temps[month][day][0];
                }
                cout << endl << setw(7) << "maximum" << " |";
                for (int day = 0; day < 30; day++) {
                    cout << setw(4) << temps[month][day][1];
                }
                cout << endl << setw(7) << "average" << " |";
                for (int day = 0; day < 30; day++) {
                    cout << setw(4) << temps[month][day][2];
                }
                cout << endl;
            }
        }
    break;
    case 3:
        double highest;
        m, d;
        for (int month = 0; month < 12; month++) {
            for (int day = 0; day < 30; day++) {
                if (month == 0 && day == 0) {
                    highest = temps[0][0][1];
                    m = 0, d = 0;
                } else if (highest < temps[month][day][1]) {
                    highest = temps[month][day][1];
                    m = month, d = day;
                }
            }
        }
        cout << "\nMonth and day with highest temperature of "
            << highest << "C is month " << m + 1 << " day " << d + 1 << endl;
        cout << string(15, '=') << endl << temps[m][d][0] << " \t" << temps[m][d][1] << " \t" << temps[m][d][2];
        break;
    case 4:
        double lowest;
        for (int month = 0; month < 12; month++) {
            for (int day = 0; day < 30; day++) {
                if (month == 0 && day == 0) {
                    lowest = temps[0][0][1];
                    m = 0, d = 0;
                } else if (lowest > temps[month][day][1]) {
                    lowest = temps[month][day][1];
                    m = month, d = day;
                }
            }
        }
        cout << "\nMonth and day with lowest temperature of "
            << lowest << "C is month " << m + 1 << " day " << d + 1 << endl;
        break;
    case 5:
        cout << setw(5) << "|";
        for (int i = 0; i < 30; i++) {
            cout << setw(4) << i + 1;
        }
        cout << endl << " ___|" << string(120, '_') << endl;

        for (int month = 0; month < 12; month++) {
            cout << setw(3) << month + 1 << " |";
            for (int day = 0; day < 30; day++) {
                cout << setw(4) << temps[month][day][2];
            }
            cout << endl;
        }
        break;
    default:
        cout << "Invalid input. try again!\n";
        break;
}
}
