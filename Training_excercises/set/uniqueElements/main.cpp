#include <iostream>
#include <set>
#include <string>

// #define DEBUG

void printSet(const std::set<char>& s) {
    if (s.empty()) {
        std::cout << "Set is empty";
    }
    else {
        std::cout << "{ ";
            for (char c : s) {
            std::cout << c << ' ';
        }
        std::cout << "}";
    }
}

std::set<char> findUniqueElements(const std::set <char>& s1, const std::set <char>& s2) {
    std::set<char> unique;

    for (auto itr = s1.begin(); itr != s1.end(); ++itr) {
        char element = *itr;
        if (s2.find(*itr) == s2.end()) {
            unique.insert(*itr);
        }
        #ifdef DEBUG
        else {
            std::cout << *itr << " exists in ";
            printSet(s2);
            std::cout << '\n';
        }
        #endif
    }
    return unique;
}

int main() {
    
    std::string s1, s2;

    std::cout << "\n===Unique Character Finder ===\n\n";

    std::cout << "Enter string to check for uniqueness: " << std::endl;
    getline(std::cin, s1);

    std::cout << "Enter string to search within: " << std::endl;
    getline(std::cin, s2);

    std::set<char> set1(s1.begin(), s1.end()); // Range constructor from string iterators
    std::set<char> set2(s2.begin(), s2.end());
    std::set<char> unique;

    unique = findUniqueElements(set1, set2);
    std::cout << "\nThank you! We've searched for characters from: \n\"" << s1 << "\"\nthat are NOT present in: \n\"" << s2 << "\"\n\n";
    if (!unique.empty()) {
       std::cout << "Unique elements: ";
        printSet(unique);
        std::cout << std::endl;
    } else {
        std::cout << "No unique elements are found\n";
    } 
    return 0;
}