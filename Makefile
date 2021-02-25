CXX	= g++
CXXFLAGS = -Wall

OBJDIR = obj
SRCDIR = src
PLATFORM := $(shell uname)

ifeq  ($(PLATFORM),Linux)
BIN = neologcat
else
BIN = neologcat.exe
endif
SRC	= $(wildcard src/*.cpp)
_OBJS = $(subst src, obj, $(SRC))
OBJS = $(patsubst %.cpp,%.o,$(_OBJS))

.PHONY: all
all: $(BIN)

$(BIN): $(OBJS)
	$(CXX) $(OBJS) -o $(BIN)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(OBJDIR)
	$(CXX) $(CXXFLAGS)  -o $@ -c $< 

$(OBJDIR):
	mkdir $(OBJDIR)
