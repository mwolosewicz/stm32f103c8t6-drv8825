/* Simple LED task demo:
 *
 * The LED on PC13 is toggled in task1.
 */
#include "FreeRTOS.h"
#include "task.h"

#include "App.h"

#include "libopencm3/stm32/rcc.h"

#ifdef __cplusplus
extern "C" {
#endif

extern void vApplicationStackOverflowHook(xTaskHandle *pxTask,signed portCHAR *pcTaskName);

void vApplicationStackOverflowHook(xTaskHandle *pxTask,signed portCHAR *pcTaskName) {
    (void)pxTask;
    (void)pcTaskName;
    for(;;);
}

#ifdef __cplusplus
}
#endif

/**
 * The main application task.
 */
static void appTask(void *args) {
    (void)args;
    App app;
    app.run();
}

int main(void) {
    rcc_clock_setup_pll(&rcc_hse_configs[RCC_CLOCK_HSE8_72MHZ]);

    xTaskCreate(appTask, "app", 100, NULL, configMAX_PRIORITIES-1, NULL);
    vTaskStartScheduler();
    for (;;);

    return 0;
}
