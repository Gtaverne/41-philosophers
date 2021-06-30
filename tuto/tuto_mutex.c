#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>

void*	philoeat (void *arg)
{
	(void)arg;
	while (1)
	{
		sleep(1);
		printf("I eat\n");
	}
	return NULL;
}

void*	philosleep(void *arg)
{
	(void)arg;
	int i = 0;
	while (i < 10)
	{
		sleep(3);
		printf("I sleep : %d\n", i);
		i++;
	}
	return NULL;
}

int main ()
{
	pthread_t newthread;

	pthread_create(&newthread, NULL, philoeat, NULL);
	philosleep(0);
	pthread_join(newthread, NULL);
}