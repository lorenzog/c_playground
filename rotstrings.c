/**
 * http://stackoverflow.com/q/2553522/204634
 *
Given two string s1 and s2 how will you check if s1 is a rotated version of s2 ?

Example:

If s1 = "stackoverflow" then the following are some of its rotated versions:

"tackoverflows"
"ackoverflowst"
"overflowstack"

where as "stackoverflwo" is not a rotated version.

 *
 */

#include <string.h>
#include <assert.h>
#include <stdio.h>

int main (int argc, char **argv) {
	if ( argc != 3 ) 
		return -1;

	char* s1 = argv[1];
	char* s2 = argv[2];

	printf("s1: %s (len: %zd)\n", s1, strlen(s1));

	size_t length = strlen(s1);
	assert (length == strlen(s2));
	int offset = 0;
	char* cur;

	while ( offset < length ) {
		cur = s1 + offset;
		printf("current string: %s\n", cur);
		// find first occurrence of s2 in s1
		char* first = strchr(cur, s2[0]);
		if ( first == NULL ) {
			printf("no can do\n");
			return -1;
		}

		// where does it start
		size_t delta = strlen(cur) - strlen(first);
		printf("first occurrency of `%c' in `%s' is at %zd\n", s2[0], cur, delta);
		
		printf("looking for `%s' in `%s'\n", cur+delta, s2);
		char *match = strstr(s2, cur + delta);
		if ( match == NULL ) {
			offset += delta+1;
			printf("not found; will start looking from %d\n\n", offset);
			continue;
		}
		match = strstr(s2 + delta, s1);
		if ( match == NULL ) {
			printf("match!\n");
			return 0;
		}
		else
		{
			printf("does not match\n");
			return 1;
		}
	}
}
