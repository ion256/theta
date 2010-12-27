std::string doublechord4(entity& input){
  /// Generates quarter notes when supplied an entity
  /**
   * This is a chord of quarter notes. Note that the span is 8 because the shortest note we intend to generate is the 64th note, its span being 1.
   * */
  
std::ostringstream response;
response << "<" << input.note1 << " "<< tabladenotas[(numero(input.note1) + 6)]<< ">"<< "4" ;
 
  return response.str();
}
