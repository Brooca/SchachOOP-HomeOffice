#include "Spiel.h"
#include "consolenfarbe.h"

extern Spiel s;

Spiel::Spiel()
{
	// User-Input: Array<string> spieler
	set_Spieler();

	// Key-String
	std::string figurenFolge = "TSLDKLSTBBBBBBBB";
	figurenFolge += std::string(32, ' ');
	figurenFolge += "bbbbbbbbtsldklst";
	int index = 0;
	
	/* spielstand map<string, Feld> : in Grundstellung mit Feldern füllen */
	for (char d = '1'; d <= '8'; d++)
	{
		for (char c = 'A'; c <= 'H'; c++)
		{
		std::string key = std::string(1,c) + d;
		spielstand[key] = Feld::Feld(key,figurenFolge[index++]); 
		}
	}
}

map<string, Feld> Spiel::get_Spielstand()
{
	return spielstand;
}

array<Spieler, 2> Spiel::get_Spieler()
{
	return spieler;
}

void Spiel::set_Spieler()
{
	std::string eingabe;

	// Spieler 1
	std::cout << "Spieler*in Weiss:   ";
	std::cin >> eingabe;
	Spieler spieler1(eingabe, 1);

	// Spieler 2
	std::cout << "Spieler*in Schwarz: ";
	std::cin >> eingabe;
	Spieler spieler2(eingabe, 0);
	std::cout << "\n";

	spieler = { spieler1, spieler2 };
}

// Funktion set Cursor
void setCursorPosition(unsigned int x, unsigned int y)
{
	static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	std::cout.flush();
	COORD coord = { (SHORT)x, (SHORT)y };
	SetConsoleCursorPosition(hOut, coord);
}

// Operator overload
ostream& operator << (ostream& lhs, Spiel& rhs) {
	using namespace dkremer;
	// Clear Screen
	// system("cls");
	concolinit();
	//setcolor(white, blue );

	// Headline
	lhs << blue << string(20, '#') << " CHESS " << string(20, '#') << white << endl << endl;

	// Spieler*in
	lhs << "White: " << rhs.get_Spieler().at(0);
	lhs << "Black: " << rhs.get_Spieler().at(1);
	// lhs << "White: " << rhs.get_Spieler().at(0).get_Name() << endl;
	// lhs << "Black: " << rhs.get_Spieler().at(1).get_Name() << endl;
	lhs << endl;

	// Board

	//unsigned int startzeile{ 20 };
	//unsigned int startspalte{ 0 };
	//setCursorPosition(startzeile, startspalte);
	for (char c = '8'; c >= '1'; c--) {  // Output : Figur auf Feld passend zur Bezeichnung
		//startspalte++;
		//setCursorPosition(startzeile, startspalte);
		lhs << c;

		// Field
		for (char d = 'A'; d <= 'H'; d++) {
			if (((d + c) % 2) == 1) {
				//setCursorPosition(startzeile, startspalte);
				setcolor(black, blue);
				lhs << rhs.get_Spielstand()[string(1, d) + c].get_Figur()->get_Bezeichnung();
				setcolor(deftextcol, defbackcol);
				//startspalte++;
				//startzeile++;
			}

				else {
					setcolor(black, white);
					lhs << rhs.get_Spielstand()[string(1, d) + c].get_Figur()->get_Bezeichnung();
					setcolor(deftextcol, defbackcol);
					//startspalte++;
				//	startzeile++;
				}		
			if ((string(1, d) + c) == s.test) {

				setcolor(black, magenta);
				lhs << rhs.get_Spielstand()[string(1, d) + c].get_Figur()->get_Bezeichnung();
				setcolor(deftextcol, defbackcol);
			}
			/*

				// nach bunt
				if (s.get_Spielstand()[s.test].get_ErlaubteFelder().size() != 0) {
					//setCursorPosition(startzeile, startspalte);
					//startspalte++;
					//startzeile++;
					for (auto& str : s.get_Spielstand()[s.test].get_ErlaubteFelder()) {
				//		setCursorPosition(startzeile, startspalte);
						//startspalte++;
						if (string(1, d) + c == str) {
					//		setCursorPosition(startzeile, startspalte);
							setcolor(black, dark_green);
							lhs << rhs.get_Spielstand()[string(1, d) + c].get_Figur()->get_Bezeichnung();
							setcolor(deftextcol, defbackcol);
						//	startspalte++;
							//startzeile++;
				}
*/
			}
			lhs << endl;
		}
		// Underline with characters
	//	startspalte++;
		//startzeile++;
		//setCursorPosition(startzeile, startspalte);
		lhs << " " << "ABCDEFGH" << endl;

		// erlaubteFelder
		lhs << endl << "Erlaubte Felder\n";

		for (string mapKey : {"A1", "B1", "C1", "D1"}) {
			lhs << rhs.get_Spielstand().at(mapKey).get_Bezeichnung() << " : ";
			for (string s : rhs.get_Spielstand().at(mapKey).get_ErlaubteFelder()) {
				lhs << s << " ";
			}
			lhs << "\n";
		}

		return lhs;
}

// test


void Spiel::ziehen()
{
	// Output
	std::cout << endl << "void Spiel::ziehen()" << endl;

	// Test-Abruf Turm auf A1
	// cout << endl << endl << "Test-Abruf Turm auf A1";
	spielstand["A1"].set_ErlaubteFelder("A1");

	// Test-Abruf Springer auf B1
	// cout << endl << "Test-Abruf Springer auf B1";
	spielstand["B1"].set_ErlaubteFelder("B1");

	// Test-Abruf Laeufer auf C1
	// cout << endl << endl << "Test-Abruf Laeufer auf C1";
	spielstand["C1"].set_ErlaubteFelder("C1");

	// Test-Abruf Dame auf D1
	// cout << endl << "Test-Abruf Dame auf D1";
	spielstand["D1"].set_ErlaubteFelder("D1");

	unsigned int startzeile = 5;
	unsigned int startspalte = 5;
	setCursorPosition(startzeile, startspalte);
	cout << "Von: "; cin >> s.test;
}


