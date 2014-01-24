OPTIMIZE = -O2
CFLAGS = -I. -I../libViewer -Wall -Wextra $(OPTIMIZE)
CXXFLAGS = -I. -I../libViewer -Wall -Wextra -std=c++0x $(OPTIMIZE)
LDFLAGS = -s ASM_JS=1 --embed-file shaders $(OPTIMIZE)
#LDFLAGS = -s ASM_JS=1 --preload-file shaders --memory-init-file 1

LIBVIEWER_DIR = ../libViewer
LIBVIEWER_SOURCES = P3dViewer.cpp PlatformAdapter.cpp ModelLoader.cpp
SOURCES = main.cpp $(LIBVIEWER_SOURCES)
OBJECTS = $(SOURCES:.cpp=.o)
VPATH = $(LIBVIEWER_DIR)
TARGET = em_test.html
SHADERS = $(shell find $(LIBVIEWER_DIR)/shaders/ -name "*.glsl")

# Targets start here.
all: $(TARGET)

shaders: $(LIBVIEWER_DIR)/shaders
	ln -s $< $@

$(TARGET): $(OBJECTS) Makefile shaders $(SHADERS)
	$(CC) $(CFLAGS) -o $@ $(LDFLAGS) $(OBJECTS)

clean:
	$(RM) $(TARGET) $(OBJECTS) deps.txt $(TARGET).mem $(basename $(TARGET)).data

deps.txt: $(SOURCES) Makefile
	@$(CC) $(CFLAGS) -MM  $^ > $@

# list targets that do not create files (but not all makes understand .PHONY)
.PHONY:	all clean

$(OBJECTS): Makefile deps.txt

-include deps.txt
