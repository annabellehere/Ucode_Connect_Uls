#include "../inc/libmx.h"

t_list* mx_create_node(void *data, t_information file){
		t_list *result = malloc(sizeof(t_list));
		result->data = data;
		result->information = file;
		result->next = NULL;
		return result;
}

