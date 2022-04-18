#include "src/lista.h"
#include "src/pila.h"
#include "src/cola.h"
#include <stdio.h>
#include <stdlib.h>
#include "pa2mm.h"

bool es_mayor_a_limite(void* elemento, void* limite){
  if(!elemento || !limite)
    return false;

  return (*(int*)elemento > *(int*)limite);
}

void pruebaDeCreacionDeListaYDestruccionDeLista(){
  lista_t* lista = lista_crear();

  pa2m_afirmar((lista != NULL), "La lista se pudo crear con exito");

  lista_destruir(lista);
}

void dadaUnaListaNULL_susCamposSonCorrectos(){
  lista_t* lista = NULL;

  pa2m_afirmar((lista_primero(lista) == NULL), "El primer elemento de la lista es NULL");
  pa2m_afirmar((lista_ultimo(lista) == NULL), "El ultimo elemento de la lista es NULL");
  pa2m_afirmar((lista_vacia(lista) == true), "La lista esta vacia");
  pa2m_afirmar((lista_tamanio(lista) == 0), "La lista tiene 0 elementos");

}

void dadaUnaListaNULL_noPuedoInsertarElementos(){
  lista_t* lista = NULL;
  char a = 'a';

  pa2m_afirmar((lista_insertar(lista, &a) == NULL), "No se puede insertar un elemento a una lista NULL");
  pa2m_afirmar((lista_insertar_en_posicion(lista, &a, 0) == NULL), "No se puede insertar un elemento a una lista NULL en una posicion determinada");
}

void dadaUnaListaNULL_noPuedoObtenerElementoEnPosicion(){
  lista_t* lista = NULL;
  
  pa2m_afirmar((lista_elemento_en_posicion(lista, 0) == NULL), "No puedo obtener elemento posicion de lista NULL");

}

void dadaUnaListaVacia_susCamposSonCorrectos(){
  lista_t* lista = lista_crear();

  pa2m_afirmar((lista_primero(lista) == NULL), "El primer elemento de la lista es NULL");
  pa2m_afirmar((lista_ultimo(lista) == NULL), "El ultimo elemento de la lista es NULL");
  pa2m_afirmar((lista_vacia(lista) == true), "La lista esta vacia");
  pa2m_afirmar((lista_tamanio(lista) == 0), "La lista tiene 0 elemento");

  lista_destruir(lista);
}

void dadaUnaListaVacia_puedoInsertar1Elemento(){
  lista_t* lista = lista_crear();
  int elemento = 1;

  pa2m_afirmar((lista_insertar(lista, &elemento)), "Puedo agregar 1 elemento a una lista vacia");

  lista_destruir(lista);
}

void dadaUnaListaVacia_puedoInsertar3Elementos(){
  lista_t* lista = lista_crear();
  int elemento1 = 1, elemento2 = 2, elemento3 = 3;

  pa2m_afirmar((lista_insertar(lista, &elemento1) != NULL), "Puedo insertar 1 elemento");
  pa2m_afirmar((lista_insertar(lista, &elemento2) != NULL), "Puedo insertar 2 elemento");
  pa2m_afirmar((lista_insertar(lista, &elemento3) != NULL), "Puedo insertar 3 elemento");

  lista_destruir(lista);
}

void dadaUnaListaConUnElemento_susCamposSonCorrectos(){
  lista_t* lista = lista_crear();
  int elemento = 1;

  lista = lista_insertar(lista, &elemento);

  pa2m_afirmar((lista_primero(lista) == &elemento), "El primer elemento de la lista es el elemento agregado");
  pa2m_afirmar((lista_ultimo(lista) == &elemento), "El ultimo elemento de la lista es el elemento agregado");
  pa2m_afirmar((lista_vacia(lista) == false), "La lista no esta vacia");
  pa2m_afirmar((lista_tamanio(lista) == 1), "La lista tiene 1 elemento");
  
  lista_destruir(lista);
}

void dadaUnaListaConMultiplesElementos_susCamposSonCorrectos(){
  lista_t* lista = lista_crear();
  int elementos[100000];
  for(int i = 0; i < 100000; i++){
    elementos[i] = i;
    lista = lista_insertar(lista, &elementos[i]);
  }

  pa2m_afirmar((lista_primero(lista) == &elementos[0]), "El primer elemento de la lista es el primer elemento agregado");
  pa2m_afirmar((lista_ultimo(lista) == &elementos[99999]), "El ultimo elemento de la lista es el ultimo elemento agregado");
  pa2m_afirmar((lista_vacia(lista) == false), "La lista no esta vacia");
  pa2m_afirmar((lista_tamanio(lista) == 100000), "La lista tiene 100000 elementos");
  
  lista_destruir(lista);
}

