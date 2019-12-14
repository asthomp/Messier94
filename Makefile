#Code adapted from Harlan James's (waldroha@oregonstate.edu) example.

#Project Name
PROJECT = Messier94

#Compiler
${CXX} = g++

#Source Files
SRCS = main.cpp
SRCS += menu.cpp
SRCS += intro.cpp
SRCS += battery.cpp
SRCS += Inventory.cpp
SRCS += Game.cpp
SRCS += Board.cpp
SRCS += Space.cpp
SRCS += Artifact.cpp
SRCS += Field.cpp
SRCS += Meadow.cpp
SRCS += Forest.cpp
SRCS += Ship.cpp

#Create an object for each source file.

OBJECT = ${SRCS:.cpp=.o}

#Compiler Flags
CFLAGS = -Wall -pedantic -std=c++11

#Valgrind Options

VOPT = --tool=memcheck --leak-check=full --show-leak-kinds=all


#A rule that keeps the makefile from looking for a file named
#"default" or "debug" etc. It lets actions be performed without
#attempting to check if a file is present or updated.

.PHONY: default debug clean zip

#The default behavior is to remove everything (clean a.k.a start from scratch), compile the executable,
#and then run it through valgrind.

default: clean ${PROJECT} debug

#On project, use Valgrind on the file found at this path
debug: ${PROJECT}
	@valgrind ${VOPT} ./${PROJECT}

#REMEMBER THESE KEYWORDS:
# @ suppresses command from terminal
# $@ is the name of the target
# $^ is the name of the dependency
# % is a wildcard
#./ means run the thing in the current directory (to run a file, need a path)

${PROJECT}: ${OBJECT}
	@echo "CC	All objects to $@"
	@${CXX} ${CFLAGS} $^ -o $@

%.o: %.cpp
	@echo "CC	$^ to $@"
	@${CXX} ${CFLAGS} -c $^

zip:
	zip Messier94_Thompson_Aaron.zip *.cpp *.hpp *.txt Makefile

clean: ${CLEAN}
	@echo "RM	*.o"
	@echo "RM	${PROJECT}"
	@rm -f *.o ${PROJECT}



