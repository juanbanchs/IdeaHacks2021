#include <FB_HTTPClient32.h>
#include <FirebaseESP32.h>
#include <FirebaseJson.h>

#include <WiFi.h>
#include <ESP32_Servo.h>

// Set your SSID and password
#define WIFI_SSID "SpectrumSetup-38"
#define WIFI_PASSWORD "stealthlake576"
#define FIREBASE_HOST "ideahacks-2021-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "GpHybjDmvic4hp1j0TocrBZDce7mv69v18ZTsYjr"

FirebaseData fbdo;

//int LED1 = 4;

Servo pill_dispenser;
#define servo_pin 18
int pos = 0;

void setup()
{
  Serial.begin(115200);
  delay(2000);Serial.println('\n');
//pinMode(LED1, OUTPUT);
  
  wifiConnect();
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  delay(10);

  pill_dispenser.attach(18);
}

void loop()
{  
  Serial.println("Start of loop");
  Serial.print(Firebase.getString(fbdo, "NewMessage") + "\n");
  Serial.println(fbdo.stringData());
  delay(1000);
  
  if(WiFi.status() != WL_CONNECTED)
  {
    wifiConnect();
  }
  delay(10);

  moveServo();

}

void moveServo()
{
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    pill_dispenser.write(pos);              // tell servo to go to position in variable 'pos'
                    // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    pill_dispenser.write(pos);              // tell servo to go to position in variable 'pos'
                     // waits 15ms for the servo to reach the position
  }
}

void wifiConnect()
{
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);             // Connect to the network
  Serial.print("Connecting to ");
  Serial.print(WIFI_SSID); Serial.println(" ...");

  int teller = 0;
  while (WiFi.status() != WL_CONNECTED)
  {                                       // Wait for the Wi-Fi to connect
    delay(1000);
    Serial.print(++teller); Serial.print(' ');
  }

  Serial.println('\n');
  Serial.println("Connection established!");  
  Serial.print("IP address:\t");
  Serial.println(WiFi.localIP());         // Send the IP address of the ESP8266 to the computer
}