#include <stdint.h>
#include <assert.h>

typedef struct tlv_c_t {
    uint16_t type;
    uint16_t len;
    uint8_t value[0];
} TLV_C;

typedef struct tlv_h_t {
    uint16_t type;
    uint16_t len;
} TLV_H;

typedef struct tlv_p_t {
    uint16_t type;
    uint16_t len;
    uint8_t* pvalue;
} TLV_P;

#define TLV_NEXT(p_tlv_c) (p_tlv_c = (TLV_C*)(p_tlv_c->value + p_tlv_c->len))

#define TLV_SCAN(p_tlv_c,buf,size) for(p_tlv_c=(TLV_C*)buf;\
                                                            p_tlv_c->value+p_tlv_c->len <= ((uint8_t*)buf)+size;\
                                                            TLV_NEXT(p_tlv_c))

#define TLV_CAST(p_tlv_c,type)    (assert(sizeof(type) == p_tlv_c->len ),*((type*)p_tlv_c->value))

#define TLV_T_CHAR      1
#define TLV_T_SHORT    2
#define TLV_T_INT 3
#define TLV_T_STR 4

#define TLV_T_USER_DEF 10
#define TLV_T_ABC (TLV_T_USER_DEF+1)


#define TLV_INT(nm,v)  struct { TLV_H h;int value;} nm=\
 {.h={.type=TLV_T_INT,.len=sizeof(int)},\
 .value=v}

#define TLV_SHORT(nm,v)  struct { TLV_H h;short value;} nm=\
 {.h={.type=TLV_T_INT,.len=sizeof(short)},\
 .value=v}

#define TLV_CSTR(nm,v)  struct { TLV_H h;char value[sizeof(v)];} nm=\
 {.h={.type=TLV_T_INT,.len=sizeof(short)},\
 .value=v}

#define TLV_SIZEOF(v) (sizeof(TLV_C)+v.len)

typedef struct memory_block_t {
    uint8_t* paddr;
    uint32_t off;
    uint32_t size;
} MemoryBlock;

#define MB_DEF(nm,buf,s) MemoryBlock nm = {\
.paddr = (uint8_t*)buf,\
.off = 0,\
.size = s\
}

#define MB_OFF(mb,s) (mb.off += s,assert(mb.off <= mb.size))
#define MB_GET_INNER_MB(n_mb,o_mb)  MB_DEF(n_mb,o_mb.paddr,o_mb.off)
//类型转换
#define MB_CAST(mb,t) (t)(mb.paddr+mb.off)
//剩余多少
#define MB_REMAIN(mb) (mb.size - mb.off)
//写入POD数据
#define MB_WRITE_POD(mb,v) do{assert(MB_REMAIN(mb)>=sizeof(v));\
memcpy(mb.paddr+ mb.off,&v,sizeof(v));\
mb.off += sizeof(v);\
}while(0)
//写入指针
#define MB_WRITE_PT(mb,pt) WRITE_POD(mb,*pt)

