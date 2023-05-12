#ifndef _STACK_DS_H
#define _STACK_DS_H

#include "std_types.h"
#define STACK_MAX_SIZE 5
#define STACK_DEBUG

typedef enum stack_status {
	STACK_EMPTY, STACK_FULL, STACK_NOT_FULL, STACK_NOT_EMPTY
}stack_status_t;


typedef struct stack_ds {
	uint32_t stack_pointer;
	uint32_t data[STACK_MAX_SIZE];

}stack_ds_t;



/*
 * @brief initialize the stack pointer
 * @param my_stack  (pointer to the stack)
 * @retval	status of the initialization process
 */
return_status_t stack_init(stack_ds_t* my_stack);

/*
 * @brief  add new value to the stack (push it)
 * @param my_stack  (pointer to the stack)
 * @param value     (element to be added to the stack)
 * @retval	 status of the stack push
 */

return_status_t stack_push(stack_ds_t* my_stack,uint32_t value);
/*
 * @brief add new element to the stack
 * @param my_stack  (pointer to the stack)
 * @param value  (value that is popped out of the stack)
 * @retval status of the stack top
 */
return_status_t stack_pop(stack_ds_t* my_stack, uint32_t *value);
/*
 * @brief get the last element pushed to the stack top
 * @param my_stack  (pointer to the stack)
 * @param value  ( value of the top element)
 * @retval	status of the stack_top
 */
return_status_t stack_top(stack_ds_t* my_stack, uint32_t* value);

/*
 * @brief get size of the stack (number of elements)
 * @param my_stack  (pointer to the stack)
 * @retval status of stack_size
 */
return_status_t stack_size(stack_ds_t* my_stack, uint32_t* stack_size);

/*
 * @brief function stack_disp prints all elements in the stack
 * @param my_stack  (pointer to the stack)
 * @retval status of the stack_disp
 */
return_status_t stack_disp(stack_ds_t* my_stack);


#endif
