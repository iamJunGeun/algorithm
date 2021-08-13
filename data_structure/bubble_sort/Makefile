PHONY = all clean

TARGET = a.out
SRCS = main.cpp bubble_sort.cpp ../data_buffer.cpp 

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $^ -o $@

clean:
	-rm $(TARGET)
