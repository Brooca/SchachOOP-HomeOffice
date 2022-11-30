#include "libChess.h"
#include "Spiel.h"

extern Spiel s;

Spiel::Spiel()
{
	// User-Input: Array<string> spieler
	set_Spieler();

	// Key-String						   X_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-X
	string figurenFolge = "TSLDKLSTBBBBBBBB                                bbbbbbbbtsldklst";
 // string figurenFolge = "TSLDKLSTBBBBBBBB                                bbbbbbbbtsldklst";
	int index = 0;

	/* spielstand map<string, Feld> : in Grundstellung mit Feldern füllen */
	for (char d = '1'; d <= '8'; d++)
	{
		for (char c = 'A'; c <= 'H'; c++)
		{
			string key = string(1, c) + d;
			spielstand[key] = Feld::Feld(key, figurenFolge[index++]);
		}
	}

	// erlaubteFelder berechnen aus der Grundstellung
	/* Documentation: Fuer alle Felder, die nicht leer sind werden die erlaubten Felder der Figuren berechnet */
	for (auto& einzelfeld : spielstand) {
		if(einzelfeld.second.get_Figur()->get_Bezeichnung() != ' ')
		spielstand[einzelfeld.first].set_ErlaubteFelder(einzelfeld.first);
	}
}

