#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif
#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

#define BUFFER_SIZE 1024

/*extern char *push_arg;*/
/*extern char *opcode;*/
/*extern int exec_failed;*/

/**
 * struct vars - used for global variables
 * @exec_failed: integer
 * @push_arg: pointer to string
 * @opcode: pointer to string
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct vars
{
	int exec_failed;
	char *push_arg;
	char *opcode;
} vars;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **h, unsigned int errLine);
} instruction_t;

extern vars global_vars;

/* ARGS_OPCODE*/
void args_count(int argc);

/* FILE_OPCODE*/
void open_file(char *filename, FILE **file);
void close_exit_file(FILE **file);
void close_exit_file_failure(stack_t *h, FILE *file);

/* FUNC_OPCODE*/
void (*get_opcode_func(char *s))(stack_t **, unsigned int);
void check_valid_opcode(char *opcode, unsigned int errLine);

/* MALLOC_OPCODE*/
void malloc_stack_check(stack_t *ptr);
void malloc_char_check(char *ptr);

/* OPERATORS_OPCODE*/
void my_add(stack_t **h, unsigned int errLine);
void my_sub(stack_t **h, unsigned int errLine);
void my_div(stack_t **h, unsigned int errLine);
void my_mul(stack_t **h, unsigned int errLine);
void my_mod(stack_t **h, unsigned int errLine);

/* PARSE_OPCODE*/
char *parse_opcode(char *s);

/* PRINT_OPCODE*/
void my_pint(stack_t **h, unsigned int errLine);
void my_pall(stack_t **h, unsigned int errLine);
void my_pchar(stack_t **h, unsigned int errLine);
void my_pstr(stack_t **h, unsigned int errLine);


/* STRCHK_OPCODE*/
int strchk_opcode(char *s);

/* PUSH_OPCODE*/
void my_push(stack_t **h, unsigned int errLine);

/* UTILS_OPCODE*/
void my_pop(stack_t **h, unsigned int errLine);
size_t stack_len(const stack_t *h);
void my_swap(stack_t **h, unsigned int errLine);
void nop_comment(char *s);
void my_nop(stack_t **h, unsigned int errLine);

/* STACK_OPCODE*/
void free_stack(stack_t *h);

/* ROTATE_OPCODE*/
void my_rotl(stack_t **h, unsigned int errLine);
void my_rotr(stack_t **h, unsigned int errLine);

#endif/*MONTY.H*/
