#include"SDL.h"

void szyfruj(std::vector<std::string>& wejsciowy, std::vector<std::string>& wyjsciowy,std::string& klucz, std::string& alfabet)
{

	int licznik = 0;
	for (int j = 0; j < wejsciowy.size(); ++j)
	{
		std::string pomocniczy;
		for (int i = 0; i < wejsciowy[j].size(); ++i)
		{
			int pozycja = alfabet.find(toupper(wejsciowy[j].at(i))) + alfabet.find(toupper(klucz.at(licznik % klucz.size())));
			pomocniczy.push_back(alfabet.at(pozycja % alfabet.length()));
			licznik++;
		}
		wyjsciowy.push_back(pomocniczy);
	}
}

void deszyfruj(std::vector<std::string>& wejsciowy, std::vector<std::string>& wyjsciowy, std::string& klucz, std::string& alfabet)

{
	int licznik = 0;
	for (int j = 0; j < wejsciowy.size(); ++j) 
	{
		std::string pomocniczy;
		for (int i = 0; i < wejsciowy[j].size(); ++i)
		{
			int pozycja = alfabet.find(toupper(wejsciowy[j].at(i))) - alfabet.find(toupper(klucz.at(licznik % klucz.size())));
			if (pozycja < 0) pozycja = alfabet.length() + pozycja;
			pomocniczy.push_back(alfabet.at(pozycja % alfabet.length()));
			licznik++;
		}
		wyjsciowy.push_back(pomocniczy);
	}
}



std::string lamanie(std::vector <std::string>& wejscie,int& dlugosc_klucza,std::string alfabet)
{
	std::string zaszyfrowany = "";
	//std::vector <std::string> tekst_grupy;//pomocniczy string, ktory zawiera grupy o dlugosci klucza
	int klucz = dlugosc_klucza;
	//std::cout << klucz << std::endl;

	for (std::string pomocniczy_string : wejscie)//for each
	{
		zaszyfrowany += pomocniczy_string;
	}
	//std::cout << zaszyfrowany<<'\n';
	std::vector <std::vector<char>> kolumna_liter;//tutaj trzymam wszystkie litery z jednej grupy
	for (int i = 0; i < dlugosc_klucza; ++i)
	{
		std::vector<char> pomocniczy;
		kolumna_liter.push_back(pomocniczy);
	}

	for (int i = 0; i < zaszyfrowany.length(); ++i)
	{
		kolumna_liter[i % dlugosc_klucza].push_back(zaszyfrowany[i]);
		
			
	}
	std::string litery_klucza;
	for (int j = 0; j < dlugosc_klucza; ++j)
	{
		std::vector<int> licznik_wyst_liter;
		std::vector<char> kolumna=kolumna_liter[j];
		for (int l = 0; l < alfabet.size(); ++l)
		{
			licznik_wyst_liter.push_back(0);
		}
		for (int k = 0; k < kolumna.size(); ++k)
		{
			++licznik_wyst_liter[alfabet.find(kolumna[k])];

		}
		int max_indexsi = 0;
		for (int i = 0; i < licznik_wyst_liter.size(); ++i)
		{
			if (licznik_wyst_liter[max_indexsi] < licznik_wyst_liter[i]) max_indexsi = i;
				
			//std::cout << max_indexsi << '\n';
		}

		litery_klucza+=(alfabet[abs((max_indexsi -4) % 26)]);//przy constach nie dziala funckja abs
	//			std::cout<<kolumna[j]<<'\n';

	}
	//for (char x : litery_klucza) std::cout << x << '\n';
	std::cout << litery_klucza;
	return litery_klucza;
}


int rozmiar_klucza(std::vector <std::string>& wejscie)// inspirowane z geekforgeeks
{
	std::string zaszyfrowany = "";
	std::vector <int> koincydencje;
	int licznikKoincydencje = 0;//powtorzen
	for (std::string pomoc : wejscie)//for each
	{
		zaszyfrowany += pomoc;
	}
	for (int transLokacja = 1; transLokacja < zaszyfrowany.size(); transLokacja++)
	{
		licznikKoincydencje = 0;
		for (int j = 0; j < zaszyfrowany.size(); ++j)
		{
			if ((j - transLokacja) >= 0)
			{
				if (zaszyfrowany[j] == zaszyfrowany[(j - transLokacja)])
					licznikKoincydencje++;
			}
		}
		koincydencje.push_back(licznikKoincydencje);
	}

	int maks = 0;
	int licz_maks = 0;
	int suma_maks = 0;//pomocnicze zmienne
		
	for (int i = 0; i < koincydencje.size() - 1; ++i)
	{
		if (koincydencje[i] > maks)
		{
			maks = koincydencje[i];
			licz_maks++;
			suma_maks += maks;
		}
	}

	std::vector<int> najwieksze;
	int x = (suma_maks / licz_maks);
	for (int i = 0; i < koincydencje.size() - 1; ++i)
	{
		if (koincydencje[i] > x)
			najwieksze.push_back(koincydencje[i]);
	}

	std::vector<int>indexy;
	for (int i = 0; i < koincydencje.size() - 1; ++i)
	{
		for (int j = 0; j < najwieksze.size(); ++j)
		{
			if (koincydencje[i] == najwieksze[j])
			{
				indexy.push_back(i);
				break;
			}
		}
	}

	int minim;
	int DlugoscKlucz = 0;
	for (int i = indexy.size() - 1; i > 0; --i)
	{
		if (i == indexy.size() - 1)
			DlugoscKlucz = indexy[i];

		minim = indexy[i] - indexy[i - 1];
		if (minim < DlugoscKlucz)
			DlugoscKlucz = minim;
	}
	//std::cout << DlugoscKlucz;
	return DlugoscKlucz;
}



