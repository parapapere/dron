#ifndef DRON_HH
#define DRON_HH

#include <iostream>
#include <iomanip>
#include "lacze_do_gnuplota.hh"
#include "Wektor3D.hh"
#include "powierzchnia.hh"
#include "powierzchnia3d.hh"
#include "bryla.hh"

using namespace std;

class Dron: public Bryla {

    Bryla Obudowa;
    
public:

    Bryla GetObudowa(){
        return Obudowa;
    }

    virtual void ObliczWspolrzedne(double a,  double b) override{
        Obudowa.ObliczWspolrzedne(a, b);
    } ;

    friend istream& operator >> (istream& Strm, Dron& dron);
    friend ostream& operator << (ostream& Strm, Dron& dron);
    
};

inline istream& operator >> (istream& Strm, Dron& dron){

        Strm >> dron.Obudowa;
    
    return Strm;
}

inline ostream& operator << (ostream& Strm, Dron& dron){
    
    Strm << dron.Obudowa;
    
    return Strm;
}







#endif