#include "./include/screen.h"
#include "./include/controller.h"
#include <iostream>
#include <windows.h>

// g++ main.cpp screen.cpp -o main.exe

int x, y;

void derecha(){
  x++;
}

char capturarTecla() {
    MSG msg;
    if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
        if (msg.message == WM_KEYDOWN) { // Detecta una tecla presionada
            char tecla = static_cast<char>(msg.wParam); // Convertir la tecla
            TranslateMessage(&msg); // Traducir teclas especiales como Shift
            DispatchMessage(&msg);  // Procesar otros mensajes
            return tecla;
        }
    }
    return '\0'; // Ninguna tecla presionada
}

int main(){
  x = 3;
  y = 6;
  Screen s(16, 8);
  s.addBorder();
  s.controller.registerAction('d', derecha);
  while(true){
    system("cls");
    s.addChar(x, y, ' ');
    s.controller.waitForAction(capturarTecla());
    s.addChar(x, y, 'o');
    s.show();
  }

  return 0;
}