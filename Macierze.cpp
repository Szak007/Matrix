//https://www.geeksforgeeks.org/array-of-objects-in-c-with-examples/
//https://stackoverflow.com/questions/23683023/how-to-store-a-matrix-of-custom-objects-in-c
//chat gpt
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "Macierz.h"
#include "funkcje.h"

//dodawanie,odejmowanie,przypisywanie, proste dzialania jako przeciazenia operatora - done
//transpozycja  - done
//jak liczyc macierze
//plik z funkcjami odnoszace sie do obslugi maina ale nie w clasie i metodach, i friendach
//dwa pliki - 1 z jedna macierza - 2 z druga macierza - plik wynikowy gdzie oddajemy macierz wynikowa
//https://www.geeksforgeeks.org/matrix-operations-using-operator-overloading/
//https://cpp0x.pl/kursy/Programowanie-obiektowe-C++/Podstawy/Operatory/498
//https://www.geeksforgeeks.org/different-operation-matrices/


//chcemy dodac metode gdzie jest mnozenie macierzy, chcemy dodac szukanie wartosci maksymalnej



int main(int num, char* params[])
{

    std::string plik_m_jeden;
    std::string plik_m_dwa;
    std::string plik_wynik;

    if (!pobieranie_param(num, params, plik_m_jeden, plik_m_dwa, plik_wynik)) {
        std::cout << "pobieranie parametrow sie nie powiodlo\n";
        return 0;
    }

    /*switch*/

    //Macierz m(4, 4); //od jeden

    //m.set(0, 3, 1); //od zera do 3
    //m.set(1, 1, 2);
    //m.set(2, 2, 3);
    //m.set(3, 3, 1);

    ////m.print();

    //Macierz s;
    //s.print();
    //std::cout << std::endl << std::endl;
    //
    //s = s.transpozycja(); //z tym się męczyłem w głupi sposób
    //s.print();

    //s.transponuj();
    //s.print();
    //std::cout << std::endl;
    //std::cout << "\n last \n";
    //s.trans();
    //s.print();
    //std::cout << std::endl;



    //std::cout << "\n\n";
    //Macierz j(plik_m_jeden);
    //Macierz d(plik_m_dwa);
    //Macierz w=j+d;
    //j.print();
    //std::cout << "\n";
    //d.print();
    //std::cout << "\n";
    //w.print();

    //w = j;
    //std::cout << "\n";
    //w.print();

    //w = j;
    //std::cout << "\n";
    //w.print();

    //w = j - d;
    //std::cout << "\n";
    //w.print();

    ////w = j + d;
    //w.print();
    //w.tworzenie_pliku();
    ////wynik(w);


}

