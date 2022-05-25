#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;



class FiguraGeometryczna{
     
    protected:
    string nazwa;
    double pole;

    public:
    FiguraGeometryczna(string name, double s){
        nazwa = name;
        pole = s;
    }

    FiguraGeometryczna () {}

    virtual string zwrocNazwe(){
        return nazwa;
    } 

    virtual double ObliczPole(){
        return pole;
    }
};

class Kolo : public FiguraGeometryczna {
    
    double promien;

    public:

    Kolo (double r){
        promien = r;
    }
    
    virtual string zwrocNazwe() override{
        
        nazwa = "Kolo ";

        return nazwa;
    } 

    virtual double ObliczPole() override{

        pole= 3.14*promien*promien;
        return pole;
    }
};

class Prostokat : public FiguraGeometryczna {
    
    double bokA, bokB;

    public:

    Prostokat (double a, double b) {
        bokA = a;
        bokB = b;
    }
    
    virtual string zwrocNazwe() override{
        
        nazwa = "Prostokat ";
        return nazwa;
    } 

    virtual double ObliczPole() override{

        pole= bokA*bokB;
        return pole;
    }
};

int main(){

    vector <Prostokat> prostokaty;
    vector <Kolo> kola;
    
    for(int i = 1; i < 7; i++){
        Prostokat tmp(i, i);
        prostokaty.push_back(tmp);
    }
     
    for(int i = 1; i < 7; i++){
        Kolo tmp(i);
        kola.push_back(tmp);
    }

     for(int i = 0; i < 5; i++){
        cout << prostokaty[i].zwrocNazwe() << i+1 << ": Pole = " << prostokaty[i].ObliczPole() << endl;
        cout << kola[i].zwrocNazwe() << i+1 << ": Pole = " << kola[i].ObliczPole() << endl;
    }

}
