all: statinfo.c
	gcc -o "stt" statinfo.c
run: all
	./stt
	make clean
clean:
	rm stt