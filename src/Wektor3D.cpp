#include <iostream>
#include <iomanip>
#include <vector>
#include "lacze_do_gnuplota.hh"
#include "Wektor3D.hh"

Wektor3D Wektor3D :: operator+(double a){
    for (int i=0; i<3; i++){
        points[i]=points[i]+a;
    }
    return points;
}