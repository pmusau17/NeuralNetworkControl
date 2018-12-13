/*
 * neural_controller.h
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

#ifndef RTW_HEADER_neural_controller_h_
#define RTW_HEADER_neural_controller_h_
#include <stddef.h>
#include <math.h>
#include <string.h>
#ifndef neural_controller_COMMON_INCLUDES_
# define neural_controller_COMMON_INCLUDES_
#include <stdio.h>
#include <string.h>
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "dt_info.h"
#include "ext_work.h"
#include "hil.h"
#include "quanser_messages.h"
#include "quanser_extern.h"
#endif                                 /* neural_controller_COMMON_INCLUDES_ */

#include "neural_controller_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlkStateChangeFlag
# define rtmGetBlkStateChangeFlag(rtm) ((rtm)->blkStateChange)
#endif

#ifndef rtmSetBlkStateChangeFlag
# define rtmSetBlkStateChangeFlag(rtm, val) ((rtm)->blkStateChange = (val))
#endif

#ifndef rtmGetBlockIO
# define rtmGetBlockIO(rtm)            ((rtm)->blockIO)
#endif

#ifndef rtmSetBlockIO
# define rtmSetBlockIO(rtm, val)       ((rtm)->blockIO = (val))
#endif

#ifndef rtmGetChecksums
# define rtmGetChecksums(rtm)          ((rtm)->Sizes.checksums)
#endif

#ifndef rtmSetChecksums
# define rtmSetChecksums(rtm, val)     ((rtm)->Sizes.checksums = (val))
#endif

#ifndef rtmGetConstBlockIO
# define rtmGetConstBlockIO(rtm)       ((rtm)->constBlockIO)
#endif

#ifndef rtmSetConstBlockIO
# define rtmSetConstBlockIO(rtm, val)  ((rtm)->constBlockIO = (val))
#endif

#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->contStates = (val))
#endif

#ifndef rtmGetDataMapInfo
# define rtmGetDataMapInfo(rtm)        ()
#endif

#ifndef rtmSetDataMapInfo
# define rtmSetDataMapInfo(rtm, val)   ()
#endif

#ifndef rtmGetDefaultParam
# define rtmGetDefaultParam(rtm)       ((rtm)->defaultParam)
#endif

#ifndef rtmSetDefaultParam
# define rtmSetDefaultParam(rtm, val)  ((rtm)->defaultParam = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetDirectFeedThrough
# define rtmGetDirectFeedThrough(rtm)  ((rtm)->Sizes.sysDirFeedThru)
#endif

#ifndef rtmSetDirectFeedThrough
# define rtmSetDirectFeedThrough(rtm, val) ((rtm)->Sizes.sysDirFeedThru = (val))
#endif

#ifndef rtmGetErrorStatusFlag
# define rtmGetErrorStatusFlag(rtm)    ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatusFlag
# define rtmSetErrorStatusFlag(rtm, val) ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetFinalTime
# define rtmSetFinalTime(rtm, val)     ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetFirstInitCondFlag
# define rtmGetFirstInitCondFlag(rtm)  ()
#endif

#ifndef rtmSetFirstInitCondFlag
# define rtmSetFirstInitCondFlag(rtm, val) ()
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ()
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ()
#endif

#ifndef rtmGetMdlRefGlobalTID
# define rtmGetMdlRefGlobalTID(rtm)    ()
#endif

#ifndef rtmSetMdlRefGlobalTID
# define rtmSetMdlRefGlobalTID(rtm, val) ()
#endif

#ifndef rtmGetMdlRefTriggerTID
# define rtmGetMdlRefTriggerTID(rtm)   ()
#endif

#ifndef rtmSetMdlRefTriggerTID
# define rtmSetMdlRefTriggerTID(rtm, val) ()
#endif

#ifndef rtmGetModelMappingInfo
# define rtmGetModelMappingInfo(rtm)   ((rtm)->SpecialInfo.mappingInfo)
#endif

#ifndef rtmSetModelMappingInfo
# define rtmSetModelMappingInfo(rtm, val) ((rtm)->SpecialInfo.mappingInfo = (val))
#endif

#ifndef rtmGetModelName
# define rtmGetModelName(rtm)          ((rtm)->modelName)
#endif

#ifndef rtmSetModelName
# define rtmSetModelName(rtm, val)     ((rtm)->modelName = (val))
#endif

#ifndef rtmGetNonInlinedSFcns
# define rtmGetNonInlinedSFcns(rtm)    ()
#endif

#ifndef rtmSetNonInlinedSFcns
# define rtmSetNonInlinedSFcns(rtm, val) ()
#endif

#ifndef rtmGetNumBlockIO
# define rtmGetNumBlockIO(rtm)         ((rtm)->Sizes.numBlockIO)
#endif

#ifndef rtmSetNumBlockIO
# define rtmSetNumBlockIO(rtm, val)    ((rtm)->Sizes.numBlockIO = (val))
#endif

#ifndef rtmGetNumBlockParams
# define rtmGetNumBlockParams(rtm)     ((rtm)->Sizes.numBlockPrms)
#endif

#ifndef rtmSetNumBlockParams
# define rtmSetNumBlockParams(rtm, val) ((rtm)->Sizes.numBlockPrms = (val))
#endif

#ifndef rtmGetNumBlocks
# define rtmGetNumBlocks(rtm)          ((rtm)->Sizes.numBlocks)
#endif

#ifndef rtmSetNumBlocks
# define rtmSetNumBlocks(rtm, val)     ((rtm)->Sizes.numBlocks = (val))
#endif

#ifndef rtmGetNumContStates
# define rtmGetNumContStates(rtm)      ((rtm)->Sizes.numContStates)
#endif

#ifndef rtmSetNumContStates
# define rtmSetNumContStates(rtm, val) ((rtm)->Sizes.numContStates = (val))
#endif

#ifndef rtmGetNumDWork
# define rtmGetNumDWork(rtm)           ((rtm)->Sizes.numDwork)
#endif

#ifndef rtmSetNumDWork
# define rtmSetNumDWork(rtm, val)      ((rtm)->Sizes.numDwork = (val))
#endif

#ifndef rtmGetNumInputPorts
# define rtmGetNumInputPorts(rtm)      ((rtm)->Sizes.numIports)
#endif

#ifndef rtmSetNumInputPorts
# define rtmSetNumInputPorts(rtm, val) ((rtm)->Sizes.numIports = (val))
#endif

#ifndef rtmGetNumNonSampledZCs
# define rtmGetNumNonSampledZCs(rtm)   ((rtm)->Sizes.numNonSampZCs)
#endif

#ifndef rtmSetNumNonSampledZCs
# define rtmSetNumNonSampledZCs(rtm, val) ((rtm)->Sizes.numNonSampZCs = (val))
#endif

#ifndef rtmGetNumOutputPorts
# define rtmGetNumOutputPorts(rtm)     ((rtm)->Sizes.numOports)
#endif

#ifndef rtmSetNumOutputPorts
# define rtmSetNumOutputPorts(rtm, val) ((rtm)->Sizes.numOports = (val))
#endif

#ifndef rtmGetNumPeriodicContStates
# define rtmGetNumPeriodicContStates(rtm) ((rtm)->Sizes.numPeriodicContStates)
#endif

#ifndef rtmSetNumPeriodicContStates
# define rtmSetNumPeriodicContStates(rtm, val) ((rtm)->Sizes.numPeriodicContStates = (val))
#endif

#ifndef rtmGetNumSFcnParams
# define rtmGetNumSFcnParams(rtm)      ((rtm)->Sizes.numSFcnPrms)
#endif

#ifndef rtmSetNumSFcnParams
# define rtmSetNumSFcnParams(rtm, val) ((rtm)->Sizes.numSFcnPrms = (val))
#endif

#ifndef rtmGetNumSFunctions
# define rtmGetNumSFunctions(rtm)      ((rtm)->Sizes.numSFcns)
#endif

