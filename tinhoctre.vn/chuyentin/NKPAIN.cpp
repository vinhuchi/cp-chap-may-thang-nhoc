#include <iostream>
#include <string>

using namespace std;

string longestPalindromeSubstring(const string& s) {
    int n = s.length();
    int start = 0, maxLength = 1;
    // Xét trường hợp chuỗi con có độ dài là số lẻ
    int left = 0, right = n-1;
    string res = "";
    while (left!=right){
        int temp = "";
    }

}
lemvxvyzlme

lvxvl
emvxvme

    

int main() {
    string input_string;
    cin >> input_string;

    string result = longestPalindromeSubstring(input_string);
    cout << result << endl;

    return 0;
}