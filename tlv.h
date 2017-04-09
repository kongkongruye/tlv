#include <stdint.h>

typedef struct tlv_c_t {
    uint16_t type;
    uint16_t len;
    uint8_t value[0];
}
TLV_C;

typedef struct tlv_p_t {
    uint16_t type;
    uint16_t len;
    void* pvalue;
} TLV_P;