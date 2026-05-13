/*
 * lqg_test.c
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
#include "lqg_test_dt.h"

/* Block signals (default storage) */
B_lqg_test_T lqg_test_B;

/* Continuous states */
X_lqg_test_T lqg_test_X;

/* Block states (default storage) */
DW_lqg_test_T lqg_test_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_lqg_test_T lqg_test_PrevZCX;

/* Real-time model */
static RT_MODEL_lqg_test_T lqg_test_M_;
RT_MODEL_lqg_test_T *const lqg_test_M = &lqg_test_M_;

/*
 * This function updates continuous states using the ODE1 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE1_IntgData *id = (ODE1_IntgData *)rtsiGetSolverData(si);
  real_T *f0 = id->f[0];
  int_T i;
  int_T nXc = 6;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  lqg_test_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

real_T rt_urand_Upu32_Yd_f_pw_snf(uint32_T *u)
{
  uint32_T hi;
  uint32_T lo;

  /* Uniform random number generator (random number between 0 and 1)

     #define IA      16807                      magic multiplier = 7^5
     #define IM      2147483647                 modulus = 2^31-1
     #define IQ      127773                     IM div IA
     #define IR      2836                       IM modulo IA
     #define S       4.656612875245797e-10      reciprocal of 2^31-1
     test = IA * (seed % IQ) - IR * (seed/IQ)
     seed = test < 0 ? (test + IM) : test
     return (seed*S)
   */
  lo = *u % 127773U * 16807U;
  hi = *u / 127773U * 2836U;
  if (lo < hi) {
    *u = 2147483647U - (hi - lo);
  } else {
    *u = lo - hi;
  }

  return (real_T)*u * 4.6566128752457969E-10;
}

real_T rt_nrand_Upu32_Yd_f_pw_snf(uint32_T *u)
{
  real_T si;
  real_T sr;
  real_T y;

  /* Normal (Gaussian) random number generator */
  do {
    sr = 2.0 * rt_urand_Upu32_Yd_f_pw_snf(u) - 1.0;
    si = 2.0 * rt_urand_Upu32_Yd_f_pw_snf(u) - 1.0;
    si = sr * sr + si * si;
  } while (si > 1.0);

  y = sqrt(-2.0 * log(si) / si) * sr;
  return y;
}

real_T rt_modd_snf(real_T u0, real_T u1)
{
  real_T y;
  y = u0;
  if (u1 == 0.0) {
    if (u0 == 0.0) {
      y = u1;
    }
  } else if (rtIsNaN(u0) || rtIsNaN(u1) || rtIsInf(u0)) {
    y = (rtNaN);
  } else if (u0 == 0.0) {
    y = 0.0 / u1;
  } else if (rtIsInf(u1)) {
    if ((u1 < 0.0) != (u0 < 0.0)) {
      y = u1;
    }
  } else {
    boolean_T yEq;
    y = fmod(u0, u1);
    yEq = (y == 0.0);
    if ((!yEq) && (u1 > floor(u1))) {
      real_T q;
      q = fabs(u0 / u1);
      yEq = !(fabs(q - floor(q + 0.5)) > DBL_EPSILON * q);
    }

    if (yEq) {
      y = u1 * 0.0;
    } else if ((u0 < 0.0) != (u1 < 0.0)) {
      y += u1;
    }
  }

  return y;
}

