CC=g++
CPPFLAGS=-g -O2 -Wall -Wextra -Isrc -rdynamic
LDFLAGS=
NAME=vm

VPATH=src

SOURCES=$(wildcard src/**/*.cpp src/*.cpp)
OBJECTS=$(patsubst %.cpp,%.o,$(SOURCES))

TARGET_EX=bin/$(NAME)

all: exec
exec: $(TARGET_EX)

main.o: main.cpp

$(TARGET_EX): $(OBJECTS) build
	$(CC) -o $@ $(LDFLAGS) $(CPPFLAGS) $(OBJECTS)

build:
	@mkdir -p bin

.PHONY:
clean:
	@$(RM) -r bin $(OBJECTS)