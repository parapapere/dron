#ifndef MATRIX_HH
#define MATRIX_HH

#include <iostream>
#include <iomanip>
#include <cmath>
#include "lacze_do_gnuplota.hh"
#include "Wektor3D.hh"

using namespace std;

class Matrix {

    Wektor3D<double, 3> kolumny[3];
    
public:

    Wektor3D <double, 3> operator [] (unsigned int Ind) const { return kolumny[Ind]; }
    Wektor3D <double, 3>&operator [] (unsigned int Ind)       { return kolumny[Ind]; }

    void GetMatrix(double alphaZ){
        kolumny[0][0]=cos(alphaZ);
        kolumny[0][1]=-sin(alphaZ);
        kolumny[0][2]=0;
        kolumny[1][0]=sin(alphaZ);
        kolumny[1][1]=cos(alphaZ);
        kolumny[1][2]=0;
        kolumny[2][0]=0;
        kolumny[2][1]=0;
        kolumny[2][2]=1;
    }

    void Print(double alphaZ){
        cout << kolumny[0][0];
       
    }

    Wektor3D<double, 3> operator* (Wektor3D<double, 3> vector) {
        Wektor3D<double, 3> wynik;
        double tmp;
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
            tmp=kolumny[i][j]*vector[j];
            wynik[i]= wynik[i] + tmp;
            }
        } 

    return wynik;
    }

};

#endif