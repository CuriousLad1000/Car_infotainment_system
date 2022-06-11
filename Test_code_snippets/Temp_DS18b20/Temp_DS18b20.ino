#include <OneWire.h>
#include <DallasTemperature.h>

int Temp_sens_pin = 9;



//#define ONE_WIRE_BUS 9
// Setup a oneWire instance to communicate with any OneWire devices
// (not just Maxim/Dallas temperature ICs)

OneWire oneWire(Temp_sens_pin);
// Pass our oneWire reference to Dallas Temperature.
DallasTemperature sensors(&oneWire);

void Tsens()
{
   // This prog. will store 5 samples of temperature and then send average of the 5
  
  sensors.requestTemperatures(); // Send the command to get temperatures

  //Serial.print(sensors.getTempCByIndex(0));
  float r1 = sensors.getTempCByIndex(0);
  //Serial.print("r1 recorded");

  sensors.requestTemperatures();
  //Serial.print(sensors.getTempCByIndex(0));
  float r2 = sensors.getTempCByIndex(0);

  sensors.requestTemperatures();
  //Serial.print(sensors.getTempCByIndex(0));
  float r3 = sensors.getTempCByIndex(0);

  sensors.requestTemperatures();
  //Serial.print(sensors.getTempCByIndex(0));
  float r4 = sensors.getTempCByIndex(0);

  sensors.requestTemperatures();
  //Serial.print(sensors.getTempCByIndex(0));
  float r5 = sensors.getTempCByIndex(0);

  float Res = (r1 + r2 + r3 + r4 + r5) / 5;
  Serial.print("Average Temp is ");
  Serial.print(Res);
  Serial.println(" *Celsius");   // You can have more than one IC on the same bus.  // 0 refers to the first IC on the wire

}
void setup(void)
{
  // start serial port
  Serial.begin(9600);
  // Start up the library
  sensors.begin();
}

void loop(void)
{
 Tsens();
}
