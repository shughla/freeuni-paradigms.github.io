struct database {
  int reference;
  short tables[2];
};

struct dataCenter {
  char *coordinates;
  struct database node;
  struct database *next;
};

typedef char* (*querySelector)(struct database*);

querySelector RetrieveData(char* coordinates);

struct database **PopulateDatabase(struct database *server, querySelector script);

struct database **CreateComputerLab(short *datacenterCoordinates, struct dataCenter *servers)
{
  querySelector queryScript = RetrieveData(servers[0].coordinates);
  datacenterCoordinates[*datacenterCoordinates] = 0;
  if (servers[2].node.reference > 3)
    servers += ((struct database *) (servers->next[0].tables))->reference;
  return PopulateDatabase((struct database *)&servers, queryScript);
}
