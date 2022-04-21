all: factorial_main.x

test: factorial_test.x
	./$<

factorial_main.x: factorial_main.o factorial.o
	g++ $^ -o $@
factorial_test.x: factorial_test.o factorial.o
	g++ $^ -o $@

# The previous two rules can be summarized as 
%.x: %.o factorial.o
	g++ $^ -o $@

%.o: %.cpp
	g++ -c $<

clean:
	rm -f *.o *.x
