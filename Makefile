.PHONY: all clean fclean re rsc make_dir sanitize

NAME 			= push_swap

SRCS_MAIN		= main.c
SRCS_STACK		= put_number_stack.c replace_number_index.c
SRCS_INSTR		= push_stack.c rotate_stack.c swap_stack.c
SRCS_METH		= hard_sort.c hard_sort2.c radix_sort.c sort.c
SRCS_UTIL		= binary_convert.c libft_utils.c stack_utils.c stack_utils2.c

OBJS_MAIN		= ${SRCS_MAIN:%.c=./obj/%.o} 
OBJS_STACK		= ${SRCS_STACK:%.c=./obj/%.o}
OBJS_INSTR		= ${SRCS_INSTR:%.c=./obj/%.o}
OBJS_METH		= ${SRCS_METH:%.c=./obj/%.o}
OBJS_UTIL		= ${SRCS_UTIL:%.c=./obj/%.o}

ALL_OBJS		= $(OBJS_MAIN) $(OBJS_STACK) $(OBJS_INSTR) $(OBJS_METH) $(OBJS_UTIL)

HEADER 		= stack.h
CC 			= gcc
FLAGS 		= -Wall -Wextra -Werror
SANITIZE	= -g -fsanitize=address
RM          = rm -rf

all:        make_dir ${NAME}

./obj/%.o:		./main/%.c ${HEADER}  
				${CC} ${FLAGS} -include${HEADER} -c $< -o $@

./obj/%.o:		./setup_stack/%.c ${HEADER}  
				${CC} ${FLAGS} -include${HEADER} -c $< -o $@

./obj/%.o:		./sort_instruction/%.c ${HEADER}  
				${CC} ${FLAGS} -include${HEADER} -c $< -o $@

./obj/%.o:		./sort_method/%.c ${HEADER}  
				${CC} ${FLAGS} -include${HEADER} -c $< -o $@

./obj/%.o:		./utils/%.c ${HEADER}  
				${CC} ${FLAGS} -include${HEADER} -c $< -o $@

$(NAME):	$(ALL_OBJS)
			${CC} ${FLAGS} -include${HEADER} $(ALL_OBJS) -o $(NAME)

make_dir:
			@mkdir -p obj

sanitize:	$(ALL_OBJS) 
			${CC} ${FLAGS} $(SANITIZE) -include${HEADER} $(ALL_OBJS) -o $(NAME)

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME} obj

re:			fclean all
			$(MAKE) all