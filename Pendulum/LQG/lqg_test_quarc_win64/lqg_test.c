/*
 * lqg_test.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "lqg_test".
 *
 * Model version              : 6.7
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C source code generated on : Mon Apr 27 16:35:31 2026
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
  real_T rtb_alpha;
  __m128d tmp_0;
  __m128d tmp_1;
  real_T tmp[2];
  real_T rtb_Gain1;
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
  srClearBC(lqg_test_DW.MeasurementUpdate_SubsysRanBC);
  if (rtmIsMajorTimeStep(lqg_test_M)) {
    /* S-Function (hil_read_encoder_timebase_block): '<S6>/HIL Read Encoder Timebase' */

    /* S-Function Block: lqg_test/Rotary Pendulum Interface/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
    {
      t_error result;
      result = hil_task_read_encoder(lqg_test_DW.HILReadEncoderTimebase_Task, 1,
        &lqg_test_DW.HILReadEncoderTimebase_Buffer[0]);
      if (result < 0) {
        rtb_HILReadEncoderTimebase_o1 = 0;
        rtb_alpha = 0;
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lqg_test_M, _rt_error_message);
      } else {
        rtb_HILReadEncoderTimebase_o1 =
          lqg_test_DW.HILReadEncoderTimebase_Buffer[0];
        rtb_alpha = lqg_test_DW.HILReadEncoderTimebase_Buffer[1];
      }
    }

    /* Gain: '<S59>/Pendulum:  counts to rad' */
    lqg_test_B.Pendulumcountstorad = lqg_test_P.Pendulumcountstorad_Gain *
      rtb_alpha;

    /* Abs: '<Root>/|alpha|' incorporates:
     *  Constant: '<S61>/Constant2'
     *  Math: '<S61>/Math Function'
     */
    rtb_alpha = rt_modd_snf(lqg_test_B.Pendulumcountstorad,
      lqg_test_P.Constant2_Value);

    /* Bias: '<S61>/Bias' */
    lqg_test_B.Bias = rtb_alpha + lqg_test_P.Bias_Bias;

    /* Abs: '<Root>/|alpha|' */
    rtb_alpha = fabs(lqg_test_B.Bias);

    /* RelationalOperator: '<S2>/Compare' incorporates:
     *  Constant: '<S2>/Constant'
     */
    lqg_test_B.Compare = (uint8_T)(rtb_alpha <=
      lqg_test_P.EnableBalanceControl_const);

    /* DataTypeConversion: '<S3>/DataTypeConversionReset' */
    lqg_test_B.DataTypeConversionReset = (lqg_test_B.Compare != 0);

    /* Gain: '<S59>/Arm: counts to rad' */
    lqg_test_B.Armcountstorad = lqg_test_P.Armcountstorad_Gain *
      rtb_HILReadEncoderTimebase_o1;
  }

  /* TransferFcn: '<S60>/theta_dot' */
  lqg_test_B.theta_dot = 0.0;
  lqg_test_B.theta_dot += lqg_test_P.theta_dot_C * lqg_test_X.theta_dot_CSTATE;
  lqg_test_B.theta_dot += lqg_test_P.theta_dot_D * lqg_test_B.Armcountstorad;

  /* TransferFcn: '<S60>/alpha_dot' */
  lqg_test_B.alpha_dot = 0.0;
  lqg_test_B.alpha_dot += lqg_test_P.alpha_dot_C * lqg_test_X.alpha_dot_CSTATE;
  lqg_test_B.alpha_dot += lqg_test_P.alpha_dot_D *
    lqg_test_B.Pendulumcountstorad;

  /* Reshape: '<S3>/ReshapeX0' */
  lqg_test_B.ReshapeX0[0] = lqg_test_B.Armcountstorad;
  lqg_test_B.ReshapeX0[1] = lqg_test_B.Bias;
  lqg_test_B.ReshapeX0[2] = lqg_test_B.theta_dot;
  lqg_test_B.ReshapeX0[3] = lqg_test_B.alpha_dot;

  /* Integrator: '<S3>/MemoryX' */
  if (rtmIsMajorTimeStep(lqg_test_M)) {
    boolean_T didZcEventOccur;
    didZcEventOccur = (((lqg_test_PrevZCX.MemoryX_Reset_ZCE == POS_ZCSIG) !=
                        (int32_T)lqg_test_B.DataTypeConversionReset) &&
                       (lqg_test_PrevZCX.MemoryX_Reset_ZCE !=
                        UNINITIALIZED_ZCSIG));
    lqg_test_PrevZCX.MemoryX_Reset_ZCE = lqg_test_B.DataTypeConversionReset;

    /* evaluate zero-crossings */
    if (didZcEventOccur || (lqg_test_DW.MemoryX_IWORK != 0)) {
      lqg_test_X.MemoryX_CSTATE[0] = lqg_test_B.ReshapeX0[0];
      lqg_test_X.MemoryX_CSTATE[1] = lqg_test_B.ReshapeX0[1];
      lqg_test_X.MemoryX_CSTATE[2] = lqg_test_B.ReshapeX0[2];
      lqg_test_X.MemoryX_CSTATE[3] = lqg_test_B.ReshapeX0[3];
    }
  }

  /* Gain: '<S4>/Gain' incorporates:
   *  Integrator: '<S3>/MemoryX'
   */
  lqg_test_B.Gain[0] = lqg_test_P.Gain_Gain * lqg_test_B.Bias;
  lqg_test_B.Gain[1] = lqg_test_P.Gain_Gain * lqg_test_X.MemoryX_CSTATE[1];
  if (rtmIsMajorTimeStep(lqg_test_M)) {
  }

  /* Gain: '<S1>/Gain1' incorporates:
   *  Gain: '<Root>/Gain'
   *  SignalGenerator: '<Root>/Signal Generator'
   */
  rtb_Gain1 = sin(6.2831853071795862 * lqg_test_M->Timing.t[0] *
                  lqg_test_P.SignalGenerator_Frequency) *
    lqg_test_P.SignalGenerator_Amplitude * lqg_test_P.Gain_Gain_e *
    lqg_test_P.Gain1_Gain;

  /* Gain: '<S5>/Gain' incorporates:
   *  Integrator: '<S3>/MemoryX'
   */
  lqg_test_B.Gain_b[0] = lqg_test_P.Gain_Gain_a * rtb_Gain1;
  lqg_test_B.Gain_b[1] = lqg_test_P.Gain_Gain_a * lqg_test_B.Armcountstorad;
  lqg_test_B.Gain_b[2] = lqg_test_P.Gain_Gain_a * lqg_test_X.MemoryX_CSTATE[0];
  if (rtmIsMajorTimeStep(lqg_test_M)) {
  }

  /* MultiPortSwitch: '<Root>/Enable Balance Control Switch' */
  if (lqg_test_B.Compare == 0) {
    /* MultiPortSwitch: '<Root>/Enable Balance Control Switch' incorporates:
     *  Constant: '<Root>/Constant'
     */
    lqg_test_B.EnableBalanceControlSwitch = lqg_test_P.Constant_Value;
  } else {
    /* MultiPortSwitch: '<Root>/Enable Balance Control Switch' incorporates:
     *  Gain: '<Root>/Convert to Vector'
     *  Gain: '<Root>/u = -K*x'
     *  Integrator: '<S3>/MemoryX'
     *  Sum: '<Root>/Sum'
     */
    lqg_test_B.EnableBalanceControlSwitch = (((lqg_test_P.ConverttoVector_Gain[0]
      * rtb_Gain1 - lqg_test_X.MemoryX_CSTATE[0]) * lqg_test_P.K_new[0] +
      (lqg_test_P.ConverttoVector_Gain[1] * rtb_Gain1 -
       lqg_test_X.MemoryX_CSTATE[1]) * lqg_test_P.K_new[1]) +
      (lqg_test_P.ConverttoVector_Gain[2] * rtb_Gain1 -
       lqg_test_X.MemoryX_CSTATE[2]) * lqg_test_P.K_new[2]) +
      (lqg_test_P.ConverttoVector_Gain[3] * rtb_Gain1 -
       lqg_test_X.MemoryX_CSTATE[3]) * lqg_test_P.K_new[3];
  }

  /* End of MultiPortSwitch: '<Root>/Enable Balance Control Switch' */
  if (rtmIsMajorTimeStep(lqg_test_M)) {
    /* Reshape: '<S3>/Reshapey' */
    lqg_test_B.Reshapey[0] = lqg_test_B.Armcountstorad;
    lqg_test_B.Reshapey[1] = lqg_test_B.Bias;

    /* Outputs for Enabled SubSystem: '<S27>/MeasurementUpdate' incorporates:
     *  EnablePort: '<S57>/Enable'
     */
    if (rtmIsMajorTimeStep(lqg_test_M)) {
      /* Constant: '<S3>/Enable' */
      if (lqg_test_P.Enable_Value) {
        lqg_test_DW.MeasurementUpdate_MODE = true;
      } else if (lqg_test_DW.MeasurementUpdate_MODE) {
        /* Disable for Product: '<S57>/Product3' incorporates:
         *  Outport: '<S57>/L*(y[k]-yhat[k|k-1])'
         */
        lqg_test_B.Product3[0] = lqg_test_P.Lykyhatkk1_Y0;
        lqg_test_B.Product3[1] = lqg_test_P.Lykyhatkk1_Y0;
        lqg_test_B.Product3[2] = lqg_test_P.Lykyhatkk1_Y0;
        lqg_test_B.Product3[3] = lqg_test_P.Lykyhatkk1_Y0;
        lqg_test_DW.MeasurementUpdate_MODE = false;
      }

      /* End of Constant: '<S3>/Enable' */
    }

    /* End of Outputs for SubSystem: '<S27>/MeasurementUpdate' */
  }

  /* Outputs for Enabled SubSystem: '<S27>/MeasurementUpdate' incorporates:
   *  EnablePort: '<S57>/Enable'
   */
  if (lqg_test_DW.MeasurementUpdate_MODE) {
    for (i = 0; i <= 0; i += 2) {
      /* Constant: '<S3>/C' incorporates:
       *  Product: '<S57>/C[k]*xhat[k|k-1]'
       */
      tmp_0 = _mm_loadu_pd(&lqg_test_P.C_Value[i]);

      /* Sum: '<S57>/Sum' incorporates:
       *  Constant: '<S3>/C'
       *  Constant: '<S3>/D'
       *  Integrator: '<S3>/MemoryX'
       *  Product: '<S57>/C[k]*xhat[k|k-1]'
       *  Product: '<S57>/D[k]*u[k]'
       */
      tmp_1 = _mm_loadu_pd(&lqg_test_B.Reshapey[i]);
      _mm_storeu_pd(&tmp[i], _mm_sub_pd(tmp_1, _mm_add_pd(_mm_mul_pd
        (_mm_loadu_pd(&lqg_test_P.D_Value[i]), _mm_set1_pd
         (lqg_test_B.EnableBalanceControlSwitch)), _mm_add_pd(_mm_mul_pd
        (_mm_loadu_pd(&lqg_test_P.C_Value[i + 6]), _mm_set1_pd
         (lqg_test_X.MemoryX_CSTATE[3])), _mm_add_pd(_mm_mul_pd(_mm_loadu_pd
        (&lqg_test_P.C_Value[i + 4]), _mm_set1_pd(lqg_test_X.MemoryX_CSTATE[2])),
        _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&lqg_test_P.C_Value[i + 2]),
        _mm_set1_pd(lqg_test_X.MemoryX_CSTATE[1])), _mm_add_pd(_mm_mul_pd(tmp_0,
        _mm_set1_pd(lqg_test_X.MemoryX_CSTATE[0])), _mm_set1_pd(0.0))))))));
    }

    for (i = 0; i <= 2; i += 2) {
      /* Product: '<S57>/Product3' incorporates:
       *  Constant: '<S8>/KalmanGainL'
       */
      _mm_storeu_pd(&lqg_test_B.Product3[i], _mm_set1_pd(0.0));

      /* Product: '<S57>/Product3' incorporates:
       *  Constant: '<S8>/KalmanGainL'
       */
      tmp_0 = _mm_loadu_pd(&lqg_test_B.Product3[i]);

      /* Product: '<S57>/Product3' incorporates:
       *  Constant: '<S8>/KalmanGainL'
       */
      _mm_storeu_pd(&lqg_test_B.Product3[i], _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(
        &lqg_test_P.KalmanGainL_Value[i]), _mm_set1_pd(tmp[0])), tmp_0));

      /* Product: '<S57>/Product3' incorporates:
       *  Constant: '<S8>/KalmanGainL'
       */
      tmp_0 = _mm_loadu_pd(&lqg_test_B.Product3[i]);

      /* Product: '<S57>/Product3' incorporates:
       *  Constant: '<S8>/KalmanGainL'
       */
      _mm_storeu_pd(&lqg_test_B.Product3[i], _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(
        &lqg_test_P.KalmanGainL_Value[i + 4]), _mm_set1_pd(tmp[1])), tmp_0));
    }

    if (rtmIsMajorTimeStep(lqg_test_M)) {
      srUpdateBC(lqg_test_DW.MeasurementUpdate_SubsysRanBC);
    }
  }

  /* End of Outputs for SubSystem: '<S27>/MeasurementUpdate' */
  for (i = 0; i <= 2; i += 2) {
    /* Constant: '<S3>/A' incorporates:
     *  Product: '<S27>/A[k]*xhat[k|k-1]'
     */
    tmp_0 = _mm_loadu_pd(&lqg_test_P.A_Value[i]);

    /* Sum: '<S27>/Add' incorporates:
     *  Constant: '<S3>/A'
     *  Product: '<S27>/A[k]*xhat[k|k-1]'
     *  Product: '<S57>/Product3'
     */
    tmp_1 = _mm_loadu_pd(&lqg_test_B.Product3[i]);

    /* Sum: '<S27>/Add' incorporates:
     *  Constant: '<S3>/A'
     *  Constant: '<S3>/B'
     *  Integrator: '<S3>/MemoryX'
     *  Product: '<S27>/A[k]*xhat[k|k-1]'
     *  Product: '<S27>/B[k]*u[k]'
     */
    _mm_storeu_pd(&lqg_test_B.Add[i], _mm_add_pd(_mm_add_pd(_mm_mul_pd
      (_mm_loadu_pd(&lqg_test_P.B_Value[i]), _mm_set1_pd
       (lqg_test_B.EnableBalanceControlSwitch)), _mm_add_pd(_mm_mul_pd
      (_mm_loadu_pd(&lqg_test_P.A_Value[i + 12]), _mm_set1_pd
       (lqg_test_X.MemoryX_CSTATE[3])), _mm_add_pd(_mm_mul_pd(_mm_loadu_pd
      (&lqg_test_P.A_Value[i + 8]), _mm_set1_pd(lqg_test_X.MemoryX_CSTATE[2])),
      _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&lqg_test_P.A_Value[i + 4]),
      _mm_set1_pd(lqg_test_X.MemoryX_CSTATE[1])), _mm_add_pd(_mm_mul_pd(tmp_0,
      _mm_set1_pd(lqg_test_X.MemoryX_CSTATE[0])), _mm_set1_pd(0.0)))))), tmp_1));
  }

  /* Gain: '<S6>/For +ve CCW' */
  lqg_test_B.ForveCCW = lqg_test_P.ForveCCW_Gain *
    lqg_test_B.EnableBalanceControlSwitch;
  if (rtmIsMajorTimeStep(lqg_test_M)) {
    /* S-Function (hil_write_analog_block): '<S6>/HIL Write Analog' */

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

    /* Gain: '<S67>/Pend Torque (N.m)' incorporates:
     *  Constant: '<S67>/Constant'
     *  Sum: '<S67>/Sum1'
     *  Trigonometry: '<S67>/cos(alpha)'
     */
    lqg_test_B.PendTorqueNm = lqg_test_P.mp * lqg_test_P.g * lqg_test_P.l *
      (lqg_test_P.Constant_Value_o - cos(lqg_test_B.Pendulumcountstorad));
  }

  /* Gain: '<S64>/J to mJ' incorporates:
   *  Gain: '<S67>/Pend Inertia (kg.m^2)'
   *  Math: '<S67>/alpha_dot^2'
   *  Sum: '<S67>/Energy'
   */
  lqg_test_B.JtomJ = (lqg_test_P.Jp_cm / 2.0 * (lqg_test_B.alpha_dot *
    lqg_test_B.alpha_dot) + lqg_test_B.PendTorqueNm) * lqg_test_P.JtomJ_Gain;
  if (rtmIsMajorTimeStep(lqg_test_M)) {
  }
}

