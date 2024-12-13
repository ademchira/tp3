#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

struct Ville {
    string nom;
    double longitude;
    double latitude;
};

void rechercherVilleVector(const vector<Ville>& villes, const string& nom) {
    for (const auto& ville : villes) {
        if (ville.nom == nom) {
            cout << "Ville: " << ville.nom << ", Position: (" << ville.longitude << ", " << ville.latitude << ")" << endl;
            return;
        }
    }
    cout << "Ville non trouvee." << endl;
}

void rechercherVilleMap(const unordered_map<string, pair<double, double>>& villes, const string& nom) {
    auto it = villes.find(nom);
    if (it != villes.end()) {
        cout << "Ville: " << nom << ", Position: (" << it->second.first << ", " << it->second.second << ")" << endl;
    } else {
        cout << "Ville non trouvee." << endl;
    }
}

int main() {

    vector<Ville> villesVector = {
        {"Tunis", 10.1815, 36.8065},
        {"Sfax", 10.7603, 34.7406},
        {"Sousse", 10.6250, 35.8256},
        {"Kairouan", 10.1000, 35.6781},
        {"Gabes", 10.1167, 33.8833}
    };

    cout << "Recherche dans vector:" << endl;
    rechercherVilleVector(villesVector, "Sfax");
    rechercherVilleVector(villesVector, "Djerba");


    unordered_map<string, pair<double, double>> villesMap = {
        {"Tunis", {10.1815, 36.8065}},
        {"Sfax", {10.7603, 34.7406}},
        {"Sousse", {10.6250, 35.8256}},
        {"Kairouan", {10.1000, 35.6781}},
        {"Gabes", {10.1167, 33.8833}}
    };

    cout << "\nRecherche dans unordered_map:" << endl;
    rechercherVilleMap(villesMap, "Sfax");
    rechercherVilleMap(villesMap, "Djerba");

    return 0;
}
