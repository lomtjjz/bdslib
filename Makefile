CC?=gcc
CCFLAGS?=-Wall -Wextra -O3

TARGET=bdslib.a
SRCS=$(wildcard bds/*.c)
OBJS=$(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	ar -r $(TARGET) $(OBJS)

%.o: %.c
	$(CC) $(CCFLAGS) -c $^ -o $@

clean:
	rm $(TARGET) $(OBJS)

.PHONY: all clean