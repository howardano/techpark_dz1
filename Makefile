packages:
    sudo apt install -y cppcheck clang-tidy python3-pip libc6-dbg cmake lcov tree libgtest-dev

build:
	mkdir build && \
	cd build && \
	cmake -D TESTS = ON ../project && \
	make

analysis: 
	chmod +x linters/run.sh && \
	./linters/run.sh && \

test:
	./build/tests/test_calc

