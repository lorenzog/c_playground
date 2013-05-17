enum directions_e { dx, up, sx, dn } direction;

	int main (int argc, char **argv) {
		int len = atoi(argv[1]);
		int offset = 2*len-1;
		int size = offset*offset;
		char *matrix = malloc(size);
		int startfrom = 2*len*(len-1);
		matrix[startfrom] = 1;
		int next = startfrom;

		int count = 1;
		int i, step = 1;
		direction = dx ;

		for (;; step++ )
			do { 
				for ( i = 0 ; i < step ; i++ ) {
					switch ( direction ) {
						case dx:
							next++;
							break;
						case up:
							next = next - offset;
							break;
						case sx:
							next--;
							break;
						case dn:
							next = next + offset;
					}
					int div = ++count;
					do {
						div--;
					} while ( count % div );
					if ( div > 1 ) {
						matrix[next] = ' ';
					}
					else { 
						matrix[next] = '*';
					}
					if (count >= size) goto dontusegoto;
				}
				direction = ++direction % 4;
			} while ( direction %2);
dontusegoto:
		for ( i = 0 ; i < size ; i++ ) {
			putchar(matrix[i]);
			if ( !((i+1) % offset) ) putchar('\n'); 
		}
		return 0;
	}
