#include <iostream>
#include <vector>
#include <list>

#include "noticiaPaper.h"
#include "noticiaDigital.h"
#include "noticiaRadio.h"

using namespace std;

int main() {
    //Se definen las variables.
    string titulo = "La invasion de Rusia a Ucrania afecta tambien las misiones a Marte";
    string fecha = "3/2/2022";
    string reportero = "Kiko Perozo";
    string url = "https://www.msn.com/es-xl/noticias/mundo/la-invasi%C3%B3n-de-rusia-a-ucrania-afecta-tambi%C3%A9n-las-misiones-a-marte/ar-AAUvVxf?ocid=msedgntp";
    string ruta = "docs/imagen.png";

    list<string> media = {"video.mp4", "foto1.png", "foto2.png", "audio.mp3"};

    //Se crea otro vector para guardar las instancias de las clases.
    vector<noticia*> noticias;

    //Se instancian las noticia.
    noticia *NoticiaPaper = new noticiaPaper(titulo, fecha, reportero, "docs/imagen.png");

    noticia *NoticiaDigital = new noticiaDigital(titulo, fecha, reportero, media);

    noticia *NoticiaRadio = new noticiaRadio(titulo, fecha, reportero, url);

    //Se rellena el segundo vector.
    noticias.push_back(NoticiaPaper);
    noticias.push_back(NoticiaDigital);
    noticias.push_back(NoticiaRadio);

    //Se imprime la información de cada noticia.
    for(int i = 0; i < noticias.size(); i++) {
            noticias[i]->getInfo();
        }

    //Se libera la memoria de los objetos.
    delete NoticiaPaper;
    delete NoticiaRadio;
    delete NoticiaDigital;

    return 0;
}