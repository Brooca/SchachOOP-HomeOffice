#include "libChess.h"
#include "consolenfarbe.h"
#include "Spiel.h"

Spiel::Spiel()
{
	// User-Input: Array<string> spieler
	set_Spieler();

	// Key-String
	string figurenFolge = "TSLDKLSTBBBBBBBB";
	figurenFolge += string(32, ' ');
	figurenFolge += "bbbbbbbbtsldklst";
	int index = 0;
	
	/* spielstand map<string, Feld> : in Grundstellung mit Feldern füllen */
	for (char d = '1'; d <= '8'; d++)
	{
		for (char c = 'A'; c <= 'H'; c++)
		{
		string key = string(1,c) + d;
		spielstand[key] = Feld::Feld(key,figurenFolge[index++]); 
		}
	}

	// erlaubteFelder aus Grundstellung
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
	string eingabe;

	// Spieler 1
	cout << "Spieler*in Weiss:   ";
	cin >> eingabe;
	Spieler spieler1(eingabe, 1);

	// Spieler 2
	cout << "Spieler*in Schwarz: ";
	cin >> eingabe;
	Spieler spieler2(eingabe, 0);
	cout << "\n";

	spieler = { spieler1, spieler2 };
}

void Spiel::ziehen()
{
	// Output Manipulation Values
	unsigned int startzeile;
	unsigned int startspalte;

	// User Input Departure
	string zugVon;

	setCursorPosition(startspalte = 5, startzeile = 10);
	cout << "Von: ";
	cin >> zugVon;
}

// Operator overload
ostream& operator << (ostream& lhs, Spiel& rhs) {

	// Output Manipulation Values
	using namespace dkremer;
	unsigned int startzeile;
	unsigned int startspalte;

	// Colour Setup
	concolinit();

	// Clear Screen
	system("cls");
	
	// Headline
	lhs << blue << string(27, '#') << " CHESS " << string(27, '#') << white<< endl << endl;

	// Spieler*in White
	setCursorPosition(startspalte = 5, startzeile = 3);
	lhs << "    /\\/|   " << "\n"; setCursorPosition(startspalte, ++startzeile);
	lhs << "  //   .\\  " << "\n"; setCursorPosition(startspalte, ++startzeile);
	lhs << "  ||  ;^;) "  << "\n"; setCursorPosition(startspalte, ++startzeile);
	lhs << "  3____\\   " << "\n"; setCursorPosition(startspalte, ++startzeile);
	lhs << " ((n_____) "  << "\n";

	setCursorPosition(startspalte, ++startzeile);
	lhs << "White: " << rhs.get_Spieler().at(0);

	// Spieler*in Black
	setCursorPosition(startspalte = 45, startzeile = 3);
	lhs <<  "|\\/\\_"    << "\n"; setCursorPosition(startspalte, ++startzeile);
	lhs <<  "/.  \\\\"   << "\n"; setCursorPosition(--startspalte, ++startzeile);
	lhs << "(;^;  ||"    << "\n"; setCursorPosition(startspalte += 2, ++startzeile);
	lhs <<   "/____3"    << "\n"; setCursorPosition(--startspalte, ++startzeile);
	lhs	<<  "(____n))"   << "\n";

	setCursorPosition(startspalte, ++startzeile);
	lhs << "Black: " << rhs.get_Spieler().at(1);

	/* Board */		
		startzeile = 3;
		startspalte = 25;

		// Output : Figur auf Feld passend zur Bezeichnung
		for (char c = '8'; c >= '1'; c--) {
		setCursorPosition(startspalte, startzeile);
			// Numbers to the left side
			lhs << c;

			// Field
			for (char d = 'A'; d <= 'H'; d++) {
				if (((d + c) % 2) == 1) {
					setcolor(black, blue);
					lhs << rhs.get_Spielstand()[string(1, d) + c].get_Figur()->get_Bezeichnung();
					setcolor(deftextcol, defbackcol);
				}
				else { 
					setcolor(black, white);
					lhs << rhs.get_Spielstand()[string(1, d) + c].get_Figur()->get_Bezeichnung() ;
					setcolor(deftextcol, defbackcol);
				}
			}
			lhs << endl;
		}
		// Underline with characters
		setCursorPosition(++startspalte, startzeile);
		lhs << "ABCDEFGH" << endl;

	// erlaubteFelder
	lhs << endl << "Erlaubte Felder\n";

	for (string mapKey : {"A1", "B1", "C1", "D1"}) {
		lhs << rhs.get_Spielstand().at(mapKey).get_Bezeichnung() << " : ";
		for (string s : rhs.get_Spielstand().at(mapKey).get_ErlaubteFelder()) {
			lhs << s << " ";
		}
		lhs << "\n";
	}

	// Return ostream
	return lhs;
}