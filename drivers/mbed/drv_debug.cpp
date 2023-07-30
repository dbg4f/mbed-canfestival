#include "mbed.h"
#include "canfestival.h"
#include "can_driver.h"


void dump(const char* msg, Message *m)
{
    
    printf("%s ", msg);
    
    print_message(m);
    
    /*
    printf("%s %04X|%02X|len %d|%02X %02X %02X %02X %02X %02X %02X %02X\n", msg,
        m->cob_id, m->rtr, m->len, 
        m->data[0],
        m->data[1],
        m->data[2],
        m->data[3],
        m->data[4],
        m->data[5],
        m->data[6],
        m->data[7]
        );
      */
        //  UNS16 cob_id; /**< message's ID */
        // UNS8 rtr;     /**< remote transmission request. (0 if not rtr message, 1 if rtr message) */
        //UNS8 len;     /**< message's length (0 to 8) */
        //UNS8 data[8]; /**< message's datas */

        
}




