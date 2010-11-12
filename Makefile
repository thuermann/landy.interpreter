#
# $Id: Makefile,v 1.1 2010/11/12 13:08:51 urs Exp $
#

RM = rm -f

programs = slip

.PHONY: all
all: $(programs)

obj = slip.o parser.o stmt.o expr.o symtab.o
slip: $(obj)
	$(CXX) $(LDFLAGS) -o $@ $(obj) $(LDLIBS)

.PHONY: clean
clean:
	$(RM) $(programs) *.o core

slip.o:   parser.h stmt.h expr.h symtab.h
parser.o: parser.h stmt.h expr.h symtab.h
stmt.o:   stmt.h expr.h symtab.h
expr.o:   expr.h symtab.h
symtab.o: symtab.h
