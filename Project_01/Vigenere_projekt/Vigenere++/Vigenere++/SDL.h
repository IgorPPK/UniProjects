/** SDL.h @file */
#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<sstream>
#include<limits>
#include<iomanip>
#include<algorithm>
#include<math.h>

/**@brief Funkcja szyfruje do pliku wyjsciowego plik wejsciowy przy pomocy pliku z kluczem.
* @param wejsciowy - wektor wejsciowy jawny.
* @param wyjsciowy - wektor wyjsciowy zaszyforwany.
* @param klucz - plik z kluczem.
* @param alfabet - zmienna typu string, ktora zawiera angielski alfabet.
*/
void szyfruj(std::vector<std::string>& wejsciowy, std::vector<std::string>& wyjsciowy, std::string& klucz, std::string& alfabet);

/**@brief Funkcja deszyfruje do pliku wyjsciowego plik wejsciowy przy pomocy pliku z kluczem.
* @param wejsciowy - wektor wejsciowy zaszyfrowany.
* @param wyjsciowy - wektor wyjsciowy odszyfrowany.
* @param klucz - plik z kluczem.
* @param alfabet - zmienna typu string, ktora zawiera angielski alfabet.
*/
void deszyfruj(std::vector<std::string>& wejsciowy, std::vector<std::string>& wyjsciowy, std::string& klucz, std::string& alfabet);

/**@brief Funkcja zwraca litery kazdej pozycji klucza, czyli caly klucz.
* @param wejsciowy - wektor wejsciowy zaszyfrowany.
* @param dlugosc_klucza - zawiera informacje o ilosci liter w kluczu.
* @param alfabet - zmienna typu string, ktora zawiera angielski alfabet.
* @return lamanie -zwraca klucz z poprawnymi literami.
*/
std::string lamanie(std::vector <std::string>& wejscie, int& dlugosc_klucza, std::string alfabet);

/**@brief Funkcja zwraca ilosc znakow w kluczu.
* @param wejscie - wektor wejsciowy zaszyfrowany.
*/
int rozmiar_klucza(std::vector <std::string>& wejscie);