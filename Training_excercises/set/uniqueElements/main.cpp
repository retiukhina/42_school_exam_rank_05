#include <iostream>
#include <set>
#include <string>

using namespace std;

// #define DEBUG

void printSet(const set<char>& s) {
    if (s.empty()) {
        cout << "Set is empty";
    }
    else {
        cout << "{ ";
            for (char c : s) {
            cout << c << ' ';
        }
        cout << "}";
    }
}

set<char> findUniqueElements(const set <char>& s1, const set <char>& s2) {
    set<char> unique;

    for (auto itr = s1.begin(); itr != s1.end(); ++itr) {
        char element = *itr;
        if (s2.find(*itr) == s2.end()) {
            unique.insert(*itr);
        }
        #ifdef DEBUG
        else {
            cout << *itr << " exists in ";
            printSet(s2);
            cout << '\n';
        }
        #endif
    }
    return unique;
}

int main() {
    
    string s1, s2;

    cout << "\n===Unique Character Finder ===\n\n";

    cout << "Enter string to check for uniqueness: " << endl;
    getline(cin, s1);

    cout << "Enter string to search within: " << endl;
    getline(cin, s2);

    set<char> set1(s1.begin(), s1.end()); // Range constructor from string iterators
    set<char> set2(s2.begin(), s2.end());
    set<char> unique;

    unique = findUniqueElements(set1, set2);
    cout << "\nThank you! We've searched for characters from: \n\"" << s1 << "\"\nthat are NOT present in: \n\"" << s2 << "\".\n\n";
    if (!unique.empty()) {
        cout << "Unique elements: ";
        printSet(unique);
        cout << endl;
    } else {
        cout << "No unique elements are found\n";
    }
}