/* Model output function */
void lqg_test_output(void)
{
  /* local block i/o variables */
  real_T rtb_HILReadEncoderTimebase_o1;
  real_T rtb_WhiteNoise;
  __m128d tmp_3;
  __m128d tmp_4;
  real_T tmp[2];
  real_T rtb_Energy;
  real_T rtb_Gain1;
  real_T rtb_Sum2_idx_1;
  int32_T i;
  if (rtmIsMajorTimeStep(lqg_test_M)) {
    /* set solver stop time */
    if (!(lqg_test_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&lqg_test_M->solverInfo,
                            ((lqg_test_M->Timing.clockTickH0 + 1) *
        lqg_test_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&lqg_test_M->solverInfo,
                            ((lqg_test_M->Timing.clockTick0 + 1) *
        lqg_test_M->Timing.stepSize0 + lqg_test_M->Timing.clockTickH0 *
        lqg_test_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(lqg_test_M)) {
    lqg_test_M->Timing.t[0] = rtsiGetT(&lqg_test_M->solverInfo);
  }

  /* Reset subsysRan breadcrumbs */
  srClearBC(lqg_test_DW.Impulse_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(lqg_test_DW.MeasurementUpdate_SubsysRanBC);
  if (rtmIsMajorTimeStep(lqg_test_M)) {
    /* S-Function (hil_read_encoder_timebase_block): '<S11>/HIL Read Encoder Timebase' */

    /* S-Function Block: lqg_test/Rotary Pendulum Interface/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
    {
      t_error result;
      result = hil_task_read_encoder(lqg_test_DW.HILReadEncoderTimebase_Task, 1,
        &lqg_test_DW.HILReadEncoderTimebase_Buffer[0]);
      if (result < 0) {
        rtb_HILReadEncoderTimebase_o1 = 0;
        rtb_WhiteNoise = 0;
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lqg_test_M, _rt_error_message);
      } else {
        rtb_HILReadEncoderTimebase_o1 =
          lqg_test_DW.HILReadEncoderTimebase_Buffer[0];
        rtb_WhiteNoise = lqg_test_DW.HILReadEncoderTimebase_Buffer[1];
      }
    }

    /* Gain: '<S64>/Pendulum:  counts to rad' */
    lqg_test_B.Pendulumcountstorad = lqg_test_P.Pendulumcountstorad_Gain *
      rtb_WhiteNoise;

    /* RandomNumber: '<S1>/White Noise' incorporates:
     *  Constant: '<S66>/Constant2'
     *  Math: '<S66>/Math Function'
     */
    rtb_WhiteNoise = rt_modd_snf(lqg_test_B.Pendulumcountstorad,
      lqg_test_P.Constant2_Value);

    /* Bias: '<S66>/Bias' */
    lqg_test_B.Bias = rtb_WhiteNoise + lqg_test_P.Bias_Bias;

    /* RandomNumber: '<S1>/White Noise' incorporates:
     *  Abs: '<Root>/|alpha|'
     */
    rtb_WhiteNoise = fabs(lqg_test_B.Bias);

    /* RelationalOperator: '<S4>/Compare' incorporates:
     *  Constant: '<S4>/Constant'
     */
    lqg_test_B.Compare = (uint8_T)(rtb_WhiteNoise <=
      lqg_test_P.EnableBalanceControl_const);

    /* DataTypeConversion: '<S6>/DataTypeConversionReset' */
    lqg_test_B.DataTypeConversionReset = (lqg_test_B.Compare != 0);

    /* Gain: '<S64>/Arm: counts to rad' */
    lqg_test_B.Armcountstorad = lqg_test_P.Armcountstorad_Gain *
      rtb_HILReadEncoderTimebase_o1;
  }

  /* TransferFcn: '<S65>/theta_dot' */
  lqg_test_B.theta_dot = 0.0;
  lqg_test_B.theta_dot += lqg_test_P.theta_dot_C * lqg_test_X.theta_dot_CSTATE;
  lqg_test_B.theta_dot += lqg_test_P.theta_dot_D * lqg_test_B.Armcountstorad;

  /* TransferFcn: '<S65>/alpha_dot' */
  lqg_test_B.alpha_dot = 0.0;
  lqg_test_B.alpha_dot += lqg_test_P.alpha_dot_C * lqg_test_X.alpha_dot_CSTATE;
  lqg_test_B.alpha_dot += lqg_test_P.alpha_dot_D *
    lqg_test_B.Pendulumcountstorad;

  /* Reshape: '<S6>/ReshapeX0' */
  lqg_test_B.ReshapeX0[0] = lqg_test_B.Armcountstorad;
  lqg_test_B.ReshapeX0[1] = lqg_test_B.Bias;
  lqg_test_B.ReshapeX0[2] = lqg_test_B.theta_dot;
  lqg_test_B.ReshapeX0[3] = lqg_test_B.alpha_dot;

  /* Integrator: '<S6>/MemoryX' */
  if (rtmIsMajorTimeStep(lqg_test_M)) {
    boolean_T didZcEventOccur;
    didZcEventOccur = (((lqg_test_PrevZCX.MemoryX_Reset_ZCE == 1) != (int32_T)
                        lqg_test_B.DataTypeConversionReset) &&
                       (lqg_test_PrevZCX.MemoryX_Reset_ZCE != 3));
    lqg_test_PrevZCX.MemoryX_Reset_ZCE = lqg_test_B.DataTypeConversionReset;

    /* evaluate zero-crossings */
    if (didZcEventOccur || (lqg_test_DW.MemoryX_IWORK != 0)) {
      lqg_test_X.MemoryX_CSTATE[0] = lqg_test_B.ReshapeX0[0];
      lqg_test_X.MemoryX_CSTATE[1] = lqg_test_B.ReshapeX0[1];
      lqg_test_X.MemoryX_CSTATE[2] = lqg_test_B.ReshapeX0[2];
      lqg_test_X.MemoryX_CSTATE[3] = lqg_test_B.ReshapeX0[3];
    }
  }

  /* Gain: '<S7>/Gain' incorporates:
   *  Integrator: '<S6>/MemoryX'
   */
  lqg_test_B.Gain[0] = lqg_test_P.Gain_Gain * lqg_test_B.Bias;
  lqg_test_B.Gain[1] = lqg_test_P.Gain_Gain * lqg_test_X.MemoryX_CSTATE[1];
  if (rtmIsMajorTimeStep(lqg_test_M)) {
    /* RandomNumber: '<S1>/White Noise' incorporates:
     *  RandomNumber: '<S2>/White Noise'
     */
    rtb_WhiteNoise = lqg_test_DW.NextOutput;

    /* Gain: '<Root>/LQR Noise' incorporates:
     *  Gain: '<S2>/Output'
     */
    lqg_test_B.LQRNoise[0] = sqrt(lqg_test_P.BandLimitedWhiteNoise1_Cov[0]) /
      0.044721359549995794 * rtb_WhiteNoise * lqg_test_P.LQRNoise_Gain;
    lqg_test_B.LQRNoise[1] = sqrt(lqg_test_P.BandLimitedWhiteNoise1_Cov[1]) /
      0.044721359549995794 * rtb_WhiteNoise * lqg_test_P.LQRNoise_Gain;
    lqg_test_B.LQRNoise[2] = sqrt(lqg_test_P.BandLimitedWhiteNoise1_Cov[2]) /
      0.044721359549995794 * rtb_WhiteNoise * lqg_test_P.LQRNoise_Gain;
    lqg_test_B.LQRNoise[3] = sqrt(lqg_test_P.BandLimitedWhiteNoise1_Cov[3]) /
      0.044721359549995794 * rtb_WhiteNoise * lqg_test_P.LQRNoise_Gain;
  }

  /* Sum: '<Root>/Sum2' */
  rtb_Sum2_idx_1 = lqg_test_B.Bias + lqg_test_B.LQRNoise[1];

  /* Gain: '<S10>/Gain' incorporates:
   *  Integrator: '<S6>/MemoryX'
   */
  lqg_test_B.Gain_l[0] = lqg_test_P.Gain_Gain_l * rtb_Sum2_idx_1;
  lqg_test_B.Gain_l[1] = lqg_test_P.Gain_Gain_l * lqg_test_X.MemoryX_CSTATE[1];
  if (rtmIsMajorTimeStep(lqg_test_M)) {
  }

  /* Gain: '<S9>/Gain' incorporates:
   *  Integrator: '<S6>/MemoryX'
   */
  lqg_test_B.Gain_m[0] = lqg_test_P.Gain_Gain_i * lqg_test_B.alpha_dot;
  lqg_test_B.Gain_m[1] = lqg_test_P.Gain_Gain_i * lqg_test_X.MemoryX_CSTATE[3];
  if (rtmIsMajorTimeStep(lqg_test_M)) {
  }

  /* Gain: '<S3>/Gain1' incorporates:
   *  Gain: '<Root>/Gain'
   *  SignalGenerator: '<Root>/Signal Generator'
   */
  rtb_Gain1 = sin(6.2831853071795862 * lqg_test_M->Timing.t[0] *
                  lqg_test_P.SignalGenerator_Frequency) *
    lqg_test_P.SignalGenerator_Amplitude * lqg_test_P.Gain_Gain_e *
    lqg_test_P.Gain1_Gain;

  /* Gain: '<S8>/Gain' incorporates:
   *  Integrator: '<S6>/MemoryX'
   */
  lqg_test_B.Gain_b[0] = lqg_test_P.Gain_Gain_a * rtb_Gain1;
  lqg_test_B.Gain_b[1] = lqg_test_P.Gain_Gain_a * lqg_test_B.Armcountstorad;
  lqg_test_B.Gain_b[2] = lqg_test_P.Gain_Gain_a * lqg_test_X.MemoryX_CSTATE[0];
  if (rtmIsMajorTimeStep(lqg_test_M)) {
    /* Gain: '<S70>/Slider Gain' incorporates:
     *  Constant: '<S12>/Constant'
     */
    lqg_test_B.SliderGain = lqg_test_P.kemsJ_gain * lqg_test_P.Constant_Value;

    /* Trigonometry: '<S72>/cos(alpha)' incorporates:
     *  Trigonometry: '<S71>/cos(alpha)'
     */
    rtb_Energy = cos(lqg_test_B.Pendulumcountstorad);

    /* Gain: '<S72>/Pend Torque (N.m)' incorporates:
     *  Constant: '<S72>/Constant'
     *  Sum: '<S72>/Sum1'
     *  Trigonometry: '<S72>/cos(alpha)'
     */
    lqg_test_B.PendTorqueNm = lqg_test_P.mp * lqg_test_P.g * lqg_test_P.l *
      (lqg_test_P.Constant_Value_o - rtb_Energy);

    /* Gain: '<S69>/mJ to J' incorporates:
     *  Constant: '<S12>/Constant'
     *  Gain: '<S67>/Slider Gain'
     */
    lqg_test_B.mJtoJ = lqg_test_P.ErmJ_gain * lqg_test_P.Constant_Value *
      lqg_test_P.mJtoJ_Gain;

    /* Trigonometry: '<S71>/cos(alpha)' */
    lqg_test_B.cosalpha = rtb_Energy;

    /* UnaryMinus: '<S71>/Unary Minus' incorporates:
     *  Constant: '<S12>/u_max'
     */
    lqg_test_B.UnaryMinus = -lqg_test_P.u_max_Value;
  }

  /* Sum: '<S72>/Energy' incorporates:
   *  Gain: '<S72>/Pend Inertia (kg.m^2)'
   *  Math: '<S72>/alpha_dot^2'
   */
  rtb_Energy = lqg_test_P.Jp_cm / 2.0 * (lqg_test_B.alpha_dot *
    lqg_test_B.alpha_dot) + lqg_test_B.PendTorqueNm;

  /* MultiPortSwitch: '<Root>/Enable Balance Control Switch' incorporates:
   *  Constant: '<Root>/Don't use Kalman'
   *  Gain: '<Root>/Convert to Vector'
   *  Gain: '<Root>/u = -K*x'
   *  Gain: '<S68>/Impulse Amplitude'
   *  Gain: '<S69>/Acceleration to Torque'
   *  Gain: '<S69>/Torque to Voltage'
   *  Sum: '<Root>/Sum'
   *  Sum: '<S12>/Sum1'
   *  Sum: '<S68>/Sum'
   *  Switch: '<Root>/1 = true, 0 = estimate'
   */
  if (lqg_test_B.Compare == 0) {
    real_T tmp_0;
    real_T tmp_1;

    /* Product: '<S71>/alpha_dot*cos(alpha)' */
    rtb_Sum2_idx_1 = lqg_test_B.cosalpha * lqg_test_B.alpha_dot;

    /* Signum: '<S71>/Sign' */
    if (rtb_Sum2_idx_1 < 0.0) {
      rtb_Sum2_idx_1 = -1.0;
    } else if (rtb_Sum2_idx_1 > 0.0) {
      rtb_Sum2_idx_1 = 1.0;
    } else if (rtb_Sum2_idx_1 == 0.0) {
      rtb_Sum2_idx_1 = 0.0;
    } else {
      rtb_Sum2_idx_1 = (rtNaN);
    }

    /* End of Signum: '<S71>/Sign' */

    /* Product: '<S71>/Product' incorporates:
     *  Product: '<S71>/(E-Er)*sign(a_dot*cos(a))'
     *  Sum: '<S71>/E-Er'
     */
    rtb_Gain1 = (rtb_Energy - lqg_test_B.mJtoJ) * rtb_Sum2_idx_1 *
      lqg_test_B.SliderGain;

    /* Switch: '<S73>/Switch2' incorporates:
     *  Constant: '<S12>/u_max'
     *  RelationalOperator: '<S73>/LowerRelop1'
     *  RelationalOperator: '<S73>/UpperRelop'
     *  Switch: '<S73>/Switch'
     */
    if (rtb_Gain1 > lqg_test_P.u_max_Value) {
      rtb_Gain1 = lqg_test_P.u_max_Value;
    } else if (rtb_Gain1 < lqg_test_B.UnaryMinus) {
      /* Switch: '<S73>/Switch' */
      rtb_Gain1 = lqg_test_B.UnaryMinus;
    }

    /* End of Switch: '<S73>/Switch2' */

    /* Step: '<S68>/Step' incorporates:
     *  Step: '<S68>/Step1'
     */
    tmp_0 = lqg_test_M->Timing.t[0];
    if (tmp_0 < lqg_test_P.Step_Time) {
      tmp_1 = lqg_test_P.Step_Y0;
    } else {
      tmp_1 = lqg_test_P.Step_YFinal;
    }

    /* End of Step: '<S68>/Step' */

    /* Step: '<S68>/Step1' */
    if (tmp_0 < lqg_test_P.Step1_Time) {
      tmp_0 = lqg_test_P.Step1_Y0;
    } else {
      tmp_0 = lqg_test_P.Step1_YFinal;
    }

    rtb_Gain1 = lqg_test_P.mr * lqg_test_P.r * rtb_Gain1 * (lqg_test_P.Rm /
      lqg_test_P.kt) + (tmp_1 + tmp_0) * lqg_test_P.ImpulseAmplitude_Gain;
  } else {
    real_T tmp_0;
    real_T tmp_1;
    real_T tmp_2;
    if (lqg_test_P.DontuseKalman_Value > lqg_test_P.utrue0estimate_Threshold) {
      /* Gain: '<Root>/u = -K*x' incorporates:
       *  Sum: '<Root>/Sum2'
       *  Switch: '<Root>/1 = true, 0 = estimate'
       */
      tmp_0 = lqg_test_B.Armcountstorad + lqg_test_B.LQRNoise[0];
      tmp_1 = lqg_test_B.theta_dot + lqg_test_B.LQRNoise[2];
      tmp_2 = lqg_test_B.alpha_dot + lqg_test_B.LQRNoise[3];
    } else {
      /* Gain: '<Root>/u = -K*x' incorporates:
       *  Integrator: '<S6>/MemoryX'
       *  Switch: '<Root>/1 = true, 0 = estimate'
       */
      tmp_0 = lqg_test_X.MemoryX_CSTATE[0];
      rtb_Sum2_idx_1 = lqg_test_X.MemoryX_CSTATE[1];
      tmp_1 = lqg_test_X.MemoryX_CSTATE[2];
      tmp_2 = lqg_test_X.MemoryX_CSTATE[3];
    }

    rtb_Gain1 = (((lqg_test_P.ConverttoVector_Gain[0] * rtb_Gain1 - tmp_0) *
                  lqg_test_P.K_new[0] + (lqg_test_P.ConverttoVector_Gain[1] *
      rtb_Gain1 - rtb_Sum2_idx_1) * lqg_test_P.K_new[1]) +
                 (lqg_test_P.ConverttoVector_Gain[2] * rtb_Gain1 - tmp_1) *
                 lqg_test_P.K_new[2]) + (lqg_test_P.ConverttoVector_Gain[3] *
      rtb_Gain1 - tmp_2) * lqg_test_P.K_new[3];
  }

  /* End of MultiPortSwitch: '<Root>/Enable Balance Control Switch' */
  if (rtmIsMajorTimeStep(lqg_test_M)) {
    /* Outputs for Triggered SubSystem: '<Root>/Impulse' incorporates:
     *  TriggerPort: '<S5>/Trigger'
     */
    if (rtmIsMajorTimeStep(lqg_test_M)) {
      ZCEventType zcEvent;

      /* Constant: '<Root>/Enable' */
      zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,&lqg_test_PrevZCX.Impulse_Trig_ZCE,
                         (lqg_test_P.Enable_Value));
      if (zcEvent != NO_ZCEVENT) {
        /* Sum: '<S5>/Sum' incorporates:
         *  Constant: '<Root>/Strength'
         *  UnitDelay: '<S5>/Unit Delay'
         */
        lqg_test_B.Sum = lqg_test_P.Strength_Value -
          lqg_test_DW.UnitDelay_DSTATE;

        /* Update for UnitDelay: '<S5>/Unit Delay' incorporates:
         *  Constant: '<Root>/Strength'
         */
        lqg_test_DW.UnitDelay_DSTATE = lqg_test_P.Strength_Value;
        lqg_test_DW.Impulse_SubsysRanBC = 4;
      }
    }

    /* End of Outputs for SubSystem: '<Root>/Impulse' */
  }

  /* Sum: '<Root>/Sum3' */
  lqg_test_B.Sum3 = rtb_Gain1 + lqg_test_B.Sum;
  if (rtmIsMajorTimeStep(lqg_test_M)) {
    /* RandomNumber: '<S1>/White Noise' */
    rtb_WhiteNoise = lqg_test_DW.NextOutput_o;

    /* Sum: '<Root>/Sum1' incorporates:
     *  Gain: '<Root>/Kalman Noise'
     *  Gain: '<S1>/Output'
     */
    lqg_test_B.Sum1[0] = sqrt(lqg_test_P.BandLimitedWhiteNoise_Cov[0]) /
      0.044721359549995794 * rtb_WhiteNoise * lqg_test_P.KalmanNoise_Gain +
      lqg_test_B.Armcountstorad;
    lqg_test_B.Sum1[1] = sqrt(lqg_test_P.BandLimitedWhiteNoise_Cov[1]) /
      0.044721359549995794 * rtb_WhiteNoise * lqg_test_P.KalmanNoise_Gain +
      lqg_test_B.Bias;

    /* Outputs for Enabled SubSystem: '<S32>/MeasurementUpdate' incorporates:
     *  EnablePort: '<S62>/Enable'
     */
    if (rtmIsMajorTimeStep(lqg_test_M)) {
      /* Constant: '<S6>/Enable' */
      if (lqg_test_P.Enable_Value_d) {
        lqg_test_DW.MeasurementUpdate_MODE = true;
      } else if (lqg_test_DW.MeasurementUpdate_MODE) {
        /* Disable for Product: '<S62>/Product3' incorporates:
         *  Outport: '<S62>/L*(y[k]-yhat[k|k-1])'
         */
        lqg_test_B.Product3[0] = lqg_test_P.Lykyhatkk1_Y0;
        lqg_test_B.Product3[1] = lqg_test_P.Lykyhatkk1_Y0;
        lqg_test_B.Product3[2] = lqg_test_P.Lykyhatkk1_Y0;
        lqg_test_B.Product3[3] = lqg_test_P.Lykyhatkk1_Y0;
        lqg_test_DW.MeasurementUpdate_MODE = false;
      }

      /* End of Constant: '<S6>/Enable' */
    }

    /* End of Outputs for SubSystem: '<S32>/MeasurementUpdate' */
  }

  /* Outputs for Enabled SubSystem: '<S32>/MeasurementUpdate' incorporates:
   *  EnablePort: '<S62>/Enable'
   */
  if (lqg_test_DW.MeasurementUpdate_MODE) {
    for (i = 0; i <= 0; i += 2) {
      /* Constant: '<S6>/C' incorporates:
       *  Product: '<S62>/C[k]*xhat[k|k-1]'
       */
      tmp_3 = _mm_loadu_pd(&lqg_test_P.C_Value[i]);

      /* Sum: '<S62>/Sum' incorporates:
       *  Constant: '<S6>/C'
       *  Constant: '<S6>/D'
       *  Integrator: '<S6>/MemoryX'
       *  Product: '<S62>/C[k]*xhat[k|k-1]'
       *  Product: '<S62>/D[k]*u[k]'
       */
      tmp_4 = _mm_loadu_pd(&lqg_test_B.Sum1[i]);
      _mm_storeu_pd(&tmp[i], _mm_sub_pd(tmp_4, _mm_add_pd(_mm_mul_pd
        (_mm_loadu_pd(&lqg_test_P.D_Value[i]), _mm_set1_pd(lqg_test_B.Sum3)),
        _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&lqg_test_P.C_Value[i + 6]),
        _mm_set1_pd(lqg_test_X.MemoryX_CSTATE[3])), _mm_add_pd(_mm_mul_pd
        (_mm_loadu_pd(&lqg_test_P.C_Value[i + 4]), _mm_set1_pd
         (lqg_test_X.MemoryX_CSTATE[2])), _mm_add_pd(_mm_mul_pd(_mm_loadu_pd
        (&lqg_test_P.C_Value[i + 2]), _mm_set1_pd(lqg_test_X.MemoryX_CSTATE[1])),
        _mm_add_pd(_mm_mul_pd(tmp_3, _mm_set1_pd(lqg_test_X.MemoryX_CSTATE[0])),
                   _mm_set1_pd(0.0))))))));
    }

    for (i = 0; i <= 2; i += 2) {
      /* Product: '<S62>/Product3' incorporates:
       *  Constant: '<S13>/KalmanGainL'
       */
      _mm_storeu_pd(&lqg_test_B.Product3[i], _mm_set1_pd(0.0));

      /* Product: '<S62>/Product3' incorporates:
       *  Constant: '<S13>/KalmanGainL'
       */
      tmp_3 = _mm_loadu_pd(&lqg_test_B.Product3[i]);

      /* Product: '<S62>/Product3' incorporates:
       *  Constant: '<S13>/KalmanGainL'
       */
      _mm_storeu_pd(&lqg_test_B.Product3[i], _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(
        &lqg_test_P.KalmanGainL_Value[i]), _mm_set1_pd(tmp[0])), tmp_3));

      /* Product: '<S62>/Product3' incorporates:
       *  Constant: '<S13>/KalmanGainL'
       */
      tmp_3 = _mm_loadu_pd(&lqg_test_B.Product3[i]);

      /* Product: '<S62>/Product3' incorporates:
       *  Constant: '<S13>/KalmanGainL'
       */
      _mm_storeu_pd(&lqg_test_B.Product3[i], _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(
        &lqg_test_P.KalmanGainL_Value[i + 4]), _mm_set1_pd(tmp[1])), tmp_3));
    }

    if (rtmIsMajorTimeStep(lqg_test_M)) {
      srUpdateBC(lqg_test_DW.MeasurementUpdate_SubsysRanBC);
    }
  }

  /* End of Outputs for SubSystem: '<S32>/MeasurementUpdate' */
  for (i = 0; i <= 2; i += 2) {
    /* Constant: '<S6>/A' incorporates:
     *  Product: '<S32>/A[k]*xhat[k|k-1]'
     */
    tmp_3 = _mm_loadu_pd(&lqg_test_P.A_Value[i]);

    /* Sum: '<S32>/Add' incorporates:
     *  Constant: '<S6>/A'
     *  Product: '<S32>/A[k]*xhat[k|k-1]'
     *  Product: '<S62>/Product3'
     */
    tmp_4 = _mm_loadu_pd(&lqg_test_B.Product3[i]);

    /* Sum: '<S32>/Add' incorporates:
     *  Constant: '<S6>/A'
     *  Constant: '<S6>/B'
     *  Integrator: '<S6>/MemoryX'
     *  Product: '<S32>/A[k]*xhat[k|k-1]'
     *  Product: '<S32>/B[k]*u[k]'
     */
    _mm_storeu_pd(&lqg_test_B.Add[i], _mm_add_pd(_mm_add_pd(_mm_mul_pd
      (_mm_loadu_pd(&lqg_test_P.B_Value[i]), _mm_set1_pd(lqg_test_B.Sum3)),
      _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&lqg_test_P.A_Value[i + 12]),
      _mm_set1_pd(lqg_test_X.MemoryX_CSTATE[3])), _mm_add_pd(_mm_mul_pd
      (_mm_loadu_pd(&lqg_test_P.A_Value[i + 8]), _mm_set1_pd
       (lqg_test_X.MemoryX_CSTATE[2])), _mm_add_pd(_mm_mul_pd(_mm_loadu_pd
      (&lqg_test_P.A_Value[i + 4]), _mm_set1_pd(lqg_test_X.MemoryX_CSTATE[1])),
      _mm_add_pd(_mm_mul_pd(tmp_3, _mm_set1_pd(lqg_test_X.MemoryX_CSTATE[0])),
                 _mm_set1_pd(0.0)))))), tmp_4));
  }

  /* Gain: '<S11>/For +ve CCW' */
  lqg_test_B.ForveCCW = lqg_test_P.ForveCCW_Gain * lqg_test_B.Sum3;
  if (rtmIsMajorTimeStep(lqg_test_M)) {
    /* S-Function (hil_write_analog_block): '<S11>/HIL Write Analog' */

    /* S-Function Block: lqg_test/Rotary Pendulum Interface/HIL Write Analog (hil_write_analog_block) */
    {
      t_error result;
      result = hil_write_analog(lqg_test_DW.HILInitialize_Card,
        &lqg_test_P.HILWriteAnalog_channels, 1, &lqg_test_B.ForveCCW);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lqg_test_M, _rt_error_message);
      }
    }
  }

  /* Gain: '<S69>/J to mJ' */
  lqg_test_B.JtomJ = lqg_test_P.JtomJ_Gain * rtb_Energy;
  if (rtmIsMajorTimeStep(lqg_test_M)) {
  }
}

