CC = gcc
CFLAGS = -c -o
TARGET = network

$(TARGET) : KISA_SHA256.o find.o
	$(CC) -o $(TARGET) KISA_SHA256.o find.o
KISA_SHA256.o : KISA_SHA256.c
	$(CC) $(CFLAGS) KISA_SHA256.o KISA_SHA256.c
find.o : find.c
	$(CC) $(CFLAGS) find.o find.c
clean :
	rm  *.o network
