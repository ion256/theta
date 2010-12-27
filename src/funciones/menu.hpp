int setdefaults(){
  autor=menu[0].value;
  titulo=menu[1].value;
  debug=atoi(menu[2].value.c_str());
  scoreLength=atoi(menu[3].value.c_str());
  tonica=menu[4].value;
  notaminima=menu[5].value;
  notamaxima=menu[6].value;
  destfile=menu[7].value;
} 

int menumaker(){
  /// Makes the menu
  /** 
   * Writes down the menu, waits for input and does whatever it has to do
   * Maybe a later version will use ncurses
   * */
  using namespace std;
   const int menu_size = 9; //sizeof(menu)/sizeof(menu[0]); // This just gives the number of elements in the menu matrix FIXME we used const int to test, the commented expression should work
  
  opt_exit = menu_size;
  opt_doit = menu_size - 1 ;

  do {
    option=NULL;
    for ( int i=0; i <= menu_size; ++i){
      if ( menu[i].status.compare("0") == 0) {
        cout << left << setw(2) << i << left << " " << setw(20) << menu[i].name << " [ ] ";
      } else {
        cout << left << setw(2) << i << left << " " << setw(20) << menu[i].name << " [X] ";
      }
     cout << endl;
    }

    cout << "Introduzca opción: ";
    cin >> option;
    if(cin.fail()){
      cin.clear();
      system("clear");
      cin.ignore(INT_MAX, '\n');
      continue;
    } 

    if ( option <= opt_exit ) { 
      if ( option == opt_exit ) { exit(0); }
      if (option != opt_doit){
        cout << endl << menu[option].help << endl;
        cin >> menu[option].value;
        menu[option].status="1";
      }
    } else {
      cout << endl << " Opción desconocida " << option << endl;
      sleep(2);
    }
  system("clear");

  } while ( option != opt_doit );

}
