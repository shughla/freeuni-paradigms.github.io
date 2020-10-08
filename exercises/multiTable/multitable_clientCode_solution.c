#include "multitable_clientCode.h"




void ListRecordsInRange(multitable *zipCodes, char *low, char *high){
  char *endpoints[] = {low, high};
  MultiTableMap(zipCodes, InRangePrint, endpoints);
}



static void InRangePrint(void *keyAddr, void *valueAddr, void *auxData){
  char *zipcode = (char *) keyAddr;
  char *city = *(char **) valueAddr;
  char **endpoints = (char **) auxData;
  char *low = endpoints[0];
  char *high = endpoints[1];
  if ((strcmp(zipcode, low) >= 0) && (strcmp(zipcode, high) <= 0))
    printf("%5s: %s\n", zipcode, city);
}


