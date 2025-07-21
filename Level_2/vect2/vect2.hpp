#pragma once

#include <string>
#include <iostream>
#include <ostream>
#include <array>

class vect2 {
    private:
        std::array<int, 2> _arr;
    
    public:
        vect2();
        vect2(int x, int y);
        vect2(const vect2& other);
        vect2& operator=(const vect2& other);
        ~vect2();

        void printVector() const;

        bool operator!=(const vect2& other) const;
        bool operator==(const vect2& other) const;
        vect2& operator+=(const vect2& other);
        vect2 operator+(const vect2& other) const;
        vect2& operator-=(const vect2& other);
        vect2 operator-(const vect2& other) const;
        vect2& operator*=(const vect2& other);
        vect2 operator*(const vect2& other) const;
        int& operator[](int index);
        int operator[](int index) const;
        vect2& operator++();
        vect2 operator++(int);
        vect2& operator--();
        vect2 operator--(int);

        vect2& operator*=(int scalar);
        vect2 operator*(int scalar) const;
        friend vect2 operator*(int scalar, const vect2& v);

        vect2 operator-() const;

        friend std::ostream& operator<<(std::ostream& os, const vect2& v);
};