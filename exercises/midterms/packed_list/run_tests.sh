export CC=gcc
export LD=gcc
export CFLAGS="-Wall -std=gnu99"
export LDFLAGS="-std=gnu99"

# Set up GL lib paths
if [[ -z "${GL_LIB_PATH}" ]]; then
    export GL_LIB_PATH="~/dev/src/gl"
fi
echo "GL lib path: $GL_LIB_PATH"
echo "CFLAGS: $CFLAGS"

export OUT_DIR=$(pwd)

# Clean
make clean
make -C tests clean

# packed_list
make packed_list ip_list
make -C tests run_tests

echo "---- Running tests ----"
./run_tests
