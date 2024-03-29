#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <filesystem>

namespace fs = std::filesystem;

// Fonction pour diviser une chaîne en tokens en utilisant un délimiteur
std::vector<std::string> split(const std::string& s, char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

int main() {
    std::string dataDir = "./data/";

    // Ensemble des caractéristiques distinctes
    std::unordered_set<std::string> distinctFeatures;

    // Map pour stocker les vecteurs d'incorporation (embedding vectors) pour chaque application
    std::unordered_map<std::string, std::vector<int>> embeddingVectors;

    // Parcourir tous les fichiers dans le répertoire data
    for (const auto& entry : fs::directory_iterator(dataDir)) {
        std::ifstream inputFile(entry.path());
        if (!inputFile.is_open()) {
            std::cerr << "Erreur : Impossible d'ouvrir le fichier " << entry.path() << std::endl;
            continue;
        }

        // Lecture des caractéristiques des applications
        std::string line;
        while (std::getline(inputFile, line)) {
            // Diviser la ligne en tokens
            std::vector<std::string> tokens = split(line, ',');

            // Premier élément est le nom de l'application
            std::string appName = tokens[0];

            // Initialisation du vecteur d'incorporation pour cette application
            std::vector<int> embeddingVector(distinctFeatures.size(), 0);

            // Parcourir les caractéristiques de l'application
            for (size_t i = 1; i < tokens.size(); ++i) {
                std::string feature = tokens[i];
                // Ajouter cette caractéristique à l'ensemble des caractéristiques distinctes
                distinctFeatures.insert(feature);
                // Marquer la présence de cette caractéristique dans le vecteur d'incorporation
                embeddingVector[std::distance(distinctFeatures.begin(), distinctFeatures.find(feature))] = 1;
            }

            // Stocker le vecteur d'incorporation pour cette application
            embeddingVectors[appName] = embeddingVector;
        }

        inputFile.close();
    }

    // Affichage des vecteurs d'incorporation pour chaque application
    for (const auto& pair : embeddingVectors) {
        std::cout << "Application: " << pair.first << " - Vecteur d'incorporation: ";
        for (int value : pair.second) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
