#ifndef NOTICIADIGITAL_H
#define NOTICIADIGITAL_H

#include "noticia.h"

class noticiaDigital : public noticia {
private:
    list<string> media;

public:
    noticiaDigital(string titulo, string fecha, string reportero, list<string> media) {
        this->titulo = titulo;
        this->fecha = fecha;
        this->reportero = reportero;
        this->media = media;
    }

    ~noticiaDigital() {}

    void getInfo() {
        cout << "Titulo: " << titulo << endl;
        cout << "Fecha: " << fecha << endl;
        cout << "Reportero: " << reportero  << endl;
        cout << "Tipos de media: " << endl;

        for(string i : media) {
            cout << i << endl;
        }
        cout << endl;
    }
};

#endif