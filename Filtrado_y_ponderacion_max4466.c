/*
 * Filtrado_y_ponderacion_max4466.c
 *
 * Code generation for model "Filtrado_y_ponderacion_max4466".
 *
 * Model version              : 1.14
 * Simulink Coder version : 9.5 (R2021a) 14-Nov-2020
 * C source code generated on : Mon Apr  3 12:48:56 2023
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Atmel->AVR
 * Code generation objective: Debugging
 * Validation result: Not run
 */

#include "Filtrado_y_ponderacion_max4466.h"
#include "Filtrado_y_ponderacion_max4466_private.h"

/* Block signals (default storage) */
B_Filtrado_y_ponderacion_max4_T Filtrado_y_ponderacion_max446_B;

/* Block states (default storage) */
DW_Filtrado_y_ponderacion_max_T Filtrado_y_ponderacion_max44_DW;

/* External outputs (root outports fed by signals with default storage) */
ExtY_Filtrado_y_ponderacion_m_T Filtrado_y_ponderacion_max446_Y;

/* Real-time model */
static RT_MODEL_Filtrado_y_ponderaci_T Filtrado_y_ponderacion_max44_M_;
RT_MODEL_Filtrado_y_ponderaci_T *const Filtrado_y_ponderacion_max44_M =
  &Filtrado_y_ponderacion_max44_M_;