#ifndef rtmSetNumSFunctions
# define rtmSetNumSFunctions(rtm, val) ((rtm)->Sizes.numSFcns = (val))
#endif

#ifndef rtmGetNumSampleTimes
# define rtmGetNumSampleTimes(rtm)     ((rtm)->Sizes.numSampTimes)
#endif

#ifndef rtmSetNumSampleTimes
# define rtmSetNumSampleTimes(rtm, val) ((rtm)->Sizes.numSampTimes = (val))
#endif

#ifndef rtmGetNumU
# define rtmGetNumU(rtm)               ((rtm)->Sizes.numU)
#endif

#ifndef rtmSetNumU
# define rtmSetNumU(rtm, val)          ((rtm)->Sizes.numU = (val))
#endif

#ifndef rtmGetNumY
# define rtmGetNumY(rtm)               ((rtm)->Sizes.numY)
#endif

#ifndef rtmSetNumY
# define rtmSetNumY(rtm, val)          ((rtm)->Sizes.numY = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ()
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ()
#endif

#ifndef rtmGetOdeY
# define rtmGetOdeY(rtm)               ()
#endif

#ifndef rtmSetOdeY
# define rtmSetOdeY(rtm, val)          ()
#endif

#ifndef rtmGetOffsetTimeArray
# define rtmGetOffsetTimeArray(rtm)    ((rtm)->Timing.offsetTimesArray)
#endif

#ifndef rtmSetOffsetTimeArray
# define rtmSetOffsetTimeArray(rtm, val) ((rtm)->Timing.offsetTimesArray = (val))
#endif

#ifndef rtmGetOffsetTimePtr
# define rtmGetOffsetTimePtr(rtm)      ((rtm)->Timing.offsetTimes)
#endif

#ifndef rtmSetOffsetTimePtr
# define rtmSetOffsetTimePtr(rtm, val) ((rtm)->Timing.offsetTimes = (val))
#endif

#ifndef rtmGetOptions
# define rtmGetOptions(rtm)            ((rtm)->Sizes.options)
#endif

#ifndef rtmSetOptions
# define rtmSetOptions(rtm, val)       ((rtm)->Sizes.options = (val))
#endif

#ifndef rtmGetParamIsMalloced
# define rtmGetParamIsMalloced(rtm)    ()
#endif

#ifndef rtmSetParamIsMalloced
# define rtmSetParamIsMalloced(rtm, val) ()
#endif

#ifndef rtmGetPath
# define rtmGetPath(rtm)               ((rtm)->path)
#endif

#ifndef rtmSetPath
# define rtmSetPath(rtm, val)          ((rtm)->path = (val))
#endif

#ifndef rtmGetPerTaskSampleHits
# define rtmGetPerTaskSampleHits(rtm)  ()
#endif

#ifndef rtmSetPerTaskSampleHits
# define rtmSetPerTaskSampleHits(rtm, val) ()
#endif

#ifndef rtmGetPerTaskSampleHitsArray
# define rtmGetPerTaskSampleHitsArray(rtm) ((rtm)->Timing.perTaskSampleHitsArray)
#endif

#ifndef rtmSetPerTaskSampleHitsArray
# define rtmSetPerTaskSampleHitsArray(rtm, val) ((rtm)->Timing.perTaskSampleHitsArray = (val))
#endif

#ifndef rtmGetPerTaskSampleHitsPtr
# define rtmGetPerTaskSampleHitsPtr(rtm) ((rtm)->Timing.perTaskSampleHits)
#endif

#ifndef rtmSetPerTaskSampleHitsPtr
# define rtmSetPerTaskSampleHitsPtr(rtm, val) ((rtm)->Timing.perTaskSampleHits = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
# define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
# define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
# define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
# define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetPrevZCSigState
# define rtmGetPrevZCSigState(rtm)     ((rtm)->prevZCSigState)
#endif

#ifndef rtmSetPrevZCSigState
# define rtmSetPrevZCSigState(rtm, val) ((rtm)->prevZCSigState = (val))
#endif

#ifndef rtmGetRTWExtModeInfo
# define rtmGetRTWExtModeInfo(rtm)     ((rtm)->extModeInfo)
#endif

#ifndef rtmSetRTWExtModeInfo
# define rtmSetRTWExtModeInfo(rtm, val) ((rtm)->extModeInfo = (val))
#endif

#ifndef rtmGetRTWGeneratedSFcn
# define rtmGetRTWGeneratedSFcn(rtm)   ((rtm)->Sizes.rtwGenSfcn)
#endif

#ifndef rtmSetRTWGeneratedSFcn
# define rtmSetRTWGeneratedSFcn(rtm, val) ((rtm)->Sizes.rtwGenSfcn = (val))
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ()
#endif

#ifndef rtmSetRTWLogInfo
# define rtmSetRTWLogInfo(rtm, val)    ()
#endif

#ifndef rtmGetRTWRTModelMethodsInfo
# define rtmGetRTWRTModelMethodsInfo(rtm) ()
#endif

#ifndef rtmSetRTWRTModelMethodsInfo
# define rtmSetRTWRTModelMethodsInfo(rtm, val) ()
#endif

#ifndef rtmGetRTWSfcnInfo
# define rtmGetRTWSfcnInfo(rtm)        ((rtm)->sfcnInfo)
#endif

#ifndef rtmSetRTWSfcnInfo
# define rtmSetRTWSfcnInfo(rtm, val)   ((rtm)->sfcnInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfo
# define rtmGetRTWSolverInfo(rtm)      ((rtm)->solverInfo)
#endif

#ifndef rtmSetRTWSolverInfo
# define rtmSetRTWSolverInfo(rtm, val) ((rtm)->solverInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfoPtr
# define rtmGetRTWSolverInfoPtr(rtm)   ((rtm)->solverInfoPtr)
#endif

#ifndef rtmSetRTWSolverInfoPtr
# define rtmSetRTWSolverInfoPtr(rtm, val) ((rtm)->solverInfoPtr = (val))
#endif

#ifndef rtmGetReservedForXPC
# define rtmGetReservedForXPC(rtm)     ((rtm)->SpecialInfo.xpcData)
#endif

#ifndef rtmSetReservedForXPC
# define rtmSetReservedForXPC(rtm, val) ((rtm)->SpecialInfo.xpcData = (val))
#endif

#ifndef rtmGetRootDWork
# define rtmGetRootDWork(rtm)          ((rtm)->dwork)
#endif

#ifndef rtmSetRootDWork
# define rtmSetRootDWork(rtm, val)     ((rtm)->dwork = (val))
#endif

#ifndef rtmGetSFunctions
# define rtmGetSFunctions(rtm)         ((rtm)->childSfunctions)
#endif

#ifndef rtmSetSFunctions
# define rtmSetSFunctions(rtm, val)    ((rtm)->childSfunctions = (val))
#endif

#ifndef rtmGetSampleHitArray
# define rtmGetSampleHitArray(rtm)     ((rtm)->Timing.sampleHitArray)
#endif

#ifndef rtmSetSampleHitArray
# define rtmSetSampleHitArray(rtm, val) ((rtm)->Timing.sampleHitArray = (val))
#endif

#ifndef rtmGetSampleHitPtr
# define rtmGetSampleHitPtr(rtm)       ((rtm)->Timing.sampleHits)
#endif

#ifndef rtmSetSampleHitPtr
# define rtmSetSampleHitPtr(rtm, val)  ((rtm)->Timing.sampleHits = (val))
#endif

#ifndef rtmGetSampleTimeArray
# define rtmGetSampleTimeArray(rtm)    ((rtm)->Timing.sampleTimesArray)
#endif

#ifndef rtmSetSampleTimeArray
# define rtmSetSampleTimeArray(rtm, val) ((rtm)->Timing.sampleTimesArray = (val))
#endif

