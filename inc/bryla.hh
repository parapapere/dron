#ifndef BRYLA_HH
#define BRYLA_HH

#include <iostream>
#include <iomanip>
#include "lacze_do_gnuplota.hh"
#include "Wektor3D.hh"
#include "powierzchnia.hh"
#include "powierzchnia3d.hh"

using namespace std;

class Bryla : public Powierzhnia3D {
    
public:


    
    friend istream& operator >> (istream& Strm, Bryla& bryla);
    friend ostream& operator << (ostream& Strm, Bryla& bryla);
    
};


inline istream& operator >> (istream& Strm, Bryla& pow){
    
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



inline ostream& operator << (ostream& Strm, Bryla& bryla){
    
    
    for (auto n : bryla.powierzhnia){ 
        
        Strm << n << "#\n\n";
    }
    
    return Strm;
}

/*inline istream& operator >> (istream& Strm, Bryla& bryla){
    
   Powierzhnia3D powierzchnia;
    
    Strm >> powierzchnia;
    bryla.SetSciana(powierzchnia);
                
    return Strm;
}*/




#endif