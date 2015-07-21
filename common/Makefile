.PHONY: all clean depend

CXX = g++
CXXFLAGS = -std=c++14 -O2 -g
SRCS = $(find . -type f -iname \*.cpp)

depend: .depend

.depend: $(SRCS)
	rm -f ./.depend
	$(CXX) $(CXXFLAGS) -MM $^ -MF ./.depend

include .depend