#ifndef rtmGetSampleTimePtr
# define rtmGetSampleTimePtr(rtm)      ((rtm)->Timing.sampleTimes)
#endif

#ifndef rtmSetSampleTimePtr
# define rtmSetSampleTimePtr(rtm, val) ((rtm)->Timing.sampleTimes = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDArray
# define rtmGetSampleTimeTaskIDArray(rtm) ((rtm)->Timing.sampleTimeTaskIDArray)
#endif

#ifndef rtmSetSampleTimeTaskIDArray
# define rtmSetSampleTimeTaskIDArray(rtm, val) ((rtm)->Timing.sampleTimeTaskIDArray = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDPtr
# define rtmGetSampleTimeTaskIDPtr(rtm) ((rtm)->Timing.sampleTimeTaskIDPtr)
#endif

#ifndef rtmSetSampleTimeTaskIDPtr
# define rtmSetSampleTimeTaskIDPtr(rtm, val) ((rtm)->Timing.sampleTimeTaskIDPtr = (val))
#endif

#ifndef rtmGetSelf
# define rtmGetSelf(rtm)               ()
#endif

#ifndef rtmSetSelf
# define rtmSetSelf(rtm, val)          ()
#endif

#ifndef rtmGetSimMode
# define rtmGetSimMode(rtm)            ((rtm)->simMode)
#endif

#ifndef rtmSetSimMode
# define rtmSetSimMode(rtm, val)       ((rtm)->simMode = (val))
#endif

#ifndef rtmGetSimTimeStep
# define rtmGetSimTimeStep(rtm)        ((rtm)->Timing.simTimeStep)
#endif

#ifndef rtmSetSimTimeStep
# define rtmSetSimTimeStep(rtm, val)   ((rtm)->Timing.simTimeStep = (val))
#endif

#ifndef rtmGetStartTime
# define rtmGetStartTime(rtm)          ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetStartTime
# define rtmSetStartTime(rtm, val)     ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetStepSize
# define rtmGetStepSize(rtm)           ((rtm)->Timing.stepSize)
#endif

#ifndef rtmSetStepSize
# define rtmSetStepSize(rtm, val)      ((rtm)->Timing.stepSize = (val))
#endif

#ifndef rtmGetStopRequestedFlag
# define rtmGetStopRequestedFlag(rtm)  ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequestedFlag
# define rtmSetStopRequestedFlag(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetTaskCounters
# define rtmGetTaskCounters(rtm)       ()
#endif

#ifndef rtmSetTaskCounters
# define rtmSetTaskCounters(rtm, val)  ()
#endif

#ifndef rtmGetTaskTimeArray
# define rtmGetTaskTimeArray(rtm)      ((rtm)->Timing.tArray)
#endif

#ifndef rtmSetTaskTimeArray
# define rtmSetTaskTimeArray(rtm, val) ((rtm)->Timing.tArray = (val))
#endif

#ifndef rtmGetTimePtr
# define rtmGetTimePtr(rtm)            ((rtm)->Timing.t)
#endif

#ifndef rtmSetTimePtr
# define rtmSetTimePtr(rtm, val)       ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTimingData
# define rtmGetTimingData(rtm)         ((rtm)->Timing.timingData)
#endif

#ifndef rtmSetTimingData
# define rtmSetTimingData(rtm, val)    ((rtm)->Timing.timingData = (val))
#endif

#ifndef rtmGetU
# define rtmGetU(rtm)                  ((rtm)->inputs)
#endif

#ifndef rtmSetU
# define rtmSetU(rtm, val)             ((rtm)->inputs = (val))
#endif

#ifndef rtmGetVarNextHitTimesListPtr
# define rtmGetVarNextHitTimesListPtr(rtm) ((rtm)->Timing.varNextHitTimesList)
#endif

#ifndef rtmSetVarNextHitTimesListPtr
# define rtmSetVarNextHitTimesListPtr(rtm, val) ((rtm)->Timing.varNextHitTimesList = (val))
#endif

#ifndef rtmGetY
# define rtmGetY(rtm)                  ((rtm)->outputs)
#endif

#ifndef rtmSetY
# define rtmSetY(rtm, val)             ((rtm)->outputs = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetZCSignalValues
# define rtmGetZCSignalValues(rtm)     ((rtm)->zcSignalValues)
#endif

#ifndef rtmSetZCSignalValues
# define rtmSetZCSignalValues(rtm, val) ((rtm)->zcSignalValues = (val))
#endif

#ifndef rtmGet_TimeOfLastOutput
# define rtmGet_TimeOfLastOutput(rtm)  ((rtm)->Timing.timeOfLastOutput)
#endif

#ifndef rtmSet_TimeOfLastOutput
# define rtmSet_TimeOfLastOutput(rtm, val) ((rtm)->Timing.timeOfLastOutput = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->derivs = (val))
#endif

#ifndef rtmGetChecksumVal
# define rtmGetChecksumVal(rtm, idx)   ((rtm)->Sizes.checksums[idx])
#endif

#ifndef rtmSetChecksumVal
# define rtmSetChecksumVal(rtm, idx, val) ((rtm)->Sizes.checksums[idx] = (val))
#endif

#ifndef rtmGetDWork
# define rtmGetDWork(rtm, idx)         ((rtm)->dwork[idx])
#endif

#ifndef rtmSetDWork
# define rtmSetDWork(rtm, idx, val)    ((rtm)->dwork[idx] = (val))
#endif

#ifndef rtmGetOffsetTime
# define rtmGetOffsetTime(rtm, idx)    ((rtm)->Timing.offsetTimes[idx])
#endif

#ifndef rtmSetOffsetTime
# define rtmSetOffsetTime(rtm, idx, val) ((rtm)->Timing.offsetTimes[idx] = (val))
#endif

#ifndef rtmGetSFunction
# define rtmGetSFunction(rtm, idx)     ((rtm)->childSfunctions[idx])
#endif

#ifndef rtmSetSFunction
# define rtmSetSFunction(rtm, idx, val) ((rtm)->childSfunctions[idx] = (val))
#endif

#ifndef rtmGetSampleTime
# define rtmGetSampleTime(rtm, idx)    ((rtm)->Timing.sampleTimes[idx])
#endif

#ifndef rtmSetSampleTime
# define rtmSetSampleTime(rtm, idx, val) ((rtm)->Timing.sampleTimes[idx] = (val))
#endif

#ifndef rtmGetSampleTimeTaskID
# define rtmGetSampleTimeTaskID(rtm, idx) ((rtm)->Timing.sampleTimeTaskIDPtr[idx])
#endif

#ifndef rtmSetSampleTimeTaskID
# define rtmSetSampleTimeTaskID(rtm, idx, val) ((rtm)->Timing.sampleTimeTaskIDPtr[idx] = (val))
#endif

#ifndef rtmGetVarNextHitTimeList
# define rtmGetVarNextHitTimeList(rtm, idx) ((rtm)->Timing.varNextHitTimesList[idx])
#endif

#ifndef rtmSetVarNextHitTimeList
# define rtmSetVarNextHitTimeList(rtm, idx, val) ((rtm)->Timing.varNextHitTimesList[idx] = (val))
#endif

#ifndef rtmIsContinuousTask
# define rtmIsContinuousTask(rtm, tid) ((tid) == 0)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmIsMajorTimeStep
# define rtmIsMajorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
# define rtmIsMinorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmIsSampleHit
# define rtmIsSampleHit(rtm, sti, tid) ((rtmIsMajorTimeStep((rtm)) && (rtm)->Timing.sampleHits[(rtm)->Timing.sampleTimeTaskIDPtr[sti]]))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmSetT
# define rtmSetT(rtm, val)                                       /* Do Nothing */
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

