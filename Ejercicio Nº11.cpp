#include <iostream>
#include <sstream>
#include <string>

using namespace std;

// Función para calcular el número de la suerte
int calcularNumeroSuerte(const string &fecha) {
    int suma = 0;

    // Sumar los dígitos de la fecha
    for (char c : fecha) {
        if (isdigit(c)) {
            suma += c - '0';
        }
    }

    // Reducir la suma a un solo dígito
    while (suma > 9) {
        int tempSuma = 0;
        while (suma > 0) {
            tempSuma += suma % 10;
            suma /= 10;
        }
        suma = tempSuma;
    }

    return suma;
}

// Función para validar la fecha ingresada
bool validarFecha(const string &fecha) {
    stringstream ss(fecha);
    int dia, mes, anio;
    char separator1, separator2;

    // Intentar leer la fecha en el formato especificado
    if (ss >> dia >> separator1 >> mes >> separator2 >> anio &&
        separator1 == '-' && separator2 == '-') {

        // Validar día, mes y año (simplificación, no se consideran años bisiestos)
        return (dia >= 1 && dia <= 31 && mes >= 1 && mes <= 12 && anio >= 1000 && anio <= 9999);
    }

    return false;
}

int main() {
    string fecha;

    do {
        // Solicitar la fecha al usuario
        cout << "Ingrese la fecha de nacimiento en formato DD-MM-YYYY (o 'exit' para salir): ";
        getline(cin, fecha);

        // Salir si el usuario ingresa "exit"
        if (fecha == "exit") {
            break;
        }

        // Validar la fecha ingresada
        if (!validarFecha(fecha)) {
            cout << "Fecha no válida. Por favor, ingrese una fecha válida.\n";
            continue;
        }

        // Calcular y mostrar el número de la suerte
        int numeroSuerte = calcularNumeroSuerte(fecha);
        cout << "El número de la suerte es: " << numeroSuerte << "\n";

    } while (true);

    cout << "¡Hasta luego!\n";

    return 0;
}