void dadaUnaListaConMultiplesElementos_puedoObtenerElementoEnPosicion(){
  lista_t* lista = lista_crear();
  int elementos[10];
  for(int i = 0; i < 10; i++){
    elementos[i] = i;
    lista = lista_insertar(lista, &elementos[i]);
  }

  pa2m_afirmar((lista_elemento_en_posicion(lista, 4) == &elementos[4]), "El elemento en una posicion arbitraria es correcto");
  pa2m_afirmar((lista_elemento_en_posicion(lista, 11) == NULL), "No puedo obtener elemento en posicion invalida");
  
  lista_destruir(lista);
}

void dadaUnaListaVacia_noPuedoObtenerElementoEnPosicion(){
  lista_t* lista = lista_crear();
  
  pa2m_afirmar((lista_elemento_en_posicion(lista, 0) == NULL), "No puedo obtener elemento posicion de lista vacia");

  lista_destruir(lista);
}

void dadaUnaListaVacia_puedoInsertarEnPosicion0(){
  lista_t* lista = lista_crear();
  int elemento1 = 1;

  pa2m_afirmar((lista_insertar_en_posicion(lista, &elemento1, 0) != NULL), "Puedo insertar elemento en lista vacia en la posicion 0");
  pa2m_afirmar((lista_primero(lista) == &elemento1), "El primer elemento de la lista es el elemento agregado");
  pa2m_afirmar((lista_ultimo(lista) == &elemento1), "El ultimo elemento de la lista es el elemento agregado");
  pa2m_afirmar((lista_tamanio(lista) == 1), "La lista tiene 1 elementos");

  lista_destruir(lista);
}

void dadaUnaListaVacia_puedoInsertarEnPosicionInvalida(){
  lista_t* lista = lista_crear();
  int elemento1 = 1;

  pa2m_afirmar((lista_insertar_en_posicion(lista, &elemento1, 3) != NULL), "Puedo insertar elemento en lista vacia en posicion invalida");
  pa2m_afirmar((lista_primero(lista) == &elemento1), "El primer elemento de la lista es el elemento agregado");
  pa2m_afirmar((lista_ultimo(lista) == &elemento1), "El ultimo elemento de la lista es el elemento agregado");
  pa2m_afirmar((lista_tamanio(lista) == 1), "La lista tiene 1 elementos");

  lista_destruir(lista);
}

void dadaUnaListaConElementos_puedoInsertarEnPosicionInicial(){
  lista_t* lista = lista_crear();
  int elemento1 = 1, elemento2 = 2, elemento3 = 3, elemento4 = 4, elemento5 = 5, elemento6 = 6;

  lista = lista_insertar(lista, &elemento1);
  lista = lista_insertar(lista, &elemento2);
  lista = lista_insertar(lista, &elemento3);
  lista = lista_insertar(lista, &elemento4);
  lista = lista_insertar(lista, &elemento5);

  pa2m_afirmar((lista_insertar_en_posicion(lista, &elemento6, 0) != NULL), "Puedo insertar elemento en lista con elementos en posicion 0");
  pa2m_afirmar((lista_primero(lista) == &elemento6), "El primer elemento de la lista es el elemento agregado");
  pa2m_afirmar((lista_tamanio(lista) == 6), "La lista tiene 6 elementos");

  lista_destruir(lista);
}

void dadaUnaListaConElementos_puedoInsertarEnPosicionFinal(){
  lista_t* lista = lista_crear();
  int elemento1 = 1, elemento2 = 2, elemento3 = 3, elemento4 = 4, elemento5 = 5, elemento6 = 6;

  lista = lista_insertar(lista, &elemento1);
  lista = lista_insertar(lista, &elemento2);
  lista = lista_insertar(lista, &elemento3);
  lista = lista_insertar(lista, &elemento4);
  lista = lista_insertar(lista, &elemento5);

  pa2m_afirmar((lista_insertar_en_posicion(lista, &elemento6, 5) != NULL), "Puedo insertar elemento en lista con elementos en posicion final");
  pa2m_afirmar((lista_ultimo(lista) == &elemento6), "El ultimo elemento de la lista es el elemento agregado");
  pa2m_afirmar((lista_tamanio(lista) == 6), "La lista tiene 6 elementos");

  lista_destruir(lista);
}

