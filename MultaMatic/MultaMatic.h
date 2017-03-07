#include <iostream>
#include "Lista.h"
#include "Tabla.h"
using namespace std;

class ECamaraRepetida{};
class ETramoRepetido{};
class ECamaraInexistente{};
class ETramoInexistente{};

class MultaMatic {
public:
	MultaMatic() {
		this->_multasPorTramo = Tabla<string /*tramo*/, Lista<string /*matricula*/>>();
		this->_multasPorMatricula = Tabla<string /*matricula*/, int /*numMultas*/>();
		this->_cochesEnTamos = Tabla<string /*matricula*/, CyTIni>();
		this->_datosTramos = Tabla<string /*camFin*/, InfoTramo>();
	}

	void insertaTramo(string tramo, string camIni, string camFin, int tMin) {
		if (_multasPorTramo.esta(tramo))
			throw ETramoRepetido();
		else {
			_multasPorTramo.inserta(tramo, Lista<string>());
			InfoTramo info;
			info.camIni = camIni;
			info.tramo = tramo;
			info.tMin = tMin;
			_datosTramos.inserta(camFin, info);
		}
	}

	void fotoEntrada(string camIni, string mat, int tIni) {
		CyTIni cyt;
		cyt.camIni = camIni;
		cyt.tIni = tIni;
		_cochesEnTamos.inserta(mat, cyt);
	}

	void fotoSalida(string camFin, string mat, int tFin){
		if (!_cochesEnTamos.esta(mat) || !_datosTramos.esta(camFin)) //Si el coche no habia entrado en ningun tramo o la camara no esta registrada
			throw ECamaraInexistente();
		else {
			CyTIni cyt = _cochesEnTamos.consulta(mat);
			_cochesEnTamos.borra(mat);
			InfoTramo info = _datosTramos.consulta(camFin);
			
			if (info.camIni != cyt.camIni) //La camara de inicio no es la que debería ser
				throw ECamaraInexistente();
			else if (tFin - cyt.tIni < info.tMin) { //Ha tardado menos del tiempo mínimo: multar
				if (_multasPorMatricula.esta(mat)) {
					int nMultas = _multasPorMatricula.consulta(mat);
					_multasPorMatricula.inserta(mat, nMultas +1);
				}
				else
					_multasPorMatricula.inserta(mat, 1);

				Lista<string> listMat = _multasPorTramo.consulta(info.tramo);
				listMat.Cons(mat);
				_multasPorTramo.inserta(info.tramo, listMat);
			}
		}
	}

	int multasPorMatricula(string mat) {
		if (_multasPorMatricula.esta(mat))
			return _multasPorMatricula.consulta(mat);
		else
			return 0;
	}

	const Lista<string>& multasPorTramos (string tramo) {
		if (_multasPorTramo.esta(tramo))
			return _multasPorTramo.consulta(tramo);
		else
			throw ETramoInexistente();
	}

private:

	struct CyTIni{
		string camIni;
		int tIni;
	};

	struct InfoTramo{
		string camIni;
		string tramo;
		int tMin;
	};

	Tabla<string /*tramo*/, Lista<string /*matricula*/>> _multasPorTramo;
	Tabla<string /*matricula*/, int /*numMultas*/> _multasPorMatricula;
	Tabla<string /*matricula*/, CyTIni> _cochesEnTamos;
	Tabla<string /*camFin*/, InfoTramo> _datosTramos;
};