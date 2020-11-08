#include <stdio.h>
#include <stdlib.h>


int main( int argc, char *argv[])  
{
    
    float k;
    float a;
    
    a = atof(argv[1]);
    
    k=a*a;
 
   if( argc == 2 ) {
      printf("Wartość %f do kwadratu to %f. \n", a, k);
   }
  
   else {
      printf("Nie podano argumentu.\n");
   }
   
}
