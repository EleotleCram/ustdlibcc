
# CXX := g++
CXX := /opt/gcc-4.9.2/bin/g++-4.9
# CXX := /opt/avr-gcc-4.9.2/bin/avr-g++
CPPFLAGS := -std=c++11 -Iinclude/

list:
	@echo "Usage: make <example>"
	@echo ""
	@echo "Available examples:"
	@echo ""
	@ls examples/ | awk -F. '{print "    * "$$1}'
	@echo ""

%: examples/%.cpp
	TMPFILE=$(shell mktemp --tmpdir) ;\
	($(CXX) $(CPPFLAGS) $< -o $${TMPFILE} && $${TMPFILE}) ; rm -f $${TMPFILE}

