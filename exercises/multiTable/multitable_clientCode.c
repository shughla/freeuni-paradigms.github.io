#include "multitable_clientCode.h"



void ListRecordsInRange(multitable *zipCodes, char *low, char *high){
  char *endpoints[] = {low, high};
  MultiTableMap(zipCodes, InRangePrint, endpoints);
}


static void InRangePrint(void *keyAddr, void *valueAddr, void *auxData){
  char *zipcode;
  char *city;
  char *low;
  char *high;

  /*include code that properly initializes
    the four local variables to be what they
    need to be so that the range check and
    the printf statement work properly. */
  
  if ((strcmp(zipcode, low) >= 0) && (strcmp(zipcode, high) <= 0)
      printf("%5s: %s\n", zipcode, city);
}
