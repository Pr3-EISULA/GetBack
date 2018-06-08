CXX = g++ -std=c++11

SOURCES = main.cpp \
	mainMenu.cpp \
	entity.cpp \
	player.cpp \
	fallingRock.cpp \
	flyingBat.cpp \
	Collision.cpp \
	firstFRArea.cpp \
	secondFRArea.cpp \
	FBArea.cpp \
	gameOver.cpp \
	victory.cpp \

OBJECTS = main.o \
	mainMenu.o \
	entity.o \
	player.o \
	fallingRock.o \
	flyingBat.o \
	Collision.o \
	firstFRArea.o \
	secondFRArea.o \
	FBArea.o \
	gameOver.o \
	victory.o \

LIBLINK = -lsfml-graphics -lsfml-window -lsfml-system

TARGET = getBack

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $^ -o $@ $(LIBLINK)

$(OBJECTS): $(SOURCES)
	$(CXX) -c $^

clean:
	$(RM) $(OBJECTS)
