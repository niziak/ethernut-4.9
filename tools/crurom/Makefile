INCLUDES = -I..\include\win32
CFLAGS = -Wall $(INCLUDES)
LDFLAGS= -mwindows

CFLAGS+= -O3
#CFLAGS+= -O0 -g3 -gdwarf-2

#set path=%path%;d:\MinGW\bin
CC = d:\MinGW\bin\gcc.exe
APP = crurom



SRC = crurom.c dirent.c getopt.c
OBJ = $(SRC:.c=.o)
EXE = $(APP).exe


%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<
	
	
all: $(EXE)


clean:
	-$(RM) $(OBJ) $(EXE)

	
	
$(EXE): $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) -o $@

	
	

.PHONY:	all clean
	

