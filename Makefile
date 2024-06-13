INCLUDE := -I ~/include
LDFLAGS := -L ~/lib -lsense -lm

all: scroll

%.o: %.c scroll.h
	cc -g -c $< $(INCLUDE)

scroll: main.o display.o input.o
	cc -o scroll main.o display.o input.o $(LDFLAGS)

clean:
	rm -f *.o scroll

run: scroll
	./scroll

commit:
	git add .
	git commit -m "Update"
	git push