void dadaUnaListaConElementos_puedoInsertarEnPosicionArbitraria(){
  lista_t* lista = lista_crear();
  int elemento1 = 1, elemento2 = 2, elemento3 = 3, elemento4 = 4, elemento5 = 5, elemento6 = 6;

  lista = lista_insertar(lista, &elemento1);
  lista = lista_insertar(lista, &elemento2);
  lista = lista_insertar(lista, &elemento3);
  lista = lista_insertar(lista, &elemento4);
  lista = lista_insertar(lista, &elemento5);

  pa2m_afirmar((lista_insertar_en_posicion(lista, &elemento6, 3) != NULL), "Puedo insertar elemento en lista con elementos en posicion 3");
  pa2m_afirmar((lista_elemento_en_posicion(lista, 3) == &elemento6), "El elemento agregado esta en la posicion 3");
  pa2m_afirmar((lista_tamanio(lista) == 6), "La lista tiene 6 elementos");

  lista_destruir(lista);
}

void dadaUnaListaConElementos_puedoInsertarEnPosicionInvalida(){
  lista_t* lista = lista_crear();
  int elemento1 = 1, elemento2 = 2, elemento3 = 3, elemento4 = 4, elemento5 = 5, elemento6 = 6;

  lista = lista_insertar(lista, &elemento1);
  lista = lista_insertar(lista, &elemento2);
  lista = lista_insertar(lista, &elemento3);
  lista = lista_insertar(lista, &elemento4);
  lista = lista_insertar(lista, &elemento5);

  pa2m_afirmar((lista_insertar_en_posicion(lista, &elemento6, 10) != NULL), "Puedo insertar elemento en lista con elementos en posicion invalida");
  pa2m_afirmar((lista_ultimo(lista) == &elemento6), "El ultimo elemento de la lista es el elemento agregado");
  pa2m_afirmar((lista_tamanio(lista) == 6), "La lista tiene 6 elementos");

  lista_destruir(lista);
}

void dadaUnaListaNULL_noPuedoQuitarElementos(){
  lista_t* lista = NULL;

  pa2m_afirmar((lista_quitar(lista) == NULL), "No se puede quitar el elemento ya que la lista es NULL");
}

void dadaUnaListaVacia_noPuedoQuitarElementos(){
  lista_t* lista = lista_crear();

  pa2m_afirmar((lista_quitar(lista) == NULL), "No se puede quitar el elemento ya que la lista esta vacia");

  lista_destruir(lista);
}

void dadaUnaListaConMultiplesElementos_puedoQuitarElementosHastaVaciarla(){
  lista_t* lista = lista_crear();
  int elemento1 = 1, elemento2 = 2;
  
  lista = lista_insertar(lista, &elemento1);
  lista = lista_insertar(lista, &elemento2);

  pa2m_afirmar((lista_quitar(lista) == &elemento2), "El elemento quitado es el que estaba en la ultima posicion");
  pa2m_afirmar(lista_ultimo(lista) == &elemento1, "El nuevo ultimo es asignado correctamente");
  pa2m_afirmar(lista_tamanio(lista) == 1, "La lista tiene 1 elemento");


  pa2m_afirmar((lista_quitar(lista) == &elemento1), "El elemento quitado es el ultimo que estaba en la lista");
  pa2m_afirmar(lista_primero(lista) == NULL, "Al estar la lista vacia, el nuevo primero es NULL");
  pa2m_afirmar(lista_ultimo(lista) == NULL, "Al estar la lista vacia, el nuevo ultimo es NULL");
  pa2m_afirmar(lista_tamanio(lista) == 0, "La lista tiene 0 elementos");
  
  lista_destruir(lista);
}

void dadaUnaListaNULL_noPuedoQuitarElementosEnPosicion(){
  lista_t* lista = NULL;

  pa2m_afirmar((lista_quitar_de_posicion(lista, 0) == NULL), "No se puede quitar el elemento ya que la lista es NULL");
}

void dadaUnaListaVacia_noPuedoQuitarElementosEnPosicion(){
  lista_t* lista = lista_crear();

  pa2m_afirmar((lista_quitar_de_posicion(lista, 0) == NULL), "No se puede quitar el elemento ya que la lista esta vacia");

  lista_destruir(lista);
}

