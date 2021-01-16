#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

// Set your SSID and password
#define WIFI_SSID "-"
#define WIFI_PASSWORD "-"
#define FIREBASE_HOST "ideahacks-2021-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "GpHybjDmvic4hp1j0TocrBZDce7mv69v18ZTsYjr"

//int LED1 = 4;

void setup()
{
  Serial.begin(115200);
  delay(2000);Serial.println('\n');
//pinMode(LED1, OUTPUT);
  
  wifiConnect();
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  delay(10);
}

void loop()
{  
  
  Serial.print(Firebase.getString("NewMessage") + "\n");
  delay(1000);
  //analogWrite(LED1, Firebase.getString("NewMessage").toInt());
  
  if(WiFi.status() != WL_CONNECTED)
  {
    wifiConnect();
  }
  delay(10);

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
