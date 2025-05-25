#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
using namespace std;

std::string FilterLettersBeforeSpace(const std::string& input) {
    std::string result;
    for (char ch : input) {
        if (ch == ' ') {
            break;
        }
        if (isalpha(static_cast<unsigned char>(ch))) {
            result += ch;
        }
    }
    return result;
}

int main() {
    ifstream testFile("t1.txt");
    if (!testFile.good()) {
        ofstream createFile("t1.txt");
        createFile << "123Hel!lo Wo*rld this is a test";
        createFile.close();
        cout << "File t1.txt created with sample content." << endl;
    }
    testFile.close();

    ifstream inFile("t1.txt");
    ofstream outFile("t2.txt");

    if (!inFile.is_open()) {
        cerr << "Failed to open file t1.txt" << endl;
        return 1;
    }

    char ch;
    while (inFile.get(ch)) {
        if (ch == ' ') {
            break;
        }
        if (isalpha(static_cast<unsigned char>(ch))) {
            outFile << ch;
        }
    }

    inFile.close();
    outFile.close();

    cout << "Processing completed. Result written to t2.txt" << endl;

    cout << "\nContents of t1.txt:" << endl;
    ifstream readT1("t1.txt");
    string line;
    while (getline(readT1, line)) {
        cout << line << endl;
    }
    readT1.close();

    cout << "\nContents of t2.txt:" << endl;
    ifstream readT2("t2.txt");
    while (getline(readT2, line)) {
        cout << line << endl;
    }
    readT2.close();

    return 0;
}
