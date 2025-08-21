#include <stdio.h>
#include <sys/time.h>
#include <immintrin.h>
#include "../lib.h"

int main() {
	unsigned long hundredMegs = 37500000; /* Actually 300MB now */
	unsigned long *array = malloc(hundredMegs * 8);
	unsigned long i;
	unsigned long j;
	unsigned long last;
	float *output = malloc(hundredMegs * 4);
	double duration;
	double whatever;
	struct timeval stop, start;

	gettimeofday(&start, NULL);
	for (i = 0; i < hundredMegs; i++) {
		array[i] = _rdtsc();
	}
	gettimeofday(&stop, NULL);
	duration = (double)((stop.tv_sec - start.tv_sec) * 1000000 + stop.tv_usec - start.tv_usec);
	whatever = 1000000.0 / (duration / (double)hundredMegs);
	printf("Took %f microseconds\n", duration);
	printf("Samplerate: %f hz\n", whatever);

	j = 0;
	last = 0;
	for (i = 0; i < hundredMegs; i++) {
		output[j] = (float)(array[i] - last) / 50.0F;
		last = array[i];
		j += 1;
	}

	write_data_to_file("output.raw", output, hundredMegs * 4);

	free(array);
	free(output);
	return 0;
}
