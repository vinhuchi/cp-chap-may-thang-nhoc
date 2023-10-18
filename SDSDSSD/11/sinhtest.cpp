#include <bits/stdc++.h>
#include <filesystem>

using namespace std;
namespace fs = filesystem;

int main() {
    fs::create_directory("tests");
    for (int testIndex = 1; testIndex <= 20; testIndex++) {
        string folderName = "tests/test" + to_string(testIndex);
        fs::create_directory(folderName);
        string inputFileName = folderName + "/test" + to_string(testIndex) + ".inp";

        // Tạo file input
        ofstream inputFile(inputFileName);

        // Sinh test với N <= 500 và K <= 255
        int N = rand() % 501;
        int K = rand() % 256 % (N+1);

        // Ghi giá trị N và K vào file
        inputFile << N << " " << K << endl;

        // Ghi giá trị mảng a vào file
        for (int i = 0; i < N; i++) {
            int value = rand() % 101; // Giả sử giá trị trong mảng là ngẫu nhiên từ 0 đến 1000
            inputFile << value << " ";
        }

        // Đóng file
        inputFile.close();

        cout << "Test " << testIndex << " input generated: " << inputFileName << endl;
    }

    cout << "All tests generated successfully!" << endl;

    return 0;
}