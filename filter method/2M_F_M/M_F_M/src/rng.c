/**
 * @file         rng.c
 * @brief        随机数的中位值滤波法
 * @author       韦剑祥
 * @date         2020-07-03
 * @version      V1.0.0
 * @copyright    2020-2030,深圳市信为科技发展有限公司
 **********************************************************************************
 * @par 修改日志:
 * <table>
 * <tr><th>Date        <th>Version  <th>Author    <th>Description
 * <tr><td>2020/07/03  <td>1.0.0    <td>韦剑祥    <td>创建初始版本
 * </table>
 *
 **********************************************************************************
*/


/* Includes ------------------------------------------------------------------*/
#include "rng.h"

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

RNG_HandleTypeDef hrng;

#define    FILTER_N      101			//随机数个数为奇数



/* RNG init function */
void MX_RNG_Init(void)
{

  hrng.Instance = RNG;
  hrng.Init.ClockErrorDetection = RNG_CED_ENABLE;
  if (HAL_RNG_Init(&hrng) != HAL_OK)
  {
    Error_Handler();
  }

}

void HAL_RNG_MspInit(RNG_HandleTypeDef* rngHandle)
{

  if(rngHandle->Instance==RNG)
  {
  /* USER CODE BEGIN RNG_MspInit 0 */

  /* USER CODE END RNG_MspInit 0 */
    /* RNG clock enable */
    __HAL_RCC_RNG_CLK_ENABLE();
  /* USER CODE BEGIN RNG_MspInit 1 */

  /* USER CODE END RNG_MspInit 1 */
  }
}

void HAL_RNG_MspDeInit(RNG_HandleTypeDef* rngHandle)
{

  if(rngHandle->Instance==RNG)
  {
  /* USER CODE BEGIN RNG_MspDeInit 0 */

  /* USER CODE END RNG_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_RNG_CLK_DISABLE();
  /* USER CODE BEGIN RNG_MspDeInit 1 */

  /* USER CODE END RNG_MspDeInit 1 */
  }
} 

/**
* @brief       得到随机数
* @param    	None
* @return       获取到的随机数
*/
uint32_t RNG_Get_RandomNum(void)
{
	uint32_t randomnum;
	
    HAL_RNG_GenerateRandomNumber(&hrng,&randomnum);
	return randomnum;
}

/**
* @brief       生成[min,max]范围的随机数
* @param        min: 最小值    max: 最大值
* @return       随机数
*/
int RNG_Get_RandomRange(int min,int max)
{ 
	uint32_t randomnum;
	
	HAL_RNG_GenerateRandomNumber(&hrng,&randomnum);
	return randomnum%(max-min+1)+min;
}

/**
* @brief     中位值滤波法
* @retval    数组中间的值
*/
int Filter(void)
{
	int filter_buf[FILTER_N];
	
	int i, j;
	int filter_temp;
	
	for(i = 0; i < FILTER_N; i++)
	{
		filter_buf[i] = RNG_Get_RandomRange(295, 305);
		HAL_Delay(1);
		
	}
	//采样值从小到大排序（冒泡法）
	for(j = 0; j < FILTER_N - 1; j++)
	{
		for(i = 0; i < FILTER_N - 1 - j; i++)
		{
			if(filter_buf[i] > filter_buf[i + 1])
			{
				filter_temp = filter_buf[i];
				filter_buf[i] = filter_buf[i + 1];
				filter_buf[i + 1] = filter_temp;
			
			}
			
		}
		
	}
	
	return filter_buf[(FILTER_N - 1) / 2];

}
/* USER CODE BEGIN 1 */

/* USER CODE END 1 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
