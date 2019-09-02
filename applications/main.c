/*
 * Copyright (c) 2006-2018, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2019-07-23     tyustli      first version
 */

#include <rtthread.h>
#include <rtdevice.h>

#include "gd32vf103_rcu.h"
#include "gd32vf103_gpio.h"

int main(int argc, char *argv[])
{
    rt_kprintf("hello GD32VF103VBT6! build %s %s\r\n", __DATE__, __TIME__);

    // gpio clk
    rcu_periph_clock_enable(RCU_GPIOE);
    // gpio init
    gpio_init(GPIOE, GPIO_MODE_OUT_PP, GPIO_OSPEED_2MHZ, GPIO_PIN_3);

    while (1)
    {
        gpio_bit_reset(GPIOE, GPIO_PIN_3);
        rt_kprintf("len on\r\n");
        rt_thread_mdelay(1000);

        gpio_bit_set(GPIOE, GPIO_PIN_3);
        rt_kprintf("led off\r\n");
        rt_thread_mdelay(1000);

    }
    
    return RT_EOK;
}

/******************** end of file *******************/
