#include "Estanteria.hh"

Estanteria::Estanteria() {
    Est = (vector<string>(0));
    files = 0;
    columnes = 0;
}

Estanteria::Estanteria(int i, int j) {
    Est = (vector<string> (i*j));
    files = i;
    columnes = j;
}

Estanteria::~Estanteria(){}

int Estanteria::afegir_producte(string& idprod, int quantitat) {
    int aux = quantitat;
    bool ha_afegit = false;
    for (int i = 0; i < Est.size() and quantitat > 0; ++i) {
        if (Est[i] == "") {
            Est[i] = idprod;
            --quantitat;
            ha_afegit = true;
        }
    }
    if (ha_afegit) {
        map<string,int>::iterator it = inv_sala.find(idprod);
        if (it != inv_sala.end()) it->second += (aux-quantitat);
        else {
            pair<string,int> x;
            x.first = idprod;
            x.second = (aux-quantitat);
            inv_sala.insert(x);
        }
    }
    return quantitat;
}

int Estanteria::eliminar_productes(string& idprod,int quantitat) {
    int aux = quantitat;
    bool ha_borrat = false;
    for (int i = 0; i < Est.size() and quantitat > 0; ++i) {
        if (Est[i] == idprod) {
            Est[i] = "";
            --quantitat;
            ha_borrat = true;
        }
    }
    if (ha_borrat) {
        map<string,int>::iterator it = inv_sala.find(idprod);
        it->second -= (aux-quantitat);
        if (it->second == 0) inv_sala.erase(idprod);
    }
    return quantitat;
}

void Estanteria::compactar_estanteria() {
    int poscanvi = 0;
    bool canvi = false;
    for (int i = 0; i < Est.size(); ++i) {
        if (Est[i] == "" and not canvi) {
            canvi = true;
            poscanvi = i;
        }
        else if (Est[i] != "" and canvi){
            swap(Est[poscanvi],Est[i]);
            canvi = false;
            i = poscanvi;
        }
    }
}

bool cmp(string& A, string& B) {
    if (A != "" and B == "") return true;
    else if (A == "" and B != "") return false;
    else if (A < B) return true;
    return false;
}

void Estanteria::reorganitzar_estanteria() {
    sort(Est.begin(),Est.end(),cmp);
}

void Estanteria::Estanteria_redimensionada(int i,int j) {
    int suma = 0;
    if (no_buida()) for (map<string,int>::iterator it = inv_sala.begin(); it != inv_sala.end();++it) suma += it->second;
    if ((i*j) >= suma) {
        int new_size = i*j;
        compactar_estanteria();
        Est.resize(new_size);
        files = i;
        columnes = j;
    }
    else {
        cout << "  error" << endl;
    }
}

bool Estanteria::no_buida() {
    if(not inv_sala.empty()) return true;
    else return false;
}

string Estanteria::consultar_pos_estanteria(int i, int j) {
    int pos =((j-1)-(columnes-1))+((Est.size()-1)-(columnes*(i-1)));
    return Est[pos];
}

void Estanteria::escriure_estanteria() const {
    int x = files*columnes - columnes, col = 0, fil = 0;
    while (x >= 0 and fil <= files) {
        if (col == 0) {
            if (Est[x] == "") cout << "  " << "NULL";
            else cout << "  " << Est[x];
        }
        else {
            if (Est[x] == "") cout << " " << "NULL";
            else cout << " " << Est[x];
        }
        ++x;
        ++col;
        if (col == columnes) {
            x = x -(2*columnes);
            col = 0;
            ++fil;
            cout << endl;
        }
    }
    
    int suma = 0;
    bool fa_algo = false;
    for (map<string,int>::const_iterator it = inv_sala.begin(); it != inv_sala.end(); ++it) {
        suma += it->second;
        fa_algo = true;
    }
    if (not fa_algo) cout << "  " << suma << endl;
    else {
        cout << "  " << suma << endl;
        for (map<string,int>::const_iterator it = inv_sala.begin(); it != inv_sala.end(); ++it) {
            if (it == inv_sala.begin()) cout << "  " << it->first << " " << it->second;
            else {
                cout << endl;
                cout << "  " << it->first << " " << it->second;
            }
        }
        cout << endl;
    }
}
