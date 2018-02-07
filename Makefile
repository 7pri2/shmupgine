.SUFFIXES:
# directories
OBJ=obj/
HEADERS=include/
SRC=src/
LIB=lib/
TESTS=tests/

CXX=g++
CXXFLAGS=-Wall -Werror -Wextra -std=c++11 -pedantic-errors -I$(HEADERS)
LDFLAGS=-L$(LIB) -lshmupgine -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
DEBUG=-g

EXECUTABLES=$(TESTS)demo
LIBS=libshmupgine.a
OBJFILES=systems.o		\
	  entity.o			\
	  graphicrenderer.o	\
	  gmanager.o		\
	  physics.o			\
	  scene.o			\
	  controls.o		\
	  attribute.o		\
	  destructor.o		\
	  spawner.o			\
	  debug.o			\
	  soundmanager.o	\
	  movement.o
OBJS=$(patsubst %,$(OBJ)%,$(OBJFILES))

all: executables libs

debug: CXXFLAGS+=$(DEBUG) -DDEBUG
debug: all

executables: $(EXECUTABLES)
libs: $(patsubst %,$(LIB)%,$(LIBS))


$(TESTS)demo: $(TESTS)demo.cpp $(HEADERS)shmupgine.h $(LIB)libshmupgine.a
	$(CXX) $(CXXFLAGS) $< -o $@ $(LDFLAGS)

$(LIB)libshmupgine.a: $(OBJS)
	ar -cr $@ $^ 

$(OBJ)bullet.o: $(HEADERS)graphicrenderer.h $(HEADERS)physics.h
$(OBJ)physics.o: $(HEADERS)systems.h $(HEADERS)entity.h
$(OBJ)scene.o: $(HEADERS)systems.h $(HEADERS)entity.h
$(OBJ)controls.o: $(HEADERS)entity.h
$(OBJ)attribute.o: $(HEADERS)entity.h
$(OBJ)destructor.o: $(HEADERS)entity.h $(HEADERS)scene.h
$(OBJ)spawner.o: $(HEADERS)entity.h $(HEADERS)scene.h

$(OBJ)%.o:	$(SRC)%.cpp $(HEADERS)%.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)*.o
	rm $(EXECUTABLES)
	rm $(patsubst %,$(LIB)%,$(LIBS))
