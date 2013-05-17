# necessary
obj-m += hello.o

# convenience
all: 
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

# convenience
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
