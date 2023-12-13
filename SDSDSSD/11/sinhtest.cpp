#include <bits/stdc++.h>
#include <filesystem>

using namespace std;
namespace fs = filesystem;

int main() {
    fs::create_directory("tests");

    // First 6 test cases with values smaller than 10^5
    for (int testIndex = 1; testIndex <= 6; testIndex++) {
        string folderName = "tests/test" + to_string(testIndex);
        fs::create_directory(folderName);
        string inputFileName = folderName + "/test" + to_string(testIndex) + ".inp";

        // Tạo file input
        ofstream inputFile(inputFileName);

        // Ghi giá trị mảng a vào file
        int value = rand() % 100001; // Values smaller than 10^5
        inputFile << value;

        // Đóng file
        inputFile.close();

        cout << "Test " << testIndex << " input generated: " << inputFileName << endl;
    }

    // Next 6 test cases with values between 10^5 and 10^9
    for (int testIndex = 7; testIndex <= 12; testIndex++) {
        string folderName = "tests/test" + to_string(testIndex);
        fs::create_directory(folderName);
        string inputFileName = folderName + "/test" + to_string(testIndex) + ".inp";

        // Tạo file input
        ofstream inputFile(inputFileName);

        // Ghi giá trị mảng a vào file
        int value = rand() % 900000001 + 100000000; // Values between 10^5 and 10^9
        inputFile << value;

        // Đóng file
        inputFile.close();

        cout << "Test " << testIndex << " input generated: " << inputFileName << endl;
    }

    // Last 8 test cases with values between 10^9 and 10^18
    for (int testIndex = 13; testIndex <= 20; testIndex++) {
        string folderName = "tests/test" + to_string(testIndex);
        fs::create_directory(folderName);
        string inputFileName = folderName + "/test" + to_string(testIndex) + ".inp";

        // Tạo file input
        ofstream inputFile(inputFileName);

        // Ghi giá trị mảng a vào file
        long long value = rand() % 900000000000000001LL + 100000000000000000LL; // Values between 10^9 and 10^18
        inputFile << value;

        // Đóng file
        inputFile.close();

        cout << "Test " << testIndex << " input generated: " << inputFileName << endl;
    }

    cout << "All tests generated successfully!" << endl;

    return 0;
}