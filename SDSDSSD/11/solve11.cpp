#include <bits/stdc++.h>
#include <fstream>
#include <filesystem>
#include <algorithm>

using namespace std;
namespace fs = filesystem;

int main() {
    // Mở thư mục "tests"
    fs::path testsFolder = "tests";

    // Kiểm tra xem thư mục "tests" có tồn tại không
    if (!fs::exists(testsFolder) || !fs::is_directory(testsFolder)) {
        cerr << "Error: 'tests' folder not found." << endl;
        return 1;
    }

    // Duyệt qua tất cả các file trong thư mục "tests"
    for (const auto& entry : fs::directory_iterator(testsFolder)) {
        if (fs::is_directory(entry.path())) {
            // Lấy tên thư mục
            string folderName = entry.path().filename().string();

            // Tìm file input trong thư mục
            fs::path inputFilePath = entry.path() / (folderName + ".inp");
            cout << folderName << endl;
            cout << inputFilePath << endl;
            if (fs::exists(inputFilePath)) {
                // Mở file input
                ifstream inputFile(inputFilePath);
                streambuf* cinbuf = cin.rdbuf(); // Save old buf
                cin.rdbuf(inputFile.rdbuf()); // Redirect cin to inputFile

                // Đọc giá trị N và K
                int n, k;
                cin >> n >> k;

                // Khai báo và nhập mảng a
                int a[n + 5];
                for (int i = 0; i < n; i++) {
                    cin >> a[i];
                }

                // Tạo tên file output với tên tương ứng
                string outputFileName = entry.path().string() + "/" + folderName + ".out";

                // Mở file output
                ofstream outputFile(outputFileName);
                streambuf* coutbuf = cout.rdbuf(); // Save old buf
                cout.rdbuf(outputFile.rdbuf()); // Redirect cout to outputFile

                // Xử lý bài toán (đoạn mã của bạn)
                int res = 0;
                int pos = 0;
                for (int i = 0; i <= n - k; i++) {
                    int sum = accumulate(a + i, a + i + k, 0);
                    if (res <= sum) {
                        pos = i;
                        res = sum;
                    }
                }
                cout << res << endl;
                for (int i = pos + 1; i <= pos + k; i++) {
                    cout << i << " ";
                }

                // Đóng file output
                outputFile.close();
                // Restore old cin and cout
                cin.rdbuf(cinbuf);
                cout.rdbuf(coutbuf);

                // Hiển thị thông báo
                cout << "Processed test in folder " << folderName << " and wrote output to " << outputFileName << endl;
            }
        }
    }

    return 0;
}