/** @file Estanteria.hh
 * @brief Especificacio de la classe Estanteria
 */

#ifndef _ESTANTERIA_HH_
#define _ESTANTERIA_HH_


#ifndef NO_DIAGRAM
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
#endif

/*
 * Classe Estanteria
 */

/** @class Estanteria
 * @brief Representa l'estanteria que hi ha a cada sala.
 * 
 * Te un tamany ixj. Pot contindre en cada una de les seves caselles o un producte o res (representat amb la paraula NULL). S'utilitza per emmagatzemar productes. Es poden afegir productes o eliminar-los. Es pot reordenar de dues formes diferents, compactant l'estanteria o reorganitzant-la. També es possible redimensionar l'estanteria donant un nou tamany si aquest compleix certes condicions. També es pot consultar que hi ha en una posicio especifica d'ella.
 */

class Estanteria{
    
public:
    //Constructores
    
    /** @brief Creadora per defecte.
     * 
     * Se executa automaticament al declarar una estanteria.
     * \pre <em>cert</em>
     * \post Crea una estanteria de 0x0 buida
     */
    Estanteria();
    
    /** @brief Constructora que crea una estanteria de mida ixj.
     * 
     * Permet declarar una estanteria nova de <em>i</em> files i <em>j</em> columnes.
     * \pre i >= 1 i j >= 1
     * \post Crea una estanteria de i files amb j columnes plena de productes nuls
     */
    Estanteria(int i, int j);
    
    //Destructores
    
    /** @brief Destructora per defecte. Esborra automàticament els objectes locals en sortir d'un àmbit de visibilitat.
     * \pre Existeix una estanteria
     * \post Destrueix la estanteria
     */
    ~Estanteria();
    
    //Modificadores
    
    /** @brief Coloca una certa quantitat d'un mateix producte dins del parametre implicit(una estanteria).
     * \pre Al canal estandard d'entrada hi ha preparades l'identificador d'un producte i una certa quantitat
     * \post S'afegeixen totes les unitats(= quantitat) que entrin dins el parametre implicit i es retorna la quantitat que no s'ha pogut afegir
     */
    int afegir_producte(string& idprod, int quantitat);
    
    /** @brief Elimina una certa quantitat d'un mateix producte dins del parametre implicit(una estanteria).
     * \pre Al canal estandard d'entrada hi ha preparades l'identificador d'un producte i una certa quantitat
     * \post S'eliminen totes les unitats(= quantitat) del parametre implicit amb identificador = <em>idprod</em> i es retorna la quantitat que no s'ha pogut eliminar
     */
    int eliminar_productes(string& idprod,int quantitat);
    
    /** @brief Es realitza la compactacio del parametre implicit.
     * \pre <em>cert</em>
     * \post Els productes queden compactats cap a l'esquerra i cap a baix de manera que no quedi cap forat entre dos productes
     */
    void compactar_estanteria();
    
    /** @brief Es realitza la reorganització del parametre implicit.
     * \pre <em>cert</em>
     * \post Els productes queden reorganitzats alfabèticament sense deixar espais ni abans ni entre ells
     */
    void reorganitzar_estanteria();
    
    /** @brief Si totes les unitats dels productes que te el parametre implicit <= ixj, la nova dimensio de l'estanteria sera ixj.
     * \pre Al canal estandard d'entrada hi ha preparades la nova possible dimensio de l'estanteria
     * \post Si totes les unitats dels productes que te el parametre implicit <= ixj, la dimensio del paramentre implicit a partir d'ara sera ixj. Si no hi caben donara error
     */
    void Estanteria_redimensionada(int i, int j);
    
    //Consultores
    
    /** @brief Retorna un boolea que diu si el parametre implicit esta buit o no.
     * \pre <em>cert</em>
     * \post Retorna true si el parametre implicit no esta buit i false si esta buit.
     */
    bool no_buida();
    
    /** @brief Indica quin producte hi ha a la posicio (i,j) del parametre implicit.
     * \pre Passa per parametres la posicio del producte
     * \post Es retornara el que hi hagi a la posicio (i,j) del parametre implicit
     */
    string consultar_pos_estanteria(int i, int j);
    
    /** @brief Escriu per pantalla el parametre implicit.
     * \pre <em>cert</em>
     * \post S'han escrit pel canal estandard de sortida el parametre implicit i els productes que conte (a les posicions on no hi ha res surt "NULL"). S'han escrit també les unitats totals de tots els productes que hi ha a l'estanteria. I també s'ha escrit cada producte, un a un, i les seves unitats dins del parametre implicit
     */
    void escriure_estanteria() const;
    
    
private:
    /** @brief Files de l'estanteria*/
    int files;
    /** @brief Columnes de l'estanteria*/
    int columnes;
    /** @brief Estructura de l'estanteria */
    vector<string> Est;
    /** @brief Inventari de la sala */
    map<string,int> inv_sala;
};

#endif
