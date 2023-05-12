#ifndef STACK_DS_C
#define STACK_DS_C

#include "stack_ds.h"

/*
 * @brief check stack is full
 * @param my_stack  (pointer to the stack)
 * @retval	status of the stack (is it full or not)
 */
static stack_status_t stack_full(stack_ds_t* my_stack);

static stack_status_t stack_full(stack_ds_t* my_stack)
{
	if (my_stack->stack_pointer == (STACK_MAX_SIZE - 1) )
	{
		return STACK_FULL;
	}
	else
	{
		return STACK_NOT_FULL;
	}
}
/*
 * @brief check stack is empty
 * @param my_stack  (pointer to the stack)
 * @retval	status of the stack (is it empty or not)
 */
static stack_status_t stack_empty(stack_ds_t* my_stack);

static stack_status_t stack_empty(stack_ds_t* my_stack)
{

	if (my_stack->stack_pointer == -1)
	{
		return STACK_EMPTY;
	}
	else
	{
		return STACK_NOT_EMPTY;
	}

}

/*
 * @brief initialize the stack pointer
 * @param my_stack  (pointer to the stack)
 * @retval	status of the initialization process
 */

return_status_t stack_init(stack_ds_t* my_stack) {
	return_status_t ret=R_NOK;

	if ( NULL == my_stack)
	{
		ret=R_NOK;
	}
	else
	{
		my_stack->stack_pointer = -1;
		ret = R_OK;
	}

	return ret;
}

/*
 * @brief  add new value to the stack (push it)
 * @param my_stack  (pointer to the stack)
 * @param value     (element to be added to the stack)
 * @retval	 status of the stack push
 */

return_status_t stack_push(stack_ds_t* my_stack, uint32_t value) {
	return_status_t ret = R_NOK;
	if ( (stack_full(my_stack)== STACK_FULL) || (NULL==my_stack)  )
	{
		#ifdef STACK_DEBUG
			printf("STACK is Full, can't push %i\n",value);

		#endif // STACK_DEBUG

		ret = R_NOK;
	}
	else {
		my_stack->stack_pointer++; 
		my_stack->data[my_stack->stack_pointer] = value;

		#ifdef STACK_DEBUG
			printf("value=%i pushed to the stack\n", value);

		#endif // STACK_DEBUG

		ret = R_OK;
	}


}
/*
 * @brief add new element to the stack 
 * @param my_stack  (pointer to the stack)
 * @param value  (value that is popped out of the stack)
 * @retval status of the stack top
 */

return_status_t stack_pop(stack_ds_t* my_stack, uint32_t* value){
	return_status_t ret = R_NOK;
	if( (NULL==my_stack) || (NULL==value) ||( stack_empty(my_stack)==STACK_EMPTY )  ) {
		#ifdef STACK_DEBUG
			printf("stack is empty\n");
		#endif
		ret = R_NOK;
	}
	else
	{
		*value = my_stack->data[my_stack->stack_pointer];
		//my_stack->data[my_stack->stack_pointer]=NULL;
		my_stack->stack_pointer--;
		#ifdef STACK_DEBUG
		printf("top value(%i) is popped \n",*value);
		#endif //STACK_DEBUG
		ret = R_OK;

	}
	return ret;
}
/*
 * @brief get the last element pushed to the stack top
 * @param my_stack  (pointer to the stack)
 * @param value  ( value of the top element)
 * @retval	status of the stack_top
 */

return_status_t stack_top(stack_ds_t* my_stack, uint32_t* value) {
	return_status_t ret=R_NOK;
	if ((NULL == my_stack) || (NULL == value) || (STACK_EMPTY == stack_empty(my_stack)) )
	{
		printf("stack is empty, so there is nothing at the top\n");
		ret = R_NOK;
	}
	else
	{
		*value= my_stack->data[my_stack->stack_pointer] ; 
		printf("value at the stack top now= %i \n", *value);

		ret = R_OK;
	}

	return ret;
}
/*
 * @brief get size of the stack (number of elements)
 * @param my_stack  (pointer to the stack)
 * @retval status of stack_size
 */

return_status_t stack_size(stack_ds_t* my_stack, uint32_t* stack_size) {
	return_status_t ret = R_NOK;
	if ((NULL == my_stack) || (NULL == stack_size))
	{
		printf("NULL Pointers \n");
	}
	else
	{
		*stack_size = (my_stack->stack_pointer) + 1;
		printf("stack size=%i \n", *stack_size);
		ret = R_OK;
	}


	return ret;
}
/*
 * @brief function stack_disp prints all elements in the stack
 * @param my_stack  (pointer to the stack)
 * @retval status of the stack_disp
 */
return_status_t stack_disp(stack_ds_t* my_stack) {
	return_status_t ret = R_NOK;
	sint32_t counter = 0;
	if ((NULL == my_stack) || (STACK_EMPTY==stack_empty(my_stack)) )
	{
		printf("stack is empty-------nothing to display-------\n");

	}
	else
	{
		printf("stack data: ");
		for (counter = (my_stack->stack_pointer); counter >= 0; counter--)
		{
			printf("%i \t", my_stack->data[counter]);
		}

		ret = R_OK;
	}


	return ret;


}



#endif // !STACK_DS_C
