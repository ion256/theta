int aleintambos(int minima, int maxima)
{
  /// gives a random int between two ints supplied
  /**
   * just means the lower number plus a part of the difference between the two. this part is calculated with the rand/randmax ratio
   */

	return (int)( ((long double)minima) + 
      ( (long double) rand() / (long double) RAND_MAX) * 
      ( ((long double) maxima+1) - ( (long double) minima) ));

}
