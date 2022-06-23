#include"sprawdz.h"
#include"widok.h"

void sprawdzParametry(int& numParametru, char**& parametr, std::fstream& plik_wej, std::fstream& plik_wyj, std::ifstream& plik_klucz, int& tryb)
{
	if (numParametru != 8 && numParametru != 6) instrukcja();//sprawdzam ilosc parametrow

	for (int i = 0; i < numParametru; ++i)
	{
		std::string pomoc = parametr[i];
		if (pomoc == "--en")
		{
			tryb = 0;

		}
		else if (pomoc == "--de")
		{
			tryb = 1;

		}
		else if (pomoc == "--br")
		{
			tryb = 2;

		}
		else if (pomoc == "-i")
		{
			plik_wej.open(parametr[i + 1]);
			i++;
		}
		else if (pomoc == "-o")
		{
			plik_wyj.open(parametr[i + 1]);
			i++;
		}
		else if (pomoc == "-k")
		{
			plik_klucz.open(parametr[i + 1]);
			i++;
		}
	}

}

bool sprawdzPliki(std::fstream& plik_wej, std::fstream& plik_wyj, std::ifstream& plik_klucz, int tryb)
{
	if (plik_wej) return 0;
	else wyswietl("Blad odczytu pliku wejsciowego");
	if (plik_wyj) return 0;
	else wyswietl("Blad odczytu pliku wyjsciowego");
	if (tryb == 2 || plik_klucz) return 0;
	else wyswietl("Blad odczyty pliku z kluczem");
	return 1;
}

