CC = cc
CFLAGS = -Wall -Wextra -Werror

SERVER = server
CLIENT = client

LIBFT_DIR = includes/libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS_SERVER = src/server.c
SRCS_CLIENT = src/client.c

OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

all: $(LIBFT) $(SERVER) $(CLIENT)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(SERVER): $(OBJS_SERVER) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS_SERVER) -L$(LIBFT_DIR) -lft -o $(SERVER)

$(CLIENT): $(OBJS_CLIENT) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS_CLIENT) -L$(LIBFT_DIR) -lft -o $(CLIENT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS_SERVER) $(OBJS_CLIENT)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(SERVER) $(CLIENT)
	make fclean -C $(LIBFT_DIR)

re: fclean all
