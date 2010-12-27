std::string note(int& input){
  /// Gives note when supplied a number
  /**
   * I just rewrote this function so that the code was clearer.
   * */
  
std::string response;
if ((input>=1)&&(input<=88)) response = tabladenotas[(input-1)];
	else response = tabladenotas[0];
 
  return response;
}
