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
 *       Author:  Jesús García Rodríguez <505547@unizar.es>,
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
  composer = \"7pro automatic score generator\" \
  copyright = \"" << autor << "\
  \" footer = \"Generated with 7pro\" \
  inputencoding = \"utf8\"} \
  \\score { \
    \\new PianoStaff << \
      \\new Staff { \
        \\key " << tonica << " \\major " << endl ;

  // Begining of notes area
  srand(time(NULL));
  do { // Main loop, generates numbers, filters valid, translates to notes and sends to file
	  final = aleintambos(numero(notaminima), numero(notamaxima));
	  if( pertenece(final, intdiamayor, numero(tonica)) ) {
		    validos++;
        musica << tabladenotas[(final-1)] << " ";
        if (debug == 1) cout << "accepted number:  " << final << 
               " note entered:  " << tabladenotas[(final-1)] << endl;
	  }
    else {
      if (debug == 1) cout << "not valid " << final <<endl;
    }
	} while (validos < longitud);

  musica << "}" << // Cierre de Staff
  ">>" << // Cierre del PianoStaff
  "}"; // Cierre del Score

  cout << "Finished, now format the .ly with lillypond to pdf" << endl;
  return 0;
}
