.PHONY: all clean depend

CXX = g++
CXXFLAGS = -std=c++14 -O2 -g
INCLUDE = -I../common
LDFLAGS =
LIBS =

OBJDIR = ./build
SRCS = $(wildcard *.cpp)
DEPS = $(SRCS:%=$(OBJDIR)/%.dep)
OBJS = $(SRCS:%.cpp=$(OBJDIR)/%.o)

MAKEDEPEND = mkdir -p $(OBJDIR); \
			    rm -f $@.dep; \
				$(CXX) $(INCLUDE) $(CXXFLAGS) -MM $^ -MF $@.dep; \
				sed -i 's|^\(.*\.o\)|$(OBJDIR)/\1|g' $@.dep;

all: run

-include $(DEPS)

run: $(OBJS)
	@$(CXX) -o $@ $^ $(LDFLAGS) $(LIBS)

$(OBJDIR)/%.o: %.cpp
	@$(MAKEDEPEND)
	@$(CXX) -c $< -o $@ $(CXXFLAGS) $(INCLUDE)

clean:
	@rm -rf ./run $(OBJDIR)
