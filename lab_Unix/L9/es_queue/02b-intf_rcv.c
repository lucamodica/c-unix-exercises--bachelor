#include "ipc-msg-common.h"

int main() {

    int q_id; //Message queue key
    struct msgbuf rcv_msg; //msg variable
    int rcv_bytes; 
    int ret_val;
    long type;

    //Setting message queue
    q_id = msgget(MY_KEY, IPC_CREAT | 0600);
    TEST_ERROR;
    printf("Setting message queue with identifier: %d\n",q_id);

    printf("\n----------------------\n");
    printf("Welcome to the message receiver jungle center!!\n");
    printf("----------------------\n\n");

    //Entering the type of messages
    printf("Type of message (type '0' to receive all kind of messages here): ");
    scanf("%ld",&type);

    //Receiving messages
    printf("Waiting for messages....\n\n");
    while (1){
        
        rcv_bytes = msgrcv(q_id,&rcv_msg,MSG_LEN,type,0);

        //Checking if bytes was received
        if(rcv_bytes >= 0){ break; }

        //Handling errors
        switch (rcv_bytes){
            case EACCES:
                printf("You don't have the permission to receive a message!!\n\n");
                break;

            case EIDRM:
                printf("Nope. This queue was already removed, so no messages for you.\n\n");
                break;

            case EINTR:
                printf("Type of message not found.\n\n");
                break;

            default:
                break;
        }

    }

    printf("Received type %ld messages of %d bytes: %s.\n",type,rcv_bytes,rcv_msg.mtext);

    //If mtype == MSGTYPE_RM, the queue will be also deallocated
    if(rcv_msg.mtype == MSGTYPE_RM){
        printf("This, is also an deallocated-type message! The queue #%d was also removed, bye.\n",q_id);
    }
    
    

    exit(EXIT_SUCCESS);
}