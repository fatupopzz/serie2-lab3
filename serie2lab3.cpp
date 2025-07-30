#include <iostream>
#include <iomanip>

using namespace std;

//calcular utilidad

double calcularUtilidad(int cantidad, double costo, double precio){
    //diferencia entre precio y costo
    double diferencia = precio - costo;

    //diferencia por cantidad vendida
    double utilidad = diferencia * cantidad;

    return utilidad;; 
}

//valor positivo (validar)
bool esPositivo(double valor){
    return valor > 0;
}

// int main

int main(){
    //variables
    int cantidad;
    double costo, precio;

    cout << "---------------------------------"<< endl;
    cout << "Calculadora de venta de utilidad"<< endl;
    cout << "----------------------------------"<< endl;

    //solicitar datos para validar
    do {

        cout << "Ingresa la cantidad vendida: ";
        cin >> cantidad;

        if (cantidad <= 0){
            cout << "La cantidad debe ser mayor a 0"<< endl;
        }


    } while (cantidad <= 0);


    do {
        cout << "Ingrese el costo por unidad (Q): ";
        cin >> costo;
        
        if (!esPositivo(costo)) {
            cout << "Error: El costo debe ser mayor a 0. Intente nuevamente.\n" << endl;
        }
    } while (!esPositivo(costo));
    
    do {
        cout << "Ingrese el precio de venta por unidad (Q): ";
        cin >> precio;
        
        if (!esPositivo(precio)) {
            cout << "Error: El precio debe ser mayor a 0. Intente nuevamente.\n" << endl;
        }
    } while (!esPositivo(precio));

    cout << "--------------------------------------------" << endl;
    cout << "              PROCESAMIENTO" << endl;
    cout << "--------------------------------------------" << endl;
    
    // Mostrar datos ingresados
    cout << "Cantidad vendida: " << cantidad << " unidades" << endl;
    cout << "Costo por unidad: Q" << fixed << setprecision(2) << costo << endl;
    cout << "Precio por unidad: Q" << fixed << setprecision(2) << precio << endl;
    
    // PROCESO: Llamar a la función calcularUtilidad()
    double utilidadTotal = calcularUtilidad(cantidad, costo, precio);
    
    cout << "\n============================================" << endl;
    cout << "                RESULTADO" << endl;
    cout << "============================================" << endl;
    
    // SALIDA: Mostrar resultado
    cout << "Utilidad por unidad: Q" << fixed << setprecision(2) << (precio - costo) << endl;
    cout << "Utilidad total: Q" << fixed << setprecision(2) << utilidadTotal << endl;
    
    // Análisis adicional
    if (utilidadTotal > 0) {
        cout << "Estado: GANANCIA ✓" << endl;
        double porcentajeGanancia = ((precio - costo) / costo) * 100;
        cout << "Margen de ganancia: " << fixed << setprecision(1) << porcentajeGanancia << "%" << endl;
    } else if (utilidadTotal < 0) {
        cout << "Estado: PÉRDIDA ✗" << endl;
        cout << "Advertencia: Está vendiendo a pérdida." << endl;
    } else {
        cout << "Estado: PUNTO DE EQUILIBRIO" << endl;
        cout << "Sin ganancia ni pérdida." << endl;
    }
    
}


