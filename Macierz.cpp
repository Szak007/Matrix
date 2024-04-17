#include "Macierz.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

Macierz::Macierz()
{
	std::string linijka;
	int liczba;
	std::cout << "\npodaj liczbe rzadow: ";
	std::cin >> rzad;
	std::cout << "\npodaj liczbe kolumn: ";
	std::cin >> kolumna;
	
	tablica = new int* [rzad];
	std::cout << "\nPodaj zawartosc macierzy: \n";
	std::cin.ignore();
	for (int i = 0; i < rzad; i++) {
		tablica[i] = new int [kolumna];
		std::getline(std::cin, linijka);
		std::stringstream ss(linijka);
		for (int j = 0; j < kolumna; j++) {
			
			if (ss >> liczba) {
				tablica[i][j] = liczba;
			}
			else {
				tablica[i][j] = 0;
			}
		}


	}
	//tablica = new int* [1]; //pierwsza kolumnal
	//tablica[0] = new int[1] {0}; ////bo = 0 nie przechodzi³o


}

Macierz::Macierz(const int &r, const int &k) : rzad(r), kolumna(k)
{
	tablica = new int* [rzad]; 
	for (int i = 0; i < rzad; i++) {
		tablica[i] = new int [kolumna];
	}
}

Macierz::Macierz(const Macierz& a)
{
	rzad = a.rzad;
	kolumna = a.kolumna;
	tablica = new int* [rzad];
	for (int i = 0; i < rzad; i++) {
		tablica[i] = new int[kolumna];
		for (int j = 0; j < kolumna; j++) {
			tablica[i][j] = a.tablica[i][j];
		}
	}
}

Macierz::Macierz(std::string &file_name)
{
	std::string linijka;
	int liczba;
	std::ifstream file_stream(file_name);
	if (file_stream.good()) {
		std::getline(file_stream, linijka);
		std::stringstream ss(linijka);
		ss >> rzad;
		ss >> kolumna;
		tablica = new int* [rzad];
		for (int i=0; i < rzad; i++) {
			tablica[i]=new int[kolumna];
			std::getline(file_stream, linijka);
			std::stringstream ss_dwa(linijka);
			for (int j = 0; j < kolumna; j++) {
				if (ss_dwa >> liczba) {
					tablica[i][j] = liczba;
				}
				else {
					tablica[i][j] = 0;
				}
			}
		}

	}
	else {
		std::cout << "\nnie zaladowano pliku \n";
	}
	file_stream.close();


}

Macierz::~Macierz()
{
	for (int i = 0; i < rzad; i++) {
		delete[] tablica[i];
	}
	delete[] tablica;
}

void Macierz::set(int r, int k, int wartosc)
{
	tablica[r][k] = wartosc;
}



int Macierz::get(int r, int k) const
{
	return tablica[r][k];
}

int Macierz::get_rzad() const
{
	return rzad;
}

int Macierz::get_kolumna() const
{
	return kolumna;
}

int** Macierz::get_tablica() const
{
	return tablica;
}

void Macierz::print() const
{
	for (int i = 0; i < rzad; i++) {
		for (int j = 0; j < kolumna; j++) {
			
			std::cout << tablica[i][j] << " ";
		}
		
		std::cout << std::endl;
	}
}

void Macierz::tworzenie_pliku()
{
	std::ofstream plik_wyjsciowy("wynik.txt");
	plik_wyjsciowy << rzad << " " << kolumna << "\n";
	for (int i = 0; i < rzad; i++) {
		for (int j = 0; j < kolumna; j++) {
			plik_wyjsciowy << tablica[i][j] << " ";
		}
		plik_wyjsciowy << std::endl;
	}
}

Macierz Macierz::operator=(const Macierz& a)
{
	if (this == &a) return *this;
	for (int i = 0; i < rzad; ++i) {
		delete[] tablica[i];
	}
	delete[] tablica;
	rzad = a.rzad;
	kolumna = a.kolumna;
	tablica = new int* [rzad];
	for (int i = 0; i < rzad; i++) {
		tablica[i] = new int[kolumna];
		for (int j = 0; j < kolumna; j++) {
			tablica[i][j] = a.tablica[i][j];
		}
	}

	return *this;
}

void Macierz::trans()
{
	for (int i = 0; i < rzad; i++) {
		for (int j = i + 1; j < kolumna; j++) {
			std::swap(tablica[i][j], tablica[j][i]);
		}
	}

}

Macierz Macierz::operator+(const Macierz& a) const
{
	Macierz wynik(rzad, kolumna);
	for (int i = 0; i < rzad; i++) {
		for (int j = 0; j < kolumna; j++) {
			wynik.tablica[i][j] = /*this->*/tablica[i][j] + a.tablica[i][j];
		}
	}
	return wynik;
}

Macierz Macierz::operator-(const Macierz& a) const
{
	Macierz wynik(rzad, kolumna);
	for (int i = 0; i < rzad; i++) {
		for (int j = 0; j < kolumna; j++) {
			wynik.tablica[i][j] = tablica[i][j] - a.tablica[i][j];
		}
	}

	return wynik;
}

Macierz Macierz::transpozycja() 
{
	Macierz wynik(kolumna, rzad);
	for (int i = 0; i < kolumna; i++) {
		for (int j = 0; j < rzad; j++) {
			/*std::swap(wynik.tablica[i][j], wynik.tablica[j][i]);*/
			wynik.tablica[i][j] = tablica[j][i];
		}
	}
	//wynik.print();
	return wynik;
}

//to z ciekawosci z chata wzi¹³em
void Macierz::transponuj() {
	// Utworzenie tymczasowej macierzy o wymiarach odwróconych
	int** tymczasowa = new int* [kolumna];
	for (int i = 0; i < kolumna; i++) {
		tymczasowa[i] = new int[rzad];
	}

	// Przepisanie transponowanych wartoœci do tymczasowej macierzy
	for (int i = 0; i < rzad; i++) {
		for (int j = 0; j < kolumna; j++) {
			tymczasowa[j][i] = tablica[i][j];
		}
	}

	// Zwolnienie pamiêci starej macierzy
	for (int i = 0; i < rzad; i++) {
		delete[] tablica[i];
	}
	delete[] tablica;

	// Przypisanie tymczasowej macierzy do oryginalnej i aktualizacja wymiarów
	tablica = tymczasowa;
	std::swap(rzad, kolumna); // Zamiana liczby rzêdów i kolumn
}






