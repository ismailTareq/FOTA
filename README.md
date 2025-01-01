# FOTA (Firmware Over-The-Air) Project with STM32F106C6T6 and ESP32

This project implements a Firmware Over-The-Air (FOTA) update mechanism for STM32 microcontrollers using a custom bootloader. The STM32 communicates with a host (Node-RED) via ESP32 to receive commands from a Node-RED Dashboard. The firmware update file is stored in Firebase and delivered to the STM32 for seamless updates.

---

## flow of the project
1.Select the command from Dashboard
2.ESP32 receives the command from NodeRed.
3.ESP appends other details to the packet,then sends it to STM32 to BootLoader
4.BootLoader receives the packet and checks the integrity of the firmware file.
5.BootLoader performs the opertion needed by the command and return ACK to ESP32

---

---
##If you want the full version of BootLoader go to this link:
https://github.com/ismailTareq/Creating-Bootloader-on-STM32f407-Discovery-Board
---

## System Architecture

                   Firebase [Update File]
                              |
                              v
[Node-RED Dashboard] <---> [ESP32] <---> [STM32 BootLoader]

---

---
## Video Link Explaining how things go:
https://drive.google.com/file/d/1M1yu0nyOM2ebn3pYRfx6vemX8BhtkEWR/view?usp=drive_link
---



