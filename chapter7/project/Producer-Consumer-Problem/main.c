#include "buffer.h"

int main(int argc, char *argv[])
{
    if(argc > 4)
    {
        perror("args error");
        exit(1);
    }
    memset(buffer, 0, sizeof(buffer));
    pthread_t prod[atoi(argv[2])], cons[atoi(argv[3])];
    sem_init(&empty, 0, 5);
    sem_init(&full, 0, 0);
    pthread_mutex_init(&mutex, NULL);
    int i;
    for(i = 0; i < atoi(argv[2]); i++)
        pthread_create(&prod[i], NULL, producer, NULL);
    for(i = 0; i < atoi(argv[3]); i++)
        pthread_create(&cons[i], NULL, consumer, NULL);

    sleep(atoi(argv[1]));
    for(i = 0; i < atoi(argv[2]); i++)
        pthread_join(prod[i], NULL);
    for(i = 0; i < atoi(argv[3]); i++)
        pthread_join(cons[i], NULL);
    sem_destroy(&empty);
    sem_destroy(&full);
    pthread_mutex_destroy(&mutex);
    exit(0);
}
