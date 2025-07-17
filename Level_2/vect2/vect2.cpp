#include "vect2.hpp"

vect2::vect2()
    : _x(0)
    , _y(0)
{
    createVector();
}

vect2::vect2(int x, int y)
    : _x(x)
    , _y(y)
{
    createVector();
}

vect2::vect2(const vect2& other) 
    : _x(other._x)
    , _y(other._y)
{
    createVector();
}

vect2& vect2::operator=(const vect2& other) {
    if (this != &other) {
        _x = other._x;
        _y = other._y;
        createVector();
    }
    return *this;
}

vect2::~vect2() {}

void vect2::createVector() {
    _arr[0] = _x;
    _arr[1] = _y;
}

void vect2::printVector() const {
    cout << "{" << _arr[0] << ", " << _arr[1] << "}" << endl;
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
    _x = _x + other._x;
    _y = _y + other._y;
    createVector();
    return *this;
}

// returns rvalue
vect2 vect2::operator+(const vect2& other) const {
    vect2 sum = *this;
    sum += other;
    sum.createVector();
    return sum;
}

vect2& vect2::operator-=(const vect2& other) {
    _x = _x - other._x;
    _y = _y - other._y;
    createVector();
    return *this;
}

vect2 vect2::operator-(const vect2& other) const {
    vect2 dif = *this;
    dif -= other;
    dif.createVector();
    return dif;
}

vect2& vect2::operator*=(const vect2& other) {
    _x = _x * other._x;
    _y = _y * other._y;
    createVector();
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
    ++_x;
    ++_y;
    createVector();
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
    --_x;
    --_y;
    createVector();
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
    this->_x = this->_x * scalar;
    this->_y = this->_y * scalar;
    this->createVector();
    return *this;
}

// returns rvalue
// v * 5
vect2 vect2::operator*(int scalar) const {
    vect2 mult(_x * scalar, _y * scalar);
    return mult;
}

// returns rvalue
// 5 * v
vect2 operator*(int scalar, const vect2& v) {
    return v * scalar;
}

vect2 vect2::operator-() const{
    return vect2(-_x, -_y);
}

std::ostream& operator<<(std::ostream& os, const vect2& v) {
    os << "{" << v._arr[0] << ", " << v._arr[1] << "}";
    return os;
}