/* Model update function */
void lqg_test_update(void)
{
  /* Update for Integrator: '<S6>/MemoryX' */
  lqg_test_DW.MemoryX_IWORK = 0;
  if (rtmIsMajorTimeStep(lqg_test_M)) {
    /* Update for RandomNumber: '<S2>/White Noise' */
    lqg_test_DW.NextOutput = rt_nrand_Upu32_Yd_f_pw_snf(&lqg_test_DW.RandSeed) *
      lqg_test_P.WhiteNoise_StdDev + lqg_test_P.WhiteNoise_Mean;

    /* Update for RandomNumber: '<S1>/White Noise' */
    lqg_test_DW.NextOutput_o = rt_nrand_Upu32_Yd_f_pw_snf
      (&lqg_test_DW.RandSeed_g) * lqg_test_P.WhiteNoise_StdDev_a +
      lqg_test_P.WhiteNoise_Mean_a;
  }

  if (rtmIsMajorTimeStep(lqg_test_M)) {
    rt_ertODEUpdateContinuousStates(&lqg_test_M->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++lqg_test_M->Timing.clockTick0)) {
    ++lqg_test_M->Timing.clockTickH0;
  }

  lqg_test_M->Timing.t[0] = rtsiGetSolverStopTime(&lqg_test_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.002s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++lqg_test_M->Timing.clockTick1)) {
      ++lqg_test_M->Timing.clockTickH1;
    }

    lqg_test_M->Timing.t[1] = lqg_test_M->Timing.clockTick1 *
      lqg_test_M->Timing.stepSize1 + lqg_test_M->Timing.clockTickH1 *
      lqg_test_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void lqg_test_derivatives(void)
{
  XDot_lqg_test_T *_rtXdot;
  _rtXdot = ((XDot_lqg_test_T *) lqg_test_M->derivs);

  /* Derivatives for TransferFcn: '<S65>/theta_dot' */
  _rtXdot->theta_dot_CSTATE = 0.0;
  _rtXdot->theta_dot_CSTATE += lqg_test_P.theta_dot_A *
    lqg_test_X.theta_dot_CSTATE;
  _rtXdot->theta_dot_CSTATE += lqg_test_B.Armcountstorad;

  /* Derivatives for TransferFcn: '<S65>/alpha_dot' */
  _rtXdot->alpha_dot_CSTATE = 0.0;
  _rtXdot->alpha_dot_CSTATE += lqg_test_P.alpha_dot_A *
    lqg_test_X.alpha_dot_CSTATE;
  _rtXdot->alpha_dot_CSTATE += lqg_test_B.Pendulumcountstorad;

  /* Derivatives for Integrator: '<S6>/MemoryX' */
  _rtXdot->MemoryX_CSTATE[0] = lqg_test_B.Add[0];
  _rtXdot->MemoryX_CSTATE[1] = lqg_test_B.Add[1];
  _rtXdot->MemoryX_CSTATE[2] = lqg_test_B.Add[2];
  _rtXdot->MemoryX_CSTATE[3] = lqg_test_B.Add[3];
}

