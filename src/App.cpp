/*
 * App.cpp
 *
 *  Created on: Feb 24, 2021
 *      Author: mw
 */

#include "App.h"

#include "FreeRTOS.h"
#include "task.h"

App::App() {
    rcc_periph_clock_enable(kLedPortClk);
    gpio_set_mode(kLedGpioPort, GPIO_MODE_OUTPUT_2_MHZ, GPIO_CNF_OUTPUT_PUSHPULL, kLedGpioPin);
}

App::~App() { }

void App::run() {
    const TickType_t xDelay = 200 / portTICK_PERIOD_MS;
    for (;;) {
        vTaskDelay(xDelay);
        gpio_toggle(kLedGpioPort, kLedGpioPin);
    }
}
