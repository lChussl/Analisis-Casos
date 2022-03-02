#ifndef NOTICIARADIO_H
#define NOTICIARADIO_H

#include "noticia.h"

class noticiaRadio : public noticia {
private:
    string url;

public:
    noticiaRadio(string titulo, string fecha, string reportero, string url) {
        this->titulo = titulo;
        this->fecha = fecha;
        this->reportero = reportero;
        this->url = url;
    }

    ~noticiaRadio() {}

    void getInfo() {
        cout << "Titulo: " << titulo << endl;
        cout << "Fecha: " << fecha << endl;
        cout << "Reportero: " << reportero  << endl;
        cout << "url: " << url << endl;
        cout << endl;
    }

};

#endif