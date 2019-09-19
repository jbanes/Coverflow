CC = mipsel-linux-g++
CFLAGS += -DPC_VERSION -DRES320X240 `sdl-config --cflags`

all: main
main : main.cpp
	$(CC) -lSDL -lSDL_gfx -lSDL_mixer -lSDL_image -lSDL_ttf -o coverflow main.cpp FileHandler.cpp CoverFlowOnScreen.cpp Configuration.cpp Helper.cpp CTime.cpp Screen.cpp
	./package
.c.o: 
	$(CC) $(CFLAGS) -c $*.c -o $*.o 

clean:
	rm -rf *.o
	rm -rf main 
	rm -rf *~

.PHONY: clean main
