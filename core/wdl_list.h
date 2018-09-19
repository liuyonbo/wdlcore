#ifndef _WDL_LIST_H
#define _WDL_LIST_H
typedef struct _wdl_snode
{
	void* data;
	int	  flag;
	struct _wdl_snode* next;
}wdl_snode;
struct wdl_slist
{
	bool	   wdl_slist_new(void* data);
	wdl_snode* wdl_slist_get_root();
	bool	   wdl_slist_push(void* data);
	wdl_snode* wdl_slist_insert(wdl_snode* node, void* data);
	bool wdl_slist_remove(wdl_snode* node);
	bool wdl_slist_reverse();
	wdl_snode* head;
};
#endif