/*
 * init.c
 *
 *  Created on: 2018-02-10 16:37
 *      Author: Jack Chen <redchenjs@live.com>
 */

#include "device/nvs.h"
#include "device/bt.h"
#include "device/spi.h"
#include "device/i2s.h"
#include "device/wifi.h"
#include "device/uart.h"

#include "driver/led.h"
#include "driver/pn532.h"

void device_init(void)
{
    nvs0_init();
    wifi0_init();
    uart1_init();

#if defined(CONFIG_ENABLE_BLUFI)
    bt0_init();
#else
    bt0_deinit();
#endif

#if defined(CONFIG_ENABLE_AUDIO)
    i2s0_init();
#endif

#if defined(CONFIG_ENABLE_GUI)
    spi1_init();
#endif
}

void driver_init(void)
{
#if defined(CONFIG_ENABLE_LED)
    led_init();
#endif
    pn532_init();
}
