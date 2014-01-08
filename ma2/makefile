all: myapp

myapp: suan.o jia.o jian.o
	$(CC) $(CFLAGS) -o myapp suan.o jia.o jian.o
suan.o: suan.cpp
	$(CC) $(CFLAGS) -o suan.o -c suan.cpp
jia.o: jia.h
	$(CC) $(CFLAGS) -o jia.o -c jia.cpp
jian.o: jian.h
	$(CC) $(CFLAGS) -o jian.o -c jian.cpp
