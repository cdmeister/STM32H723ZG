#include "stm32h7xx.h"
#include "startup.h"
#include "systick.h"
#include "scheduler.h"
#include "task_management.h"



extern struct task_block TASKS[MAX_TASKS];
extern struct task_block * tasklist_active;
extern struct task_block * tasklist_waiting;
extern struct task_block *t_cur;

#define kernel TASKS[0]
#define BUTTON_DEBOUNCE_TIME 120
struct task_block *button_task = NULL;
static void (*button_callback)(void) = NULL;



void delay(uint32_t count);
void sleep_ms(int ms);
int button_read(void);
void button_start_read(void);


void sleep_ms(int ms)
{
    if (ms < 2)
        return;
    t_cur->wakeup_time = milliseconds + ms;
    task_waiting(t_cur);
    schedule();
}

void task_test0(void *arg) {
  uint32_t now = millis();
  GPIOB->ODR = 0x4000;
  while(1) {
    if ((millis() - now) > 1000) {
      GPIOB->ODR = 0x000;
      schedule();
      now = millis();
      GPIOB->ODR = 0x4000;
    }
  }
}

void task_test1(void *arg) {
	GPIOB->ODR = 0x4000;
  while(1) {
    sleep_ms(125);
	  GPIOB->ODR ^= 0x4000;
  }
}


void task_test2(void *arg)

{
  uint32_t toggle_time = 0;
  GPIOE->ODR = 0x0000;
  while(1) {
    if (button_read()) {
        GPIOE->ODR ^= 0x02;
        toggle_time = milliseconds;
    }
  }
}

int button_read(void)

{
  if (button_task)
    return 0;
  button_task = t_cur;
  task_waiting(t_cur);
  button_start_read();
  schedule();
  return 1;
}


void button_wakeup(void)

{
  if (button_task) {
    task_ready(button_task);
    button_task = NULL;
    schedule();
  }
}

void button_setup(void){
  /* Push button */
  GPIOC->MODER &= ~(GPIO_MODER_MODE13);
  button_callback = button_wakeup;
  // Select PC13 as the trigger source of EXTI 13
  SYSCFG->EXTICR[3] &= ~SYSCFG_EXTICR4_EXTI13; //clear EXTI 13
  SYSCFG->EXTICR[3] |= SYSCFG_EXTICR4_EXTI13_PC; // set EXTI14 to map ext interrupt
                                               //  to PC13
  // Enable rising edge trigger for EXTI 11
  // Rising edge trigger selection register (RSTR)
  // 0 = disable  1 = enable
  EXTI->RTSR1 &= ~EXTI_RTSR1_TR13;
  EXTI->RTSR1 |= EXTI_RTSR1_TR13;
  EXTI->FTSR1 &= ~EXTI_FTSR1_TR13;
  EXTI->IMR1 &= ~EXTI_IMR1_IM13;
  EXTI->IMR1 |= EXTI_IMR1_IM13;

  // Set EXTI 11 priority to 1
  NVIC_SetPriority(EXTI15_10_IRQn, 1);

 }

void EXTI15_10_IRQHandler (void){

    // Check for EXTI 11 flag
  if((EXTI->PR1 & EXTI_PR1_PR13_Msk) == EXTI_PR1_PR13){
    NVIC_DisableIRQ(EXTI15_10_IRQn);

    // Clear interupt pending request
    EXTI->PR1 |= EXTI_PR1_PR13;

    if (button_callback)
      button_callback();
   }

}


void button_start_read() {
  // Enable EXT 11 interrupt
  NVIC_EnableIRQ(EXTI15_10_IRQn);

}


int main() {

   RCC->AHB2ENR |= (RCC_AHB2ENR_D2SRAM1EN | RCC_AHB2ENR_D2SRAM2EN);
	/* Enable clock on GPIOB GPIOC GPIOE peripheral */
	RCC->AHB4ENR = 0x1F;
  RCC->APB4ENR |= (RCC_APB4ENR_SYSCFGEN);
	/* Configure the PA5 as output pull-up */
  /* red led */
  GPIOB->MODER &= ~(GPIO_MODER_MODE14);
  GPIOB->MODER |= (GPIO_MODER_MODE14_0);


  /* Yellow led */
	GPIOE->MODER &= 0x4; // Sets MODER[11:10] = 0x1

	systick_config(SystemCoreClock/1000);
  button_setup();

	kernel.name[0] = 0;
  kernel.id = 0;
  kernel.state = TASK_RUNNING;
  kernel.wakeup_time = 0;
  tasklist_add(&tasklist_active, &kernel);
  //task_create("test0",task_test0, NULL);
  task_create("test1",task_test1, NULL);
  task_create("test2",task_test2, NULL);
  while(1) {
    struct task_block *t = tasklist_waiting;
    while (t) {
      if (t->wakeup_time && (t->wakeup_time < milliseconds)) {
        t->wakeup_time = 0;
        task_ready(t);
      }
      t = t->next;
    }
    __WFI();
  }
}

