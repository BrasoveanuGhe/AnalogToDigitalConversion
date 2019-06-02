/*
 * stdutils.h
 *
 * Created: 4/19/2019 9:46:20 PM
 *  Author: braso
 */ 


#ifndef STDUTILS_H_
#define STDUTILS_H_


/***************************************************************************************************
                                Macros for Bit Manipulation
 ****************************************************************************************************/
#define  util_GetBitMask(bit)          (1<<(bit))
#define  util_BitSet(x,bit)            ((x) |=  util_GetBitMask(bit))
#define  util_BitClear(x,bit)          ((x) &= ~util_GetBitMask(bit))
#define  util_BitToggle(x,bit)         ((x) ^=  util_GetBitMask(bit))
#define  util_UpdateBit(x,bit,val)     ((val)? util_BitSet(x,bit): util_BitClear(x,bit))
/**************************************************************************************************/



#endif /* STDUTILS_H_ */