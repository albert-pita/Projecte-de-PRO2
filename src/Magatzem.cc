#include "Magatzem.hh"

Magatzem::Magatzem() {
    BinTree<int> T;
}

Magatzem::~Magatzem(){}

void Magatzem::poner_items(int& idsala, string& idprod, int& quantitat) {
    int aux = quantitat;
    int ret = V[idsala-1].afegir_producte(idprod,quantitat);
    cout << "  " << ret << endl;
    S.afegir_items(idprod,aux-ret);
}

void Magatzem::quitar_items(int& idsala, string& idprod, int& quantitat) {
    int aux = quantitat;
    int ret = V[idsala-1].eliminar_productes(idprod,quantitat);
    cout << "  " << ret << endl;
    S.treure_items(idprod,aux-ret);
}

int Magatzem::distribuir_immer(BinTree<int>& T, string& idprod, int quantitat) {
    if (T.empty() or quantitat == 0) {
        return quantitat;
    }
    else {
        int node = T.value(), sl,sr;
        BinTree<int> l = T.left();
        BinTree<int> r = T.right();
        quantitat = V[node-1].afegir_producte(idprod,quantitat);
        sl = distribuir_immer(l,idprod,((quantitat+1)/2));
        sr = distribuir_immer(r,idprod,(quantitat/2));
        return sl + sr;
    }
}

void Magatzem::distribuir(string& idprod, int quantitat) {
    int aux = quantitat;
    int ret = distribuir_immer(T,idprod,quantitat);
    cout << "  " << ret << endl;
    S.afegir_items(idprod,aux-ret);
}

void Magatzem::quitar_prod_del_s_del_mag(string& idprod) {
    S.quitar_prod(idprod);
}

void Magatzem::poner_prod_en_el_s_del_mag(string& idprod) {
    S.poner_prod(idprod);
}

void Magatzem::compactar(int& idsala) {
    if(V[idsala-1].no_buida()) V[idsala-1].compactar_estanteria();
}

void Magatzem::reorganizar(int& idsala) {
    if(V[idsala-1].no_buida()) V[idsala-1].reorganitzar_estanteria();
}

void Magatzem::redimensionar(int& idsala, int& i, int& j) {
    V[idsala-1].Estanteria_redimensionada(i,j);
}

void llegir_arbre(BinTree<int>& T,int& nombre_sales) {
    int n;
    cin >> n;
    if (n != 0 and n <= nombre_sales) {
        BinTree<int> left;
        BinTree<int> right;
        llegir_arbre(left,nombre_sales);
        llegir_arbre(right,nombre_sales);
        T = BinTree<int>(n,left,right);
    }
}

vector<Estanteria> llegir_vector(int& nombre_sales) {
    int i, j, k = 0;
    vector<Estanteria> V (nombre_sales);
    while (k < nombre_sales) {
        cin >> i >> j;
        V[k] = Estanteria(i,j);
        ++k;
    }
    return V;
}
        
void Magatzem::llegir(int& nombre_sales) {
    llegir_arbre(T,nombre_sales);
    V = llegir_vector(nombre_sales);
}

void Magatzem::consultar_pos(int& idsala, int& fila, int& columna) {
    string s = V[idsala-1].consultar_pos_estanteria(fila,columna);
    if (s == "") cout << "  NULL" << endl;
    else cout << "  " << s << endl;
}

void Magatzem::inventario_del_mag() {
    S.inventario();
}

void Magatzem::consultar_prod_en_el_s_del_mag(string& idprod) {
    S.consultar_prod(idprod);
}

bool Magatzem::esta_prod_al_mag(string& idprod) {
    return S.esta_prod(idprod);
}

void Magatzem::escribir(int& idsala) {
    V[idsala-1].escriure_estanteria();
}
