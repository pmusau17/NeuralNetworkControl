/*
 * neural_controller.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "neural_controller".
 *
 * Model version              : 1.239
 * Simulink Coder version : 8.12 (R2017a) 16-Feb-2017
 * C source code generated on : Thu Dec 13 12:04:56 2018
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "neural_controller.h"
#include "neural_controller_private.h"
#include "neural_controller_dt.h"

/* Block signals (auto storage) */
B_neural_controller_T neural_controller_B;

/* Block states (auto storage) */
DW_neural_controller_T neural_controller_DW;

/* Real-time model */
RT_MODEL_neural_controller_T neural_controller_M_;
RT_MODEL_neural_controller_T *const neural_controller_M = &neural_controller_M_;

/*
 * Writes out MAT-file header.  Returns success or failure.
 * Returns:
 *      0 - success
 *      1 - failure
 */
int_T rt_WriteMat4FileHeader(FILE *fp, int32_T m, int32_T n, const char *name)
{
  typedef enum { ELITTLE_ENDIAN, EBIG_ENDIAN } ByteOrder;

  int16_T one = 1;
  ByteOrder byteOrder = (*((int8_T *)&one)==1) ? ELITTLE_ENDIAN : EBIG_ENDIAN;
  int32_T type = (byteOrder == ELITTLE_ENDIAN) ? 0: 1000;
  int32_T imagf = 0;
  int32_T name_len = (int32_T)strlen(name) + 1;
  if ((fwrite(&type, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&m, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&n, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&imagf, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&name_len, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(name, sizeof(char), name_len, fp) == 0)) {
    return(1);
  } else {
    return(0);
  }
}                                      /* end rt_WriteMat4FileHeader */

/* Model output function */
void neural_controller_output(void)
{
  /* local block i/o variables */
  real_T rtb_HILReadEncoder1;
  real_T rtb_netsum_g_idx_0;
  real_T rtb_netsum_g_idx_1;

  /* Constant: '<Root>/Constant3' */
  neural_controller_B.Constant3 = neural_controller_P.Constant3_Value;

  /* DotProduct: '<S15>/Dot Product' incorporates:
   *  Constant: '<S12>/IW{1,1}(2,:)''
   */
  rtb_HILReadEncoder1 = neural_controller_P.IW112_Value *
    neural_controller_B.Constant3;

  /* Sum: '<S6>/netsum' incorporates:
   *  Constant: '<S12>/IW{1,1}(1,:)''
   *  Constant: '<S6>/b{1}'
   *  DotProduct: '<S14>/Dot Product'
   */
  rtb_netsum_g_idx_0 = neural_controller_P.IW111_Value *
    neural_controller_B.Constant3 + neural_controller_P.b1_Value[0];
  rtb_netsum_g_idx_1 = rtb_HILReadEncoder1 + neural_controller_P.b1_Value[1];

  /* DotProduct: '<S19>/Dot Product' incorporates:
   *  Constant: '<S17>/IW{2,1}(1,:)''
   */
  rtb_HILReadEncoder1 = neural_controller_P.IW211_Value[0] * rtb_netsum_g_idx_0
    + neural_controller_P.IW211_Value[1] * rtb_netsum_g_idx_1;

  /* DotProduct: '<S24>/Dot Product' incorporates:
   *  Constant: '<S17>/IW{2,1}(2,:)''
   *  Constant: '<S22>/IW{3,2}(1,:)''
   *  Constant: '<S7>/b{2}'
   *  DotProduct: '<S20>/Dot Product'
   *  Sum: '<S7>/netsum'
   */
  rtb_HILReadEncoder1 = ((neural_controller_P.IW212_Value[0] *
    rtb_netsum_g_idx_0 + neural_controller_P.IW212_Value[1] * rtb_netsum_g_idx_1)
    + neural_controller_P.b2_Value[1]) * neural_controller_P.IW321_Value[1] +
    (rtb_HILReadEncoder1 + neural_controller_P.b2_Value[0]) *
    neural_controller_P.IW321_Value[0];

  /* Bias: '<S25>/Add min x' incorporates:
   *  Bias: '<S25>/Subtract min y'
   *  Constant: '<S8>/b{3}'
   *  Gain: '<S25>/Divide by range y'
   *  Sum: '<S8>/netsum'
   */
  neural_controller_B.Addminx = (neural_controller_P.mapminmax_reverse_xmax -
    neural_controller_P.mapminmax_reverse_xmin) /
    (neural_controller_P.mapminmax_reverse_ymax -
     neural_controller_P.mapminmax_reverse_ymin) * ((rtb_HILReadEncoder1 +
    neural_controller_P.b3_Value) + -neural_controller_P.mapminmax_reverse_ymin)
    + neural_controller_P.mapminmax_reverse_xmin;

  /* Sum: '<Root>/Add1' incorporates:
   *  Constant: '<Root>/Constant4'
   */
  neural_controller_B.Add1 = neural_controller_P.Constant4_Value +
    neural_controller_B.Addminx;

  /* S-Function (hil_write_analog_block): '<Root>/HIL Write Analog' */

  /* S-Function Block: neural_controller/HIL Write Analog (hil_write_analog_block) */
  {
    t_error result;
    result = hil_write_analog(neural_controller_DW.HILInitialize_Card,
      &neural_controller_P.HILWriteAnalog_channels, 1, &neural_controller_B.Add1);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(neural_controller_M, _rt_error_message);
    }
  }

  /* Sum: '<Root>/Subtract2' incorporates:
   *  Constant: '<Root>/Constant4'
   */
  neural_controller_B.Subtract2 = neural_controller_P.Constant4_Value -
    neural_controller_B.Addminx;

  /* S-Function (hil_write_analog_block): '<Root>/HIL Write Analog1' */

  /* S-Function Block: neural_controller/HIL Write Analog1 (hil_write_analog_block) */
  {
    t_error result;
    result = hil_write_analog(neural_controller_DW.HILInitialize_Card,
      &neural_controller_P.HILWriteAnalog1_channels, 1,
      &neural_controller_B.Subtract2);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(neural_controller_M, _rt_error_message);
    }
  }

  /* S-Function (hil_read_encoder_block): '<Root>/HIL Read Encoder1' */

  /* S-Function Block: neural_controller/HIL Read Encoder1 (hil_read_encoder_block) */
  {
    t_error result = hil_read_encoder(neural_controller_DW.HILInitialize_Card,
      &neural_controller_P.HILReadEncoder1_channels, 1,
      &neural_controller_DW.HILReadEncoder1_Buffer);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(neural_controller_M, _rt_error_message);
    } else {
      rtb_HILReadEncoder1 = neural_controller_DW.HILReadEncoder1_Buffer;
    }
  }

  /* Product: '<Root>/Product' incorporates:
   *  Constant: '<Root>/Constant1'
   *  Constant: '<Root>/Constant2'
   *  Product: '<Root>/Divide'
   */
  neural_controller_B.Product = rtb_HILReadEncoder1 /
    neural_controller_P.Constant1_Value * neural_controller_P.Constant2_Value;

  /* ToFile: '<Root>/To File' */
  {
    if (!(++neural_controller_DW.ToFile_IWORK.Decimation % 1) &&
        (neural_controller_DW.ToFile_IWORK.Count * (1 + 1)) + 1 < 100000000 ) {
      FILE *fp = (FILE *) neural_controller_DW.ToFile_PWORK.FilePtr;
      if (fp != (NULL)) {
        real_T u[1 + 1];
        neural_controller_DW.ToFile_IWORK.Decimation = 0;
        u[0] = neural_controller_M->Timing.t[1];
        u[1] = neural_controller_B.Product;
        if (fwrite(u, sizeof(real_T), 1 + 1, fp) != 1 + 1) {
          rtmSetErrorStatus(neural_controller_M,
                            "Error writing to MAT-file encoder_reading.mat");
          return;
        }

        if (((++neural_controller_DW.ToFile_IWORK.Count) * (1 + 1))+1 >=
            100000000) {
          (void)fprintf(stdout,
                        "*** The ToFile block will stop logging data before\n"
                        "    the simulation has ended, because it has reached\n"
                        "    the maximum number of elements (100000000)\n"
                        "    allowed in MAT-file encoder_reading.mat.\n");
        }
      }
    }
  }

  /* ToFile: '<Root>/To File1' */
  {
    if (!(++neural_controller_DW.ToFile1_IWORK.Decimation % 1) &&
        (neural_controller_DW.ToFile1_IWORK.Count * (1 + 1)) + 1 < 100000000 ) {
      FILE *fp = (FILE *) neural_controller_DW.ToFile1_PWORK.FilePtr;
      if (fp != (NULL)) {
        real_T u[1 + 1];
        neural_controller_DW.ToFile1_IWORK.Decimation = 0;
        u[0] = neural_controller_M->Timing.t[1];
        u[1] = neural_controller_B.Addminx;
        if (fwrite(u, sizeof(real_T), 1 + 1, fp) != 1 + 1) {
          rtmSetErrorStatus(neural_controller_M,
                            "Error writing to MAT-file input_signal.mat");
          return;
        }

        if (((++neural_controller_DW.ToFile1_IWORK.Count) * (1 + 1))+1 >=
            100000000) {
          (void)fprintf(stdout,
                        "*** The ToFile block will stop logging data before\n"
                        "    the simulation has ended, because it has reached\n"
                        "    the maximum number of elements (100000000)\n"
                        "    allowed in MAT-file input_signal.mat.\n");
        }
      }
    }
  }
}