void dadaUnaListaConMultiplesElementos_puedoQuitarElementosEnPosicionHastaVaciarla(){
  lista_t* lista = lista_crear();
  int elemento1 = 1, elemento2 = 2, elemento3 = 3;
  
  lista = lista_insertar(lista, &elemento1);
  lista = lista_insertar(lista, &elemento2);
  lista = lista_insertar(lista, &elemento3);

  pa2m_afirmar((lista_quitar_de_posicion(lista, 1) == &elemento2), "El elemento quitado es el que estaba en la posicion 1");
  pa2m_afirmar(lista_tamanio(lista) == 2, "La lista tiene 2 elemento");

  pa2m_afirmar((lista_quitar_de_posicion(lista, 0) == &elemento1), "El elemento quitado es el que estaba en la posicion 0");
  pa2m_afirmar(lista_primero(lista) == &elemento3, "El nuevo primero es asignado correctamente");
  pa2m_afirmar(lista_tamanio(lista) == 1, "La lista tiene 1 elemento");

  pa2m_afirmar((lista_quitar_de_posicion(lista, 0) == &elemento3), "El elemento quitado es el que quedaba en la lista");
  pa2m_afirmar(lista_primero(lista) == NULL, "Al estar la lista vacia, el nuevo primero es NULL");
  pa2m_afirmar(lista_ultimo(lista) == NULL, "Al estar la lista vacia, el nuevo ultimo es NULL");
  pa2m_afirmar(lista_tamanio(lista) == 0, "La lista tiene 0 elementos");
  
  lista_destruir(lista);
}

void dadaUnaListaConMultiplesElementos_puedoQuitarElementosEnPosicionInvalida(){
  lista_t* lista = lista_crear();
  int elemento1 = 1, elemento2 = 2;
  
  lista = lista_insertar(lista, &elemento1);
  lista = lista_insertar(lista, &elemento2);

  pa2m_afirmar((lista_quitar_de_posicion(lista, 2) == &elemento2), "El elemento quitado es el que estaba en la ultima posicion");
  pa2m_afirmar(lista_ultimo(lista) == &elemento1, "El nuevo ultimo es asignado correctamente");
  pa2m_afirmar(lista_tamanio(lista) == 1, "La lista tiene 1 elemento");
  
  lista_destruir(lista);
}

void dadaUnaListaNULL_listaConCadaElementoDevuelve0(){
  lista_t* lista = NULL;
  int limite = 5;

  pa2m_afirmar((lista_con_cada_elemento(lista, es_mayor_a_limite, &limite) == 0), "Aplicar funcion a cada elemento de una lista nula me da 0");

  lista_destruir(lista);
}

void dadaUnaListaVacia_listaConCadaElementoDevuelve0(){
  lista_t* lista = lista_crear();
  int limite = -1;
  
  pa2m_afirmar((lista_con_cada_elemento(lista, es_mayor_a_limite, &limite) == 0), "Aplicar funcion a cada elemento de una lista vacia me da 0");

  lista_destruir(lista);
}

void dadaUnaFuncionNULL_listaConCadaElementoDevuelve0(){
  lista_t* lista = lista_crear();
  int elemento1 = 9, elemento2 = 7, elemento3 = 6;
  int limite = 5;

  lista = lista_insertar(lista, &elemento1);
  lista = lista_insertar(lista, &elemento2);
  lista = lista_insertar(lista, &elemento3);
  
  pa2m_afirmar((lista_con_cada_elemento(lista, NULL, &limite) == 0), "Aplicar funcion nula a cada elemento de una lista me da 0");

  lista_destruir(lista);
}

void dadaUnaListaConElementos_listaConCadaElementoDevuelveLaCantidadDeElementos(){
  lista_t* lista = lista_crear();
  int elemento1 = 9, elemento2 = 7, elemento3 = 6, elemento4 = 2, elemento5 = 8, elemento6 = 21; 
  int limite = 5;

  lista = lista_insertar(lista, &elemento1);
  lista = lista_insertar(lista, &elemento2);
  lista = lista_insertar(lista, &elemento3);
  lista = lista_insertar(lista, &elemento4);
  lista = lista_insertar(lista, &elemento5);
  lista = lista_insertar(lista, &elemento6);
  
  pa2m_afirmar((lista_con_cada_elemento(lista, es_mayor_a_limite, &limite) == 3), "Aplicar funcion a cada elemento de una lista recorre 3 elementos");

  lista_destruir(lista);
}



void pruebaDeCreacionYDestruccionDeIterador(){
  lista_t* lista_valida = lista_crear();
  lista_t* lista_invalida= NULL;
  lista_iterador_t* iterador_con_lista = lista_iterador_crear(lista_valida);
  lista_iterador_t* iterador_invalido = lista_iterador_crear(lista_invalida);

  pa2m_afirmar(iterador_con_lista != NULL, "El iterador con lista valida se pudo crear con exito");
  pa2m_afirmar(iterador_invalido == NULL, "El iterador con lista invalida no puede ser creado");

  lista_destruir(lista_valida);
  lista_iterador_destruir(iterador_con_lista);
}

