OBJS = neologcat.o
CXXFLAGS = -Wall
CXX = g++

neologcat: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)