#include "my_libc.h"

void my_list_foreach_if(t_list *begin_list, void (*f)(void *), void
*data_ref, int (*cmp)())
{
    while(begin_list)
    {
        if (!cmp(begin_list->content, data_ref))
            (*f)(begin_list->content);
        begin_list = begin_list->next;
    }
}