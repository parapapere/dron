#ifndef POWIERZHNIA_HH
#define POWIERZHNIA_HH

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "lacze_do_gnuplota.hh"
#include "lamana.hh"
using namespace std;

class Powierzhnia : public Lamana {
    protected:
    
    vector <Lamana> powierzhnia;

    public:

    Lamana operator [] (unsigned int Ind) const { return powierzhnia[Ind]; }
    Lamana &operator [] (unsigned int Ind)       { return powierzhnia[Ind]; }

    vector <Lamana> GetLamana(){
        return powierzhnia;
    }

    void operator = (Powierzhnia now) {
         
         int a = powierzhnia.size();
            for (int i = 0; i < a; i++){
                now[i] = powierzhnia[i];        
     }
    }
    

    virtual void SetLamana (Lamana vec){
        powierzhnia.push_back(vec);
        }

    void MakePowierszchniaDna(string);
    void MakePowierszchniaWody(string);

    friend ostream& operator << (ostream& Strm, Powierzhnia& pow);
    friend ostream& operator >> (ostream& Strm, Powierzhnia& pow);
};

inline istream& operator >> (istream& Strm, Powierzhnia& pow){
    
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

inline ostream& operator << (ostream& Strm, Powierzhnia& pow){
    
    
    for (auto n : pow.powierzhnia){
        int size = 0;
        size++;
        Strm << n << endl;
         if (size%4 == 1)
            Strm << "\n#\n\n";
    }
    
    return Strm;
}



#endif