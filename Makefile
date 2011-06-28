#
# $Id: Makefile,v 1.2 2011/06/28 20:41:09 urs Exp $
#

RM    = rm -f
BISON = bison

programs = slip

.PHONY: all
all: $(programs)

obj    = slip.o parser.o parse.tab.o scan.o stmt.o expr.o symtab.o
LDLIBS = -ll
slip: $(obj)
	$(CXX) $(LDFLAGS) -o $@ $(obj) $(LDLIBS)

parse.tab.cc parse.tab.hh: parse.yy
	$(BISON) -d $<

scan.cc: scan.l
	$(LEX) -t $< > $@

parser.o: parse.tab.hh

.PHONY: clean
clean:
	$(RM) $(programs) *.o core parse.tab.cc parse.tab.hh scan.cc

slip.o:   parser.h stmt.h expr.h symtab.h
parser.o: parser.h stmt.h expr.h symtab.h
stmt.o:   stmt.h expr.h symtab.h
expr.o:   expr.h symtab.h
symtab.o: symtab.h

parse.tab.o: stmt.h expr.h symtab.h
scan.o:      stmt.h expr.h symtab.h parse.tab.hh
