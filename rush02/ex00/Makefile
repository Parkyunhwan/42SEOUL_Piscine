CC=gcc
CFLAGS=-Wall	-Wextra	-Werror
TARGET=rush-02
OBJS=file.o	main.o	keyvalue_insert.o	ft_split.o	find.o	check.o	print.o

all	:	$(TARGET)

$(TARGET): $(OBJS)
	$(CC)	$(CFLAGS)	-o	$@	$^	

fclean	:
	rm	$(OBJS)	$(TARGET)

