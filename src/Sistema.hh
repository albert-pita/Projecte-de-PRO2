/** @file Sistema.hh
    @brief Especificacio de la classe Sistema
 */

#ifndef _SISTEMA_HH_
#define _SISTEMA_HH_

#ifndef NO_DIAGRAM
#include <iostream>
#include <string>
#include <map>
using namespace std;
#endif

/*
 * Classe Sistema
 */

/** @class Sistema
    @brief Representa el sistema que controla els productes que hi ha dins del magatzem.

     Controla els productes que hi han dins l'almacen. Es pot consultar si hi ha algun producte, es pot afegir un, se'n pot eliminar i també es pot posar o treure una certa quantitat. Es pot fer també un inventari dels productes que hi han al almacen.
 */

class Sistema {

public:
    
    //Creadores
    
    /** @brief Creadora per defecte.
     * \pre <em>cert</em>
     * \post Crea un sistema buit
     */
    Sistema();
    
    
    //Destructores
    
    /** @brief Destructora per defecte.
     * \pre Existeix un sistema
     * \post Destrueix el sistema
     */
    ~Sistema();
    
    
    //Modificadores
    
    /** @brief Modificadora que afegeix una certa quantitat d'unitats d'un producte dins del sistema general del magatzem.
     * \pre Es passa per parametre l'identificador d'un producte i una certa quantitat
     * \post S'ha afegit la quantitat desitjada del <em>idprod</em> dins del sistema general del magatzem
     */
    void afegir_items(string& idprod, int quantitat);
    
    /** @brief Modificadora que treu una certa quantitat d'unitats d'un producte del sistema general del magatzem.
     * \pre Es passa per parametre l'identificador d'un producte i una certa quantitat
     * \post S'ha eliminat la quantitat desitjada de <em>idprod</em> del sistema general del magatzem
     */
    void treure_items(string& idprod, int quantitat);
    
    /** @brief Modificadora que afegeix un producte no existent dintre del sistema amb zero unitats, donant error si ja existeix.
     * \pre Es passa per paràmetre l'identificador del producte
     * \post S'introdueix a sistema el producte sense cap unitat si no existeix, si prèviament està dona error
     */
    void poner_prod(string& idprod);
    
    /** @brief Modificadora que dona de baixa un producte del sistema si aquest existeix i no queden unitats. Si no existeix o li queden unitats, dona error.
     * \pre Es passa per paràmetre l'identificador del producte
     * \post Es dona de baixa el producte amb l'identificador proporcionat, si aquest no existeix o li queden unitats, saltara un error
     */
    void quitar_prod(string& idprod);
    

    //Consultores
    
    /** @brief Consulta les unitats d'un cert producte.
     * \pre Es passa per paràmetre l'identificador del producte
     * \post Si el producte existeix al parametre implicit, escriure les seves unitats, si no, dona error
     */
    void consultar_prod(string& idprod);
    
    /** @brief Per a cada producte s'escriu el seu identificador i la quantitat total que hi ha al magatzem d'ell.
     * \pre <em>cert</em>
     * \post S'escriu cada producte amb el seu identificador i la quantitat total que hi ha al magatzem d'ell, ordenat per idprod. Si esta buit, no escriure res
     */
    void inventario();
    
    /** @brief Retorna un boolea que diu si el producte esta al sistema general del magatzem.
     * \pre <em>cert</em>
     * \post Retorna true si el producte amb <em>idprod</em> esta al sistema general o false si no hi esta
     */
    bool esta_prod(string& idprod);
    
private:
    /** @brief Sistema general d'un magatzem */
    map<string,int> S;
};

#endif

   
