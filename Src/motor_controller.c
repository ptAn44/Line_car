#include "user_define.h"
#include "motor_controller.h"

void Motor_Init (void){
	HAL_TIM_PWM_Start(&MOTOR0_TIMER,MOTOR0_CHANNEL);
	HAL_TIM_PWM_Start(&MOTOR1_TIMER,MOTOR1_CHANNEL);
}

void Motor_Set_Speed(motor_t motor,int16_t speed){
	if(speed <-255){
		speed = -255;
	}else if(speed >255){
		speed =255;
	}
	switch(motor){
		case MOTOR_0:
		{
			if(speed>=0){
#ifdef MOTOR0_REVERT
			HAL_GPIO_WritePin(MOTOR0_DIR0_PORT,MOTOR0_DIR0_PIN,GPIO_PIN_SET);
			HAL_GPIO_WritePin(MOTOR0_DIR1_PORT,MOTOR0_DIR1_PIN,GPIO_PIN_RESET);
#else
			HAL_GPIO_WritePin(MOTOR0_DIR0_PORT,MOTOR0_DIR0_PIN,GPIO_PIN_RESET);
			HAL_GPIO_WritePin(MOTOR0_DIR1_PORT,MOTOR0_DIR1_PIN,GPIO_PIN_SET);	
#endif
			}
			else{
#ifdef MOTOR0_REVERT
			HAL_GPIO_WritePin(MOTOR0_DIR0_PORT,MOTOR0_DIR0_PIN,GPIO_PIN_RESET);
			HAL_GPIO_WritePin(MOTOR0_DIR1_PORT,MOTOR0_DIR1_PIN,GPIO_PIN_SET);
#else
			HAL_GPIO_WritePin(MOTOR0_DIR0_PORT,MOTOR0_DIR0_PIN,GPIO_PIN_SET);
			HAL_GPIO_WritePin(MOTOR0_DIR1_PORT,MOTOR0_DIR1_PIN,GPIO_PIN_RESET);
#endif
			}
		}
		case MOTOR_1:
		{
			if(speed>=0){
#ifdef MOTOR1_REVERT
			HAL_GPIO_WritePin(MOTOR1_DIR0_PORT,MOTOR1_DIR0_PIN,GPIO_PIN_SET);
			HAL_GPIO_WritePin(MOTOR1_DIR1_PORT,MOTOR1_DIR1_PIN,GPIO_PIN_RESET);
#else
			HAL_GPIO_WritePin(MOTOR1_DIR0_PORT,MOTOR1_DIR0_PIN,GPIO_PIN_RESET);
			HAL_GPIO_WritePin(MOTOR1_DIR1_PORT,MOTOR1_DIR1_PIN,GPIO_PIN_SET);	
#endif
			}
			else{
#ifdef MOTOR1_REVERT
			HAL_GPIO_WritePin(MOTOR1_DIR0_PORT,MOTOR1_DIR0_PIN,GPIO_PIN_RESET);
			HAL_GPIO_WritePin(MOTOR1_DIR1_PORT,MOTOR1_DIR1_PIN,GPIO_PIN_SET);
#else
			HAL_GPIO_WritePin(MOTOR1_DIR0_PORT,MOTOR1_DIR0_PIN,GPIO_PIN_SET);
			HAL_GPIO_WritePin(MOTOR1_DIR1_PORT,MOTOR1_DIR1_PIN,GPIO_PIN_RESET);
#endif
			}
		}
	}
}