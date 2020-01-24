/**
 * @mainpage TreeKEA, simulacio d'un nou model de magatzem.

Una cadena de tendes de mobles vol cambiar els seus metodes d'emmagatzematge provant noves distribucions als seus magatzems. I ens han encarregat que implementem una simulacio del nou tipus de magatzem per poder estudiar si adapten o no aquest nou diseny en futures tendes.

En aquest programa s'introdueixen les classes <em>Magatzem</em>, <em>Estanteria</em> i <em>Sistema</em>.

Fet per Albert Pita Argemi.
*/

/** @file main.cc
    @brief Programa principal de la simulacio del nou model de magatzem TreeKEA.
*/

#include "Magatzem.hh"

#ifndef NO_DIAGRAM
#include "BinTree.hh"
#include <string>
#include <iostream>
#endif
using namespace std;

/** @brief Programa principal de la simulacio del nou model de magatzem TreeKEA per a la cadena de tendes de mobles.
 */

int main() {
    Magatzem Mag;
    int num_sales;
    cin >> num_sales;
    Mag.llegir(num_sales);
    string instruccio;
    cin >> instruccio;
    while(instruccio != "fin"){
            if(instruccio == "consultar_pos"){
                    int idsala, f, c;
                    cin >> idsala >> f >> c;
                    cout << instruccio << " " << idsala << " " << f << " " << c << endl;
                    Mag.consultar_pos(idsala,f,c);
            }
            else if(instruccio == "consultar_prod"){
                    string idprod;
                    cin >> idprod;
                    cout << instruccio << " " << idprod << endl;
                    Mag.consultar_prod_en_el_s_del_mag(idprod);
            }
            else if(instruccio == "inventario"){
                    cout << instruccio << endl;
                    Mag.inventario_del_mag();
            }
            else if(instruccio == "escribir"){
                    int idsala;
                    cin >> idsala;
                    cout << instruccio << " " << idsala << endl;
                    Mag.escribir(idsala);
            }
            else if(instruccio == "poner_prod"){
                    string idprod;
                    cin >> idprod;
                    cout << instruccio << " " << idprod << endl;
                    Mag.poner_prod_en_el_s_del_mag(idprod);
            }
            else if(instruccio == "quitar_prod"){
                    string idprod;
                    cin >> idprod;
                    cout << instruccio << " " << idprod << endl;
                    Mag.quitar_prod_del_s_del_mag(idprod);
            }
            else if(instruccio == "poner_items"){
                    int idsala, quant;
                    string idprod;
                    cin >> idsala >> idprod >> quant;
                    cout << instruccio << " " << idsala << " " << idprod << " " << quant << endl;
                    if (Mag.esta_prod_al_mag(idprod)) {
                        Mag.poner_items(idsala, idprod, quant);
                    }
                    else cout << "  error" << endl;
            }
            else if(instruccio == "quitar_items"){
                    int idsala, quant;
                    string idprod;
                    cin >> idsala >> idprod >> quant;
                    cout << instruccio << " " << idsala << " " << idprod << " " << quant << endl;
                    if (Mag.esta_prod_al_mag(idprod)) Mag.quitar_items(idsala, idprod, quant);
                    else cout << "  error" << endl;
            }
            else if(instruccio == "distribuir"){
                    int quant;
                    string idprod;
                    cin >> idprod >> quant;
                    cout << instruccio << " " << idprod << " " << quant << endl;
                    if (Mag.esta_prod_al_mag(idprod)) Mag.distribuir(idprod,quant);
                    else cout << "  error" << endl;
            }
            else if(instruccio == "compactar"){
                    int idsala;
                    cin >> idsala;
                    cout << instruccio << " " << idsala << endl;
                    Mag.compactar(idsala);
            }
            else if(instruccio == "reorganizar"){
                    int idsala;
                    cin >> idsala;
                    cout << instruccio << " " << idsala << endl;
                    Mag.reorganizar(idsala);
            }
            else if(instruccio == "redimensionar"){
                    int idsala, f, c;
                    cin >> idsala >> f >> c;
                    cout << instruccio << " " << idsala << " " << f << " " << c << endl;
                    Mag.redimensionar(idsala,f,c);
            }
            cin >> instruccio;	
    }
    cout << "fin" << endl;
}
	