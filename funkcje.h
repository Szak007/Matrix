#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include "Macierz.h"
#include <sstream>

bool pobieranie_param(int num, char* params[], std::string& plik_m_jeden, std::string& plik_m_dwa, std::string& plik_wyjsciowy);
void wynik(Macierz& a);