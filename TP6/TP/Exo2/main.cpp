#include <iostream>
#include <fstream>
#include <filesystem>
#include <set>
#include <vector>
#include <unordered_map>
#include <string>
#include <sstream>

using namespace std;
namespace fs = std::filesystem;

// Déclaration de la fonction split
vector<string> split(const string& str, char delimiter);

int main() {
    // Répertoire contenant les données de caractéristiques de l'application
    const string data_dir = "./data/";

    // Ensemble pour stocker toutes les caractéristiques uniques
    set<string> unique_features;

    // Map pour stocker la correspondance caractéristique -> index
    unordered_map<string, int> feature_index;

    // Vecteur pour stocker tous les vecteurs d'incorporation
    vector<vector<int>> embedding_vectors;

    // Parcourir chaque fichier dans le répertoire de données
    for (const auto& entry : fs::directory_iterator(data_dir)) {
        if (entry.is_regular_file()) {
            string filename = entry.path().string();
            ifstream file(filename);

            if (!file.is_open()) {
                cerr << "Erreur lors de l'ouverture du fichier : " << filename << endl;
                continue;
            }

            // Vecteur d'incorporation de l'application
            vector<int> app_embedding_vector(unique_features.size(), 0);

            string line;
            while (getline(file, line)) {
                // Extraire les caractéristiques de chaque ligne (remplacer par la logique d'analyse réelle)
                vector<string> features = split(line, '::');

                for (const string& feature : features) {
                    // Ajouter la caractéristique unique à l'ensemble et à la map
                    auto [iter, inserted] = unique_features.insert(feature);
                    if (inserted) {
                        feature_index[feature] = distance(unique_features.begin(), iter);
                    }

                    // Mettre à jour le vecteur d'incorporation de l'application
                    if (feature_index.find(feature) != feature_index.end()) {
                        app_embedding_vector[feature_index[feature]] = 1;
                    }
                }
            }

            // Ajouter le vecteur d'incorporation de l'application à la collection
            embedding_vectors.push_back(app_embedding_vector);

            file.close();
        }
    }

    // **Optionnel: Traiter ou afficher les vecteurs d'incorporation**
    // Vous pouvez utiliser la structure de données `embedding_vectors` pour un traitement ultérieur
    // ou le formater dans un format désiré.

    cout << "Nombre de caractéristiques uniques : " << unique_features.size() << endl;
    // ... traitement supplémentaire ou sortie des vecteurs d'incorporation

    return 0;
}

// Fonction pour diviser une chaîne en un vecteur (remplacer par votre implémentation)
vector<string> split(const string& str, char delimiter) {
    vector<string> tokens;
    istringstream stream(str);
    string token;
    while (getline(stream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}
