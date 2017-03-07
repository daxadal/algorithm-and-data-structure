#include "MultaMatic.h"
typedef string Matricula;

int main() {
	MultaMatic m;
	try {
        m.insertaTramo("AP6GuadarramaII", "AP6GuadarramaIIIni", "AP6GuadarramaIIFin",118);
        m.insertaTramo("AP6GuadarramaIII", "AP6GuadarramaIIIIni", "AP6GuadarramaIIIFin",288);
        m.insertaTramo("AP9Sartego","AP9SartegoIni","AP9SartegoFin",49);
        m.insertaTramo("A4Despenaperros","A4DespenaperrosIni","A4DespenaperrosFin",125);
        m.insertaTramo("Zaragoza","ZaragozaIni","ZaragozaFin",90);
        m.insertaTramo("A7Torrox","A7TorroxIni","A7TorroxFin",52);
        m.fotoEntrada("AP6GuadarramaIIIni", "4532DFT",2860);
        m.fotoEntrada("AP9SartegoIni", "9821NNN",2863);
        m.fotoEntrada("AP6GuadarramaIIIni", "0021BBB",2865);
        m.fotoSalida("AP9SartegoFin","9821NNN",2880); // Multado
        m.fotoSalida("AP6GuadarramaIIFin", "4532DFT",2960); // Multado
        m.fotoSalida("AP6GuadarramaIIFin", "0021BBB",2995); // No multado
        m.fotoEntrada("ZaragozaIni", "9821NNN",3856);
        m.fotoSalida("ZaragozaFin", "9821NNN",3956); // No multado
		 m.fotoEntrada("ZaragozaIni", "9821NNN",3856);
        m.fotoSalida("ZaragozaFin", "9821NNN",3856); // Multado
		m.fotoEntrada("ZaragozaIni", "9821AAA",3856);
        m.fotoSalida("ZaragozaFin", "9821AAA",3856); // Multado
        cout << "Multas por matricula \n";
        cout << "4532DFT   " << m.multasPorMatricula("4532DFT") << endl;
        cout << "0021BBB   " << m.multasPorMatricula("0021BBB") << endl;
        cout << "9821NNN   " << m.multasPorMatricula("9821NNN") << endl;
		cout << "9821AAA   " << m.multasPorMatricula("9821AAA") << endl;
        cout << endl << "Multas por tramo \n" ;
        cout << "AP6GuadarramaII\n";
        Lista<Matricula> l = m.multasPorTramos("AP6GuadarramaII");
        Lista<Matricula>::Iterador it = l.principio();
        Lista<Matricula>::Iterador itFinal = l.final();
        while (it != itFinal) {
            cout << it.elem();
            it.avanza();
        }
        cout << endl;
        cout << "AP6GuadarramaIII\n";
        l = m.multasPorTramos("AP6GuadarramaIII");
        it = l.principio();
        itFinal = l.final();
        while (it != itFinal) {
            cout << it.elem();
            it.avanza();
        }
        cout << endl;
        cout << "AP9Sartego\n";
        l = m.multasPorTramos("AP9Sartego");
        it = l.principio();
        itFinal = l.final();
        while (it != itFinal) {
            cout << it.elem();
            it.avanza();
        }
        cout << endl;
        cout << "Zaragoza\n";
        l = m.multasPorTramos("Zaragoza");
        it = l.principio();
        itFinal = l.final();
        while (it != itFinal) {
            cout << it.elem();
            it.avanza();
        }
        cout << endl;
        cout << "A7Torrox\n";
        l = m.multasPorTramos("A7Torrox");
        it = l.principio();
        itFinal = l.final();
        while (it != itFinal) {
            cout << it.elem();
            it.avanza();
        }
	}
	catch (ECamaraRepetida& e){ cout << "Camara repetida \n";}
	catch (ETramoRepetido& e) {cout << "Tramo repetido \n";}
	catch (ECamaraInexistente& e) {cout << "Camara inexistente \n";}
	catch (ETramoInexistente& e) {cout << "Tramo inexistente \n";}
    
}
