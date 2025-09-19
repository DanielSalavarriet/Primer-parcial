#include <iostream>
#include <cmath>

// Estructura para un punto 2D
struct Coordenada {
    double posX;
    double posY;
};

// Función para calcular la distancia euclidiana
double obtenerDistancia(const Coordenada &a, const Coordenada &b) {
    return std::sqrt(std::pow(b.posX - a.posX, 2) + std::pow(b.posY - a.posY, 2));
}

int main() {
    Coordenada p1{0, 0};
    Coordenada p2{3, 4};

    std::cout << "Distancia entre p1 y p2 = " 
              << obtenerDistancia(p1, p2) << std::endl;

    return 0;
}
