#pragma once

#include <iostream>

using std:: string;
using std:: cout;
using std:: endl;

class Warlock {
    private:
        string _name;
        string _title;
        Warlock();

    public:
        Warlock(const string& name, const string& title);
        ~Warlock();
        Warlock(const Warlock&);
        Warlock& operator=(const Warlock& other);

        void setName(const string& name);
        void setTitle(const string& title);
        const string& getName() const;
        const string& getTitle() const;

        void introduce() const;
};