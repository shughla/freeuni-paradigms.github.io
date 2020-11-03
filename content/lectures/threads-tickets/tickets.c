// gcc tickets.c -lpthread

#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void RandomSleep(int sec) { sleep(rand() % sec); }

typedef struct {
  int agent_id;
  int *num_tickets;
  sem_t *lock;
} SellTicketsArgs;

void *SellTickets(void *args_ptr) {
  SellTicketsArgs args = *(SellTicketsArgs *)args_ptr;
  while (1) {
    RandomSleep(3);
    sem_wait(args.lock);
    if (*args.num_tickets == 0) {
      sem_post(args.lock);
      break;
    }
    printf("Agent %d sold ticket\n", args.agent_id);
    (*args.num_tickets)--;
    sem_post(args.lock);
  }
  printf("Agent %d sold all tickets\n", args.agent_id);
  return NULL;
}

int main() {
  int num_agents = 3;
  int num_tickets = 15;
  sem_t lock;
  sem_init(&lock, 0, 1);
  // For MacOS
  // sem_t *lock = sem_open("/ticket-lock", O_CREAT, 1);
  SellTicketsArgs args[num_agents];
  pthread_t tids[num_agents];
  for (int i = 0; i < num_agents; ++i) {
    args[i].agent_id = i;
    args[i].num_tickets = &num_tickets;
    args[i].lock = &lock;
    pthread_create(&tids[i], NULL, SellTickets, &args[i]);
  }
  for (int i = 0; i < num_agents; ++i) {
    pthread_join(tids[i], NULL);
  }
  return 0;
}
