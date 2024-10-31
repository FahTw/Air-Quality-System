#define BLYNK_TEMPLATE_ID "TMPL6HN2I4LX2"  // Ensure this ID is correct
#define BLYNK_TEMPLATE_NAME "AirQuality"    // Ensure this name is correct

#include <LiquidCrystal_I2C.h>
#include <WiFiS3.h>
#include <ArtronShop_LineNotify.h>
#include <BlynkSimpleWifi.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

// Configuration
const char* WIFI_SSID = "TEST";
const char* WIFI_PASSWORD = "fahfahfah";
const char* LINE_TOKEN = "x19PWQZvx9dTSrL11TsGJflUXI9j7SJMTiVjdn5ibgZ";
const char* BLYNK_AUTH_TOKEN = "bCEsTqS1lI-Sa-Yp72oKWp5hzvla-uTQ";

// Dust sensor pins and variables
int measurePin = A0;
int ledPower = 2;
int samplingTime = 280;
int deltaTime = 40;
int sleepTime = 9680;
float voMeasured = 0;
float calcVoltage = 0;
float dustDensity = 0;
bool notifyEnabled = false;

void setup() {
  Serial.begin(9600);
  pinMode(ledPower, OUTPUT);
  lcd.begin();
  lcd.backlight();

  Serial.println("\nกำลังเชื่อมต่อ WiFi...");
  lcd.print("Connecting WiFi..");

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }

  Serial.println("\nเชื่อมต่อ WiFi สำเร็จ!");
  lcd.clear();
  lcd.print("WiFi Connected!");
  delay(1000);

  Blynk.begin(BLYNK_AUTH_TOKEN, WIFI_SSID, WIFI_PASSWORD);
}
  BLYNK_WRITE(V2) {
  notifyEnabled = param.asInt();
  }

// ส่งข้อความไปยัง LINE Notify
void sendLineNotify(float dustDensity) {
  Serial.println("\n----- เริ่มส่งการแจ้งเตือน LINE -----");
  LINE.begin(LINE_TOKEN);

  // สร้างข้อความแจ้งเตือน
  String message = "[อันตราย!!] ค่าฝุ่นที่วัดได้ " + String(dustDensity) + " ug/m3 เริ่มมีผลต่อสุขภาพแล้วนะ";
  LINE.send(message); 

  Serial.println("----- จบการส่งการแจ้งเตือน -----\n");
}

void loop() {
  Blynk.run();
  
  digitalWrite(ledPower, LOW);
  delayMicroseconds(samplingTime);
  voMeasured = analogRead(measurePin);
  delayMicroseconds(deltaTime);
  digitalWrite(ledPower, HIGH);
  delayMicroseconds(sleepTime);

  calcVoltage = voMeasured * (5.0 / 1024.0);
  dustDensity = 170 * calcVoltage - 0.1;

  Serial.print("ค่าฝุ่นละออง: ");
  Serial.print(dustDensity);
  Serial.println(" ug/m3");

  // ส่งค่าไปยัง Blynk App
  Blynk.virtualWrite(V0, dustDensity);
  Blynk.virtualWrite(V1, dustDensity);

  // แสดงผลบน LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Pm2.5:");
  lcd.setCursor(2, 1);
  lcd.print(dustDensity);
  lcd.print(" ug/m3");

  // ทดสอบการส่ง LINE ทุกครั้งที่ค่าฝุ่นเกิน 37.6
  if (dustDensity > 37.6 && notifyEnabled) {
    Serial.println("\nค่าฝุ่นเกินกำหนด! กำลังส่งการแจ้งเตือน...");
    sendLineNotify(dustDensity);
  }

  delay(1000);
}
