/*************************************************************
  Download latest ERa library here:
    https://github.com/eoh-jsc/era-lib/releases/latest
    https://www.arduino.cc/reference/en/libraries/era
    https://registry.platformio.org/libraries/eoh-ltd/ERa/installation

    ERa website:                https://e-ra.io
    ERa blog:                   https://iotasia.org
    ERa forum:                  https://forum.eoh.io
    Follow us:                  https://www.fb.com/EoHPlatform
 *************************************************************/

// Enable debug console
// Set CORE_DEBUG_LEVEL = 3 first
#define ERA_DEBUG
#define ERA_SERIAL Serial

#include <TinyGPS++.h>

//GPS connection
#define RXD2 18
#define TXD2 19
#define GPS_BAUD 9600
TinyGPSPlus gps;
// Create an instance of the HardwareSerial class for Serial 2
HardwareSerial gpsSerial(2);

/* Select your apn */
#define APN_VIETTEL
// #define APN_VINAPHONE
// #define APN_MOBIFONE

/* Select your modem */
//#define TINY_GSM_MODEM_SIM800
// #define TINY_GSM_MODEM_SIM900
#define TINY_GSM_MODEM_SIM7600

/* For override Modbus uart pin */
// #define MODBUS_RXD_Pin 5
// #define MODBUS_TXD_Pin 4

/* Select ERa host location (VN: Viet Nam, SG: Singapore) */
#define ERA_LOCATION_VN
// #define ERA_LOCATION_SG

// You should get Auth Token in the ERa App or ERa Dashboard
#define ERA_AUTH_TOKEN "YOUR_TOKEN"

#include <Arduino.h>

/* GPIO and Virtual Pin */
#include <ERaSimpleEsp32Gsm.hpp>
/* GPIO, Virtual Pin and Modbus */
// #include <ERaSimpleMBEsp32Gsm.hpp>

/* GPIO and Virtual Pin */
HardwareSerial SerialGsm(1);
/* GPIO, Virtual Pin and Modbus */
// HardwareSerial SerialGsm(2);
TinyGsm modem(SerialGsm);

#if defined(APN_VIETTEL)
const char apn[] = "v-internet";
const char user[] = "";
const char pass[] = "";
#elif defined(APN_VINAPHONE)
const char apn[] = "m3-world";
const char user[] = "mms";
const char pass[] = "mms";
#elif defined(APN_MOBIFONE)
const char apn[] = "m-wap";
const char user[] = "mms";
const char pass[] = "mms";
#else
const char apn[] = "internet";
const char user[] = "";
const char pass[] = "";
#endif

//Module sim connection
const int gsmRxPin = 16;
const int gsmTxPin = 17;
const int pwrPin = 15;

/* This function will run every time ERa is connected */
ERA_CONNECTED() {
  ERA_LOG("ERa", "ERa connected!");
}

/* This function will run every time ERa is disconnected */
ERA_DISCONNECTED() {
  ERA_LOG("ERa", "ERa disconnected!");
}

/* This function print uptime every second */
void timerEvent() {
  ERA_LOG("Timer", "Uptime: %d", ERaMillis() / 1000L);
}

void setup() {
  Serial.begin(115200);

  /* Set GSM module baud rate */
  SerialGsm.begin(115200, SERIAL_8N1, gsmRxPin, gsmTxPin);
  /* Set board id */
  // ERa.setBoardID("Board_1");
  /* Initializing the ERa library. */
  ERa.begin(modem, apn, user, pass, pwrPin);
  /* Setup timer called function every second */
  ERa.addInterval(1000L, timerEvent);

  gpsSerial.begin(GPS_BAUD, SERIAL_8N1, RXD2, TXD2);
  Serial.println("Serial 2 started at 9600 baud rate");
}

void loop() {
  ERa.run();
  delay(100);

  // Checking GPS device 
  while (gpsSerial.available() > 0) {
    char gpsData = gpsSerial.read();
    Serial.print(gpsData);
    gps.encode(gpsData);
  }
  
  Serial.println();
  Serial.println("-------------------------------");
  Serial.println();

  //Display data on serial monitor
  Serial.print("LAT: ");
  Serial.println(gps.location.lat(), 6);
  Serial.print("LONG: ");
  Serial.println(gps.location.lng(), 6);
  Serial.print("Speed: ");
  Serial.println(gps.speed.kmph());

  // Push data to E-Ra Platform
  if((gps.location.lat() != 0) && (gps.location.lng() != 0)){
    ERa.virtualWrite(V0, gps.location.lat()); 
    ERa.virtualWrite(V1, gps.location.lng()); 
    ERa.virtualWrite(V4, gps.speed.kmph());
  }

  Serial.println();
  Serial.println("-------------------------------");
  Serial.println();


  delay(1000);  

}
