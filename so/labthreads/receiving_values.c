#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* myturn(void* arg)  {
    int* iptr = (int *)malloc(sizeof(int));
    *iptr = 5;
    for(int I=0; I < 8; I++) {
         sleep(1);
	printf("My turn! %d %d\n", I, *iptr);
        (*iptr)++;
    }
    // what if we return a value?
	return iptr;
}

void yourturn() {
    for(int I=0; I < 3; I++) {
	sleep(2);
	printf("Your turn! %d\n", I);
    }
}  

int main() {
    pthread_t newthread;
    int* result;
    pthread_create(&newthread, NULL, &myturn, NULL);
    yourturn();
    pthread_join(newthread, (void *) &result);
    printf("thread’s done: *result=%d\n", *result);
}

