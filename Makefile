OBJS = 
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)
OBJDIR=out

all: joseki

joseki : $(OBJS) $(OBJDIR)
	$(CC) $(LFLAGS) Joseki.cc $(OBJS) -o $(OBJDIR)/joseki

$(OBJDIR)/%.o : %.cpp $(OBJDIR)
	$(CC) $(CFLAGS) -o $(OBJDIR)/$@ $<

$(OBJDIR) :
	mkdir $(OBJDIR)

clean :
	\rm -r $(OBJDIR)

