.PHONY: all common clean depend

CXX = g++
CXXFLAGS = -std=c++14 -O2 -g
INCLUDE = -I../common
LDFLAGS =
LIBS = -lgmp

OBJDIR = ./build
SRCS = $(wildcard *.cpp)
DEPS = $(SRCS:%=$(OBJDIR)/%.dep)
OBJS = $(SRCS:%.cpp=$(OBJDIR)/%.o)

MAKEDEPEND = mkdir -p $(OBJDIR); \
			    rm -f $@.dep; \
				$(CXX) $(INCLUDE) $(CXXFLAGS) -MM $^ -MF $@.dep; \
				sed -i 's|^\(.*\.o\)|$(OBJDIR)/\1|g' $@.dep;

all: common run

common:
	@cd ../common; make objs

-include $(DEPS)

run: $(OBJS) ../common/build/primes.o
	@$(CXX) -o $@ $^ $(LDFLAGS) $(LIBS)

$(OBJDIR)/%.o: %.cpp
	@$(MAKEDEPEND)
	@$(CXX) -c $< -o $@ $(CXXFLAGS) $(INCLUDE)

clean:
	@cd ../common; make clean
	@rm -rf ./run $(OBJDIR)
