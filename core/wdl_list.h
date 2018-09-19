#ifndef _WDL_LIST_H
#define _WDL_LIST_H
struct wdl_slist
{
	void* data;
	struct wdl_slist* next;
};

struct wdl_slist* wdl_slist_new(void* data);

struct wdl_slist* wdl_slist_add(struct wdl_slist* node, void* data);
void   wdl_slist_remove(struct wdl_slist* node);
struct wdl_slist* wdl_slist_reverse(struct wdl_slist* head);
#endif