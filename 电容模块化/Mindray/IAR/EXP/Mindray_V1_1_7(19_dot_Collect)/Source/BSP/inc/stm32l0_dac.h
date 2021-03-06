/****************************************************************************************************************************************************************
** 版权:          2017-2027,深圳市信为科技发展有限公司
** 文件名:        stm32l0_dac.h
** 作者:          庄明群
** 版本:          V1.0.0
** 日期:          2017-05-12
** 描述:          
** 功能:          STM32L072 DAC多通道配置 DAC转换
*****************************************************************************************************************************************************************
** 修改者:        No
** 版本:          No
** 修改内容:      No
** 日期:          No
****************************************************************************************************************************************************************/

#ifndef __STM32L0_DAC_H
#define __STM32L0_DAC_H

#include "stm32l0xx_hal_rcc.h"
#include "stm32l0xx_hal_rcc_ex.h"
#include "stm32l0xx_hal_gpio.h"
#include "stm32l0xx_hal_gpio_ex.h"
#include "stm32l0xx_hal_dma.h"
#include "stm32l0xx_hal_dac.h"
#include "stm32l0xx_hal_dac_ex.h"
#include "stm32l0xx_hal_cortex.h"
#include "VariaType.h"

#define  DAC_VALUE_MAX             4096

//以下的宏在stm32l0xx.h中定义
//typedef enum {DISABLE = 0, ENABLE = !DISABLE} FunctionalState;
//FunctionalState 只有两种可能 使能和禁止

//DAC通道选择结构体
typedef struct
{
  FunctionalState DAC_OUT0_State;
  FunctionalState DAC_OUT1_State;
}DAC_Chn_ConfigTypeDef;

//***************************************************************************************************************************************************************
// 名称               : DAC_Chn_Init()
// 创建日期           : 2017-05-12
// 作者        	      : 庄明群
// 功能               : 多通道DAC初始化
// 输入参数           : DAC_Chn_ConfigTypeDef结构体(多通道DAC使能状态)
// 输出参数           : 无
// 返回结果           : 无
// 注意和说明         : DAC引脚使能状态只有两种(ENABLE和DISABLE)
// 修改内容           :
//***************************************************************************************************************************************************************

void DAC_Chn_Init(DAC_Chn_ConfigTypeDef * gDAC_Chn_Config);

//***************************************************************************************************************************************************************
// 名称               : DAC_Chn_SetValue()
// 创建日期           : 2017-05-12
// 作者        	      : 庄明群
// 功能               : DAC通道设置输出值
// 输入参数           : ChnValue(DA值),Chn(通道号)
// 输出参数           : 无
// 返回结果           : 0(成功),1(失败)
// 注意和说明         : 输出值不能超过4095,通道号只有两种(1和2)
// 修改内容           :
//***************************************************************************************************************************************************************

uint8_t DAC_Chn_SetValue(uint16_t ChnValue, uint8_t Chn);

#endif