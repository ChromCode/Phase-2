all:
	g++ -std=c++14 -w string.cpp main.cpp helperFunctions.cpp label.cpp jumproto.cpp jump.cpp Function.cpp Math.cpp Add.cpp Sub.cpp Div.cpp Mult.cpp Out.cpp jumpgt.cpp jumpz.cpp -o Main
	./Main >> a.out 2> a.err

output:
	open a.out

error:
	open a.err

clean:
	rm -f Main
	rm -f a.out
	rm -f a.err

memCheck:
	valgrind --leak-check=yes ./Main