#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

#include "Ampoule.hpp"
#include "Guirlande.hpp"

using namespace std;

int main() {
    // Write guirlandes to "guirlandes.txt"
    string fichierName = "guirlandes.txt";
    vector<Guirlande> guirlandesToWrite;

    // Create 10 guirlandes
    for (int i = 0; i < 10; ++i) {
        vector<Ampoule> ampoules;
        for (int j = 0; j < 5; ++j) {
            float intensite = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
            ampoules.push_back(Ampoule(intensite));
        }

        float coutCable = static_cast<float>(rand()) / static_cast<float>(RAND_MAX) * 90 + 10;
        Guirlande guirlande(ampoules, coutCable);
        guirlandesToWrite.push_back(guirlande);
    }

    ofstream fichier(fichierName);
    if (fichier.is_open()) {
        for (const Guirlande& guirlande : guirlandesToWrite) {
            fichier << guirlande.getAmpoules().size() << " ";
            for (const Ampoule& ampoule : guirlande.getAmpoules()) {
                fichier << ampoule.getIntensite() << " ";
            }
            fichier << guirlande.getCoutCable() << endl;
        }
        fichier.close();
        cout << "Guirlandes written to: " << fichierName << endl;
    } else {
        cerr << "Error: Could not create file '" << fichierName << "'" << endl;
    }

    vector<Guirlande> guirlandes;

    ifstream fichierLecture(fichierName); // Renamed to avoid conflict
    if (!fichierLecture.is_open()) {
        cerr << "Error: Could not open file '" << fichierName << "'" << endl;
        return 1;
    }

    string line;
    while (std::getline(fichierLecture, line)) {
        vector<Ampoule> ampoules;
        float coutCable;

        stringstream ss(line);
        string data;

        int nbAmpoules;
        if (ss >> nbAmpoules) {
            for (int i = 0; i < nbAmpoules; ++i) {
                if (ss >> data) {
                    float intensite;
                    try {
                        intensite = stof(data);
                        ampoules.push_back(Ampoule(intensite));
                    } catch (const std::invalid_argument& e) {
                        cerr << "Error: Invalid data format in line: " << line << endl;
                        break;
                    }
                } else {
                    cerr << "Error: Invalid data format in line: " << line << endl;
                    break;
                }
            }

            if (ss >> coutCable) {
                Guirlande guirlande(ampoules, coutCable);
                guirlandes.push_back(guirlande);
            } else {
                cerr << "Error: Invalid data format in line: " << line << endl;
            }
        } else {
            cerr << "Error: Invalid data format in line: " << line << endl;
        }
    }

    fichierLecture.close();

    string outputFileName = "guirlandes_data.txt"; // Removed extra space
    ofstream outputFile(outputFileName);
    if (outputFile.is_open()) {
        for (const Guirlande& guirlande : guirlandes) {
            outputFile << "Prix de vente minimum: " << guirlande.getPrixVente() << " euros" << endl;
        }
        outputFile.close();
        cout << "Guirlande data written to: " << outputFileName << endl;
    } else {
        cerr << "Error: Could not create output file '" << outputFileName << "'" << endl;
    }

    return 0;
}
