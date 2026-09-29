#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Persona{
private:
string nombre;
float edad;

public:
Persona(string nombre, float edad): nombre(nombre), edad(edad) {}

string getNombre() const { return nombre; }
float getEdad() const { return edad; }

void mostrar() const {
        cout<<"Nombre: "<<nombre<<endl<<" Edad: "<<edad<<" anios"<<endl;
    }
};

bool compararPorEdad(const Persona& a, const Persona& b) {
    return a.getEdad() < b.getEdad();
}

int main() {

vector<Persona> personas= {
Persona("Fafi", 16),
Persona("Aitor", 87),
Persona("Manu", 2),
Persona("Ciro", 21),
Persona("Octavio", 52)
};
sort(personas.begin(), personas.end(), compararPorEdad);

cout<<"Personas ordenadas por edad (asc)"<<endl;
    for (int i = 0; i < personas.size(); i++) {
        personas[i].mostrar();
    }

return 0;
}
