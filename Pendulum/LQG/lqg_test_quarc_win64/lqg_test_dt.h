/*
 * lqg_test_dt.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "lqg_test".
 *
 * Model version              : 6.9
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C source code generated on : Thu May  7 15:06:21 2026
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T),
  sizeof(int32_T),
  sizeof(t_uint64),
  sizeof(t_card),
  sizeof(t_task),
  sizeof(char_T),
  sizeof(uchar_T),
  sizeof(time_T)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T",
  "physical_connection",
  "t_uint64",
  "t_card",
  "t_task",
  "char_T",
  "uchar_T",
  "time_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&lqg_test_B.Pendulumcountstorad), 0, 0, 40 },

  { (char_T *)(&lqg_test_B.Compare), 3, 0, 1 },

  { (char_T *)(&lqg_test_B.DataTypeConversionReset), 8, 0, 1 }
  ,

  { (char_T *)(&lqg_test_DW.HILInitialize_FilterFrequency[0]), 0, 0, 4 },

  { (char_T *)(&lqg_test_DW.ToHostFile_PointsWritten), 15, 0, 1 },

  { (char_T *)(&lqg_test_DW.HILInitialize_Card), 16, 0, 1 },

  { (char_T *)(&lqg_test_DW.HILReadEncoderTimebase_Task), 17, 0, 1 },

  { (char_T *)(&lqg_test_DW.Pendulumdeg_PWORK.LoggedData), 11, 0, 9 },

  { (char_T *)(&lqg_test_DW.HILInitialize_ClockModes), 6, 0, 8 },

  { (char_T *)(&lqg_test_DW.RandSeed), 7, 0, 4 },

  { (char_T *)(&lqg_test_DW.MemoryX_IWORK), 10, 0, 1 },

  { (char_T *)(&lqg_test_DW.MeasurementUpdate_SubsysRanBC), 2, 0, 1 },

  { (char_T *)(&lqg_test_DW.MeasurementUpdate_MODE), 8, 0, 1 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  13U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&lqg_test_P.Jp_cm), 0, 0, 23 },

  { (char_T *)(&lqg_test_P.HILWriteAnalog_channels), 7, 0, 1 },

  { (char_T *)(&lqg_test_P.Lykyhatkk1_Y0), 0, 0, 118 },

  { (char_T *)(&lqg_test_P.HILInitialize_CKChannels), 6, 0, 4 },

  { (char_T *)(&lqg_test_P.HILInitialize_AIChannels), 7, 0, 14 },

  { (char_T *)(&lqg_test_P.HILInitialize_Active), 8, 0, 39 },

  { (char_T *)(&lqg_test_P.HILReadEncoderTimebase_Overflow), 3, 0, 16 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  7U,
  rtPTransitions
};

/* [EOF] lqg_test_dt.h */
