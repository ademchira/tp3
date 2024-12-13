#include <iostream>
#include <vector>
#include <string>
using namespace std;


void remplirTableau(int* tableau, int taille) {
    for (int i = 0; i < taille; ++i) {
        cout << "Entrez une valeur pour l'index " << i << ": ";
        cin >> tableau[i];
    }
}


int compterPositifs(const int* tableau, int taille) {
    int compteur = 0;
    for (int i = 0; i < taille; ++i) {
        if (tableau[i] > 0) {
            ++compteur;
        }
    }
    return compteur;
}

void allocationStatique() {
    const int taille = 5;
    int tableau[taille];

    remplirTableau(tableau, taille);

    int positifs = compterPositifs(tableau, taille);
    cout << "Nombre de valeurs positives (allocation statique) : " << positifs << endl;
}


void allocationDynamique() {
    int taille;
    cout << "Entrez la taille du tableau : ";
    cin >> taille;

    int* tableau = new int[taille];

    remplirTableau(tableau, taille);

    int positifs = compterPositifs(tableau, taille);
    cout << "Nombre de valeurs positives (allocation dynamique) : " << positifs << endl;

    delete[] tableau;
}

int main() {
    cout << "=== Allocation statique ===" << endl;
    allocationStatique();

    cout << "\n=== Allocation dynamique ===" << endl;
    allocationDynamique();

    return 0;
}
