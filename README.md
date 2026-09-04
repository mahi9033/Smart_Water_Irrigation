# Smart Water Irrigation System using STM32F411RE

## 📌 Project Overview

The Smart Water Irrigation System is an embedded system designed to automate irrigation based on soil moisture and water availability.

The system uses an STM32F411RE microcontroller and is developed using **register-level Embedded C**, without relying on HAL libraries.

The controller continuously monitors the soil moisture and water level and controls the irrigation pump accordingly.

A manual irrigation button and an emergency STOP button are also provided for user control and safety.

---

## 🎯 Objectives

- Automatically control irrigation based on soil moisture.
- Prevent the pump from running when water is unavailable.
- Provide manual irrigation control.
- Provide an emergency STOP function.
- Display system information using a 16×2 I2C LCD.
- Improve system reliability using the STM32 Independent Watchdog (IWDG).
- Develop the firmware using register-level programming.

---

## ⚙️ System Features

- Soil moisture monitoring using ADC
- Water-level monitoring
- Automatic pump control
- Manual irrigation control
- Emergency STOP
- 16×2 LCD with I2C interface
- I2C communication
- SysTick-based delay
- Independent Watchdog Timer (IWDG)
- Register-level STM32 programming

---

## 🔧 Hardware

| Component | STM32F411RE Pin |
|---|---|
| Soil Moisture Sensor | PA4 / ADC1_IN4 |
| Water Level Sensor | PA1 |
| Status LED | PA5 |
| Pump / Relay | PA6 |
| Manual Irrigation Button | PC13 |
| Emergency STOP Button | PB0 |
| I2C SCL | PB8 |
| I2C SDA | PB9 |
| LCD | I2C |

> Physical hardware testing has not yet been performed because the STM32 hardware and sensors are currently unavailable.

---

## 🧠 Control Logic

The irrigation controller follows this priority:

1. Emergency STOP
2. Check water availability
3. Manual irrigation request
4. Soil moisture level
5. Pump ON/OFF decision

### Automatic Mode

If the soil moisture is below the configured threshold and water is available, the pump is turned ON.

If the soil moisture reaches the required level, the pump is turned OFF.

### Safety

If the water-level sensor indicates that water is unavailable, the pump is turned OFF.

The emergency STOP has the highest priority and immediately commands the pump OFF.

---

## 📊 Software Architecture

```text
                    STM32F411RE
                         |
        +----------------+----------------+
        |                |                |
     Sensors          Control          Outputs
        |                |                |
   +----+----+           |          +-----+-----+
   |         |           |          |           |
Soil      Water     Irrigation     Pump        LCD
Moisture  Level      Logic        Relay       I2C
   |         |           |
   +---------+-----------+
             |
       Safety Inputs
             |
      +------+------+
      |             |
 Manual Button   Emergency STOP
