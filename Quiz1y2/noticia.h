#ifndef NOTICIA_H
#define NOTICIA_H

#include <iostream>
#include <list>
#include <vector>

using namespace std;

class noticia {
protected:
    string titulo;
    string fecha;
    string reportero;

public:
    noticia() {}
    virtual ~noticia() {}
    virtual void getInfo() = 0;
};

#endif