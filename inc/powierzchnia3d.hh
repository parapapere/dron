#ifndef POW3D_HH
#define POW3D_HH

#include <iostream>
#include <iomanip>
#include "lacze_do_gnuplota.hh"
#include "Wektor3D.hh"
#include "lamana.hh"
#include "powierzchnia.hh"

using namespace std;

class Powierzhnia3D : public Powierzhnia {

protected:

    double kat = 3.14;
    Wektor3D <double, 3> translacja;
    
    
public:

    virtual void ObliczWspolrzedne(double, double);

    friend istream& operator >> (istream& Strm, Powierzhnia3D& pow);
    friend ostream& operator << (ostream& Strm, Powierzhnia3D& pow);
    
};


inline ostream& operator << (ostream& Strm, Powierzhnia3D& pow){
    
    for (auto n : pow.powierzhnia){
        Strm << n << "\n\n#\n\n";
    }
    
    return Strm;
}

inline istream& operator >> (istream& Strm, Powierzhnia3D& pow){
    
     Lamana lamana;
    char h;
    while(!Strm.eof()){
        Strm >> lamana;
        
        if(Strm.fail() && (!Strm.eof())){
        Strm.unget();
        Strm.clear();
        Strm >> h;
            if ((h == '#') && (!Strm.eof())){
                pow.SetLamana(lamana);
                lamana.clear();
            }
            else{
                return Strm;
            }
        }
    }
    return Strm;
}





#endif