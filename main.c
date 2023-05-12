#include "stack_ds.h"

stack_ds_t Stack1;
stack_ds_t Stack2;

uint32_t stack_pop_value = 0;
uint32_t stack_Top_value = 0;

int main()
{
	return_status_t ret = R_NOK;
	ret = stack_init(&Stack1);
	if (ret == R_NOK)
	{
		printf("stack1 failed to be initialized !! \n");
	}
	else
	{

		ret = stack_push(&Stack1, 11);
		ret = stack_push(&Stack1, 22);
		ret = stack_push(&Stack1, 33);
		ret = stack_push(&Stack1, 44);
		ret = stack_push(&Stack1, 55);
		ret = stack_push(&Stack1, 66);
		printf("------------------------------\n");
		ret = stack_disp(&Stack1);

		ret = stack_top(&Stack1,&(stack_Top_value) );
		for (int i = 0; i < 7; i++)
		{
			ret = stack_pop(&Stack1, &(stack_pop_value));
			if (R_OK == ret) {
				printf("stack_pop_value=%i \n", stack_pop_value);
			}

		}
		//ret= stack_top(&Stack1, &(stack_Top_value));
		//printf("------------------------------\n");
		ret = stack_push(&Stack1, 55);
		ret = stack_push(&Stack1, 66);

		ret = stack_size(&Stack1, &(stack_Top_value));
		printf("------------------------------\n");
		ret=stack_disp(&Stack1);
	}
	///
	ret = stack_init(&Stack2);
	if (ret == R_NOK)
	{
		printf("stack1 failed to be initialized !! \n");
	}
	else {
		printf("stack1 is initialized !! \n");
	}

	return 0;
}