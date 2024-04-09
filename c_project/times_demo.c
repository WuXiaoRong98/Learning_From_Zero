#include <stdio.h>
#include <stdlib.h>
#include <sys/times.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	struct tms t_buf_s;
	struct tms t_buf_e;
	clock_t t_s;
	clock_t t_e;
	long tck;
	int i, j;

	tck = sysconf(_SC_CLK_TCK);

	t_s = times(&t_buf_s);
	if (t_s < 0) {
		perror("times error");
		exit(-1);
	}


	for (i = 0; i < 2000; i++) {
		for (j = 0; j < 2000; j++) {
			;
		}
	}

	sleep(1);

	t_e = times(&t_buf_e);
	if (t_e < 0) {
		perror("times error");
		exit(-1);
	}
	printf("total time = %f sec\n", (t_e - t_s) / (double)tck);
	printf("user cpu time: %f\n", (t_buf_e.tms_utime - t_buf_s.tms_utime)/(double)tck);
	printf("system cpu time: %f\n", (t_buf_e.tms_stime - t_buf_s.tms_stime)/(double)tck);
	

	return 0;
}
