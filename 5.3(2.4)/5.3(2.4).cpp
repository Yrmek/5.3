#include <iostream>
#include <iomanip>
#include <time.h>
#include <list>
#include <iterator>

using namespace std;

void print_list(const list<char>& lst);
void fill_list(list<char>& lst, int quantity);
void deleteSublist(list<char>& lst, const list<char>& sublist);

int main() {
    srand(time(NULL));
    cout << "Enter quantity of elements in lists" << endl;
    int quantity, quantity1;
    cin >> quantity >> quantity1;

    list<char> lst;
    list<char> lst1;

    fill_list(lst, quantity);
    cout << "List L:" << endl;
    print_list(lst);

    fill_list(lst1, quantity1);
    cout << "List L1:" << endl;
    print_list(lst1);

    deleteSublist(lst, lst1);
    cout << "Transformed list L without symbols of L1:" << endl;
    print_list(lst);

    return 0;
}

void fill_list(list<char>& lst, int quantity) {
    for (int i = 0; i < quantity; i++) {
        char symbol;
        cin >> symbol;
        lst.push_back(symbol); 
    }
}

void print_list(const list<char>& lst) {
    for (char symbol : lst) {
        cout << symbol << " ";
    }
    cout << endl;
}

void deleteSublist(list<char>& lst, const list<char>& sublist) {
    if (sublist.empty()) return;

    auto it = lst.begin();
    while (it != lst.end()) {
        auto itMain = it;
        auto itSub = sublist.begin();

        while (itMain != lst.end() && itSub != sublist.end() && *itMain == *itSub) {
            ++itMain;
            ++itSub;
        }

        if (itSub == sublist.end()) {
            it = lst.erase(it, itMain);
        }
        else {
            ++it;
        }
    }
}