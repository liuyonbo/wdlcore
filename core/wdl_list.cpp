#include <stdlib.h>
#include "wgl_alloc.h"
#include "wdl_list.h"

bool wdl_slist::wdl_slist_new(void* data) {

	head = (wdl_snode*)wgl_alloc(sizeof(wdl_snode));
	head->data = data;
	head->flag = 0;
	head->next = NULL;
	return true;
}
wdl_snode*  wdl_slist::wdl_slist_get_root() {

	return head;
}
bool wdl_slist::wdl_slist_push(void* data) {
	if (head == NULL) return false;
	wdl_snode* temp = head;
	wdl_snode* nnode = (wdl_snode*)wgl_alloc(sizeof(wdl_snode));
	if (nnode == NULL) return NULL;
	nnode->data = data;
	nnode->flag = 1;
	nnode->next = NULL;

	while (temp && temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = nnode;
	return nnode;
}

wdl_snode* wdl_slist::wdl_slist_insert(wdl_snode* node, void* data) {
	if (node == NULL) return NULL;

	wdl_snode* nnode = (wdl_snode*)wgl_alloc(sizeof(wdl_snode));
	if (nnode == NULL) return NULL;
	nnode->data = data;
	nnode->flag = 1;
	nnode->next = node->next;
	node->next = nnode;
	return nnode;
}

bool wdl_slist::wdl_slist_remove(wdl_snode* node) {
	if (head == NULL || node == NULL) return false;
	wdl_snode* temp = head;
	if (head->flag == 0 && head == node && head->next == NULL) {
		wgl_free(head);
		head = head->next;
		head->flag = 0;
		return true;
	}
	while (temp) {
		if (temp->next == node) {
			temp->next = node->next;
			wgl_free(node);
			return head;
		}
		temp = temp->next;
	}
	return true;
}
bool wdl_slist::wdl_slist_reverse() {
	if (head == NULL || head->flag != 0) return false;
	wdl_snode* next;
	wdl_snode* prv = NULL;
	head->flag = 1;
	while (head != NULL)
	{
		next = head->next;
		head->next = prv;
		prv = head;
		head = next;
	}
	prv->flag = 0;
	head = prv;
	return true;
}