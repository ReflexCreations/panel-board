#ifndef __ADC_H
#define __ADC_H

#include "stm32f3xx_hal.h"

static void init_adc_periph();
static void init_adc_channels();
static void init_adc_gpio();
static void init_adc_dma();
void init_adc();

void ADC_IRQHandler();
void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef *adc_handle);

#endif