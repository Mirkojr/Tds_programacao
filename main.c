#include <stdio.h>
#include "src/inc/arvoreBinaria.h"
#include <stdlib.h>
int main(void) {
 ArvoreBB *arvore = NULL;
  inicializar(&arvore);
  inserir_interativo(&arvore, 10, 5.5);
  inserir_recursivo(&arvore, 13, 4.2);
  inserir_recursivo(&arvore, 2, 9.9);
  float numero = buscar_interativo(&*arvore, 10);
  float numero2 = buscar_recursivo(&*arvore, 13);
  printf("%f %f\n", numero, numero2);
  listar_elementos(&*arvore);
  // Add more test cases as needed

  return 0;
}