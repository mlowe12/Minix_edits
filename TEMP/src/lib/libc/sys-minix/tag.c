
#include <lib.h>

int get_tag(int PID) {

  message m;  // Minix uses message to pass parameters to a system call
  m.m1_i1 = 0;
  m.m1_i2 = PID;

return   _syscall(PM_PROC_NR, DO_PROJECT1_SYSCALL, &m);
      /* _syscall leads to the system server identified by PM_PRO_NR (the PM
       * server process) invoking the function identified by call number
       * PRINTMSG with parameters in the message copied to address &m
       */
}

int set_tag(int PID, int new_value) {

  message m;  // Minix uses message to pass parameters to a system call
  m.m1_i1 = 1;
  m.m1_i2 = PID;
  m.m1_i3 = new_value;


return  _syscall(PM_PROC_NR, DO_PROJECT1_SYSCALL, &m);
      /* _syscall leads to the system server identified by PM_PRO_NR (the PM
       * server process) invoking the function identified by call number
       * PRINTMSG with parameters in the message copied to address &m
       */
}
