#ifndef _H_DRIVER_PAG
#define _H_DRIVER_PAG
#include "zcpag.h"

extern struct sk_buff * alloc_zcopy_zkb(struct net_device *, unsigned int);
extern void deliver_zcopy_zkb(struct sk_buff *);
extern void free_zcopy_zkb(struct sk_buff *);
static inline struct sk_buff * convert_sk_buff(struct sk_zcopy * zkb)
{
	return (struct sk_buff *)zkb->ptr_skb;
}
static inline struct sk_zcopy * convert_sk_zcopy(struct sk_buff * skb)
{
	return container_of((void*)skb, struct sk_zcopy, ptr_skb);
}
static inline int is_zcopy_packet(struct sk_buff * skb)
{
	struct sk_zcopy * zkb = convert_sk_zcopy(skb);
	
	if((zkb->magic == FROMKERNEL) || (zkb->magic == FROMUSER))
		return 1;
	return 0;
}
#endif
