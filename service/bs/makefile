cc = g++
flags = -Wall -fPIC
#flags = -g -Wall -fPIC
inc = -I../frame -I../common -I../hiredis
lib = -pthread -ldl -L../common -lcommon -L../hiredis -L./ -lhiredis

bs_srcs = bs.cpp redis_handler.cpp
bs_objs = $(patsubst %cpp,%o,$(bs_srcs))
target= bs.so

all : $(target)

bs.so : $(bs_objs)
	$(cc) $(bs_objs) $(lib) -Wl,-E -shared -fPIC -o $@

%.o : %.cpp
	$(cc) $(flags) -I../frame -I../common -I../hiredis -c $< -o $@

clean:
	rm -f *.o $(target)

