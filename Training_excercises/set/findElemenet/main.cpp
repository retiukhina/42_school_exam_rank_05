#include <iostream>
#include <set>

void findElement(const std::set<char>& s, char e) {
    if (s.find(e) == s.end()) {
        std::cout << "Couldn't find " << e << std::endl;
    } else {
        std::cout << "Found " << e << std::endl;
    }
}

void printSet(const std::set<char>& s, const std::string& m) {
    std::cout << m;
    if (s.empty()) {
        std::cout << "(Set is empty)\n" << std::endl;
    }
    for (auto itr = s.begin(); itr != s.end(); ++itr) {
        std::cout << *itr << std::endl;
    }
}

int main() {
    std::set<char> s1 = {'C', 'D', 'C', 'D', 'A'};
    printSet(s1, "Set after creation\n");

    s1.insert('B');
    s1.erase('C');
    printSet(s1, "Added B and erased C\n");

    findElement(s1, 'C');
    findElement(s1, 'A');
}