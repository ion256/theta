/*
 * =====================================================================================
 *
 *   Filename: theta.hpp 
 *
 *   Description:  theta headers.
 *
 *   Version:  .0
 *   Created:  22/03/0 4:32:44
 *   Revision:  none
 *   Compiler:  gcc
 *
 *   Author:  Jesús García Rodríguez <505547@unizar.es>,
 *   David Francos Cuartero (XayOn) <yo.orco@gmaiL.com>
 *   Company:  
 *
 * =====================================================================================
 */


FILE* fp1, * fp2;

int final, scoreLength, timeIndex=0, debug; // validos has been substitued for timeIndex and longitud has been substitued for scoreLenght
int option, opt_exit, opt_doit;

int debug_flag=0;
int batch_flag=0;

std::string tonica;
std::string notaminima;
std::string notamaxima;
std::string status;
std::string templatescore;
std::string destfile;
std::string titulo;
std::string autor;


/*  
std::string opt_author; 
std::string opt_title; 
std::string opt_longitud; 
std::string opt_tonica; 
std::string opt_notaminima;
std::string opt_notamaxima;
std::string opt_dstfile;
std::string opt_templatescore; 

*/

typedef struct 
{
  std::string name;
  std::string help;
  std::string value;
  std::string status;
} MenuElement;
  
MenuElement menu[] = {// Whenever a new option is added that shall be done before the two last ones.
    { "Autor" , "Introduzca el autor" , "Automatic Score Generator" , "0" },
    { "Titulo" , "Introduzca el titulo de la partitura" , "Automated Score", "0"  },
    { "Debug mode", "Seleccione 1 para activar el modo debug", "1", "0" },
    { "Score lenght", "Enter the length in tempos", "16", "0" },
    { "Nota tónica", "Introduzca la nota tónica", "do", "0" },
    { "Nota mínima", "Introduzca la nota mínima", "do'" , "0" },
    { "Nota máxima", "Introduzca la nota máxima", "do''", "0" },
    { "Archivo de destino", "Introduzca el archivo de destino", "score.ly", "0" },
    { "Generar y salir", "", "", "0" },
    { "Salir", "", "", "0" }
};

typedef struct
{
	int typeOfElement;
	std::string note1;
	int note2;
	int span;
} entity; // this variable is the pregeneration entity. The music element will be generated upon it by calling a different function depending on typeOfElement.
entity present; //FIXME please give initial values, I just couldn't do it. "0", "do'", "40", "8". TODO use note2 to define the DEGREE note1 is in the given scale.


#include "funciones/tablas.hpp" // these are the tables for note to number converstion and the note intervals
#include "funciones/numero.hpp" // returns the number of the supplied note, 0 being la..., firs key in most pianos
#include "funciones/note.hpp" // returns the note when supplied a number.
#include "funciones/aleintambos.hpp" //returns an integer random number between the two integers supplied both included. uses long double to guarantee uniform distribution. RAND_MAX and rand() are used here
#include "funciones/pertenece.hpp" //means "belongs", returns 1 if the supplied note belongs to the described scale 
#include "funciones/menu.hpp" //  menu parameters and functions
#include "funciones/quarter.hpp" // generates quarter notes
#include "funciones/eighth.hpp" // generates eighth notes
#include "funciones/doublechord4.hpp" // generates chords of quarter with fifth interval up

