#ifndef NOTICIAPAPER_H
#define NOTICIAPAPER_H

#include "noticia.h"

class noticiaPaper : public noticia {
private:
    string rutaArchivo;

public:
    noticiaPaper(string titulo, string fecha, string reportero, string ruta) {
        this->titulo = titulo;
        this->fecha = fecha;
        this->reportero = reportero;
        this->rutaArchivo = ruta;
    }

    ~noticiaPaper() {}

    void getInfo() {
        cout << "Titulo: " << titulo << endl;
        cout << "Fecha: " << fecha << endl;
        cout << "Reportero: " << reportero  << endl;
        cout << "Ruta del archivo: " << rutaArchivo << endl;
        cout << endl;
    }
};

#endif