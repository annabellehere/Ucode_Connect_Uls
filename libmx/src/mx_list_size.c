#include "../inc/libmx.h"

int mx_list_size(t_list *list) {
	int counter = 1;
	if (list == NULL)
		return 0;
	t_list *temp = list;
	while (temp->next != NULL) {
		temp = temp->next;
		counter++;
	}
	return counter;
}

