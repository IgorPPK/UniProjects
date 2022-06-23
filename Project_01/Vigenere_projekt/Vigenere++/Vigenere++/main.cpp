#include"przetwarzania.h"
#include"SDL.h"
#include"widok.h"
#include"sprawdz.h"


int main(int argc, char* argv[])
{
	std::string alfabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	std::fstream strumien_pliku_wej;
	std::fstream strumien_pliku_wyj;
	std::ifstream plik_klucz;
	int tryb;

	sprawdzParametry(argc, argv, strumien_pliku_wej, strumien_pliku_wyj, plik_klucz, tryb);
	if (sprawdzPliki(strumien_pliku_wej, strumien_pliku_wyj, plik_klucz, tryb))
		return 0;
	std::string klucz;
	if(tryb!=2) klucz = przetwarzanie_klucz(plik_klucz);
	std::vector<std::string> wejscie = przetwarzanie_danych_io(strumien_pliku_wej), wyjsciowy;
	
	switch (tryb)
	{
	case 0:
		szyfruj(wejscie, wyjsciowy, klucz, alfabet);
		break;
	case 1:
		deszyfruj(wejscie, wyjsciowy, klucz, alfabet);
		break;
	case 2:
		int dlugosc_klucza = rozmiar_klucza(wejscie);
		std::string klucz_br=lamanie(wejscie,dlugosc_klucza ,alfabet);
		deszyfruj(wejscie, wyjsciowy, klucz_br, alfabet);
		break;
	}

	for (std::string tekst : wyjsciowy)// dla kazdego stringa w wektorze wejsciowym
	{
		zapisz_plik(tekst+" ",strumien_pliku_wyj);
	}

	return 0;
	//zakoncz lub potowrz
}
