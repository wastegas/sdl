CXX	=	c++
FRAMEWORK_PATH=/Library/Frameworks
INCLUDES=-I/Library/Frameworks/SDL2.Framework/Headers/	-I./
CXXFLAGS=-std=c++14	$(INCLUDES)	-F$(FRAMEWORK_PATH)	-framework	SDL2	-framework	Cocoa	-Wall	-g
LXXDFLAGS=-stdlib=libc++
SRCDIR=src
OBJDIR=obj
BINDIR=build
TARGET=$(BINDIR)/sdlwindow
vpath	%.c	./src

all:	$(TARGET)

_OBJS=	main.o	\
	app.o

OBJS=	$(patsubst %,$(OBJDIR)/%,$(_OBJS))

$(OBJDIR)/%.o:	$(SRCDIR)/%.cc
	$(CXX)	$(CXXFLAGS)	$(LXXDFLAGS)	-c	-o	$@	$<

$(TARGET):	$(OBJS)
	$(CXX)	$(CXXFLAGS)	$(LXXDFLAGS)	-o	$@	$^

clean:
	rm	-rf	$(OBJDIR)/*.o	$(BINDIR)/*
