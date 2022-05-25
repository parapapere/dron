#include <iostream>
#include <iomanip>

#include "lacze_do_gnuplota.hh"
#include "Wektor3D.hh"
#include "lamana.hh"
#include "powierzchnia.hh"
#include "powierzchnia3d.hh"
#include "matrix.hh"


void Powierzhnia3D :: ObliczWspolrzedne(double kat, double t){

    Matrix MacierzObrotu;
    MacierzObrotu.GetMatrix(kat);
    Wektor3D <double, 3> translacja;
    translacja={t, t, t};

    int a = powierzhnia.size();
    for (int lamana = 0; lamana < a; lamana ++){
        int b = powierzhnia[lamana].Size();
        for (int prosta = 0; prosta < b; prosta ++){
            powierzhnia[lamana].points[prosta]=  MacierzObrotu*powierzhnia[lamana].points[prosta] + translacja;  
        }
    }
}


