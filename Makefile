CC=clang++
#CC=g++
CFLAGS+= -std=c++11 #-g -O0 -Wall -pedantic -I./ -I./include

#STRINGFIX = -lXext -lX11
STRINGFIX = -lXext -lX11 -L/usr/lib/nvidia-340-updates
GLUT2 = -lGL -lGLU -lglut -lpthread
#GLUI2 = -L./src/lib -lglui
LIBS = $(STRINGFIX) $(GLUT2) #$(GLUI2)

PROD= Voxelizer

#HDRS= $(shell ls *.h)
SRCS= $(shell ls *.cpp)

OBJS= $(patsubst %.cpp, %.o, $(SRCS))

all: $(PROD)

$(OBJS): %.o: %.cpp
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $(INCLUDES) $< -o $@ #$(LIBGL) #$(LIBGLUT) $(LIBGL) $(LIBS)

$(PROD): $(OBJS)
	$(CC) -o $(PROD) $^ $(LIBS)

clean:
	rm -f $(PROD)
	rm -f *.o
