#include "inc/arvoreBinaria.h"
#include <stdlib.h>
#include <stdio.h>
void inicializar(ArvoreBB** arv){
  arv = NULL;
}
int inserir_interativo(ArvoreBB **a, int chave, float val) {
  ArvoreBB *atual = *a;
  while (atual != NULL) {
    if (chave == atual->chave) {
      return 0;
    } else if (chave < atual->chave) {
      atual = atual->esq;
    } else {
      atual = atual->dir;
    }
  }
  ArvoreBB *novo = (ArvoreBB *)malloc(sizeof(ArvoreBB));
  novo->chave = chave;
  novo->valor = val;
  novo->esq = NULL;
  novo->dir = NULL;
  *a = novo;
  return 1;
}

int inserir_recursivo(ArvoreBB **a, int chave, float val) {
  if (*a == NULL) {
    ArvoreBB *novo = (ArvoreBB *)malloc(sizeof(ArvoreBB));
    novo->chave = chave;
    novo->valor = val;
    novo->esq = NULL;
    novo->dir = NULL;
    *a = novo;
    return 1;
  }
  if (chave == (*a)->chave) {
    return 0;
  }
  if (chave < (*a)->chave) {
    inserir_recursivo(&((*a)->esq), chave, val);
  } else {
    inserir_recursivo(&((*a)->dir), chave, val);
  }
}
float buscar_interativo(ArvoreBB *a, int chave) {
  while (a != NULL) {
    if (chave == a->chave) {
      return a->valor;
    } else if (chave < a->chave) {
      a = a->esq;
    } else {
      a = a->dir;
    }
  }
  return 0.0; 
}
float buscar_recursivo(ArvoreBB *a, int chave) {
  if (a == NULL) {
    return 0.0;
  }
  if (chave == a->chave) {
    return a->valor;
  } else if (chave < a->chave) {
    return buscar_recursivo(a->esq, chave);
  } else {
    return buscar_recursivo(a->dir, chave);
  }
}
void listar_elementos (ArvoreBB *a) {
  if (a != NULL) {
    listar_elementos(a->esq);
    printf("chave: %d valor: %f\n", a->chave, a->valor);
    listar_elementos(a->dir);
  }
}