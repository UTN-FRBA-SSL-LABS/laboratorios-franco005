# Nombre del ejecutable final
PROGRAMA := programa

# Compilador y flags
CC     := gcc
CFLAGS := -Wall

# TODO 1
SRCS := main.c operaciones.c

# TODO 2
OBJS := $(SRCS:.c=.o)

# Regla principal
all: $(PROGRAMA)

# TODO 3
$(PROGRAMA): $(OBJS)
	$(CC) $^ -o $(PROGRAMA)

# TODO 4
%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Regla para limpiar archivos generados
clean:
	rm -f $(PROGRAMA) $(OBJS)

# TODO 5
.PHONY: all clean