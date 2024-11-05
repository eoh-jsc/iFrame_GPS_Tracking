# ERa iFrame_GPS_Tracking

[![GitHub download](https://img.shields.io/github/downloads/eoh-jsc/iFrame_GPS_Tracking/total.svg)](https://github.com/eoh-jsc/iFrame_GPS_Tracking/releases/latest)
[![GitHub stars](https://img.shields.io/github/stars/eoh-jsc/iFrame_GPS_Tracking.svg)](https://github.com/eoh-jsc/iFrame_GPS_Tracking/stargazers)

An IoT Market Enabler! It supports WiFi, Ethernet, Zigbee, Modbus, Serial. Works with boards like Arduino, ESP8266, ESP32, STM32, Raspberry Pi...

Website: https://e-ra.io

## Tutorial

Source code: https://github.com/eoh-jsc/iFrame_GPS_Tracking
1. Chỉnh sửa code của ESP32: bao gồm chân kết nối, loại thiết bị, loại sim và token!

![image](https://github.com/user-attachments/assets/12da63c0-199c-4aac-b95b-5bd81b058751)

2. Chỉnh sửa code HTML:
   - Tạo API Google Map: https://developers.google.com/maps
   - Lưu ý: "ADD" website để được phép sử dụng API đã tạo.
     
   ![image](https://github.com/user-attachments/assets/a0ae9a59-332e-4508-a8e5-439652dc622d)

   - Thêm API đã tạo:
   ![image](https://github.com/user-attachments/assets/83c42513-4e7c-4a05-a287-81585847903b)

3. Deploy HTML trên Github: xem hướng dẫn iframe tại https://e-ra-iot-wiki.gitbook.io/documentation/huong-dan-su-dung-e-ra/hot-tinh-nang-iframe
   (sau khi Deploy, kiểm tra xem Google map đã hiện ra hay chưa)

4. Cấu hình E-Ra Platform
   - Virtual Pin:
   
   ![image](https://github.com/user-attachments/assets/cf582af9-ff86-482e-b960-4969f1b81413)
   ![image](https://github.com/user-attachments/assets/91eac15c-8303-40cf-8d3e-08fdd99cf8d0)
   ![image](https://github.com/user-attachments/assets/75470c07-a543-4f19-97e0-9a9d9d7868e6)

   - Widget(Dashboard):
     + Value Box:
     
   ![image](https://github.com/user-attachments/assets/603e53e4-42ac-4ad8-b9a2-13dfa97aaa54)

      + Button:
   ![image](https://github.com/user-attachments/assets/15861a59-574c-4308-9610-8d1675f8ec6e)

      + iFrame with configs:
   
   ![image](https://github.com/user-attachments/assets/1740faa2-35d8-4612-9dbe-444a9fa5f2f0)
   ![image](https://github.com/user-attachments/assets/d607155a-abf2-44bd-b80f-01c8754898c3)

5. Trải nghiệm!

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
