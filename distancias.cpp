#include <iostream>
#include <cmath>
#include <vector>

// Estructura para un punto 2D
struct Coordenada {
    double posX;
    double posY;
};

// Función para calcular la distancia euclidiana
double obtenerDistancia(const Coordenada &a, const Coordenada &b) {
    return std::sqrt(std::pow(b.posX - a.posX, 2) + std::pow(b.posY - a.posY, 2));
}

// Función para leer puntos manualmente o usar predeterminados
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
        // Usar un patrón predeterminado (ejemplo: (0,0), (3,4), (6,8) ...)
        for (int i = 0; i < cantidad; ++i) {
            lista.push_back({3.0 * i, 4.0 * i});
        }
        std::cout << "Usando puntos predeterminados...\n";
    }
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

    std::cout << "\nLista de puntos cargados:\n";
    for (size_t i = 0; i < lista.size(); ++i) {
        std::cout << "  Punto " << i << ": (" << lista[i].posX << ", " << lista[i].posY << ")\n";
    }

    return 0;
}
