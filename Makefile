CC = gcc
CFLAGS = -c -o
TARGET = network

$(TARGET) : KISA_SHA256.o main.o
	$(CC) -o $(TARGET) KISA_SHA256.o main.o
KISA_SHA256.o : KISA_SHA256.c
	$(CC) $(CFLAGS) KISA_SHA256.o KISA_SHA256.c
main.o : main.c
	$(CC) $(CFLAGS) main.o main.c
clean :
	rm  *.o network
