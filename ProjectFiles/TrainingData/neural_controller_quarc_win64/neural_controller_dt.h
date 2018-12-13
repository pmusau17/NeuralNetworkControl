/*
 * neural_controller_dt.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "neural_controller".
 *
 * Model version              : 1.238
 * Simulink Coder version : 8.12 (R2017a) 16-Feb-2017
 * C source code generated on : Wed Dec 12 09:56:14 2018
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
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
  sizeof(t_card)
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
  "t_card"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&neural_controller_B.SineWave), 0, 0, 5 }
  ,

  { (char_T *)(&neural_controller_DW.HILInitialize_AIMinimums[0]), 0, 0, 48 },

  { (char_T *)(&neural_controller_DW.HILInitialize_Card), 14, 0, 1 },

  { (char_T *)(&neural_controller_DW.HILWriteAnalog_PWORK), 11, 0, 10 },

  { (char_T *)(&neural_controller_DW.HILInitialize_QuadratureModes[0]), 6, 0, 17
  },

  { (char_T *)(&neural_controller_DW.ToFile_IWORK.Count), 10, 0, 2 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  6U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&neural_controller_P.mapminmax_reverse_xmax), 0, 0, 4 },

  { (char_T *)(&neural_controller_P.HILWriteAnalog_channels), 7, 0, 3 },

  { (char_T *)(&neural_controller_P.HILInitialize_OOTerminate), 0, 0, 35 },

  { (char_T *)(&neural_controller_P.HILInitialize_CKChannels[0]), 6, 0, 7 },

  { (char_T *)(&neural_controller_P.HILInitialize_AIChannels[0]), 7, 0, 25 },

  { (char_T *)(&neural_controller_P.HILInitialize_Active), 8, 0, 38 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  6U,
  rtPTransitions
};

/* [EOF] neural_controller_dt.h */
