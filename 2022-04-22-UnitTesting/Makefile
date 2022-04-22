SHELL:=/bin/bash

all: factorial_main.x

test: factorial_test.x
	./$<

%.x: %.o factorial.o
	source $$HOME/repos/spack/share/spack/setup-env.sh; \
	spack load catch2; \
	g++ $$(pkg-config --cflags catch2) $^ -o $@

%.o: %.cpp
	source $$HOME/repos/spack/share/spack/setup-env.sh; \
	spack load catch2; \
	g++ $$(pkg-config --cflags catch2) -c $<

clean:
	rm -f *.o *.x
