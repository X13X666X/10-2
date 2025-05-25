#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
using namespace std;

void CreateInputFile(const char* filename) {
    ofstream fout(filename);
    fout << "123a!b@c D456ef gh!12iJKL" << endl;
    fout.close();
}

void ProcessFile(const char* inputFilename, const char* outputFilename) {
    ifstream fin(inputFilename);
    ofstream fout(outputFilename);
    bool foundSpace = false;
    char ch;
    while (fin.get(ch)) {
        if (!foundSpace) {
            if (ch == ' ') {
                foundSpace = true;
                fout.put(ch);  // записуємо пробіл
            }
            else {
                if (isalpha(ch))  // записуємо лише літери
                    fout.put(ch);
            }
        }
        else {
            fout.put(ch);  // усе після першого пробілу — як є
        }
    }
    fin.close();
    fout.close();
}

void PrintFile(const char* filename) {
    ifstream fin(filename);
    string line;
    while (getline(fin, line))
        cout << line << endl;
    fin.close();
}

int DisplayMenu() {
    int choice;
    cout << "\nMenu:" << endl;
    cout << "1. Process file t1 -> t2" << endl;
    cout << "0. Exit" << endl;
    cout << "Enter your choice: ";
    while (!(cin >> choice)) {
        cin.clear();
        while (cin.get() != '\n');
        cout << "Invalid input. Please try again: ";
    }
    return choice;
}

int main() {
    const char* t1 = "t1.txt";
    const char* t2 = "t2.txt";

    CreateInputFile(t1);

    int choice;
    do {
        choice = DisplayMenu();
        switch (choice) {
        case 1:
            ProcessFile(t1, t2);
            cout << "\nProcessed file (t2):" << endl;
            PrintFile(t2);
            break;
        case 0:
            cout << "Exiting the program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);

    return 0;
}