void dadaUnaListaVacia_creoUnIteradorParaLaMisma_yNoPuedoOperar(){
  lista_t* lista = lista_crear();
  lista_iterador_t* iterador = lista_iterador_crear(lista);

  pa2m_afirmar((lista_iterador_elemento_actual(iterador) == NULL), "El elemento actual debe ser NULL");
  pa2m_afirmar((lista_iterador_tiene_siguiente(iterador) == false), "No hay elemento siguiente");
  pa2m_afirmar((lista_iterador_avanzar(iterador) == false), "No se puede avanzar al siguiente elemento");

  lista_destruir(lista);
  lista_iterador_destruir(iterador);
}

void dadaUnaListaConElementos_creoUnIteradorParaLaMisma_eIteroPorTodosLosElementos(){
  lista_t* lista = lista_crear();
  int elemento1 = 1, elemento2 = 2, elemento3 = 3;

  lista = lista_insertar(lista, &elemento1);
  lista = lista_insertar(lista, &elemento2);
  lista = lista_insertar(lista, &elemento3);

  lista_iterador_t* iterador = lista_iterador_crear(lista);

  pa2m_afirmar((lista_iterador_elemento_actual(iterador) == &elemento1), "El elemento actual debe ser el primero");
  pa2m_afirmar((lista_iterador_tiene_siguiente(iterador) == true), "Hay elemento sobre el cual iterar");
  pa2m_afirmar((lista_iterador_avanzar(iterador) == true), "Puedo avanzar al segundo elemento");

  pa2m_afirmar((lista_iterador_elemento_actual(iterador) == &elemento2), "El elemento actual debe ser el segundo");
  pa2m_afirmar((lista_iterador_tiene_siguiente(iterador) == true), "Hay elemento sobre el cual iterar");
  pa2m_afirmar((lista_iterador_avanzar(iterador) == true), "Puedo avanzar al tercer elemento");

  pa2m_afirmar((lista_iterador_elemento_actual(iterador) == &elemento3), "El elemento actual debe ser el tercero");
  pa2m_afirmar((lista_iterador_tiene_siguiente(iterador) == true), "Hay elemento sobre el cual iterar");
  pa2m_afirmar((lista_iterador_avanzar(iterador) == false), "Avanzar de elemento devuelve false ya que no hay mas elementos");

  pa2m_afirmar((lista_iterador_elemento_actual(iterador) == NULL), "El elemento actual debe ser NULL porque estoy al final de la lista");
  pa2m_afirmar((lista_iterador_tiene_siguiente(iterador) == false), "No hay elemento sobre el cual iterar");
  pa2m_afirmar((lista_iterador_avanzar(iterador) == false), "No puedo avanzar de elemento");

  lista_destruir(lista);
  lista_iterador_destruir(iterador);
}

void dadaUnaListaConElementos_creoUnIteradorParaLaMisma_eIteroPorTodosLosElementosUsandoUnFor(){
  lista_t* lista = lista_crear();
  int elementos[10];
  for(int i = 0; i < 10; i++){
    elementos[i] = i;
    lista = lista_insertar(lista, &elementos[i]);
  }
  
  lista_iterador_t* iterador = NULL;
  int j = 0;

  for(iterador = lista_iterador_crear(lista); lista_iterador_tiene_siguiente(iterador); lista_iterador_avanzar(iterador)){
    pa2m_afirmar((lista_iterador_elemento_actual(iterador) == &elementos[j]), "El elemento actual del iterador es el elemento en la posicion");
    j++;
  }
  pa2m_afirmar((j == 10), "Se recorrieron todos los elementos de la lista");


  lista_destruir(lista);
  lista_iterador_destruir(iterador);
}


void pruebaDeCreacionYDestruccionDePila(){
  pila_t* pila = pila_crear();

  pa2m_afirmar((pila != NULL), "La pila se pudo crear con exito");

  pila_destruir(pila);
}

void dadaUnaPilaNULL_noPuedoApilarYDesapilar(){
  pila_t* pila = NULL;
  int elemento1 = 1;

  pa2m_afirmar((pila_apilar(pila, &elemento1) == NULL), "No puedo apilar un elemento en una pila NULL");
  pa2m_afirmar((pila_desapilar(pila) == NULL), "No puedo desapilar un elemento en una pila NULL");

  pila_destruir(pila);
}

