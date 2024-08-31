CXX		:=	c++
CXXFLAGS	:=	-Wall -Wextra -Werror -Wconversion -std=c++98
RM		:=	rm -f

TARGET	:=	a.out

SRCS    :=	test_eof.cpp
OBJS    :=	$(patsubst %.cpp, %.o, $(SRCS))

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $^ -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(TARGET)

run: all
	./$(TARGET)