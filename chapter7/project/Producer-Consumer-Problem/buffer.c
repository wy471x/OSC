#include "buffer.h"
int in = 0;
int out = 0;
int count = 0;
int insert_item(buffer_item item)
{
    if(count == BUFFER_SIZE)
       return -1;
    buffer[in] = item;
    in = (in + 1) % BUFFER_SIZE;
    count++;
    return 0;
}

int remove_item(buffer_item *item)
{
    if(count == 0)
        return -1;
    *item = buffer[out];
    out = (out + 1) % BUFFER_SIZE;
    count--;
    return 0;
}

void *producer(void *param)
{
    buffer_item item;
    while(true){
        sleep(1);
        item = random()%100 + 1;
        sem_wait(&empty);
        pthread_mutex_lock(&mutex);
        if(insert_item(item))
            printf("report error condition for insert\n");
        else
            printf("producer produced %d\n", item);
        pthread_mutex_unlock(&mutex);
        sem_post(&full);
    }
}

void *consumer(void *param)
{
    buffer_item item;

    while(true){
        sleep(1);

        sem_wait(&full);
        pthread_mutex_lock(&mutex);
        if(remove_item(&item))
            printf("report error condition for remove\n");
        else
            printf("consumer consumed %d\n", item); 
        pthread_mutex_unlock(&mutex);
        sem_post(&empty); 
    }
}
