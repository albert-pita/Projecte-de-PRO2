/** @file Magatzem.hh
 * @brief Especificacio de la classe Magatzem
 */

#ifndef _MAGATZEM_HH_
#define _MAGATZEM_HH_

#include "Estanteria.hh"
#include "Sistema.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#include <vector>
#include "BinTree.hh"
using namespace std;
#endif

/*
 * Classe Magatzem
 */

/** @class Magatzem
 * @brief Representa un magatzem.
 * 
 * Propiament un magatzem està compost de sales, les quals a dins tenen una estanteria que alhora emmagatzema productes. El magatzem pot tenir diferents tamanys, al parlar de tamany ens referim al nombre de sales que te. Es a partir d'ell que nosaltres accedim a les sales, estanteries o productes.
 */

class Magatzem
{
    
public:
    //Constructores
    
    /** @brief Creadora per defecte.
     * \pre <em>cert</em>
     * \post Crea un magatzem amb cap sala
     */
    Magatzem();
    
    //Destructores
    
    /** @brief Destructora per defecte.
     * \pre Existeix un magatzem
     * \post Destrueix el magatzem
     */
    ~Magatzem();
    
    //Modificadores
     
    /** @brief Modificadora que introdueix una certa quantitat de l'<em>idprod</em> a una sala amb <em>idsala</em>.
     * \pre Preparats al canal d'entrada estandard la idsala, el idprod i la quantitat que es vol afegir
     * \post Es posen a l'estanteria de la <em>idsala</em> la quantitat d'<em>idprod</em> passada, si hi caben menys que la quantitat senyalada, els sobrants es treuen pel canal estandard de sortida
     */
    void poner_items(int& idsala, string& idprod, int& quantitat);
    
    /** @brief Modificadora que treu una certa quantitat d'un <em>idprod</em> d'una certa estanteria amb <em>idsala</em>. Si no existeix el producte treu error.
     * \pre Preparats al canal d'entrada estandard la idsala, el idprod i la quantitat que es vol eliminar
     * \post Es retiren tots els <em>idprod</em> de l'estanteria de la <em>idsala</em>, es retorna un enter amb el nombre de <em>idprod</em> que no han pogut esser eliminats
     */
    void quitar_items(int& idsala, string& idprod, int& quantitat);
    
    /** @brief Funció immersiva de distribuir.
     * \pre <em>cert</em>
     * \post Retorna un enter amb la quantitat de <em>idprod</em> que no ha estat possible distribuir
     */
    int distribuir_immer(BinTree<int>& T, string& idprod, int quantitat);
    
    /** @brief Modificadora que distribueix una certa quantitat de nombre seguint una certa politica a l'hora de fer-ho.
     * 
     * La politica de distribucio consisteix en que, començant des de la sala inicial, s'afegeixen totes les unitats del producte que es pugui a la sala. Despreś el restant, si es parell, es distribueix mitad a la sala de la dreta, mitad a la sala de l'esquerra. Si el restant no es parell, es distribueix, mitad a la dreta, i mitad+1 a l'esquerra.
     * \pre Preparats al canal d'entrada estandard el idprod i la quantitat que es vol distribuir
     * \post Treu per pantalla la quantitat de <em>idprod</em> que no ha estat possible distribuir
     */
    void distribuir(string& idprod, int quantitat);
    
    /** @brief Modificadora que treu del inventari general del magatzem un producte.
     * \pre Preparats al canal d'entrada estantard l'identificador del producte que es vol eliminar.
     * \post <em>idprod</em> ha estat eliminat del inventari general del magatzem si previament tenia 0 unitats, si no es dona el cas, salta error
     */
    void quitar_prod_del_s_del_mag(string& idprod);
    
    /** @brief Modificadora que afegeix del inventari general del magatzem un producte.
     * \pre Preparats al canal d'entrada estandard l'identificador del producte que es vol afegir.
     * \post <em>idprod</em> ha estat afegit al inventari general del magatzem amb 0 unitats
     */
    void poner_prod_en_el_s_del_mag(string& idprod);
    