void dadaUnaPilaVacia_apiloYDesapiloUnElemento(){
  pila_t* pila = pila_crear();
  int elemento1 = 1;

  pa2m_afirmar((pila_apilar(pila, &elemento1) != NULL), "Puedo apilar 1 elemento en una pila vacia");
  pa2m_afirmar((pila_desapilar(pila) == &elemento1), "Puedo desapilar 1 elemento en una pila vacia");
  pa2m_afirmar((pila_desapilar(pila) == NULL), "Cuando no quedan mas elementos para desapilar, recibo NULL");

  pila_destruir(pila);
}

void dadaUnaPilaVacia_apiloYDesapiloMultiplesElementos(){
  pila_t* pila = pila_crear();
  int elemento1 = 1, elemento2 = 2, elemento3 = 3;

  pa2m_afirmar((pila_apilar(pila, &elemento1) != NULL), "Puedo apilar 1 elemento en una pila vacia");
  pa2m_afirmar((pila_apilar(pila, &elemento2) != NULL), "Puedo apilar 1 elemento en una pila con 1 elemento");
  pa2m_afirmar((pila_apilar(pila, &elemento3) != NULL), "Puedo apilar 1 elemento en una pila con 2 elementos");
  pa2m_afirmar((pila_desapilar(pila) == &elemento3), "El primer elemento desapilado es el ultimo apilado");
  pa2m_afirmar((pila_desapilar(pila) == &elemento2), "El segundo elemento desapilado es el segundo apilado");
  pa2m_afirmar((pila_desapilar(pila) == &elemento1), "El ultimo elemento desapilado es el primer apilado");

  pila_destruir(pila); 
}

void dadaUnaPilaNULL_susCamposSonCorrectos(){
  pila_t* pila = pila_crear();

  pa2m_afirmar((pila_tope(pila) == NULL), "El tope de la pila vacia es NULL");
  pa2m_afirmar((pila_vacia(pila) == true), "La pila esta vacia");
  pa2m_afirmar((pila_tamanio(pila) == 0), "La pila tiene 0 elementos");

  pila_destruir(pila);
}

void dadaUnaPilaVacia_susCamposSonCorrectos(){
  pila_t* pila = NULL;

  pa2m_afirmar((pila_tope(pila) == NULL), "El tope de la pila NULL es NULL");
  pa2m_afirmar((pila_vacia(pila) == true), "La pila esta vacia ya que es NULL");
  pa2m_afirmar((pila_tamanio(pila) == 0), "La pila tiene 0 elementos ya que es NULL");

  pila_destruir(pila);
}

void dadaUnaPilaConUnElemento_susCamposSonCorrectos(){
  pila_t* pila = pila_crear();
  int elemento1 = 1;
  pila_apilar(pila, &elemento1);

  pa2m_afirmar((pila_tope(pila) == &elemento1), "El tope de la pila es el elemento cargado");
  pa2m_afirmar((pila_vacia(pila) == false), "La pila no esta vacia (tiene 1 elemento)");
  pa2m_afirmar((pila_tamanio(pila) == 1), "La pila tiene 1 elementos");

  pila_destruir(pila);
}

void dadaUnaPilaConMultiples_susCamposSonCorrectos(){
  pila_t* pila = pila_crear();
  int elementos[100000];
  for(int i = 0; i < 100000; i++){
    elementos[i] = i;
    pila = pila_apilar(pila, &elementos[i]);
  }

  pa2m_afirmar((pila_tope(pila) == &elementos[99999]), "El tope de la pila es el ultimo elemento cargado");
  pa2m_afirmar((pila_vacia(pila) == false), "La pila no esta vacia (tiene 100000 elementos)");
  pa2m_afirmar((pila_tamanio(pila) == 100000), "La pila tiene 100000 elementos");

  pila_destruir(pila);
}



void pruebaDeCreacionYDestruccionDeCola(){
  cola_t* cola = cola_crear();

  pa2m_afirmar((cola != NULL), "La cola pudo ser creada con exito");

  cola_destruir(cola);
}

void dadaUnaColaNULL_noPuedoEncolarYDesencolar(){
  cola_t* cola = NULL;
  int elemento1 = 1;

  pa2m_afirmar((cola_encolar(cola, &elemento1) == NULL), "No puedo encolar un elemento en una cola NULL");
  pa2m_afirmar((cola_desencolar(cola) == NULL), "No puedo desencolar un elemento en una cola NULL");

  cola_destruir(cola);
}

