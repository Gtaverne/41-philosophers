#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>

void*	philoeat (void *arg)
{
	char *str = (char *)arg;
	int i = 0;
	while (i < 10)
	{
		usleep(100000);
		printf("I eat %s\n", str);
		i++;
	}
	return NULL;
}

void*	philosleep(void *arg)
{
	(void)arg;
	int i = 0;
	while (i < 10)
	{
		usleep(300000);
		printf("I sleep : %d\n", i);
		i++;
	}
	return NULL;
}

int main ()
{
	pthread_t newthread;

	pthread_create(&newthread, NULL, philoeat, "une pomme");
	philosleep(0);
	pthread_join(newthread, NULL);
}
