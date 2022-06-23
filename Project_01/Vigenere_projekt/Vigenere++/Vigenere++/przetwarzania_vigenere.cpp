#include"przetwarzania.h"

std::vector<std::string> przetwarzanie_danych_io(std::fstream& plik)
{
	std::vector<std::string> wektor_pomoc;
	std::string pomoc;
	for (int i = 0; !plik.eof(); ++i)
	{
		plik >> pomoc;
		wektor_pomoc.push_back(pomoc);
	}
	return wektor_pomoc;
}

std::string przetwarzanie_klucz(std::ifstream& klucz)
{
	std::string pomocnicza;
	klucz >> pomocnicza;
	return pomocnicza;
}

void zapisz_plik(std::string napis, std::fstream& plik_wyj)
{
	plik_wyj << napis;
}