/* Model update function */
void lqg_test_update(void)
{
  /* Update for Integrator: '<S3>/MemoryX' */
  lqg_test_DW.MemoryX_IWORK = 0;
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

  /* Derivatives for TransferFcn: '<S60>/theta_dot' */
  _rtXdot->theta_dot_CSTATE = 0.0;
  _rtXdot->theta_dot_CSTATE += lqg_test_P.theta_dot_A *
    lqg_test_X.theta_dot_CSTATE;
  _rtXdot->theta_dot_CSTATE += lqg_test_B.Armcountstorad;

  /* Derivatives for TransferFcn: '<S60>/alpha_dot' */
  _rtXdot->alpha_dot_CSTATE = 0.0;
  _rtXdot->alpha_dot_CSTATE += lqg_test_P.alpha_dot_A *
    lqg_test_X.alpha_dot_CSTATE;
  _rtXdot->alpha_dot_CSTATE += lqg_test_B.Pendulumcountstorad;

  /* Derivatives for Integrator: '<S3>/MemoryX' */
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
    result = hil_set_card_specific_options(lqg_test_DW.HILInitialize_Card, " ",
      2);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(lqg_test_M, _rt_error_message);
      return;
    }

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

  /* Start for S-Function (hil_read_encoder_timebase_block): '<S6>/HIL Read Encoder Timebase' */

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

  /* Start for Enabled SubSystem: '<S27>/MeasurementUpdate' */
  lqg_test_DW.MeasurementUpdate_MODE = false;

  /* End of Start for SubSystem: '<S27>/MeasurementUpdate' */
  lqg_test_PrevZCX.MemoryX_Reset_ZCE = UNINITIALIZED_ZCSIG;

  /* InitializeConditions for TransferFcn: '<S60>/theta_dot' */
  lqg_test_X.theta_dot_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<S60>/alpha_dot' */
  lqg_test_X.alpha_dot_CSTATE = 0.0;

  /* InitializeConditions for Integrator: '<S3>/MemoryX' */
  if (rtmIsFirstInitCond(lqg_test_M)) {
    lqg_test_X.MemoryX_CSTATE[0] = 0.0;
    lqg_test_X.MemoryX_CSTATE[1] = 0.0;
    lqg_test_X.MemoryX_CSTATE[2] = 0.0;
    lqg_test_X.MemoryX_CSTATE[3] = 0.0;
  }

  lqg_test_DW.MemoryX_IWORK = 1;

  /* End of InitializeConditions for Integrator: '<S3>/MemoryX' */

  /* SystemInitialize for Enabled SubSystem: '<S27>/MeasurementUpdate' */
  /* SystemInitialize for Product: '<S57>/Product3' incorporates:
   *  Outport: '<S57>/L*(y[k]-yhat[k|k-1])'
   */
  lqg_test_B.Product3[0] = lqg_test_P.Lykyhatkk1_Y0;
  lqg_test_B.Product3[1] = lqg_test_P.Lykyhatkk1_Y0;
  lqg_test_B.Product3[2] = lqg_test_P.Lykyhatkk1_Y0;
  lqg_test_B.Product3[3] = lqg_test_P.Lykyhatkk1_Y0;

  /* End of SystemInitialize for SubSystem: '<S27>/MeasurementUpdate' */

  /* set "at time zero" to false */
  if (rtmIsFirstInitCond(lqg_test_M)) {
    rtmSetFirstInitCond(lqg_test_M, 0);
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
  lqg_test_M->Sizes.checksums[0] = (1280752382U);
  lqg_test_M->Sizes.checksums[1] = (2434010662U);
  lqg_test_M->Sizes.checksums[2] = (3602918U);
  lqg_test_M->Sizes.checksums[3] = (222236076U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[4];
    lqg_test_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = (sysRanDType *)&lqg_test_DW.MeasurementUpdate_SubsysRanBC;
    systemRan[3] = &rtAlwaysEnabled;
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
  lqg_test_M->Sizes.numBlocks = (61);  /* Number of blocks */
  lqg_test_M->Sizes.numBlockIO = (17); /* Number of block outputs */
  lqg_test_M->Sizes.numBlockPrms = (182);/* Sum of parameter "widths" */
  return lqg_test_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
