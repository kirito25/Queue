Objs = queue.o
Exec = test_queue 

test_queue: test_queue.c queue.o 
	$(CC) -o test_queue test_queue.c queue.o

queue.o: queue.c queue.h
	$(CC) -c queue.c

clean:
	rm -f $(Objs) $(Exec)
