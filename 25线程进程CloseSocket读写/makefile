

#%.o:%.cpp
#	$(CC) -c $(CFLAFS) $(CPPFLAGS) $< -o $@

#%:%.o
#	$(CC) -o $@ $(CFLAGS) $(CPPFLAGS) $<

CC=g++
CPPFLAGS+= -std=c++11
CPPFLAGS+= -lpthread
LDLIBS=$(CPPFLAGS)

all:app
	@echo $(CFLAGS)
	@echo $(CPPFLAGS)

app:app.o ServerSocket.o Socket.o worker.o Server.o Request.o

app.o:app.cpp

ServerSocket.o:ServerSocket.h

Socket.o:Socket.h

worker.o:worker.h

Server.o:Server.h

Request.o:Request.h

clean:
	-rm -f *.o app
