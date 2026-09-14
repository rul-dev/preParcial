#include <iostream>
using namespace std;

struct Elemento
{
    int codigoElemento;
    string nombreElemento;
    int Longitud;
    float cargas[3];
    int Factor, capacidadMaxima;
    bool Estado;
};

float calcularFactor(Elemento *elemento){
    float promedio;
    
    promedio = (elemento->cargas[0]+elemento->cargas[1]+elemento->cargas[2]) / 3;

    float Factor = promedio/elemento->capacidadMaxima;

    return Factor;
}

void registrarElemento(Elemento &elemento)
{
    cout << "Cual es el codigo de su Elemento?" << endl;
    cin >> elemento.codigoElemento;
    
    cout << "Cual es el nombre de su Elemento?" << endl;
    cin >> elemento.nombreElemento;

    cout << "Cual es la longitud de su Elemento?" << endl;
    cin >> elemento.Longitud;

    cout << "Cual es la primera carga de su Elemento?" << endl;
    cin >> elemento.cargas[0];

    cout << "Cual es la segunda carga de su Elemento?" << endl;
    cin >> elemento.cargas[1];

    cout << "Cual es la tercera carga de su Elemento?" << endl;
    cin >> elemento.cargas[2];

    cout << "Cual es la capacidad maxima de su Elemento?" << endl;
    cin >> elemento.capacidadMaxima;

    cout << endl;
    cout << "Factor de utilizacion: " << calcularFactor(&elemento) << endl;
    cout << endl;
}



int main()
{
    Elemento elementos[10];
    int cantidad;

    do
    {
        cout << "Cuantos elementos va a registrar de 1 a 10? : " << endl;
        cin >> cantidad;

        if (cantidad < 1 || cantidad > 10)
        {
            system("cls");
            cout << "Cantidad invalida, escriba una cantidad correcta" << endl;
        }
    } while (cantidad < 1 || cantidad > 10);

    for(int i = 0; i < cantidad; i++){
        cout << endl;
        cout << i+1 << ". Elemento: " << endl;
        cout << endl;
        registrarElemento(elementos[i]);
    }
}