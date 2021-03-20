CC = gcc
LINK = $(CC)
STRIP = strip

SRC = ./src/c
BUILD = ./objs
LIB = ./lib

CFLAGS      = -g -O2 $$(python3-config --includes --ldflags) -Wincompatible-pointer-types
CSAHREDLIBS = -shared

INCS = -I$(SRC) 

DEPS = $(SRC)/test.h 

OBJS = $(BUILD)/test.o \
	$(BUILD)/demorec.o \
	$(BUILD)/demorec_func.o \
	$(BUILD)/basic_func.o

BINS = $(BUILD)/testmod.so

BINS2 = testmod.so 

all: prebuild \
	$(BINS)

$(BUILD)/testmod.so: \
	$(OBJS)
	$(CC) $(CFLAGS) $(CSAHREDLIBS) -o $(LIB)/testmod.so $(OBJS)
	$(STRIP) --strip-unneeded $(LIB)/testmod.so

$(BUILD)/test.o: $(DEPS) \
	$(SRC)/test.c
	$(CC) -c $(CFLAGS) -fPIC $(INCS) -o $(BUILD)/test.o $(SRC)/test.c

$(BUILD)/demorec.o: $(DEPS) \
	$(SRC)/demorec.c
	$(CC) -c $(CFLAGS) -fPIC $(INCS) -o $(BUILD)/demorec.o $(SRC)/demorec.c
	
$(BUILD)/demorec_func.o: $(DEPS) \
	$(SRC)/demorec_func.c
	$(CC) -c $(CFLAGS) -fPIC $(INCS) -o $(BUILD)/demorec_func.o $(SRC)/demorec_func.c
	
$(BUILD)/basic_func.o: $(DEPS) \
	$(SRC)/basic_func.c
	$(CC) -c $(CFLAGS) -fPIC $(INCS) -o $(BUILD)/basic_func.o $(SRC)/basic_func.c		

clean:
	rm -rf $(BUILD)
	rm -rf $(LIB)

prebuild:
	test -d $(BUILD) || mkdir -p $(BUILD)
	test -d $(LIB) || mkdir -p $(LIB)
	
install: 
	ldconfig
