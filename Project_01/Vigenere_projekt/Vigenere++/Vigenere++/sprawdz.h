/** sprawdz.h @file */
#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
//#include<sstream>
//#include<limits>
//#include<iomanip>
//#include<algorithm>
//#include<math.h>

/**@brief Funkcja sprawdza ilosc wpisanych parametrow oraz tryb, ktory determinuje potrzebe stosowana klucza.
*
* @param numParametru - ilosc wyrazow odczytanych z wiersza polecen.
* @param parametr - tablica wyrazow odczytywana z wiersza polecen.
* @param plik_wej - plik wejsciowy.
* @param plik_wyj - plik wyjsciowy.
* @param plik_klucz - plik z kluczem.
* @param tryb - determinuje potrzebe stosowania pliku z kluczem.
*/
void sprawdzParametry(int& numParametru, char**& parametr, std::fstream& plik_wej, std::fstream& plik_wyj, std::ifstream& plik_klucz, int& tryb);

/**@brief Funkcja sprawdza poprawnosc odczytu plikow.
* @param plik_wej - plik wejsciowy.
* @param plik_wyj - plik wyjsciowy.
* @param plik_klucz - plik z kluczem.
* @param tryb - zapobiega falszywym bledom.
* @return bool
*/
bool sprawdzPliki(std::fstream& plik_wej, std::fstream& plik_wyj, std::ifstream& plik_klucz, int tryb);