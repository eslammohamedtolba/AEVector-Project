#include <iostream>
#include <map>
#include <fstream>

using namespace std;
string str;
int n;
bool flag = false;
map<string, bool> English_dictionary;

void valid(int i, string pre, string ans) {
    if (flag)return;
    if (i == n) {
        if (English_dictionary[pre]) {
            cout << ans + " " + pre << endl;
            flag = true;
        }
        return;
    }
    pre += str[i];
    valid(i + 1, pre, ans);
    if (English_dictionary[pre]) {
        if (!ans.empty()) {
            ans = ans + " ";
        }
        valid(i + 1, "", ans + pre);
        ans.pop_back();
    }
}

int main() {

    ifstream file;
    file.open("english word.txt");
    string temp;

    while (file >> temp) {
        English_dictionary[temp] = 1;
    }
    while (true) {
        cout << "enter the string \n";
        cin >> str;
        n = (int) str.size();
        valid(0, "", "");
        cout << " 1-continue\n2-exit ";
        int choice;
        cin >> choice;
        while (choice != 1 && choice != 2) {
            cout << "enter valid number\n";
            cin >> choice;
        }
        if (choice == 2)break;
    }

}
