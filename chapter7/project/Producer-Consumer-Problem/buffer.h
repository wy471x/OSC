#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>
#include <pthread.h>
#include <string.h>
#include <stdbool.h>

typedef int buffer_item;
#define BUFFER_SIZE 5
buffer_item buffer[BUFFER_SIZE];
sem_t full, empty;
pthread_mutex_t mutex;
int insert_item(int);
int remove_item(int *);
void *producer(void *);
void *consumer(void *);
