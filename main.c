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
#include <sys/queue.h>

/*
 * 
 */


int main(int argc, char** argv) {
    uint16_t buf[6] = {1, 2, 0, 1, 2, 2};
    
    TLV_C* ptlv;
    TLV_SCAN(ptlv, buf, sizeof (buf)) {

        printf("tlv %d\n", TLV_CAST(ptlv, short));

        //        printf("tlv %d\n",TLV_CAST(ptlv,int));    
    }

    TLV_INT(ta, 9);
    TLV_INT(tb, 9);
    TLV_CSTR(tc, "addkdkdkdkdkd");
    
    MB_DEF(mb1,buf,sizeof(buf));
    MB_OFF(mb1,2);
    MB_GET_INNER_MB(mb2,mb1);
    
    
    return EXIT_SUCCESS;
}

