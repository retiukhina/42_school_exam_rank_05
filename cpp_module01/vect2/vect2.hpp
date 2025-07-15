#pragma once

#include <string>
#include <iostream>
#include <ostream>

using std::cout;
using std::endl;
using std::string;
using std:: ostream;

class vect2 {
    private:
        int _x;
        int _y;
        int _arr[2];
    
    public:
        vect2();
        vect2(const int x, const int y);
        vect2(const vect2& other);
        vect2& operator=(const vect2& other);
        ~vect2();

        void createVector();
        void setInts(const int x, const int y);
        void printVector() const;

        bool operator==(const vect2& other) const;
        bool operator!=(const vect2& other) const;
        const vect2 operator+(const vect2& other) const;
        vect2& operator+=(const vect2& other);
        int operator[](int index);


        friend std::ostream& operator<<(std::ostream& os, const vect2& v);
};