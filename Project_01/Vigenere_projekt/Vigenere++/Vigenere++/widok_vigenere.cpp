#include"widok.h"

void wyswietl(std::string napis)
{
	std::cout << std::endl << napis << std::endl;
}

void instrukcja() {//krotka instrukcja korzystania z programu

	std::cerr << "Do szyfrowania plikow tekstowych wykorzystaj nastepujace przelaczniki:\n"
		<< "--en\n -i plik tekstowy wejsciowy jawny\n -o plik tekstowy wyjsciowy zaszyfrowany\n"
		<< "--k plik tekstowy z kluczem\n"
		<< "\nDo deszyfrowania plikow tekstowych wykorzystaj nastepujace przelaczniki:\n"
		<< "--de\n -i plik tekstowy wejsciowy jawny\n -o plik tekstowy wyjsciowy zaszyfrowany\n"
		<< "--k plik tekstowy z kluczem\n"
		<< "\nDo lamania plikow tekstowych wykorzystaj nastepujace przelaczniki:\n"
		<< " -i plik tekstowy wejsciowy jawny\n -o plik tekstowy wyjsciowy zaszyfrowany\n";
	exit(1);
}