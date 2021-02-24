/* Simple LED task demo:
 *
 * The LED on PC13 is toggled in task1.
 */
#include "FreeRTOS.h"
#include "task.h"

#include "main.h"

#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>

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


static void initDeviceClock() {
    rcc_clock_setup_pll(&rcc_hse_configs[RCC_CLOCK_HSE8_72MHZ]);
}

static void initGpio() {
    rcc_periph_clock_enable(RCC_GPIOC);
    gpio_set_mode(GPIOC,GPIO_MODE_OUTPUT_2_MHZ,GPIO_CNF_OUTPUT_PUSHPULL,GPIO13);
}

static void init() {
    initDeviceClock();
    initGpio();
}

void App::run() {
    const TickType_t xDelay = 200 / portTICK_PERIOD_MS;
    for (;;) {
        vTaskDelay(xDelay);
        gpio_toggle(GPIOC,GPIO13);
    }
}

/**
 * The main application task.
 */
static void appTask(void *args) {
    (void)args;

    App app;
    app.run();
}


int main(void) {
    init();

    xTaskCreate(appTask, "app", 100, NULL, configMAX_PRIORITIES-1, NULL);
    vTaskStartScheduler();
    for (;;);

    return 0;
}
