#include "monty.h"

/**
  * div - Dvivides the second top element of the stack by the top element
  * @stack: Address of stack whose top elements need to be divided
  * @line_number: Line number of opcode currently being executed
  */

void div_(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int result = 0;

	if (temp == NULL || temp->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (temp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	result = (temp->next->n) / (temp->n);
	pop(stack, line_number);
	(*stack)->n = result;
}
