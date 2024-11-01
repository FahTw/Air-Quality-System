# Physical Computing Project 2024 - IT KMITL
โปรเจคนี้ เป็นโปรเจคในรายวิชา Physical Computer ปี 2 ภาคเรียนที่ 1
โดยมีจุดประสงค์เพื่อวัดคุณภาพอากาศในบริเวณนั้นว่าเป็นอย่างไรโดยตัวโปรเจคจะมีการแสดงข้อความทั้งในตัววงจร และมีการแจ้งเตือนใน Line notification โดยหากคุณภาพอากาศแย่จะมีการแจ้งเตือน
## Hardware (ทั้งหมด)
- Arduino R4 WIFI
  ![Arduino_Uno_R4_WiFi webp](https://github.com/user-attachments/assets/404e5069-aeeb-4f35-8f86-b9deb4f1a86a)
- BreadBoard
  ![breadboard](https://github.com/user-attachments/assets/37172a56-53f9-40a1-bc7a-f6e67067b785)
- sensor วัดฝุ่น
  ![เซนเซอร์วัดฝุ่น](https://github.com/user-attachments/assets/2165d868-3d2c-40c2-aa20-f4b51e46103c)
- LCD
  ![lcd](https://github.com/user-attachments/assets/6bd96958-ea46-4acb-af85-6f8ae8525dc1)

## LIBRARY
- WIFI S3  เพื่อเชื่อมต่อ WIFI
- LiquidCrystal_I2C เป็นของจอ LCD
- ArtronShop_LineNotify เชื่อมต่อ Line notify
- BlynkSimpleWifi
## Abstract
โปรเจคนี้เป็นโปรเจค microcontrollor มีจุดประสงค์เพื่อต้องการให้ผู้ที่ได้ใช้ได้ทราบว่า ตอนนี้สภาวะอากาศ หรือ มลภาวะในขณะนั้นเป็นอย่างไรโดยเป็นการวัดค่าฝุ่น pm2.5 เพื่อที่ผู้ที่ใช้งานสามารถป้องกัน เพื่อไม่ให้ส่งผลต่อสุขภาพในระยะสั้นหรือยาวได้
## input
ค่าที่เซนเซอร์วัดฝุ่นที่รับเข้ามาจากอากาศ
## output
ค่า PM2.5 หน่วย µg/m3 ที่ผ่านการคำนวณแสดงบนจอ LCD
ค่า PM2.5 หน่วย µg/m3 ที่ผ่านการคำนวณแสดงการแจ้งเตือนใน Line Notification เมื่อค่าเกิน 37.6
ค่า PM2.5 หน่วย µg/m3 ที่ผ่านการคำนวณแสดงบนเว็บแบบ realtime และสามารถดูประวัติได้
## สมาชิก
1. นางสาวเขมอัปสร ตั้งวิรุฬห์ 66070021
2. นายกฤติเดช โตใจธรรม 66070004
3. นายเจตนิพัทธ์ ทานะมัย 66070032
4. นายณัฐวุฒิ ฤกษ์สมจิต 66070067

#Link
https://www.youtube.com/watch?v=EFk9rBnu42c&feature=youtu.be
https://fahtw.github.io/io/
#Poster
![Air_Quality](https://github.com/user-attachments/assets/cf3524d0-f193-4299-99e4-3c32b3f35844)

