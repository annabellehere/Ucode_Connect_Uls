#include "../inc/libmx.h"

void mx_push_back (t_list **list, void *data, t_information file){
	if (list && !*list) {
		*list = mx_create_node(data, file);
		return;
	}
	t_list *back = mx_create_node(data, file);
	t_list *cur = *list;
	if (!back) return;
	while (cur->next != 0) 
		cur = cur->next;
	cur->next = back;
}




