#include "funkcje.h"
#include <iostream>
#include <fstream>
#include <vector>
#include "Macierz.h"
#include <sstream>


bool pobieranie_param(int num, char* params[], std::string& plik_m_jeden, std::string& plik_m_dwa, std::string& plik_wyjsciowy) {
    std::cout << params[0] << "\n";
    if (num < 5) {
        std::cout << "nie poprawna ilosc parametrow\n";
        return 0;
    }
    for (int i = 1; i < num; i += 2) {
        if ((std::string)params[i] == "-f") {
            std::ifstream macierz_jeden(params[i + 1]);
            plik_m_jeden = params[i + 1];
            if (!macierz_jeden) {
                std::cout << "nie dziala plik macierz_jeden.txt\n";
                return 0;
            }
        }
        else if ((std::string)params[i] == "-s") {
            std::ifstream macierz_dwa(params[i + 1]);
            plik_m_dwa = params[i + 1];
            if (!macierz_dwa) {
                std::cout << "nie dziala plik macierz_dwa.txt\n";
                return 0;
            }

        }
        else if ((std::string)params[i] == "-w") {
            std::ifstream p_wynik(params[i + 1]);
            plik_wyjsciowy = params[i + 1];
            if (!p_wynik) {
                std::cout << "nie dziala plik wyjscia - wynik.txt\n";
                return 0;
            }
        }
        else {
            std::cout << "bledne parametry\n";
            return 0;
        }
    }
    return 1;

}
void wynik(Macierz& a)
{
    std::ofstream plik_wyjsciowy("wynik.txt");
    auto rzad = a.get_rzad();
    auto kolumna = a.get_kolumna();
    auto tablica = a.get_tablica();
    plik_wyjsciowy << a.get_rzad() << " " << a.get_kolumna() << "\n";
    for (int i = 0; i < rzad; i++) {
        for (int j = 0; j < kolumna; j++) {
            plik_wyjsciowy << tablica[i][j] << " ";
            
        }
        plik_wyjsciowy << std::endl; 
    }
}
//https://stackoverflow.com/questions/35814963/read-matrix-from-file-give-it-to-main




/// zakonczyc calosc

//int pobier() {
//
//}
//
//int dialog( int liczba) {
//    bool zakoncz;
//    do {
//        switch (liczba) {
//
//
//        case 2:
//
//        }
//    } while (zakoncz <= 1);
//}
//
//bool menager() {
//
//}