void dadaUnaColaVacia_encoloYDesencoloUnElemento(){
  cola_t* cola = cola_crear();
  int elemento1 = 1;

  pa2m_afirmar((cola_encolar(cola, &elemento1) != NULL), "Puedo encolar un elemento en una cola vacia");
  pa2m_afirmar((cola_desencolar(cola) == &elemento1), "Desencolar me devuelve el elemento encolado");
  pa2m_afirmar((cola_desencolar(cola) == NULL), "No puedo desencolar en una cola vacia");

  cola_destruir(cola);
}

void dadaUnaColaVacia_encoloYDesencoloMultiplesElementos(){
  cola_t* cola = cola_crear();
  int elemento1 = 1, elemento2 = 2, elemento3 = 3;

  pa2m_afirmar((cola_encolar(cola, &elemento1) != NULL), "Puedo encolar 1 elemento en una cola vacia");
  pa2m_afirmar((cola_encolar(cola, &elemento2) != NULL), "Puedo encolar 1 elemento en una cola con 1 elemento");
  pa2m_afirmar((cola_encolar(cola, &elemento3) != NULL), "Puedo encolar 1 elemento en una cola con 2 elementos");
  pa2m_afirmar((cola_desencolar(cola) == &elemento1), "El primer elemento desencolado es el primer encolado");
  pa2m_afirmar((cola_desencolar(cola) == &elemento2), "El segundo elemento desencolado es el segundo encolado");
  pa2m_afirmar((cola_desencolar(cola) == &elemento3), "El ultimo elemento desencolado es el ultimo encolado");

  cola_destruir(cola); 
}

void dadaUnaColaNULL_susCamposSonCorrectos(){
  cola_t* cola = NULL;

  pa2m_afirmar((cola_frente(cola) == NULL), "El frente de la cola NULL es NULL");
  pa2m_afirmar((cola_vacia(cola) == true), "La cola NULL esta vacia");
  pa2m_afirmar((cola_tamanio(cola) == 0), "La cola NULL tiene 0 elementos");
}

void dadaUnaColaVacia_susCamposSonCorrectos(){
  cola_t* cola = cola_crear();

  pa2m_afirmar((cola_frente(cola) == NULL), "El frente de la cola vacia es NULL");
  pa2m_afirmar((cola_vacia(cola) == true), "La cola esta vacia");
  pa2m_afirmar((cola_tamanio(cola) == 0), "La cola tiene 0 elementos");

  cola_destruir(cola);
}

void dadaUnaColaConUnElemento_susCamposSonCorrectos(){
  cola_t* cola = cola_crear();
  int elemento1 = 1;
  cola_encolar(cola, &elemento1);

  pa2m_afirmar((cola_frente(cola) == &elemento1), "El frente de la cola es el elemento cargado");
  pa2m_afirmar((cola_vacia(cola) == false), "La cola no esta vacia (tiene 1 elemento)");
  pa2m_afirmar((cola_tamanio(cola) == 1), "La cola tiene 1 elementos");

  cola_destruir(cola);
}

void dadaUnaColaConMultiples_susCamposSonCorrectos(){
  cola_t* cola = cola_crear();
  int elementos[100000];
  for(int i = 0; i < 100000; i++){
    elementos[i] = i;
    cola = cola_encolar(cola, &elementos[i]);
  }

  pa2m_afirmar((cola_frente(cola) == &elementos[0]), "El frente de la cola es el primer elemento cargado");
  pa2m_afirmar((cola_vacia(cola) == false), "La cola no esta vacia (tiene 100000 elementos)");
  pa2m_afirmar((cola_tamanio(cola) == 100000), "La cola tiene 100000 elementos");

  cola_destruir(cola);
}

