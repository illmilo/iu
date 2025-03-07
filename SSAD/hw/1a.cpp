#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void problemA() {
    // reading inputs
    int x; cin >> x;
    vector<int> ahmed, karim;
    while (x != 0) {
        ahmed.push_back(x);
        cin >> x;
    }
    cin >> x;
    while (x != 0) {
        karim.push_back(x);
        cin >> x;
    }
    vector<int> karimWin, ahmedWin;
    int i = 0;
    while (i < min(ahmed.size(), karim.size())) {
        // first, check ahmed's card
        if (ahmed[i] != -1) {
            for (int j = 0; j < karim.size(); j++) {
                // cards are equal and both are not checked
                if (ahmed[i] == karim[j] && karim[j] != -1) {
                    if (i < j) ahmedWin.push_back(ahmed[i]);
                    if (i > j) karimWin.push_back(karim[j]);
                    karim[j] = -1;
                    ahmed[i] = -1;
                    break;
                }
            }
        }
        if (karim[i] != -1) {
            for (int j = 0; j < ahmed.size(); j++) {
                // cards are equal and both are not checked
                if (karim[i] == ahmed[j] && ahmed[j] != -1) {
                    if (i < j) karimWin.push_back(karim[i]);
                    if (i > j) ahmedWin.push_back(ahmed[j]);
                    ahmed[j] = -1;
                    karim[i] = -1;
                    break;
                }
            }
        }
        i++;
    }
    if (!ahmedWin.size()) cout << '-';
    else {
        for (int item: ahmedWin) cout << item << ' ';
    }
    cout << '\n';
    if (!karimWin.size()) cout << '-';
    else {
        for (int item: karimWin) cout << item << ' ';
    }
    cout << '\n';
    if (karimWin.size() == ahmedWin.size()) cout << "Tie";
    else if (karimWin.size() > ahmedWin.size()) cout << "Karim";
    else cout << "Ahmed";
}

int main() {
    // freopen("i.txt", "r", stdin);
    problemA();
}