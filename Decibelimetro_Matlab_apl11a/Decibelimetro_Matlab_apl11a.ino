#include <math.h>
#include <ESP8266WiFi.h> // Incluimos la librería para ESP8266
#include "thingProperties.h"
#include <SPI.h>
#include <Wire.h>
// Definición de constantes
const int sampleRate = 44100;
const int numChannels = 1;
const int frameSize = 1024;
const int weightingType = 'A';
const int impulseResponse = 'IIR';
const int frequencyUnits = 'HZ';
const int classType = 1;
const int inputSampleRate = 48000;
const int designMethod = 'ANSI S1.42';
const float upperLimit = 999999;
const float lowerLimit = 0;
const float gain1 = 56.818;
const float gain2 = 7653.3;
const float initialCondition = 0;
const int externalReset = 'None';
const int initialConditionSource = 'Internal';
const int sampleTime = -1;
const float gain3 = 12.13;
const float gain4 = 0.08244;

// Variables globales
float inputSignal; // Señal de entrada
//float outputSignal; // Señal de salida

void setup() {
 Serial.begin(9600); // Iniciamos la comunicación serial para monitorear el programa

  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);

  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo(); 
}  
  
void loop() {
  // Lectura de la señal de entrada (ejemplo: desde un sensor)
  inputSignal = analogRead(A0); // Leer valor analógico del pin A0

  // Cálculo del bloque Audio Weighting Filter
  float filteredSignal = calculateWeightedFilter(inputSignal);

  // Cálculo del bloque de saturación
  float saturatedSignal = calculateSaturation(filteredSignal);

  // Cálculo del bloque de ganancia 1
  float gain1Signal = calculateGain(saturatedSignal, gain1);

  // Cálculo del bloque de integración discreta
  float integratedSignal = calculateDiscreteIntegration(gain1Signal, gain2);

  // Cálculo del bloque de ganancia 2
  float gain2Signal = calculateGain(integratedSignal, gain3);

  // Cálculo del bloque Math
  float mathSignal = calculateMath(gain2Signal);

  // Cálculo del bloque de ganancia 3
  outputSignal = calculateGain(mathSignal, gain4);

  Serial.println(outputSignal);
  delay(2000); 
}

// Funciones para realizar los cálculos de cada bloque
float calculateWeightedFilter(float input) {
  // Cálculo del bloque Audio Weighting Filter
  float filteredOutput = 0;

  // Parámetros del filtro ponderado de audio
  float omega = 2 * M_PI * inputSampleRate / sampleRate;
  float z = exp(-omega * frameSize / sampleRate);
  float numCoeffs[3] = {0.0072, -0.0144, 0.0072};
  float denCoeffs[3] = {1, -2 * z * cos(omega), z * z};

  // Implementación de la ecuación en diferencia del filtro IIR
  static float x1 = initialCondition;
  static float x2 = initialCondition;
  float y = numCoeffs[0] * input + numCoeffs[1] * x1 + numCoeffs[2] * x2
            - denCoeffs[1] * filteredOutput - denCoeffs[2] * x1;

  x2 = x1;
  x1 = input;
  filteredOutput = y;

  return filteredOutput;
}

  
float calculateSaturation(float input) {
  // Cálculo del bloque de saturación
float saturatedAudioData=0;

  // Implementación de la función de saturación
if (input > upperLimit) {
  saturatedAudioData = upperLimit;
} else if (input < lowerLimit) {
  saturatedAudioData = lowerLimit;
} else {
  saturatedAudioData = input;
}
  return saturatedAudioData;
}


float calculateGain(float input, float gain) {
  // Código para calcular un bloque de ganancia
  float output = 0;

  // Implementación del bloque de ganancia
  output = input * gain;

  return output;
}

float calculateDiscreteIntegration(float input, float gain) {
  // Cálculo del bloque de integración discreta
  static float lastOutput = initialCondition;
  float integratedOutput = 0;

  // Implementación de la integración discreta usando Euler hacia adelante
  integratedOutput = lastOutput + input * gain;
  lastOutput = integratedOutput;

  return integratedOutput;
}

float calculateMath(float input) {
  // Cálculo del bloque Math
  float mathOutput = 0;

  // Implementación del bloque Math
  mathOutput = log10(input); // Logaritmo base 10

  return mathOutput;
}