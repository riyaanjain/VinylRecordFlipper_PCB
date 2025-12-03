# 🎵 Automatic Vinyl Record Flipper

I love vinyl records.

But each side of a 12 inch LP can only store about 20 minutes of music, and I don't necessarily love having to get up to flip the record often. I just wish that, after I put the record on, it would play the entire album.

So, we took matters into our own hands and built an **automatic vinyl record flipper**.

Included are:
- 🛠️ **PCB Design Files made with KiCad**
- 💻 **The program code**
- 📷 **A picture and video for your enjoyment (have to download the video from Image_and_Video folder🥲)**

Hopefully, you enjoy it as much as I did.

---

## 🧠 What It Does

This device automatically flips a vinyl record by sending PWM signals to servo motors using an ESP32 microcontroller. It detects the tonearm rest position using a Hall effect sensor, then triggers the motors to lift, rotate, and drop the record back down.

---

## 🖼️ Project Gallery

### 🔧 PCB Preview  
![PCB Preview](PCB_Design/PCB_preview.png)

### 📸 Final Project Photo  
![Project Photo](Image_and_Video/IMG_6376.jpeg)

---

## 📁 Folder Structure

```bash
VinylRecordFlipper/
├── PCB_Design/                     # KiCad schematic and layout
│   └── PCB_preview.png
├── Image_and_Video/                # Demo photo and video of the final product
├── Record_Flipper_Program.ino      # ESP32 code (Arduino-compatible)
└── README.md                       # You're here
