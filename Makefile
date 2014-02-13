ifdef HTSLIB
	ABSPATH=$(shell cd `dirname $(HTSLIB)`; pwd)/$(shell basename $(HTSLIB))
	PARAMS := $(PARAMS) HTSLIB=$(ABSPATH)
endif

ifdef DEBUG
	PARAMS := $(PARAMS) DEBUG=$(DEBUG)
endif

all: tools benchmarks dev

tools:
	cd tools; make $(PARAMS)
benchmarks:
	cd benchmarks; make $(PARAMS)
dev:
	cd dev; make $(PARAMS)

clean:
	cd tools; make clean
	cd benchmarks; make clean
	cd dev; make clean

.PHONY: all clean tools benchmarks dev
