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
	$(BUILD)/animal.o \
	$(BUILD)/animal_repr.o \
	$(BUILD)/vcpu.o \
	$(BUILD)/vcpu_repr.o \
	$(BUILD)/unitvarstruct.o \
	$(BUILD)/unitvarstruct_repr.o \
	$(BUILD)/instructionsequence.o \
	$(BUILD)/instructionsequence_repr.o \
	$(BUILD)/basic_func.o \
	$(BUILD)/advanced_func.o

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
	
#$(BUILD)/cpu.o: $(DEPS) \
#	$(SRC)/cpu.c
#	$(CC) -c $(CFLAGS) -fPIC $(INCS) -o $(BUILD)/cpu.o $(SRC)/cpu.c

$(BUILD)/demorec.o: $(DEPS) \
	$(SRC)/demorec.c
	$(CC) -c $(CFLAGS) -fPIC $(INCS) -o $(BUILD)/demorec.o $(SRC)/demorec.c
	
$(BUILD)/animal.o: $(DEPS) \
	$(SRC)/animal.c
	$(CC) -c $(CFLAGS) -fPIC $(INCS) -o $(BUILD)/animal.o $(SRC)/animal.c
	
$(BUILD)/animal_repr.o: $(DEPS) \
	$(SRC)/animal_repr.c
	$(CC) -c $(CFLAGS) -fPIC $(INCS) -o $(BUILD)/animal_repr.o $(SRC)/animal_repr.c
	
$(BUILD)/vcpu.o: $(DEPS) \
	$(SRC)/vcpu.c
	$(CC) -c $(CFLAGS) -fPIC $(INCS) -o $(BUILD)/vcpu.o $(SRC)/vcpu.c
	
$(BUILD)/vcpu_repr.o: $(DEPS) \
	$(SRC)/vcpu_repr.c
	$(CC) -c $(CFLAGS) -fPIC $(INCS) -o $(BUILD)/vcpu_repr.o $(SRC)/vcpu_repr.c
	
$(BUILD)/unitvarstruct.o: $(DEPS) \
	$(SRC)/unitvarstruct.c
	$(CC) -c $(CFLAGS) -fPIC $(INCS) -o $(BUILD)/unitvarstruct.o $(SRC)/unitvarstruct.c
	
$(BUILD)/unitvarstruct_repr.o: $(DEPS) \
	$(SRC)/unitvarstruct_repr.c
	$(CC) -c $(CFLAGS) -fPIC $(INCS) -o $(BUILD)/unitvarstruct_repr.o $(SRC)/unitvarstruct_repr.c
	
$(BUILD)/instructionsequence.o: $(DEPS) \
	$(SRC)/instructionsequence.c
	$(CC) -c $(CFLAGS) -fPIC $(INCS) -o $(BUILD)/instructionsequence.o $(SRC)/instructionsequence.c
	
$(BUILD)/instructionsequence_repr.o: $(DEPS) \
	$(SRC)/instructionsequence_repr.c
	$(CC) -c $(CFLAGS) -fPIC $(INCS) -o $(BUILD)/instructionsequence_repr.o $(SRC)/instructionsequence_repr.c
	
$(BUILD)/basic_func.o: $(DEPS) \
	$(SRC)/basic_func.c
	$(CC) -c $(CFLAGS) -fPIC $(INCS) -o $(BUILD)/basic_func.o $(SRC)/basic_func.c
	
$(BUILD)/advanced_func.o: $(DEPS) \
	$(SRC)/advanced_func.c
	$(CC) -c $(CFLAGS) -fPIC $(INCS) -o $(BUILD)/advanced_func.o $(SRC)/advanced_func.c

clean:
	rm -rf $(BUILD)
	rm -rf $(LIB)

prebuild:
	test -d $(BUILD) || mkdir -p $(BUILD)
	test -d $(LIB) || mkdir -p $(LIB)
	
install: 
	ldconfig
