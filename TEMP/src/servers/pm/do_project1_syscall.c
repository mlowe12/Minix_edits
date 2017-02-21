#include <stdio.h>
#include "pm.h"
#include "mproc.h"


int do_project1_syscall(void){

    int z_flag = m_in.m1_i1;
    int PID = m_in.m1_i2;

    struct mproc* req_process = find_proc(PID);


    if(req_process == NULL){return -1;}


    if(z_flag){

      // perform set_tag
        int new_value = m_in.m1_i3;

        if(new_value < 0){return -1; }
        if(mp->mp_effuid != 0){return -1;}


        req_process->tag = new_value;

        return req_process->tag;
    }



    else{

      if(mp->mp_effuid != 0 && mp->mp_pid != PID){return -1;}

      //perform get_tag
      return req_process->tag;

    }

      //printf("System call 'DO_PROJECT1_SYSCALL' is called. %d\n", m_in.m1_i1);

}
