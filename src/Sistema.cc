/** @file Sistema.cc
 * @brief Codi de la classe Sistema.cc
 */

#include "Sistema.hh"

Sistema::Sistema() {
    map<string,int> S;
}

Sistema::~Sistema(){}

bool Sistema::esta_prod(string& idprod) {
    if (S.empty()) return false;
    else {
        map<string,int>::iterator i = S.find(idprod);
        if (i != S.end()) return true;
        else return false;
    }
}

void Sistema::afegir_items(string& idprod, int quantitat) {
    map<string,int>::iterator it = S.find(idprod);
    it->second += quantitat;
}

void Sistema::treure_items(string& idprod, int quantitat) {
    map<string,int>::iterator it = S.find(idprod);
    it->second -= quantitat;
}

void Sistema::consultar_prod(string& idprod) {
    if (S.empty()) cout << "  error" << endl;
    else {
        map<string,int>::iterator i = S.find(idprod);
        if (i != S.end()) cout << "  " << i->second << endl;
        else cout << "  error" << endl;
    }
}

void Sistema::inventario() {
    for(map<string,int>::const_iterator i = S.begin(); i != S.end(); ++i) {
        cout << "  " << i->first << " " << i->second << endl;
    }
}

void Sistema::poner_prod(string& idprod) {
    if (S.empty()) {
        pair<string,int> x;
        x.first = idprod;
        x.second = 0;
        S.insert(x);
    }
    else {
        bool found = false;
        for(map<string,int>::const_iterator i = S.begin(); i != S.end() and not found; ++i) {
            if (i->first == idprod) found = true;
        }
        if (not found) {
            pair<string,int> x;
            x.first = idprod;
            x.second = 0;
            S.insert(x);
        }
        else cout << "  error" << endl;
    }   
}

void Sistema::quitar_prod(string& idprod) {
    if (S.empty()) cout << "  error" << endl;
    else {
        bool found = false;
        map<string,int>::iterator aux;
        for(map<string,int>::iterator i = S.begin(); i != S.end() and not found; ++i) {
            if (i->first == idprod) {
                found = true;
                aux = i;
            }
        }
        if(not found) cout << "  error" << endl;
        else {
            if (aux->second != 0) cout << "  error" << endl;
            else S.erase(idprod);
        }
    }
}


