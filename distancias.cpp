#include <iostream>
#include <cmath>
#include <vector>

// Estructura para un punto 2D
struct Coordenada {
    double posX;
    double posY;
};

// Calcula la distancia euclidiana entre dos coordenadas
double obtenerDistancia(const Coordenada &a, const Coordenada &b) {
    return std::sqrt(std::pow(b.posX - a.posX, 2) + std::pow(b.posY - a.posY, 2));
}

// Lee puntos manual o por patrón
void cargarCoordenadas(std::vector<Coordenada> &lista, int cantidad) {
    char opcion;
    std::cout << "¿Desea ingresar los puntos manualmente? (s/n): ";
    std::cin >> opcion;

    if (opcion == 's' || opcion == 'S') {
        for (int i = 0; i < cantidad; ++i) {
            Coordenada c;
            std::cout << "Ingrese las coordenadas del punto " << (i + 1) << " (x y): ";
            std::cin >> c.posX >> c.posY;
            lista.push_back(c);
        }
    } else {
        for (int i = 0; i < cantidad; ++i) {
            lista.push_back({3.0 * i, 4.0 * i});
        }
        std::cout << "Usando puntos predeterminados...\n";
    }
}

// Retorna la menor distancia desde 'referencia' a los puntos en 'lista'.
double encontrarDistanciaMinima(const std::vector<Coordenada> &lista, const Coordenada &referencia, int &indiceCercano) {
    double menor = obtenerDistancia(lista[0], referencia);
    indiceCercano = 0;
    for (size_t i = 1; i < lista.size(); ++i) {
        double d = obtenerDistancia(lista[i], referencia);
        if (d < menor) {
            menor = d;
            indiceCercano = static_cast<int>(i);
        }
    }
    return menor;
}

// BONO: distancia total si se recorren los puntos en el orden del vector
double distanciaRecorrida(const std::vector<Coordenada> &lista) {
    double total = 0.0;
    for (size_t i = 0; i + 1 < lista.size(); ++i) {
        total += obtenerDistancia(lista[i], lista[i + 1]);
    }
    return total;
}

int main() {
    int total;
    std::cout << "Ingrese la cantidad de puntos (mínimo 2): ";
    std::cin >> total;

    if (total < 2) {
        std::cout << "Se necesitan al menos 2 puntos.\n";
        return 1;
    }

    std::vector<Coordenada> lista;
    lista.reserve(total);
    cargarCoordenadas(lista, total);

    Coordenada referencia;
    std::cout << "Ingrese las coordenadas del punto de referencia (x y): ";
    std::cin >> referencia.posX >> referencia.posY;

    int indiceCercano;
    double distanciaMinima = encontrarDistanciaMinima(lista, referencia, indiceCercano);

    std::cout << "\nEl punto más cercano es: (" << lista[indiceCercano].posX
              << ", " << lista[indiceCercano].posY << ")\n";
    std::cout << "Distancia mínima = " << distanciaMinima << "\n";

    std::cout << "Bono - distancia total recorriendo puntos en orden = " << distanciaRecorrida(lista) << "\n";

    return 0;
}
