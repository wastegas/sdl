CXX	=	c++
FRAMEWORK_PATH=/Library/Frameworks
INCLUDES=-I/Library/Frameworks/SDL2.Framework/Headers/
CXXFLAGS=-std=c++14	$(INCLUDES)	-F$(FRAMEWORK_PATH)	-framework	SDL2	-framework	Cocoa	-Wall	-g
LXXDFLAGS=-stdlib=libc++
SRCDIR=./src
OBJDIR=./obj
BINDIR=./build
TARGET=$(BINDIR)/sdlwindow
vpath	%.c	./src


$(TARGET):	$(SRCDIR)/main.cc
	$(CXX)	$(CXXFLAGS)	$(LXXDFLAGS)	-o	$@	$^

_OBJS=	main.o

OBJS=	$(patsubst %,$(OBJDIR)/%,$(_OBJS))

$(OBJDIR)/%.o:	$(SRCDIR)/%.cc
	$(CXX)	$(CXXFLAGS)	$(LXXDFLAGS)	-c	-o	$@	$<


clean:
	rm	-f	$(OBJDIR)/*.o	$(BINDIR)/*