int main() {
  pa2m_nuevo_grupo("Pruebas de creacion y destruccion de lista");
  pruebaDeCreacionDeListaYDestruccionDeLista();

  pa2m_nuevo_grupo("Pruebas con una lista NULL");
  dadaUnaListaNULL_susCamposSonCorrectos();
  dadaUnaListaNULL_noPuedoInsertarElementos();
  dadaUnaListaNULL_noPuedoObtenerElementoEnPosicion();

  pa2m_nuevo_grupo("Pruebas de lista vacia");
  dadaUnaListaVacia_susCamposSonCorrectos();
  dadaUnaListaVacia_puedoInsertar1Elemento();
  dadaUnaListaVacia_puedoInsertar3Elementos();
  dadaUnaListaVacia_noPuedoObtenerElementoEnPosicion();
  dadaUnaListaVacia_listaConCadaElementoDevuelve0();

  pa2m_nuevo_grupo("Pruebas de lista con 1 elemento");
  dadaUnaListaConUnElemento_susCamposSonCorrectos();

  pa2m_nuevo_grupo("Pruebas de lista con muchos elementos");
  dadaUnaListaConMultiplesElementos_susCamposSonCorrectos();
  dadaUnaListaConMultiplesElementos_puedoObtenerElementoEnPosicion();

  pa2m_nuevo_grupo("Pruebas de insercion en posicion de lista vacia");
  dadaUnaListaVacia_puedoInsertarEnPosicion0();
  dadaUnaListaVacia_puedoInsertarEnPosicionInvalida();

  pa2m_nuevo_grupo("Pruebas de insercion en posicion de lista con elementos");
  dadaUnaListaConElementos_puedoInsertarEnPosicionInicial();
  dadaUnaListaConElementos_puedoInsertarEnPosicionFinal();
  dadaUnaListaConElementos_puedoInsertarEnPosicionArbitraria();
  dadaUnaListaConElementos_puedoInsertarEnPosicionInvalida();

  pa2m_nuevo_grupo("Pruebas de eliminacion");
  dadaUnaListaNULL_noPuedoQuitarElementos();
  dadaUnaListaVacia_noPuedoQuitarElementos();
  dadaUnaListaConMultiplesElementos_puedoQuitarElementosHastaVaciarla();

  pa2m_nuevo_grupo("Pruebas de eliminacion en posicion");
  dadaUnaListaNULL_noPuedoQuitarElementosEnPosicion();
  dadaUnaListaVacia_noPuedoQuitarElementosEnPosicion();
  dadaUnaListaConMultiplesElementos_puedoQuitarElementosEnPosicionHastaVaciarla();
  dadaUnaListaConMultiplesElementos_puedoQuitarElementosEnPosicionInvalida();

  pa2m_nuevo_grupo("Pruebas de iterador interno de lista");
  dadaUnaListaNULL_listaConCadaElementoDevuelve0();
  dadaUnaListaVacia_listaConCadaElementoDevuelve0();
  dadaUnaFuncionNULL_listaConCadaElementoDevuelve0();
  dadaUnaListaConElementos_listaConCadaElementoDevuelveLaCantidadDeElementos();



  pa2m_nuevo_grupo("Pruebas de creacion y destruccion de iterador externo de lista");
  pruebaDeCreacionYDestruccionDeIterador();

  pa2m_nuevo_grupo("Pruebas de iterador externo de lista");
  dadaUnaListaVacia_creoUnIteradorParaLaMisma_yNoPuedoOperar();
  dadaUnaListaConElementos_creoUnIteradorParaLaMisma_eIteroPorTodosLosElementos();
  dadaUnaListaConElementos_creoUnIteradorParaLaMisma_eIteroPorTodosLosElementosUsandoUnFor();



  pa2m_nuevo_grupo("Pruebas de creacion y destruccion de pilas");
  pruebaDeCreacionYDestruccionDePila();

  pa2m_nuevo_grupo("Pruebas de apilado y desapilado de pila");
  dadaUnaPilaNULL_noPuedoApilarYDesapilar();
  dadaUnaPilaVacia_apiloYDesapiloUnElemento();
  dadaUnaPilaVacia_apiloYDesapiloMultiplesElementos();

  pa2m_nuevo_grupo("Pruebas de campos de pila");
  dadaUnaPilaNULL_susCamposSonCorrectos();
  dadaUnaPilaVacia_susCamposSonCorrectos();
  dadaUnaPilaConUnElemento_susCamposSonCorrectos();
  dadaUnaPilaConMultiples_susCamposSonCorrectos();



  pa2m_nuevo_grupo("Pruebas de creacion y destruccion de colas");
  pruebaDeCreacionYDestruccionDeCola();

  pa2m_nuevo_grupo("Pruebas encolado y desencolado de cola");
  dadaUnaColaNULL_noPuedoEncolarYDesencolar();
  dadaUnaColaVacia_encoloYDesencoloUnElemento();
  dadaUnaColaVacia_encoloYDesencoloMultiplesElementos();
  
  pa2m_nuevo_grupo("Pruebas de campos de cola");
  dadaUnaColaNULL_susCamposSonCorrectos();
  dadaUnaColaVacia_susCamposSonCorrectos();
  dadaUnaColaConUnElemento_susCamposSonCorrectos();
  dadaUnaColaConMultiples_susCamposSonCorrectos();

  return pa2m_mostrar_reporte();
}



