#ifndef __LED_H
#define __LED_H

#include "stm32f3xx_hal.h"

static void init_led_gpio();
static void init_timer_periph();
static void init_timer_events();
static void init_timer_dma();

void DMA1_Channel2_IRQHandler(void);
void transfer_complete_handler(DMA_HandleTypeDef *dma_handle);

void send_buffer();
void init_leds();

#endif