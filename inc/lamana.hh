#ifndef LAMANA_HH
#define LAMANA_HH

#include <iostream>
#include <iomanip>
#include "lacze_do_gnuplota.hh"
#include "Wektor3D.hh"

using namespace std;

class Lamana {

    
public:
    vector <Wektor3D<double, 3>> points;

    Wektor3D<double, 3> operator [] (unsigned int Ind) const { return points[Ind]; }
    Wektor3D<double, 3> &operator [] (unsigned int Ind)       { return points[Ind]; }

    vector <Wektor3D<double, 3>> GetPoints () const {
        return points;
    }
    void SetPoints (Wektor3D<double, 3> vec){
        points.push_back(vec);
    }
    
    int Size() const{
        return points.size();
    }

    void clear(){
        points.clear();
    }

    void operator = (Lamana now) {
         
         int a = Size();
     for (int i = 0; i < a; i++){
         now.SetPoints(points[i]);        
     }
    }

    Lamana operator + (double a) {

      int size = points.size();
      Lamana wynik;
      for (int i = 0; i < size; i++){
        wynik[i] = points[i]+a;
      }
      return wynik;
    }

    friend istream& operator >> (istream &Strm, Lamana &lamana);

    friend ostream& operator << (ostream &Strm, Lamana &lamana);


    
};

inline ostream& operator << (ostream &Strm, Lamana &lamana){
    
    for (auto n: lamana.points){
        Strm << n << "\n";
        }
        

  return Strm;
}

inline istream& operator >> (istream &Strm, Lamana &lamana){
  
  Wektor3D<double, 3> tmp;
  bool fail = false;
  while ((!Strm.fail()) && (!Strm.eof())){
      Strm >> tmp;
      fail =Strm.fail();
      if(!fail) {
          lamana.SetPoints(tmp);
      }
  }

  return Strm;
}





#endif