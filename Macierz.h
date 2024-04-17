#pragma once
#include <iostream>
class Macierz
{
private:
	int rzad;// --
	int kolumna; // ||
	int** tablica;

public:
	Macierz();
	Macierz(const int &r, const int &k);
	Macierz(const Macierz& a);
	Macierz(std::string &file_name);
	~Macierz();
	
	void set(int r, int k, int wartosc);
	int get(int r, int k ) const;
	int get_rzad() const;
	int get_kolumna() const;
	int** get_tablica() const;
	void print() const;
	void tworzenie_pliku();
	void transponuj();
	void trans();

	Macierz transpozycja();
	Macierz operator=(const Macierz& a); //wymaga³o bycia w klasie
	Macierz operator+(const Macierz& a) const;
	Macierz operator-(const Macierz& a) const;
	
	
};


//implementacja czystej macierzy w sposob komunikatywny i dziala tak jak macierz, czyli whodzenie do danej komóreczki 