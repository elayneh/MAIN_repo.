#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <conio.h>
#include <ctime>
#include <cstdlib>

using namespace std;

const int MONTH = 12, DAY = 30;

// holds daily high, low and average temprature of the year 2010 E.C
double dailyTempretures[MONTH][DAY][3];
// just holds options for readablitiy
enum Options {
    TEMPRATURE_OF_DAY = 1,
    TEMPRATURES_OF_MONTH,
    HIGHEST_TEMPRATURE,
    LOWEST_TEMPRATURE,
    PRINT_TEMPRATURES,
    GENERATE_DATA,
    ACCEPT_INPUT,
    PRINT_OPTIONS
};

enum DailyTemprature { LOW, HIGH, AVG };
void printTable();
void printOptions();
string ethMonth(unsigned int);
void printLine(unsigned int, char fill = '-');
void generateSampleData();
void loadSampleData();
void acceptDailyTemp();
void saveToFile();
void clearScreen();
void printTitle(string, unsigned int width = 90);
double averageTemperature(unsigned int);
double lowestTemperature(unsigned int);
double highestTemperature(unsigned int);
bool validate(unsigned int, unsigned int);

int main() {
    clearScreen();
    // loads sample data
    cout << "Loading data into memory ..." << endl;
    loadSampleData();
    cout << "done." << endl;
    do {
        printOptions();
        cout << endl << "What do you want to do? ";
        unsigned int choice;
        cin >> choice;
        unsigned int day, month; // used for user input  
        clearScreen();
        switch (choice) {
        case TEMPRATURE_OF_DAY:
            printTitle("Temprature for a Day");
            cout << "Enter month and day: ";
            cin >> month >> day;
            // checks/validates user input. 
            if (!validate(month, day)) {
                cout << "Out of range(month must be between 1 & 12 and "
                    "day should be betwee 1 & 30). Please try again";
                continue;
            }

            cout << endl << "Daily temperature for "
                << ethMonth(month) << " " << day << " is : \n";
            printLine(90); // prints long line
            for (int i = 0; i < 3; i++) {
                string str = i == LOW ? "Low" : (i == HIGH ? "High" : "Average");
                cout << left << setw(7) << str << " |" << right << setw(3)
                    << dailyTempretures[month - 1][day - 1][i] << endl;
            }
            break;

        case TEMPRATURES_OF_MONTH:
            printTitle("Temperatures of the Month");
            cout << "Enter month: ";
            cin >> month;
            // checks/validates user input. 
            if (month < 1 && month > 12) {
                cout << "Out of range(month must be between 1 & 12). Please try again";
                continue;
            }
            cout << "Temperatures of " << ethMonth(month) << endl;
            cout << "Lowest  Temperature: " << setw(6) << lowestTemperature(month) << endl;
            cout << "Highest Temperature: " << setw(6) << highestTemperature(month) << endl;
            cout << "Average Temperature: " << setw(6) << setprecision(2) << averageTemperature(month) << endl;

            break;
        case HIGHEST_TEMPRATURE: {
            printTitle("Highest Temperature for a Year 2010 E.C");
            double highest, currTemp;
            for (int m = 0; m < MONTH; m++) {
                currTemp = highestTemperature(m+1);
                if (m == 0)
                    highest = currTemp;
                else if (highest < currTemp)
                    highest = currTemp;
            }
            cout << "Highest temprature recorded in the year is "
                << highest << " Celsius." << endl;
            break;
        }
        case LOWEST_TEMPRATURE: {
            printTitle("Lowest Temperature for a Year 2010 E.C");
            double lowest, currTemp;
            for (int m = 0; m < MONTH; m++) {
                currTemp = lowestTemperature(m+1);
                if (m == 0)
                    lowest = currTemp;
                else if (lowest > currTemp)
                    lowest = currTemp;
            }
            cout << "Lowest temprature recorded in the year is "
                << lowest << " Celsius." << endl;
            break;
        }
        case PRINT_TEMPRATURES:
            printTitle("Daily Temperatures for year 2010 E.C. ", 163);
            printTable();
            break;
        case GENERATE_DATA:
            printTitle("Generating New Sample Temperature Data");
            generateSampleData();
            cout << "done" << endl;
            break;
        case ACCEPT_INPUT:
            printTitle("Accepting Daily Temperature");
            acceptDailyTemp();
            break;

        default:
            cout << "Invalid input. try again!\n";
            break;
        }

        cout << "\n Do you wish to continue? (press 'n' to quit or press any other key to continue): ";
        char tryAgain = getch();
        clearScreen();
        if (tryAgain == 'n') break;
        else continue;
    } while (true);
}
// finds a average temperature for month m
double averageTemperature(unsigned int month) {
    double sum = 0;
    for (int d = 0; d < DAY; d++) {
        sum += dailyTempretures[month - 1][d][AVG];
    }
    return sum / DAY;
}
// finds a lowest temperature for the month m
double lowestTemperature(unsigned int m) {
    double lowest;
    for (int d = 0; d < DAY; d++) {
        double currTemp = dailyTempretures[m - 1][d][LOW];
        if (d == 0)
            lowest = currTemp;
        else if (lowest > currTemp)
            lowest = currTemp;
    }
    return lowest;
}
// finds highest temperature for the month m
double highestTemperature(unsigned int m) {
    double highest;
    for (int d = 0; d < DAY; d++) {
        double currTemp = dailyTempretures[m - 1][d][HIGH];
        if (d == 0)
            highest = currTemp;
        else if (highest < currTemp)
            highest = currTemp;
    }
    return highest;
}

// clears console screen
void clearScreen() {
    system("cls");
}

