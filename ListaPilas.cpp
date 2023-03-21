#include <iostream>
#include <string>
using namespace std;

class Nodo {
public:
  char valor;
  Nodo *next;
  Nodo(char v) { this->valor = v; }
};

class Lista {
public:
  Nodo *head = NULL;

  void agregar(char valor) {
    Nodo *nuevo = new Nodo(valor);
    nuevo->next = head;
    head = nuevo;
  }

bool eliminarCentro(char usuario) {
    if (head == NULL) return false;
  
    if (head->valor == usuario) {
      head = head->next;
      return true;
    }
  
    Nodo *anterior = head;
    Nodo *actual = anterior->next;
    while (actual != NULL) {
      if (actual->valor == usuario) {
        anterior->next = actual->next;
        return true;
      }
      anterior = actual;
      actual = actual->next;
    }
    return false;
  }
  void print() {
    Nodo *actual = this->head;
    while (actual != NULL) {
      cout << actual->valor;
      actual = actual->next;
    }
    cout << endl;
  }


void popearUltimoCaracter(){
    head = head->next;
  }
};

int main() {
  Lista lista;
  while (true) {
    cout << "presionar 1 para agregar un caracter, " << endl;
    cout << "2 para eliminar un caracter del centro y "<< endl;
    cout<< "3 para eliminar el ultimo caracter en la lista"<<endl;
    int opcionUsuario;
    cin >> opcionUsuario;
    if (opcionUsuario == 1) {
      cout << " agregue un caracter a la lista enlazada" << endl;
      char caracter;
      cin >> caracter;
      lista.agregar(caracter);
      cout << "La lista actual es : ";
      lista.print();
    }
    else if(opcionUsuario == 2) {
      cout << "inserte el dato que quiere eliminar" << endl;
      char datoParaEliminar;
      cin >> datoParaEliminar;
       lista.eliminarCentro(datoParaEliminar);
        cout << "El elemento se elimino exitosamente" << endl;
      cout << "La nueva lista es: " << endl;
      lista.print();
    }
    else if(opcionUsuario == 3){
      lista.popearUltimoCaracter();
      cout<<"La lista actual tiene los siguientes elementos: "<<endl;
      lista.print();
    }
  }
}
