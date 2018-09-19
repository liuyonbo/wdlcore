#include <stdlib.h>

void* wgl_alloc(size_t size){
	return malloc(size);
}
void wgl_free(void* p){
	free(p);
}