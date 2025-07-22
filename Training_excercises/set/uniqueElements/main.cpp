#include <iostream>
#include <set>
#include <string>
#include <fmt/core.h>

// #define DEBUG

void printUnique(const std::set<char>& s) {
    if (!s.empty()) {
        fmt::print("Unique elements in the first string: ");
        for (char c : s) {
            fmt::print("{} ", c);
        }
        fmt::print("\n");
    } else {
        fmt::print("No unique elements are found\n");
    } 
}

std::set<char> findUniqueElements(const std::string& s1, const std::string& s2) {
    std::set<char> findUnique;

    for (int i = 0; i < s1.length(); ++i) {
        char element = s1[i];
        findUnique.insert(element);
        #ifdef DEBUG
        else {
            std::cout << element << " exists in " << s2 << std::endl;
        }
        #endif
    }
    for (int i = 0; i < s2.length(); ++i) {
        char element = s2[i];
        findUnique.erase(element);
    }
    return findUnique;
}

int main() {
    
    std::string s1, s2;

    std::cout << "\n===Unique Character Finder ===\n\n";

    std::cout << "Enter string to check for uniqueness: " << std::endl;
    getline(std::cin, s1);

    std::cout << "Enter string to search within: " << std::endl;
    getline(std::cin, s2);

    std::set<char> unique;

    unique = findUniqueElements(s1, s2);
    std::cout << "\nThank you! We've searched for characters from: \n\"" << s1 << "\"\nthat are NOT present in: \n\"" << s2 << "\"\n\n";
    printUnique(unique);
    return 0;
}