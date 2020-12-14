#include "ipc-msg-common.h"

int main() {

    int q_id; //Message queue key
    struct msgbuf msg; //msg variable
    msg.mtype = 0;
    int num_bytes; 
    int ret_val;

    //Setting message queue
    q_id = msgget(MY_KEY, IPC_CREAT | 0600);
    TEST_ERROR;
    printf("Setting message queue with identifier: %d\n",q_id);

    printf("\n----------------------\n");
    printf("Welcome to the message sender jungle center!!\n");
    printf("----------------------\n\n");

    //Sending messages
    do{

        printf("Type of message (type a value <= 0 to end the program):");
        scanf("%ld",&msg.mtype);
        getchar();

        if(msg.mtype > 0){
            printf("Message: ");
            fgets(msg.mtext,MSG_LEN,stdin);
            num_bytes = strlen(msg.mtext);
            num_bytes++; //Incrementing to add \0 escape character

            msgsnd(q_id, &msg, num_bytes, 0);
            if(msg.mtype == MSGTYPE_RM){ 
                printf("WARNING: THIS A QUEUE DEALLOCATOR MESSAGE!\n");
            }
            printf("We just sent a message of %d bytes: %s\n",num_bytes,msg.mtext);
        }

    }while(msg.mtype > 0 && msg.mtype != MSGTYPE_RM);

    printf("\nSender work ended.\n");
    if(msg.mtype == MSGTYPE_RM){ 
        printf("And queue #%d, succesfully deallocated.\n",q_id);
    }

    exit(EXIT_SUCCESS);
}