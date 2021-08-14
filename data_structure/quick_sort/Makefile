PHONY = all clean

TARGET = a.out
SRCS = main.cpp quick_sort.cpp ../data_buffer.cpp 

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) -g $^ -o $@

clean:
	-rm $(TARGET)
