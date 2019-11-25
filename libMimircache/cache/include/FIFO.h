//
//  FIFO.h
//  mimircache
//
//  Created by Juncheng on 6/2/16.
//  Copyright © 2016 Juncheng. All rights reserved.
//

#ifndef FIFO_H
#define FIFO_H

#ifdef __cplusplus
extern "C"
{
#endif


#include "../../include/mimircache/cache.h"

/* need add support for p and c obj_id_type of data 
 
 */



struct FIFO_params {
  GHashTable *hashtable;
  GQueue *list;
};


extern gboolean FIFO_check(cache_t *cache, request_t *req);

extern gboolean FIFO_add(cache_t *cache, request_t *req);

extern void _FIFO_insert(cache_t *FIFO, request_t *req);

extern void _FIFO_update(cache_t *FIFO, request_t *req);

extern void _FIFO_evict(cache_t *FIFO, request_t *req);

extern void *_FIFO_evict_with_return(cache_t *FIFO, request_t *req);


extern void FIFO_destroy(cache_t *cache);

extern void FIFO_destroy_unique(cache_t *cache);

extern guint64 FIFO_get_size(cache_t *cache);


cache_t *FIFO_init(guint64 size, obj_id_t obj_id_type, void *params);


#ifdef __cplusplus
}
#endif


#endif  /* FIFO_H */
