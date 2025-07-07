#include "Warlock.hpp"

Warlock::Warlock(const string& name, const string& title)
    : _name(name)
    , _title(title)
{
    cout << _name << ": This looks like another boring day." << endl;
}

Warlock::~Warlock() {
    cout << this->getName() << ": My job here is done!" << endl;
}

Warlock::Warlock(const Warlock& other)
    : _name(other._name)
    , _title(other._title)
{}

Warlock& Warlock::operator=(const Warlock& other) {
    if (this != &other) {
        this->_name = other._name;
        this->_title = other._title;
    }
    return *this;
}

void Warlock::setName(const string& name) {
    _name = name;
}

void Warlock::setTitle(const string& title) {
    _title = title;
}

const string& Warlock::getName() const {
    return _name;
}

const string& Warlock::getTitle() const {
    return _title;
}

void Warlock::introduce() const {
    const string name = this->getName();
    const string title = this->getTitle();
    cout << name << ": I am " << name << ", " << title << "!" << endl;
}