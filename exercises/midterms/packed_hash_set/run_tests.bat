set CC=gcc
set LD=gcc
set CFLAGS="-Wall -std=gnu99"
set LDFLAGS="-std=gnu99"

rem Set up GL lib paths
if not defined GL_LIB_PATH (
    set GL_LIB_PATH="~/dev/src/gl"
)
echo "GL lib path: %GL_LIB_PATH%"
echo "CFLAGS: %CFLAGS%"

set OUT_DIR=%cd%

# Clean
make clean
make -C tests clean

# packed_hash_set
make packed_hash_set tuple_hash_set
make -C tests run_tests

echo "---- Running tests ----"
start run_tests
