CXX = $(shell wx-config --cxx) # C++ compiler
CXXFLAGS = -g -Wall -I include/ # C++ compiler flags
WXCXXFLAGS = $(shell wx-config --cxxflags) # wxWidgets C++ compiler flags
WXLIBS = $(shell wx-config --libs) # wxWidgets libraries

TARGET = WrestlingScheduler # Target name, output file

SRCS = $(shell find src/ -name "*.cpp") # Source files to build (all src/*.cpp)
OBJS = $(patsubst src/%.cpp, obj/%.o, $(SRCS)) # Object files to build (source files with .o extension)

all: $(TARGET) # Target to build everything, depends on TARGET

$(TARGET): $(OBJS) # Target to build, depends on OBJS
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET) $(WXLIBS)

obj/%.d: %.cpp # Build dependency file for object file
	$(CXX) -MM -MT -o $@ $(CXXFLAGS) $<

obj/%.o: src/%.cpp # Build object file for source file
	$(CXX) $(CXXFLAGS) $(WXCXXFLAGS) -c -o $@ $<

clean: # Target to clean up, removes all object files
	$(RM) $(OBJS)

dist-clean: clean # Target to clean up everything, runs the clean target and then removes the output file
	$(RM) $(TARGET)
