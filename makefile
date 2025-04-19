# Makefile (use gcc or clang for linux)
# clang -o main main.c libai/maths/matrices/vectors/vectors.c libai/neural_
# networks/perceptron/perceptron.c libai/maths/logistics/sigmoid.c -Ilibai/maths/matrices/vectors -Ilibai/neural_networks/perceptron -Il
# ibai/maths/logistics -lm

COMPILER			= clang
MAKETOOL			= make
CFLAGS				= -Wall -Wextra -pedantic -std=c11
LFLAGS				= -lm
INCLUDES			= -Ilibai/maths/matrices/vectors -Ilibai/neural_networks/perceptron -Ilibai/maths/logistics
SOURCES				= main.c libai/maths/matrices/vectors/vectors.c libai/neural_networks/perceptron/perceptron.c libai/maths/logistics/sigmoid.c
OBJECTS				= $(SOURCES:.c=.o)
TARGET				= main
TEST_SOURCES		= tests/neural_networks/perceptron/test_perceptron.c libai/maths/matrices/vectors/vectors.c libai/neural_networks/perceptron/perceptron.c libai/maths/logistics/sigmoid.c
TEST_OBJECTS		= $(TEST_SOURCES:.c=.o)
TEST_TARGET			= test
BUILD_DIRECTORY		= build

# -------------
# Make targets
# -------------

all: $(BUILD_DIRECTORY) $(TARGET) $(TEST_TARGET)

$(BUILD_DIRECTORY):
	@mkdir $(BUILD_DIRECTORY)

$(TARGET): $(BUILD_DIRECTORY) $(SOURCES)
	@echo Compiling $(TARGET) ...
	@$(COMPILER) $(CFLAGS) -o $(BUILD_DIRECTORY)/$(TARGET) $(SOURCES) $(INCLUDES) $(LFLAGS)
	@echo Compilation Done.
	@echo Run "$(MAKETOOL) run" to execute program.

run: $(BUILD_DIRECTORY)/$(TARGET)
	@echo Running program.
	@echo -----------------------
	@./$(BUILD_DIRECTORY)/$(TARGET)
	@echo -----------------------
	@echo Program finished.

$(TEST_TARGET): $(BUILD_DIRECTORY) $(TEST_SOURCES) $(SOURCES)
	@echo Compiling $(TEST_TARGET) ...
	@$(COMPILER) $(CFLAGS) -o $(BUILD_DIRECTORY)/$(TEST_TARGET) $(TEST_SOURCES) $(INCLUDES) $(LFLAGS)
	@echo Compilation Done.
	@echo Run "$(MAKETOOL) $(TEST_TARGET)_run" to execute program.

$(TEST_TARGET)_run: $(BUILD_DIRECTORY)/$(TEST_TARGET)
	@echo Running tests.
	@echo -----------------------
	@./$(BUILD_DIRECTORY)/$(TEST_TARGET)
	@echo -----------------------
	@echo Testing finished.

clean:
	@echo Cleaning up ...
	@rm -f $(BUILD_DIRECTORY)/$(TARGET)
	@rm -f $(BUILD_DIRECTORY)/$(TEST_TARGET)
	@rm -rf $(BUILD_DIRECTORY)
	@rm -f *.o 2>/dev/null
	@rm -f *~ 2>/dev/null
	@rm -f *.dSYM 2>/dev/null
	@echo Cleaning done.