/* Model initialize function */
void lqg_test_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: lqg_test/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("qube_servo2_usb", "0", &lqg_test_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(lqg_test_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_watchdog_clear(lqg_test_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(lqg_test_M, _rt_error_message);
      return;
    }

    if ((lqg_test_P.HILInitialize_AIPStart && !is_switching) ||
        (lqg_test_P.HILInitialize_AIPEnter && is_switching)) {
      result = hil_set_analog_input_ranges(lqg_test_DW.HILInitialize_Card,
        &lqg_test_P.HILInitialize_AIChannels, 1U,
        &lqg_test_P.HILInitialize_AILow, &lqg_test_P.HILInitialize_AIHigh);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lqg_test_M, _rt_error_message);
        return;
      }
    }

    if ((lqg_test_P.HILInitialize_AOPStart && !is_switching) ||
        (lqg_test_P.HILInitialize_AOPEnter && is_switching)) {
      result = hil_set_analog_output_ranges(lqg_test_DW.HILInitialize_Card,
        &lqg_test_P.HILInitialize_AOChannels, 1U,
        &lqg_test_P.HILInitialize_AOLow, &lqg_test_P.HILInitialize_AOHigh);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lqg_test_M, _rt_error_message);
        return;
      }
    }

    if ((lqg_test_P.HILInitialize_AOStart && !is_switching) ||
        (lqg_test_P.HILInitialize_AOEnter && is_switching)) {
      result = hil_write_analog(lqg_test_DW.HILInitialize_Card,
        &lqg_test_P.HILInitialize_AOChannels, 1U,
        &lqg_test_P.HILInitialize_AOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lqg_test_M, _rt_error_message);
        return;
      }
    }

    if (lqg_test_P.HILInitialize_AOReset) {
      result = hil_watchdog_set_analog_expiration_state
        (lqg_test_DW.HILInitialize_Card, &lqg_test_P.HILInitialize_AOChannels,
         1U, &lqg_test_P.HILInitialize_AOWatchdog);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lqg_test_M, _rt_error_message);
        return;
      }
    }

    result = hil_set_digital_directions(lqg_test_DW.HILInitialize_Card, NULL, 0U,
      &lqg_test_P.HILInitialize_DOChannels, 1U);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(lqg_test_M, _rt_error_message);
      return;
    }

    if ((lqg_test_P.HILInitialize_DOStart && !is_switching) ||
        (lqg_test_P.HILInitialize_DOEnter && is_switching)) {
      result = hil_write_digital(lqg_test_DW.HILInitialize_Card,
        &lqg_test_P.HILInitialize_DOChannels, 1U, (t_boolean *)
        &lqg_test_P.HILInitialize_DOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lqg_test_M, _rt_error_message);
        return;
      }
    }

    if (lqg_test_P.HILInitialize_DOReset) {
      result = hil_watchdog_set_digital_expiration_state
        (lqg_test_DW.HILInitialize_Card, &lqg_test_P.HILInitialize_DOChannels,
         1U, (const t_digital_state *) &lqg_test_P.HILInitialize_DOWatchdog);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lqg_test_M, _rt_error_message);
        return;
      }
    }

    if ((lqg_test_P.HILInitialize_EIPStart && !is_switching) ||
        (lqg_test_P.HILInitialize_EIPEnter && is_switching)) {
      lqg_test_DW.HILInitialize_QuadratureModes[0] =
        lqg_test_P.HILInitialize_EIQuadrature;
      lqg_test_DW.HILInitialize_QuadratureModes[1] =
        lqg_test_P.HILInitialize_EIQuadrature;
      result = hil_set_encoder_quadrature_mode(lqg_test_DW.HILInitialize_Card,
        lqg_test_P.HILInitialize_EIChannels, 2U, (t_encoder_quadrature_mode *)
        &lqg_test_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lqg_test_M, _rt_error_message);
        return;
      }
    }

    if ((lqg_test_P.HILInitialize_EIStart && !is_switching) ||
        (lqg_test_P.HILInitialize_EIEnter && is_switching)) {
      lqg_test_DW.HILInitialize_InitialEICounts[0] =
        lqg_test_P.HILInitialize_EIInitial;
      lqg_test_DW.HILInitialize_InitialEICounts[1] =
        lqg_test_P.HILInitialize_EIInitial;
      result = hil_set_encoder_counts(lqg_test_DW.HILInitialize_Card,
        lqg_test_P.HILInitialize_EIChannels, 2U,
        &lqg_test_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lqg_test_M, _rt_error_message);
        return;
      }
    }

    if ((lqg_test_P.HILInitialize_OOStart && !is_switching) ||
        (lqg_test_P.HILInitialize_OOEnter && is_switching)) {
      result = hil_write_other(lqg_test_DW.HILInitialize_Card,
        lqg_test_P.HILInitialize_OOChannels, 3U,
        lqg_test_P.HILInitialize_OOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lqg_test_M, _rt_error_message);
        return;
      }
    }

    if (lqg_test_P.HILInitialize_OOReset) {
      result = hil_watchdog_set_other_expiration_state
        (lqg_test_DW.HILInitialize_Card, lqg_test_P.HILInitialize_OOChannels, 3U,
         lqg_test_P.HILInitialize_OOWatchdog);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lqg_test_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (hil_read_encoder_timebase_block): '<S11>/HIL Read Encoder Timebase' */

  /* S-Function Block: lqg_test/Rotary Pendulum Interface/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
  {
    t_error result;
    result = hil_task_create_encoder_reader(lqg_test_DW.HILInitialize_Card,
      lqg_test_P.HILReadEncoderTimebase_SamplesI,
      lqg_test_P.HILReadEncoderTimebase_Channels, 2,
      &lqg_test_DW.HILReadEncoderTimebase_Task);
    if (result >= 0) {
      result = hil_task_set_buffer_overflow_mode
        (lqg_test_DW.HILReadEncoderTimebase_Task, (t_buffer_overflow_mode)
         (lqg_test_P.HILReadEncoderTimebase_Overflow - 1));
    }

    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(lqg_test_M, _rt_error_message);
    }
  }

  /* Start for Enabled SubSystem: '<S32>/MeasurementUpdate' */
  lqg_test_DW.MeasurementUpdate_MODE = false;

  /* End of Start for SubSystem: '<S32>/MeasurementUpdate' */
  lqg_test_PrevZCX.MemoryX_Reset_ZCE = UNINITIALIZED_ZCSIG;
  lqg_test_PrevZCX.Impulse_Trig_ZCE = UNINITIALIZED_ZCSIG;

  {
    real_T tmp;
    int32_T r;
    int32_T t;
    uint32_T tseed;

    /* InitializeConditions for TransferFcn: '<S65>/theta_dot' */
    lqg_test_X.theta_dot_CSTATE = 0.0;

    /* InitializeConditions for TransferFcn: '<S65>/alpha_dot' */
    lqg_test_X.alpha_dot_CSTATE = 0.0;

    /* InitializeConditions for Integrator: '<S6>/MemoryX' */
    if (rtmIsFirstInitCond(lqg_test_M)) {
      lqg_test_X.MemoryX_CSTATE[0] = 0.0;
      lqg_test_X.MemoryX_CSTATE[1] = 0.0;
      lqg_test_X.MemoryX_CSTATE[2] = 0.0;
      lqg_test_X.MemoryX_CSTATE[3] = 0.0;
    }

    lqg_test_DW.MemoryX_IWORK = 1;

    /* End of InitializeConditions for Integrator: '<S6>/MemoryX' */

    /* InitializeConditions for RandomNumber: '<S2>/White Noise' */
    tmp = floor(lqg_test_P.BandLimitedWhiteNoise1_seed);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-tmp : (uint32_T)tmp;
    r = (int32_T)(tseed >> 16U);
    t = (int32_T)(tseed & 32768U);
    tseed = ((((tseed - ((uint32_T)r << 16U)) + t) << 16U) + t) + r;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else if (tseed > 2147483646U) {
      tseed = 2147483646U;
    }

    lqg_test_DW.RandSeed = tseed;
    lqg_test_DW.NextOutput = rt_nrand_Upu32_Yd_f_pw_snf(&lqg_test_DW.RandSeed) *
      lqg_test_P.WhiteNoise_StdDev + lqg_test_P.WhiteNoise_Mean;

    /* End of InitializeConditions for RandomNumber: '<S2>/White Noise' */

    /* InitializeConditions for RandomNumber: '<S1>/White Noise' */
    tmp = floor(lqg_test_P.BandLimitedWhiteNoise_seed);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-tmp : (uint32_T)tmp;
    r = (int32_T)(tseed >> 16U);
    t = (int32_T)(tseed & 32768U);
    tseed = ((((tseed - ((uint32_T)r << 16U)) + t) << 16U) + t) + r;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else if (tseed > 2147483646U) {
      tseed = 2147483646U;
    }

    lqg_test_DW.RandSeed_g = tseed;
    lqg_test_DW.NextOutput_o = rt_nrand_Upu32_Yd_f_pw_snf
      (&lqg_test_DW.RandSeed_g) * lqg_test_P.WhiteNoise_StdDev_a +
      lqg_test_P.WhiteNoise_Mean_a;

    /* End of InitializeConditions for RandomNumber: '<S1>/White Noise' */

    /* SystemInitialize for Triggered SubSystem: '<Root>/Impulse' */
    /* InitializeConditions for UnitDelay: '<S5>/Unit Delay' */
    lqg_test_DW.UnitDelay_DSTATE = lqg_test_P.UnitDelay_InitialCondition;

    /* End of SystemInitialize for SubSystem: '<Root>/Impulse' */

    /* SystemInitialize for Enabled SubSystem: '<S32>/MeasurementUpdate' */
    /* SystemInitialize for Product: '<S62>/Product3' incorporates:
     *  Outport: '<S62>/L*(y[k]-yhat[k|k-1])'
     */
    lqg_test_B.Product3[0] = lqg_test_P.Lykyhatkk1_Y0;
    lqg_test_B.Product3[1] = lqg_test_P.Lykyhatkk1_Y0;
    lqg_test_B.Product3[2] = lqg_test_P.Lykyhatkk1_Y0;
    lqg_test_B.Product3[3] = lqg_test_P.Lykyhatkk1_Y0;

    /* End of SystemInitialize for SubSystem: '<S32>/MeasurementUpdate' */

    /* set "at time zero" to false */
    if (rtmIsFirstInitCond(lqg_test_M)) {
      rtmSetFirstInitCond(lqg_test_M, 0);
    }
  }
}

