#ifndef DISPLAYELEMENT_H
#define DISPLAYELEMENT_H

#include "../../src/Date/Date.hpp"

#include "../../src/Server/Server.hpp"

template <class Element>
class DisplayElement
{
public:
    DisplayElement(Element &_element);
private:
    Element element;
};

#endif // DISPLAYELEMENT_H
