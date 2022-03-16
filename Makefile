packages:
	apt update -y && \
	sudo apt install -y cppcheck clang-tidy python3-pip libc6-dbg cmake lcov tree libgtest-dev && \ 
	pip install cpplint && \
	wget https://sourceware.org/pub/valgrind/valgrind-3.18.1.tar.bz2 && \
	tar xfv valgrind-3.18.1.tar.bz2 && \
	cd valgrind-3.18.1 && \
	./autogen.sh && \
	./configure && \
	make && \
	make install

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

