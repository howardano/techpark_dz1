packages:
	sudo apt-get update -y && \
	sudo apt-get install build-essential && \
	sudo apt-get install -y cppcheck clang-tidy python3-pip libc6-dbg lcov libgtest-dev && \
	pip3 install cpplint && \
	sudo apt-get valgrind

build:
	mkdir build && \
	cd build && \
	cmake -D TESTS=ON ../project && \
	make

analysis: 
	chmod +x linters/run.sh && \
	./linters/run.sh

test:
	./build/tests/test_calc

