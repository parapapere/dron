#ifndef SCENA_HH
#define SCENA_HH

#include <iostream>
#include <iomanip>
#include <cmath>
#include "lacze_do_gnuplota.hh"
#include "Wektor3D.hh"
#include "powierzchnia.hh"
#include "powierzchnia3d.hh"
#include "bryla.hh"
#include "dron.hh"

using namespace std;

class Scena {

    Powierzhnia PowWody;
    Powierzhnia PowDna;
    Dron dron;

public:

  void WczytajDrona(){
     ifstream in;
    in.open("bryly/prostopadloscian3.dat");

    while (!in.eof()){
      in >> dron;
    }
    in.close();
  }


  void MakeScena(string NazwaPliku){

    ofstream out;
    
      out.open(NazwaPliku, ios::out);
      out.close();


      out.open(NazwaPliku);
      out << dron;
      out.close();
    PowDna.MakePowierszchniaDna(NazwaPliku);
    PowWody.MakePowierszchniaWody(NazwaPliku);
    }
  

  void Zmiana(double a, double b){
    
    dron.ObliczWspolrzedne(a, b);
  }


};

#endif