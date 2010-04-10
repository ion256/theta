int numero(std::string& nota){
  /// Pon una descripcion corta aqui
  /**
   * Y una larga aqui
   * */
  
  int i;
  for( i=0; nota.compare(tabladenotas[i]) != 0 && (i<90) ; i++ ){} // selfnote: nota.compare will return 0 when match.
  if(i>89) return 0; // this means that badly spelled notes will run out the counter and return 0
  return i+1;
}
