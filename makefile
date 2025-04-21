# Makefile (use gcc or clang for linux)

COMPILER			= clang
MAKETOOL			= make
DEBUGGER			= lldb
CFLAGS				= -Wall -Wextra -pedantic -std=c11
LDFLAGS				= -lm
DFLAGS				= -g -O0
INCLUDES			= -Ilibai/maths/matrices/vectors -Ilibai/neural_networks/perceptron -Ilibai/maths/activation
SOURCES				= main.c libai/maths/matrices/vectors/vectors.c libai/neural_networks/perceptron/perceptron.c libai/maths/activation/relu.c
OBJECTS				= $(SOURCES:.c=.o)
TARGET				= main
TEST_INCLUDES		= -Itests/framework 	
TEST_SOURCES		= tests/framework/test_framework.c tests/neural_networks/perceptron/test_perceptron.c libai/maths/matrices/vectors/vectors.c libai/neural_networks/perceptron/perceptron.c libai/maths/activation/relu.c
TEST_OBJECTS		= $(TEST_SOURCES:.c=.o)
TEST_TARGET			= test
DEBUG_TARGET		= debug
DEBUG_OBJECTS		= $(SOURCES:.c=.o) $(TEST_SOURCES:.c=.o)
BUILD_DIRECTORY		= build

# -------------
# Make targets
# -------------

all: $(BUILD_DIRECTORY) $(TARGET) $(TEST_TARGET) $(DEBUG_TARGET)

$(BUILD_DIRECTORY):
	@mkdir $(BUILD_DIRECTORY)

$(TARGET): $(BUILD_DIRECTORY) $(SOURCES)
	@echo Compiling $(TARGET) ...
	@$(COMPILER) $(CFLAGS) -o $(BUILD_DIRECTORY)/$(TARGET) $(SOURCES) $(INCLUDES) $(LDFLAGS)
	@echo Compilation Done.
	@echo Run \"$(MAKETOOL) run\" to execute program.

run: $(BUILD_DIRECTORY)/$(TARGET)
	@echo Running program.
	@echo -----------------------
	@./$(BUILD_DIRECTORY)/$(TARGET)
	@echo -----------------------
	@echo Program finished.

$(TEST_TARGET): $(BUILD_DIRECTORY) $(TEST_SOURCES) $(SOURCES)
	@echo Compiling $(TEST_TARGET) ...
	@$(COMPILER) $(CFLAGS) -o $(BUILD_DIRECTORY)/$(TEST_TARGET) $(TEST_SOURCES) $(INCLUDES) $(TEST_INCLUDES) $(LDFLAGS)
	@echo Compilation Done.
	@echo Run \"$(MAKETOOL) $(TEST_TARGET)_run\" to execute program.

$(TEST_TARGET)_run: $(BUILD_DIRECTORY)/$(TEST_TARGET)
	@echo Running tests.
	@echo -----------------------
	@./$(BUILD_DIRECTORY)/$(TEST_TARGET)
	@echo -----------------------
	@echo Testing finished.

$(DEBUG_TARGET): $(BUILD_DIRECTORY) $(TEST_SOURCES) $(SOURCES)
	@echo Compiling $(DEBUG_TARGET) ...
	@$(COMPILER) $(CFLAGS) $(DFLAGS) -o $(BUILD_DIRECTORY)/$(DEBUG_TARGET) $(TEST_SOURCES) $(INCLUDES) $(TEST_INCLUDES) $(LDFLAGS)
	@echo Compilation Done.
	@echo Run \"$(DEBUGGER) $(BUILD_DIRECTORY)/$(DEBUG_TARGET)\" to execute program.

$(DEBUG_TARGET)_run: $(BUILD_DIRECTORY)/$(DEBUG_TARGET)
	@echo Running tests.
	@echo -----------------------
	@$(DEBUGGER) ./$(BUILD_DIRECTORY)/$(DEBUG_TARGET)
	@echo -----------------------
	@echo Testing finished.

clean:
	@echo Cleaning up ...
	@rm -rvf $(BUILD_DIRECTORY)
	@echo Cleaning done.
