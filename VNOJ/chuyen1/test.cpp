#include <iostream>
#include <string>
using namespace std;
int countzero(int x, int req){
    int count = 0;
    while (x % 10 == 0){
        count++;
        x = x / 10;
    }
    return count==req;
}
int main() {
    string s;
    cin >> s;
    int count = 1;
    auto pos = s.find('.');
    if (pos != string::npos) {
        string d = s.substr(pos + 1);
        int num = stoi(d);
        int req = d.size();
        int store = num;
        while (countzero(num,req)){
            num=num+store;
            count=count+1;
        }
        //cout << decimalInt << endl;
    } 
    cout << count;
    return 0;
}