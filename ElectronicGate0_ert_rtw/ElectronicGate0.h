/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ElectronicGate0.h
 *
 * Code generated for Simulink model 'ElectronicGate0'.
 *
 * Model version                  : 1.71
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Wed Jun  5 10:03:22 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_ElectronicGate0_h_
#define RTW_HEADER_ElectronicGate0_h_
#ifndef ElectronicGate0_COMMON_INCLUDES_
#define ElectronicGate0_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* ElectronicGate0_COMMON_INCLUDES_ */

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  real_T working_time;                 /* '<S1>/SYSTEM CORE' */
  real_T closing_time;                 /* '<S1>/SYSTEM CORE' */
  int32_T sfEvent;                     /* '<S1>/SYSTEM CORE' */
  uint32_T temporalCounter_i1;         /* '<S1>/SYSTEM CORE' */
  uint32_T durationCounter_1;          /* '<S1>/SYSTEM CORE' */
  uint8_T is_TOGGLE_YELLOW;            /* '<S1>/TOGGLE_YELLOW_LED' */
  uint8_T is_SWITCH;                   /* '<S1>/TOGGLE_YELLOW_LED' */
  uint8_T is_BLINKING;                 /* '<S1>/TOGGLE_YELLOW_LED' */
  uint8_T is_active_c5_ElectronicGate0;/* '<S1>/TOGGLE_YELLOW_LED' */
  uint8_T temporalCounter_i1_j;        /* '<S1>/TOGGLE_YELLOW_LED' */
  uint8_T is_TOGGLE_GREEN;             /* '<S1>/TOGGLE_GREEN_LED' */
  uint8_T is_SWITCH_e;                 /* '<S1>/TOGGLE_GREEN_LED' */
  uint8_T is_BLINKING_n;               /* '<S1>/TOGGLE_GREEN_LED' */
  uint8_T is_active_c1_ElectronicGate0;/* '<S1>/TOGGLE_GREEN_LED' */
  uint8_T temporalCounter_i1_d;        /* '<S1>/TOGGLE_GREEN_LED' */
  uint8_T is_c3_ElectronicGate0;       /* '<S1>/SYSTEM CORE' */
  uint8_T is_GATE;                     /* '<S1>/SYSTEM CORE' */
  uint8_T is_OPEN;                     /* '<S1>/SYSTEM CORE' */
  uint8_T is_CLOSE;                    /* '<S1>/SYSTEM CORE' */
  uint8_T is_B1;                       /* '<S1>/SYSTEM CORE' */
  uint8_T is_B2;                       /* '<S1>/SYSTEM CORE' */
  uint8_T is_B3;                       /* '<S1>/SYSTEM CORE' */
  uint8_T is_WORKING_TIME;             /* '<S1>/SYSTEM CORE' */
  uint8_T is_CLOSING_TIME;             /* '<S1>/SYSTEM CORE' */
  uint8_T is_active_c3_ElectronicGate0;/* '<S1>/SYSTEM CORE' */
  uint8_T is_active_WORKING_TIME;      /* '<S1>/SYSTEM CORE' */
  uint8_T is_active_CLOSING_TIME;      /* '<S1>/SYSTEM CORE' */
  uint8_T is_active_GATE;              /* '<S1>/SYSTEM CORE' */
  uint8_T is_active_B3;                /* '<S1>/SYSTEM CORE' */
  uint8_T is_active_B2;                /* '<S1>/SYSTEM CORE' */
  uint8_T is_active_B1;                /* '<S1>/SYSTEM CORE' */
  boolean_T enable_green;              /* '<S1>/SYSTEM CORE' */
  boolean_T blink_green;               /* '<S1>/SYSTEM CORE' */
  boolean_T enable_yellow;             /* '<S1>/SYSTEM CORE' */
  boolean_T blink_yellow;              /* '<S1>/SYSTEM CORE' */
} DW;

/* External inputs (root inport signals with default storage) */
typedef struct {
  boolean_T p1;                        /* '<Root>/p1' */
  boolean_T p2;                        /* '<Root>/p2' */
  boolean_T b1;                        /* '<Root>/b1' */
  boolean_T b2;                        /* '<Root>/b2' */
  boolean_T b3;                        /* '<Root>/b3' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  boolean_T green_led;                 /* '<Root>/green_led' */
  boolean_T red_led;                   /* '<Root>/red_led' */
  boolean_T yellow_led;                /* '<Root>/yellow_led' */
} ExtY;

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T * volatile errorStatus;
};

/* Block signals and states (default storage) */
extern DW rtDW;

/* External inputs (root inport signals with default storage) */
extern ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY rtY;

/* Model entry point functions */
extern void ElectronicGate0_initialize(void);
extern void ElectronicGate0_step(void);

/* Real-time Model object */
extern RT_MODEL *const rtM;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('ElectronicGateDeploy/ElectronicGate')    - opens subsystem ElectronicGateDeploy/ElectronicGate
 * hilite_system('ElectronicGateDeploy/ElectronicGate/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'ElectronicGateDeploy'
 * '<S1>'   : 'ElectronicGateDeploy/ElectronicGate'
 * '<S2>'   : 'ElectronicGateDeploy/ElectronicGate/SYSTEM CORE'
 * '<S3>'   : 'ElectronicGateDeploy/ElectronicGate/TOGGLE_GREEN_LED'
 * '<S4>'   : 'ElectronicGateDeploy/ElectronicGate/TOGGLE_YELLOW_LED'
 */
#endif                                 /* RTW_HEADER_ElectronicGate0_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