/* Model update function */
void neural_controller_update(void)
{
  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++neural_controller_M->Timing.clockTick0)) {
    ++neural_controller_M->Timing.clockTickH0;
  }

  neural_controller_M->Timing.t[0] = neural_controller_M->Timing.clockTick0 *
    neural_controller_M->Timing.stepSize0 +
    neural_controller_M->Timing.clockTickH0 *
    neural_controller_M->Timing.stepSize0 * 4294967296.0;

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
    if (!(++neural_controller_M->Timing.clockTick1)) {
      ++neural_controller_M->Timing.clockTickH1;
    }

    neural_controller_M->Timing.t[1] = neural_controller_M->Timing.clockTick1 *
      neural_controller_M->Timing.stepSize1 +
      neural_controller_M->Timing.clockTickH1 *
      neural_controller_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Model initialize function */
void neural_controller_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: neural_controller/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("q8", "0", &neural_controller_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(neural_controller_M, _rt_error_message);
      return;
    }

    is_switching = false;
    if ((neural_controller_P.HILInitialize_CKPStart && !is_switching) ||
        (neural_controller_P.HILInitialize_CKPEnter && is_switching)) {
      result = hil_set_clock_mode(neural_controller_DW.HILInitialize_Card,
        (t_clock *) neural_controller_P.HILInitialize_CKChannels, 2U,
        (t_clock_mode *) neural_controller_P.HILInitialize_CKModes);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(neural_controller_M, _rt_error_message);
        return;
      }
    }

    result = hil_watchdog_clear(neural_controller_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(neural_controller_M, _rt_error_message);
      return;
    }

    if ((neural_controller_P.HILInitialize_AIPStart && !is_switching) ||
        (neural_controller_P.HILInitialize_AIPEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AIMinimums = &neural_controller_DW.HILInitialize_AIMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMinimums[i1] = (neural_controller_P.HILInitialize_AILow);
        }
      }

      {
        int_T i1;
        real_T *dw_AIMaximums = &neural_controller_DW.HILInitialize_AIMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMaximums[i1] = neural_controller_P.HILInitialize_AIHigh;
        }
      }

      result = hil_set_analog_input_ranges
        (neural_controller_DW.HILInitialize_Card,
         neural_controller_P.HILInitialize_AIChannels, 8U,
         &neural_controller_DW.HILInitialize_AIMinimums[0],
         &neural_controller_DW.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(neural_controller_M, _rt_error_message);
        return;
      }
    }

    if ((neural_controller_P.HILInitialize_AOPStart && !is_switching) ||
        (neural_controller_P.HILInitialize_AOPEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOMinimums = &neural_controller_DW.HILInitialize_AOMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMinimums[i1] = (neural_controller_P.HILInitialize_AOLow);
        }
      }

      {
        int_T i1;
        real_T *dw_AOMaximums = &neural_controller_DW.HILInitialize_AOMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMaximums[i1] = neural_controller_P.HILInitialize_AOHigh;
        }
      }

      result = hil_set_analog_output_ranges
        (neural_controller_DW.HILInitialize_Card,
         neural_controller_P.HILInitialize_AOChannels, 8U,
         &neural_controller_DW.HILInitialize_AOMinimums[0],
         &neural_controller_DW.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(neural_controller_M, _rt_error_message);
        return;
      }
    }

    if ((neural_controller_P.HILInitialize_AOStart && !is_switching) ||
        (neural_controller_P.HILInitialize_AOEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &neural_controller_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = neural_controller_P.HILInitialize_AOInitial;
        }
      }

      result = hil_write_analog(neural_controller_DW.HILInitialize_Card,
        neural_controller_P.HILInitialize_AOChannels, 8U,
        &neural_controller_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(neural_controller_M, _rt_error_message);
        return;
      }
    }

    if (neural_controller_P.HILInitialize_AOReset) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &neural_controller_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = neural_controller_P.HILInitialize_AOWatchdog;
        }
      }

      result = hil_watchdog_set_analog_expiration_state
        (neural_controller_DW.HILInitialize_Card,
         neural_controller_P.HILInitialize_AOChannels, 8U,
         &neural_controller_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(neural_controller_M, _rt_error_message);
        return;
      }
    }

    if ((neural_controller_P.HILInitialize_EIPStart && !is_switching) ||
        (neural_controller_P.HILInitialize_EIPEnter && is_switching)) {
      {
        int_T i1;
        int32_T *dw_QuadratureModes =
          &neural_controller_DW.HILInitialize_QuadratureModes[0];
        for (i1=0; i1 < 8; i1++) {
          dw_QuadratureModes[i1] =
            neural_controller_P.HILInitialize_EIQuadrature;
        }
      }

      result = hil_set_encoder_quadrature_mode
        (neural_controller_DW.HILInitialize_Card,
         neural_controller_P.HILInitialize_EIChannels, 8U,
         (t_encoder_quadrature_mode *)
         &neural_controller_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(neural_controller_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        real_T *dw_FilterFrequency =
          &neural_controller_DW.HILInitialize_FilterFrequency[0];
        for (i1=0; i1 < 8; i1++) {
          dw_FilterFrequency[i1] = neural_controller_P.HILInitialize_EIFrequency;
        }
      }

      result = hil_set_encoder_filter_frequency
        (neural_controller_DW.HILInitialize_Card,
         neural_controller_P.HILInitialize_EIChannels, 8U,
         &neural_controller_DW.HILInitialize_FilterFrequency[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(neural_controller_M, _rt_error_message);
        return;
      }
    }

    if ((neural_controller_P.HILInitialize_EIStart && !is_switching) ||
        (neural_controller_P.HILInitialize_EIEnter && is_switching)) {
      {
        int_T i1;
        int32_T *dw_InitialEICounts =
          &neural_controller_DW.HILInitialize_InitialEICounts[0];
        for (i1=0; i1 < 8; i1++) {
          dw_InitialEICounts[i1] = neural_controller_P.HILInitialize_EIInitial;
        }
      }

      result = hil_set_encoder_counts(neural_controller_DW.HILInitialize_Card,
        neural_controller_P.HILInitialize_EIChannels, 8U,
        &neural_controller_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(neural_controller_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for ToFile: '<Root>/To File' */
  {
    FILE *fp = (NULL);
    char fileName[509] = "encoder_reading.mat";
    if ((fp = fopen(fileName, "wb")) == (NULL)) {
      rtmSetErrorStatus(neural_controller_M,
                        "Error creating .mat file encoder_reading.mat");
      return;
    }

    if (rt_WriteMat4FileHeader(fp, 1 + 1, 0, "encoder_readings")) {
      rtmSetErrorStatus(neural_controller_M,
                        "Error writing mat file header to file encoder_reading.mat");
      return;
    }

    neural_controller_DW.ToFile_IWORK.Count = 0;
    neural_controller_DW.ToFile_IWORK.Decimation = -1;
    neural_controller_DW.ToFile_PWORK.FilePtr = fp;
  }

  /* Start for ToFile: '<Root>/To File1' */
  {
    FILE *fp = (NULL);
    char fileName[509] = "input_signal.mat";
    if ((fp = fopen(fileName, "wb")) == (NULL)) {
      rtmSetErrorStatus(neural_controller_M,
                        "Error creating .mat file input_signal.mat");
      return;
    }

    if (rt_WriteMat4FileHeader(fp, 1 + 1, 0, "input_voltage_readings")) {
      rtmSetErrorStatus(neural_controller_M,
                        "Error writing mat file header to file input_signal.mat");
      return;
    }

    neural_controller_DW.ToFile1_IWORK.Count = 0;
    neural_controller_DW.ToFile1_IWORK.Decimation = -1;
    neural_controller_DW.ToFile1_PWORK.FilePtr = fp;
  }
}

/* Model terminate function */
void neural_controller_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: neural_controller/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    hil_task_stop_all(neural_controller_DW.HILInitialize_Card);
    hil_monitor_stop_all(neural_controller_DW.HILInitialize_Card);
    is_switching = false;
    if ((neural_controller_P.HILInitialize_AOTerminate && !is_switching) ||
        (neural_controller_P.HILInitialize_AOExit && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &neural_controller_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = neural_controller_P.HILInitialize_AOFinal;
        }
      }

      num_final_analog_outputs = 8U;
    }

    if (num_final_analog_outputs > 0) {
      result = hil_write_analog(neural_controller_DW.HILInitialize_Card,
        neural_controller_P.HILInitialize_AOChannels, num_final_analog_outputs,
        &neural_controller_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(neural_controller_M, _rt_error_message);
      }
    }

    hil_task_delete_all(neural_controller_DW.HILInitialize_Card);
    hil_monitor_delete_all(neural_controller_DW.HILInitialize_Card);
    hil_close(neural_controller_DW.HILInitialize_Card);
    neural_controller_DW.HILInitialize_Card = NULL;
  }

  /* Terminate for ToFile: '<Root>/To File' */
  {
    FILE *fp = (FILE *) neural_controller_DW.ToFile_PWORK.FilePtr;
    if (fp != (NULL)) {
      char fileName[509] = "encoder_reading.mat";
      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(neural_controller_M,
                          "Error closing MAT-file encoder_reading.mat");
        return;
      }

      if ((fp = fopen(fileName, "r+b")) == (NULL)) {
        rtmSetErrorStatus(neural_controller_M,
                          "Error reopening MAT-file encoder_reading.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp, 1 + 1,
           neural_controller_DW.ToFile_IWORK.Count, "encoder_readings")) {
        rtmSetErrorStatus(neural_controller_M,
                          "Error writing header for encoder_readings to MAT-file encoder_reading.mat");
      }

      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(neural_controller_M,
                          "Error closing MAT-file encoder_reading.mat");
        return;
      }

      neural_controller_DW.ToFile_PWORK.FilePtr = (NULL);
    }
  }

  /* Terminate for ToFile: '<Root>/To File1' */
  {
    FILE *fp = (FILE *) neural_controller_DW.ToFile1_PWORK.FilePtr;
    if (fp != (NULL)) {
      char fileName[509] = "input_signal.mat";
      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(neural_controller_M,
                          "Error closing MAT-file input_signal.mat");
        return;
      }

      if ((fp = fopen(fileName, "r+b")) == (NULL)) {
        rtmSetErrorStatus(neural_controller_M,
                          "Error reopening MAT-file input_signal.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp, 1 + 1,
           neural_controller_DW.ToFile1_IWORK.Count, "input_voltage_readings"))
      {
        rtmSetErrorStatus(neural_controller_M,
                          "Error writing header for input_voltage_readings to MAT-file input_signal.mat");
      }

      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(neural_controller_M,
                          "Error closing MAT-file input_signal.mat");
        return;
      }

      neural_controller_DW.ToFile1_PWORK.FilePtr = (NULL);
    }
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  neural_controller_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  neural_controller_update();
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
  neural_controller_initialize();
}

