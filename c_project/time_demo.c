#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	time_t tm;
	char buf[512] = {0};
	struct tm tim, gtm;

	time(&tm);

	printf("time cls %ld\n", tm);

	printf("%s\n", ctime(&tm));
	
	ctime_r(&tm, buf);

	printf("buf = %s\n", buf);

	localtime_r(&tm, &tim);

	printf("second = %d\n", tim.tm_sec);
	printf("localtime_t year = %d\n", tim.tm_year + 1900);

	gmtime_r(&tm, &gtm);
	printf("gmtime year = %d\n", gtm.tm_year + 1900);
	
	time_t sec = mktime(&tim);
	printf("mktime sec = %ld\n", sec);

	memset(buf, 0, sizeof(buf));
	asctime_r(&tim, buf);
	printf("asctime_r buf = %s\n", buf);

	memset(buf, 0, sizeof(buf));
	strftime(buf, sizeof(buf), "%Y-%m-%d", &tim);
	printf("strftime = %s\n", buf);
	return 0;
}
