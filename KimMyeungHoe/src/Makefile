CC = gcc
CFLAGS = -W -Wall -O2
LDFLAGS = -lm

all : Main FileSystemsInfo FilePointFromPopen		
		$(CC) $(CFLAGS) -o Main Main.o FileSystemInfo.o FilePointer.o $(LDFLAGS)
Main : Main.c
		$(CC) $(CFLAGS) -c Main.c

FileSystemsInfo : FileSystemInfo.c
		$(CC) $(CFLAGS) -c FileSystemInfo.c

FilePointFromPopen : FilePointer.c
		$(CC) $(CFLAGS) -c FilePointer.c

clean  :
		@rm -rf *.o Main *~
