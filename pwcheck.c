#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
//test
//level 1
char heslalvl1(char pole[])
{
  char found_lower = false, found_upper = false;
  for(int i = 0; pole[i] != '\0'; i++) //pruchod 2 rozmernym polem (slova a radky)
    {      
       found_lower = found_lower || (pole[i] >= 'a' && pole[i] <= 'z'); //hleda male pismeno
       found_upper = found_upper || (pole[i] >= 'A' && pole[i] <= 'Z'); // hleda velke pismeno
      if(found_upper == true && found_lower == true)
      {
         return 1;  //vypis hesel co splnuji podminky
      }     
    }
  return 0; // program konci
}
//level 2
char heslalvl2(char pole[], unsigned int param)
{ 


    char found_lower = false, found_upper = false, found_number = false, found_special = false;
  for(int i = 0; pole[i] != '\0'; i++)
  {
    found_lower = found_lower || (pole[i] >= 'a' && pole[i] <= 'z'); 
    found_upper = found_upper || (pole[i] >= 'A' && pole[i] <= 'Z'); 
    found_number = found_number || (pole[i] >= '0' && pole[i] <= '9'); 
    found_special = found_special || (pole[i] >= '!' && pole[i] <= '/') || (pole[i] >= ':' && pole[i] <= '@') || (pole[i] >= '[' && pole[i] <= '`') || (pole[i] >= '{' && pole[i] <= '~'); 
    int splneno_pravidel = found_lower + found_upper + found_number + found_special;
    //soucet splnenych podminek
    if(splneno_pravidel >= param) //porovnani zda je splneno zadani
    return 1;
  }
  return 0; // program konci
}

//level 3 
char heslalvl3 (char pole[], unsigned int param){
  char znak = ch_arr[0];
  int nalezeno = 1;
  //int heslo = 100; // 100 znaku
  int i;

  for (i = 1; ch_arr[i] != '\0'; i++) { // puvodne (i = 1; i < ch_arr[i] != '\0'; i++)
    if (znak == ch_arr[i]) {
      nalezeno++; //podiva se na dalsi znak a pokud je stejny, inkrementuje hodnotu nalezeno
    }
    else {
      nalezeno = 1;
      znak = ch_arr[i];
    }
    if (nalezeno >= param){
      return 0;
    } 
  }
  return 1;
}

//lvl 4 
char heslalvl4 (char pole[], unsigned int param)
  {

    if ((strlen(pole)/2) < param) //nelze mit vetsi parametr nez delku pulky slova
    {
      return 1;
    }
    for (size_t i = 0; pole [i + param - 1] != '\0'; i++)
    {
      for (size_t ii = i + 1; pole [ii + param - 1] != '\0'; ii++) {
        char same = 1;
        for (size_t iii = 0; iii < param; iii++) {
          if (pole[i + iii] != pole[ii + iii]) {
            same = 0;
          }
        }
        if (same == 1) {
          return 0;
        } 
      }
    } 
    return 1;
  }

//ODSUD VYS NESAHAT, FINALNI

// int main(int argc, char* agrv[]){
// for(int counter=0; counter<argc; counter++){
//   printf("%s\n", agrv[counter]);
// }
// return 0;
// }

int main(int argc, char* agrv[])
{

  int levl = 0, param=0;
  bool statsshow=false;

// looping trough arguments EXCLUDING file redirection
 for(int counter=0; counter<argc; counter++){ 
     printf("%s\n", agrv[counter]);
    //level
    if (counter == 1){
   levl = agrv[counter];
    }
    //param
    else if(counter == 2){
      param = agrv[counter];
    }

//stats required?
    if(argv[counter] == "--stats")
    {
      statsshow = true;
    }
}



  //reading STDIN redirection from file.txt
    int bufferSize = 100;
    char *buffer = malloc(bufferSize);
    int length = 0;
    int c;

    while ((c = getchar()) != EOF)
    {
        if (length == bufferSize)
        {
            bufferSize *= 2;
            buffer = realloc(buffer, bufferSize);
        }

        buffer[length++] = c;
    }

    for (int j = 0; j < length; j++)
    {
        putchar(buffer[j]);
        
    }

    return 0;
}

  // prikazovy radek na levely a parametr - preteka pamet
  /*bool porovnani_stringu(char *a, char *b) {
    while (*a != '\0' || *b != '\0') {
        if (*a != *b)
            return false;
        a++;
        b++;
    }
    return *a == '\0' && *b == '\0'; 
}*/
  // zaridit aby se pri kontrole vyssich lvlu zkontrolovaly i ty nizsi

  /*snaha o input
  char znaky[100];
  int c;
  while (!eof(stdin)){
    for (int i = 0; c != '\n'; i++)
  }
*/

