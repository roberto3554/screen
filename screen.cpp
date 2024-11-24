#include "screen.h"
#include <vector>
#include <iostream>
#include <string>

Screen::Screen(int width, int height) {
  this->width = width;
  this->height = height;
  border = false;
  screen.resize(height, std::vector<char>(width, ' '));
}

void Screen::show() {
  for (unsigned int i = 0; i < height; i++) {
    for (unsigned int j = 0; j < width; j++) {
      std::cout << screen[i][j];
    }
    std::cout << std::endl;
  }
}

void Screen::addBorder(std::string bor) {
  if(border){
    std::cerr << "Error: border alrready exist." << std::endl;
    return;
  }
  if(bor.size()<6){
    std::cerr << "Error: mark debe tener al menos 3 caracteres." << std::endl;
    return;
  }

  border = true;

  // Nuevo tamaño
  int newHeight = height + 2;
  int newWidth = width + 2;

  // Crear nueva pantalla con dimensiones ajustadas
  std::vector<std::vector<char>> newScreen(newHeight, std::vector<char>(newWidth, ' '));

  // Colocar el marco
  newScreen[0][0]                     = bor[0]; // Esquina superior izquierda
  newScreen[0][newWidth-1]            = bor[2]; // Esquina superior derecha
  newScreen[newHeight-1][0]           = bor[3]; // Esquina inferior izquierda
  newScreen[newHeight-1][newWidth-1]  = bor[5]; // Esquina inferior derecha

  for (int i=1; i<newHeight-1; i++) {
    newScreen[i][0]                   = bor[4]; // Borde izquierdo
    newScreen[i][newWidth-1]          = bor[4]; // Borde derecho
  }

  for (int j=1; j<newWidth-1; j++) {
    newScreen[0][j]                   = bor[1]; // Borde superior
    newScreen[newHeight-1][j]         = bor[1]; // Borde inferior
  }

  // Copiar el contenido antiguo dentro del nuevo marco
  for (int i=0; i<height; i++) {
    for (int j=0; j<width; j++) {
      newScreen[i+1][j+1] = screen[i][j];
    }
  }

  // Actualizar pantalla y dimensiones
  screen  = newScreen;
  height  = newHeight;
  width   = newWidth;
}
