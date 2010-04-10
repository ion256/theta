int pertenece(int evaluada, int intervalos[], int madre){
  /// returns 1 if the note belongs to the scale
  /**
   * madre is the tonic, thus the difference has to be one of the allowed intervals listed in intervalos, the loop returns 1 if there is any match. The first value in each table is the loop limit, if exceeded will return 0 and the note will be discarded
   * */
  int i;
  for( i = 1;((evaluada-madre)!=intervalos[i])&&(i<intervalos[0]);i++ ){}
  if (i<intervalos[0]) return 1;
  return 0;
}
