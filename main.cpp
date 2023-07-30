#include "mbed.h"
#include "canfestival.h"
//#include "ObjDict.h"
#include "TestMaster.h"
#include "TestSlave.h"


#define DEBUG_WAR_CONSOLE_ON
#define DEBUG_ERR_CONSOLE_ON

// CAN
unsigned char nodeID;

static Message m = Message_Initializer;     // contain a CAN message

DigitalOut led1(LED1);

Serial serial(USBTX, USBRX);



// ID 0012002C-464B430E-20343338
// ID 80080025-464B430C-20343338


unsigned long *id = (unsigned long *)0x1FFFF7AC;


int master = 1;

CO_Data* pDict;

extern UNS8 ObjDict_iam_a_slave;


void TestMaster_post_SlaveBootup(CO_Data* d, UNS8 nodeId)
{
    printf("TestMaster_post_SlaveBootup %x\n", nodeId);
    
    //ConfigureSlaveNode(d, nodeid);
    
    
    /* Put the master in operational mode */
    setState(d, Operational);
         
    
    /* Ask slave node to go in operational mode */
    masterSendNMTstateChange (d, nodeId, NMT_Start_Node);

}


int main() 
{

    int i=0;
    
    Message m1;
    Message m2;


    serial.baud(115200);
   
   printf("\n\n\n\n-----------------------------------------\n\n\n\n\n");     
        
    printf("ID %08X-%08X-%08X\n", id[0], id[1], id[2]);

    canInit();
    initTimer();

    
    //pDict = &ObjDict_Data;
    
    if (id[0] == 0x0012002C) 
    {
        master = 1;
        printf("Start master\n");
        pDict = &TestMaster_Data;
        //ObjDict_iam_a_slave = 0;
        
    }
    else 
    {
        master = 0;
        printf("Start slave\n");
        pDict = &TestSlave_Data;
        //ObjDict_iam_a_slave = 1;
    }
   /* 
    if (master) {
      for(;;) 
      {
            if (canReceive(&m1)) {
                printf("Received %d\n", m1.cob_id);
            }
            m1.cob_id = 1;            
            canSend(NULL, &m1);            
            printf("Sent %d\n", m1.cob_id); 
            wait(1);                                
        }    
    }
    else {
      for(;;) 
      {
            if (canReceive(&m2)) {
                printf("Received %d\n", m2.cob_id);
            }
            m2.cob_id = 0;            
            canSend(NULL, &m2);            
            printf("Sent %d\n", m2.cob_id);   
            wait(1);                             
        }    
        
    }
    */
    
    
    
                               
    MSG_WAR(0x3407, "Start  ", 0);         
                
    if (master)
    {
        
        TestMaster_Data.post_SlaveBootup = TestMaster_post_SlaveBootup;
        
        setNodeId (pDict, 0x01);
        setState(pDict, Initialisation);  // Init the state
        //setState(pDict, Operational);
    }
    else 
    {
        setNodeId (pDict, 0x02);
        setState(pDict, Initialisation);  // Init the state
                
    }
  

  for(;;)                               // forever loop
  {

    if (canReceive(&m)) {         
      canDispatch(pDict, &m);     
      led1 = !led1;
    }
          
          
  }
  
  

}