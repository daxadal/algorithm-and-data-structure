﻿//
//  Pila.h
//
//

#ifndef _Pila_h
#define _Pila_h


#include <iostream>
#include <string>
#include <cassert>
#include <cstddef>
#include "Excepciones.h"
using namespace std;

// Excepcion generada por algunos ḿetodos de Pila. ∗/
class EPilaVacia : public ExcepcionTAD {
	public :
    EPilaVacia () {};
    EPilaVacia(const std :: string &msg) : ExcepcionTAD(msg) {}
};

template <class T>
class PilaLE {
public:
    PilaLE() : _cima(NULL) {}
    
    // Constructor copia
    PilaLE(const PilaLE<T> &other) : _cima(NULL) {
        copia(other);
    }
    
    ~PilaLE() {
        libera(_cima);
        _cima = NULL;
    }
    
    void apila(const T &elem) {
        _cima = new Nodo(elem, _cima);
    }
    
    void desapila() {
        if ( esVacia ()) throw EPilaVacia("Pila vacia al intentar desapilar");
        Nodo* aBorrar = _cima;
        _cima = _cima->_sig;
        delete aBorrar;
    }
    
    const T &cima() const {
        if (esVacia()) throw EPilaVacia("Pila vacia al intentar desapilar");
        return _cima->_elem;
    }
    
    bool esVacia() const {
        return _cima == NULL;
    }
    
    // Operador de asignacion
    PilaLE &operator=(const PilaLE &other ) {
        if (this != &other) {
            libera(_cima);
            copia(other);
        }
        return *this;
    }
    
    // Operador de comparacion .
    bool operator==(const PilaLE &rhs ) const {
        Nodo* cima1 = _cima;
        Nodo* cima2 = rhs._cima ;
        while ((cima1 != NULL) && (cima2 != NULL) &&
               cima1->_elem == cima2->_elem ) {
            cima1 = cima1->_sig;
            cima2 = cima2->_sig;
        }
        return (cima1 == NULL) && (cima2 == NULL);
    }
    
    friend ostream &operator<< (std::ostream &out, const PilaLE &p){
        PilaLE<T> paux = p;
        while (!paux.esVacia() ) {
            out << paux.cima() << " ";
            paux.desapila();
        }
        return out;
    }

	///////////
	//Ejercicios

	void inversa() {
		if (!this->esVacia() && _cima->_sig != NULL) { //Al menos dos elementos
			
			Nodo* ant_ant = NULL;
			Nodo* ant = _cima;
			_cima = _cima->_sig;
			
			while(_cima != NULL) {
				ant->_sig = ant_ant;

				ant_ant = ant;
				ant = _cima;
				_cima = _cima->_sig;
			}
			ant->_sig = ant_ant;

			_cima = ant;
		}
	}

	void vacia() {
		this->libera(_cima);
	}

	void revolver() {
		if (!this->esVacia() && _cima->_sig != NULL) { //Al menos dos elementos
			Nodo* izda = _cima;
			Nodo* dcha = _cima->_sig;
			Nodo* nuevo;

			//Primer nodo
			nuevo = new Nodo(_cima->_sig->_elem, _cima);
			_cima = nuevo;

			//Nodos centrales
			while (dcha->_sig != NULL) { //No sea el ultimo nodo
				nuevo = new Nodo(dcha->_sig->_elem, dcha);
				izda->_sig = nuevo;
				izda = dcha;
				dcha = dcha->_sig;
			}

			//Ulitimo nodo
			nuevo = new Nodo(_cima->_sig->_elem, dcha);
			izda->_sig = nuevo;
		}
	}

	//Fin Ejercicios
    ///////////////

private:
    class Nodo {
    public:
        Nodo() : _sig(NULL) {}
        Nodo(const T &elem) : _elem(elem), _sig(NULL) {}
        Nodo(const T &elem, Nodo *sig) : _elem(elem), _sig(sig) {}
        T _elem;
        Nodo *_sig;
    };
    Nodo *_cima;
    void libera(Nodo* prim) {
        while (prim != NULL) {
            Nodo *aux = prim;
            prim = prim->_sig;
            delete aux;
        }
    }
    
    void copia(const PilaLE &other) {
        if (other.esVacia()) { _cima = NULL;}
        else {
            Nodo* act = other._cima ;
            Nodo* ant;
            _cima = new Nodo(act->_elem);
            ant = _cima;
            while (act->_sig != NULL) {
                act = act->_sig ;
                ant->_sig = new Nodo(act->_elem );
                ant = ant->_sig ;
            } }
    }
};



#endif