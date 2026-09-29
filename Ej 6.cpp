#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Libro {
private:
    string titulo;
    string autor;
    int anio;

public:
    Libro(string titulo, string autor, int anio)
    : titulo(titulo), autor(autor), anio(anio) {}

    int getAnio() const {
        return anio;
    }

    void mostrar() const {
        cout<<"Titulo: "<<titulo<<endl;
        cout<<"Autor: "<<autor<<endl;
        cout<<"Fecha: "<<anio<<endl;
    }
};

int main() {
    vector<Libro> libros;
    int cantidad;
    string titulo;
    string autor;
    int anio;

    cout<<"Cuantos libros desea ingresar? ";
    cin>>cantidad;

    for(int i = 0; i < cantidad; i++) {
        cout<<endl<<"Libro "<<i + 1<<endl;
        cout<<"Titulo: ";
        cin>>titulo;
        cout<<"Autor: ";
        cin>>autor;
        cout<<"Anio de publicacion: ";
        cin>>anio;
        libros.push_back(Libro(titulo, autor, anio));
    }

    for (int i = 0; i < libros.size() - 1; i++) {
        for (int j = 0; j < libros.size() - 1 - i; j++) {
            if (libros[j].getAnio() > libros[j + 1].getAnio()) {
                Libro auxiliar = libros[j];
                libros[j] = libros[j + 1];
                libros[j + 1] = auxiliar;
            }
        }
    }

    cout<<endl<<"Libros ordenados por fecha (Mas antiguo a mas reciente)"<<endl;
    for (int i = 0; i < libros.size(); i++) {
        cout<<endl;
        libros[i].mostrar();
    }

    return 0;
}
