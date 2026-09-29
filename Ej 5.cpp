#include <iostream>
#include <vector>
#include <string>
using namespace std;
 
class Empleado {
private:
    string nombre;
    float salario;
    string departamento;
 
public:
	Empleado(string nombre, float salario, string departamento)
    : nombre(nombre), salario(salario), departamento(departamento) {}
 
    float getSalario() const {
        return salario;
    }
 
    void mostrar(){
        cout<<"Nombre: "<<nombre<<endl;
        cout<<"Salario: "<<salario<<endl;
        cout<<"Departamento: "<<departamento<<endl;
    }
};
 
int main(){
    vector<Empleado> empleados;
    int cantidad;
    string nombre;
    float salario;
    string departamento;
 
    cout<<"Cuantos empleados desea ingresar?: ";
    cin>>cantidad;
 
    for(int i = 0; i<cantidad; i++) {
        cout<<endl<<"Empleado "<<i + 1<<endl;
        cout<<"Nombre: "; cin>>nombre;
        cout<<"Salario: "; cin>>salario;
        cout<<"Departamento: "; cin>>departamento;
        empleados.push_back(Empleado(nombre, salario, departamento));
    }
 
    for(int i = 0; i < empleados.size() - 1; i++) {
        for(int j = 0; j < empleados.size() - 1 - i; j++) {
            if(empleados[j].getSalario() < empleados[j + 1].getSalario()) {
                Empleado auxiliar = empleados[j];
                empleados[j] = empleados[j + 1];
                empleados[j + 1] = auxiliar;
            }
        }
    }
 
    cout<<endl<<"Empleados ordenados por salario (de mayor a menor): "<<endl;
    for (int i = 0; i < empleados.size(); i++) {
        cout<<endl;
        empleados[i].mostrar();
    }
 
    return 0;
}
