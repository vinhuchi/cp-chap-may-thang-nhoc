#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Hàm kiểm tra số N có thỏa mãn các điều kiện đề bài hay không
bool isValidNumber(int N, int s, int d, int m) {
    int sum_digits = 0;
    vector<int> count_digits(d + 1, 0);

    // Tính tổng các chữ số của N và đếm số lần xuất hiện của từng chữ số
    while (N > 0) {
        int digit = N % 10;
        sum_digits += digit;
        count_digits[digit]++;
        N /= 10;
    }

    // Kiểm tra tổng các chữ số của N
    if (sum_digits != s) {
        return false;
    }

    // Kiểm tra các chữ số đều xuất hiện chẵn lần và không chứa chữ số 0 ở vị trí đầu
    for (int i = 1; i <= d; i++) {
        if (count_digits[i] % 2 != 0) {
            return false;
        }
    }

    // Kiểm tra N chia hết cho m
    if (N % m != 0) {
        return false;
    }

    return true;
}

int main() {
    int s=6, d=10, m=4;
   // cin >> s >> d >> m;

    // Xây dựng số N từ các chữ số thỏa mãn các điều kiện
    int N = -1;
    vector<int> digits(d, 0); // Mảng chứa d chữ số từ 1 đến d
    for (int i = 0; i < d; i++) {
        digits[i] = i + 1;
    }

    do {
        int number = 0;
        for (int i = 0; i < d; i++) {
            number = number * 10 + digits[i];
        }

        if (isValidNumber(number, s, d, m)) {
            N = number;
            break;
        }
    } while (next_permutation(digits.begin(), digits.end()));

    cout << N << endl;

    return 0;
}