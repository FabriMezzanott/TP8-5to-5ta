#include <iostream>
#include <string>
#include <vector>
using namespace std;

class CuentaBancaria{
private:
	float id;
	string nombre;
	float saldo;
public:
CuentaBancaria(float id, string nombre, float saldo) : id(id), nombre(nombre), saldo(saldo) {}
float getId() const { return id; }
string getNombre() const { return nombre; }
float getSaldo() const { return saldo; }

void depositar(float monto){
	saldo = saldo + monto;
}

bool retirar(float monto){
	if(monto > saldo){
		return false;
	}
	saldo = saldo - monto;
	return true;
}
};

void mostrarCuentas(const vector<CuentaBancaria>& cuentas){
	cout<<"Datos de las cuentas:"<<endl;
	for(const auto& cuentaBancaria : cuentas) {
		cout<<"Numero de cuenta: "<<cuentaBancaria.getId()<<endl;
		cout<<"Nombre de la cuenta: "<<cuentaBancaria.getNombre()<<endl;
		cout<<"Saldo de la cuenta: "<<cuentaBancaria.getSaldo()<<endl;
	}
}

int main (){
	vector<CuentaBancaria> cuentas;
	float id;
	string nombre;
	float saldo;
	float num;

cout<<"Digite el numero de cuentas: "; cin>>num;
for(int i = 0; i < num; i++) {
cout<<"Digite el numero de la cuenta (id): "; cin>>id;
cout<<"Digite el nombre de la cuenta: "; cin>>nombre;
cout<<"Digite el saldo de la cuenta: "; cin>>saldo;

cuentas.push_back(CuentaBancaria(id, nombre, saldo));
}

mostrarCuentas(cuentas);

int opcion;
do{
	cout<<"\nMenu"<<endl;
	cout<<"1. Depositar"<<endl;
	cout<<"2. Retirar"<<endl;
	cout<<"3. Mostrar cuentas"<<endl;
	cout<<"4. Salir"<<endl;
	cout<<"Elija una opcion: ";
	cin>>opcion;

	if(opcion == 1 || opcion == 2){
		float idBuscado;
		cout<<"Digite el numero de cuenta: "; cin>>idBuscado;

		int posicion = -1;
		for(int i = 0; i < cuentas.size(); i++){
			if(cuentas[i].getId() == idBuscado){
				posicion = i;
				break;
			}
		}

		if(posicion == -1){
			cout<<"No se encontro la cuenta."<<endl;
		} else {
			float monto;
			cout<<"Digite el monto: "; cin>>monto;

			if(opcion == 1){
				cuentas[posicion].depositar(monto);
				cout<<"Deposito realizado. Nuevo saldo: "<<cuentas[posicion].getSaldo()<<endl;
			} else {
				bool exito = cuentas[posicion].retirar(monto);
				if(exito){
					cout<<"Retiro realizado. Nuevo saldo: "<<cuentas[posicion].getSaldo()<<endl;
				} else {
					cout<<"Saldo insuficiente."<<endl;
				}
			}
		}
	} else if(opcion == 3){
		mostrarCuentas(cuentas);
	}

}while(opcion != 4);

return 0;
}