/*### Getter ###*/
map<string, Feld> Spiel::get_Spielstand(){	return spielstand;	}
array<Spieler, 2> Spiel::get_Spieler(){	return spieler;	}

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

	//TODO: Bugs
	/*	- Uebeschrift erlaubteFelder springt hin und her 
		- synchronisieren der Farben

	// Experiement find
	Feld zugNachF(zugNach);
	if (*find(s.get_Spielstand().at(zugVon).get_ErlaubteFelder().begin(), s.get_Spielstand().at(zugVon).get_ErlaubteFelder().end(), zugNachF)->get_Bezeichnung() == zugNachF.get_Bezeichnung())
	{
	}
	
	// Experiement Lambda + for_each
	  for_each(arr1.begin(), arr1.end(), lambda function);
	  Lamda : [ capture clause ] (parameters) -> return-type  { definition of method }

		for_each(s.get_Spielstand().at(zugVon).get_ErlaubteFelder().begin(),
		s.get_Spielstand().at(zugVon).get_ErlaubteFelder().end(),
		[zugNach] (Feld f1) { 
			cout << "Lambda";
			return f1.get_Bezeichnung() == zugNach;
		});
	*/

	//! User Input Departure
	//? ZugVon pruefen auf Guetltigkeit gegen Stack-overflow
		/*	- Range von Buchstabe und von der Zahl
			- Laenge des Strings muss 2 betragen
		*/

	// ZugVon ruft Feld der map auf 
	// ZugNach gleicht erlaubte Felder des Feldes ab
	// falls erlaubtes ausgewählt, wird es dort hin kopiert und hinterlässt leeres Feld

	//! Variablen
	string zugVon, zugNach;
	bool check; // Steuer-Variable for while
	
	//! zugVon wird geprueft
	do{
		check = true;

		// User Input
		cout << s;
		setCursorPosition(startspalte = 5, startzeile = 10);
		cout << "Von: ";
		cin >> zugVon;

		// Gueltigkeits-Pruefung
		if ( zugVon.size() == 2)
		{  
			if (not (zugVon.at(0) >= 'A' && zugVon.at(0) <= 'H' || zugVon.at(0) >= 'a' && zugVon.at(0) <= 'h'))
			{ 
				check = false; 
				cout << " X Koordinate falsch eingegeben\n";
			}
			if (not (zugVon.at(1) >= '1' && zugVon.at(1) <= '8'))
			{ 
				check = false; 
				cout << " Y Koordinate falsch eingegeben\n";
			}
		}
		else {	
			check = false;
			cout << "Laenge der Eingabe nicht okay. \n"; 
		} 
		//system("Pause");
	} while (not check);

	//! Eingabe muss in Upper convert
	zugVon.at(0) = toupper(zugVon.at(0));

	//! zugVon ist eine eigene Figur
	if(s.get_Spielstand().at(zugVon).get_Figur()->get_Farbe() == s.get_Spieler().at(0).get_Farbe()){	//todo: amZug ??
		cout << "Figur hat nicht deine Farbe";
	//	system("Pause");
		ziehen();
	}

	//! zugNach wird geprueft
	do {
		check = true;

		// User Input
		cout << s;
		setCursorPosition(startspalte = 5, startzeile = 10);
		cout << "Nach: ";
		cin >> zugNach;

		// Gueltigkeits-Pruefung
		if (zugNach.size() == 2) {
			if (not (zugNach.at(0) >= 'A' && zugNach.at(0) <= 'H' || zugNach.at(0) >= 'a' && zugNach.at(0) <= 'h')) { 
				check = false; 
				cout << " X Koordinate falsch eingegeben\n"; 
			}
			if (not (zugNach.at(1) >= '1' && zugNach.at(1) <= '8')) { 
				check = false; 
				cout << " Y Koordinate falsch eingegeben\n";
			}
		}
		else { 
			check = false; 
			cout << "Laenge der Eingabe nicht okay. \n";
		}
		//system("Pause");
	} while (not check);

	//! Eingabe muss in Upper convert
	zugNach.at(0) = toupper(zugNach.at(0));

	//! Pruefung der erlaubten Felder
	// Empty
	if(s.get_Spielstand().at(zugVon).get_ErlaubteFelder().empty()){
		cout << "Figur hat keine erlaubten Feder   ";
		//system("Pause");
		ziehen();
	}

	//! map(zugVon).erlaubteFelder enthaelt zugNach
	bool enthalten = false;
	for (int i = 0; i < s.get_Spielstand().at(zugVon).get_ErlaubteFelder().size(); i++)
	{
		if (s.get_Spielstand().at(zugVon).get_ErlaubteFelder().at(i).get_Bezeichnung() == zugNach)
		{
			enthalten = true;
		}
	}

	if (enthalten)
	{
		//! map manipulieren
		char zwischenspeicher = s.get_Spielstand().at(zugNach).get_Figur()->get_Bezeichnung();
		s.spielstand.at(zugNach) = Feld::Feld(zugNach, s.spielstand.at(zugVon).get_Figur()->get_Bezeichnung());
		s.spielstand.at(zugVon) = Feld::Feld(zugVon, ' ');

		//! erlaubteFelder berechnen aus der Grundstellung
		/* Documentation: Fuer alle Felder, die nicht leer sind werden die erlaubten Felder der Figuren berechnet */
		for (auto& einzelfeld : spielstand) {
			if (einzelfeld.second.get_Figur()->get_Bezeichnung() != ' ')
				spielstand[einzelfeld.first].set_ErlaubteFelder(einzelfeld.first);
		}

		//! is der Koenig dabei ?
		for (auto& einzelfeld : spielstand) {
			for (auto& f1 : einzelfeld.second.get_ErlaubteFelder()) {
				if(f1.get_Figur()->get_Bezeichnung() == 'K' || f1.get_Figur()->get_Bezeichnung() == 'k'){
					cout << "Schach";
					system("Pause");
				}
			}
		}

		cout << s;
	}
	else
	{
		ziehen();
	}
	/*
	zugNach : A5 || A3
	A6 A5 A4
	A4 -> raus

	if(zugNach = map(zugVon).erlaubteFelder))			
	cout << "zugNach kein erlaubtes Feld";
	 wenn nicht ziehen()
	*/

	
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
	lhs << blue << string(27, '#') << " CHESS " << string(27, '#') << white << endl << endl;

	// Spieler*in White
	setCursorPosition(startspalte = 5, startzeile = 3);
	lhs << "    /\\/|   " << "\n"; setCursorPosition(startspalte, ++startzeile);
	lhs << "  //   .\\  " << "\n"; setCursorPosition(startspalte, ++startzeile);
	lhs << "  ||  ;^;) " << "\n"; setCursorPosition(startspalte, ++startzeile);
	lhs << "  3____\\   " << "\n"; setCursorPosition(startspalte, ++startzeile);
	lhs << " ((n_____) " << "\n";

	setCursorPosition(startspalte, ++startzeile);
	lhs << "White: " << rhs.get_Spieler().at(0);

	// Spieler*in Black
	setCursorPosition(startspalte = 45, startzeile = 3);
	lhs << "|\\/\\_" << "\n"; setCursorPosition(startspalte, ++startzeile);
	lhs << "/.  \\\\" << "\n"; setCursorPosition(--startspalte, ++startzeile);
	lhs << "(;^;  ||" << "\n"; setCursorPosition(startspalte += 2, ++startzeile);
	lhs << "/____3" << "\n"; setCursorPosition(--startspalte, ++startzeile);
	lhs << "(____n))" << "\n";

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
				lhs << rhs.get_Spielstand()[string(1, d) + c].get_Figur()->get_Bezeichnung();
				setcolor(deftextcol, defbackcol);
			}
		}
		lhs << endl;
		startzeile++;
	}
	// Underline with characters
	setCursorPosition(++startspalte, startzeile);
	lhs << "ABCDEFGH" << endl;

	/*### Output : erlaubteFelder ###*/
	/*
		Documentation:
		Fuer jedes im Spielstand gespeicherte Feld wird
			- wenn es nicht leer ist:
				- die Feld-Bezeichnung ausgegeben und
				- der Vector erlaubteFelder iterierend dem Output-Stream lhs hinzugefuegt.

		ToDo:
			- um nur die erlaubten Felder der eigenen Figuren auszugeben oder ueberhaupt zu unterscheiden
			waere es noetig die spielerfarbe mit der figurenfarbe in zusammenhang zu bringen
				-> Possible Solution: zugnummer etablieren
	*/
	lhs << endl << "Erlaubte Felder\n";

	for(auto& einzelfeld : rhs.spielstand){
	// if(einzelfeld.second.get_Figur()->get_Farbe() == rhs.get_Spieler().at(/*unpredictable  -> boolean zugnummer */)) {		// Fuer welchen Spieler ?
	
		// isEmpty ?
		if(not einzelfeld.second.get_ErlaubteFelder().empty()) {
		lhs << rhs.get_Spielstand().at(einzelfeld.first).get_Bezeichnung() << " -> ";
		lhs << rhs.get_Spielstand().at(einzelfeld.first).get_Figur()->get_Bezeichnung() << " : ";

			// vector erlaubteFelder hinzufuegen
			for (int i = 0; i < rhs.get_Spielstand().at(einzelfeld.first).get_ErlaubteFelder().size(); i++) {
				string s = rhs.get_Spielstand().at(einzelfeld.first).get_ErlaubteFelder().at(i).get_Bezeichnung();
				lhs << s << " ";
			}

		// Zeilenumbruch
		lhs << "\n";
		}
	// }
	}

	/*### Return ostream ###*/
	return lhs;
}