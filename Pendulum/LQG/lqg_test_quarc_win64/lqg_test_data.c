/*
 * lqg_test_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "lqg_test".
 *
 * Model version              : 6.8
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C source code generated on : Thu May  7 14:39:39 2026
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "lqg_test.h"
#include "lqg_test_private.h"

/* Block parameters (default storage) */
P_lqg_test_T lqg_test_P = {
  /* Variable: Jp_cm
   * Referenced by: '<S68>/Pend Inertia (kg.m^2)'
   */
  3.3282000000000004E-5,

  /* Variable: K_new
   * Referenced by: '<Root>/u = -K*x'
   */
  { -2.4494897427832028, 28.510724971822164, -1.3798107919534566,
    2.4101579284728909 },

  /* Variable: Rm
   * Referenced by: '<S65>/Torque to Voltage'
   */
  8.4,

  /* Variable: g
   * Referenced by: '<S68>/Pend Torque (N.m)'
   */
  9.81,

  /* Variable: kt
   * Referenced by: '<S65>/Torque to Voltage'
   */
  0.042,

  /* Variable: l
   * Referenced by: '<S68>/Pend Torque (N.m)'
   */
  0.0645,

  /* Variable: mp
   * Referenced by: '<S68>/Pend Torque (N.m)'
   */
  0.024,

  /* Variable: mr
   * Referenced by: '<S65>/Acceleration to Torque'
   */
  0.095,

  /* Variable: r
   * Referenced by: '<S65>/Acceleration to Torque'
   */
  0.085,

  /* Mask Parameter: EnableBalanceControl_const
   * Referenced by: '<S2>/Constant'
   */
  0.17453292519943295,

  /* Mask Parameter: kemsJ_gain
   * Referenced by: '<S66>/Slider Gain'
   */
  70.0,

  /* Mask Parameter: ErmJ_gain
   * Referenced by: '<S63>/Slider Gain'
   */
  30.4,

  /* Mask Parameter: HILWriteAnalog_channels
   * Referenced by: '<S7>/HIL Write Analog'
   */
  0U,

  /* Expression: 0
   * Referenced by: '<S58>/L*(y[k]-yhat[k|k-1])'
   */
  0.0,

  /* Expression: 0.2
   * Referenced by: '<S64>/Impulse Amplitude'
   */
  0.2,

  /* Expression: 0
   * Referenced by: '<Root>/1 = true, 0 = estimate'
   */
  0.0,

  /* Expression: [1 0 0 0]
   * Referenced by: '<Root>/Convert to Vector'
   */
  { 1.0, 0.0, 0.0, 0.0 },

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
   * Referenced by: '<S60>/Pendulum:  counts to rad'
   */
  0.0030679615757712823,

  /* Expression: 2*pi
   * Referenced by: '<S62>/Constant2'
   */
  6.2831853071795862,

  /* Expression: -pi
   * Referenced by: '<S62>/Bias'
   */
  -3.1415926535897931,

  /* Expression: -2*pi/512/4
   * Referenced by: '<S60>/Arm: counts to rad'
   */
  -0.0030679615757712823,

  /* Computed Parameter: theta_dot_A
   * Referenced by: '<S61>/theta_dot'
   */
  -50.0,

  /* Computed Parameter: theta_dot_C
   * Referenced by: '<S61>/theta_dot'
   */
  -2500.0,

  /* Computed Parameter: theta_dot_D
   * Referenced by: '<S61>/theta_dot'
   */
  50.0,

  /* Computed Parameter: alpha_dot_A
   * Referenced by: '<S61>/alpha_dot'
   */
  -50.0,

  /* Computed Parameter: alpha_dot_C
   * Referenced by: '<S61>/alpha_dot'
   */
  -2500.0,

  /* Computed Parameter: alpha_dot_D
   * Referenced by: '<S61>/alpha_dot'
   */
  50.0,

  /* Expression: 180/pi
   * Referenced by: '<S4>/Gain'
   */
  57.295779513082323,

  /* Expression: 180/pi
   * Referenced by: '<S6>/Gain'
   */
  57.295779513082323,

  /* Expression: 0
   * Referenced by: '<Root>/Signal Generator'
   */
  0.0,

  /* Expression: 0.05
   * Referenced by: '<Root>/Signal Generator'
   */
  0.05,

  /* Expression: 30
   * Referenced by: '<Root>/Gain'
   */
  30.0,

  /* Expression: pi/180
   * Referenced by: '<S1>/Gain1'
   */
  0.017453292519943295,

  /* Expression: 180/pi
   * Referenced by: '<S5>/Gain'
   */
  57.295779513082323,

  /* Expression: 1
   * Referenced by: '<S64>/Step'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S64>/Step'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S64>/Step'
   */
  1.0,

  /* Expression: 1.1
   * Referenced by: '<S64>/Step1'
   */
  1.1,

  /* Expression: 0
   * Referenced by: '<S64>/Step1'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S64>/Step1'
   */
  -1.0,

  /* Expression: 8
   * Referenced by: '<S8>/u_max'
   */
  8.0,

  /* Expression: 1
   * Referenced by: '<S8>/Constant'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S68>/Constant'
   */
  1.0,

  /* Expression: 0.001
   * Referenced by: '<S65>/mJ to J'
   */
  0.001,

  /* Expression: 0
   * Referenced by: '<Root>/Constant'
   */
  0.0,

  /* Expression: pInitialization.A
   * Referenced by: '<S3>/A'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 152.00573888091816, 264.30799773114006, 1.0,
    0.0, -12.254198666554135, -12.111707984384902, 0.0, 1.0,
    -0.50048380100764056, -0.50637184572537752 },

  /* Expression: pInitialization.B
   * Referenced by: '<S3>/B'
   */
  { 0.0, 0.0, 50.637184572537755, 50.048380100764049 },

  /* Expression: pInitialization.C
   * Referenced by: '<S3>/C'
   */
  { 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0 },

  /* Expression: pInitialization.Z
   * Referenced by: '<S9>/CovarianceZ'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0 },

  /* Expression: pInitialization.L
   * Referenced by: '<S9>/KalmanGainL'
   */
  { 336.28313183506481, -3.7614408983490093, 6550.2465972157288,
    -1496.2405581438929, -3.7614408983512919, 350.5565845267252,
    -1087.2664415911756, 11452.033696337532 },

  /* Expression: pInitialization.D
   * Referenced by: '<S3>/D'
   */
  { 0.0, 0.0 },

  /* Expression: -1
   * Referenced by: '<S7>/For +ve CCW'
   */
  -1.0,

  /* Expression: 1000
   * Referenced by: '<S65>/J to mJ'
   */
  1000.0,

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

  /* Computed Parameter: ToHostFile_Decimation
   * Referenced by: '<Root>/To Host File'
   */
  1U,

  /* Computed Parameter: ToHostFile_BitRate
   * Referenced by: '<Root>/To Host File'
   */
  2000000U,

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

  /* Expression: pInitialization.isSqrtUsed
   * Referenced by: '<S56>/isSqrtUsed'
   */
  false,

  /* Expression: true()
   * Referenced by: '<S3>/Enable'
   */
  true,

  /* Computed Parameter: HILWriteAnalog_Active
   * Referenced by: '<S7>/HIL Write Analog'
   */
  true,

  /* Computed Parameter: HILReadEncoderTimebase_Overflow
   * Referenced by: '<S7>/HIL Read Encoder Timebase'
   */
  2U,

  /* Expression: file_name_argument
   * Referenced by: '<Root>/To Host File'
   */
  { 100U, 97U, 116U, 97U, 46U, 99U, 115U, 118U, 0U },

  /* Expression: variable_name_argument
   * Referenced by: '<Root>/To Host File'
   */
  { 100U, 97U, 116U, 97U, 0U },

  /* Computed Parameter: ToHostFile_FileFormat
   * Referenced by: '<Root>/To Host File'
   */
  4U
};
