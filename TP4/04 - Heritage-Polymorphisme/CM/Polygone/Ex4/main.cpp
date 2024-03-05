using namespace std;

#include <iostream>
#include "Polygon.hpp"

//////////////////////////////////////////////////////////////////////////
// Programme : main.cpp                                                 //
// Acces     : Public                                                   //
// But       : Utilisation de la classe Etudiant                        //
//                                                                      //
// Arguments                                                            //
// - IN      : neant                                                    //
// - IN/OUT  : neant                                                    //
// - OUT     : neant                                                    //
// Retour    : EXIT_SUCCESS Execution OK                                //
//             EXIT_FAILURE Execution KO                                //
//                                                                      //
// Historique                       Date        Version  par            //
// Ajout main.cpp                   20/02/2024  1.0.00   Alain BERTAILS //
//////////////////////////////////////////////////////////////////////////

int main()
{
  Rectangle rect(5, 3);
  std::cout << 'Aire du rectangle : ' << rect.GetArea() << std::endl;

  Triangle tri(4, 6);
  std::cout << 'Aire du triangle : ' << tri.getArea() << std::endl;

  return EXIT_SUCCESS;
}