#define POCET_HESEL = 5 //prepsat vsude 4 na pocet hesel

//int main() // nacitani prikazak
// {
//   /*char ch_arr[5][102] = { //102 kvuli \n a \0 na konci kazdeho hesla
//                           "Test123", //deklarace pole s hesly
//                           "ahoj",
//                           "AlesAles",
//                           "AGOHJ",
//                           "123456"
//                         };*/



//   //stats - dodelat
//   /*char c;
//   int lvl = 2;
//   while (c = getchar() != EOF) 
  
//   { 
//     char znaky [100] = {0} //vsechny znaky inicializovany na 0
//     int nacteny_heslo = 0

//     if (c != '\n') {
//       znaky[nacteny_heslo] = c
//       nacteny_heslo++
//     }
//     else 
//     {
//       if (lvl == 1 && heslalvl1(znaky) == true)
//       { printf("%s\n", znaky);  } 
//       if (lvl == 2 && heslalvl2(znaky) == true)
//       { printf("%s\n", znaky);  } 
//       if (lvl == 3 && heslalvl3(znaky) == true)
//       { printf("%s\n", znaky);  } 
//       if (lvl == 4 && heslalvl4(znaky) == true)
//       { printf("%s\n", znaky);  } 

//     }
//   }*/

//   int lvl;
//    printf ("Level?\n");
//   scanf("%d", &lvl);


  
//   int param; // POZOR muze byt vetsi
//   printf ("Parametr?\n");
//   scanf("%d", &param);
//   if (param > 5) {
//     param = 4;
//   }

//   // for(int i = 0; i <= 4; i++)
//   // {
//   //   printf("%c\n", heslalvl1(ch_arr[i]));
//   // }
  
//   // for(int i = 0; i <= 4; i++)
//   // {
//   //   printf("%c\n", heslalvl2(ch_arr[i], param));
//   // }
  
//    // moje

// // doupravit do statistik
//   for(int i = 0; i <= 4; i++){
//     if (heslalvl3(ch_arr[i], param)) {
//       printf("%s\n", ch_arr[i]);
//     }
//   } 
//   // k lvl 4



//    for(int i = 0; i <= 4; i++) 
//   {
//      if ( heslalvl4(ch_arr[i], param)) {
//        printf("%s\n", ch_arr[i]);
//   }
//   }

//   /*int nchars;
//   for(int i = 0; ch_arr[][] != '\0'; i++)
//   {


//   }


//   }
//   if (argv[3] == "--stats"){ - vypis statistik, dodelat, mame jen 1/3?
//     printf("Statistika:\n");
//     printf("Ruznych znaku: %d \n", nchars);
//   }*/

//   //- Kroupa, odsud dolu by az na lvl3 melo jit
//   // volani levelu, dodelat na parametry a fix na [i]
  
//     /*if (porovnani_stringu(argv[1], "1")) {
//         heslalvl1(*ch_arr);
//           for(int i = 0; i <= 4; i++)
//   {
//     printf("%c\n", heslalvl1(ch_arr[i]));
//   }
//     } else if (porovnani_stringu(argv[1], "2")) {
//       if (heslalvl1(*ch_arr) == true){
//         heslalvl2(*ch_arr, param);
//          for(int i = 0; i <= 4; i++){
//            printf("%c\n", heslalvl2(*ch_arr, param));
//          }
//       }
//     } else if (porovnani_stringu(argv[1], "3")) {
//       if (heslalvl1(*ch_arr) == true && heslalvl2(*ch_arr, param) == true) {
//        printf("%c\n", heslalvl3(*ch_arr, param));
//         for (int i = 0; i <= 4; i++){
//           printf("%c\n", printf("%c\n", heslalvl3(*ch_arr, param)));
//         }
//       }
//     } else if (porovnani_stringu(argv[1], "4")){
//       if (heslalvl1(*ch_arr) == true && heslalvl2(*ch_arr, param) == true && heslalvl3(*ch_arr, param) == true) {
//         heslalvl4(*ch_arr, param);
//         for (int i = 0; i <= 4; i++){
//            printf("%s\n", ch_arr[i]);
//         }
//       }
//     } else if (porovnani_stringu(argv[1], ">4")) {
//        if (heslalvl1(*ch_arr) == true && heslalvl2(*ch_arr, param) == true && heslalvl3(*ch_arr, param) == true) {
//         heslalvl4(*ch_arr, param);
//         for (int i = 0; i <= 4; i++){
//            printf("%s\n", ch_arr[i]);
//         }
//       }
//     }*/
// }


