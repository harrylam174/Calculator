CC = c++
CCFLAGS = -std=c++17
EXEC = result
SOURCES = ${wildcard *.cpp}
OBJECTS = ${SOURCES:.cpp=.o}

main: $(OBJECTS)
	$(CC) $(CCFLAGS) $(OBJECTS) -o $(EXEC)

%.o: %.cpp
	$(CC) -c -o $@ $< $(CCFLAGS)

.PHONY: clean
clean:
	rm -f $(EXEC) $(OBJECTS)

