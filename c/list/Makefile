all:list.c test_list.c
	gcc -c $^

clean:
	rm *.o test

test:list.c test_list.c
	gcc -o $@ $^ -lcunit