#ifndef rtmSetTPtr
# define rtmSetTPtr(rtm, val)          ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTStart
# define rtmGetTStart(rtm)             ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetTStart
# define rtmSetTStart(rtm, val)        ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetTaskTime
# define rtmGetTaskTime(rtm, sti)      (rtmGetTPtr((rtm))[(rtm)->Timing.sampleTimeTaskIDPtr[sti]])
#endif

#ifndef rtmSetTaskTime
# define rtmSetTaskTime(rtm, sti, val) (rtmGetTPtr((rtm))[sti] = (val))
#endif

#ifndef rtmGetTimeOfLastOutput
# define rtmGetTimeOfLastOutput(rtm)   ((rtm)->Timing.timeOfLastOutput)
#endif

#ifdef rtmGetRTWSolverInfo
#undef rtmGetRTWSolverInfo
#endif

#define rtmGetRTWSolverInfo(rtm)       &((rtm)->solverInfo)

/* Definition for use in the target main file */
#define neural_controller_rtModel      RT_MODEL_neural_controller_T

/* Block signals (auto storage) */
typedef struct {
  real_T SineWave;                     /* '<Root>/Sine Wave' */
  real_T Addminx;                      /* '<S25>/Add min x' */
  real_T Add1;                         /* '<Root>/Add1' */
  real_T Subtract2;                    /* '<Root>/Subtract2' */
  real_T Product;                      /* '<Root>/Product' */
} B_neural_controller_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T HILInitialize_AIMinimums[8];  /* '<Root>/HIL Initialize' */
  real_T HILInitialize_AIMaximums[8];  /* '<Root>/HIL Initialize' */
  real_T HILInitialize_AOMinimums[8];  /* '<Root>/HIL Initialize' */
  real_T HILInitialize_AOMaximums[8];  /* '<Root>/HIL Initialize' */
  real_T HILInitialize_AOVoltages[8];  /* '<Root>/HIL Initialize' */
  real_T HILInitialize_FilterFrequency[8];/* '<Root>/HIL Initialize' */
  t_card HILInitialize_Card;           /* '<Root>/HIL Initialize' */
  void *HILWriteAnalog_PWORK;          /* '<Root>/HIL Write Analog' */
  void *HILWriteAnalog1_PWORK;         /* '<Root>/HIL Write Analog1' */
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */

  void *HILReadEncoder1_PWORK;         /* '<Root>/HIL Read Encoder1' */
  struct {
    void *LoggedData[2];
  } Scope2_PWORK;                      /* '<Root>/Scope2' */

  struct {
    void *LoggedData;
  } Scope5_PWORK;                      /* '<Root>/Scope5' */

  struct {
    void *LoggedData;
  } Scope6_PWORK;                      /* '<Root>/Scope6' */

  struct {
    void *FilePtr;
  } ToFile_PWORK;                      /* '<Root>/To File' */

  struct {
    void *FilePtr;
  } ToFile1_PWORK;                     /* '<Root>/To File1' */

  int32_T HILInitialize_QuadratureModes[8];/* '<Root>/HIL Initialize' */
  int32_T HILInitialize_InitialEICounts[8];/* '<Root>/HIL Initialize' */
  int32_T HILReadEncoder1_Buffer;      /* '<Root>/HIL Read Encoder1' */
  struct {
    int_T Count;
    int_T Decimation;
  } ToFile_IWORK;                      /* '<Root>/To File' */

  struct {
    int_T Count;
    int_T Decimation;
  } ToFile1_IWORK;                     /* '<Root>/To File1' */
} DW_neural_controller_T;

/* Backward compatible GRT Identifiers */
#define rtB                            neural_controller_B
#define BlockIO                        B_neural_controller_T
#define rtP                            neural_controller_P
#define Parameters                     P_neural_controller_T
#define rtDWork                        neural_controller_DW
#define D_Work                         DW_neural_controller_T

