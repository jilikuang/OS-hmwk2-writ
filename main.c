#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

#define ITER_DEFAULT	(1000000)

#define TIMEDIFF(t0,t1)	\
	((t1.tv_sec * 1000 + t1.tv_usec) - \
	 (t0.tv_sec * 1000 + t0.tv_usec))

int getxid(void)
{
	return 0;
}

int main(int argc, char *argv[])
{
	int i, iter;
	int retval;
	struct timeval t0, t1;
	char *exit;

	/* Get iteration number */
	if (argc > 1)
		iter = strtol(argv[1], &exit, 10);
	else
		iter = ITER_DEFAULT;

	printf("Iteration: %d\n", iter);
	/* Check getpid() */
	retval = gettimeofday(&t0, NULL);
	for (i = 0; i < iter; i++)
		retval = getpid();
	retval = gettimeofday(&t1, NULL);
	printf("%d-time getpid(): %ld msec\n", iter, TIMEDIFF(t0, t1));

	/* Check getpid() */
	retval = gettimeofday(&t0, NULL);
	for (i = 0; i < iter; i++)
		retval = getxid();
	retval = gettimeofday(&t1, NULL);
	printf("%d-time getxid(): %ld msec\n", iter, TIMEDIFF(t0, t1));

	return 0;
}