/* Model step function */
void Filtrado_y_ponderacion_max4466_step(void)
{
  real_T numAccum;
  real_T u0;
  int32_T ioIdx;
  int16_T i;
  char_T *sErr;
  for (i = 0; i < 1024; i++) {
    /* DiscreteIntegrator: '<Root>/Discrete-Time Integrator' */
    Filtrado_y_ponderacion_max446_B.DiscreteTimeIntegrator[i] =
      Filtrado_y_ponderacion_max44_DW.DiscreteTimeIntegrator_DSTATE[i];

    /* Gain: '<Root>/Ganancia Vref' incorporates:
     *  DiscreteIntegrator: '<Root>/Discrete-Time Integrator'
     */
    Filtrado_y_ponderacion_max446_B.GananciaVref[i] =
      Filtrado_y_ponderacion_max446_P.GananciaVref_Gain *
      Filtrado_y_ponderacion_max446_B.DiscreteTimeIntegrator[i];

    /* MinMax: '<S2>/Max' incorporates:
     *  Constant: '<S2>/Constant'
     *  Gain: '<Root>/Ganancia Vref'
     */
    u0 = Filtrado_y_ponderacion_max446_B.GananciaVref[i];
    if ((!(u0 > Filtrado_y_ponderacion_max446_P.Constant_Value)) && (!rtIsNaN
         (Filtrado_y_ponderacion_max446_P.Constant_Value))) {
      u0 = Filtrado_y_ponderacion_max446_P.Constant_Value;
    }

    /* MinMax: '<S2>/Max' */
    Filtrado_y_ponderacion_max446_B.Max[i] = u0;

    /* Math: '<Root>/Log' incorporates:
     *  MinMax: '<S2>/Max'
     *
     * About '<Root>/Log':
     *  Operator: log
     */
    Filtrado_y_ponderacion_max446_B.Log[i] = log
      (Filtrado_y_ponderacion_max446_B.Max[i]);

    /* Outport: '<Root>/Output' incorporates:
     *  Gain: '<Root>/Gain2'
     *  Math: '<Root>/Log'
     *
     * About '<Root>/Log':
     *  Operator: log
     */
    Filtrado_y_ponderacion_max446_Y.Output[i] =
      Filtrado_y_ponderacion_max446_P.Gain2_Gain *
      Filtrado_y_ponderacion_max446_B.Log[i];
  }

  /* S-Function (saudioFromAudioDevice): '<Root>/Audio Device Reader' */
  sErr = GetErrorBuffer
    (&Filtrado_y_ponderacion_max44_DW.AudioDeviceReader_AudioDeviceLi[0UL]);
  LibOutputs_Audio
    (&Filtrado_y_ponderacion_max44_DW.AudioDeviceReader_AudioDeviceLi[0UL],
     &Filtrado_y_ponderacion_max446_B.AudioDeviceReader[0UL], 5L, 1024L, 0L);
  if (*sErr != 0) {
    rtmSetErrorStatus(Filtrado_y_ponderacion_max44_M, sErr);
    rtmSetStopRequested(Filtrado_y_ponderacion_max44_M, 1);
  }

  /* End of S-Function (saudioFromAudioDevice): '<Root>/Audio Device Reader' */

  /* S-Function (sdspbiquad): '<S1>/Generated Filter Block' incorporates:
   *  S-Function (saudioFromAudioDevice): '<Root>/Audio Device Reader'
   */
  ioIdx = 0L;
  for (i = 0; i < 1024; i++) {
    u0 = 0.78804816721176729 *
      Filtrado_y_ponderacion_max446_B.AudioDeviceReader[ioIdx];
    u0 -= -0.22455845805977917 *
      Filtrado_y_ponderacion_max44_DW.GeneratedFilterBlock_FILT_STATE[0L];
    u0 -= 0.0126066252715464 *
      Filtrado_y_ponderacion_max44_DW.GeneratedFilterBlock_FILT_STATE[1L];
    numAccum = 0.00032231859289771897 * u0;
    numAccum += 0.00064463718579543794 *
      Filtrado_y_ponderacion_max44_DW.GeneratedFilterBlock_FILT_STATE[0L];
    numAccum += 0.00032231859289771897 *
      Filtrado_y_ponderacion_max44_DW.GeneratedFilterBlock_FILT_STATE[1L];
    Filtrado_y_ponderacion_max44_DW.GeneratedFilterBlock_FILT_STATE[1L] =
      Filtrado_y_ponderacion_max44_DW.GeneratedFilterBlock_FILT_STATE[0L];
    Filtrado_y_ponderacion_max44_DW.GeneratedFilterBlock_FILT_STATE[0L] = u0;
    u0 = numAccum;
    u0 -= -1.8938704947230705 *
      Filtrado_y_ponderacion_max44_DW.GeneratedFilterBlock_FILT_STATE[2L];
    u0 -= 0.89515976909466144 *
      Filtrado_y_ponderacion_max44_DW.GeneratedFilterBlock_FILT_STATE[3L];
    numAccum = u0;
    numAccum += -2.0 *
      Filtrado_y_ponderacion_max44_DW.GeneratedFilterBlock_FILT_STATE[2L];
    numAccum += Filtrado_y_ponderacion_max44_DW.GeneratedFilterBlock_FILT_STATE
      [3L];
    Filtrado_y_ponderacion_max44_DW.GeneratedFilterBlock_FILT_STATE[3L] =
      Filtrado_y_ponderacion_max44_DW.GeneratedFilterBlock_FILT_STATE[2L];
    Filtrado_y_ponderacion_max44_DW.GeneratedFilterBlock_FILT_STATE[2L] = u0;
    u0 = numAccum;
    u0 -= -1.9946144559930217 *
      Filtrado_y_ponderacion_max44_DW.GeneratedFilterBlock_FILT_STATE[4L];
    u0 -= 0.99462170701408448 *
      Filtrado_y_ponderacion_max44_DW.GeneratedFilterBlock_FILT_STATE[5L];
    numAccum = u0;
    numAccum += -2.0 *
      Filtrado_y_ponderacion_max44_DW.GeneratedFilterBlock_FILT_STATE[4L];
    numAccum += Filtrado_y_ponderacion_max44_DW.GeneratedFilterBlock_FILT_STATE
      [5L];
    Filtrado_y_ponderacion_max44_DW.GeneratedFilterBlock_FILT_STATE[5L] =
      Filtrado_y_ponderacion_max44_DW.GeneratedFilterBlock_FILT_STATE[4L];
    Filtrado_y_ponderacion_max44_DW.GeneratedFilterBlock_FILT_STATE[4L] = u0;
    Filtrado_y_ponderacion_max446_B.GeneratedFilterBlock[ioIdx] =
      922.43864463225691 * numAccum;
    ioIdx++;
  }

  /* End of S-Function (sdspbiquad): '<S1>/Generated Filter Block' */
  for (i = 0; i < 1024; i++) {
    /* Saturate: '<Root>/Saturation' incorporates:
     *  S-Function (sdspbiquad): '<S1>/Generated Filter Block'
     */
    u0 = Filtrado_y_ponderacion_max446_B.GeneratedFilterBlock[i];
    if (u0 > Filtrado_y_ponderacion_max446_P.Saturation_UpperSat) {
      u0 = Filtrado_y_ponderacion_max446_P.Saturation_UpperSat;
    } else if (u0 < Filtrado_y_ponderacion_max446_P.Saturation_LowerSat) {
      u0 = Filtrado_y_ponderacion_max446_P.Saturation_LowerSat;
    }

    /* Saturate: '<Root>/Saturation' */
    Filtrado_y_ponderacion_max446_B.Saturation[i] = u0;

    /* Gain: '<Root>/Resitencia Fast' incorporates:
     *  Saturate: '<Root>/Saturation'
     */
    Filtrado_y_ponderacion_max446_B.ResitenciaFast[i] =
      Filtrado_y_ponderacion_max446_P.ResitenciaFast_Gain *
      Filtrado_y_ponderacion_max446_B.Saturation[i];

    /* Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' incorporates:
     *  Gain: '<Root>/Resitencia Fast'
     */
    Filtrado_y_ponderacion_max44_DW.DiscreteTimeIntegrator_DSTATE[i] +=
      Filtrado_y_ponderacion_max446_P.DiscreteTimeIntegrator_gainval *
      Filtrado_y_ponderacion_max446_B.ResitenciaFast[i];
  }

  /* Matfile logging */
  rt_UpdateTXYLogVars(Filtrado_y_ponderacion_max44_M->rtwLogInfo,
                      (&Filtrado_y_ponderacion_max44_M->Timing.taskTime0));

  /* signal main to stop simulation */
  {                             /* Sample time: [0.023219954648526078s, 0.0s] */
    if ((rtmGetTFinal(Filtrado_y_ponderacion_max44_M)!=-1) &&
        !((rtmGetTFinal(Filtrado_y_ponderacion_max44_M)-
           Filtrado_y_ponderacion_max44_M->Timing.taskTime0) >
          Filtrado_y_ponderacion_max44_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(Filtrado_y_ponderacion_max44_M, "Simulation finished");
    }
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
  if (!(++Filtrado_y_ponderacion_max44_M->Timing.clockTick0)) {
    ++Filtrado_y_ponderacion_max44_M->Timing.clockTickH0;
  }

  Filtrado_y_ponderacion_max44_M->Timing.taskTime0 =
    Filtrado_y_ponderacion_max44_M->Timing.clockTick0 *
    Filtrado_y_ponderacion_max44_M->Timing.stepSize0 +
    Filtrado_y_ponderacion_max44_M->Timing.clockTickH0 *
    Filtrado_y_ponderacion_max44_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void Filtrado_y_ponderacion_max4466_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Filtrado_y_ponderacion_max44_M, 0,
                sizeof(RT_MODEL_Filtrado_y_ponderaci_T));
  rtmSetTFinal(Filtrado_y_ponderacion_max44_M, 9.9845804988662135);
  Filtrado_y_ponderacion_max44_M->Timing.stepSize0 = 0.023219954648526078;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = (NULL);
    Filtrado_y_ponderacion_max44_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(Filtrado_y_ponderacion_max44_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(Filtrado_y_ponderacion_max44_M->rtwLogInfo, (NULL));
    rtliSetLogT(Filtrado_y_ponderacion_max44_M->rtwLogInfo, "tout");
    rtliSetLogX(Filtrado_y_ponderacion_max44_M->rtwLogInfo, "");
    rtliSetLogXFinal(Filtrado_y_ponderacion_max44_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(Filtrado_y_ponderacion_max44_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(Filtrado_y_ponderacion_max44_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(Filtrado_y_ponderacion_max44_M->rtwLogInfo, 0);
    rtliSetLogDecimation(Filtrado_y_ponderacion_max44_M->rtwLogInfo, 1);
    rtliSetLogY(Filtrado_y_ponderacion_max44_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(Filtrado_y_ponderacion_max44_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(Filtrado_y_ponderacion_max44_M->rtwLogInfo, (NULL));
  }

  /* block I/O */
  (void) memset(((void *) &Filtrado_y_ponderacion_max446_B), 0,
                sizeof(B_Filtrado_y_ponderacion_max4_T));

  /* states (dwork) */
  (void) memset((void *)&Filtrado_y_ponderacion_max44_DW, 0,
                sizeof(DW_Filtrado_y_ponderacion_max_T));

  /* external outputs */
  (void) memset(&Filtrado_y_ponderacion_max446_Y.Output[0], 0,
                1024U*sizeof(real_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(Filtrado_y_ponderacion_max44_M->rtwLogInfo,
    0.0, rtmGetTFinal(Filtrado_y_ponderacion_max44_M),
    Filtrado_y_ponderacion_max44_M->Timing.stepSize0, (&rtmGetErrorStatus
    (Filtrado_y_ponderacion_max44_M)));

  {
    char_T *sErr;

    /* Start for S-Function (saudioFromAudioDevice): '<Root>/Audio Device Reader' */
    sErr = GetErrorBuffer
      (&Filtrado_y_ponderacion_max44_DW.AudioDeviceReader_AudioDeviceLi[0UL]);
    CreateHostLibrary("hostlibaudio.dll",
                      &Filtrado_y_ponderacion_max44_DW.AudioDeviceReader_AudioDeviceLi
                      [0UL]);
    if (*sErr == 0) {
      LibCreate_Audio
        (&Filtrado_y_ponderacion_max44_DW.AudioDeviceReader_AudioDeviceLi[0UL],
         0L, "Default", 1L, 0L, 1L, 44100.0, 3L, 1024L, 10240L, 1024L, 5L, NULL);
    }

    if (*sErr != 0) {
      DestroyHostLibrary
        (&Filtrado_y_ponderacion_max44_DW.AudioDeviceReader_AudioDeviceLi[0UL]);
      if (*sErr != 0) {
        rtmSetErrorStatus(Filtrado_y_ponderacion_max44_M, sErr);
        rtmSetStopRequested(Filtrado_y_ponderacion_max44_M, 1);
      }
    }

    /* End of Start for S-Function (saudioFromAudioDevice): '<Root>/Audio Device Reader' */
  }

  {
    int16_T i;

    /* InitializeConditions for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' */
    for (i = 0; i < 1024; i++) {
      Filtrado_y_ponderacion_max44_DW.DiscreteTimeIntegrator_DSTATE[i] =
        Filtrado_y_ponderacion_max446_P.DiscreteTimeIntegrator_IC;
    }

    /* End of InitializeConditions for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' */

    /* InitializeConditions for S-Function (sdspbiquad): '<S1>/Generated Filter Block' */
    for (i = 0; i < 6; i++) {
      Filtrado_y_ponderacion_max44_DW.GeneratedFilterBlock_FILT_STATE[i] = 0.0;
    }

    /* End of InitializeConditions for S-Function (sdspbiquad): '<S1>/Generated Filter Block' */
  }
}

/* Model terminate function */
void Filtrado_y_ponderacion_max4466_terminate(void)
{
  char_T *sErr;

  /* Terminate for S-Function (saudioFromAudioDevice): '<Root>/Audio Device Reader' */
  sErr = GetErrorBuffer
    (&Filtrado_y_ponderacion_max44_DW.AudioDeviceReader_AudioDeviceLi[0UL]);
  LibTerminate(&Filtrado_y_ponderacion_max44_DW.AudioDeviceReader_AudioDeviceLi
               [0UL]);
  if (*sErr != 0) {
    rtmSetErrorStatus(Filtrado_y_ponderacion_max44_M, sErr);
    rtmSetStopRequested(Filtrado_y_ponderacion_max44_M, 1);
  }

  LibDestroy_Audio
    (&Filtrado_y_ponderacion_max44_DW.AudioDeviceReader_AudioDeviceLi[0UL], 0L,
     1L);
  DestroyHostLibrary
    (&Filtrado_y_ponderacion_max44_DW.AudioDeviceReader_AudioDeviceLi[0UL]);

  /* End of Terminate for S-Function (saudioFromAudioDevice): '<Root>/Audio Device Reader' */
}