/* Parameters (auto storage) */
struct P_neural_controller_T_ {
  real_T mapminmax_reverse_xmax;       /* Mask Parameter: mapminmax_reverse_xmax
                                        * Referenced by: '<S25>/Divide by range y'
                                        */
  real_T mapminmax_reverse_xmin;       /* Mask Parameter: mapminmax_reverse_xmin
                                        * Referenced by:
                                        *   '<S25>/Add min x'
                                        *   '<S25>/Divide by range y'
                                        */
  real_T mapminmax_reverse_ymax;       /* Mask Parameter: mapminmax_reverse_ymax
                                        * Referenced by: '<S25>/Divide by range y'
                                        */
  real_T mapminmax_reverse_ymin;       /* Mask Parameter: mapminmax_reverse_ymin
                                        * Referenced by:
                                        *   '<S25>/Subtract min y'
                                        *   '<S25>/Divide by range y'
                                        */
  uint32_T HILWriteAnalog_channels;    /* Mask Parameter: HILWriteAnalog_channels
                                        * Referenced by: '<Root>/HIL Write Analog'
                                        */
  uint32_T HILWriteAnalog1_channels;   /* Mask Parameter: HILWriteAnalog1_channels
                                        * Referenced by: '<Root>/HIL Write Analog1'
                                        */
  uint32_T HILReadEncoder1_channels;   /* Mask Parameter: HILReadEncoder1_channels
                                        * Referenced by: '<Root>/HIL Read Encoder1'
                                        */
  real_T HILInitialize_OOTerminate;    /* Expression: set_other_outputs_at_terminate
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  real_T HILInitialize_OOExit;         /* Expression: set_other_outputs_at_switch_out
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  real_T HILInitialize_OOStart;        /* Expression: set_other_outputs_at_start
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  real_T HILInitialize_OOEnter;        /* Expression: set_other_outputs_at_switch_in
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  real_T HILInitialize_AOFinal;        /* Expression: final_analog_outputs
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  real_T HILInitialize_POFinal;        /* Expression: final_pwm_outputs
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  real_T HILInitialize_AIHigh;         /* Expression: analog_input_maximums
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  real_T HILInitialize_AILow;          /* Expression: analog_input_minimums
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  real_T HILInitialize_AOHigh;         /* Expression: analog_output_maximums
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  real_T HILInitialize_AOLow;          /* Expression: analog_output_minimums
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  real_T HILInitialize_AOInitial;      /* Expression: initial_analog_outputs
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  real_T HILInitialize_AOWatchdog;     /* Expression: watchdog_analog_outputs
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  real_T HILInitialize_EIFrequency;    /* Expression: encoder_filter_frequency
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  real_T HILInitialize_POFrequency;    /* Expression: pwm_frequency
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  real_T HILInitialize_POInitial;      /* Expression: initial_pwm_outputs
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  real_T Constant4_Value;              /* Expression: 1.5
                                        * Referenced by: '<Root>/Constant4'
                                        */
  real_T IW321_Value[2];               /* Expression: [-0.1656368717531822;-0.26069324361374069]
                                        * Referenced by: '<S22>/IW{3,2}(1,:)''
                                        */
  real_T IW211_Value[2];               /* Expression: [0.035722440084135824;0.16023921638585181]
                                        * Referenced by: '<S17>/IW{2,1}(1,:)''
                                        */
  real_T IW111_Value;                  /* Expression: -0.066069138817719336
                                        * Referenced by: '<S12>/IW{1,1}(1,:)''
                                        */
  real_T SineWave_Amp;                 /* Expression: 45
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_Bias;                /* Expression: 0
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_Freq;                /* Expression: 1
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_Phase;               /* Expression: 0
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T IW112_Value;                  /* Expression: -0.29892671944931076
                                        * Referenced by: '<S12>/IW{1,1}(2,:)''
                                        */
  real_T b1_Value[2];                  /* Expression: [0.0024713083182635888;0.011181318563108802]
                                        * Referenced by: '<S6>/b{1}'
                                        */
  real_T IW212_Value[2];               /* Expression: [0.056265851093742728;0.25239025828449979]
                                        * Referenced by: '<S17>/IW{2,1}(2,:)''
                                        */
  real_T b2_Value[2];                  /* Expression: [0.020023066256757222;0.031538015339021494]
                                        * Referenced by: '<S7>/b{2}'
                                        */
  real_T b3_Value;                     /* Expression: -0.12108973633588316
                                        * Referenced by: '<S8>/b{3}'
                                        */
  real_T Constant2_Value;              /* Expression: 90
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T Constant1_Value;              /* Expression: 2048
                                        * Referenced by: '<Root>/Constant1'
                                        */
  int32_T HILInitialize_CKChannels[2]; /* Computed Parameter: HILInitialize_CKChannels
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  int32_T HILInitialize_CKModes[2];    /* Computed Parameter: HILInitialize_CKModes
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  int32_T HILInitialize_DOWatchdog;    /* Computed Parameter: HILInitialize_DOWatchdog
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  int32_T HILInitialize_EIInitial;     /* Computed Parameter: HILInitialize_EIInitial
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  int32_T HILInitialize_POModes;       /* Computed Parameter: HILInitialize_POModes
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  uint32_T HILInitialize_AIChannels[8];/* Computed Parameter: HILInitialize_AIChannels
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  uint32_T HILInitialize_AOChannels[8];/* Computed Parameter: HILInitialize_AOChannels
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  uint32_T HILInitialize_EIChannels[8];/* Computed Parameter: HILInitialize_EIChannels
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  uint32_T HILInitialize_EIQuadrature; /* Computed Parameter: HILInitialize_EIQuadrature
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  boolean_T HILInitialize_Active;      /* Computed Parameter: HILInitialize_Active
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  boolean_T HILInitialize_AOTerminate; /* Computed Parameter: HILInitialize_AOTerminate
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  boolean_T HILInitialize_AOExit;      /* Computed Parameter: HILInitialize_AOExit
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  boolean_T HILInitialize_DOTerminate; /* Computed Parameter: HILInitialize_DOTerminate
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  boolean_T HILInitialize_DOExit;      /* Computed Parameter: HILInitialize_DOExit
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  boolean_T HILInitialize_POTerminate; /* Computed Parameter: HILInitialize_POTerminate
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  boolean_T HILInitialize_POExit;      /* Computed Parameter: HILInitialize_POExit
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  boolean_T HILInitialize_CKPStart;    /* Computed Parameter: HILInitialize_CKPStart
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  boolean_T HILInitialize_CKPEnter;    /* Computed Parameter: HILInitialize_CKPEnter
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  boolean_T HILInitialize_CKStart;     /* Computed Parameter: HILInitialize_CKStart
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  boolean_T HILInitialize_CKEnter;     /* Computed Parameter: HILInitialize_CKEnter
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  boolean_T HILInitialize_AIPStart;    /* Computed Parameter: HILInitialize_AIPStart
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  boolean_T HILInitialize_AIPEnter;    /* Computed Parameter: HILInitialize_AIPEnter
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  boolean_T HILInitialize_AOPStart;    /* Computed Parameter: HILInitialize_AOPStart
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  boolean_T HILInitialize_AOPEnter;    /* Computed Parameter: HILInitialize_AOPEnter
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  boolean_T HILInitialize_AOStart;     /* Computed Parameter: HILInitialize_AOStart
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  boolean_T HILInitialize_AOEnter;     /* Computed Parameter: HILInitialize_AOEnter
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  boolean_T HILInitialize_AOReset;     /* Computed Parameter: HILInitialize_AOReset
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  boolean_T HILInitialize_DOPStart;    /* Computed Parameter: HILInitialize_DOPStart
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  boolean_T HILInitialize_DOPEnter;    /* Computed Parameter: HILInitialize_DOPEnter
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  boolean_T HILInitialize_DOStart;     /* Computed Parameter: HILInitialize_DOStart
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  boolean_T HILInitialize_DOEnter;     /* Computed Parameter: HILInitialize_DOEnter
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  boolean_T HILInitialize_DOReset;     /* Computed Parameter: HILInitialize_DOReset
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  boolean_T HILInitialize_EIPStart;    /* Computed Parameter: HILInitialize_EIPStart
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  boolean_T HILInitialize_EIPEnter;    /* Computed Parameter: HILInitialize_EIPEnter
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  boolean_T HILInitialize_EIStart;     /* Computed Parameter: HILInitialize_EIStart
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  boolean_T HILInitialize_EIEnter;     /* Computed Parameter: HILInitialize_EIEnter
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  boolean_T HILInitialize_POPStart;    /* Computed Parameter: HILInitialize_POPStart
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  boolean_T HILInitialize_POPEnter;    /* Computed Parameter: HILInitialize_POPEnter
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  boolean_T HILInitialize_POStart;     /* Computed Parameter: HILInitialize_POStart
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  boolean_T HILInitialize_POEnter;     /* Computed Parameter: HILInitialize_POEnter
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  boolean_T HILInitialize_POReset;     /* Computed Parameter: HILInitialize_POReset
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  boolean_T HILInitialize_OOReset;     /* Computed Parameter: HILInitialize_OOReset
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  boolean_T HILInitialize_DOFinal;     /* Computed Parameter: HILInitialize_DOFinal
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  boolean_T HILInitialize_DOInitial;   /* Computed Parameter: HILInitialize_DOInitial
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  boolean_T HILWriteAnalog_Active;     /* Computed Parameter: HILWriteAnalog_Active
                                        * Referenced by: '<Root>/HIL Write Analog'
                                        */
  boolean_T HILWriteAnalog1_Active;    /* Computed Parameter: HILWriteAnalog1_Active
                                        * Referenced by: '<Root>/HIL Write Analog1'
                                        */
  boolean_T HILReadEncoder1_Active;    /* Computed Parameter: HILReadEncoder1_Active
                                        * Referenced by: '<Root>/HIL Read Encoder1'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_neural_controller_T {
  const char_T *path;
  const char_T *modelName;
  struct SimStruct_tag * *childSfunctions;
  const char_T *errorStatus;
  SS_SimMode simMode;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  RTWSolverInfo *solverInfoPtr;
  void *sfcnInfo;
  void *blockIO;
  const void *constBlockIO;
  void *defaultParam;
  ZCSigState *prevZCSigState;
  real_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  void *zcSignalValues;
  void *inputs;
  void *outputs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T blkStateChange;
  void *dwork;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    uint32_T options;
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numU;
    int_T numY;
    int_T numSampTimes;
    int_T numBlocks;
    int_T numBlockIO;
    int_T numBlockPrms;
    int_T numDwork;
    int_T numSFcnPrms;
    int_T numSFcns;
    int_T numIports;
    int_T numOports;
    int_T numNonSampZCs;
    int_T sysDirFeedThru;
    int_T rtwGenSfcn;
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
    void *xpcData;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T stepSize;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T stepSize1;
    time_T tStart;
    time_T tFinal;
    time_T timeOfLastOutput;
    void *timingData;
    real_T *varNextHitTimesList;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *sampleTimes;
    time_T *offsetTimes;
    int_T *sampleTimeTaskIDPtr;
    int_T *sampleHits;
    int_T *perTaskSampleHits;
    time_T *t;
    time_T sampleTimesArray[2];
    time_T offsetTimesArray[2];
    int_T sampleTimeTaskIDArray[2];
    int_T sampleHitArray[2];
    int_T perTaskSampleHitsArray[4];
    time_T tArray[2];
  } Timing;
};

/* Block parameters (auto storage) */
extern P_neural_controller_T neural_controller_P;

/* Block signals (auto storage) */
extern B_neural_controller_T neural_controller_B;

/* Block states (auto storage) */
extern DW_neural_controller_T neural_controller_DW;

/* Model entry point functions */
extern void neural_controller_initialize(void);
extern void neural_controller_output(void);
extern void neural_controller_update(void);
extern void neural_controller_terminate(void);

/*====================*
 * External functions *
 *====================*/
extern neural_controller_rtModel *neural_controller(void);
extern void MdlInitializeSizes(void);
extern void MdlInitializeSampleTimes(void);
extern void MdlInitialize(void);
extern void MdlStart(void);
extern void MdlOutputs(int_T tid);
extern void MdlUpdate(int_T tid);
extern void MdlTerminate(void);

/* Real-time Model object */
extern RT_MODEL_neural_controller_T *const neural_controller_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'neural_controller'
 * '<S1>'   : 'neural_controller/NN Controller 2 (linear)'
 * '<S2>'   : 'neural_controller/NN Controller 2 (relu)'
 * '<S3>'   : 'neural_controller/NN Controller 3 (relu and linear)'
 * '<S4>'   : 'neural_controller/NN controller 3 (tanh)'
 * '<S5>'   : 'neural_controller/Ramp'
 * '<S6>'   : 'neural_controller/NN Controller 2 (linear)/Layer 1'
 * '<S7>'   : 'neural_controller/NN Controller 2 (linear)/Layer 2'
 * '<S8>'   : 'neural_controller/NN Controller 2 (linear)/Layer 3'
 * '<S9>'   : 'neural_controller/NN Controller 2 (linear)/Process Input 1'
 * '<S10>'  : 'neural_controller/NN Controller 2 (linear)/Process Output 1'
 * '<S11>'  : 'neural_controller/NN Controller 2 (linear)/Layer 1/Delays 1'
 * '<S12>'  : 'neural_controller/NN Controller 2 (linear)/Layer 1/IW{1,1}'
 * '<S13>'  : 'neural_controller/NN Controller 2 (linear)/Layer 1/purelin'
 * '<S14>'  : 'neural_controller/NN Controller 2 (linear)/Layer 1/IW{1,1}/dotprod1'
 * '<S15>'  : 'neural_controller/NN Controller 2 (linear)/Layer 1/IW{1,1}/dotprod2'
 * '<S16>'  : 'neural_controller/NN Controller 2 (linear)/Layer 2/Delays 1'
 * '<S17>'  : 'neural_controller/NN Controller 2 (linear)/Layer 2/LW{2,1}'
 * '<S18>'  : 'neural_controller/NN Controller 2 (linear)/Layer 2/purelin'
 * '<S19>'  : 'neural_controller/NN Controller 2 (linear)/Layer 2/LW{2,1}/dotprod1'
 * '<S20>'  : 'neural_controller/NN Controller 2 (linear)/Layer 2/LW{2,1}/dotprod2'
 * '<S21>'  : 'neural_controller/NN Controller 2 (linear)/Layer 3/Delays 1'
 * '<S22>'  : 'neural_controller/NN Controller 2 (linear)/Layer 3/LW{3,2}'
 * '<S23>'  : 'neural_controller/NN Controller 2 (linear)/Layer 3/purelin'
 * '<S24>'  : 'neural_controller/NN Controller 2 (linear)/Layer 3/LW{3,2}/dotprod1'
 * '<S25>'  : 'neural_controller/NN Controller 2 (linear)/Process Output 1/mapminmax_reverse'
 * '<S26>'  : 'neural_controller/NN Controller 2 (relu)/Layer 1'
 * '<S27>'  : 'neural_controller/NN Controller 2 (relu)/Layer 2'
 * '<S28>'  : 'neural_controller/NN Controller 2 (relu)/Layer 3'
 * '<S29>'  : 'neural_controller/NN Controller 2 (relu)/Process Input 1'
 * '<S30>'  : 'neural_controller/NN Controller 2 (relu)/Process Output 1'
 * '<S31>'  : 'neural_controller/NN Controller 2 (relu)/Layer 1/Delays 1'
 * '<S32>'  : 'neural_controller/NN Controller 2 (relu)/Layer 1/IW{1,1}'
 * '<S33>'  : 'neural_controller/NN Controller 2 (relu)/Layer 1/poslin'
 * '<S34>'  : 'neural_controller/NN Controller 2 (relu)/Layer 1/IW{1,1}/dotprod1'
 * '<S35>'  : 'neural_controller/NN Controller 2 (relu)/Layer 1/IW{1,1}/dotprod10'
 * '<S36>'  : 'neural_controller/NN Controller 2 (relu)/Layer 1/IW{1,1}/dotprod11'
 * '<S37>'  : 'neural_controller/NN Controller 2 (relu)/Layer 1/IW{1,1}/dotprod12'
 * '<S38>'  : 'neural_controller/NN Controller 2 (relu)/Layer 1/IW{1,1}/dotprod13'
 * '<S39>'  : 'neural_controller/NN Controller 2 (relu)/Layer 1/IW{1,1}/dotprod14'
 * '<S40>'  : 'neural_controller/NN Controller 2 (relu)/Layer 1/IW{1,1}/dotprod15'
 * '<S41>'  : 'neural_controller/NN Controller 2 (relu)/Layer 1/IW{1,1}/dotprod16'
 * '<S42>'  : 'neural_controller/NN Controller 2 (relu)/Layer 1/IW{1,1}/dotprod17'
 * '<S43>'  : 'neural_controller/NN Controller 2 (relu)/Layer 1/IW{1,1}/dotprod18'
 * '<S44>'  : 'neural_controller/NN Controller 2 (relu)/Layer 1/IW{1,1}/dotprod19'
 * '<S45>'  : 'neural_controller/NN Controller 2 (relu)/Layer 1/IW{1,1}/dotprod2'
 * '<S46>'  : 'neural_controller/NN Controller 2 (relu)/Layer 1/IW{1,1}/dotprod20'
 * '<S47>'  : 'neural_controller/NN Controller 2 (relu)/Layer 1/IW{1,1}/dotprod21'
 * '<S48>'  : 'neural_controller/NN Controller 2 (relu)/Layer 1/IW{1,1}/dotprod22'
 * '<S49>'  : 'neural_controller/NN Controller 2 (relu)/Layer 1/IW{1,1}/dotprod23'
 * '<S50>'  : 'neural_controller/NN Controller 2 (relu)/Layer 1/IW{1,1}/dotprod24'
 * '<S51>'  : 'neural_controller/NN Controller 2 (relu)/Layer 1/IW{1,1}/dotprod25'
 * '<S52>'  : 'neural_controller/NN Controller 2 (relu)/Layer 1/IW{1,1}/dotprod3'
 * '<S53>'  : 'neural_controller/NN Controller 2 (relu)/Layer 1/IW{1,1}/dotprod4'
 * '<S54>'  : 'neural_controller/NN Controller 2 (relu)/Layer 1/IW{1,1}/dotprod5'
 * '<S55>'  : 'neural_controller/NN Controller 2 (relu)/Layer 1/IW{1,1}/dotprod6'
 * '<S56>'  : 'neural_controller/NN Controller 2 (relu)/Layer 1/IW{1,1}/dotprod7'
 * '<S57>'  : 'neural_controller/NN Controller 2 (relu)/Layer 1/IW{1,1}/dotprod8'
 * '<S58>'  : 'neural_controller/NN Controller 2 (relu)/Layer 1/IW{1,1}/dotprod9'
 * '<S59>'  : 'neural_controller/NN Controller 2 (relu)/Layer 2/Delays 1'
 * '<S60>'  : 'neural_controller/NN Controller 2 (relu)/Layer 2/LW{2,1}'
 * '<S61>'  : 'neural_controller/NN Controller 2 (relu)/Layer 2/poslin'
 * '<S62>'  : 'neural_controller/NN Controller 2 (relu)/Layer 2/LW{2,1}/dotprod1'
 * '<S63>'  : 'neural_controller/NN Controller 2 (relu)/Layer 2/LW{2,1}/dotprod10'
 * '<S64>'  : 'neural_controller/NN Controller 2 (relu)/Layer 2/LW{2,1}/dotprod11'
 * '<S65>'  : 'neural_controller/NN Controller 2 (relu)/Layer 2/LW{2,1}/dotprod12'
 * '<S66>'  : 'neural_controller/NN Controller 2 (relu)/Layer 2/LW{2,1}/dotprod13'
 * '<S67>'  : 'neural_controller/NN Controller 2 (relu)/Layer 2/LW{2,1}/dotprod14'
 * '<S68>'  : 'neural_controller/NN Controller 2 (relu)/Layer 2/LW{2,1}/dotprod15'
 * '<S69>'  : 'neural_controller/NN Controller 2 (relu)/Layer 2/LW{2,1}/dotprod16'
 * '<S70>'  : 'neural_controller/NN Controller 2 (relu)/Layer 2/LW{2,1}/dotprod17'
 * '<S71>'  : 'neural_controller/NN Controller 2 (relu)/Layer 2/LW{2,1}/dotprod18'
 * '<S72>'  : 'neural_controller/NN Controller 2 (relu)/Layer 2/LW{2,1}/dotprod19'
 * '<S73>'  : 'neural_controller/NN Controller 2 (relu)/Layer 2/LW{2,1}/dotprod2'
 * '<S74>'  : 'neural_controller/NN Controller 2 (relu)/Layer 2/LW{2,1}/dotprod20'
 * '<S75>'  : 'neural_controller/NN Controller 2 (relu)/Layer 2/LW{2,1}/dotprod21'
 * '<S76>'  : 'neural_controller/NN Controller 2 (relu)/Layer 2/LW{2,1}/dotprod22'
 * '<S77>'  : 'neural_controller/NN Controller 2 (relu)/Layer 2/LW{2,1}/dotprod23'
 * '<S78>'  : 'neural_controller/NN Controller 2 (relu)/Layer 2/LW{2,1}/dotprod24'
 * '<S79>'  : 'neural_controller/NN Controller 2 (relu)/Layer 2/LW{2,1}/dotprod25'
 * '<S80>'  : 'neural_controller/NN Controller 2 (relu)/Layer 2/LW{2,1}/dotprod3'
 * '<S81>'  : 'neural_controller/NN Controller 2 (relu)/Layer 2/LW{2,1}/dotprod4'
 * '<S82>'  : 'neural_controller/NN Controller 2 (relu)/Layer 2/LW{2,1}/dotprod5'
 * '<S83>'  : 'neural_controller/NN Controller 2 (relu)/Layer 2/LW{2,1}/dotprod6'
 * '<S84>'  : 'neural_controller/NN Controller 2 (relu)/Layer 2/LW{2,1}/dotprod7'
 * '<S85>'  : 'neural_controller/NN Controller 2 (relu)/Layer 2/LW{2,1}/dotprod8'
 * '<S86>'  : 'neural_controller/NN Controller 2 (relu)/Layer 2/LW{2,1}/dotprod9'
 * '<S87>'  : 'neural_controller/NN Controller 2 (relu)/Layer 3/Delays 1'
 * '<S88>'  : 'neural_controller/NN Controller 2 (relu)/Layer 3/LW{3,2}'
 * '<S89>'  : 'neural_controller/NN Controller 2 (relu)/Layer 3/purelin'
 * '<S90>'  : 'neural_controller/NN Controller 2 (relu)/Layer 3/LW{3,2}/dotprod1'
 * '<S91>'  : 'neural_controller/NN Controller 2 (relu)/Process Output 1/mapminmax_reverse'
 * '<S92>'  : 'neural_controller/NN Controller 3 (relu and linear)/Layer 1'
 * '<S93>'  : 'neural_controller/NN Controller 3 (relu and linear)/Layer 2'
 * '<S94>'  : 'neural_controller/NN Controller 3 (relu and linear)/Layer 3'
 * '<S95>'  : 'neural_controller/NN Controller 3 (relu and linear)/Layer 4'
 * '<S96>'  : 'neural_controller/NN Controller 3 (relu and linear)/Process Input 1'
 * '<S97>'  : 'neural_controller/NN Controller 3 (relu and linear)/Process Output 1'
 * '<S98>'  : 'neural_controller/NN Controller 3 (relu and linear)/Layer 1/Delays 1'
 * '<S99>'  : 'neural_controller/NN Controller 3 (relu and linear)/Layer 1/IW{1,1}'
 * '<S100>' : 'neural_controller/NN Controller 3 (relu and linear)/Layer 1/poslin'
 * '<S101>' : 'neural_controller/NN Controller 3 (relu and linear)/Layer 1/IW{1,1}/dotprod1'
 * '<S102>' : 'neural_controller/NN Controller 3 (relu and linear)/Layer 1/IW{1,1}/dotprod10'
 * '<S103>' : 'neural_controller/NN Controller 3 (relu and linear)/Layer 1/IW{1,1}/dotprod2'
 * '<S104>' : 'neural_controller/NN Controller 3 (relu and linear)/Layer 1/IW{1,1}/dotprod3'
 * '<S105>' : 'neural_controller/NN Controller 3 (relu and linear)/Layer 1/IW{1,1}/dotprod4'
 * '<S106>' : 'neural_controller/NN Controller 3 (relu and linear)/Layer 1/IW{1,1}/dotprod5'
 * '<S107>' : 'neural_controller/NN Controller 3 (relu and linear)/Layer 1/IW{1,1}/dotprod6'
 * '<S108>' : 'neural_controller/NN Controller 3 (relu and linear)/Layer 1/IW{1,1}/dotprod7'
 * '<S109>' : 'neural_controller/NN Controller 3 (relu and linear)/Layer 1/IW{1,1}/dotprod8'
 * '<S110>' : 'neural_controller/NN Controller 3 (relu and linear)/Layer 1/IW{1,1}/dotprod9'
 * '<S111>' : 'neural_controller/NN Controller 3 (relu and linear)/Layer 2/Delays 1'
 * '<S112>' : 'neural_controller/NN Controller 3 (relu and linear)/Layer 2/LW{2,1}'
 * '<S113>' : 'neural_controller/NN Controller 3 (relu and linear)/Layer 2/poslin'
 * '<S114>' : 'neural_controller/NN Controller 3 (relu and linear)/Layer 2/LW{2,1}/dotprod1'
 * '<S115>' : 'neural_controller/NN Controller 3 (relu and linear)/Layer 2/LW{2,1}/dotprod10'
 * '<S116>' : 'neural_controller/NN Controller 3 (relu and linear)/Layer 2/LW{2,1}/dotprod2'
 * '<S117>' : 'neural_controller/NN Controller 3 (relu and linear)/Layer 2/LW{2,1}/dotprod3'
 * '<S118>' : 'neural_controller/NN Controller 3 (relu and linear)/Layer 2/LW{2,1}/dotprod4'
 * '<S119>' : 'neural_controller/NN Controller 3 (relu and linear)/Layer 2/LW{2,1}/dotprod5'
 * '<S120>' : 'neural_controller/NN Controller 3 (relu and linear)/Layer 2/LW{2,1}/dotprod6'
 * '<S121>' : 'neural_controller/NN Controller 3 (relu and linear)/Layer 2/LW{2,1}/dotprod7'
 * '<S122>' : 'neural_controller/NN Controller 3 (relu and linear)/Layer 2/LW{2,1}/dotprod8'
 * '<S123>' : 'neural_controller/NN Controller 3 (relu and linear)/Layer 2/LW{2,1}/dotprod9'
 * '<S124>' : 'neural_controller/NN Controller 3 (relu and linear)/Layer 3/Delays 1'
 * '<S125>' : 'neural_controller/NN Controller 3 (relu and linear)/Layer 3/LW{3,2}'
 * '<S126>' : 'neural_controller/NN Controller 3 (relu and linear)/Layer 3/purelin'
 * '<S127>' : 'neural_controller/NN Controller 3 (relu and linear)/Layer 3/LW{3,2}/dotprod1'
 * '<S128>' : 'neural_controller/NN Controller 3 (relu and linear)/Layer 3/LW{3,2}/dotprod10'
 * '<S129>' : 'neural_controller/NN Controller 3 (relu and linear)/Layer 3/LW{3,2}/dotprod2'
 * '<S130>' : 'neural_controller/NN Controller 3 (relu and linear)/Layer 3/LW{3,2}/dotprod3'
 * '<S131>' : 'neural_controller/NN Controller 3 (relu and linear)/Layer 3/LW{3,2}/dotprod4'
 * '<S132>' : 'neural_controller/NN Controller 3 (relu and linear)/Layer 3/LW{3,2}/dotprod5'
 * '<S133>' : 'neural_controller/NN Controller 3 (relu and linear)/Layer 3/LW{3,2}/dotprod6'
 * '<S134>' : 'neural_controller/NN Controller 3 (relu and linear)/Layer 3/LW{3,2}/dotprod7'
 * '<S135>' : 'neural_controller/NN Controller 3 (relu and linear)/Layer 3/LW{3,2}/dotprod8'
 * '<S136>' : 'neural_controller/NN Controller 3 (relu and linear)/Layer 3/LW{3,2}/dotprod9'
 * '<S137>' : 'neural_controller/NN Controller 3 (relu and linear)/Layer 4/Delays 1'
 * '<S138>' : 'neural_controller/NN Controller 3 (relu and linear)/Layer 4/LW{4,3}'
 * '<S139>' : 'neural_controller/NN Controller 3 (relu and linear)/Layer 4/purelin'
 * '<S140>' : 'neural_controller/NN Controller 3 (relu and linear)/Layer 4/LW{4,3}/dotprod1'
 * '<S141>' : 'neural_controller/NN Controller 3 (relu and linear)/Process Output 1/mapminmax_reverse'
 * '<S142>' : 'neural_controller/NN controller 3 (tanh)/Layer 1'
 * '<S143>' : 'neural_controller/NN controller 3 (tanh)/Layer 2'
 * '<S144>' : 'neural_controller/NN controller 3 (tanh)/Layer 3'
 * '<S145>' : 'neural_controller/NN controller 3 (tanh)/Layer 4'
 * '<S146>' : 'neural_controller/NN controller 3 (tanh)/Process Input 1'
 * '<S147>' : 'neural_controller/NN controller 3 (tanh)/Process Output 1'
 * '<S148>' : 'neural_controller/NN controller 3 (tanh)/Layer 1/Delays 1'
 * '<S149>' : 'neural_controller/NN controller 3 (tanh)/Layer 1/IW{1,1}'
 * '<S150>' : 'neural_controller/NN controller 3 (tanh)/Layer 1/tansig'
 * '<S151>' : 'neural_controller/NN controller 3 (tanh)/Layer 1/IW{1,1}/dotprod1'
 * '<S152>' : 'neural_controller/NN controller 3 (tanh)/Layer 1/IW{1,1}/dotprod10'
 * '<S153>' : 'neural_controller/NN controller 3 (tanh)/Layer 1/IW{1,1}/dotprod2'
 * '<S154>' : 'neural_controller/NN controller 3 (tanh)/Layer 1/IW{1,1}/dotprod3'
 * '<S155>' : 'neural_controller/NN controller 3 (tanh)/Layer 1/IW{1,1}/dotprod4'
 * '<S156>' : 'neural_controller/NN controller 3 (tanh)/Layer 1/IW{1,1}/dotprod5'
 * '<S157>' : 'neural_controller/NN controller 3 (tanh)/Layer 1/IW{1,1}/dotprod6'
 * '<S158>' : 'neural_controller/NN controller 3 (tanh)/Layer 1/IW{1,1}/dotprod7'
 * '<S159>' : 'neural_controller/NN controller 3 (tanh)/Layer 1/IW{1,1}/dotprod8'
 * '<S160>' : 'neural_controller/NN controller 3 (tanh)/Layer 1/IW{1,1}/dotprod9'
 * '<S161>' : 'neural_controller/NN controller 3 (tanh)/Layer 2/Delays 1'
 * '<S162>' : 'neural_controller/NN controller 3 (tanh)/Layer 2/LW{2,1}'
 * '<S163>' : 'neural_controller/NN controller 3 (tanh)/Layer 2/tansig'
 * '<S164>' : 'neural_controller/NN controller 3 (tanh)/Layer 2/LW{2,1}/dotprod1'
 * '<S165>' : 'neural_controller/NN controller 3 (tanh)/Layer 2/LW{2,1}/dotprod10'
 * '<S166>' : 'neural_controller/NN controller 3 (tanh)/Layer 2/LW{2,1}/dotprod2'
 * '<S167>' : 'neural_controller/NN controller 3 (tanh)/Layer 2/LW{2,1}/dotprod3'
 * '<S168>' : 'neural_controller/NN controller 3 (tanh)/Layer 2/LW{2,1}/dotprod4'
 * '<S169>' : 'neural_controller/NN controller 3 (tanh)/Layer 2/LW{2,1}/dotprod5'
 * '<S170>' : 'neural_controller/NN controller 3 (tanh)/Layer 2/LW{2,1}/dotprod6'
 * '<S171>' : 'neural_controller/NN controller 3 (tanh)/Layer 2/LW{2,1}/dotprod7'
 * '<S172>' : 'neural_controller/NN controller 3 (tanh)/Layer 2/LW{2,1}/dotprod8'
 * '<S173>' : 'neural_controller/NN controller 3 (tanh)/Layer 2/LW{2,1}/dotprod9'
 * '<S174>' : 'neural_controller/NN controller 3 (tanh)/Layer 3/Delays 1'
 * '<S175>' : 'neural_controller/NN controller 3 (tanh)/Layer 3/LW{3,2}'
 * '<S176>' : 'neural_controller/NN controller 3 (tanh)/Layer 3/tansig'
 * '<S177>' : 'neural_controller/NN controller 3 (tanh)/Layer 3/LW{3,2}/dotprod1'
 * '<S178>' : 'neural_controller/NN controller 3 (tanh)/Layer 3/LW{3,2}/dotprod10'
 * '<S179>' : 'neural_controller/NN controller 3 (tanh)/Layer 3/LW{3,2}/dotprod2'
 * '<S180>' : 'neural_controller/NN controller 3 (tanh)/Layer 3/LW{3,2}/dotprod3'
 * '<S181>' : 'neural_controller/NN controller 3 (tanh)/Layer 3/LW{3,2}/dotprod4'
 * '<S182>' : 'neural_controller/NN controller 3 (tanh)/Layer 3/LW{3,2}/dotprod5'
 * '<S183>' : 'neural_controller/NN controller 3 (tanh)/Layer 3/LW{3,2}/dotprod6'
 * '<S184>' : 'neural_controller/NN controller 3 (tanh)/Layer 3/LW{3,2}/dotprod7'
 * '<S185>' : 'neural_controller/NN controller 3 (tanh)/Layer 3/LW{3,2}/dotprod8'
 * '<S186>' : 'neural_controller/NN controller 3 (tanh)/Layer 3/LW{3,2}/dotprod9'
 * '<S187>' : 'neural_controller/NN controller 3 (tanh)/Layer 4/Delays 1'
 * '<S188>' : 'neural_controller/NN controller 3 (tanh)/Layer 4/LW{4,3}'
 * '<S189>' : 'neural_controller/NN controller 3 (tanh)/Layer 4/purelin'
 * '<S190>' : 'neural_controller/NN controller 3 (tanh)/Layer 4/LW{4,3}/dotprod1'
 * '<S191>' : 'neural_controller/NN controller 3 (tanh)/Process Output 1/mapminmax_reverse'
 */
#endif                                 /* RTW_HEADER_neural_controller_h_ */
