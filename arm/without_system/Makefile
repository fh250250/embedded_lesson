all:
	arm-linux-gcc -c $(NAME).s -o $(NAME).o
	arm-linux-ld -Ttext=50003000 $(NAME).o -o $(NAME)
	arm-linux-objcopy -I elf32-littlearm -O binary $(NAME) $(NAME).bin
	rm $(NAME).o $(NAME)
