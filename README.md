# IoT Smart Irrigation & Environmental Monitoring System

An automated, cloud-connected smart irrigation and environmental monitoring system built using the **ESP32 microcontroller**, multiple environmental sensors, and the **Blynk IoT platform**.

The system continuously monitors ambient temperature, humidity, light intensity, and soil moisture levels to automate irrigation, provide local visual alerts, and stream real-time telemetry data to a cloud dashboard.

---

## 🚀 Features

* **Automated Irrigation:** Automatically activates a DC water pump through a relay module when dry soil conditions are detected.
* **Ambient Light Sensing:** Turns on an LED indicator when ambient light falls below a predefined threshold.
* **Climate Monitoring:** Measures temperature and humidity using a DHT11 sensor.
* **Cloud Connectivity:** Sends all sensor readings to the Blynk Cloud for remote monitoring through mobile and web dashboards.
* **Real-Time Monitoring:** Provides continuous updates of environmental conditions.

---

## 🛠️ Hardware Architecture

### Components Used

#### Microcontroller

* ESP32 (NodeMCU-32S)

#### Sensors

* DHT11 Temperature and Humidity Sensor
* Soil Moisture Sensor (FC-28 with Comparator Module)
* LDR (Light Dependent Resistor)

#### Actuators & Indicators

* 5V Single Channel Relay Module
* Mini DC Submersible Water Pump
* LED Indicator

#### Supporting Components

* Breadboard
* Jumper Wires
* 5V / 3.3V Power Supply

---

## 🔌 Pin Mapping

| Component                    | ESP32 Pin | Mode   | Description                    |
| ---------------------------- | --------- | ------ | ------------------------------ |
| DHT11 Data                   | GPIO 19   | INPUT  | Temperature & Humidity Reading |
| Soil Moisture Digital Output | GPIO 18   | INPUT  | Dry/Wet Detection              |
| LDR Analog Output            | GPIO 34   | INPUT  | Light Intensity Measurement    |
| Relay Module                 | GPIO 5    | OUTPUT | Controls Water Pump            |
| LED Indicator                | GPIO 21   | OUTPUT | Light Status Indicator         |

---

## 🌐 System Workflow

### 1. Data Acquisition

The ESP32 continuously collects data from:

* DHT11 Sensor
* Soil Moisture Sensor
* LDR Sensor

### 2. Local Decision Making

#### Soil Moisture Logic

```text
If Soil Moisture = Dry (1)
    → Relay ON
    → Water Pump ON

If Soil Moisture = Wet (0)
    → Relay OFF
    → Water Pump OFF
```

#### Light Detection Logic

```text
If LDR Value > 2000
    → LED ON

Else
    → LED OFF
```

### 3. Cloud Synchronization

The ESP32 sends all collected sensor data to the Blynk Cloud over Wi-Fi for remote monitoring.

---

## 📊 Blynk Virtual Datastreams

| Virtual Pin | Parameter                               |
| ----------- | --------------------------------------- |
| V1          | Light Intensity                         |
| V2          | Temperature (°C)                        |
| V3          | Humidity (%)                            |
| V4          | Soil Moisture Status (0 = Wet, 1 = Dry) |

---

## 📡 System Architecture

```text
                +--------------------+
                |  Blynk Mobile App  |
                +---------+----------+
                          |
                          |
                     Wi-Fi/Cloud
                          |
                          v
                +--------------------+
                |       ESP32        |
                +----+----+----+-----+
                     |    |    |
                     |    |    |
                     |    |    +------> DHT11 Sensor
                     |    |
                     |    +-----------> LDR Sensor
                     |
                     +---------------> Soil Moisture Sensor

                          |
                          v

                +--------------------+
                |     Relay Module    |
                +----------+----------+
                           |
                           v

                +--------------------+
                |     Water Pump      |
                +--------------------+

                +--------------------+
                |   LED Indicator     |
                +--------------------+
```

---

## 💻 Software Setup

### Prerequisites

1. Install Arduino IDE.
2. Add ESP32 Board Support.

#### ESP32 Board URL

```text
https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
```

### Install Required Libraries

Open:

```text
Tools → Manage Libraries
```

Install:

* Blynk
* DHT Sensor Library (Adafruit)

---

## 📈 Future Enhancements

* Analog soil moisture percentage monitoring.
* ESP32 deep sleep for battery-powered deployments.
* OLED/LCD display integration.
* Mobile push notifications.
* Weather forecast integration.
* AI-based irrigation prediction.
* Solar-powered deployment.

---

## 🔒 Safety Notes

* Use a properly rated relay module.
* Never connect high-voltage AC loads directly to the ESP32.
* Ensure correct power supply ratings.
* Keep electronics protected from water exposure.

---

