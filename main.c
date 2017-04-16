/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Administrator
 *
 * Created on 2017年4月16日, 上午11:06
 */

#include <stdio.h>
#include <stdlib.h>
#include "tlv.h"

/*
 * 
 */
int main(int argc, char** argv) {
    uint16_t buf[6] = {1, 2, 0, 1, 2, 2};

    TLV_SCAN(ptlv, buf, sizeof (buf)) {

        printf("tlv %d\n", TLV_CAST(ptlv, short));

        //        printf("tlv %d\n",TLV_CAST(ptlv,int));    
    }

    TLV_INT(ta, 9);
    TLV_INT(tb, 9);
    TLV_CSTR(tc, "addkdkdkdkdkd");
    printf(tc.value);
//    TLV_ARRAY(td, ta, tb, tc);


    return (EXIT_SUCCESS);
}

