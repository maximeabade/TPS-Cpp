#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

#include "Ampoule.hpp"
#include "Guirlande.hpp"

using namespace std;

int main() {
    //ecrivons des guirlandes dans "guirlandes.txt"
    ofstream fichier("guirlandes.txt");
    // Variables for guirlande creation
    string fichierName = "guirlandes.txt"; // File name
    vector<Guirlande> guirlandes; // Vector to store guirlandes

    // Open the file for reading
    ifstream fichier(fichierName);
    if (!fichier.is_open()) {
        cerr << "Error: Could not open file '" << fichierName << "'" << endl;
        return 1; // Exit with error code
    }

    // Read the file line by line
    string line;
    while (getline(fichier, line)) {
        // Process each line to create a Guirlande
        vector<Ampoule> ampoules;
        float coutCable;

        // Extract data from the line using stringstream
        stringstream ss(line);
        string data;

        // Read number of ampoules
        int nbAmpoules;
        if (ss >> nbAmpoules) {
            // Read data for each ampoule
            for (int i = 0; i < nbAmpoules; ++i) {
                if (ss >> data) {
                    // Convert string to float (assuming data represents intensity)
                    float intensite = stof(data);
                    ampoules.push_back(Ampoule(intensite));
                } else {
                    cerr << "Error: Invalid data format in line: " << line << endl;
                    break; // Skip to next line on error
                }
            }

            // Read cable cost
            if (ss >> coutCable) {
                // Create a Guirlande and calculate price
                Guirlande guirlande(ampoules, coutCable);
                guirlandes.push_back(guirlande);
            } else {
                cerr << "Error: Invalid data format in line: " << line << endl;
            }
        } else {
            cerr << "Error: Invalid data format in line: " << line << endl;
        }
    }

    // Close the file
    fichier.close();

    // Write guirlande data to a new file (optional)
    string outputFileName = " guirlandes_data.txt";
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

    return 0; // Exit successfully
}
