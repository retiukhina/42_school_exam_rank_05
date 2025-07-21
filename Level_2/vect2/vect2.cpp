#include "vect2.hpp"

vect2::vect2()
    : _arr{0, 0} 
{}

vect2::vect2(int x, int y)
    : _arr{x, y}
{}

vect2::vect2(const vect2& other) 
    : _arr{other._arr[0], other._arr[1]}
{}

vect2& vect2::operator=(const vect2& other) {
    if (this != &other) {
        _arr[0] = other._arr[0];
        _arr[1] = other._arr[1];
    }
    return *this;
}

vect2::~vect2() {}

void vect2::printVector() const {
    std::cout << "{" << _arr[0] << ", " << _arr[1] << "}" << std::endl;
}

bool vect2::operator!=(const vect2& other) const {
    return (_arr[0] != other._arr[0] ||
        _arr[1] != other._arr[1]);
}

bool vect2::operator==(const vect2& other) const {
    return (_arr[0] == other._arr[0] &&
        _arr[1] == other._arr[1]);
}

// return lvalue
vect2& vect2::operator+=(const vect2& other) {
    _arr[0] = _arr[0] + other._arr[0];
    _arr[1] = _arr[1] + other._arr[1];
    return *this;
}

// returns rvalue
vect2 vect2::operator+(const vect2& other) const {
    vect2 sum = *this;
    sum += other;
    return sum;
}

vect2& vect2::operator-=(const vect2& other) {
    _arr[0] = _arr[0] - other._arr[0];
    _arr[1] = _arr[1] - other._arr[1];
    return *this;
}

vect2 vect2::operator-(const vect2& other) const {
    vect2 dif = *this;
    dif -= other;
    return dif;
}

vect2& vect2::operator*=(const vect2& other) {
    _arr[0] = _arr[0] * other._arr[0];
    _arr[1] = _arr[1] * other._arr[1];
    return *this;
}

vect2 vect2::operator*(const vect2& other) const {
    vect2 mult = *this;
    mult *= other;
    return mult;
}

int& vect2::operator[](int index) {
    return _arr[index];
}

int vect2::operator[](int index) const {
    return _arr[index];
}

//prefix increment
vect2& vect2::operator++() {
    ++_arr[0];
    ++_arr[1];
    return *this;
}

//postfix increment
vect2 vect2::operator++(int) {
    vect2 tmp = *this;
    ++(*this);
    return tmp; 
}

//prefix decrement
vect2& vect2::operator--() {
    --_arr[0];
    --_arr[1];
    return *this;
}

//postfix decrement
vect2 vect2::operator--(int) {
    vect2 tmp = *this;
    --(*this);
    return tmp;
}

// modify the object
// v *= 5
vect2& vect2::operator*=(int scalar) {
    this->_arr[0] = this->_arr[0] * scalar;
    this->_arr[1] = this->_arr[1] * scalar;
    return *this;
}

// returns rvalue
// v * 5
vect2 vect2::operator*(int scalar) const {
    vect2 mult(_arr[0] * scalar, _arr[1] * scalar);
    return mult;
}

// returns rvalue
// 5 * v
vect2 operator*(int scalar, const vect2& v) {
    return v * scalar;
}

vect2 vect2::operator-() const{
    return vect2(-_arr[0], -_arr[1]);
}

std::ostream& operator<<(std::ostream& os, const vect2& v) {
    os << "{" << v._arr[0] << ", " << v._arr[1] << "}";
    return os;
}