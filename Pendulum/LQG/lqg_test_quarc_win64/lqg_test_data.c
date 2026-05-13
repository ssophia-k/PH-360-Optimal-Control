/*
 * lqg_test_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "lqg_test".
 *
 * Model version              : 6.10
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C source code generated on : Wed May 13 14:56:22 2026
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
   * Referenced by: '<S72>/Pend Inertia (kg.m^2)'
   */
  3.3282000000000004E-5,

  /* Variable: K_new
   * Referenced by: '<Root>/u = -K*x'
   */
  { -2.4494897427832028, 28.510724971822164, -1.3798107919534566,
    2.4101579284728909 },

  /* Variable: Rm
   * Referenced by: '<S69>/Torque to Voltage'
   */
  8.4,

  /* Variable: g
   * Referenced by: '<S72>/Pend Torque (N.m)'
   */
  9.81,

  /* Variable: kt
   * Referenced by: '<S69>/Torque to Voltage'
   */
  0.042,

  /* Variable: l
   * Referenced by: '<S72>/Pend Torque (N.m)'
   */
  0.0645,

  /* Variable: mp
   * Referenced by: '<S72>/Pend Torque (N.m)'
   */
  0.024,

  /* Variable: mr
   * Referenced by: '<S69>/Acceleration to Torque'
   */
  0.095,

  /* Variable: r
   * Referenced by: '<S69>/Acceleration to Torque'
   */
  0.085,

  /* Mask Parameter: BandLimitedWhiteNoise1_Cov
   * Referenced by: '<S2>/Output'
   */
  { 1.0E-5, 1.0E-5, 1.0E-5, 1.0E-5 },

  /* Mask Parameter: BandLimitedWhiteNoise_Cov
   * Referenced by: '<S1>/Output'
   */
  { 1.0E-5, 1.0E-5 },

  /* Mask Parameter: EnableBalanceControl_const
   * Referenced by: '<S4>/Constant'
   */
  0.17453292519943295,

  /* Mask Parameter: kemsJ_gain
   * Referenced by: '<S70>/Slider Gain'
   */
  80.0,

  /* Mask Parameter: ErmJ_gain
   * Referenced by: '<S67>/Slider Gain'
   */
  30.4,

  /* Mask Parameter: BandLimitedWhiteNoise1_seed
   * Referenced by: '<S2>/White Noise'
   */
  23341.0,

  /* Mask Parameter: BandLimitedWhiteNoise_seed
   * Referenced by: '<S1>/White Noise'
   */
  23341.0,

  /* Mask Parameter: HILWriteAnalog_channels
   * Referenced by: '<S11>/HIL Write Analog'
   */
  0U,

  /* Expression: 0
   * Referenced by: '<S5>/Unit Delay'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S62>/L*(y[k]-yhat[k|k-1])'
   */
  0.0,

  /* Expression: 0.2
   * Referenced by: '<S68>/Impulse Amplitude'
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
   * Referenced by: '<S64>/Pendulum:  counts to rad'
   */
  0.0030679615757712823,

  /* Expression: 2*pi
   * Referenced by: '<S66>/Constant2'
   */
  6.2831853071795862,

  /* Expression: -pi
   * Referenced by: '<S66>/Bias'
   */
  -3.1415926535897931,

  /* Expression: -2*pi/512/4
   * Referenced by: '<S64>/Arm: counts to rad'
   */
  -0.0030679615757712823,

  /* Computed Parameter: theta_dot_A
   * Referenced by: '<S65>/theta_dot'
   */
  -50.0,

  /* Computed Parameter: theta_dot_C
   * Referenced by: '<S65>/theta_dot'
   */
  -2500.0,

  /* Computed Parameter: theta_dot_D
   * Referenced by: '<S65>/theta_dot'
   */
  50.0,

  /* Computed Parameter: alpha_dot_A
   * Referenced by: '<S65>/alpha_dot'
   */
  -50.0,

  /* Computed Parameter: alpha_dot_C
   * Referenced by: '<S65>/alpha_dot'
   */
  -2500.0,

  /* Computed Parameter: alpha_dot_D
   * Referenced by: '<S65>/alpha_dot'
   */
  50.0,

  /* Expression: 180/pi
   * Referenced by: '<S7>/Gain'
   */
  57.295779513082323,

  /* Expression: 0
   * Referenced by: '<S2>/White Noise'
   */
  0.0,

  /* Computed Parameter: WhiteNoise_StdDev
   * Referenced by: '<S2>/White Noise'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<Root>/LQR Noise'
   */
  1.0,

  /* Expression: 180/pi
   * Referenced by: '<S10>/Gain'
   */
  57.295779513082323,

  /* Expression: 180/pi
   * Referenced by: '<S9>/Gain'
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
   * Referenced by: '<S3>/Gain1'
   */
  0.017453292519943295,

  /* Expression: 180/pi
   * Referenced by: '<S8>/Gain'
   */
  57.295779513082323,

  /* Expression: 1
   * Referenced by: '<S68>/Step'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S68>/Step'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S68>/Step'
   */
  1.0,

  /* Expression: 1.1
   * Referenced by: '<S68>/Step1'
   */
  1.1,

  /* Expression: 0
   * Referenced by: '<S68>/Step1'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S68>/Step1'
   */
  -1.0,

  /* Expression: 8
   * Referenced by: '<S12>/u_max'
   */
  8.0,

  /* Expression: 1
   * Referenced by: '<S12>/Constant'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S72>/Constant'
   */
  1.0,

  /* Expression: 0.001
   * Referenced by: '<S69>/mJ to J'
   */
  0.001,

  /* Expression: 1
   * Referenced by: '<Root>/Don't use Kalman'
   */
  1.0,

  /* Expression: 3
   * Referenced by: '<Root>/Strength'
   */
  3.0,

  /* Expression: 0
   * Referenced by: '<Root>/Enable'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/White Noise'
   */
  0.0,

  /* Computed Parameter: WhiteNoise_StdDev_a
   * Referenced by: '<S1>/White Noise'
   */
  1.0,

  /* Expression: pInitialization.A
   * Referenced by: '<S6>/A'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 152.00573888091816, 264.30799773114006, 1.0,
    0.0, -12.254198666554135, -12.111707984384902, 0.0, 1.0,
    -0.50048380100764056, -0.50637184572537752 },

  /* Expression: pInitialization.B
   * Referenced by: '<S6>/B'
   */
  { 0.0, 0.0, 50.637184572537755, 50.048380100764049 },

  /* Expression: pInitialization.C
   * Referenced by: '<S6>/C'
   */
  { 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0 },

  /* Expression: pInitialization.Z
   * Referenced by: '<S13>/CovarianceZ'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0 },

  /* Expression: pInitialization.L
   * Referenced by: '<S13>/KalmanGainL'
   */
  { 117.72732285729253, -3.2895449446803036, 1935.2718265441276,
    -592.155281080894, -3.2895449446803307, 132.78386810344696,
    -231.91254072984657, 3821.1883672283338 },

  /* Expression: pInitialization.D
   * Referenced by: '<S6>/D'
   */
  { 0.0, 0.0 },

  /* Expression: 0
   * Referenced by: '<Root>/Kalman Noise'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S11>/For +ve CCW'
   */
  -1.0,

  /* Expression: 1000
   * Referenced by: '<S69>/J to mJ'
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
   * Referenced by: '<S11>/HIL Read Encoder Timebase'
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
   * Referenced by: '<S11>/HIL Read Encoder Timebase'
   */
  { 0U, 1U },

  /* Computed Parameter: HILReadEncoderTimebase_SamplesI
   * Referenced by: '<S11>/HIL Read Encoder Timebase'
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

  /* Computed Parameter: ToHostFile1_Decimation
   * Referenced by: '<Root>/To Host File1'
   */
  1U,

  /* Computed Parameter: ToHostFile1_BitRate
   * Referenced by: '<Root>/To Host File1'
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
   * Referenced by: '<S11>/HIL Read Encoder Timebase'
   */
  true,

  /* Expression: pInitialization.isSqrtUsed
   * Referenced by: '<S60>/isSqrtUsed'
   */
  false,

  /* Expression: true()
   * Referenced by: '<S6>/Enable'
   */
  true,

  /* Computed Parameter: HILWriteAnalog_Active
   * Referenced by: '<S11>/HIL Write Analog'
   */
  true,

  /* Computed Parameter: HILReadEncoderTimebase_Overflow
   * Referenced by: '<S11>/HIL Read Encoder Timebase'
   */
  2U,

  /* Expression: file_name_argument
   * Referenced by: '<Root>/To Host File'
   */
  { 115U, 116U, 97U, 116U, 101U, 46U, 99U, 115U, 118U, 0U },

  /* Expression: variable_name_argument
   * Referenced by: '<Root>/To Host File'
   */
  { 115U, 116U, 97U, 116U, 101U, 0U },

  /* Computed Parameter: ToHostFile_FileFormat
   * Referenced by: '<Root>/To Host File'
   */
  4U,

  /* Expression: file_name_argument
   * Referenced by: '<Root>/To Host File1'
   */
  { 105U, 110U, 112U, 117U, 116U, 46U, 99U, 115U, 118U, 0U },

  /* Expression: variable_name_argument
   * Referenced by: '<Root>/To Host File1'
   */
  { 105U, 110U, 112U, 117U, 116U, 0U },

  /* Computed Parameter: ToHostFile1_FileFormat
   * Referenced by: '<Root>/To Host File1'
   */
  4U
};
