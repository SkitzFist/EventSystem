CXX = g++
TARGET = EventSystem

OBJDIR := obj/
DEPDIR := $(OBJDIR)deps/

SRCS := $(wildcard *.cpp)
HEADERS := $(wildcard *.h)

OBJS := $(SRCS:%.cpp=$(OBJDIR)%.o)
DEPS := $(SRCS:%.cpp=$(DEPDIR)%.d)

$(TARGET) : $(HDS) $(OBJS)
	$(CXX) $^ -o $@

$(OBJDIR)%.o : %.cpp $(DEPDIR)%.d | $(DEPDIR)
	$(CXX) -MMD -MT $@ -MP -MF $(DEPDIR)$*.d -o $@ -c $<

$(DEPS):

clean:
	del obj\*.o
	del obj\deps\*.d

fullClean: clean
	del *.exe

include $(wildcard $(DEPS))