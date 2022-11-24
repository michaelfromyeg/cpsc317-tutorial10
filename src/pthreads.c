#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

void complete_task();
void begin_task(char *message);
void *wait_time_task();
void *print_argument_task(void *args);
void *return_int_task();

int main()
{
    pthread_t t1, t2, t3;

    pthread_create(&t1, NULL, wait_time_task, NULL);
    pthread_join(t1, NULL);

    char *message = "Hello from main!";
    pthread_create(&t2, NULL, print_argument_task, message);
    pthread_join(t2, NULL);

    int *i;
    pthread_create(&t3, NULL, return_int_task, NULL);
    pthread_join(t3, (void *)&i);

    printf("return_int_task gave i=%d\n", *i);

    return 0;
}

void *wait_time_task()
{
    char *name = "wait_time_task";
    begin_task(name);

    for (int i = 0; i < 10000000; i++)
    {
    }

    complete_task();
    return NULL;
}

void *print_argument_task(void *args)
{
    char *name = "print_argument_task";
    begin_task(name);

    char *message = (char *)args;
    printf("%s\n", message);

    complete_task();
    return NULL;
}

void *return_int_task()
{
    char *name = "return_int_task";
    begin_task(name);

    int *i = malloc(sizeof(int));
    *i = 1;

    complete_task();
    return i;
}

void begin_task(char *message)
{
    printf("Beginning task %s...\n", message);
}

void complete_task()
{
    printf("Finished task!\n\n");
}
