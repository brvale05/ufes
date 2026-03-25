#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* myturn(void* arg)  {
    int* iptr = (int *)arg;
    for(int I=0; I < 8; I++) {
         sleep(1);
	printf("My turn! %d %d\n", I, *iptr);
        (*iptr)++;
    }
    // what if we return a value?
	return NULL;
}

void yourturn() {
    for(int I=0; I < 3; I++) {
	sleep(2);
	printf("Your turn! %d\n", I);
    }
}  

int main() {
    pthread_t newthread;
    int v=5;
    pthread_create(&newthread, NULL, &myturn, &v);
    yourturn();
    pthread_join(newthread, NULL);
    printf("thread’s done: v=%d\n", v);
}

