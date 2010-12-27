std::string quarter(entity& input){
  /// Generates quarter notes when supplied an entity
  /**
   * This is the simplest generation, just concatenates note1 and the assigned span, which should be generated in the main, not here.
   * */
  
std::ostringstream response;
input.span=8;
response << input.note1 << (input.span/2);
 
  return response.str();
}
