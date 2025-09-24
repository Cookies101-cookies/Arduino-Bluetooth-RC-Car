# Arduino Bluetooth RC Car

An Arduino-based RC car controlled via Bluetooth using an HC-05 module and an L298N motor driver.  
This project allows you to drive the car forward, backward, left, right, diagonally, and even perform a **smooth stop** instead of an abrupt halt.

---

## Features
- Control car movement with Bluetooth commands.  
- Smooth stop mechanism for gradual braking.  
- Adjustable motor speed via PWM.  
- LED control (on/off) through Bluetooth.  
- Compatible with **Arduino UNO/Nano** + **HC-05** + **L298N**.

---

## Controls
| Command | Action |
|---------|--------|
| `F` | Move Forward |
| `B` | Move Backward |
| `L` | Turn Left |
| `R` | Turn Right |
| `C` | Diagonal Left |
| `A` | Diagonal Right |
| `S` | Smooth Stop |
| `s` | LED ON |
| `O` | LED OFF |

---

## Hardware Required
- Arduino Uno/Nano: ![Amazon Link](https://www.amazon.com/Arduino-A000066-ARDUINO-UNO-R3/dp/B008GRTSV6/ref=sr_1_1?crid=37FUY3ZQK66SW&dib=eyJ2IjoiMSJ9.MazmhFfn-DF8W5oyX_S-tLcvfWSAdtKHJpMqjADQBPqXaeRbmfDqLsrbbwWVU4pqqWuwthaWpxkTZluDAopWgYDoeN7eGVd8YyfWtTzL81DwQh1Ac2WaqVq_HClTlfmJ4grQVcjDEexuZtsrSEfsJy5spUV38LcamKTq4EeWm5DSOu4UmEW1VhZTPwdZwZUL2dugW_9dxrHYfs9XmMBMygdsBoqCn78l8yD0Q6eghx4.8KlrAoEmqaOEDGa-jR7v-KN5PMQ528uBDPzFKZR71Jw&dib_tag=se&keywords=arduino+uno&qid=1758754176&sprefix=arduino+uno%2Caps%2C130&sr=8-1)
- HC-05 Bluetooth module: ![Amazon Link](https://www.amazon.com/DSD-TECH-HC-05-Pass-through-Communication/dp/B01G9KSAF6/ref=sr_1_1_sspa?crid=1K0DZZ2NW3XSV&dib=eyJ2IjoiMSJ9.VZL1p5RDGQw7c8DXaqrVkS9F3rHeDCI460gr5VIRo5uPOMlM3-9u3RX0YiLfC3bLaDq1cC56b508dCWLQtEUGSTjOJuDwYffgVXCwm6ag3zX0hW2gV5KssWGR07NAtvLoYXPTsooslOornt6cqOsXgtfgioSqcJPUskhO4VH3fVMlvuLZeVdAWn9O2shT_-xElbrpm5gEWPIeAyljxmAVm4QJeq7A6yIP4K3hBydaxE.ej2IF9ARA2Kak0HR3T520vyMfzbPCT-KNmFYpD1M0pQ&dib_tag=se&keywords=hc+05+bluetooth+module&qid=1758754268&sprefix=hc+%2Caps%2C175&sr=8-1-spons&sp_csd=d2lkZ2V0TmFtZT1zcF9hdGY&psc=1)
- L298N motor driver: ![Amazon Link](https://www.amazon.com/H-Bridge-Driver-Module-Stepper-Controller/dp/B0DZXG6D9B/ref=sr_1_11?crid=B8TL22XR2CCR&dib=eyJ2IjoiMSJ9.hK2FjV8Ukp8CCyVTI1seMk4n3aguoO_lNXX3xoiH-O1cfzuTK5sJFJvDXGGy0gjnq6YqBeJ3CTWVLvglRoeWxyck7hIRUDjYlnD1HbZipEXDC0GIh0bfKekrj493l7El3MLSFVru9AIO4r64NKBMU6MxZc_SD_Wt97QBrWll0dAPHBOzYcA7UW0J-bCMBDz0iWi_XGkA49D7nk7gcaHhPnNUxTE5ZsNQ0LF2QgWn0GjzYqU1kT7ZQrA6xU-7ByPQLclVBgDA3ZSzqVng8ClRMWSEv_XSJ40wIbpOPR-_ir8.3q3cxfj_pkQKRtJFTkrysS9sEIDMUJpOJ069tZQV5lM&dib_tag=se&keywords=l298n+moto+driver&qid=1758754321&sprefix=l298n+motor+driver%2Caps%2C116&sr=8-11)
- 2 or 4 DC motors + wheels: ![Amazon Link](https://www.amazon.com/dp/B099Z85573/ref=sspa_dk_detail_3?psc=1&pd_rd_i=B099Z85573&pd_rd_w=fG1tJ&content-id=amzn1.sym.386c274b-4bfe-4421-9052-a1a56db557ab&pf_rd_p=386c274b-4bfe-4421-9052-a1a56db557ab&pf_rd_r=STA77EP0MEGW8N560AA1&pd_rd_wg=NpyNd&pd_rd_r=c2fbe827-d91b-4c58-a2c4-936c2a7671ee&sp_csd=d2lkZ2V0TmFtZT1zcF9kZXRhaWxfdGhlbWF0aWM)
- Battery pack (7–12V recommended): ![Amazon Link](https://www.amazon.com/5800mAh-Lithium-Battery-Charger-Rechargeable/dp/B0DZM52TB5/ref=sr_1_4_sspa?crid=18XPDHPFW0FE3&dib=eyJ2IjoiMSJ9.Bo01F_p93XIPIDExzCXNwfmSMBHklymYaOgSpGLcT5PnCi6lywIlqpmtFsw3yZmHpm-tq4VYLHZE1DJSVsW7AsNrQNIkBqf43fvHVhQU1YgbWhdKrvaOdu5B4dSN9Np7f7454VOt3xIiESDqbx3PhjVaeBYCsiYk1U4jcQj0I78G8ZEGhUU4ejyqcG4aPnJ5XhafRgO23RKAz4c-mxBvmjNDKbZDvIG-p_KM0WkjgZ2xX6sAJV0JSaWg29z-QZKAfpHAZlwZN_zoVLVHKldC1igwB22_VQ-o3FVKNNVAkDs.oocL-PMDOBQ8qE7RUbvCVay6iKlnq3FYqiQoZW9GhS0&dib_tag=se&keywords=12v+battery+rc+car&qid=1758754431&sprefix=12v+battery+rc+ca%2Caps%2C117&sr=8-4-spons&sp_csd=d2lkZ2V0TmFtZT1zcF9hdGY&psc=1)
- Chassis(I used thick cardboard) + jumper wires: ![Amazon Link](https://www.amazon.com/Elegoo-EL-CP-004-Multicolored-Breadboard-arduino/dp/B01EV70C78/ref=sr_1_1_sspa?crid=N718BH1E5O4R&dib=eyJ2IjoiMSJ9.I3nSspk5onl8Jong0G-0Eej0s1agLXJoNbNWfIFXRRAEOMuK7c7b9DmCgh8gnhKUMAy-sHPyWmi5Ocv1Fztc4CAJo9WAGXJ1lKruBXkZG4MiSw41yP5MY0BmxejL4wiwGXpXEgTM1b5VcG4b_o4K3xsOSTWmhvXbA0QljY_oOh_ZCv4ZKHAbPdPYl-2ypMyHetgeuhp9CgrHTjE1SNGz2waGMd1UEsQH9FMo3K99Sbk.nbVXJOTLuG8fIWQOtr-bBxrvRn1q0F9eZD9hw6FNSFo&dib_tag=se&keywords=jumper+wires&qid=1758754513&sprefix=jumper+wires%2Caps%2C126&sr=8-1-spons&sp_csd=d2lkZ2V0TmFtZT1zcF9hdGY&psc=1) 
- LED (optional): [Amazon Link](https://www.amazon.com/California-JOS-50-PCS-Colorful/dp/B0CR886L92/ref=sr_1_4?crid=2G5WW7YP6XO1X&dib=eyJ2IjoiMSJ9.D-FZ38nN8aYf_T0FMLvBT5U8AEF7YUYdftEfJlolABI9cTufg9hPAOjWvKkNrigDPmDWo3i7rR097uZ_efwNuxVdA6vlnRXEzJ_uXfoC0nwSyeFDjKHIUWyIEQ34oDyZvNq6ruYAYr0PjAppdAilDu_y3kcZPjkxMBYTToEYaJxTx1ElDnmmdbYBFW0Gz_uvK6BcwvJlByM6Ulp3BUQn1KgZKNyPOVAr6B0dVefyHTM.pAaBlZ1m3PNpXooLXv8uHOu0h7cfflKVCrpYdFe8oks&dib_tag=se&keywords=led%2Barduino&qid=1758754630&sprefix=led%2Barduino%2Caps%2C129&sr=8-4&th=1)

---

## Circuit Connections
- **Motor A:** IN1 → D12, IN2 → D11, ENA → D6  
- **Motor B:** IN3 → D10, IN4 → D9, ENB → D5  
- **LED:** D13  
- **Bluetooth HC-05:** TX → Arduino RX, RX → Arduino TX, VCC → 5V, GND → GND  

---

## Schematics
Here’s the wiring diagram for the project:  

![Schematics](schematics.JPEG)

---

## Setup & Usage
1. Upload the provided code to your Arduino.  
2. Pair your HC-05 Bluetooth module with your smartphone (default password: `1234` or `0000`).  
3. Open a Bluetooth controller app (e.g., **Arduino Bluetooth Controller** or **Serial Bluetooth Terminal**).  
4. Send commands from your phone to control the car.
