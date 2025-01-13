#include <unistd.h>
#include <stdio.h>
#include <sys/select.h>


struct State {
  unsigned long Out;
  unsigned long Time; 
  unsigned long Next[4];};
typedef const struct State STyp;

#define goN   0
#define waitN 1
#define goE   2
#define waitE 3

STyp FSM[4]={
 {0x21,3000,{goN,waitN,goN,waitN}},
 {0x22, 500,{goE,goE,goE,goE}},
 {0x0C,3000,{goE,goE,waitE,waitE}},
 {0x14, 500,{goN,goN,goN,goN}}};

unsigned long S;  // index to the current state

unsigned long Input=0;



// cc.byexamples.com calls this int kbhit(), to mirror the Windows console
//  function of the same name.  Otherwise, the code is the same.
int inputAvailable()  
{
  struct timeval tv;
  fd_set fds;
  tv.tv_sec = 0;
  tv.tv_usec = 0;
  FD_ZERO(&fds);
  FD_SET(STDIN_FILENO, &fds);
  select(STDIN_FILENO+1, &fds, NULL, NULL, &tv);
  return (FD_ISSET(0, &fds));
}

int main()
{ 
    char data[200];
    int oldOutput = 0;

    S = goN;
    while(1){
       usleep(10000000);

       /* add in  here your emulation of the code */

    		printf("Current value of lights: %lu\n", FSM[S].Out);

       //LIGHT = FSM[S].Out;  
      
      

  //  SysTick_Wait10ms(FSM[S].Time);   // no need of this line in initial testing
                                     // use usleep() instead of Syst=Tick_Wait

    //Input = SENSOR;             // read sensors the input value is set in the 
                                // if statement below

      if (inputAvailable()) {
    scanf("%s", data);
    printf("You entered %s\n", data);

    if (data[0] == 'N') {
        Input = 2; // 10 in binary
    } else if (data[0] == 'E') {
        Input = 1; // 01 in binary
    } else if (data[0] == 'B') {
        Input = 3; // 11 in binary
    } else {
        Input = 0; // Default value if the user enters an unrecognized key
    }
    

}

       S = FSM[S].Next[Input];     // keep this line as is
}
}

