rm -f CMakeCache.txt
export CC=gcc
export CXX=g++
export CMAKE_C_COMPILER=gcc
export CMAKE_CXX_COMPILER=g++
cmake -G "Unix Makefiles" .
make clean
make
cd bin
./latino ../ejemplos/coverage.lat
gcov ../src/*.c --object-directory ../src/CMakeFiles/latino.dir/
bash <(curl -s https://codecov.io/bash)
cd ..
