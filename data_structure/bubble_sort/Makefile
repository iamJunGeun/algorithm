PHONY = all clean

TARGET = bubble_sort
SRCS = main.cpp bubble_sort.cpp ../data_buffer.cpp 

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $^ -o $@

clean:
	-rm $(TARGET)
