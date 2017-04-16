CC = gcc
CFLAGS =  -O2 -std=c99
LDFLAGS = 
OBJS = main.o
TARGET = tlv
RM = rm -f
OUT_DIR=build/

$(TARGET):$(OBJS)
	$(CC) -o  $(OUT_DIR)$(TARGET)  $(OUT_DIR)$(OBJS) $(LDFLAGS)

$(OBJS):%o:%c
	$(CC) -c $(CFLAGS) $< -o $(OUT_DIR)$@

clean:
	$(RM) $(OUT_DIR)$(TARGET) $(OUT_DIR)$(OBJS)