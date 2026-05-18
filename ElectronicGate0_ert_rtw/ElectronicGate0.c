/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ElectronicGate0.c
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

#include "ElectronicGate0.h"
#include "rtwtypes.h"
#include <math.h>
#include <stddef.h>

/* Named constants for Chart: '<S1>/SYSTEM CORE' */
#define CALL_EVENT                     (-1)
#define INCREMENT                      (10.0)
#define IN_CLOSE                       ((uint8_T)1U)
#define IN_CLOSING_TIME_INC            ((uint8_T)1U)
#define IN_CLOSING_TIME_RESET          ((uint8_T)2U)
#define IN_ERROR_STATE                 ((uint8_T)2U)
#define IN_GREEN_BLK_OFF               ((uint8_T)1U)
#define IN_GREEN_BLK_ON                ((uint8_T)2U)
#define IN_IS_CLOSING                  ((uint8_T)3U)
#define IN_IS_OPENING                  ((uint8_T)4U)
#define IN_LONG_PRESSED                ((uint8_T)1U)
#define IN_NO_ACTIVE_CHILD             ((uint8_T)0U)
#define IN_OPEN                        ((uint8_T)5U)
#define IN_PRESSED                     ((uint8_T)2U)
#define IN_RELEASED                    ((uint8_T)3U)
#define IN_STOP_SYSTEM                 ((uint8_T)6U)
#define IN_SYSTEM                      ((uint8_T)1U)
#define IN_WORKING_TIME_INC            ((uint8_T)1U)
#define IN_WORKING_TIME_RESET          ((uint8_T)2U)
#define MAX                            (120.0)
#define OFF                            (false)
#define ON                             (true)
#define event_b1_pressed               (0)
#define event_b2_pressed               (1)
#define event_b3_pressed               (2)

/* Named constants for Chart: '<S1>/TOGGLE_GREEN_LED' */
#define IN_BLINKING                    ((uint8_T)1U)
#define IN_BLINKING_OFF                ((uint8_T)1U)
#define IN_BLINKING_ON                 ((uint8_T)2U)
#define IN_SWITCH                      ((uint8_T)2U)
#define IN_SWITCH_OFF                  ((uint8_T)1U)
#define IN_SWITCH_ON                   ((uint8_T)2U)
#define NumBitsPerChar                 8U

/* Block signals and states (default storage) */
DW rtDW;

/* External inputs (root inport signals with default storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;

/* Real-time model */
static RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;

/* Forward declaration for local functions */
static real_T mod(real_T x);
static void GATE(void);
static void broadcast_b3_pressed_c3_Electro(void);
static void broadcast_b2_pressed_c3_Electro(void);
static void broadcast_b1_pressed_c3_Electro(void);
static void c3_ElectronicGate0(void);
static real_T rtGetNaN(void);
static real32_T rtGetNaNF(void);

#define NOT_USING_NONFINITE_LITERALS   1

extern real_T rtInf;
extern real_T rtMinusInf;
extern real_T rtNaN;
extern real32_T rtInfF;
extern real32_T rtMinusInfF;
extern real32_T rtNaNF;
static void rt_InitInfAndNaN(size_t realSize);
static boolean_T rtIsInf(real_T value);
static boolean_T rtIsInfF(real32_T value);
static boolean_T rtIsNaN(real_T value);
static boolean_T rtIsNaNF(real32_T value);
typedef struct {
  struct {
    uint32_T wordH;
    uint32_T wordL;
  } words;
} BigEndianIEEEDouble;

typedef struct {
  struct {
    uint32_T wordL;
    uint32_T wordH;
  } words;
} LittleEndianIEEEDouble;

typedef struct {
  union {
    real32_T wordLreal;
    uint32_T wordLuint;
  } wordL;
} IEEESingle;

