#include <iostream>
#include <vector>
using namespace std;

int digitSum(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

pair<int, int> findNumbersWithEqualDigitSum(int X) {
    vector<int> A, B;
    int sum = digitSum(X);
    if (sum % 2 == 1 || X < sum) {
        return make_pair(-1, -1);
    }

    int remainingSum = sum / 2;
    while (X > 0) {
        int digit = X % 10;
        if (digit <= remainingSum) {
            A.push_back(digit);
            remainingSum -= digit;
        } else {
            A.push_back(remainingSum);
            remainingSum = 0;
        }
        B.push_back(digit - A.back());
        X /= 10;
    }

    int a = 0, b = 0;
    for (int i = A.size() - 1; i >= 0; i--) {
        a = a * 10 + A[i];
        b = b * 10 + B[i];
    }

    return make_pair(a, b);
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int X;
        cin >> X;
        pair<int, int> result = findNumbersWithEqualDigitSum(X);
        if (result.first != -1 && result.second != -1) {
            cout << result.first << " " << result.second << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}