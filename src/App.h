/*
 * App.h
 *
 *  Created on: Feb 24, 2021
 *      Author: mw
 */

#pragma once

#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>

/**
 * The main application class.
 */
class App {
public:
    /**
     * Constructor.
     */
    App();

    /**
     * Destructor.
     */
    virtual ~App();

    /**
     * This is main application task and should be run in separate thread.
     */
    void run();

private:
    static constexpr auto kLedPortClk = RCC_GPIOC;
    static constexpr auto kLedGpioPort = GPIOC;
    static constexpr auto kLedGpioPin = GPIO13;
};
