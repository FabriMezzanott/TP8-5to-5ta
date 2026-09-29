#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Rectangulo{
private:
float base;
float altura;

public:
Rectangulo(float base, float altura) : base(base), altura(altura) {}

float getBase() const {
return base; 
}
float getAltura() const {
return altura; 
}

float area() const {
return base * altura; 
}
float perimetro() const {
return 2 * (base + altura); 
}

};
int main() {

vector<Rectangulo> rectangulos;
float base;
float altura;
int numRec;
cout<<"Digite el numero de rectangulos: "; cin>>numRec;
for(int i = 0; i < numRec; i++) {
cout<<"Digite la base del rectangulo: "; cin>>base;
cout<<"Digite la altura del rectangulo: "; cin>>altura;
rectangulos.push_back(Rectangulo(base, altura));
}
cout<<"Area y perimetro de los rectangulos: "<<endl;
for (const auto& r : rectangulos) {
cout<<"Base: "<<r.getBase()<<endl<<"Altura: "<<r.getAltura()<<endl;
cout<<"Area: "<<r.area()<<endl<<"Perimetro: "<<r.perimetro()<<endl;
}
return 0;
}
