#include <stdio.h>
#include <assert.h>

int main (int argc, char **argv) {
		assert(argc==2);

		int val = atoi(argv[1]);

		printf("inserted %d(dec), %lX(hex)\n", val, val);
		printf("value << 2: %d(dec), %lX(hex)\n", val << 2, val << 2);

		return 0;
}

