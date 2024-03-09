#ifndef ELECTRIQUE_HPP
#define ELECTRIQUE_HPP

class Electrique {
protected:
    float tension;
    float intensite;

public:
    Electrique(float tension = 220, float intensite = 0);

    virtual float puissance() const = 0;

    void afficher() const;
};

#endif // ELECTRIQUE_HPP