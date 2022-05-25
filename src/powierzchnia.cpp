#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <fstream>
#include "lacze_do_gnuplota.hh"
#include "lamana.hh"
#include "powierzchnia.hh"

void Powierzhnia:: MakePowierszchniaDna(string NazwaPliku){
        
        int OX = -20, OY = -60, OZ = -20;
        ofstream dno;
        ifstream powdno;

        dno.open(NazwaPliku,  ios::app);
        
        for(OY; OY < 90; OY = OY + 20){
            for (OX = -20; OX < 100; OX = OX + 20){
                    dno << OX << " " << OY << " " << OZ << endl;
                    dno << OX << " " << OY + 20 << " " << OZ << endl ;
                    dno << OX + 20 << " " << OY + 20 << " " << OZ << endl;
                    dno << OX + 20 << " " << OY  << " " << OZ << endl;
                    dno << OX << " " << OY << " " << OZ << endl;
                    if(OX == 80)
                        dno << OX << " " << OY + 20 << " " << OZ << endl ;
                    dno << "#\n\n";
                } 
        }
        dno<<endl;
        dno.close();
    }

    void Powierzhnia:: MakePowierszchniaWody(string NazwaPliku){
        
        int OX = -20, OY = -60, OZ = 70;
        ofstream woda;

        woda.open(NazwaPliku,  ios::app);
        
        for(OY; OY < 90; OY = OY + 40){
            for (OX = -20; OX < 100; OX = OX + 20){
                    woda << OX << " " << OY << " " << OZ << endl;
                    woda << OX << " " << OY + 20 << " " << OZ + 10 << endl;
                    woda << OX + 20 << " " << OY + 20 << " " << OZ + 10 << endl;
                    woda << OX << " " << OY + 20 << " " << OZ + 10 << endl;
                    woda << OX << " " << OY + 40 << " " << OZ << endl;
                    woda << OX + 20 << " " << OY + 40 << " " << OZ << endl;
                    woda << OX + 20 << " " << OY + 20 << " " << OZ + 10 << endl;
                    woda << OX + 20 << " " << OY  << " " << OZ << endl;
                    woda << OX << " " << OY << " " << OZ << endl;
                    if(OX == 80){
                        woda << OX << " " << OY + 20 << " " << OZ + 10 << endl;
                        woda << OX << " " << OY + 40 << " " << OZ << endl;
                        }
                    woda << "#\n";
                } 
        }
        woda << endl;
        woda.close();
    }