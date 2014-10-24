CC=g++
CPPFLAGS=-g -O2 -Wall -Wextra -Isrc -rdynamic -Iinclude/ -fPIC
LDFLAGS=

SRC_DIR=src
RUN_DIR=run

LIBD_DIR=lib
RUND_DIR=bin

NAME=vm

VPATH=src

LIB_SOURCES=$(wildcard $(SRC_DIR)/**/*.cpp $(SRC_DIR)/*.cpp)
LIB_OBJECTS=$(patsubst %.cpp,%.o,$(LIB_SOURCES))

RUN_SOURCES=$(wildcard $(RUN_DIR)/**/*.cpp $(RUN_DIR)/*.cpp)
RUN_OBJECTS=$(patsubst %.cpp,%.o,$(RUN_SOURCES))

TARGET_EX=$(RUND_DIR)/$(NAME)
TARGET_A=$(LIBD_DIR)/lib$(NAME).a
TARGET_SO=$(LIBD_DIR)/lib$(NAME).so

all: exec lib
exec: $(TARGET_EX)
lib: $(TARGET_SO) $(TARGET_A)

main.o: main.cpp

$(TARGET_EX): $(LIB_OBJECTS) $(RUN_OBJECTS) run_dir
	$(CC) -o $@ $(LDFLAGS) $(CPPFLAGS) $(LIB_OBJECTS) $(RUN_OBJECTS)

$(TARGET_A): $(LIB_OBJECTS) lib_dir
	ar rcs $@ $(LIB_OBJECTS)

$(TARGET_SO): LDFLAGS += -shared
$(TARGET_SO): $(LIB_OBJECTS) lib_dir
	$(CC) -o $@ $(LDFLAGS) $(CPPFLAGS) $(LIB_OBJECTS)

lib_dir:
	@mkdir -p $(LIBD_DIR)
run_dir:
	@mkdir -p $(RUND_DIR)
.PHONY:
clean:
	@$(RM) -r $(LIBD_DIR) $(RUND_DIR) $(LIB_OBJECTS) $(RUN_OBJECTS)