#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <assert.h>

#define BUF_SIZE	255

void urldecode (const char *in, char *out) {
	// zeroes memory, better play it safe
	bzero((void*)out, sizeof(out));
	//while ( *out++ = *in++ )
	while ( *in )
	{
		if ( *in == '%' && isxdigit(*(in+1)) && isxdigit (*(in+2)) )
		{
			// need to fix size because %320 would behave strangely
			char buf[2];
			buf[0] = *(in+1);
			buf[1] = *(in+2);
			sscanf(buf, "%x", out);

			in +=3;
			out += 1;
			continue;
		}
		if ( *in == '+' )
		{
			*out++ = ' ';
			in++;
			continue;
		}
		*out++ = *in++;
	}
}

int main ( int argc, char **argv ) {

	assert(argc > 1 );

	char in[BUF_SIZE];
	char out[BUF_SIZE];

	sprintf(in, "%s", argv[1]);
	printf("in: %s\n", in);
	urldecode(in, out);
	printf("out: %s\n", out);

	return 0;
}
