#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* myturn(void* arg)  {
    for(int I=0; I < 8; I++) {
         sleep(1);
	printf("My turn! %d\n", I);
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
    pthread_create(&newthread, NULL, &myturn, NULL);
    yourturn();
    pthread_join(newthread, NULL);
}

