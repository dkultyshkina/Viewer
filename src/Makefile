CC=gcc -Wall -Werror -Wextra
SRC=3DViewer.c
PFLAGS=$(shell pkg-config --libs --cflags check)
OBJ=3DViewer.o

all: gcov_report

gcov_report:
	$(CC) --coverage ../tests/test.c $(SRC) $(TLIBS) -o gcov_test $(PFLAGS)
	./gcov_test
	gcovr -r . --html --html-details -o report_3DViewer.html
	open ./report_3DViewer.html

3DViewer.a:
	$(CC) -c $(SRC) $(PFLAGS)
	ar rcs 3DViewer.a $(OBJ)

tests: 3DViewer.a
	$(CC) -c $(SRC) -o $(OBJ) $(PFLAGS)
	$(CC) ../tests/test.c 3DViewer.a $(TLIBS) -o test $(PFLAGS)
	./test

clean:
	rm -rf QtFiles/moc_* *.o *.css QtFiles/.DS_Store .DS_Store *.html *.gcda *.gcno *.a test QtFiles/.qm QtFiles/*.o Archive_3DViewer.tgz QtFiles/.qmake.stash QtFiles/*.qrc QtFiles/3DViewer.app test_output gcov_test report build/ 
	
html:
	open ../documentation/html/annotated.html

install: 
	rm -rf build
	mkdir build
	cd QtFiles && qmake && make && mv 3DViewer.app ../build && cd ..

uninstall:
	rm -rf build*
	rm -rf qt_files/moc*
	rm -rf qt_files/*.o
	rm -rf qt_files/ui*

dist: install
	rm -rf Archive_3DViewer/
	mkdir Archive_3DViewer/
	mkdir Archive_3DViewer/src
	cp -r ./build/3DViewer.app Archive_3DViewer/src/
	tar cvzf Archive_3DViewer.tgz Archive_3DViewer/
	rm -rf Archive_3DViewer/

clang-format:
	clang-format --style=Google -n *.c *.h QtFiles/*.cpp QtFiles/*.h
	
style:
	clang-format --style=Google -i *.c *.h QtFiles/*.cpp QtFiles/*.h

valgrind: test
	valgrind --track-origins=yes --leak-check=full --show-leak-kinds=all ./test
