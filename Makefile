OBJS = Node.o Processor.o Tokenizer.o Board.o
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

run: joseki
	cat simple.sgf | ./out/joseki

super_simple: joseki
	cat super_simple.sgf | ./out/joseki

super_super_simple: joseki
	cat super_super_simple.sgf | ./out/joseki
clean :
	\rm -r $(OBJDIR)

