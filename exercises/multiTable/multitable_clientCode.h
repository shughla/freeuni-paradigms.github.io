#include "multitable.h"


void ListRecordsInRange(multitable *zipCodes, char *low, char *high);

static void InRangePrint(void *keyAddr, void *valueAddr, void *auxData);
