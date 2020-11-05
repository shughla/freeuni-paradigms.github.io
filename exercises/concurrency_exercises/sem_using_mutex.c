#include "sem_using_mutex.h"

typedef struct {
	int value;
	pthread_cond_t * wait;
	pthread_mutex_t * lock;
} semT;

void semInit(semT * s, int value) {
	s->value = value;
	s->wait = malloc(sizeof(pthread_cond_t));
	s->lock = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(s->lock, NULL);
	pthread_cond_init(s->wait, NULL);
}

void semPost(semT * s) {
	pthread_mutex_lock(s->lock);
	s->value++;
	pthread_cond_signal(s->wait);	
	pthread_mutex_unlock(s->lock);
}

void semWait(semT * s) {
	pthread_mutex_lock(s->lock);
	// while instead of if because
	// depends on scheduler implementation
	// look up spurious wakeup
	while (s->value == 0) {
		pthread_cond_wait(s->wait, s->lock);
	} 
	s->value--;
	pthread_mutex_unlock(s->lock);
}