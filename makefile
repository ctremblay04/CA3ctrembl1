# Specifiy the target
all:	LLC

# Specify the object files that the target depends on
# Also specify the object files needed to create the executable
LLC:	LLC.o main.o
	g++  LLC.o main.o -o LLC

# Specify how the object files should be created from source files
LLC.o:	LLC.cpp
	g++ -g -Wall -c LLC.cpp

main.o:	main.cpp
	g++ -g -Wall -c main.cpp

# Specify the object files and executables that are generated
# and need to be removed to re-compile the whole thing
clean:
	rm -f *.o LLC
