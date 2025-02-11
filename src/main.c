#include "stm32h7xx.h"
#include "startup.h"
#include "systick.h"
#include "led.h"
#include "os_tasks.h"

#if ENABLE_DBG_MSG
#include "stdio.h"
#endif


#if ENABLE_DBG_MSG
int _write(int fd, char *ptr, int len){
  size_t i;
  for(i=0; i<len;i++){
    ITM_SendChar(ptr[i]);
  }
  return len;
}
#endif

int main() {

#if ENABLE_DBG_MSG
	printf("Hello World\n");
	printf("Hello World2\n");
#endif
	LED_Initializer();
	os_start();

	while(1) {
		/* Should not reach here */
		stop_cpu;
	}

}

