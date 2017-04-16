CC = gcc
CFLAGS =  -O2 -std=c99
LDFLAGS = 
OBJS = main.o
TARGET = tlv
RM = rm -f

$(TARGET):$(OBJS)
	$(CC) -o $(TARGET) $(OBJS) $(LDFLAGS)

$(OBJS):%o:%c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	$(RM) $(TARGET) $(OBJS)