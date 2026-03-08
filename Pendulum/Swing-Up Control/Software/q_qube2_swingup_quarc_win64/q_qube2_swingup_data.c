/*
 * q_qube2_swingup_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "q_qube2_swingup".
 *
 * Model version              : 1.493
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C source code generated on : Sun Mar  8 14:48:03 2026
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "q_qube2_swingup.h"
#include "q_qube2_swingup_private.h"

/* Block parameters (default storage) */
P_q_qube2_swingup_T q_qube2_swingup_P = {
  /* Variable: Jp_cm
   * Referenced by: '<S14>/Pend Inertia (kg.m^2)'
   */
  3.3282000000000004E-5,

  /* Variable: Rm
   * Referenced by: '<S8>/Torque to Voltage'
   */
  8.4,

  /* Variable: g
   * Referenced by: '<S14>/Pend Torque (N.m)'
   */
  9.81,

  /* Variable: kt
   * Referenced by: '<S8>/Torque to Voltage'
   */
  0.042,

  /* Variable: l
   * Referenced by: '<S14>/Pend Torque (N.m)'
   */
  0.0645,

  /* Variable: mp
   * Referenced by: '<S14>/Pend Torque (N.m)'
   */
  0.024,

  /* Variable: mr
   * Referenced by: '<S8>/Acceleration to Torque'
   */
  0.095,

  /* Variable: r
   * Referenced by: '<S8>/Acceleration to Torque'
   */
  0.085,

  /* Mask Parameter: EnableBalanceControl_const
   * Referenced by: '<S1>/Constant'
   */
  0.3490658503988659,

  /* Mask Parameter: kemsJ_gain
   * Referenced by: '<S9>/Slider Gain'
   */
  50.0,

  /* Mask Parameter: ErmJ_gain
   * Referenced by: '<S2>/Slider Gain'
   */
  80.0,

  /* Mask Parameter: HILWriteAnalog_channels
   * Referenced by: '<S7>/HIL Write Analog'
   */
  0U,

  /* Expression: 0.2
   * Referenced by: '<S3>/Impulse Amplitude'
   */
  0.2,

  /* Expression: [-2 35 -1.5 3]
   * Referenced by: '<Root>/u = -K*x'
   */
  { -2.0, 35.0, -1.5, 3.0 },

  /* Expression: set_other_outputs_at_terminate
   * Referenced by: '<Root>/HIL Initialize'
   */
  1.0,

  /* Expression: set_other_outputs_at_switch_out
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: set_other_outputs_at_start
   * Referenced by: '<Root>/HIL Initialize'
   */
  1.0,

  /* Expression: set_other_outputs_at_switch_in
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: final_analog_outputs
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: final_other_outputs
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 1.0, 0.0, 0.0 },

  /* Expression: analog_input_maximums
   * Referenced by: '<Root>/HIL Initialize'
   */
  3.0,

  /* Expression: analog_input_minimums
   * Referenced by: '<Root>/HIL Initialize'
   */
  -3.0,

  /* Expression: analog_output_maximums
   * Referenced by: '<Root>/HIL Initialize'
   */
  15.0,

  /* Expression: analog_output_minimums
   * Referenced by: '<Root>/HIL Initialize'
   */
  -15.0,

  /* Expression: initial_analog_outputs
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: watchdog_analog_outputs
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: initial_other_outputs
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 0.0, 1.0, 0.0 },

  /* Expression: watchdog_other_outputs
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 0.0, 0.0, 1.0 },

  /* Expression: 2*pi/512/4
   * Referenced by: '<S10>/Pendulum:  counts to rad'
   */
  0.0030679615757712823,

  /* Expression: 2*pi
   * Referenced by: '<S12>/Constant2'
   */
  6.2831853071795862,

  /* Expression: -pi
   * Referenced by: '<S12>/Bias'
   */
  -3.1415926535897931,

  /* Expression: 180/pi
   * Referenced by: '<S5>/Gain'
   */
  57.295779513082323,

  /* Expression: 180/pi
   * Referenced by: '<S6>/Gain'
   */
  57.295779513082323,

  /* Expression: 1
   * Referenced by: '<S14>/Constant'
   */
  1.0,

  /* Computed Parameter: alpha_dot_A
   * Referenced by: '<S11>/alpha_dot'
   */
  -50.0,

  /* Computed Parameter: alpha_dot_C
   * Referenced by: '<S11>/alpha_dot'
   */
  -2500.0,

  /* Computed Parameter: alpha_dot_D
   * Referenced by: '<S11>/alpha_dot'
   */
  50.0,

  /* Expression: 1000
   * Referenced by: '<S8>/J to mJ'
   */
  1000.0,

  /* Expression: -2*pi/512/4
   * Referenced by: '<S10>/Arm: counts to rad'
   */
  -0.0030679615757712823,

  /* Expression: 180/pi
   * Referenced by: '<S4>/Gain'
   */
  57.295779513082323,

  /* Expression: 1
   * Referenced by: '<S3>/Step'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S3>/Step'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S3>/Step'
   */
  1.0,

  /* Expression: 1.1
   * Referenced by: '<S3>/Step1'
   */
  1.1,

  /* Expression: 0
   * Referenced by: '<S3>/Step1'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S3>/Step1'
   */
  -1.0,

  /* Expression: 6
   * Referenced by: '<Root>/u_max'
   */
  6.0,

  /* Expression: 1
   * Referenced by: '<Root>/Constant'
   */
  1.0,

  /* Expression: 0.001
   * Referenced by: '<S8>/mJ to J'
   */
  0.001,

  /* Expression: [0 0 0 0]
   * Referenced by: '<Root>/Setpoint State: Xd'
   */
  { 0.0, 0.0, 0.0, 0.0 },

  /* Computed Parameter: theta_dot_A
   * Referenced by: '<S11>/theta_dot'
   */
  -50.0,

  /* Computed Parameter: theta_dot_C
   * Referenced by: '<S11>/theta_dot'
   */
  -2500.0,

  /* Computed Parameter: theta_dot_D
   * Referenced by: '<S11>/theta_dot'
   */
  50.0,

  /* Expression: 10
   * Referenced by: '<Root>/+//-10V'
   */
  10.0,

  /* Expression: -10
   * Referenced by: '<Root>/+//-10V'
   */
  -10.0,

  /* Expression: -1
   * Referenced by: '<S7>/For +ve CCW'
   */
  -1.0,

  /* Computed Parameter: HILInitialize_CKChannels
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_DOWatchdog
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_EIInitial
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILReadEncoderTimebase_Clock
   * Referenced by: '<S7>/HIL Read Encoder Timebase'
   */
  0,

  /* Computed Parameter: HILInitialize_AIChannels
   * Referenced by: '<Root>/HIL Initialize'
   */
  0U,

  /* Computed Parameter: HILInitialize_AOChannels
   * Referenced by: '<Root>/HIL Initialize'
   */
  0U,

  /* Computed Parameter: HILInitialize_DOChannels
   * Referenced by: '<Root>/HIL Initialize'
   */
  0U,

  /* Computed Parameter: HILInitialize_EIChannels
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 0U, 1U },

  /* Computed Parameter: HILInitialize_EIQuadrature
   * Referenced by: '<Root>/HIL Initialize'
   */
  4U,

  /* Computed Parameter: HILInitialize_OOChannels
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 11000U, 11001U, 11002U },

  /* Computed Parameter: HILReadEncoderTimebase_Channels
   * Referenced by: '<S7>/HIL Read Encoder Timebase'
   */
  { 0U, 1U },

  /* Computed Parameter: HILReadEncoderTimebase_SamplesI
   * Referenced by: '<S7>/HIL Read Encoder Timebase'
   */
  1U,

  /* Computed Parameter: HILInitialize_Active
   * Referenced by: '<Root>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_AOTerminate
   * Referenced by: '<Root>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_AOExit
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_DOTerminate
   * Referenced by: '<Root>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_DOExit
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_POTerminate
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_POExit
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_CKPStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_CKPEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_CKStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_CKEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_AIPStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_AIPEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_AOPStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_AOPEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_AOStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_AOEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_AOReset
   * Referenced by: '<Root>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_DOPStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_DOPEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_DOStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_DOEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_DOReset
   * Referenced by: '<Root>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_EIPStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_EIPEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_EIStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_EIEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_POPStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_POPEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_POStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_POEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_POReset
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_OOReset
   * Referenced by: '<Root>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_DOFinal
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_DOInitial
   * Referenced by: '<Root>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILReadEncoderTimebase_Active
   * Referenced by: '<S7>/HIL Read Encoder Timebase'
   */
  true,

  /* Computed Parameter: HILWriteAnalog_Active
   * Referenced by: '<S7>/HIL Write Analog'
   */
  true,

  /* Computed Parameter: HILReadEncoderTimebase_Overflow
   * Referenced by: '<S7>/HIL Read Encoder Timebase'
   */
  2U
};
