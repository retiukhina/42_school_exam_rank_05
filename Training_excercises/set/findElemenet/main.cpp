#include <iostream>
#include <set>
using namespace std;

void findElement(const set<char>& s, char e) {
    if (s.find(e) == s.end()) {
        cout << "Couldn't find " << e << endl;
    } else {
        cout << "Found " << e << endl;
    }
}

void printSet(const set<char>& s, const string& m) {
    cout << m;
    if (s.empty()) {
        cout << "(Set is empty)\n" << endl;
    }
    for (auto itr = s.begin(); itr != s.end(); ++itr) {
        cout << *itr << endl;
    }
}

int main() {
    set<char> s1 = {'C', 'D', 'C', 'D', 'A'};
    printSet(s1, "Set after creation\n");

    s1.insert('B');
    s1.erase('C');
    printSet(s1, "Added B and erased C\n");

    findElement(s1, 'C');
    findElement(s1, 'A');
}