/* Model terminate function */
void lqg_test_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: lqg_test/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_digital_outputs = 0;
    t_uint32 num_final_other_outputs = 0;
    hil_task_stop_all(lqg_test_DW.HILInitialize_Card);
    hil_monitor_stop_all(lqg_test_DW.HILInitialize_Card);
    is_switching = false;
    if ((lqg_test_P.HILInitialize_AOTerminate && !is_switching) ||
        (lqg_test_P.HILInitialize_AOExit && is_switching)) {
      num_final_analog_outputs = 1U;
    } else {
      num_final_analog_outputs = 0;
    }

    if ((lqg_test_P.HILInitialize_DOTerminate && !is_switching) ||
        (lqg_test_P.HILInitialize_DOExit && is_switching)) {
      num_final_digital_outputs = 1U;
    } else {
      num_final_digital_outputs = 0;
    }

    if ((lqg_test_P.HILInitialize_OOTerminate && !is_switching) ||
        (lqg_test_P.HILInitialize_OOExit && is_switching)) {
      num_final_other_outputs = 3U;
    } else {
      num_final_other_outputs = 0;
    }

    if (0
        || num_final_analog_outputs > 0
        || num_final_digital_outputs > 0
        || num_final_other_outputs > 0
        ) {
      /* Attempt to write the final outputs atomically (due to firmware issue in old Q2-USB). Otherwise write channels individually */
      result = hil_write(lqg_test_DW.HILInitialize_Card
                         , &lqg_test_P.HILInitialize_AOChannels,
                         num_final_analog_outputs
                         , NULL, 0
                         , &lqg_test_P.HILInitialize_DOChannels,
                         num_final_digital_outputs
                         , lqg_test_P.HILInitialize_OOChannels,
                         num_final_other_outputs
                         , &lqg_test_P.HILInitialize_AOFinal
                         , NULL
                         , (t_boolean *) &lqg_test_P.HILInitialize_DOFinal
                         , lqg_test_P.HILInitialize_OOFinal
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0) {
          local_result = hil_write_analog(lqg_test_DW.HILInitialize_Card,
            &lqg_test_P.HILInitialize_AOChannels, num_final_analog_outputs,
            &lqg_test_P.HILInitialize_AOFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_digital_outputs > 0) {
          local_result = hil_write_digital(lqg_test_DW.HILInitialize_Card,
            &lqg_test_P.HILInitialize_DOChannels, num_final_digital_outputs,
            (t_boolean *) &lqg_test_P.HILInitialize_DOFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_other_outputs > 0) {
          local_result = hil_write_other(lqg_test_DW.HILInitialize_Card,
            lqg_test_P.HILInitialize_OOChannels, num_final_other_outputs,
            lqg_test_P.HILInitialize_OOFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(lqg_test_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(lqg_test_DW.HILInitialize_Card);
    hil_monitor_delete_all(lqg_test_DW.HILInitialize_Card);
    hil_close(lqg_test_DW.HILInitialize_Card);
    lqg_test_DW.HILInitialize_Card = NULL;
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  lqg_test_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  lqg_test_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  lqg_test_initialize();
}

void MdlTerminate(void)
{
  lqg_test_terminate();
}

/* Registration function */
RT_MODEL_lqg_test_T *lqg_test(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)lqg_test_M, 0,
                sizeof(RT_MODEL_lqg_test_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&lqg_test_M->solverInfo,
                          &lqg_test_M->Timing.simTimeStep);
    rtsiSetTPtr(&lqg_test_M->solverInfo, &rtmGetTPtr(lqg_test_M));
    rtsiSetStepSizePtr(&lqg_test_M->solverInfo, &lqg_test_M->Timing.stepSize0);
    rtsiSetdXPtr(&lqg_test_M->solverInfo, &lqg_test_M->derivs);
    rtsiSetContStatesPtr(&lqg_test_M->solverInfo, (real_T **)
                         &lqg_test_M->contStates);
    rtsiSetNumContStatesPtr(&lqg_test_M->solverInfo,
      &lqg_test_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&lqg_test_M->solverInfo,
      &lqg_test_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&lqg_test_M->solverInfo,
      &lqg_test_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&lqg_test_M->solverInfo,
      &lqg_test_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&lqg_test_M->solverInfo, (&rtmGetErrorStatus
      (lqg_test_M)));
    rtsiSetRTModelPtr(&lqg_test_M->solverInfo, lqg_test_M);
  }

  rtsiSetSimTimeStep(&lqg_test_M->solverInfo, MAJOR_TIME_STEP);
  lqg_test_M->intgData.f[0] = lqg_test_M->odeF[0];
  lqg_test_M->contStates = ((real_T *) &lqg_test_X);
  rtsiSetSolverData(&lqg_test_M->solverInfo, (void *)&lqg_test_M->intgData);
  rtsiSetSolverName(&lqg_test_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = lqg_test_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "lqg_test_M points to
       static memory which is guaranteed to be non-NULL" */
    lqg_test_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    lqg_test_M->Timing.sampleTimes = (&lqg_test_M->Timing.sampleTimesArray[0]);
    lqg_test_M->Timing.offsetTimes = (&lqg_test_M->Timing.offsetTimesArray[0]);

    /* task periods */
    lqg_test_M->Timing.sampleTimes[0] = (0.0);
    lqg_test_M->Timing.sampleTimes[1] = (0.002);

    /* task offsets */
    lqg_test_M->Timing.offsetTimes[0] = (0.0);
    lqg_test_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(lqg_test_M, &lqg_test_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = lqg_test_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    lqg_test_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(lqg_test_M, -1);
  lqg_test_M->Timing.stepSize0 = 0.002;
  lqg_test_M->Timing.stepSize1 = 0.002;
  rtmSetFirstInitCond(lqg_test_M, 1);

  /* External mode info */
  lqg_test_M->Sizes.checksums[0] = (3863130946U);
  lqg_test_M->Sizes.checksums[1] = (3056390902U);
  lqg_test_M->Sizes.checksums[2] = (1419047151U);
  lqg_test_M->Sizes.checksums[3] = (3880578026U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[7];
    lqg_test_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = (sysRanDType *)&lqg_test_DW.Impulse_SubsysRanBC;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = (sysRanDType *)&lqg_test_DW.MeasurementUpdate_SubsysRanBC;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(lqg_test_M->extModeInfo,
      &lqg_test_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(lqg_test_M->extModeInfo, lqg_test_M->Sizes.checksums);
    rteiSetTPtr(lqg_test_M->extModeInfo, rtmGetTPtr(lqg_test_M));
  }

  lqg_test_M->solverInfoPtr = (&lqg_test_M->solverInfo);
  lqg_test_M->Timing.stepSize = (0.002);
  rtsiSetFixedStepSize(&lqg_test_M->solverInfo, 0.002);
  rtsiSetSolverMode(&lqg_test_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  lqg_test_M->blockIO = ((void *) &lqg_test_B);
  (void) memset(((void *) &lqg_test_B), 0,
                sizeof(B_lqg_test_T));

  /* parameters */
  lqg_test_M->defaultParam = ((real_T *)&lqg_test_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &lqg_test_X;
    lqg_test_M->contStates = (x);
    (void) memset((void *)&lqg_test_X, 0,
                  sizeof(X_lqg_test_T));
  }

  /* states (dwork) */
  lqg_test_M->dwork = ((void *) &lqg_test_DW);
  (void) memset((void *)&lqg_test_DW, 0,
                sizeof(DW_lqg_test_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    lqg_test_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 21;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  lqg_test_M->Sizes.numContStates = (6);/* Number of continuous states */
  lqg_test_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  lqg_test_M->Sizes.numY = (0);        /* Number of model outputs */
  lqg_test_M->Sizes.numU = (0);        /* Number of model inputs */
  lqg_test_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  lqg_test_M->Sizes.numSampTimes = (2);/* Number of sample times */
  lqg_test_M->Sizes.numBlocks = (105); /* Number of blocks */
  lqg_test_M->Sizes.numBlockIO = (25); /* Number of block outputs */
  lqg_test_M->Sizes.numBlockPrms = (239);/* Sum of parameter "widths" */
  return lqg_test_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