void MdlTerminate(void)
{
  neural_controller_terminate();
}

/* Registration function */
RT_MODEL_neural_controller_T *neural_controller(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)neural_controller_M, 0,
                sizeof(RT_MODEL_neural_controller_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&neural_controller_M->solverInfo,
                          &neural_controller_M->Timing.simTimeStep);
    rtsiSetTPtr(&neural_controller_M->solverInfo, &rtmGetTPtr
                (neural_controller_M));
    rtsiSetStepSizePtr(&neural_controller_M->solverInfo,
                       &neural_controller_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&neural_controller_M->solverInfo, (&rtmGetErrorStatus
      (neural_controller_M)));
    rtsiSetRTModelPtr(&neural_controller_M->solverInfo, neural_controller_M);
  }

  rtsiSetSimTimeStep(&neural_controller_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&neural_controller_M->solverInfo,"FixedStepDiscrete");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = neural_controller_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    neural_controller_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    neural_controller_M->Timing.sampleTimes =
      (&neural_controller_M->Timing.sampleTimesArray[0]);
    neural_controller_M->Timing.offsetTimes =
      (&neural_controller_M->Timing.offsetTimesArray[0]);

    /* task periods */
    neural_controller_M->Timing.sampleTimes[0] = (0.0);
    neural_controller_M->Timing.sampleTimes[1] = (0.002);

    /* task offsets */
    neural_controller_M->Timing.offsetTimes[0] = (0.0);
    neural_controller_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(neural_controller_M, &neural_controller_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = neural_controller_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    neural_controller_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(neural_controller_M, -1);
  neural_controller_M->Timing.stepSize0 = 0.002;
  neural_controller_M->Timing.stepSize1 = 0.002;

  /* External mode info */
  neural_controller_M->Sizes.checksums[0] = (2449951517U);
  neural_controller_M->Sizes.checksums[1] = (387705153U);
  neural_controller_M->Sizes.checksums[2] = (108044941U);
  neural_controller_M->Sizes.checksums[3] = (1104546612U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    neural_controller_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(neural_controller_M->extModeInfo,
      &neural_controller_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(neural_controller_M->extModeInfo,
                        neural_controller_M->Sizes.checksums);
    rteiSetTPtr(neural_controller_M->extModeInfo, rtmGetTPtr(neural_controller_M));
  }

  neural_controller_M->solverInfoPtr = (&neural_controller_M->solverInfo);
  neural_controller_M->Timing.stepSize = (0.002);
  rtsiSetFixedStepSize(&neural_controller_M->solverInfo, 0.002);
  rtsiSetSolverMode(&neural_controller_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  neural_controller_M->blockIO = ((void *) &neural_controller_B);

  {
    neural_controller_B.Constant3 = 0.0;
    neural_controller_B.Addminx = 0.0;
    neural_controller_B.Add1 = 0.0;
    neural_controller_B.Subtract2 = 0.0;
    neural_controller_B.Product = 0.0;
  }

  /* parameters */
  neural_controller_M->defaultParam = ((real_T *)&neural_controller_P);

  /* states (dwork) */
  neural_controller_M->dwork = ((void *) &neural_controller_DW);
  (void) memset((void *)&neural_controller_DW, 0,
                sizeof(DW_neural_controller_T));

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      neural_controller_DW.HILInitialize_AIMinimums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      neural_controller_DW.HILInitialize_AIMaximums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      neural_controller_DW.HILInitialize_AOMinimums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      neural_controller_DW.HILInitialize_AOMaximums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      neural_controller_DW.HILInitialize_AOVoltages[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      neural_controller_DW.HILInitialize_FilterFrequency[i] = 0.0;
    }
  }

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    neural_controller_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 15;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  neural_controller_M->Sizes.numContStates = (0);/* Number of continuous states */
  neural_controller_M->Sizes.numY = (0);/* Number of model outputs */
  neural_controller_M->Sizes.numU = (0);/* Number of model inputs */
  neural_controller_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  neural_controller_M->Sizes.numSampTimes = (2);/* Number of sample times */
  neural_controller_M->Sizes.numBlocks = (37);/* Number of blocks */
  neural_controller_M->Sizes.numBlockIO = (5);/* Number of block outputs */
  neural_controller_M->Sizes.numBlockPrms = (109);/* Sum of parameter "widths" */
  return neural_controller_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