    /** @brief Compacta l'estanteria d'una sala seguint uns criteris concrets.
     * 
     * Els criteris són, els productes es desplaçaran cap a l'esquerra i cap a baix de manera que no quedi cap lloc buit entre dos productes, ni abans de cap tampoc. I no s'ha de canviar l'ordre en que aquests estan.
     * \pre <em>cert</em>
     * \post L'estanteria de la <em>idsala</em> ha estat compactada seguint els criteris ja mencionats
     */
    void compactar(int& idsala);
    
    /** @brief Reorganitza l'estanteria d'una sala seguint uns criteris concrets.
     * 
     * Els criteris són, els productes són ordenats alfabeticament, sense deixar espais buits entre ells ni abans de cap producte.
     * \pre <em>cert</em>
     * \post L'estanteria de la <em>idsala</em> ha estat reorganitzada seguint els criteris ja mecionats
     */
    void reorganizar(int& idsala);
    
    /** @brief Redimensiona l'estanteria a una amb un tamany ixj on i >= 1 i j >= 1. L'estanteria no sera redimensionada si la quantitat d'objectes de l'estanteria original es superior al tamany de la nova estanteria que es vol redimensionar, si fos el cas donaria error.
     * \pre i>= 1 i j>=1
     * \post La sala amb identidificador <em>idsala</em> te ara tamany ixj, en el cas que la quantitat d'objectes de l'estanteria original no sigui superior o igual al tamany de la nova estanteria que es vol redimensionar, sino donara error
     */
    void redimensionar(int& idsala, int& i, int& j);
    
    /** @brief Llegeix el nombre_sales i "omple" el magatzem amb les seves respectives sales que tenen el seu respectiu identificador.
     * \pre El parametre implict es buit. Maxim de sales que es poden crear = numero_sales. Pel canal estandard d'entrada hi han enters, on un 0 representa que no hi ha sala en aquella branca del magatzem
     * \post El parametre implicit conté totes les sales del magatzem amb els seus respectius identificadors
     */
    void llegir(int& nombre_sales);

    //Consultores
    
    /** @brief Consultora de la posició d'un producte a una sala.
     * \pre <em>cert</em>
     * \post Escriu la posició del producte de la sala indicada
     */
    void consultar_pos(int& idsala, int& fila, int& columna);
    
    /** @brief Consultora que retorna l'inventari general del magatzem.
     * \pre <em>cert</em>
     * \post S'escriu cada producte amb el seu identificador i la quantitat total que hi ha al magatzem d'ell, ordenat per idprod. Si esta buit, no escriure res
     */
    void inventario_del_mag();
    
    /** @brief Consultora que retorna les unitats totals d'un cert producte al magatzem.
     * \pre <em>cert</em>
     * \post S'escriu les unitats totals dins el magatzem del producte amb identificador <em>idprod</em>
     */
    void consultar_prod_en_el_s_del_mag(string& idprod);
    
    /** @brief Consultora que retorna un boolea indicant si un cert producte esta al magatzem o no.
     * \pre Preparats al canal d'entrada estandard l'identificador del producte que es vol veure si esta o no
     * \post Retorna cert si el producte esta al magatzem o false si no
     */
    bool esta_prod_al_mag(string& idprod);
    
    /** @brief Escriu el contingut de l'estanteria de la sala, de dalt a baix i d'esquerra a dreta, també les unitats que hi han en total a l'estanteria i per ordre d'identificador, s'aniran escribint tots els idprod i quantes unitats hi han d'aquest.
     * \pre Existeix una sala amb <em>idsala</em>
     * \post Se escriu l'estanteria de la sala, de dalt a baix i d'esquerra a dreta, les unitats en total a l'estanteria, i per ordre d'identificador, es treuen tots els productes amb les seves respectives unitats
     */
    void escribir(int& idsala);

private:
    /** @brief Estructura del magatzem */
    BinTree<int> T;
    /** @brief Vector amb totes les sales del magatzem */
    vector<Estanteria> V;
    /** @brief Sistema general del magatzem */
    Sistema S;
};

#endif
    
