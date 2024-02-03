#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


struct Vaca {
    int peso;
    int produccionLeche;
};


bool compararVacas(const Vaca& a, const Vaca& b) {
    return a.produccionLeche > b.produccionLeche;
}

int obtenerProduccionMaxima(int totalVacas, int pesoCamion, const vector<int>& pesos, const vector<int>& produccionLeche) {

    vector<Vaca> vacas;
    for (int i = 0; i < totalVacas; ++i) {
        Vaca vaca;
        vaca.peso = pesos[i];
        vaca.produccionLeche = produccionLeche[i];
        vacas.push_back(vaca);
    }


    sort(vacas.begin(), vacas.end(), compararVacas);


    int pesoActual = 0;
    int produccionTotal = 0;


    for (int i = 0; i < totalVacas; ++i) {
        if (pesoActual + vacas[i].peso <= pesoCamion) {
            pesoActual += vacas[i].peso;
            produccionTotal += vacas[i].produccionLeche;
        }
    }

 
    return produccionTotal;
}

int main() {

    int totalVacas, pesoCamion;
    cout << "Ingrese el número total de vacas: ";
    cin >> totalVacas;

    cout << "Ingrese el peso total que el camión puede llevar: ";
    cin >> pesoCamion;

    vector<int> pesos(totalVacas);
    vector<int> produccionLeche(totalVacas);

    cout << "Ingrese los pesos de las vacas: ";
    for (int i = 0; i < totalVacas; ++i) {
        cin >> pesos[i];
    }

    cout << "Ingrese la producción de leche en litros por día: ";
    for (int i = 0; i < totalVacas; ++i) {
        cin >> produccionLeche[i];
    }

  
    int produccionMaxima = obtenerProduccionMaxima(totalVacas, pesoCamion, pesos, produccionLeche);


    cout << "La cantidad máxima de producción de leche es: " << produccionMaxima << " litros" << endl;

    return 0;
}