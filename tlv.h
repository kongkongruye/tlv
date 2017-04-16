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

#define TLV_SCAN(p_tlv_c,buf,size) for(TLV_C* p_tlv_c=(TLV_C*)buf;\
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

//#define TLV_ARRAY() struct {}