// prints centered 
void printTitle(string title, unsigned int width) {
    printLine(width, '~');
    cout << string((width - title.length()) / 2, ' ') << title << endl;
    printLine(width, '~');
}

//  Prints average tempratures of the year in table.
void printTable() {
    printLine(163, '_');
    cout << "| " << left << setw(8) << "Days" << "|";
    // prints days header for table
    for (int i = 0; i < DAY; i++) {
        cout << right << setw(5) << i + 1;
    }
    cout << " |" << endl;
    // prints 130 character long dividing line
    printLine(163);

    for (int month = 0; month < MONTH; month++) {
        // prints month on front of each row
        cout << "| " << left << setw(7) << ethMonth(month + 1) << " |";
        // prints average temprature for every day of the year
        for (int day = 0; day < DAY; day++) {
            cout << right << setw(5) << dailyTempretures[month][day][AVG];
        }
        cout << " |" << endl;
    }
    printLine(163);
}

// prints options
void printOptions() {
    cout << endl;
    printTitle("National Metrology Agency of Ethiopia - Daily Temperatures for year 2010 E.C.");
    cout << "\nChoose corresponding number from  the following options:\n\n";
    cout << "\t1. Highest and Lowest Temperature of a day \n\n"
        "\t2. High, low and average temperature of a month\n\n"
        "\t3. Month and day with the highest temperature\n\n"
        "\t4. Month and day with the lowest temperature\n\n"
        "\t5. Print average tempratures of each day of the year in table format.\n\n"
        "\t6. Generate sample data and save to `sample_temp.txt` file\n\n"
        "\t7. Accept User input for each day.\n\n"
        << endl;
}

//   changes number corresponding ethiopian month name
string ethMonth(unsigned int month) {

    switch (month) {
    case 1:
        return "Meskrem";
        break;
    case 2:
        return "Tikmit";
        break;
    case 3:
        return "Hidar";
        break;
    case 4:
        return "Tahisas";
        break;
    case 5:
        return "Tir";
        break;
    case 6:
        return "Yekatit";
        break;
    case 7:
        return "Megabit";
        break;
    case 8:
        return "Miaziya";
        break;
    case 9:
        return "Ginbot";
        break;
    case 10:
        return "Sene";
        break;
    case 11:
        return "Hamel";
        break;
    case 12:
        return "Nehase";
        break;
    default:
        throw invalid_argument("expected integer between 1 and 12");
        break;
    }
}

// print n character long line with specfied fill character
void printLine(unsigned int length, char fill) {
    cout << string(length, fill) << endl;
}

/*
*  generates sample daily temperature data into file `daily_temp.txt`.
*  the random numbers are between 1 and 100 celisuis(not realistic).
*/
void generateSampleData() {
    // randomize random number generator using current time
    srand((unsigned int)time(0));

    for (int month = 0; month < MONTH; month++) {
        for (int day = 0; day < DAY; day++) {
            int val1 = rand() % 50 + 1, val2 = rand() % 50 + 1;

            double low = val1 >= val2 ? val2 : val1;
            double high = val1 >= val2 ? val1 : val2;
            double average = (val1 + val2) / 2;

            dailyTempretures[month][day][LOW] = low;
            dailyTempretures[month][day][HIGH] = high;
            dailyTempretures[month][day][AVG] = average;
        }
    }
    saveToFile();
}

// loades sample temperature data from `daily_temp.txt` file 
void loadSampleData() {
    ifstream inTempratureFile("daily_temp.txt");

    if (!inTempratureFile) {
        cout << "Unable to open file. please try again!" << endl;
        exit(EXIT_FAILURE);
    }
    for (int month = 0; month < MONTH; month++) {
        for (int day = 0; day < DAY; day++) {
            double low, high, average;
            inTempratureFile >> low >> high >> average;
            dailyTempretures[month][day][LOW] = low;
            dailyTempretures[month][day][HIGH] = high;
            dailyTempretures[month][day][AVG] = average;
        }
    }
    inTempratureFile.close();
}

void acceptDailyTemp() {
    cout << "Enter month, day, low, and high temprature"
        << "Enter EOF(ctrl-z on windows) to end input. \n? ";
    double low, high, average;
    unsigned int month, day;
    while (cin >> month >> day >> low >> high) {
        // checks/validates user input. 
        if (!validate(month, day)) {
            cout << "Out of range(month must be between 1 & 12 and "
                "day should be betwee 1 & 30). Please try again\n? ";
            continue;
        }
        dailyTempretures[month - 1][day - 1][LOW] = low;
        dailyTempretures[month - 1][day - 1][HIGH] = high;
        dailyTempretures[month - 1][day - 1][AVG] = (low + high) / 2;
        cout << "? ";
    }
    cin.clear();
    saveToFile();
}

// validates month and days
bool validate(unsigned int month, unsigned int day) {
    if (month > 0 && month <= 12 && day > 0 && day <= 30) return true;
    return false;
}

// saves dailyTempratures array from memory into daily_temp.txt
void saveToFile() {
    ofstream outTempratureFile("daily_temp.txt");

    if (!outTempratureFile) {
        cout << "Unable to open file. please try again!" << endl;
        exit(EXIT_FAILURE);
    }
    for (int month = 0; month < MONTH; month++) {
        for (int day = 0; day < DAY; day++) {
            double low, high, average;
            low = dailyTempretures[month][day][LOW];
            high = dailyTempretures[month][day][HIGH];
            average = dailyTempretures[month][day][AVG];

            outTempratureFile << setw(4) << low << " " << setw(4) << high
                << " " << setw(4) << average << "   ";
        }
        outTempratureFile << endl;
    }
    outTempratureFile.close();
}