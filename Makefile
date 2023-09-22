CC=g++
CFLAGS=-Wall -Wextra -Werror -std=c++17 -g
TEST_SOURCES=Model/calculator.cc Model/financecalculator.cc Tests/*.cc
GCOV_FLAGS=
LDFLAGS=-lgtest -lgtest_main -lpthread

all: install

test:
	$(CC) $(CFLAGS) $(TEST_SOURCES) $(LDFLAGS) $(GCOV_FLAGS) -o test

gcov_report: GCOV_FLAGS += -fprofile-arcs -ftest-coverage
gcov_report: test
	./test > /dev/null
	lcov --no-external -t "report" -o report.info -c -d .
	genhtml -o "html_report" report.info
	open html_report/index.html

install:
	rm -rf s21_smart_calc
	mkdir s21_smart_calc
	qmake qt_smart_calc.pro -o s21_smart_calc
	cd s21_smart_calc && make && cd ../
	chmod +x s21_smart_calc/qt_smart_calc.app
	ln -s ${PWD}/s21_smart_calc/qt_smart_calc.app ${HOME}/Desktop/Smart\ Calc\ v2.0

uninstall:
	rm -rf s21_smart_calc
	rm ${HOME}/Desktop/Smart\ Calc\ v2.0

dvi:
	open html/index.html
#	doxygen -g Doxyfile
#	doxygen Doxyfile

dist: install
	tar -czf s21_smart_calc.tar.gz --directory=s21_smart_calc/ .

style:
	clang-format -style=google -i Model/*.cc Model/*.h View/*.cc View/*.h Controller/*.cc Controller/*.h Tests/*.cc *.cc *.h
	clang-format -style=google -n Model/*.cc Model/*.h View/*.cc View/*.h Controller/*.cc Controller/*.h Tests/*.cc *.cc *.h

clean:
	rm -rf obj *.a test html_report report.info program *.o *.gch calc_functions/*.gch *.gcno *.gcda s21_smart_calc.tar.gz *.dSYM

.PHONY: all test clean gcov_report
