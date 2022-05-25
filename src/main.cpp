#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

#include "lacze_do_gnuplota.hh"
#include "Wektor3D.hh"
#include "lamana.hh"
#include "powierzchnia.hh"
#include "bryla.hh"
#include "dron.hh"
#include "powierzchnia3d.hh"
#include "matrix.hh"
#include "scena.hh"

using namespace std;


int main(){

PzG::LaczeDoGNUPlota  Lacze;
char c, tmp;
Lacze.ZmienTrybRys(PzG::TR_3D);
Lacze.Inicjalizuj();  // Tutaj startuje gnuplot.

Lacze.UstawZakresX(-40, 100);
Lacze.UstawZakresY(-90, 90);
Lacze.UstawZakresZ(-20, 90);

Lacze.UstawRotacjeXZ(40,60); // Tutaj ustawiany jest widok

Scena one;

while (tmp !='k'){

  cout << "\n\nr - zadaj ruch na wprost\n\no - zadaj zmiane orientacji\nt - zmiana i ruch;\n m - wyswietl menu\nk - koniec dzialania programu\n";
  cin >> tmp;

  switch(tmp){

    case 'r':
    double p;
    cout << "Podaj wartosc kata przesuwania w stopniach\n.Wartosc kata>";
    cin >> p;
    one.WczytajDrona();
  
    one.Zmiana (0, p);
    one.MakeScena("bryly/scena.dat");
  
    Lacze.UsunWszystkieNazwyPlikow();
    Lacze.DodajNazwePliku("bryly/scena.dat");
    Lacze.Rysuj(); 
    break;

  case 'o':
    double o;
    cout << "Podaj wartosc kata obrotu w stopniach\n.Wartosc kata>";
    cin >> o;
    one.WczytajDrona();
  
    one.Zmiana (o, 0);
    one.MakeScena("bryly/scena.dat");
  
    Lacze.UsunWszystkieNazwyPlikow();
    Lacze.DodajNazwePliku("bryly/scena.dat");
    Lacze.Rysuj(); 
    break;
  
  case 't':

    double a,b;
    cout << "Podaj wartosc kata obrotu i przesuwania w stopniach\n.Wartosc katow>";
    cin >> a;
    cin >> b;
    one.WczytajDrona();
  
    one.Zmiana (a, b);
    one.MakeScena("bryly/scena.dat");
  
    Lacze.UsunWszystkieNazwyPlikow();
    Lacze.DodajNazwePliku("bryly/scena.dat");
    Lacze.Rysuj(); 
    break;
  
  case 'm':
    cout << "menu"; 
    break;
}
}

















/*Dron a,b;

PzG::LaczeDoGNUPlota  Lacze;
char c;
 Lacze.DodajNazwePliku("bryly/prostopadloscian3.dat");
  Lacze.ZmienTrybRys(PzG::TR_3D);
  Lacze.Inicjalizuj();  // Tutaj startuje gnuplot.

  Lacze.UstawZakresX(-40, 100);
  Lacze.UstawZakresY(-90, 90);
  Lacze.UstawZakresZ(-20, 90);


  Lacze.UstawRotacjeXZ(40,60); // Tutaj ustawiany jest widok

ifstream in;

in.open("bryly/prostopadloscian3.dat");


while (!in.eof()){
  in >> a;
}
in.close();

 

for (int i = 0; i < 1000000000; i++)
{
  a.ObliczWspolrzedne(0.003);
 
  ofstream out;

  out.open("bryly/prostopadloscian1.dat");

  out << a;
  out.close();
  Lacze.UsunWszystkieNazwyPlikow();
  Lacze.DodajNazwePliku("bryly/prostopadloscian1.dat");
  Lacze.Rysuj();  
}
cout << "Nacisnij ENTER, aby zobaczyc prostopadloscian nr 2 ... " << flush;
  cin >> noskipws >> c;*/

/*a.ObliczWspolrzedne(1);


in.close();

ofstream out;

out.open("bryly/prostopadloscian1.dat");

  out << a;
out.close();

PzG::LaczeDoGNUPlota  Lacze;
char c;

  Lacze.DodajNazwePliku("bryly/prostopadloscian3.dat");
  Lacze.ZmienTrybRys(PzG::TR_3D);
  Lacze.Inicjalizuj();  // Tutaj startuje gnuplot.

  Lacze.UstawZakresX(-40, 100);
  Lacze.UstawZakresY(-90, 90);
  Lacze.UstawZakresZ(-20, 90);


  Lacze.UstawRotacjeXZ(40,60); // Tutaj ustawiany jest widok

  Lacze.Rysuj();        // Teraz powinno pojawic sie okienko gnuplota
                        // z rysunkiem, o ile istnieje plik "prostopadloscian1.dat"
  cout << "Nacisnij ENTER, aby zobaczyc prostopadloscian nr 2 ... " << flush;
  cin >> noskipws >> c;

  Lacze.UsunWszystkieNazwyPlikow();
  Lacze.DodajNazwePliku("bryly/prostopadloscian1.dat");
  Lacze.Rysuj();        // Teraz powinno pojawic sie okienko gnuplota
                        // z rysunkiem, o ile istnieje plik "prostopadloscian2.dat"

  cout << "Nacisnij ENTER, aby zobaczyc prostopadloscian nr 3 ... " << flush;
  cin >> noskipws >> c;*/

/*
Matrix Macoxa;
Wektor3D <double, 3> VEC, wyn;

cin >> VEC;
Macoxa.GetMatrix(3);

wyn = Macoxa*VEC;

cout << wyn;
*/

}
