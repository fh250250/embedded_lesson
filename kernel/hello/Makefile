KERNELDIR=/lib/modules/3.13.0-39-generic/build

all:
	make -C ${KERNELDIR} M=`pwd` modules

clean:
	make -C ${KERNELDIR} M=`pwd` clean

obj-m = hello.o
