CC = gcc
CFLAGS = -Wall -std=c11

SRC = main.c resolver.c \
	  validation/validation.c \
	  dns_resolution/dns_resolution.c \
	  ip_resolution/ip_resolution.c

OBJ = $(SRC:.c=.o)
TARGET = resolver

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)