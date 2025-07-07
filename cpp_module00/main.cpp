#include "Warlock.hpp"
#include <cassert>

int main() {

    string name = "Richard";
    string title = "Mistress of Magma";

    Warlock const richard(name, title);
    assert(richard.getName() == name);
    assert(richard.getTitle() == title);
    richard.introduce();

    name = "Jack";
    title = "the Long";
    Warlock* jack = new Warlock(name, title);
    assert(jack->getName() == name);
    assert(jack->getTitle() == title);
    jack->introduce();
    jack->setTitle("the Mighty");
    assert(jack->getTitle() == "the Mighty");
    jack->introduce();

    delete jack;

    return (0);
}