/*
 * =====================================================================================
 *
 *       Filename:  theta.cpp
 *
 *       Description:  Aleatory score generator
 *
 *       Version:  1.0
 *       Created:  22/03/10 13:40:56
 *       Revision:  none
 *       Compiler:  gcc
 *
 *       Author:  Jesús García Rodríguez (Ión) <505547@unizar.es>,
 *                  David Francos (XayOn) <yo.orco@gmail.com>
 *       Company:  
 *
 * =====================================================================================
 */
// FIXME Copy a license here, if u want u can copy the text of the gpl, I mean, to license this code you have to copy a small notice of the gpl for each file. Then include full gpl with the pacakge.
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <climits>
#include <string.h>
#include "theta.hpp"

int main(int argc, char **argv){
  using namespace std;

  if ( ! batch_flag ) menumaker(); // this creates the menu
  setdefaults(); // this sets the default values for the variables
//FIXME the output .ly file is not overwritten, either we enable the deletion prior to the new file generation or a different name with the date and time can be generated each time unless specified otherwise.
  if (debug == 1) cout << "Title: " << titulo << endl
  << "Author: " << autor << endl
  << "tonic: " << tonica << " . its number: " << numero(tonica) << endl
  << "Minimum: " << notaminima << " , Maximum: " << notamaxima<< endl
  << "Nminimum= " << numero(notaminima) << " , Nmaximum = " << numero(notamaxima) << endl; 

  ofstream file(destfile.c_str(), ios::app | ios::binary);
  ostream& musica=file; // So we can do the stdout stuff in a future...

  musica << "%" << endl << "% " << destfile << endl << "%"  << endl
  << "\\version \"2.12.0\"" << endl << "\\include \"espanol.ly\" " << endl
  << "\\paper { paperheight = 29.8\\cm paperwidth = 21\\cm line = 17 \\cm}" << endl
  << "\\header { title = \"" << titulo << "\" \
  composer = \"Theta automatic score generator\" \
  copyright = \"" << autor << "\
  \" footer = \"Generated with Theta\" \
  inputencoding = \"utf8\"} \
  \\score { \
    \\new PianoStaff << \
      \\new Staff { \
        \\key " << tonica << " \\major " << endl ;

  // Begining of notes area
  srand(time(NULL));
  do { // Main loop, generates numbers, filters valid, translates to notes and sends to file
	  final = aleintambos(numero(notaminima), numero(notamaxima));
		present.typeOfElement = aleintambos(0, 2);
		switch (present.typeOfElement){//TODO XayOn, this is a problem: the span has to be defined prior to the admission of the entity because of the remaining time condition explained below. This means that the switch appears twice. We have to discuss this.
			case 0:	present.span = 8; break;
			case 1: present.span = 4; break;
			case 2: present.span = 8; break;
			default: present.span = 8;
			}
		if( (pertenece(final, intdiamayor, numero(tonica))) && ((present.span) <= (scoreLength*32 - timeIndex)) ) {//the loop will accept the entity only when the note is valid AND shorter than the time remaining
		timeIndex = (timeIndex + present.span);
		present.note1 = note(final);
		present.note2 = numero(present.note1);
			if (debug==1) cout << "nota(final) is:"<< note(final)<< " final:"<< final<< " tonica:" << tonica<< " numero(tonica):"<<numero(tonica)<< endl;
		switch (present.typeOfElement){
			case 0:	musica << quarter(present) << " ";if (debug == 1) cout << "accepted number:  " << present.note2 << " note entered:  " << quarter(present) << "present vector:" << present.typeOfElement << " * "<< present.note1 << " * " << present.note2 << " * " << present.span << " * timeIndex:" << timeIndex << " scoreLength:" << scoreLength << endl;  break;
			case 1: musica << eighth(present) << " "; if (debug == 1) cout << "accepted number:  " << present.note2 << " note entered:  " << eighth(present) << "present vector:" << present.typeOfElement << " * "<< present.note1 << " * " << present.note2 << " * " << present.span << " * timeIndex:" << timeIndex << " scoreLength:" << scoreLength << endl; break;
			case 2: musica << doublechord4(present) << " "; if (debug == 1) cout << "accepted number:  " << present.note2 << " note entered:  " << doublechord4(present) << "present vector:" << present.typeOfElement << " * "<< present.note1 << " * " << present.note2 << " * " << present.span << " * timeIndex:" << timeIndex << " scoreLength:" << scoreLength << endl; break;
			default: present.span = 8;
			}// end switch TODO I believe we could change typeOfElement to a string with the name of the function to call but I don't know how to do this. In the future we are going to have pretty many elements, way too many to put them all in a switch.
        		if (debug == 1) cout << endl;
	  }// end if
    else {
      if (debug == 1) cout << "not valid " << final <<endl;
    }

	} while (timeIndex < (scoreLength*32));
	/*if (debug==1) {
		for (int j=1; j<89; j++)
			cout << "j is:"<< j << " and note(j) is:"<< note(j)<< endl;
			}*/
  musica << "}" << // Cierre de Staff
  ">>" << // Cierre del PianoStaff
  "}"; // Cierre del Score

  cout << "Finished. Don't forget that you must format the output file using lilypond. Suggested command for this: lilypond -o scorefinished score.ly" << endl;
  return 0;
}
