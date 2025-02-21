#include "TextBox.hpp"
#include <iostream>

int main() {
    TextBox box = TextBox {"test", 10, 10};
    box.draw(); // errors initially

    Rectangle &r = box;
    r.draw();
    Text &t = box;
    t.draw();
}
