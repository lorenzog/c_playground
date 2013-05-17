#include <sys/types.h>
#include <sys/stat.h>

main(int argc, char *argv[]) {
	return ( mknod(argv[2], S_IFDIR, 0) );
}
