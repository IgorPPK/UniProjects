/** przetwarzania.h @file */
#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<sstream>
#include<limits>
//#include<iomanip>
//#include<algorithm>
//#include<math.h>



/**@brief Funkcja ma za zadanie przeslac zawartosc zmiennej typu string na plik wyjsciowy.
* @param napis - zmienna typu string, ktora zawiera caly tekst.
* @param plik_wyj - plik do ktorego przesylamy plik napis.
*/
void zapisz_plik(std::string napis, std::fstream& plik_wyj);

/// Funkcja ma za zadanie przeslanie zawartosci pliku z kluczem do zmiennej typu string.
std::string przetwarzanie_klucz(std::ifstream& klucz);

/// Funkcja ma za zadanie przeslanie zawartosci pliku wejsciowego i/lub wyjsciowego do wektora typu string.
std::vector<std::string> przetwarzanie_danych_io(std::fstream& plik);