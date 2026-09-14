#include <iostream>
using namespace std;

struct Elemento
{
    int codigoElemento;
    string nombreElemento;
    int Longitud;
    float cargas[3];
    int Factor, capacidadMaxima;
    string Estado;
};

float calcularFactor(Elemento *elemento)
{
    float promedio;

    promedio = (elemento->cargas[0] + elemento->cargas[1] + elemento->cargas[2]) / 3;

    float Factor = promedio / elemento->capacidadMaxima;

    return Factor;
}

void determinarSeguridad(Elemento *elemento)
{
    float factor = elemento->Factor;

    if (factor >= 0.00 && factor <= 0.50)
    {
        elemento->Estado = "Seguro";
    }
    else if (factor > 0.50 && factor <= 0.80)
    {
        elemento->Estado = "Precaucion";
    }
    else if (factor > 0.80 && factor <= 1.0)
    {
        elemento->Estado = "Riesgo";
    }
    else if (factor > 1.00)
    {
        elemento->Estado = "SOBRECARGA";
    }
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

    determinarSeguridad(&elemento);

    cout << endl;
    cout << "Estado de seguridad: " << elemento.Estado << endl;
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

    for (int i = 0; i < cantidad; i++)
    {
        cout << endl;
        cout << i + 1 << ". Elemento: " << endl;
        cout << endl;
        registrarElemento(elementos[i]);
    }
}