real_T rtInf;
real_T rtMinusInf;
real_T rtNaN;
real32_T rtInfF;
real32_T rtMinusInfF;
real32_T rtNaNF;
static real_T rtGetInf(void);
static real32_T rtGetInfF(void);
static real_T rtGetMinusInf(void);
static real32_T rtGetMinusInfF(void);

/*
 * Initialize rtNaN needed by the generated code.
 * NaN is initialized as non-signaling. Assumes IEEE.
 */
static real_T rtGetNaN(void)
{
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  real_T nan = 0.0;
  if (bitsPerReal == 32U) {
    nan = rtGetNaNF();
  } else {
    union {
      LittleEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.bitVal.words.wordH = 0xFFF80000U;
    tmpVal.bitVal.words.wordL = 0x00000000U;
    nan = tmpVal.fltVal;
  }

  return nan;
}

/*
 * Initialize rtNaNF needed by the generated code.
 * NaN is initialized as non-signaling. Assumes IEEE.
 */
static real32_T rtGetNaNF(void)
{
  IEEESingle nanF = { { 0.0F } };

  nanF.wordL.wordLuint = 0xFFC00000U;
  return nanF.wordL.wordLreal;
}

/*
 * Initialize the rtInf, rtMinusInf, and rtNaN needed by the
 * generated code. NaN is initialized as non-signaling. Assumes IEEE.
 */
static void rt_InitInfAndNaN(size_t realSize)
{
  (void) (realSize);
  rtNaN = rtGetNaN();
  rtNaNF = rtGetNaNF();
  rtInf = rtGetInf();
  rtInfF = rtGetInfF();
  rtMinusInf = rtGetMinusInf();
  rtMinusInfF = rtGetMinusInfF();
}

/* Test if value is infinite */
static boolean_T rtIsInf(real_T value)
{
  return (boolean_T)((value==rtInf || value==rtMinusInf) ? 1U : 0U);
}

/* Test if single-precision value is infinite */
static boolean_T rtIsInfF(real32_T value)
{
  return (boolean_T)(((value)==rtInfF || (value)==rtMinusInfF) ? 1U : 0U);
}

/* Test if value is not a number */
static boolean_T rtIsNaN(real_T value)
{
  boolean_T result = (boolean_T) 0;
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  if (bitsPerReal == 32U) {
    result = rtIsNaNF((real32_T)value);
  } else {
    union {
      LittleEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.fltVal = value;
    result = (boolean_T)((tmpVal.bitVal.words.wordH & 0x7FF00000) == 0x7FF00000 &&
                         ( (tmpVal.bitVal.words.wordH & 0x000FFFFF) != 0 ||
                          (tmpVal.bitVal.words.wordL != 0) ));
  }

  return result;
}

/* Test if single-precision value is not a number */
static boolean_T rtIsNaNF(real32_T value)
{
  IEEESingle tmp;
  tmp.wordL.wordLreal = value;
  return (boolean_T)( (tmp.wordL.wordLuint & 0x7F800000) == 0x7F800000 &&
                     (tmp.wordL.wordLuint & 0x007FFFFF) != 0 );
}

/*
 * Initialize rtInf needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
static real_T rtGetInf(void)
{
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  real_T inf = 0.0;
  if (bitsPerReal == 32U) {
    inf = rtGetInfF();
  } else {
    union {
      LittleEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.bitVal.words.wordH = 0x7FF00000U;
    tmpVal.bitVal.words.wordL = 0x00000000U;
    inf = tmpVal.fltVal;
  }

  return inf;
}

/*
 * Initialize rtInfF needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
static real32_T rtGetInfF(void)
{
  IEEESingle infF;
  infF.wordL.wordLuint = 0x7F800000U;
  return infF.wordL.wordLreal;
}

/*
 * Initialize rtMinusInf needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
static real_T rtGetMinusInf(void)
{
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  real_T minf = 0.0;
  if (bitsPerReal == 32U) {
    minf = rtGetMinusInfF();
  } else {
    union {
      LittleEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.bitVal.words.wordH = 0xFFF00000U;
    tmpVal.bitVal.words.wordL = 0x00000000U;
    minf = tmpVal.fltVal;
  }

  return minf;
}

/*
 * Initialize rtMinusInfF needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
static real32_T rtGetMinusInfF(void)
{
  IEEESingle minfF;
  minfF.wordL.wordLuint = 0xFF800000U;
  return minfF.wordL.wordLreal;
}

/* Function for Chart: '<S1>/SYSTEM CORE' */
static real_T mod(real_T x)
{
  real_T r;
  if (rtIsNaN(x)) {
    r = (rtNaN);
  } else if (rtIsInf(x)) {
    r = (rtNaN);
  } else if (x == 0.0) {
    r = 0.0;
  } else {
    r = fmod(x, MAX);
    if (r == 0.0) {
      r = 0.0;
    } else if (x < 0.0) {
      r += MAX;
    }
  }

  return r;
}

/* Function for Chart: '<S1>/SYSTEM CORE' */
static void GATE(void)
{
  switch (rtDW.is_GATE) {
   case IN_CLOSE:
    /* Inport: '<Root>/p1' */
    if ((rtDW.sfEvent == event_b1_pressed) && rtU.p1) {
      rtDW.is_CLOSE = IN_NO_ACTIVE_CHILD;
      rtDW.is_GATE = IN_IS_OPENING;
      rtDW.temporalCounter_i1 = 0U;

      /* Outport: '<Root>/red_led' */
      rtY.red_led = OFF;
      rtDW.enable_yellow = OFF;
      rtDW.enable_green = OFF;
      rtDW.blink_green = OFF;
      rtDW.blink_yellow = ON;
    } else {
      switch (rtDW.is_CLOSE) {
       case IN_GREEN_BLK_OFF:
        rtDW.enable_green = OFF;

        /* Outport: '<Root>/red_led' */
        rtY.red_led = OFF;
        rtDW.enable_yellow = OFF;
        rtDW.blink_green = OFF;
        rtDW.blink_yellow = OFF;
        if ((rtDW.sfEvent == event_b1_pressed) && (!rtU.p1)) {
          rtDW.is_CLOSE = IN_GREEN_BLK_ON;
          rtDW.temporalCounter_i1 = 0U;
          rtDW.blink_green = ON;
        }
        break;

       case IN_GREEN_BLK_ON:
        rtDW.enable_green = OFF;

        /* Outport: '<Root>/red_led' */
        rtY.red_led = OFF;
        rtDW.enable_yellow = OFF;
        rtDW.blink_green = ON;
        rtDW.blink_yellow = OFF;
        if ((rtDW.temporalCounter_i1 >= 150U) || rtU.p1) {
          rtDW.is_CLOSE = IN_GREEN_BLK_OFF;
          rtDW.blink_green = OFF;
        } else if ((rtDW.sfEvent == event_b1_pressed) && (!rtU.p1)) {
          rtDW.is_CLOSE = IN_GREEN_BLK_ON;
          rtDW.temporalCounter_i1 = 0U;
        }
        break;
      }
    }
    break;

   case IN_ERROR_STATE:
    /* Outport: '<Root>/red_led' */
    rtY.red_led = ON;
    rtDW.enable_yellow = OFF;
    rtDW.enable_green = OFF;
    rtDW.blink_green = OFF;
    rtDW.blink_yellow = OFF;

    /* Inport: '<Root>/p2' */
    if (!rtU.p2) {
      rtDW.is_GATE = IN_CLOSE;
      rtDW.is_CLOSE = IN_GREEN_BLK_OFF;

      /* Outport: '<Root>/red_led' */
      rtY.red_led = OFF;
    }
    break;

   case IN_IS_CLOSING:
    /* Outport: '<Root>/red_led' */
    rtY.red_led = OFF;
    rtDW.enable_yellow = OFF;
    rtDW.enable_green = OFF;
    rtDW.blink_green = OFF;
    rtDW.blink_yellow = ON;

    /* Inport: '<Root>/p1' incorporates:
     *  Inport: '<Root>/p2'
     */
    if ((rtDW.sfEvent == event_b1_pressed) || (!rtU.p1)) {
      rtDW.is_GATE = IN_IS_OPENING;
      rtDW.temporalCounter_i1 = 0U;
    } else if (!rtU.p2) {
      rtDW.is_GATE = IN_CLOSE;
      rtDW.is_CLOSE = IN_GREEN_BLK_OFF;
      rtDW.blink_yellow = OFF;
    } else if ((rtDW.temporalCounter_i1 >= (uint32_T)ceil(rtDW.working_time *
                 5.0)) && rtU.p2) {
      rtDW.is_GATE = IN_STOP_SYSTEM;
      rtDW.temporalCounter_i1 = 0U;
      rtDW.blink_yellow = OFF;
    }
    break;

   case IN_IS_OPENING:
    /* Outport: '<Root>/red_led' */
    rtY.red_led = OFF;
    rtDW.enable_yellow = OFF;
    rtDW.enable_green = OFF;
    rtDW.blink_green = OFF;
    rtDW.blink_yellow = ON;

    /* Inport: '<Root>/p1' */
    if ((rtDW.sfEvent == event_b1_pressed) && rtU.p1) {
      rtDW.is_GATE = IN_IS_CLOSING;
      rtDW.temporalCounter_i1 = 0U;
    } else if (rtDW.temporalCounter_i1 >= (uint32_T)ceil(rtDW.working_time * 5.0))
    {
      rtDW.durationCounter_1 = 0U;
      rtDW.is_GATE = IN_OPEN;
      rtDW.is_OPEN = IN_GREEN_BLK_OFF;
      rtDW.enable_green = ON;

      /* Outport: '<Root>/red_led' */
      rtY.red_led = ON;
      rtDW.enable_yellow = ON;
      rtDW.blink_yellow = OFF;
    }
    break;

   case IN_OPEN:
    /* Inport: '<Root>/p1' */
    if (!rtU.p1) {
      rtDW.durationCounter_1 = 0U;
    }

    if (((rtDW.sfEvent == event_b1_pressed) && rtU.p1) ||
        (rtDW.durationCounter_1 >= (uint32_T)ceil(rtDW.closing_time * 5.0))) {
      rtDW.is_OPEN = IN_NO_ACTIVE_CHILD;
      rtDW.is_GATE = IN_IS_CLOSING;
      rtDW.temporalCounter_i1 = 0U;

      /* Outport: '<Root>/red_led' */
      rtY.red_led = OFF;
      rtDW.enable_yellow = OFF;
      rtDW.enable_green = OFF;
      rtDW.blink_green = OFF;
      rtDW.blink_yellow = ON;
    } else {
      switch (rtDW.is_OPEN) {
       case IN_GREEN_BLK_OFF:
        rtDW.enable_green = ON;

        /* Outport: '<Root>/red_led' */
        rtY.red_led = ON;
        rtDW.enable_yellow = ON;
        rtDW.blink_green = OFF;
        rtDW.blink_yellow = OFF;
        if ((rtDW.sfEvent == event_b1_pressed) && (!rtU.p1)) {
          rtDW.is_OPEN = IN_GREEN_BLK_ON;
          rtDW.temporalCounter_i1 = 0U;
          rtDW.enable_green = OFF;

          /* Outport: '<Root>/red_led' */
          rtY.red_led = OFF;
          rtDW.enable_yellow = OFF;
          rtDW.blink_green = ON;
        }
        break;

       case IN_GREEN_BLK_ON:
        rtDW.enable_green = OFF;

        /* Outport: '<Root>/red_led' */
        rtY.red_led = OFF;
        rtDW.enable_yellow = OFF;
        rtDW.blink_green = ON;
        rtDW.blink_yellow = OFF;
        if ((rtDW.temporalCounter_i1 >= 150U) || rtU.p1) {
          rtDW.is_OPEN = IN_GREEN_BLK_OFF;
          rtDW.enable_green = ON;

          /* Outport: '<Root>/red_led' */
          rtY.red_led = ON;
          rtDW.enable_yellow = ON;
          rtDW.blink_green = OFF;
        } else if ((rtDW.sfEvent == event_b1_pressed) && (!rtU.p1)) {
          rtDW.is_OPEN = IN_GREEN_BLK_ON;
          rtDW.temporalCounter_i1 = 0U;
        }
        break;
      }
    }
    break;

   case IN_STOP_SYSTEM:
    /* Outport: '<Root>/red_led' */
    rtY.red_led = OFF;
    rtDW.enable_yellow = OFF;
    rtDW.enable_green = OFF;
    rtDW.blink_green = OFF;
    rtDW.blink_yellow = OFF;
    if (rtDW.temporalCounter_i1 >= 50U) {
      rtDW.is_GATE = IN_ERROR_STATE;

      /* Outport: '<Root>/red_led' */
      rtY.red_led = ON;
    }
    break;
  }
}

/* Function for Chart: '<S1>/SYSTEM CORE' */
static void broadcast_b3_pressed_c3_Electro(void)
{
  int32_T b_previousEvent;
  b_previousEvent = rtDW.sfEvent;
  rtDW.sfEvent = event_b3_pressed;

  /* Chart: '<S1>/SYSTEM CORE' */
  c3_ElectronicGate0();
  rtDW.sfEvent = b_previousEvent;
}

/* Function for Chart: '<S1>/SYSTEM CORE' */
static void broadcast_b2_pressed_c3_Electro(void)
{
  int32_T b_previousEvent;
  b_previousEvent = rtDW.sfEvent;
  rtDW.sfEvent = event_b2_pressed;

  /* Chart: '<S1>/SYSTEM CORE' */
  c3_ElectronicGate0();
  rtDW.sfEvent = b_previousEvent;
}

/* Function for Chart: '<S1>/SYSTEM CORE' */
static void broadcast_b1_pressed_c3_Electro(void)
{
  int32_T b_previousEvent;
  b_previousEvent = rtDW.sfEvent;
  rtDW.sfEvent = event_b1_pressed;

  /* Chart: '<S1>/SYSTEM CORE' */
  c3_ElectronicGate0();
  rtDW.sfEvent = b_previousEvent;
}

/* Function for Chart: '<S1>/SYSTEM CORE' */
static void c3_ElectronicGate0(void)
{
  /* Chart: '<S1>/SYSTEM CORE' incorporates:
   *  Inport: '<Root>/b1'
   *  Inport: '<Root>/b2'
   *  Inport: '<Root>/b3'
   *  Inport: '<Root>/p2'
   */
  if (rtDW.is_active_c3_ElectronicGate0 == 0U) {
    rtDW.is_active_c3_ElectronicGate0 = 1U;
    rtDW.is_c3_ElectronicGate0 = IN_SYSTEM;
    rtDW.is_active_WORKING_TIME = 1U;
    rtDW.is_WORKING_TIME = IN_WORKING_TIME_RESET;
    rtDW.working_time = 10.0;
    rtDW.is_active_CLOSING_TIME = 1U;
    rtDW.is_CLOSING_TIME = IN_CLOSING_TIME_RESET;
    rtDW.closing_time = 10.0;
    rtDW.is_active_GATE = 1U;
    rtDW.is_GATE = IN_IS_CLOSING;
    rtDW.temporalCounter_i1 = 0U;

    /* Outport: '<Root>/red_led' */
    rtY.red_led = OFF;
    rtDW.enable_yellow = OFF;
    rtDW.enable_green = OFF;
    rtDW.blink_green = OFF;
    rtDW.blink_yellow = ON;
    rtDW.is_active_B3 = 1U;
    rtDW.is_B3 = IN_RELEASED;
    rtDW.is_active_B2 = 1U;
    rtDW.is_B2 = IN_RELEASED;
    rtDW.is_active_B1 = 1U;
    rtDW.is_B1 = IN_RELEASED;
  } else if (rtDW.is_c3_ElectronicGate0 == IN_SYSTEM) {
    if (rtDW.is_active_WORKING_TIME != 0U) {
      switch (rtDW.is_WORKING_TIME) {
       case IN_WORKING_TIME_INC:
        if ((rtDW.sfEvent == event_b3_pressed) && (!rtU.p2)) {
          rtDW.is_WORKING_TIME = IN_WORKING_TIME_INC;
          rtDW.working_time = mod(rtDW.working_time) + INCREMENT;
        }
        break;

       case IN_WORKING_TIME_RESET:
        if ((rtDW.sfEvent == event_b3_pressed) && (!rtU.p2)) {
          rtDW.is_WORKING_TIME = IN_WORKING_TIME_INC;
          rtDW.working_time = mod(rtDW.working_time) + INCREMENT;
        }
        break;
      }
    }

    if (rtDW.is_active_CLOSING_TIME != 0U) {
      switch (rtDW.is_CLOSING_TIME) {
       case IN_CLOSING_TIME_INC:
        if ((rtDW.sfEvent == event_b2_pressed) && (!rtU.p2)) {
          rtDW.is_CLOSING_TIME = IN_CLOSING_TIME_INC;
          rtDW.closing_time = mod(rtDW.closing_time) + INCREMENT;
        }
        break;

       case IN_CLOSING_TIME_RESET:
        if ((rtDW.sfEvent == event_b2_pressed) && (!rtU.p2)) {
          rtDW.is_CLOSING_TIME = IN_CLOSING_TIME_INC;
          rtDW.closing_time = mod(rtDW.closing_time) + INCREMENT;
        }
        break;
      }
    }

    if (rtDW.is_active_GATE != 0U) {
      GATE();
    }

    if (rtDW.is_active_B3 != 0U) {
      switch (rtDW.is_B3) {
       case IN_LONG_PRESSED:
        if (!rtU.b3) {
          rtDW.is_B3 = IN_RELEASED;
        } else {
          broadcast_b3_pressed_c3_Electro();
        }
        break;

       case IN_PRESSED:
        if (!rtU.b3) {
          rtDW.is_B3 = IN_LONG_PRESSED;
          broadcast_b3_pressed_c3_Electro();
        }
        break;

       case IN_RELEASED:
        if (rtU.b3) {
          rtDW.is_B3 = IN_PRESSED;
        }
        break;
      }
    }

    if (rtDW.is_active_B2 != 0U) {
      switch (rtDW.is_B2) {
       case IN_LONG_PRESSED:
        if (!rtU.b2) {
          rtDW.is_B2 = IN_RELEASED;
        } else {
          broadcast_b2_pressed_c3_Electro();
        }
        break;

       case IN_PRESSED:
        if (!rtU.b2) {
          rtDW.is_B2 = IN_LONG_PRESSED;
          broadcast_b2_pressed_c3_Electro();
        }
        break;

       case IN_RELEASED:
        if (rtU.b2) {
          rtDW.is_B2 = IN_PRESSED;
        }
        break;
      }
    }

    if (rtDW.is_active_B1 != 0U) {
      switch (rtDW.is_B1) {
       case IN_LONG_PRESSED:
        if (!rtU.b1) {
          rtDW.is_B1 = IN_RELEASED;
        } else {
          broadcast_b1_pressed_c3_Electro();
        }
        break;

       case IN_PRESSED:
        if (!rtU.b1) {
          rtDW.is_B1 = IN_LONG_PRESSED;
          broadcast_b1_pressed_c3_Electro();
        }
        break;

       case IN_RELEASED:
        if (rtU.b1) {
          rtDW.is_B1 = IN_PRESSED;
        }
        break;
      }
    }
  }

  /* End of Chart: '<S1>/SYSTEM CORE' */
}

/* Model step function */
void ElectronicGate0_step(void)
{
  /* Chart: '<S1>/SYSTEM CORE' incorporates:
   *  Inport: '<Root>/p1'
   */
  if (rtDW.temporalCounter_i1 < MAX_uint32_T) {
    rtDW.temporalCounter_i1++;
  }

  rtDW.sfEvent = CALL_EVENT;
  c3_ElectronicGate0();
  if (rtU.p1) {
    rtDW.durationCounter_1++;
  } else {
    rtDW.durationCounter_1 = 0U;
  }

  /* End of Chart: '<S1>/SYSTEM CORE' */

  /* Chart: '<S1>/TOGGLE_GREEN_LED' */
  if (rtDW.temporalCounter_i1_d < 7U) {
    rtDW.temporalCounter_i1_d++;
  }

  if (rtDW.is_active_c1_ElectronicGate0 == 0U) {
    rtDW.is_active_c1_ElectronicGate0 = 1U;
    rtDW.is_TOGGLE_GREEN = IN_SWITCH;
    rtDW.is_SWITCH_e = IN_SWITCH_OFF;

    /* Outport: '<Root>/green_led' */
    rtY.green_led = OFF;
  } else if (rtDW.is_TOGGLE_GREEN == IN_BLINKING) {
    if (!rtDW.blink_green) {
      rtDW.is_BLINKING_n = IN_NO_ACTIVE_CHILD;
      rtDW.is_TOGGLE_GREEN = IN_SWITCH;
      rtDW.is_SWITCH_e = IN_SWITCH_OFF;

      /* Outport: '<Root>/green_led' */
      rtY.green_led = OFF;
    } else if (rtDW.is_BLINKING_n == IN_BLINKING_OFF) {
      /* Outport: '<Root>/green_led' */
      rtY.green_led = OFF;
      if (rtDW.temporalCounter_i1_d >= 5U) {
        rtDW.is_BLINKING_n = IN_BLINKING_ON;
        rtDW.temporalCounter_i1_d = 0U;

        /* Outport: '<Root>/green_led' */
        rtY.green_led = ON;
      }
    } else {
      /* Outport: '<Root>/green_led' */
      /* case IN_BLINKING_ON: */
      rtY.green_led = ON;
      if (rtDW.temporalCounter_i1_d >= 5U) {
        rtDW.is_BLINKING_n = IN_BLINKING_OFF;
        rtDW.temporalCounter_i1_d = 0U;

        /* Outport: '<Root>/green_led' */
        rtY.green_led = OFF;
      }
    }

    /* case IN_SWITCH: */
  } else if (rtDW.blink_green) {
    rtDW.is_SWITCH_e = IN_NO_ACTIVE_CHILD;
    rtDW.is_TOGGLE_GREEN = IN_BLINKING;
    rtDW.is_BLINKING_n = IN_BLINKING_ON;
    rtDW.temporalCounter_i1_d = 0U;

    /* Outport: '<Root>/green_led' */
    rtY.green_led = ON;
  } else if (rtDW.is_SWITCH_e == IN_SWITCH_OFF) {
    /* Outport: '<Root>/green_led' */
    rtY.green_led = OFF;
    if (rtDW.enable_green) {
      rtDW.is_SWITCH_e = IN_SWITCH_ON;

      /* Outport: '<Root>/green_led' */
      rtY.green_led = ON;
    }
  } else {
    /* Outport: '<Root>/green_led' */
    /* case IN_SWITCH_ON: */
    rtY.green_led = ON;
    if (!rtDW.enable_green) {
      rtDW.is_SWITCH_e = IN_SWITCH_OFF;

      /* Outport: '<Root>/green_led' */
      rtY.green_led = OFF;
    }
  }

  /* End of Chart: '<S1>/TOGGLE_GREEN_LED' */

  /* Chart: '<S1>/TOGGLE_YELLOW_LED' */
  if (rtDW.temporalCounter_i1_j < 15U) {
    rtDW.temporalCounter_i1_j++;
  }

  if (rtDW.is_active_c5_ElectronicGate0 == 0U) {
    rtDW.is_active_c5_ElectronicGate0 = 1U;
    rtDW.is_TOGGLE_YELLOW = IN_SWITCH;
    rtDW.is_SWITCH = IN_SWITCH_OFF;

    /* Outport: '<Root>/yellow_led' */
    rtY.yellow_led = OFF;
  } else if (rtDW.is_TOGGLE_YELLOW == IN_BLINKING) {
    if (!rtDW.blink_yellow) {
      rtDW.is_BLINKING = IN_NO_ACTIVE_CHILD;
      rtDW.is_TOGGLE_YELLOW = IN_SWITCH;
      rtDW.is_SWITCH = IN_SWITCH_OFF;

      /* Outport: '<Root>/yellow_led' */
      rtY.yellow_led = OFF;
    } else if (rtDW.is_BLINKING == IN_BLINKING_OFF) {
      /* Outport: '<Root>/yellow_led' */
      rtY.yellow_led = OFF;
      if (rtDW.temporalCounter_i1_j >= 10U) {
        rtDW.is_BLINKING = IN_BLINKING_ON;
        rtDW.temporalCounter_i1_j = 0U;

        /* Outport: '<Root>/yellow_led' */
        rtY.yellow_led = ON;
      }
    } else {
      /* Outport: '<Root>/yellow_led' */
      /* case IN_BLINKING_ON: */
      rtY.yellow_led = ON;
      if (rtDW.temporalCounter_i1_j >= 10U) {
        rtDW.is_BLINKING = IN_BLINKING_OFF;
        rtDW.temporalCounter_i1_j = 0U;

        /* Outport: '<Root>/yellow_led' */
        rtY.yellow_led = OFF;
      }
    }

    /* case IN_SWITCH: */
  } else if (rtDW.blink_yellow) {
    rtDW.is_SWITCH = IN_NO_ACTIVE_CHILD;
    rtDW.is_TOGGLE_YELLOW = IN_BLINKING;
    rtDW.is_BLINKING = IN_BLINKING_ON;
    rtDW.temporalCounter_i1_j = 0U;

    /* Outport: '<Root>/yellow_led' */
    rtY.yellow_led = ON;
  } else if (rtDW.is_SWITCH == IN_SWITCH_OFF) {
    /* Outport: '<Root>/yellow_led' */
    rtY.yellow_led = OFF;
    if (rtDW.enable_yellow) {
      rtDW.is_SWITCH = IN_SWITCH_ON;

      /* Outport: '<Root>/yellow_led' */
      rtY.yellow_led = ON;
    }
  } else {
    /* Outport: '<Root>/yellow_led' */
    /* case IN_SWITCH_ON: */
    rtY.yellow_led = ON;
    if (!rtDW.enable_yellow) {
      rtDW.is_SWITCH = IN_SWITCH_OFF;

      /* Outport: '<Root>/yellow_led' */
      rtY.yellow_led = OFF;
    }
  }

  /* End of Chart: '<S1>/TOGGLE_YELLOW_LED' */
}

/* Model initialize function */
void ElectronicGate0_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* SystemInitialize for Chart: '<S1>/SYSTEM CORE' */
  rtDW.sfEvent = CALL_EVENT;
  rtDW.working_time = 10.0;
  rtDW.closing_time = 10.0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
