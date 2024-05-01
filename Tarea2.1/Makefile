CC = gcc
CFLAGS = -Wall
TARGET = FactoryofNumbers
SOURCES = FactoryofNumbers.c Manufactura.c Mundo.c Robot.c
HEADERS = Mundo.h Manufactura.h Io.h Robot.h

$(TARGET): $(SOURCES) $(HEADERS)
	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET)

.PHONY: clean

clean:
	rm -f $(TARGET)