#ifndef WEKTOR3D_HH
#define WEKTOR3D_HH

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>
#include "lacze_do_gnuplota.hh"

using namespace std;

/*!

 */
template <typename STyp, int SWymiar>
class Wektor3D {
    
    double  kordynaty[SWymiar];

    public:
    Wektor3D() { for (STyp &Wsp: kordynaty) Wsp = 0; }
  
    STyp  operator [] (unsigned int Ind) const { return kordynaty[Ind]; }
    STyp &operator [] (unsigned int Ind)       { return kordynaty[Ind]; }

   void operator = ( vector<double> wek) {
        
        //Wektor3D<STyp,SWymiar> wynik;

      for (int i = 0; i < SWymiar; i++){
        
        kordynaty[i] = wek[i];
    
      } 
    };

    

  void operator = ( Wektor3D<double, 3> wek) {
        
        //Wektor3D<STyp,SWymiar> wynik;

      for (int i = 0; i < SWymiar; i++){
        
        kordynaty[i] = wek[i];
    
      } 
    };

     Wektor3D<STyp,SWymiar> operator + (double a) {
      
      Wektor3D<STyp,SWymiar> wynik;
      
      wynik[0]=kordynaty[0]+a;
      wynik[1]=kordynaty[1]+a;
      wynik[2]=kordynaty[2];
      return wynik;
    };

    Wektor3D<STyp,SWymiar> operator + ( Wektor3D<STyp,SWymiar> wek) {
      Wektor3D<STyp,SWymiar> wynik;
    
      for (int i = 0; i < SWymiar; i++){
        wynik[i] = wek[i] + kordynaty[i];
      }
    return wynik;
    };


     Wektor3D<STyp,SWymiar> operator - ( Wektor3D<STyp,SWymiar> wek) {
      Wektor3D<STyp,SWymiar> wynik;
    
      for (int i = 0; i < SWymiar; i++){
        wynik[i] = wek[i] - kordynaty[i];
      }
    return wynik;
    };

    string PrintWektor3D(){ 
      ostringstream strm;
      for(auto n : kordynaty){
        strm << n << " ";
      }
      string wynik = strm.str();
      wynik.pop_back();
      return wynik;
    }

};

template <typename STyp, int SWymiar>
ostream& operator << (ostream &StrmWyj, Wektor3D<STyp,SWymiar>& W)
{
  for (unsigned int Ind = 0; Ind < SWymiar; ++Ind) {
    StrmWyj << W[Ind] << " ";
  }  
  return StrmWyj;
}

template <typename STyp, int SWymiar>
istream& operator >> (istream &StrmWej, Wektor3D<STyp,SWymiar>& W)
{
  for (unsigned int Ind = 0; Ind < SWymiar; Ind++) {
    StrmWej >> W[Ind];
  }  
  return StrmWej;
}


#endif