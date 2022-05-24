# OPTIONS
CC      := mpicc
CFLAGS  := -O3

# RULES
serial : serial.c
	$(CC) $(CFLAGS) -o $@ $^ 

para1 : parallel1.c
	$(CC) $(CFLAGS) -o $@ $^

para2 : parallel2.c
	$(CC) $(CFLAGS) -o $@ $^

para3 : parallel3.c
	$(CC) $(CFLAGS) -o $@ $^

# Useful phony targets
.PHONY: 
clean :
	rm -rf serial para1 para2 para3

# EOF
